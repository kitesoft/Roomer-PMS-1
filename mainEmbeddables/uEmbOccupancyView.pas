unit uEmbOccupancyView;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.Grids, AdvObj, BaseGrid, AdvGrid, Vcl.ExtCtrls, sPanel,
  uD, HData, PrjConst, cmpRoomerDataSet, uSqlDefinitions, uDateUtils, uUtils, uRoomerLanguage, uAppGlobal, AdvUtil
  , uHotelStatistics
  ;

type

  TOccupancyViewType = (ovtDefault, ovtAdvanced);

  TembOccupancyView = class(TForm)
    pnlEmbeddable: TsPanel;
    grdOccupancy: TAdvStringGrid;
    procedure grdOccupancyGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure grdOccupancyDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
    procedure FormCreate(Sender: TObject);
  private
    fromDate, toDate: TDateTime;
    FOccupancyViewType: TOccupancyViewType;
    FCell0FontSize: Integer;
    procedure TranslateHeaders;
    procedure RefreshStats;
    procedure SetOccupancyViewType(const Value: TOccupancyViewType);
    function GetOriginalParentHeight: Integer;
    procedure SetOriginalParentHeight(const Value: Integer);
    procedure CheckResizeFont;
    function ResizeFont(Canvas : TCanvas; width : Integer; text : String) : Integer;
    procedure SetCell0FontSize(const Value: Integer);
    procedure UpdateGridFromStats(aStats: THotelStatisticsList);
    { Private declarations }
  protected
    FOriginalParentHeight : Integer;
  public
    { Public declarations }
    procedure InitEmbededOccupancyView(prnt : TWinControl);
    procedure Release;

    procedure ShowOccupancy(fromDate, toDate : TDateTime); overload;

    procedure SetCellWidth(ACol, AWidth : Integer);

    procedure Reset;
    property OccupancyViewType : TOccupancyViewType read FOccupancyViewType write SetOccupancyViewType;
    property OriginalParentHeight : Integer read GetOriginalParentHeight write SetOriginalParentHeight;

    property Cell0FontSize : Integer read FCell0FontSize write SetCell0FontSize;
  end;

implementation

{$R *.dfm}

uses uHotelStatisticsAPI
    ;

{ TembOccupancyView }

procedure TembOccupancyView.SetCell0FontSize(const Value: Integer);
begin
  FCell0FontSize := Value;
  grdOccupancy.Resize;
end;

procedure TembOccupancyView.SetCellWidth(ACol, AWidth: Integer);
begin
  grdOccupancy.ColWidths[ACol] := AWidth;
end;

procedure TembOccupancyView.SetOccupancyViewType(const Value: TOccupancyViewType);
begin
  if FOccupancyViewType <> Value then
  begin
    FOccupancyViewType := Value;
    if FOccupancyViewType = ovtDefault then
      pnlEmbeddable.Parent.Height := FOriginalParentHeight
    else
      pnlEmbeddable.Parent.Height := 200;

    RefreshStats;
  end;
end;

procedure TembOccupancyView.SetOriginalParentHeight(const Value: Integer);
begin
  FOriginalParentHeight := Value;
end;

procedure TembOccupancyView.ShowOccupancy(fromDate, toDate: TDateTime);
begin
  self.FromDate := fromDate;
  self.ToDate := toDate;
  RefreshStats;
end;

procedure TembOccupancyView.RefreshStats;
begin
  THotelStatisticsMobileAPICallerThreaded.GetHotelStatistics(fromDate, toDate, UpdateGridFromStats);
end;

procedure TembOccupancyView.UpdateGridFromStats(aStats: THotelStatisticsList);
var
  col : Integer;
  lDateStat: TSingleDateStatistics;
