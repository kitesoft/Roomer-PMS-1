unit uInvoiceList2;

interface

uses
    Windows
  , Messages
  , SysUtils
  , Variants
  , Classes
  , Graphics
  , Controls
  , shellapi
  , Forms
  , Dialogs
  , DateUtils
  , DB
  , ug
  , ADODB
  , Grids
  , StdCtrls
  , ExtCtrls
  , System.Generics.Collections

  , kbmMemTable
  , hdata
  , _glob
  , uUtils

  , Mask
  , ImgList
  , cxGraphics
  , cxControls
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , cxStyles
  , cxCustomData
  , cxFilter
  , cxData
  , cxDataStorage
  , cxEdit
  , cxDBData
  , cxGridCustomTableView
  , cxGridTableView
  , cxGridDBTableView
  , cxGridLevel
  , cxClasses
  , cxGridCustomView
  , cxGrid
  , cxPC
  , cxGridExportLink
  , cxPCdxBarPopupMenu
  , cxNavigator
  , cxGridBandedTableView
  , cxGridDBBandedTableView

  , DBCtrls
  , cmpRoomerDataSet
  , cmpRoomerConnection
  , dxSkinsCore
  , dxSkinDarkSide
  , dxSkinDevExpressDarkStyle
  , dxSkinMcSkin
  , dxSkinOffice2013White
  , dxSkinsDefaultPainters
  , dxSkinscxPCPainter
  , cxPropertiesStore
  , sRadioButton
  , sComboBox
  , sEdit
  , sGroupBox
  , sButton
  , sPanel
  , sLabel
  , Vcl.Buttons

  , Vcl.ComCtrls
  , sSpeedButton
  , sSpinEdit
  , sMaskEdit
  , sCustomComboEdit
  , sTooledit
  , sPageControl, cxCurrencyEdit, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, dxSkinBlack, dxSkinBlue, dxSkinBlueprint,
  dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast, dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue, Vcl.Menus
  , uRoomerForm, dxPScxCommon, dxPScxGridLnk, sStatusBar, cxCheckBox
  ;

