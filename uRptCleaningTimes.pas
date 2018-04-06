unit uRptCleaningTimes;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, kbmMemTable, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sRadioButton,
  acPNG, sLabel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sGroupBox, sButton, Vcl.ExtCtrls, sPanel,
  uDImages, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, cxStyles,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxGridLevel,
  cxGridCustomTableView, cxGridTableView, cxGridBandedTableView, cxGridDBBandedTableView, cxGridCustomView, cxGrid,
  cxGridDBTableView, Vcl.Grids, Vcl.DBGrids, Vcl.Menus, cxTimeEdit, uRoomerForm, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg,
  dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport,
  cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLnk,
  dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter,
  dxPScxCommon, dxPSCore, dxStatusBar
  , AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxTextEdit, sEdit, Vcl.Buttons, sSpeedButton, cxCalc, cxMemo,
  uRoomerGridForm, System.Actions, Vcl.ActnList, cxCalendar, sPageControl  ;

type
  TfrmCleaningTimes = class(TfrmBaseRoomerGridForm)
    kbmCleaningTimes: TkbmMemTable;
    kbmCleaningTimesfldRoom: TWideStringField;
    kbmCleaningTimesLocation: TWideStringField;
    pnlExportButtons: TsPanel;
    btnExport: TsButton;
    gbxSelectDates: TsGroupBox;
    rbToday: TsRadioButton;
    rbYesterday: TsRadioButton;
    rbManualRange: TsRadioButton;
    dtDateFrom: TsDateEdit;
    btnRefresh: TsButton;
    pmnuExport: TPopupMenu;
    Print1: TMenuItem;
    kbmCleaningTimesStaffmember: TWideStringField;
    kbmCleaningTimesstartTime: TDateTimeField;
    kbmCleaningTimesendTime: TDateTimeField;
    kbmCleaningTimesDurationMinutes: TIntegerField;
    kbmCleaningTimesroomtype: TWideStringField;
    dtDateTo: TsDateEdit;
    tsHistory: TsTabSheet;
    tvDataLocation: TcxGridDBBandedColumn;
    tvdataRoom: TcxGridDBBandedColumn;
    tvdataRoomtype: TcxGridDBBandedColumn;
    tvdataStaffmember: TcxGridDBBandedColumn;
    tvDataStarttime: TcxGridDBBandedColumn;
    tvDataEndTime: TcxGridDBBandedColumn;
    tvDataDuration: TcxGridDBBandedColumn;
    grHistory: TcxGrid;
    tvHistory: TcxGridDBBandedTableView;
    lvHistory: TcxGridLevel;
    dsHistory: TDataSource;
    kbmHistory: TkbmMemTable;
    kbmHistoryLocation: TWideStringField;
    kbmHistoryRoom: TWideStringField;
    kbmHistoryRoomtype: TWideStringField;
    kbmHistoryStaffmember: TWideStringField;
    kbmHistoryLogtime: TDateTimeField;
    kbmHistorystatusChangedTo: TWideStringField;
    tvHistoryLocation: TcxGridDBBandedColumn;
    tvHistoryRoom: TcxGridDBBandedColumn;
    tvHistoryroomtype: TcxGridDBBandedColumn;
    tvHistorystatusChangedBy: TcxGridDBBandedColumn;
    tvHistorylogtime: TcxGridDBBandedColumn;
    tvHistorystatusChangedTo: TcxGridDBBandedColumn;
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmCleaningTimesAfterScroll(DataSet: TDataSet);
    procedure rbYesterdayClick(Sender: TObject);
    procedure rbTodayClick(Sender: TObject);
    procedure rbManualRangeClick(Sender: TObject);
    procedure btnExportClick(Sender: TObject);
    procedure pcClientChange(Sender: TObject);
  private
    function ConstructSQL: string;
  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
    { Public declarations }
  end;


/// <summary>
///   Global access point for showing the Cleaning times form, If Modalresult is OK then True is returned
/// </summary>
procedure ShowCleaningTimes();

implementation

{$R *.dfm}

uses
    uRoomerLanguage
  , uAppGlobal
  , uG
  , uUtils
  , cxGridExportLink
  , ShellApi
  , cmpRoomerDataset
  , uD
  , PrjConst
  , hData
  , DateUtils
  , uDateTimeHelper, uReservationProfile
  , uSQLUtils
  , Types
  ;

