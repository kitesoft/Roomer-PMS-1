unit uRoomerGridForm;

interface

uses
  WIndows, uRoomerForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, cxStyles,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, System.Classes, System.Actions, Vcl.ActnList, dxPSCore, dxPScxCommon,
  cxClasses, kbmMemTable, cxGridLevel, cxGridCustomView, cxGridCustomTableView, cxGridTableView, cxGridDBTableView,
  cxGrid, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, Vcl.Forms, sPanel, cxPropertiesStore, Vcl.Controls, dxStatusBar
  ;

type
  TfrmBaseRoomerGridForm = class(TfrmBaseRoomerForm)
    kbmGridData: TkbmMemTable;
    dsGridData: TDataSource;
    pnlTop: TsPanel;
    pnlActionButtons: TsPanel;
    grData: TcxGrid;
    lvGridDataLevel1: TcxGridLevel;
    grDataDBTableView1: TcxGridDBTableView;
    cxGridStyleRepository: TcxStyleRepository;
    cxsBoldStyle: TcxStyle;
    btnReport: TsButton;
    gridPrinter: TdxComponentPrinter;
    gridPrinterLink1: TdxGridReportLink;
    alGridActions: TActionList;
    acPrint: TAction;
    acRefresh: TAction;
    btnRefresh: TsButton;
    pnlSelection: TsPanel;
    acExportExcel: TAction;
    btnExcel: TsButton;
    procedure kbmGridDataAfterScroll(DataSet: TDataSet);
    procedure acRefreshExecute(Sender: TObject);
    procedure acPrintExecute(Sender: TObject);
    procedure acExportExcelExecute(Sender: TObject);
    procedure acGridDependentActionUpdate(Sender: TObject);
  private
    function GridContainsData: boolean;
  protected
    procedure LoadData; override;
    function ConstructSQLStatement: string; virtual;
  public
    { Public declarations }
  end;



implementation

{$R *.dfm}

uses
    uG
  , IOUtils
  , hData
  , SysUtils
  , cxGridExportLink
  , ShellApi
  , cmpRoomerDataset
  , uD
  , uUtils
  ;



function TfrmBaseRoomerGridForm.GridContainsData: boolean;
begin
  Result := kbmGridData.Active and not kbmGridData.IsEmpty;
end;

procedure TfrmBaseRoomerGridForm.acExportExcelExecute(Sender: TObject);
var
  sFilename : string;
  s         : string;
  c : char;
const
  cFilenameReplaceChar: char = '_';
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFileName := TPath.Combine(g.qProgramPath, s);

  s := Caption;
  for c in Caption do
    if not TPath.IsValidFileNameChar(c) then
      s := s.Replace(c, cFilenameReplaceChar);

  sFilename := sFileName + s;
  ExportGridToExcel(sFilename, grData, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmBaseRoomerGridForm.acPrintExecute(Sender: TObject);
begin
  gridPrinter.PrintTitle := Caption;
  gridPrinterLink1.ReportTitle.Text := Caption;
  gridPrinterLink1.ComponentPrinter := gridPrinter;
  gridPrinter.Print(True, nil, gridPrinterLink1);
end;

procedure TfrmBaseRoomerGridForm.acGridDependentActionUpdate(Sender: TObject);
begin
  inherited;
  TAction(Sender).Enabled := GridContainsData;
end;

procedure TfrmBaseRoomerGridForm.acRefreshExecute(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmBaseRoomerGridForm.kbmGridDataAfterScroll(DataSet: TDataSet);
begin
  if not Dataset.ControlsDisabled then
    UpdateControls;
end;

function TfrmBaseRoomerGridForm.ConstructSQLStatement: string;
begin
  // if not overridden then no data is delivered
  Result := 'SELECT ''<NO DATA>'' as Result';
end;

procedure TfrmBaseRoomerGridForm.LoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  inherited;

  Screen.Cursor := crHourglass;
  try
    kbmGridData.DisableControls;
    try
      rSet1 := CreateNewDataSet;
      try
        kbmGridData.EmptyTable;
        s := ConstructSQLStatement;

        hData.rSet_bySQL(rSet1, s, false);
        rSet1.First;
        if not kbmGridData.Active then
          kbmGridData.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmGridData,rSet1,[]);
      finally
        FreeAndNil(rSet1);
      end;
      kbmGridData.First;

    finally
      kbmGridData.EnableControls;
    end;
  finally
    Screen.Cursor := crDefault;
  end;
end;


end.
