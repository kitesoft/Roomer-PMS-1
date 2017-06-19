unit uFrontDeskPageButton;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, acImage, Vcl.StdCtrls, sLabel, sPanel, Vcl.ImgList, PngImageList, AdvUtil, Vcl.Grids, AdvObj, BaseGrid,
  AdvGrid, cmpRoomerDataSet, uRoomerThreadedRequest;

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
  private
    FShowFromDate: TDate;
    procedure SetShowFromDate(const Value: TDate);
    { Private declarations }
  private
    ThreadedDataGetter : TGetSQLDataThreaded;
    procedure RefreshButtons;
    procedure RefreshGrid;
    function GetSenderAsPanel(Sender: TObject): TsPanel;
    function GetShapeComponentOfButton(Sender: TObject): TShape;
    procedure BackgroundDataFetchHandler(Sender: TObject);
    procedure ShowGridData(SetOfData: TRoomerDataSet);
    procedure DrawDateRow;
    procedure PrepareGridText;
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
    ;

const

   ROW_DAY          = 0;
   ROW_DATE         = 1;
   ROW_SPEC_DAY     = 2;

   ROW_ARRIVALS     = 3;
   ROW_DEPARTURES   = 4;
   ROW_LEFT_TO_SELL = 5;
   ROW_OCCUPANCY    = 6;
   ROW_BAR          = 7;

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

procedure TFrmFrontDeskPageButton.RefreshButtons;
var sql: String;
    res : TRoomerDataSet;
    sDate, sYesterday : String;
begin
  res := CreateNewDataSet;
  try
    sDate := dateToSqlString(now);
    sYesterday := dateToSqlString(now-1);
    sql := format('SELECT ' +
                  '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
                  'WHERE ADate=''%s'' ' +
                  'AND rd.ResFlag IN (''P'') ' +
                  'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL -1 DAY))) AS NumArrivals, ' +

                  '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
                  'WHERE ADate=DATE_ADD(''%s'', INTERVAL -1 DAY) ' +
                  'AND rd.ResFlag IN (''G'',''P'') ' +
                  'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL 1 DAY))) AS NumDepartures, ' +

                  '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
                  'WHERE ADate=DATE_ADD(''%s'', INTERVAL 1 DAY) ' +
                  'AND rd.ResFlag IN (''P'') ' +
                  'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL -1 DAY))) AS NumArrivalsTomorrow, ' +

                  '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
                  'WHERE ADate=''%s'' ' +
                  'AND rd.ResFlag IN (''G'',''P'') ' +
                  'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL 1 DAY))) AS NumDeparturesTomorrow, ' +

                  '(SELECT COUNT(id) NumEntries FROM ' +
                  '(SELECT ID FROM roomsdate rd ' +
                  'WHERE ADate IN (''%s'', ''%s'') ' +
                  'AND rd.ResFlag IN (''G'') ' +
                  'GROUP BY RoomReservation) xxx) AS NumInHouse',
                  [sDate, sDate, sDate, sDate, sDate, sYesterday]
            );
    rSet_bySQL(res, sql, False);
    res.First;
    if NOT res.Eof then
    begin
      lblArrivals.Caption := inttostr(res['NumArrivals']);
      lblDepartures.Caption := inttostr(res['NumDepartures']);
      lblTomArrivals.Caption := inttostr(res['NumArrivalsTomorrow']);
      lblTomDepartures.Caption := inttostr(res['NumDeparturesTomorrow']);
      lblInHouse.Caption := inttostr(res['NumInHouse']);
    end;
  finally
    FreeAndNil(res);
  end;
end;

procedure TFrmFrontDeskPageButton.RefreshDisplay;
begin
  RefreshButtons;
  RefreshGrid;
end;

procedure TFrmFrontDeskPageButton.RefreshGrid;
var sql : String;
    sDate : String;