begin
  grdOccupancy.BeginUpdate;
  try
    grdOccupancy.RowCount := 3 + (4 * ABS(ORD(OccupancyViewType = ovtAdvanced)));
    grdOccupancy.ColCount := trunc(toDate) - trunc(fromDate) + 2;

    col := 0;
    for lDateStat in aStats.StatisticsPerDateList do // TODO: Force order by date!
    begin
      inc(col);

      grdOccupancy.Cells[col,0] := lDateStat.Statistic['Occupancy'].FormattedValue;
      grdOccupancy.Cells[col,1] := lDateStat.Statistic['LEFT_TO_SELL'].FormattedValue;
      grdOccupancy.Cells[col,2] := lDateStat.Statistic['REVPAR'].FormattedValue;

      if OccupancyViewType = ovtAdvanced then
      begin
        grdOccupancy.Cells[col,3] := lDateStat.Statistic['REVENUES'].FormattedValue;
        grdOccupancy.Cells[col,4] := lDateStat.Statistic['ROOMS_SOLD'].FormattedValue;
        grdOccupancy.Cells[col,5] := lDateStat.Statistic['OOO_ROOMS'].FormattedValue;
        grdOccupancy.Cells[col,6] := lDateStat.Statistic['ADR'].FormattedValue;
      end;

    end;
    TranslateHeaders;
    grdOccupancy.FixedCols := 1;
    grdOccupancy.Show;
  finally
    grdOccupancy.EndUpdate;
  end;
//  PostMessage(ParentWindow, WM_REFRESH_PERIOD_VIEW_BOTTOM_REFRESH, 0, 0);
end;

procedure TembOccupancyView.TranslateHeaders;
begin
  grdOccupancy.Cells[0,0] := GetTranslatedText('shUI_Occupancy');
  grdOccupancy.Cells[0,1] := GetTranslatedText('shUI_Availability');
  grdOccupancy.Cells[0,2] := GetTranslatedText('shUI_RevPar');

  if OccupancyViewType = ovtAdvanced then
  begin
    grdOccupancy.Cells[0,3] := GetTranslatedText('shUI_RoomRevenue');
    grdOccupancy.Cells[0,4] := GetTranslatedText('shUI_RoomsSold');
    grdOccupancy.Cells[0,5] := GetTranslatedText('shUI_OOO');
    grdOccupancy.Cells[0,6] := GetTranslatedText('shUI_AverageDailyRate');
  end;
  CheckResizeFont;
end;


procedure TembOccupancyView.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(Self);
end;

function TembOccupancyView.GetOriginalParentHeight: Integer;
begin
  result := FOriginalParentHeight;
end;

function TembOccupancyView.ResizeFont(Canvas : TCanvas; width : Integer; text : String) : Integer;
begin
  while (Canvas.TextWidth(text) > width) AND (Canvas.Font.Size >= 7) do
    Canvas.Font.Size := Canvas.Font.Size - 1;

  Result := Canvas.Font.Size;
end;

procedure TembOccupancyView.CheckResizeFont;
var
  i, iLen: Integer;
  sLongest, s : String;
begin
  iLen := 0;
  sLongest := '';
  with grdOccupancy do
  begin
    for i := 0 to grdOccupancy.RowCount - 1 do
    begin
      s := grdOccupancy.Cells[0, i];
      if Canvas.TextWidth(s) > iLen then
      begin
        iLen := Canvas.TextWidth(s);
        sLongest := s;
      end;
    end;
  end;
  Cell0FontSize := ResizeFont(grdOccupancy.Canvas, grdOccupancy.ColWidths[0], sLongest);
end;

procedure TembOccupancyView.grdOccupancyDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
begin
  if (ACol = 0) AND (ARow >= 0) then
  begin
    grdOccupancy.Canvas.Font.Size := FCell0FontSize;
    grdOccupancy.Canvas.FillRect(Rect);
    grdOccupancy.Canvas.TextOut(Rect.Left + 2, Rect.Top + 2, grdOccupancy.Cells[ACol, ARow]);
  end;
end;

procedure TembOccupancyView.grdOccupancyGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if ACol > 0 then
    HAlign := taCenter;
end;

procedure TembOccupancyView.InitEmbededOccupancyView(prnt: TWinControl);
begin
  grdOccupancy.Hide;
  pnlEmbeddable.Parent := prnt;
  grdOccupancy.RowHeights[0] := 25;
  grdOccupancy.RowHeights[1] := grdOccupancy.RowHeights[0];
  grdOccupancy.RowHeights[2] := grdOccupancy.RowHeights[0];

  FCell0FontSize := grdOccupancy.Font.Size;
  FOriginalParentHeight := prnt.Height;
  FOccupancyViewType := ovtDefault;
end;

procedure TembOccupancyView.Release;
begin
  grdOccupancy.Hide;
  pnlEmbeddable.Parent := self;
end;

procedure TembOccupancyView.Reset;
begin
  if FOccupancyViewType <> ovtDefault then
    OccupancyViewType := ovtDefault;
end;

end.
