unit uRptReservationStatusPerDay;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, DateUtils,
  uRoomerForm, uAppGlobal, uFileDependencyManager, uUtils, cmpRoomerDataSet, uDateUtils, uFileSystemUtils,
  frxClass, frxDBSet, frxDesgn, Vcl.StdCtrls, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sButton, sComboBox, sGroupBox, sLabel,
  Vcl.ExtCtrls, sPanel, Data.DB, kbmMemTable;

type
  TFrmRptReservationStatusPerDay = class(TfrmBaseRoomerForm)
    fdRegFormDesigner: TfrxDesigner;
    rptForm: TfrxReport;
    dsForm: TfrxDBDataset;
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
    tblDaysAndGroups: TkbmMemTable;
    dsDays: TDataSource;
    dslUnconfirmed: TDataSource;
    tblUnconfirmed: TkbmMemTable;
    tblConfirmed: TkbmMemTable;
    dsConfirmed: TDataSource;
    tblWaitingList: TkbmMemTable;
    dsWaitingList: TDataSource;
    procedure FormCreate(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure cbxMonthCloseUp(Sender: TObject);
    procedure dtDateFromChange(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    zSetDates : Boolean;
    zDateFrom : TDate;
    lastDay   : Integer;
    zDateTo   : TDate;

    procedure FormDesignMode;
    procedure GetResData;
    procedure PrepareDates;
    procedure AddToTable(GroupsAndRoomTypeSet : TRoomerDataSet; invRefrence : String);
    procedure AddNumbersToTable(tbl: TKbmMemTable; numRooms: Integer; ADate: TDate; Reservation, WeekNr: Integer; invRefrence: String; RoomType: String);
    procedure AddZeroToTable(DatesAndGroupsSet: TRoomerDataSet; RoomType: String);
    function ScrollRoomTypeTo(GroupsAndRoomTypeSet: TRoomerDataSet; ADate: TDate; Reservation: Integer; RoomType: String) : Boolean;
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmRptReservationStatusPerDay: TFrmRptReservationStatusPerDay;

procedure ShowRptReservationStatusPerDay;

implementation

{$R *.dfm}

uses hData,
     uD
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
  if IsControlKeyPressed then
    FormDesignMode
  else
  begin
    dsForm.DataSet := tblDaysAndGroups;
    dsForm.Open;
    rptForm.DataSets.Add(dsForm);
    try
//      rptForm.LoadFromFile(FileDependencyManager.getResStatusPerDayFormFilePath());
      rptForm.PrepareReport(True);
      rptForm.ShowPreparedReport;
    finally
      rptForm.DataSets.Clear;
    end;
  end;
end;

procedure TFrmRptReservationStatusPerDay.FormDesignMode;
var
  filename: String;
begin
  filename := FileDependencyManager.getResStatusPerDayFormFilePath;
  dsForm.DataSet := tblDaysAndGroups;
  dsForm.Open;
  rptForm.DataSets.Add(dsForm);
  try
    if FileExists(filename) AND (GetFileSize(filename) >= 10) then
      rptForm.LoadFromFile(filename)
    else
      rptForm.FileName := filename;
    rptForm.DesignReport(True);
    FileDependencyManager.sendChangedFile(filename);
  finally
    rptForm.DataSets.Clear;
  end;
end;

procedure TFrmRptReservationStatusPerDay.FormShow(Sender: TObject);
begin
  inherited;
  PrepareDates;
end;

procedure TFrmRptReservationStatusPerDay.GetResData;
var sqlDaysAndGroups : String;
    sqlGroupsAndRoomTypes : String;
    DatesAndGroupsSet : TRoomerDataSet;
    GroupsAndRoomTypeSet : TRoomerDataSet;
    RoomsSet : TRoomerDataSet;
    iLastRes : Integer;
    dLastDate : TDate;
    i : Integer;
begin
  sqlDaysAndGroups    := format('SELECT DISTINCT DATE(rd.ADate) AS ADate, WEEK(rd.ADate) AS WeekNr, r.Reservation, r.invRefrence, '  +
                   'r.Name, r.Customer, cu.Surname AS CustomerName ' +
                   'FROM reservations r JOIN roomsdate rd ON r.Reservation=rd.Reservation JOIN customers cu ON cu.Customer=r.Customer ' +
                   'WHERE (rd.ADate >= ''%s'' AND rd.ADate <= ''%s'') AND rd.ResFlag NOT IN (''X'',''C'',''N'') ' +
                   'GROUP BY rd.ADate, rd.Reservation, rd.RoomType',
            [
              uDateUtils.dateToSqlString(dtDateFrom.Date),
              uDateUtils.dateToSqlString(dtDateTo.Date)
            ]);

  sqlGroupsAndRoomTypes := format('SELECT DATE(pdd.date) AS ADate, WEEK(pdd.date) AS WeekNr, rt.RoomType, rd1.Reservation, ' +
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

  RoomsSet := glb.RoomTypesSet;
  DatesAndGroupsSet := CreateNewDataSet;
  GroupsAndRoomTypeSet := CreateNewDataSet;
  try
    CopyToClipboard(sqlDaysAndGroups);
    hData.rSet_bySQL(DatesAndGroupsSet, sqlDaysAndGroups, false);
    CopyToClipboard(sqlGroupsAndRoomTypes);
    hData.rSet_bySQL(GroupsAndRoomTypeSet, sqlGroupsAndRoomTypes, false);

    DatesAndGroupsSet.First;
    tblDaysAndGroups.Close;
    tblDaysAndGroups.Open;

    iLastRes := 0;
    dLastDate := 0;
    while NOT DatesAndGroupsSet.Eof do
    begin
      if (dLastDate <> DatesAndGroupsSet['ADate']) AND
         (iLastRes <> DatesAndGroupsSet['Reservation']) then
      begin
        tblDaysAndGroups.Insert;
          tblDaysAndGroups['dtDate'] := DatesAndGroupsSet['ADate'];
          tblDaysAndGroups['Reservation'] := DatesAndGroupsSet['Reservation'];
          tblDaysAndGroups['WeekNr'] := DatesAndGroupsSet['WeekNr'];
          tblDaysAndGroups['invRefrence'] := DatesAndGroupsSet['invRefrence'];
          tblDaysAndGroups['Name'] := DatesAndGroupsSet['Name'];
          tblDaysAndGroups['CustomerName'] := DatesAndGroupsSet['CustomerName'];
        tblDaysAndGroups.Post;

        dLastDate := DatesAndGroupsSet['ADate'];
        iLastRes := DatesAndGroupsSet['Reservation'];

        RoomsSet.First;
        while NOT RoomsSet.Eof do
        begin
          if ScrollRoomTypeTo(GroupsAndRoomTypeSet, dLastDate, iLastRes, RoomsSet['RoomType']) then
              AddToTable(GroupsAndRoomTypeSet, DatesAndGroupsSet['invRefrence'])
          else
              AddZeroToTable(DatesAndGroupsSet, RoomsSet['RoomType']);
          RoomsSet.Next;
        end;
          
      end;

      DatesAndGroupsSet.Next;
    end;

  tblDaysAndGroups.First;
  finally
    FreeAndNil(DatesAndGroupsSet);
    FreeAndNil(GroupsAndRoomTypeSet);
  end;
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

procedure TFrmRptReservationStatusPerDay.AddZeroToTable(DatesAndGroupsSet : TRoomerDataSet; RoomType : String);
var tbl : TKbmMemTable;
    numRooms : Integer;
  i: Integer;
begin
  for i := 1 to 3 do
  begin
    case i of
      1 : tbl := tblUnconfirmed;
      2 : tbl := tblWaitingList;
      3 : tbl := tblConfirmed;
    end;
    AddNumbersToTable(tbl, 
        0, 
        DatesAndGroupsSet['ADate'],
        DatesAndGroupsSet['Reservation'],
        DatesAndGroupsSet['WeekNr'],
        DatesAndGroupsSet['invRefrence'],
        RoomType
    );
  end;
end;

procedure TFrmRptReservationStatusPerDay.AddToTable(GroupsAndRoomTypeSet : TRoomerDataSet; invRefrence : String);
var tbl : TKbmMemTable;
    numRooms : Integer;
  i: Integer;
begin
  for i := 1 to 3 do
  begin
    case i of
      1 : begin  
            tbl := tblUnconfirmed;
            numRooms := GroupsAndRoomTypeSet['UnConfirmed'];
          end;
      2 : begin  
            tbl := tblWaitingList;
            numRooms := GroupsAndRoomTypeSet['WaitingList'];
          end;
      3 : begin  
            tbl := tblConfirmed;
            numRooms := GroupsAndRoomTypeSet['Confirmed'];
          end;
    end;
    AddNumbersToTable(tbl, 
        numRooms, 
        GroupsAndRoomTypeSet['ADate'],
        GroupsAndRoomTypeSet['Reservation'],
        GroupsAndRoomTypeSet['WeekNr'],
        invRefrence,
        GroupsAndRoomTypeSet['RoomType']
    );
  end;
end;

procedure TFrmRptReservationStatusPerDay.AddNumbersToTable(tbl : TKbmMemTable; 
    numRooms : Integer; 
    ADate : TDate;
    Reservation : Integer;
    WeekNr : Integer;
    invRefrence : String;
    RoomType : String
    );
begin
  tbl.Insert;
    tbl['dtDate'] := ADate;
    tbl['Reservation'] := Reservation;
    tbl['WeekNr'] := WeekNr;
    tbl['invRefrence'] := invRefrence;
    tbl['RoomType'] := RoomType;
    tbl['NumRooms'] := numRooms;
  tbl.Post;
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