type
  TfrmInvoiceList2 = class(TfrmBaseRoomerForm)
    LMDSimplePanel1: TsPanel;
    LMDGroupBox1: TsGroupBox;
    dtFrom: TsDateEdit;
    dtTo: TsDateEdit;
    rbtDates: TsRadioButton;
    rbtInvoices: TsRadioButton;
    LMDSimpleLabel2: TsLabel;
    LMDSimpleLabel3: TsLabel;
    cbxPeriod: TsComboBox;
    edtFreeText: TsEdit;
    rbtFreeText: TsRadioButton;
    LMDSpeedButton3: TsButton;
    rbtLast: TsRadioButton;
    cbxTxtType: TsComboBox;
    edtLast: TsSpinEdit;
    edtInvoiceFrom: TsSpinEdit;
    edtInvoiceTo: TsSpinEdit;
    FormStore: TcxPropertiesStore;
    pnlFilter: TsPanel;
    mDS: TDataSource;
    m22_: TkbmMemTable;
    grInvoiceHead: TcxGrid;
    tvInvoiceHead: TcxGridDBBandedTableView;
    tvInvoiceHeadInvoiceNumber: TcxGridDBBandedColumn;
    tvInvoiceHeadInvoiceDate: TcxGridDBBandedColumn;
    tvInvoiceHeadDueDate: TcxGridDBBandedColumn;
    tvInvoiceHeadCreditType: TcxGridDBBandedColumn;
    tvInvoiceHeadNameOnInvoice: TcxGridDBBandedColumn;
    tvInvoiceHeadInvoicetype: TcxGridDBBandedColumn;
    tvInvoiceHeadLink: TcxGridDBBandedColumn;
    tvInvoiceHeadAmount: TcxGridDBBandedColumn;
    tvInvoiceHeadWithOutVAT: TcxGridDBBandedColumn;
    tvInvoiceHeadVAT: TcxGridDBBandedColumn;
    tvInvoiceHeadTaxes: TcxGridDBBandedColumn;
    tvInvoiceHeadTaxunits: TcxGridDBBandedColumn;
    tvInvoiceHeadCurrency: TcxGridDBBandedColumn;
    tvInvoiceHeadCurrencyRate: TcxGridDBBandedColumn;
    tvInvoiceHeadCurrencyAmount: TcxGridDBBandedColumn;
    tvInvoiceHeadRoomGuest: TcxGridDBBandedColumn;
    tvInvoiceHeadCustomer: TcxGridDBBandedColumn;
    tvInvoiceHeadCompanyId: TcxGridDBBandedColumn;
    tvInvoiceHeadCustomerName: TcxGridDBBandedColumn;
    tvInvoiceHeadAddress1: TcxGridDBBandedColumn;
    tvInvoiceHeadAddress2: TcxGridDBBandedColumn;
    tvInvoiceHeadAddress3: TcxGridDBBandedColumn;
    tvInvoiceHeadRefrence: TcxGridDBBandedColumn;
    tvInvoiceHeadStaff: TcxGridDBBandedColumn;
    tvInvoiceHeadConfirmdate: TcxGridDBBandedColumn;
    tvInvoiceHeadReservation: TcxGridDBBandedColumn;
    tvInvoiceHeadRoomReservation: TcxGridDBBandedColumn;
    lvInvoiceHead: TcxGridLevel;
    cLabFilter: TsLabel;
    edFilter: TsEdit;
    btnClear: TsSpeedButton;
    tvInvoiceHeadRowSelected: TcxGridDBBandedColumn;
    tvInvoiceHeadexternalInvoiceId: TcxGridDBBandedColumn;
    pnlButtons: TsPanel;
    LMDSpeedButton6: TsButton;
    btnReservation: TsButton;
    LMDSpeedButton1: TsButton;
    btnViewInvoice: TsButton;
    btnPrint: TsButton;
    btnBestFit: TsButton;
    LMDButton1: TsButton;
    tvInvoiceHeadpaytypes: TcxGridDBBandedColumn;
    tvInvoiceHeadpayments: TcxGridDBBandedColumn;
    tvInvoiceHeadLocalAmount: TcxGridDBBandedColumn;
    tvInvoiceHeadLocalWithOutVAT: TcxGridDBBandedColumn;
    tvInvoiceHeadLocalVAT: TcxGridDBBandedColumn;
    pmnuExportMenu: TPopupMenu;
    mnuExport: TMenuItem;
    N1: TMenuItem;
    mnuExportability: TMenuItem;
    tvInvoiceHeadexportAllowed: TcxGridDBBandedColumn;
    mnuEditFinExportProp: TMenuItem;
    btnExport: TsButton;
    procedure rbtDatesClick(Sender : TObject);
    procedure FormCreate(Sender : TObject);
    procedure cbxPeriodChange(Sender : TObject);
    procedure cbxTxtTypeChange(Sender : TObject);
    procedure edtFreeTextChange(Sender : TObject);
    procedure dtFromChange(Sender : TObject);
    procedure dtToChange(Sender : TObject);
    procedure LMDSpeedButton3Click(Sender : TObject);
    procedure FormShow(Sender : TObject);
    procedure btnReservationClick(Sender : TObject);
    procedure LMDSpeedButton1Click(Sender : TObject);
    procedure LMDButton1Click(Sender : TObject);
    procedure btnViewInvoiceClick(Sender : TObject);
    procedure LMDSpeedButton6Click(Sender : TObject);
    procedure tvInvDblClick(Sender: TObject);
    procedure edLastCountChange(Sender: TObject);
    procedure edtInvoiceFromChange(Sender: TObject);
    procedure edtInvoiceToChange(Sender: TObject);
    procedure btnBestFitClick(Sender: TObject);
    procedure btnPrintClick(Sender: TObject);
    procedure tvInvoiceHeadDblClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure btnExportClick(Sender: TObject);
    procedure tvInvoiceHeadVATGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadTaxesGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadWithOutVATGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadLocalAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
    procedure pmnuExportMenuPopup(Sender: TObject);
    procedure mnuExportClick(Sender: TObject);
    procedure mnuExportabilityClick(Sender: TObject);
    procedure tvInvoiceHeadSelectionChanged(Sender: TcxCustomGridTableView);
    procedure mnuEditFinExportPropClick(Sender: TObject);
    procedure tvInvoiceHeadCellClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState;
      var AHandled: Boolean);
  private
    { Private declarations }

    bIsFinanceSystemConnected : Boolean;
    initialRead : Boolean;
    zSortField : string;
    zSortDir : string;

    zRecordCount : integer;
    zLastInvoiceID : integer;

    firstTime : boolean;

    procedure ViewInvoice;
    procedure ApplyFilter;
    function GetSelectedInvoices : String;
    function GetExportTemplate: String;
    procedure InitSelections;
    function IsFinanceSystemConnected: Boolean;
    procedure EditCurrentProperties;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    { Public declarations }
    zFilterby : integer; // 1=period 2=invoicenumber 3=FreeText 4=InvoiceNumber
    zPeriodIndex : integer;
    zdtFrom : Tdate;
    zDTTo : Tdate;
    zInvoiceFrom : integer;
    zInvoiceTo : integer;
    zLast : integer;
    zText : string;
    zTextType : integer;

    zRoom : string;
    zArrival : Tdate;
  end;

type TExportPropertiesHolder = class
     private
       InvoiceNumber : Integer;
       ExternalId : Integer;
       ExportAllowed : Boolean;
     public
       constructor Create(_InvoiceNumber : Integer; _ExternalId : Integer; _ExportAllowed : Boolean);
     end;

function ShowClosedInvoicesDetailed(var aReturnToRoom: string; var aReturnToDate: TDate): boolean;