begin
  sDate := dateToSqlString(ShowFromDate);
  sql := 'SELECT ' +
         'DATE(pdd.date) AS date, ' +
         '(SELECT MIN(Price*cu.aValue) FROM channelrates cr ' +
         'JOIN channels ch ON ch.Id=cr.channelId ' +
         'JOIN roomtypegroups rtg ON rtg.Id=cr.roomClassId AND rtg.Active=1 ' +
         'JOIN currencies cu ON cu.Id=ch.currencyId ' +
         'JOIN roomtypes rt ON rt.RoomTypeGroup=rtg.Code AND rt.Active=1 ' +
         'WHERE date=pdd.date ' +
         'AND Price > 0) AS BAR, ' +
         ' ' +
         '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
         'WHERE ADate=pdd.date ' +
         'AND rd.ResFlag IN (''P'',''G'',''B'',''A'',''L'')) AS NumOccupied, ' +
         ' ' +
         '(SELECT COUNT(id) AS NumEntries FROM rooms r ' +
         'WHERE r.Active=1 ' +
         'AND r.WildCard=0 ' +
         'AND r.Statistics=1 ' +
         'AND r.Hidden=0) AS NumRooms, ' +
         ' ' +
         '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
         'WHERE ADate=pdd.date ' +
         'AND rd.ResFlag IN (''P'',''A'') ' +
         'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL -1 DAY))) AS NumArrivals, ' +
         ' ' +
         '(SELECT COUNT(id) AS NumEntries FROM roomsdate rd ' +
         'WHERE ADate=DATE_ADD(pdd.date, INTERVAL -1 DAY) ' +
         'AND rd.ResFlag IN (''G'',''P'',''A'') ' +
         'AND NOT EXISTS(SELECT id FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND ADate=DATE_ADD(rd.ADate, INTERVAL 1 DAY))) AS NumDepartures ' +
         ' ' +
         'FROM predefineddates pdd ' +
         'WHERE pdd.date >= ''%s'' ANd pdd.date <= DATE_ADD(''%s'', INTERVAL 6 DAY)';
  sql := format(sql, [sDate, sDate]);
  CopyToClipboard(sql);
  ThreadedDataGetter.execute(sql, BackgroundDataFetchHandler);
end;

procedure TFrmFrontDeskPageButton.Shape2MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowDeparturesReport(true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape3MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowArrivalsReport(true, true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape4MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowDeparturesReport(true, true);
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

procedure TFrmFrontDeskPageButton.ShowGridData(SetOfData : TRoomerDataSet);
var col : Integer;
    NumOccupied,
    NumRooms : Integer;
begin
  DrawDateRow;
  col := 1;
  SetOfData.First;
  while NOT SetOfData.Eof do
  begin
    NumRooms := SetOfData.FieldByName('NumRooms').AsInteger;;
    NumOccupied := SetOfData.FieldByName('NumOccupied').AsInteger;
    StatGrid.Cells[col, ROW_ARRIVALS]     := inttostr(SetOfData['NumArrivals']);
    StatGrid.Cells[col, ROW_DEPARTURES]   := inttostr(SetOfData['NumDepartures']);
    StatGrid.Cells[col, ROW_LEFT_TO_SELL] := inttostr(SetOfData.FieldByName('NumRooms').AsInteger - SetOfData.FieldByName('NumOccupied').AsInteger);
    StatGrid.Cells[col, ROW_OCCUPANCY]    := trim(_floattostr((SetOfData.FieldByName('NumOccupied').AsInteger / SetOfData.FieldByName('NumRooms').AsInteger) * 100, 6, 0)) + '%';

    if (NumRooms - NumOccupied) > 0 then
      StatGrid.Cells[col, ROW_BAR]        := g.qNativeCurrency + ' ' + trim(_floattostr(SetOfData['BAR'], 12,2))
    else
      StatGrid.Cells[col, ROW_BAR]        := 'N/A';

    SetOfData.Next;
    inc(col);
  end;
end;

procedure TFrmFrontDeskPageButton.BackgroundDataFetchHandler(Sender : TObject);
begin
  try
    ShowGridData(ThreadedDataGetter.RoomerDataSet);
    ThreadedDataGetter.RoomerDataSet.Close;
    ThreadedDataGetter.RoomerDataSet.Recordset := nil;
  except
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
  ShowArrivalsReport(true);
  RefreshDisplay;
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
  if (ARow < 3) OR (ACol < 1) then
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

  ThreadedDataGetter := TGetSQLDataThreaded.Create;
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
