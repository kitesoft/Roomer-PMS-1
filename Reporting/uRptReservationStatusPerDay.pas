unit uRptReservationStatusPerDay;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, DateUtils,
  uRoomerForm, uAppGlobal, uFileDependencyManager, uUtils, cmpRoomerDataSet, uDateUtils, uFileSystemUtils,
  frxClass, frxDBSet, frxDesgn, Vcl.StdCtrls, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sButton, sComboBox, sGroupBox, sLabel,
  Vcl.ExtCtrls, sPanel, Data.DB, kbmMemTable, ppCtrls, ppPrnabl, ppClass, ppDB, ppDBPipe, ppBands, ppCache, ppDesignLayer, ppParameter, ppComm, ppRelatv,
  ppProd, ppReport, AdvUtil, Vcl.Grids, AdvObj, BaseGrid, AdvGrid;

type

//  TCellType = ( ctNormalText,
//                ctHeaderText,
//
//                ctBeginBox,
//                ctMiddleBox,
//                ctEndBox,
//
//                ctVertLine
//              );

  TCellType = Integer;
const
  ctNormalText  = 100;
  ctHeaderText  = 110;

  ctBeginBox    = 120;
  ctMiddleBox   = 130;
  ctEndBox      = 140;

  ctBeginBar    = 150;
  ctEndBar      = 160;

  ctVertLine    = 170;

