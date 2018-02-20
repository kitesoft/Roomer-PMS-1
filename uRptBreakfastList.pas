unit uRptBreakfastList;

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
  uRoomerGridForm, System.Actions, Vcl.ActnList  ;

type
  TfrmBreakfastList = class(TfrmBaseRoomerGridForm)
    kbmBreakfastList: TkbmMemTable;
    kbmBreakfastListfldRoom: TStringField;
    kbmBreakfastListfldGuestName: TStringField;
    kbmBreakfastListfldNumGuests: TIntegerField;
    kbmBreakfastListRoomerRoomReservationID: TIntegerField;
    kbmBreakfastListLocation: TWideStringField;
    kbmBreakfastListLocationDescription: TWideStringField;
    kbmBreakfastListnumChildren: TIntegerField;
    kbmBreakfastListnumInfants: TIntegerField;
    kbmBreakfastListRoomnotes: TWideMemoField;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
    btnProfile: TsButton;
    gbxSelectDates: TsGroupBox;
    rbToday: TsRadioButton;
    rbTomorrow: TsRadioButton;
    rbManualRange: TsRadioButton;
    dtDate: TsDateEdit;
    btnRefresh: TsButton;
    tvDataRoom: TcxGridDBBandedColumn;
    tvDataMainGuest: TcxGridDBBandedColumn;
    tvDataNumGuests: TcxGridDBBandedColumn;
    tvDataRoomReservationID: TcxGridDBBandedColumn;
    tvDataLocation: TcxGridDBBandedColumn;
    tvDataLocationDescription: TcxGridDBBandedColumn;
    tvDatanumChildren: TcxGridDBBandedColumn;
    tvDatanumInfants: TcxGridDBBandedColumn;
    tvDataRoomnotes: TcxGridDBBandedColumn;
    kbmBreakfastListReservations: TIntegerField;
    tvDataReservation: TcxGridDBBandedColumn;
    pmnuExport: TPopupMenu;
    Print1: TMenuItem;
    procedure rbRadioButtonClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmBreakfastListAfterScroll(DataSet: TDataSet);
    procedure btnProfileClick(Sender: TObject);
    procedure tvDataCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
    procedure tvDataGetDisplayTextHideZeroes(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
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
///   Global access point for showing the arrival report form, If Modalresult is OK then True is returned
/// </summary>
procedure ShowBreakfastList();

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
  cSQL = 'SELECT '#10 +
         '        rr.reservation '#10+
         '      , rr.Roomreservation '#10+
         '      , rr.Room '#10+
         '      , r.location '#10+
         '      , l.description as LocationDescription '#10+
         '      , (SELECT count(id) FROM persons pe WHERE pe.roomreservation = rr.roomreservation) AS NumGuests '#10+
         '      , rr.numChildren '#10+
         '      , rr.numInfants '#10+
         '      , rr.HiddenInfo as RoomNotes '#10+
         '      , (SELECT pe.Name FROM persons pe WHERE pe.roomreservation = rr.roomreservation and pe.MainName LIMIT 1) As MainGuest '#10+
         ' from roomreservations rr '#10+
         ' left join rooms r on r.room = rr.room '#10+
         ' left join locations l on r.location = l.location '#10+
         ' where '#10+
         '     rr.roomreservation in '#10+
         '        (select distinct(roomreservation) '#10+
         '         from roomsdate rd '#10+
         '         where aDate = DATE_ADD(%s, INTERVAL -1 DAY) and resflag not in (''X'', ''C'', ''B'')) '#10+
         '     AND rr.breakfast <> ''NONE'' ';


procedure ShowBreakfastList;
var
  frm: TfrmBreakfastList;
begin
  frm := TfrmBreakfastList.Create(nil);
  try
    frm.ShowModal(TRoomerGridFormMode.Browse);
  finally
    frm.Free;
  end;
end;

procedure TfrmBreakfastList.btnProfileClick(Sender: TObject);
begin
  if EditReservation(kbmBreakfastList['Reservation'], kbmBreakfastList['RoomReservation']) then
    RefreshData;
end;

procedure TfrmBreakfastList.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

function TfrmBreakfastList.ConstructSQL: string;
begin
  Result := Format(cSQL, [_db(dtDate.Date)]);
  CopyToClipboard(Result);
end;

procedure TfrmBreakfastList.DoShow;
begin
  inherited;
  pmnuExport.Items.Add(GridExporter.ExportSubMenu);
  DialogButtons := [mbClose];
  RefreshData;
end;

procedure TfrmBreakfastList.tvDataCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  inherited;
  btnProfile.Click;
end;

procedure TfrmBreakfastList.tvDataGetDisplayTextHideZeroes(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  if aText = '0' then aText := '';
end;

procedure TfrmBreakfastList.kbmBreakfastListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmBreakfastList.rbRadioButtonClick(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmBreakfastList.DoLoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  if NOT btnRefresh.Enabled then exit;

  btnRefresh.Enabled := False;
  try
    kbmBreakfastList.DisableControls;
    try
      rSet1 := CreateNewDataSet;
      try
        s := ConstructSQL;

        hData.rSet_bySQL(rSet1, s);
        rSet1.First;
        if not kbmBreakfastList.Active then
          kbmBreakfastList.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmBreakfastList,rSet1,[]);
      finally
        FreeAndNil(rSet1);
      end;

      kbmBreakfastList.First;

      tvData.ViewData.Expand(True);

    finally
      kbmBreakfastList.EnableControls;
    end;
  finally
    btnRefresh.Enabled := True;
  end;
end;


procedure TfrmBreakfastList.DoUpdateControls;
begin
  inherited;

  if rbToday.Checked then
    dtDate.Date := now;
  if rbTomorrow.Checked then
    dtDate.Date := TDateTime.Tomorrow;

  btnProfile.Enabled := HasData;
  btnExcel.Enabled := HasData;
end;


end.