implementation

uses
  uD
  , uReservationProfile
  , uGuestProfile2
  , uFinishedInvoices2
  , uSqlDefinitions
  , uAppGlobal
  , PrjConst
  , uDImages
  , uFrmPostInvoices
  , uSQLUtils
  , uFrmHandleBookKeepingException
  , uEditFinanceExportProperties
  , uFinanceConnectService
  ;

{$R *.dfm}


function ShowClosedInvoicesDetailed(var aReturnToRoom: string; var aReturnToDate: TDate): boolean;
var
  lFrm: TfrmInvoiceList2;
begin
  lFrm := TfrmInvoiceList2.Create(nil);
  try
    Result := lFrm.ShowModal = mrOK;
    if Result then
    begin
      aReturnToRoom := lFrm.zRoom;
      aReturnToDate := lFrm.zArrival;
    end;
  finally
    lFrm.Free;
  end;
end;

procedure TfrmInvoiceList2.rbtDatesClick(Sender : TObject);
begin
  // **
  // -- Date edits
  dtFrom.enabled := rbtDates.checked;
  dtTo.enabled := rbtDates.checked;
  cbxPeriod.enabled := rbtDates.checked;
  // lblToDate.enabled      := RadioButton1.checked;

  // -- Invoice edits
  edtInvoiceFrom.enabled := rbtInvoices.checked;
  edtInvoiceTo.enabled := rbtInvoices.checked;
  edtLast.enabled := rbtInvoices.checked;
  // lblToInvoice.enabled   := RadioButton2.checked;

  edtFreeText.enabled := rbtFreeText.checked;
  cbxTxtType.enabled := rbtFreeText.checked;

  edtLast.enabled := rbtLast.checked;

  if rbtLast.checked then
  begin
    zLast := edtLast.value;
    zInvoiceTo := zLastInvoiceID;
    zInvoiceFrom := zLastInvoiceID - zLast + 1;
    if zLast < 100 then
      RefreshData;
  end;
end;

procedure TfrmInvoiceList2.FormCreate(Sender : TObject);
begin
  zSortField := 'InvoiceNumber';
  zSortDir := '';

  zRoom := '';
  zArrival := Date;

  firstTime := true;
  zFilterby := 0; // 0=period 1=invoicenumber 2=FreeText 3=InvoiceNumber
  zdtFrom := Date;
  zDTTo := Date;
  zInvoiceFrom := 0;
  zInvoiceTo := 0;
  zLast := 0;
  zText := '';
  zTextType := 0;
  zPeriodIndex := 1;
//  edtLast.Value := 50;
  zLast := edtLast.Value;

  cbxPeriod.ItemIndex := zPeriodIndex;
  cbxPeriodChange(nil);
  cbxTxtType.ItemIndex := zTextType;

  tvInvoiceHeadRowSelected.Visible := GetExportTemplate <> '';
end;

//TODO: Move to a global property, dependend on existing link to financial system
function TfrmInvoiceList2.GetExportTemplate : String;
var rSet : TRoomerDataSet;
begin
  rSet := CreateNewDataSet;
  try
    rSet_bySQL(rSet, 'SELECT InvoiceExportFilename FROM hotelconfigurations LIMIT 1');
    rSet.First;
    if NOT rSet.Eof then
      result := rSet['InvoiceExportFilename']
    else
      result := '';
  finally
    rSet.Free;
  end;
end;

procedure TfrmInvoiceList2.cbxPeriodChange(Sender : TObject);
var
  ThisDay : word;
  ThisWeekDay : word;
  ThisMonth : word;
  ThisYear : word;

  LastMonth : word;
begin
  deCodeDate(now, ThisYear, ThisMonth, ThisDay);
  ThisWeekDay := DayOfTheWeek(now);
  zPeriodIndex := cbxPeriod.ItemIndex;

  case zPeriodIndex of
    0 :
      begin
        // - ekkert vali� -
      end;
    1 :
      begin
        // � dag
        dtTo.Date := Date;
        dtFrom.Date := Date;
      end;
    2 :
      begin
        // � g�r
        dtTo.Date := Date - 1;
        dtFrom.Date := Date - 1;
      end;
    3 :
      begin
        // S��ustu 3 daga
        dtTo.Date := Date;
        dtFrom.Date := Date - 4;
      end;
    4 :
      begin
        // S��ustu 10 daga
        dtTo.Date := Date;
        dtFrom.Date := Date - 9;
      end;
    5 :
      begin
        // � �essari viku
        dtTo.Date := Date;
        dtFrom.Date := Date - ThisWeekDay + 1;
      end;
    6 :
      begin
        // � s��ustu viku
        dtTo.Date := (Date - ThisWeekDay);
        dtFrom.Date := (Date - ThisWeekDay) - 6;
      end;
    7 :
      begin
        dtTo.Date := (Date);
        dtFrom.Date := (Date - ThisDay) + 1;
      end;
    8 :
      begin
        // � s��asta m�nu�i
        if ThisMonth = 1 then
          LastMonth := 12
        else
          LastMonth := ThisMonth - 1;

        dtFrom.Date := (Date - ThisDay) - DaysInAMonth(ThisYear, LastMonth) + 1;
        dtTo.Date := (Date - ThisDay);
      end;
    9 :
      begin
        dtTo.Date := (Date);
        dtFrom.Date := (Date - DayOfTheYear(now)) + 1;
      end;
    10 :
      begin
        // � s��asta �ri
        dtFrom.Date := encodeDate(ThisYear - 1, 1, 1);
        dtTo.Date := encodeDate(ThisYear - 1, 12, 31)
      end;
    11 :
      begin
        dtFrom.Date := encodeDate(2000, 1, 1);
        dtTo.Date := Date;
      end;
  end;
  RefreshData;