const
  cSQLCleaningTimes = 'select '#10 +
        '   r.roomtype, '#10 +
        '   r.location, '#10 +
        '   xxx.*, '#10 +
        '   xxx.endTime - xxx.startTime as durationInSec, '#10 +
        '   (xxx.endTime - xxx.startTime) div 60 as durationInMinutes '#10 +
        'from '#10 +
        ' (select -- start and endtime of cleaning '#10 +
        '        rhCleaning.room, '#10 +
        '        rhCleaning.statusChangedBy as Staffmember, '#10 +
        '        (select max(logtime) from roomcleanstate_history rh2 where rh2.statusChangedto=''%s'' and rh2.room=rhCleaning.room and rh2.logtime < (rhCleaning.logtime)) as startTime, '#10 +
        '        rhCleaning.logtime as endTime, '#10 +
        '        cast(rhCleaning.logtime as Date) as date '#10 +
        '    from roomcleanstate_history rhCleaning '#10 +
        '    where statuschangedTo = ''%s'' '#10 +
        '    and logtime between %s and %s '#10 +
        ' ) xxx '#10 +
        ' join rooms r on r.room=xxx.room '#10 +
        ' where xxx.endtime is not null and xxx.starttime is not null '#10 +
        ' order by location, room, date '#10 ;

  cSQLHistory = 'select '#10 +
        '   r.roomtype '#10 +
        '   , r.location '#10 +
        '   , rhCleaning.room '#10 +
        '   , rhCleaning.statusChangedBy '#10 +
        '   , rhCleaning.logtime '#10 +
        '   , m.name as statusChangedTo '#10 +
        'from '#10 +
        ' roomcleanstate_history rhCleaning '#10 +
        ' join rooms r on r.room=rhCleaning.room '#10 +
        ' join maintenancecodes m on rhCleaning.statusChangedTo = m.code '#10+
        ' where logtime between %s and %s '#10 +
        ' order by location, room, logtime '#10 ;

procedure ShowCleaningTimes;
var
  frm: TfrmCleaningTimes;
begin
  frm := TfrmCleaningTimes.Create(nil);
  try
    frm.ShowModal(TRoomerGridFormMode.Browse);
  finally
    frm.Free;
  end;
end;

procedure TfrmCleaningTimes.btnExportClick(Sender: TObject);
var
  btn: TsButton;
  pt: TPoint;
begin
  btn := (Sender as TsButton);
  if assigned(btn.DropDownMenu) then
  begin
    pt := btn.ClientToScreen(Point(0, btn.ClientHeight));
    btn.DropDownMenu.Popup(pt.X, pt.Y);
  end;
end;

procedure TfrmCleaningTimes.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

function TfrmCleaningTimes.ConstructSQL: string;
begin
  if ActiveGrid = grData then
    Result := Format(cSQLCleaningTimes, [ 'W', 'R', _db(dtDateFrom.Date), _db(dtDateTo.Date.AddDays(1))])
  else if ActiveGrid = grHistory then
    Result := Format(cSQLHistory, [_db(dtDateFrom.Date), _db(dtDateTo.Date.AddDays(1))]);
  CopyToClipboard(Result);
end;

procedure TfrmCleaningTimes.DoShow;
begin
  inherited;
  pmnuExport.Items.Add(GridExporter.ExportSubMenu);
  DialogButtons := [mbClose];
  pcClient.ActivePage := tsMain;
  RefreshData;
end;

procedure TfrmCleaningTimes.kbmCleaningTimesAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmCleaningTimes.pcClientChange(Sender: TObject);
begin
  inherited;
  GridExporter.ActiveGrid := ActiveGrid;
end;

procedure TfrmCleaningTimes.rbManualRangeClick(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmCleaningTimes.rbTodayClick(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmCleaningTimes.rbYesterdayClick(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmCleaningTimes.DoLoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  if NOT btnRefresh.Enabled then exit;

  btnRefresh.Enabled := False;
  try
    kbmCleaningTimes.DisableControls;
    kbmHistory.DisableControls;
    try
      rSet1 := CreateNewDataSet;
      try
        s := ConstructSQL;

        hData.rSet_bySQL(rSet1, s);
        rSet1.First;

        if ActiveGrid = grData then
        begin
          if not kbmCleaningTimes.Active then
            kbmCleaningTimes.Open;
          LoadKbmMemtableFromDataSetQuiet(kbmCleaningTimes,rSet1,[]);
          tvData.ViewData.Expand(True);
          kbmCleaningTimes.First;
        end
        else if ActiveGRid = grHistory then
        begin
          if not kbmHistory.Active then
            kbmHistory.Open;
          LoadKbmMemtableFromDataSetQuiet(kbmHistory,rSet1,[]);
          kbmHistory.First;
        end;

      finally
        FreeAndNil(rSet1);
      end;


    finally
      kbmHistory.EnableControls;
      kbmCleaningTimes.EnableControls;
    end;
  finally
    btnRefresh.Enabled := True;
  end;
end;


procedure TfrmCleaningTimes.DoUpdateControls;
begin
  inherited;

  if rbToday.Checked then
  begin
    dtDateFrom.Date := now;
    dtDateTo.Date := now;
  end;
  if rbYesterday.Checked then
  begin
    dtDateFrom.Date := TDateTime.Yesterday;
    dtDateTo.Date := TDateTime.Yesterday;
  end;

  dtDateFrom.Enabled := rbManualRange.Checked;
  dtDateTo.Enabled := rbManualRange.Checked;
  btnExport.Enabled := HasData;
end;


end.