type

  TFrmRptReservationStatusPerDay = class(TfrmBaseRoomerForm)
    Panel3: TsPanel;
    labLocationsList: TsLabel;
    labLocations: TsLabel;
    cxGroupBox2: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    grdReport: TAdvStringGrid;
    procedure FormCreate(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure cbxMonthCloseUp(Sender: TObject);
    procedure dtDateFromChange(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure grdReportDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
  private
    zSetDates : Boolean;
    zDateFrom : TDate;
    zDateTo   : TDate;
    FCol: Integer;
    FRow: Integer;
    NumRoomTypes : Integer;

    procedure GetResData;
    procedure PrepareDates;
    procedure AddToTable(GroupsAndRoomTypeSet : TRoomerDataSet; invRefrence : String);
    procedure AddZeroToTable(DatesAndGroupsSet: TRoomerDataSet; RoomType: String);
    function ScrollRoomTypeTo(GroupsAndRoomTypeSet: TRoomerDataSet; ADate: TDate; Reservation: Integer; RoomType: String) : Boolean;
    procedure SetCol(const Value: Integer);
    procedure SetRow(const Value: Integer);
    procedure AddTotalsToTable(dLastDate : TDate; StartAtRow, EndAtRow, WriteInRow: Integer);
    procedure WriteHeader(ARow : Integer);
    procedure SetCellValue(C, R: Integer; Value: String; CellType: TCellType);
    function GetCellType(C, R: Integer): TCellType;
    function isEndBox(ACol: Integer): Boolean;
    function isBeginBox(ACol: Integer): Boolean;
    function isNormalBox(ACol: Integer): Boolean;
    function GetCellTypeByColumn(ACol: Integer): TCellType;
    function isFirstBox(ACol: Integer): Boolean;
    function isLastBox(ACol: Integer): Boolean;
    function GetFirstOrLastCellTypeByColumn(ACol: Integer): TCellType;
    { Private declarations }
    property iRow : Integer read FRow write SetRow;
    property iCol : Integer read FCol write SetCol;
  public
    { Public declarations }
  end;

var
  FrmRptReservationStatusPerDay: TFrmRptReservationStatusPerDay;

procedure ShowRptReservationStatusPerDay;

implementation

{$R *.dfm}

uses hData,
     uD,
     UITypes
    ;

procedure ShowRptReservationStatusPerDay;
var
  _FrmRptReservationStatusPerDay: TFrmRptReservationStatusPerDay;
begin
  _FrmRptReservationStatusPerDay := TFrmRptReservationStatusPerDay.Create(nil);
  try
    _FrmRptReservationStatusPerDay.ShowModal;
  finally
    FreeAndNil(_FrmRptReservationStatusPerDay);
  end;
end;

procedure TFrmRptReservationStatusPerDay.btnRefreshClick(Sender: TObject);
begin
  GetResData;
end;


procedure TFrmRptReservationStatusPerDay.FormShow(Sender: TObject);
begin
  inherited;
  PrepareDates;
end;

CONST HEADER_STARTS = 10;
      ROOMTYPES_START = 4;

procedure TFrmRptReservationStatusPerDay.GetResData;
var sqlDaysAndGroups : String;
    sqlGroupsAndRoomTypes : String;
    DatesAndGroupsSet : TRoomerDataSet;
    GroupsAndRoomTypeSet : TRoomerDataSet;
    RoomsSet : TRoomerDataSet;
    iLastRes : Integer;
    dLastDate : TDate;
    i, Week : Integer;
    StartAtRow : Integer;

    CellType : TCellType;
begin
  sqlDaysAndGroups    := format('SELECT DISTINCT DATE(rd.ADate) AS ADate, to_int(WEEK(rd.ADate)) AS WeekNr, r.Reservation, r.invRefrence, '  +
                   'r.Name, r.Customer, cu.Surname AS CustomerName ' +
                   'FROM reservations r JOIN roomsdate rd ON r.Reservation=rd.Reservation JOIN customers cu ON cu.Customer=r.Customer ' +
                   'WHERE (rd.ADate >= ''%s'' AND rd.ADate <= ''%s'') AND rd.ResFlag NOT IN (''X'',''C'',''N'') ' +
                   'GROUP BY rd.ADate, rd.Reservation, rd.RoomType',
            [
              uDateUtils.dateToSqlString(dtDateFrom.Date),
              uDateUtils.dateToSqlString(dtDateTo.Date)
            ]);

  sqlGroupsAndRoomTypes := format('SELECT DATE(pdd.date) AS ADate, to_int(WEEK(pdd.date)) AS WeekNr, rt.RoomType, rd1.Reservation, ' +
                        '(SELECT COUNT(rd.id) FROM roomsdate rd WHERE rd.ADate=pdd.date AND rd.Reservation=rd1.Reservation AND rd.RoomType=rt.RoomType AND rd.ResFlag IN (''O'',''A'',''B'')) AS UnConfirmed, ' +
                        '(SELECT COUNT(rd.id) FROM roomsdate rd WHERE rd.ADate=pdd.date AND rd.Reservation=rd1.Reservation AND rd.RoomType=rt.RoomType AND rd.ResFlag IN (''L'')) AS WaitingList, ' +
                        '(SELECT COUNT(rd.id) FROM roomsdate rd WHERE rd.ADate=pdd.date AND rd.Reservation=rd1.Reservation AND rd.RoomType=rt.RoomType AND rd.ResFlag NOT IN (''L'',''O'',''A'',''B'',''X'',''C'',''N'')) AS Confirmed ' +
                        'FROM roomtypes rt ' +
                        'JOIN predefineddates pdd ' +
                        'LEFT JOIN roomsdate rd1 ON rd1.ADate=pdd.date ' +
                        'WHERE rt.Active=1 ' +
                        'AND (pdd.date >= ''%s'' AND pdd.date <= ''%s'') ' +
                        'AND rd1.ResFlag NOT IN (''X'',''C'',''N'')  ' +
                        'AND rd1.RoomType=rt.RoomType ' +
                        'GROUP BY pdd.date, rd1.Reservation, rt.RoomType',
            [
              uDateUtils.dateToSqlString(dtDateFrom.Date),
              uDateUtils.dateToSqlString(dtDateTo.Date)
            ]);

  iRow := HEADER_STARTS + 1;
  RoomsSet := glb.RoomTypesSet;
  RoomsSet.Filter := 'Active=1';
  RoomsSet.Filtered := True;
  try
    iCol := ROOMTYPES_START;
    NumRoomTypes := 0;
    for i := 1 to 3 do
    begin
      CellType := ctBeginBox;
      RoomsSet.First;
      while NOT RoomsSet.Eof do
      begin
        SetCellValue(iCol, iRow, RoomsSet['RoomType'], CellType);
        if i = 1 then inc(NumRoomTypes);
        iCol := iCol + 1;
        CellType := ctMiddleBox;
        RoomsSet.Next;
      end;
      if NumRoomTypes > 0 then
        grdReport.Objects[iCol - 1, iRow] := POINTER(ORD(ctEndBox));
      iCol := iCol + 1;
    end;
    WriteHeader(HEADER_STARTS);

    StartAtRow := iRow + 1;
    DatesAndGroupsSet := CreateNewDataSet;
    GroupsAndRoomTypeSet := CreateNewDataSet;
    try
      CopyToClipboard(sqlDaysAndGroups);
      hData.rSet_bySQL(DatesAndGroupsSet, sqlDaysAndGroups, false);
      CopyToClipboard(sqlGroupsAndRoomTypes);
      hData.rSet_bySQL(GroupsAndRoomTypeSet, sqlGroupsAndRoomTypes, false);

      DatesAndGroupsSet.First;

      dLastDate := 0;
      while NOT DatesAndGroupsSet.Eof do
      begin
        if (dLastDate <> DatesAndGroupsSet['ADate']) then
        begin
          if dLastDate <> 0 then
          begin
            iRow := iRow + 1;
            AddTotalsToTable(dLastDate, StartAtRow, iRow - 1, iRow);
            StartAtRow := iRow + 1;
          end;
          dLastDate := DatesAndGroupsSet['ADate'];
          iRow := iRow + 1;
          Week := DatesAndGroupsSet.FieldByName('WeekNr').AsInteger;
          SetCellValue(0, iRow, uDateUtils.RoomerDateToString(dLastDate), ctHeaderText);
          SetCellValue(2, iRow, IntToStr(Week), ctHeaderText);
          SetCellValue(ROOMTYPES_START, iRow, '', ctBeginBar);
          SetCellValue(ROOMTYPES_START + (NumRoomTypes * 3) + 1, iRow, '', ctEndBar);
        end;

        iRow := iRow + 1;
        grdReport.RowCount := iRow;

        iLastRes := DatesAndGroupsSet['Reservation'];
        SetCellValue(0, iRow, inttostr(iLastRes), ctNormalText);
        SetCellValue(1, iRow, DatesAndGroupsSet['invRefrence'], ctNormalText);
        SetCellValue(2, iRow, DatesAndGroupsSet['Name'], ctNormalText);
        SetCellValue(3, iRow, DatesAndGroupsSet['CustomerName'], ctNormalText);

        iCol := ROOMTYPES_START;
        RoomsSet.First;
        while NOT RoomsSet.Eof do
        begin
          if ScrollRoomTypeTo(GroupsAndRoomTypeSet, dLastDate, iLastRes, RoomsSet['RoomType']) then
              AddToTable(GroupsAndRoomTypeSet, DatesAndGroupsSet['invRefrence'])
          else
              AddZeroToTable(DatesAndGroupsSet, RoomsSet['RoomType']);
          RoomsSet.Next;
        end;


        DatesAndGroupsSet.Next;
      end;

      if dLastDate <> 0 then
      begin
        iRow := iRow + 1;
        AddTotalsToTable(dLastDate, StartAtRow, iRow - 1, iRow);
      end;

    finally
      FreeAndNil(DatesAndGroupsSet);
      FreeAndNil(GroupsAndRoomTypeSet);
    end;
  finally
    RoomsSet.Filtered := False;
    RoomsSet.Filter := '';
  end;
  grdReport.AutoSizeColumns(false, 4);
end;

procedure TFrmRptReservationStatusPerDay.grdReportDrawCell(Sender: TObject; ACol, ARow: Integer; Rect: TRect; State: TGridDrawState);
var grd : TAdvStringGrid;
    Borders : TCellBorders;
    PenColor : TColor;
begin
  grd := TAdvStringGrid(Sender);
  with grd do
  begin

    Borders := [];
    if getCellType(ACol, ARow) IN [ctBeginBox, ctMiddleBox, ctEndBox] then
      Borders := [cbTop,cbBottom];
    if getCellType(ACol, ARow) IN [ctBeginBox] then
      Borders := Borders + [cbLeft];
    if getCellType(ACol, ARow) IN [ctEndBox] then
      Borders := Borders + [cbRight];

    if getCellType(ACol, ARow) IN [ctBeginBar] then
      Borders := [cbLeft];
    if getCellType(ACol, ARow) IN [ctEndBar] then
      Borders := [cbRight];

    Canvas.Font.Color := grd.Font.Color;
    Canvas.Font.Style := [];
    if (getCellType(ACol, ARow) IN [ctHeaderText]) then
    begin
      Canvas.Font.Color := grd.Font.Color;
      Canvas.Font.Style := [fsBold];
    end;

    ExtTextOut(handle, Rect.Left + 2, (Rect.Top + Rect.Bottom) div 2,
      ETO_CLIPPED or ETO_OPAQUE, @Rect,
      PChar(Cells[ACol, ARow]), length(Cells[ACol, ARow]), nil);

    if Borders <> [] then
    begin
      PenColor := Canvas.Pen.Color;
      try
        Canvas.Pen.Color := clBlack;
        Canvas.Pen.Width := 1;
        if cbTop IN Borders then
        begin
          Canvas.MoveTo(Rect.Left, Rect.Top + 2);
          Canvas.LineTo(Rect.Right, Rect.Top + 2);
        end;
        if cbLeft IN Borders then
        begin
          Canvas.MoveTo(Rect.Left + 1, Rect.Top + 2);
          Canvas.LineTo(Rect.Left + 1, Rect.Bottom - 2);
        end;
        if cbRight IN Borders then
        begin
          Canvas.MoveTo(Rect.Right - 2, Rect.Bottom - 2);
          Canvas.LineTo(Rect.Right - 2, Rect.Top + 2);
        end;
        if cbBottom IN Borders then
        begin
          Canvas.MoveTo(Rect.Right, Rect.Bottom - 2);
          Canvas.LineTo(Rect.Left, Rect.Bottom - 2);
        end;
      finally
        Canvas.Pen.Color := PenColor;
      end;
    end;

  end;
end;

procedure TFrmRptReservationStatusPerDay.WriteHeader(ARow : Integer);
begin
  SetCellValue(0, ARow, 'Date', ctHeaderText);
  SetCellValue(1, ARow, 'Booking Id', ctHeaderText);
  SetCellValue(2, ARow, 'Guest name', ctHeaderText);
  SetCellValue(3, ARow, 'Customer name', ctHeaderText);

  grdReport.MergeCells(ROOMTYPES_START + (1 + NumRoomTypes) * 2, ARow, NumRoomTypes, 1);
  grdReport.MergeCells(ROOMTYPES_START + (1 + NumRoomTypes), ARow, NumRoomTypes, 1);
  grdReport.MergeCells(ROOMTYPES_START, ARow, NumRoomTypes, 1);

  SetCellValue(ROOMTYPES_START, ARow, 'Unconfirmed', ctHeaderText);
  SetCellValue(ROOMTYPES_START + (1 + NumRoomTypes) * 1, ARow, 'Confirmed', ctHeaderText);
  SetCellValue(ROOMTYPES_START + (1 + NumRoomTypes) * 2, ARow, 'Waiting list', ctHeaderText);
end;

procedure TFrmRptReservationStatusPerDay.SetCellValue(C, R : Integer; Value : String; CellType : TCellType);
begin
  grdReport.Cells[C, R] := Value;
  grdReport.Objects[C, R] := POINTER(CellType);
end;

Function TFrmRptReservationStatusPerDay.GetCellType(C, R : Integer) : TCellType;
begin
  Result := 0;
  if Assigned(grdReport.Objects[C, R]) then
    result := TCellType(grdReport.Objects[C, R]);
end;

function TFrmRptReservationStatusPerDay.ScrollRoomTypeTo(GroupsAndRoomTypeSet : TRoomerDataSet;
      ADate : TDate;
      Reservation : Integer;
      RoomType : String) : Boolean;
begin
  result := False;
  GroupsAndRoomTypeSet.First;
  while NOT GroupsAndRoomTypeSet.Eof do
  begin
    if (ADate = GroupsAndRoomTypeSet['ADate']) AND
       (Reservation = GroupsAndRoomTypeSet['Reservation']) AND
       (RoomType = GroupsAndRoomTypeSet['RoomType']) then
    begin
       result := True;
       Break;
    end;
    GroupsAndRoomTypeSet.Next;
  end;
end;

procedure TFrmRptReservationStatusPerDay.SetCol(const Value: Integer);
begin
  FCol := Value;
  if FCol > grdReport.ColCount then
    grdReport.ColCount := FCol;
end;

procedure TFrmRptReservationStatusPerDay.SetRow(const Value: Integer);
begin
  FRow := Value;
  if FRow > grdReport.RowCount then
    grdReport.RowCount := FRow;
end;

procedure TFrmRptReservationStatusPerDay.AddZeroToTable(DatesAndGroupsSet : TRoomerDataSet; RoomType : String);
begin
  SetCellValue(iCol, iRow, '', GetFirstOrLastCellTypeByColumn(iCol));
  SetCellValue(iCol + (1 + NumRoomTypes), iRow, '', GetFirstOrLastCellTypeByColumn(iCol + (1 + NumRoomTypes)));
  SetCellValue(iCol + (1 + NumRoomTypes) * 2, iRow, '', GetFirstOrLastCellTypeByColumn(iCol + (1 + NumRoomTypes) * 2));
  iCol := iCol + 1;
end;

procedure TFrmRptReservationStatusPerDay.AddToTable(GroupsAndRoomTypeSet : TRoomerDataSet; invRefrence : String);
begin
  SetCellValue(iCol, iRow, IIF(GroupsAndRoomTypeSet['UnConfirmed'] > 0, IntToStr(GroupsAndRoomTypeSet['UnConfirmed']), ''), GetFirstOrLastCellTypeByColumn(iCol));
  SetCellValue(iCol + (1 + NumRoomTypes), iRow, IIF(GroupsAndRoomTypeSet['Confirmed'] > 0, IntToStr(GroupsAndRoomTypeSet['Confirmed']), ''), GetFirstOrLastCellTypeByColumn(iCol + (1 + NumRoomTypes)));
  SetCellValue(iCol + (1 + NumRoomTypes) * 2, iRow, IIF(GroupsAndRoomTypeSet['WaitingList'] > 0, IntToStr(GroupsAndRoomTypeSet['WaitingList']), ''), GetFirstOrLastCellTypeByColumn(iCol + (1 + NumRoomTypes) * 2));
  iCol := iCol + 1;
end;

function TFrmRptReservationStatusPerDay.isEndBox(ACol : Integer) : Boolean;
begin
  result := ACol IN [ROOMTYPES_START + NumRoomTypes - 1,
                     ROOMTYPES_START + (NumRoomTypes * 2),
                     ROOMTYPES_START + (NumRoomTypes * 3) + 1];
end;

function TFrmRptReservationStatusPerDay.isLastBox(ACol : Integer) : Boolean;
begin
  result := ACol IN [ROOMTYPES_START + (NumRoomTypes * 3) + 1];
end;

function TFrmRptReservationStatusPerDay.isBeginBox(ACol : Integer) : Boolean;
begin
  result := ACol IN [ROOMTYPES_START,
                     ROOMTYPES_START + NumRoomTypes + 1,
                     ROOMTYPES_START + (1 + NumRoomTypes) * 2];
end;

function TFrmRptReservationStatusPerDay.isFirstBox(ACol : Integer) : Boolean;
begin
  result := ACol IN [ROOMTYPES_START];
end;

function TFrmRptReservationStatusPerDay.isNormalBox(ACol : Integer) : Boolean;
begin
  result := ACol IN [ROOMTYPES_START + NumRoomTypes,
                     ROOMTYPES_START + ((1 + NumRoomTypes) * 2) - 1,
                     ROOMTYPES_START + (NumRoomTypes * 3) + 2];
end;

function TFrmRptReservationStatusPerDay.GetCellTypeByColumn(ACol : Integer) : TCellType;
begin
  result := ctMiddleBox;
  if isEndBox(ACol) then
    result := ctEndBox
  else
  if isBeginBox(ACol) then
    result := ctBeginBox
  else
  if isNormalBox(ACol) then
    result := ctNormalText;
end;

function TFrmRptReservationStatusPerDay.GetFirstOrLastCellTypeByColumn(ACol : Integer) : TCellType;
begin
  result := ctNormalText;
  if isLastBox(ACol) then
    result := ctEndBar
  else
  if isFirstBox(ACol) then
    result := ctBeginBar;
end;

procedure TFrmRptReservationStatusPerDay.AddTotalsToTable(dLastDate : TDate; StartAtRow, EndAtRow, WriteInRow : Integer);
var ACol, ARow : Integer;
begin
  for ARow := StartAtRow to EndAtRow do
  begin
    for ACol := ROOMTYPES_START to grdReport.ColCount - 1 do
    begin
      SetCellValue(ACol, WriteInRow, IIF(StrToIntDef(grdReport.Cells[ACol, WriteInRow], 0) +
                                               StrToIntDef(grdReport.Cells[ACol, ARow], 0) > 0,
                                               IntToStr(StrToIntDef(grdReport.Cells[ACol, WriteInRow], 0) +
                                               StrToIntDef(grdReport.Cells[ACol, ARow], 0)),
                                               ''), GetCellTypeByColumn(ACol));
    end;

  end;
  grdReport.Cells[3, WriteInRow] := 'Total for date ' + uDateUtils.RoomerDateToString(dLastDate);
  iRow := iRow + 1;
  SetCellValue(ROOMTYPES_START, iRow, '', ctBeginBar);
  SetCellValue(ROOMTYPES_START + (NumRoomTypes * 3) + 1, iRow, '', ctEndBar);
end;

procedure TFrmRptReservationStatusPerDay.cbxMonthCloseUp(Sender: TObject);
var
  y, m : word;
  lastDay : integer;
begin
  if cbxYear.ItemIndex < 1 then
    exit;
  if cbxMonth.ItemIndex < 1 then
    exit;
  zSetDates := false;
  y := StrToInt(cbxYear.Items[cbxYear.ItemIndex]);
  m := cbxMonth.ItemIndex;

  zDateFrom := encodeDate(y, m, 1);
  lastDay := DaysInAMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;

procedure TFrmRptReservationStatusPerDay.dtDateFromChange(Sender: TObject);
begin
  if zSetDates then
  begin
    zDateFrom := dtDateFrom.Date;
    zDateTo := dtDateTo.Date;

    cbxYear.ItemIndex := 0;
    cbxMonth.ItemIndex := 0;
  end;
end;

procedure TFrmRptReservationStatusPerDay.FormCreate(Sender: TObject);
begin
  inherited;
  zSetDates := False;
  glb.fillListWithMonthsLong(cbxMonth.Items, 1);
  glb.fillListWithYears(cbxYear.Items, 1, False);
  zSetDates := True;
end;

procedure TFrmRptReservationStatusPerDay.PrepareDates;
var
  y, m, d : word;
  lastDay : integer;
begin

  decodeDate(now, y, m, d);

  cbxMonth.ItemIndex := m;
  cbxYear.ItemIndex := cbxYear.Items.IndexOf(inttostr(y));
  cbxMonthCloseUp(nil);

  zDateFrom := encodeDate(y, m, 1);
  lastDay := DaysInaMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;


end.