end;

procedure TfrmInvoiceList2.cbxTxtTypeChange(Sender : TObject);
begin
  zTextType := cbxTxtType.ItemIndex;
  rbtFreeText.Checked := True;
end;

procedure TfrmInvoiceList2.edFilterChange(Sender: TObject);
begin
  if edFilter.Text = '' then
  begin
    tvInvoiceHead.DataController.Filter.Root.Clear;
    tvInvoiceHead.DataController.Filter.Active := false;
  end else
  begin
    applyFilter;
  end;
end;

procedure TfrmInvoiceList2.ApplyFilter;
begin
  tvInvoiceHead.DataController.Filter.Active := false;

  tvInvoiceHead.DataController.Filter.Options := [fcoCaseInsensitive];
  tvInvoiceHead.DataController.Filter.Root.BoolOperatorKind := fboOr;
  tvInvoiceHead.DataController.Filter.Root.Clear;
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadCurrency,foLike,'%'+Uppercase(edFilter.Text)+'%','%'+Uppercase(edFilter.Text)+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadInvoiceNumber,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadCreditType,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadNameOnInvoice,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadInvoicetype,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadLink,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadRoomGuest,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadCustomer,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadCompanyId,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadCustomerName,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadAddress1,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadAddress3,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadAddress3,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadRefrence,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadStaff,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadReservation,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadRoomReservation,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvInvoiceHead.DataController.Filter.Root.AddItem(tvInvoiceHeadexternalInvoiceId,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');

  tvInvoiceHead.DataController.Filter.Active := True;
end;


procedure TfrmInvoiceList2.edLastCountChange(Sender: TObject);
begin
  zLast := edtLast.Value;
  zInvoiceTo := zLastInvoiceID;
  zInvoiceFrom := zLastInvoiceID - zLast + 1;
  rbtLast.Checked := True;
end;

procedure TfrmInvoiceList2.edtFreeTextChange(Sender : TObject);
begin
  zText := edtFreeText.Text;
  rbtFreeText.Checked := True;
end;

procedure TfrmInvoiceList2.dtFromChange(Sender : TObject);
begin
  zdtFrom := dtFrom.Date;
  rbtDates.Checked := True;
end;

procedure TfrmInvoiceList2.dtToChange(Sender : TObject);
begin
  zDTTo := dtTo.Date;
  rbtDates.Checked := True;
end;

procedure TfrmInvoiceList2.mnuEditFinExportPropClick(Sender: TObject);
var i: integer;
    lInvNumber: integer;
    lSelected: TcxCustomGridRow;
    bValue : Boolean;
    iExternalId : Integer;

    List : TObjectList<TExportPropertiesHolder>;

begin
  with tvInvoiceHead do
  begin
    DataController.BeginLocate;
    DataController.DataSet.DisableControls;
    List := TObjectList<TExportPropertiesHolder>.Create;
    try
      for i := 0 to PRED(Controller.SelectedRowCount ) do
      begin
        lSelected := Controller.SelectedRows[i];
        lInvNumber := lSelected.Values[tvInvoiceHeadInvoiceNumber.Index];
        bValue := Boolean(lSelected.Values[tvInvoiceHeadexportAllowed.Index]);
        iExternalId := lSelected.Values[tvInvoiceHeadexternalInvoiceId.Index];
        if EditFinanceExportProperties(lInvNumber, iExternalId, bValue) then
          List.Add(TExportPropertiesHolder.Create(lInvNumber, iExternalId, bValue));
      end;

      for i := 0 to PRED(List.Count) do
      begin
        lInvNumber := List[i].InvoiceNumber;
        with DataController.DataSet do
          if Locate('invoiceNumber', lInvNumber, []) then
          begin
            Edit;
            try
              FieldByName('exportAllowed').AsBoolean := List[i].ExportAllowed;
              FieldByName('externalInvoiceId').AsInteger := List[i].ExternalId;
              Post;
            except
              Cancel;
              raise;
            end;
          end;
      end;
    finally
      List.Free;
      DataController.EndLocate;
      DataController.DataSet.EnableControls;
    end;
  end;
end;

procedure TfrmInvoiceList2.DoUpdateControls;
begin
  inherited;

  if bIsFinanceSystemConnected then
    tvInvoiceHead.PopupMenu := pmnuExportMenu
  else
    tvInvoiceHead.PopupMenu := nil;

  btnExport.Visible := bIsFinanceSystemConnected;
  btnExport.Enabled := tvInvoiceHead.Controller.SelectedRowCount > 0;

  tvInvoiceHeadexternalInvoiceId.Visible := bIsFinanceSystemConnected;
end;

procedure TfrmInvoiceList2.DoLoadData;
var
  s : string;
  rSet : TroomerDataSet;

begin
  inherited;

  m22_.DisableControls;
  try

    if m22_.active then m22_.Close;
      m22_.open;

    initialRead := True;
    zdtFrom := dtFrom.Date;
    zdtTo := dtTo.Date;

    if rbtFreeText.Checked and (cbxTxtType.ItemIndex in [4, 5, 6]) and  not _isInteger(edtFreeText.Text) then
    begin
      ShowMessage(Format(GetTranslatedtext('shTx_Invoice_NotANumber'), ['"' + edtFreeText.Text + '"']));
      exit;
    end;

    screen.Cursor := crHourGlass;
    rSet := CreateNewDataset;
    try
      s := '';
      s := s + 'SELECT '#10;
      s := s + '      ih.externalInvoiceId '#10;
      s := s + '    , ih.exportAllowed '#10;
      s := s + '    , ih.Reservation '#10;
      s := s + '    , ih.RoomReservation '#10;
      s := s + '    , ih.InvoiceNumber '#10;
      s := s + '    , ih.Customer '#10;
      s := s + '    , ih.Name AS NameOnInvoice'#10;
      s := s + '    , ih.Address1 '#10;
      s := s + '    , ih.Address2 '#10;
      s := s + '    , ih.Address3 '#10;
      s := s + '    , ih.invRefrence AS Refrence '#10;
      s := s + '    , ih.Total/ihCurrencyRate AS Amount '#10;
      s := s + '    , ih.TotalWOVat/ihCurrencyRate AS WithOutVAT'#10;
      s := s + '    , ih.TotalVat/ihCurrencyRate AS VAT '#10;
      s := s + '    , ih.Total AS LocalAmount '#10;
      s := s + '    , ih.TotalWOVat AS LocalWithOutVAT'#10;
      s := s + '    , ih.TotalVat AS LocalVAT '#10;
      s := s + '    , ih.RoomGuest '#10;
  //    s := s + '    , ih.ihInvoiceDate AS InvoiceDate'#10;
      s := s + '    , date(ih.InvoiceDate) AS InvoiceDate'#10;
      s := s + '    , ih.ihConfirmDate AS Confirmdate'#10;
      s := s + '    , ih.ihPayDate AS DueDate'#10;
      s := s + '    , ih.ihStaff AS Staff'#10;
      s := s + '    , ih.custPID AS CompanyId'#10;
      s := s + '    , ih.ihcurrency AS Currency'#10;
      s := s + '    , ih.ihcurrencyRate AS CurrencyRate'#10;
      s := s + '    , ih.totalStayTax AS Taxes'#10;
      s := s + '    , ih.TotalStayTaxNights Taxunits'#10;
      s := s + '    , (if(ih.Splitnumber=1,'+_db('CREDIT')+','+_db('DEBIT')+')) AS CreditType '#10;
      s := s + '    , (ih.Total div ih.ihCurrencyRate) AS CurrencyAmount '#10;
      s := s + '    , (if(ih.Reservation = 0 and ih.Roomreservation=0,' + _db(GetTranslatedText('shUI_Reports_InvoiceTypeCash')) +
                       ',if(ih.Reservation > 0 and ih.Roomreservation=0,'+ _db(GetTranslatedText('shUI_Reports_InvoiceTypeGroup')) + ',' + _db(GetTranslatedText('shUI_Reports_InvoiceTypeRoom')) + '))) AS Invoicetype '#10;
      s := s + '    , (IF(ih.CreditInvoice<>0,ih.CreditInvoice,if(ih.OriginalInvoice<>0,ih.OriginalInvoice,0))) AS Link'#10;
      s := s + '    , (SELECT surName FROM customers WHERE Customer = ih.Customer Limit 1) As CustomerName'#10;
      s := s + '    , (SELECT GROUP_CONCAT(PayType) FROM payments WHERE InvoiceNumber=ih.InvoiceNumber) AS paytypes'#10;
      s := s + '    , (SELECT GROUP_CONCAT(Amount) FROM payments WHERE InvoiceNumber=ih.InvoiceNumber) AS payments'#10;
      s := s + '     FROM '#10;
      s := s + '        invoiceheads ih '#10;
      s := s + '    WHERE '#10;
      s := s + '      (ih.invoicenumber > 0) '#10;

      if rbtDates.checked then
      begin
        s := s + '    AND ((ih.InvoiceDate >= ' + _db(zdtFrom, true) + ')  AND (ih.InvoiceDate <= ' + _db(zDTTo, true) + ')) ';
      end;

      if (rbtInvoices.checked) or (rbtLast.checked) then
      begin
        s := s + '    AND ((ih.InvoiceNumber >= ' + _db(zInvoiceFrom) + ')  AND (ih.InvoiceNumber <= ' + _db(zInvoiceTo) + ')) ';
      end;

      if (rbtFreeText.checked) then
      begin
        case cbxTxtType.ItemIndex of
          0 : s := s + '  AND (ih.InvoiceNumber=' + _db(edtFreeText.Text) + ') ';
          1 : s := s + '  AND (custPID=' + _db(edtFreeText.Text) + ') ';
          2 : s := s + '  AND (Customer=' + _db(edtFreeText.Text) + ') ';
          3 : s := s + '  AND ((Name LIKE ' + _db('%' + edtFreeText.Text + '%') + ') OR (RoomGuest LIKE ' + _db('%' + edtFreeText.Text + '%') + ')) ';
          4 : s := s + '  AND (Reservation=' + edtFreeText.Text + ') ';
          5 : s := s + '  AND (RoomReservation=' + edtFreeText.Text + ') ';
          6 : s := s + '  AND (externalInvoiceId=' + edtFreeText.Text + ') ';
        end;
      end;
      s := s + ' ORDER BY ';
      s := s + '   ih.InvoiceNumber DESC';

      copytoclipboard(s);
  //    debugMessage(s);

      if hData.rSet_bySQL(rSet,s) then
      begin
        LoadKbmMemtableFromDataSetQuiet(m22_,rset,[]);
        InitSelections;
        m22_.First;
      end;
    finally
      freeandnil(rSet);
      m22_.EnableControls;
      screen.Cursor := crDefault;
      zRecordCount := m22_.RecordCount;
    end;
  finally
    initialRead := False;
  end;
end;

procedure TfrmInvoiceList2.btnPrintClick(Sender: TObject);
var
  InvoiceNumber : integer;
begin
  InvoiceNumber := m22_.fieldbyname('InvoiceNumber').AsInteger;
  ViewInvoice2(InvoiceNumber, true, false, false,false, '');
end;

procedure TfrmInvoiceList2.btnBestFitClick(Sender: TObject);
begin
  tvInvoiceHead.ApplyBestFit();
end;

procedure TfrmInvoiceList2.InitSelections;
begin
  m22_.First;
  while NOT m22_.Eof do
  begin
    m22_.Edit;
    m22_['RowSelected'] := False;
    m22_.Post;
    m22_.Next;
  end;
  m22_.First;
end;

function TfrmInvoiceList2.GetSelectedInvoices : String;
begin
  result := '';
  m22_.DisableControls;
  try
    m22_.First;
    while NOT m22_.Eof do
    begin
      if (m22_['RowSelected']) then
      begin
        if result = '' then
          result := inttostr(m22_['InvoiceNumber'])
        else
          result := result + ',' + inttostr(m22_['InvoiceNumber']);
      end;
      m22_.Next;
    end;
  finally
     m22_.EnableControls;
  end;
  m22_.First;
end;

procedure TfrmInvoiceList2.btnExportClick(Sender: TObject);
begin
  PostInvoicesToBookKeepingSystem(GetSelectedInvoices);
end;

procedure TfrmInvoiceList2.LMDSpeedButton3Click(Sender : TObject);
begin
  RefreshData;
end;

procedure TfrmInvoiceList2.FormShow(Sender : TObject);
begin

  bIsFinanceSystemConnected := FinanceConnectActive OR IsFinanceSystemConnected;
  cbxPeriod.ItemIndex := 0;
  cbxTxtType.ItemIndex := 0;
  zLastInvoiceID := hdata.IVH_GetLastID();
  firstTime := false;

  rbtLast.Checked := true;
  ActiveControl := edtLast;

  if rbtLast.checked then
  begin
    zLast := edtLast.Value;
    zInvoiceTo := zLastInvoiceID;
    zInvoiceFrom := zLastInvoiceID - zLast + 1;
  end;

end;

procedure TfrmInvoiceList2.edtInvoiceFromChange(Sender: TObject);
begin
  if edtInvoiceTo.value < edtInvoiceFrom.value then
    edtInvoiceTo.Value := edtInvoiceFrom.value;
  zInvoiceFrom := edtInvoiceFrom.value;
  rbtInvoices.Checked := True;
end;

procedure TfrmInvoiceList2.edtInvoiceToChange(Sender: TObject);
begin
  if edtInvoiceTo.value < edtInvoiceFrom.Value then
    edtInvoiceTo.Value := edtInvoiceFrom.value;
  zInvoiceTo := edtInvoiceTo.value;
  rbtInvoices.Checked := True;
end;

procedure TfrmInvoiceList2.tvInvDblClick(Sender: TObject);
begin
  ViewInvoice;
end;

procedure TfrmInvoiceList2.tvInvoiceHeadAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(ARecord.Values[tvInvoiceHeadCurrency.index]);;
end;

procedure TfrmInvoiceList2.tvInvoiceHeadCellClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
  AShift: TShiftState; var AHandled: Boolean);
