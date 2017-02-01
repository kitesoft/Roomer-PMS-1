unit uUserActivityReport;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.StdCtrls, sEdit, sSpinEdit, sLabel, Vcl.Menus, dxPSCore, cxGridLevel,
  cxGridCustomView, cxGridCustomTableView, cxGridDBTableView, cxGrid, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit,
  sGroupBox, sButton, Vcl.ExtCtrls, sPanel, sComboBox

  , uRoomerHotelServicesCommunicationModel_RequestsResponses
  ;

type


  TListDataSource = class(TcxCustomDataSource)
  private
    FList  : TUserActivityLogFragment;
  protected
    function GetRecordCount: Integer; override;
    function GetValue(ARecordHandle: TcxDataRecordHandle; AItemHandle: TcxDataItemHandle): Variant; override;
  public
    constructor Create(aList : TUserActivityLogFragment);
  end;


  TfrmUserActivityReport = class(TfrmBaseRoomerForm)
    pnlFilter: TsPanel;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
    btnProfile: TsButton;
    btnInvoice: TsButton;
    btnReport: TsButton;
    grActivityLog: TcxGrid;
    grActivityLogDBTableView1: TcxGridDBTableView;
    lvArrivalsListLevel1: TcxGridLevel;
    grdPrinter: TdxComponentPrinter;
    grdPrinterLink1: TdxGridReportLink;
    pmnuInvoiceMenu: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    pnmuGridMenu: TPopupMenu;
    mnuCheckin: TMenuItem;
    mnuProfile: TMenuItem;
    mnuInvoice: TMenuItem;
    mnuRoomInvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    lblFrom: TsLabel;
    lblTo: TsLabel;
    tmFrom: TsTimePicker;
    tmTo: TsTimePicker;
    gbxRestrictions: TsGroupBox;
    lblCategory: TsLabel;
    lbAction: TsLabel;
    cbxCategories: TsComboBox;
    cbxActions: TsComboBox;
    procedure FormShow(Sender: TObject);
  private
    FGridDataSource: TListDataSource;
    FCatsAndActions: TUserActivityCategoriesOverview;
    FLogEventFragment: TUserActivityLogFragment;
    procedure PopulateComboboxes;
    { Private declarations }

  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
  end;

procedure ShowUserActivityReport;

implementation

uses
  uHotelServicesAPICaller
  ;

{$R *.dfm}
procedure ShowUserActivityReport;
begin
  with TfrmUserActivityReport.Create(nil) do
  try
    ShowModal;
  finally
    Free;
  end;
end;


procedure TfrmUserActivityReport.PopulateComboboxes;
var
  lAPi: TUserActivityLogAPICaller;
begin
  cbxCategories.Clear;
  lApi := TUserActivityLogAPICaller.Create;
  try
    lApi.GetAllCategoriesAndActionsForHotel(FCatsAndActions);
  finally
    lApi.Free;
  end;

  FCatsAndActions.AddCategoryNamesAsString(cbxCategories.Items);
  cbxCategories.ItemIndex := -1;
end;

constructor TfrmUserActivityReport.Create(aOwner: TComponent);
begin
  inherited;
  FCatsAndActions := TUserActivityCategoriesOverview.Create;
  FLogEventFragment := TUserActivityLogFragment.Create;
  FGridDataSource := TListDataSource(FLogEventFragment);

  grActivityLogDBTableView1.DataController.CustomDataSource := FGridDatasource;
end;

destructor TfrmUserActivityReport.Destroy;
begin
  FCatsAndActions.Free;
  FLogEventFragment.Free;
  inherited;
end;

procedure TfrmUserActivityReport.DoLoadData;
var
  lAPi: TUserActivityLogAPICaller;
begin
  inherited;
  FLogEventFragment.Clear;
  lApi := TUserActivityLogAPICaller.Create;
  try
    if lApi.GetLogFragment(0,0,0,0,FLogEventFragment) then
      FGridDatasource.DataChanged;

  finally
    lApi.Free;
  end;
end;

procedure TfrmUserActivityReport.DoUpdateControls;
begin
  inherited;
  cbxCategories.Enabled := cbxCategories.Items.Count > 0;
  cbxActions.Enabled := (cbxCategories.ItemIndex <> -1);
end;

procedure TfrmUserActivityReport.FormShow(Sender: TObject);
begin
  inherited;

  PopulateComboboxes;
end;

{ TListDataSource }

constructor TListDataSource.Create(aList: TUserActivityLogFragment);
begin
  inherited Create;
  FList := aList;
end;

function TListDataSource.GetRecordCount: Integer;
begin
  Result := FList.LogEventList.Count;
end;

function TListDataSource.GetValue(ARecordHandle: TcxDataRecordHandle; AItemHandle: TcxDataItemHandle): Variant;
var
  lRecordIndex: integer absolute aRecordHandle;
  lFieldIndex: integer absolute aItemHandle;
begin
  Result := '';
  if (lRecordIndex >= 0) and (lRecordIndex < Flist.LogEventList.Count) then
  begin
    case lFieldIndex of
      0 : Result := FList.LogEventList[lRecordIndex].Description;
      1 : Result := FList.LogEventList[lRecordIndex].DetailedDescription;
      2 : Result := FList.LogEventList[lRecordIndex].MachineName;
      3 : Result := FList.LogEventList[lRecordIndex].OldValue;
      4 : Result := FList.LogEventList[lRecordIndex].NewValue;
      5 : Result := FList.LogEventList[lRecordIndex].Code;
      6 : Result := FList.LogEventList[lRecordIndex].UserId;
      7 : Result := FList.LogEventList[lRecordIndex].Category;
      8 : Result := FList.LogEventList[lRecordIndex].Action;
      9 : Result := FList.LogEventList[lRecordIndex].ActionDateTime;
      10 : Result := FList.LogEventList[lRecordIndex].ActionAffectsDate;
      11 : Result := FList.LogEventList[lRecordIndex].UserLocation;
      12 : Result := FList.LogEventList[lRecordIndex].Reservation;
      13 : Result := FList.LogEventList[lRecordIndex].Roomreservation;
      14 : Result := FList.LogEventList[lRecordIndex].id1;
      15 : Result := FList.LogEventList[lRecordIndex].id2;
      16 : Result := FList.LogEventList[lRecordIndex].id3;
    end;
  end;
end;

end.
