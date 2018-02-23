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
  uRoomerGridForm, System.Actions, Vcl.ActnList, cxCalendar  ;

type
  TfrmCleaningTimes = class(TfrmBaseRoomerGridForm)
    kbmCleaningTimes: TkbmMemTable;
    kbmCleaningTimesfldRoom: TWideStringField;
    kbmCleaningTimesLocation: TWideStringField;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
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
    tvDataLocation: TcxGridDBBandedColumn;
    tvDataRoom: TcxGridDBBandedColumn;
    tvDataroomtype: TcxGridDBBandedColumn;
    tvDatastartTime: TcxGridDBBandedColumn;
    tvDataendTime: TcxGridDBBandedColumn;
    tvDataDurationInMinutes: TcxGridDBBandedColumn;
    tvDataStaffmember: TcxGridDBBandedColumn;
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmCleaningTimesAfterScroll(DataSet: TDataSet);
    procedure rbYesterdayClick(Sender: TObject);
    procedure rbTodayClick(Sender: TObject);
    procedure rbManualRangeClick(Sender: TObject);
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
  , uDateTimeHelper, uReservationProfile, uSQLUtils;

const
  cSQL = 'select '#10 +
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
        ' order by room, date '#10 ;

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

procedure TfrmCleaningTimes.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

function TfrmCleaningTimes.ConstructSQL: string;
begin
  Result := Format(cSQL, [ 'W', 'R', _db(dtDateFrom.Date), _db(dtDateTo.Date.AddDays(1))]);
  CopyToClipboard(Result);
end;

procedure TfrmCleaningTimes.DoShow;
begin
  inherited;
  pmnuExport.Items.Add(GridExporter.ExportSubMenu);
  DialogButtons := [mbClose];
  RefreshData;
end;

procedure TfrmCleaningTimes.kbmCleaningTimesAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
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
    try
      rSet1 := CreateNewDataSet;
      try
        s := ConstructSQL;

        hData.rSet_bySQL(rSet1, s);
        rSet1.First;
        if not kbmCleaningTimes.Active then
          kbmCleaningTimes.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmCleaningTimes,rSet1,[]);
      finally
        FreeAndNil(rSet1);
      end;

      tvData.ViewData.Expand(True);

      kbmCleaningTimes.First;
    finally
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
  btnExcel.Enabled := HasData;
end;


end.