begin
  if IsAltKeyPressed then
    EditCurrentProperties;
end;

procedure TfrmInvoiceList2.EditCurrentProperties;
var
  InvoiceNumber : integer;
  exportable : Boolean;
  externalId : Integer;
begin
  InvoiceNumber := m22_.fieldbyname('InvoiceNumber').AsInteger;
  exportable := m22_.fieldbyname('exportAllowed').AsBoolean;
  externalId := m22_.fieldbyname('externalInvoiceId').AsInteger;
  if EditFinanceExportProperties(InvoiceNumber, externalId, exportable) then
    with tvInvoiceHead do
    begin
      DataController.BeginLocate;
      DataController.DataSet.DisableControls;
      try
        with DataController.DataSet do
          if Locate('invoiceNumber', InvoiceNumber, []) then
          begin
            Edit;
            try
              FieldByName('exportAllowed').AsBoolean := exportable;
              FieldByName('externalInvoiceId').AsInteger := externalId;
              Post;
            except
              Cancel;
              raise;
            end;
          end;
      finally
        DataController.EndLocate;
        DataController.DataSet.EnableControls;
      end;
    end;
end;

procedure TfrmInvoiceList2.tvInvoiceHeadDblClick(Sender: TObject);
begin
  if IsAltKeyPressed then
    EditCurrentProperties
  else
    btnViewInvoiceClick(Sender);
end;

procedure TfrmInvoiceList2.tvInvoiceHeadLocalAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmInvoiceList2.tvInvoiceHeadSelectionChanged(Sender: TcxCustomGridTableView);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmInvoiceList2.tvInvoiceHeadTaxesGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmInvoiceList2.tvInvoiceHeadVATGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(ARecord.Values[tvInvoiceHeadCurrency.index]);;
end;

procedure TfrmInvoiceList2.tvInvoiceHeadWithOutVATGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(ARecord.Values[tvInvoiceHeadCurrency.index]);;
end;

procedure TfrmInvoiceList2.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmInvoiceList2.btnReservationClick(Sender : TObject);
var
  iReservation : integer;
  iRoomReservation : integer;
begin
  iReservation := m22_.fieldbyname('Reservation').AsInteger;
  iRoomReservation := m22_.fieldbyname('RoomReservation').AsInteger;

  if iReservation = 0 then
  begin
	  showmessage(GetTranslatedText('shTx_InvoiceList2_CashAccount'));
    exit;
  end;
  EditReservation(iReservation, iRoomReservation);
end;

procedure TfrmInvoiceList2.LMDSpeedButton1Click(Sender : TObject);
var
  iReservation : integer;
  iRoomReservation : integer;
  sName : string;
  theData : recPersonHolder;
begin
  sName := m22_.fieldbyname('RoomGuest').asstring;
  iReservation := m22_.fieldbyname('Reservation').AsInteger;
  iRoomReservation := m22_.fieldbyname('RoomReservation').AsInteger;

  if (iReservation > 0) and (iRoomReservation = 0) then
  begin
    showmessage(GetTranslatedText('shTx_InvoiceList2_GroupInvoice'));
    exit;
  end;


  initPersonHolder(theData);
  theData.RoomReservation := iRoomreservation;
  theData.Reservation := iReservation;
  theData.name := sName;

  openGuestProfile(actNone,theData);
end;

procedure TfrmInvoiceList2.LMDButton1Click(Sender : TObject);
var
  iRoomReservation : integer;
begin

  iRoomReservation := m22_.fieldbyname('roomReservation').AsInteger;

  if iRoomReservation = 0 then
  begin
    showmessage(GetTranslatedText('shTx_InvoiceList2_NotRoomInvoice'));
    exit;
  end;

  zRoom := d.RR_GetRoomNr(iRoomReservation);
  zArrival := d.RR_GetArrivalDate(iRoomReservation);
end;

procedure TfrmInvoiceList2.btnViewInvoiceClick(Sender : TObject);
var
  InvoiceNumber : integer;
begin
  InvoiceNumber := m22_.fieldbyname('InvoiceNumber').AsInteger;
  ViewInvoice2(InvoiceNumber, false, false, false,false, '');
end;

procedure TfrmInvoiceList2.ViewInvoice;
var
  InvoiceNumber : integer;
begin
  InvoiceNumber := m22_.fieldbyname('InvoiceNumber').AsInteger;
  ViewInvoice2(InvoiceNumber, false, false, false,false, '');
end;


procedure TfrmInvoiceList2.LMDSpeedButton6Click(Sender : TObject);
var
  sFilename : string;
  s : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Invoicelist';
  ExportGridToExcel(sFilename, grInvoicehead, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmInvoiceList2.mnuExportabilityClick(Sender: TObject);
var i: integer;
    lInvNumber: integer;
    lUpdatePlan: TROomerExecutionPlan;
    lSelected: TcxCustomGridRow;
    bValue : Boolean;
const
  cSQLUpdateLine = 'UPDATE invoiceheads SET exportAllowed=%d WHERE InvoiceNumber=%d';
begin
  with tvInvoiceHead do
  begin
    DataController.BeginLocate;
    DataController.DataSet.DisableControls;
    lUpdatePLan := TRoomerExecutionPlan.Create(d.roomerMainDataSet);
    try
      for i := 0 to PRED(Controller.SelectedRowCount ) do
      begin
        lSelected := Controller.SelectedRows[i];
//        if integer(lSelected.Values[tvInvoiceHeadexternalInvoiceId.Index]) in [0, 1] then
//        begin
          lInvNumber := lSelected.Values[tvInvoiceHeadInvoiceNumber.Index];
          bValue := NOT Boolean(lSelected.Values[tvInvoiceHeadexportAllowed.Index]);
          lUpdatePLan.AddExec(Format(cSQLUpdateLine, [IIF(bValue, 1, 0), lInvNumber]));
//        end;
      end;

      if lUpdatePlan.ExecCount > 0 then
        if lUpdatePlan.Execute(ptExec, True, True) then
          for i := 0 to PRED(Controller.SelectedRowCount ) do
          begin
            lSelected := Controller.SelectedRows[i];
            lInvNumber := lSelected.Values[tvInvoiceHeadInvoiceNumber.Index];
            with DataController.DataSet do
              if Locate('invoiceNumber', lInvNumber, []) then
              begin
                Edit;
                try
                  FieldByName('exportAllowed').AsBoolean := NOT FieldByName('exportAllowed').AsBoolean;
                  Post;
                except
                  Cancel;
                end;
              end;
          end;
    finally
      DataController.EndLocate;
      DataController.DataSet.EnableControls;
      lUpdatePLan.Free;
    end;
  end;
end;

procedure TfrmInvoiceList2.mnuExportClick(Sender: TObject);
var i,
    lInvNumber : Integer;
    lSelected : TcxCustomGridRow;
    remoteResult : String;
    lUpdateNeeded: boolean;
begin
  with tvInvoiceHead do
  begin
    lUpdateNeeded := false;
    DataController.BeginLocate;
    DataController.DataSet.DisableControls;
    try
      for i := 0 to PRED(Controller.SelectedRowCount ) do
      begin
        lSelected := Controller.SelectedRows[i];
        if integer(lSelected.Values[tvInvoiceHeadexternalInvoiceId.Index]) in [0, 1] then
        begin
          lInvNumber := lSelected.Values[tvInvoiceHeadInvoiceNumber.Index];
          SendInvoiceToActiveFinanceConnector(lInvNumber);
          remoteResult := d.roomerMainDataSet.SystemSendInvoiceToBookkeeping(lInvNumber);
          if remoteResult <> '' then
            HandleFinanceBookKeepingExceptions(lInvNumber, remoteResult)
          else
            lUpdateNeeded := true;
        end;
      end;

      if lUpdateNeeded then
        RefreshData;
    finally
      DataController.EndLocate;
      DataController.DataSet.EnableControls;
    end;
  end;
end;


//TODO: This sould be implemented as a global property
function TfrmInvoiceList2.IsFinanceSystemConnected : Boolean;
var rSet : TRoomerDataSet;
begin
  rSet := CreateNewDataSet;
  rSet_bySQL(rSet, 'SELECT to_bool(IFNULL((SELECT 1 FROM home100.hotelservices WHERE active=1 AND hotelId=SUBSTR(DATABASE(), 9, 15) AND serviceType=''FINANCE'' LIMIT 1), 0)) AS financeConnected, InvoiceExportFilename FROM hotelconfigurations LIMIT 1');
  rSet.First;
  Result := NOT rSet.Eof and rSet['financeConnected'];
end;


procedure TfrmInvoiceList2.pmnuExportMenuPopup(Sender: TObject);
begin
  mnuExportability.Enabled := tvInvoiceHead.Controller.SelectedRowCount > 0;
  mnuExport.Enabled := (tvInvoiceHead.Controller.SelectedRowCount > 0);
end;


{ TExportPropertiesHolder }

constructor TExportPropertiesHolder.Create(_InvoiceNumber, _ExternalId: Integer; _ExportAllowed: Boolean);
begin
  InvoiceNumber := _InvoiceNumber;
  ExternalId := _ExternalId;
  ExportAllowed := _ExportAllowed;
end;

end.

