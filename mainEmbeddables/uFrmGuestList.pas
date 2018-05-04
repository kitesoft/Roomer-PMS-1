unit uFrmGuestList;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ExtCtrls,
  sPanel,
  Vcl.StdCtrls,
  sCheckBox,
  sButton,
  sGroupBox,
  Data.DB,
  kbmMemTable,
  Vcl.Menus,
  ppDB,
  ppDBPipe,
  ppParameter,
  ppDesignLayer,
  ppCtrls,
  ppBands,
  ppStrtch,
  ppMemo,
  ppClass,
  ppPrnabl,
  ppCache,
  ppComm,
  ppRelatv,
  ppProd,
  ppReport,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxStyles,
  dxSkinsCore,
  dxSkinCaramel,
  dxSkinCoffee,
  dxSkinDarkSide,
  dxSkinTheAsphaltWorld,
  dxSkinsDefaultPainters,
  dxSkinscxPCPainter,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxEdit,
  cxNavigator,
  cxDBData,
  cxTextEdit,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxClasses,
  cxGridCustomView,
  cxGrid
  , uRoomerDefinitions
  ;

type
  TfrmGuestList = class(TForm)
    pnlHolder: TsPanel;
    rptbGroups: TppReport;
    ppHeaderBand1: TppHeaderBand;
    rLabReportName: TppLabel;
    ppLabel9: TppLabel;
    rlabFrom: TppLabel;
    rLabHotelName: TppLabel;
    rlabUser: TppLabel;
    rLabTimeCreated: TppLabel;
    ppLine4: TppLine;
    ppDetailBand1: TppDetailBand;
    ppDBText1: TppDBText;
    ppDBText2: TppDBText;
    ppDBText5: TppDBText;
    ppDBText6: TppDBText;
    ppDBText7: TppDBText;
    ppDBText8: TppDBText;
    ppDBText9: TppDBText;
    ppDBText10: TppDBText;
    ppDBText11: TppDBText;
    ppFooterBand1: TppFooterBand;
    ppGroup1: TppGroup;
    ppGroupHeaderBand1: TppGroupHeaderBand;
    ppLabel1: TppLabel;
    ppLabel2: TppLabel;
    ppDBText3: TppDBText;
    ppLine2: TppLine;
    ppLabel5: TppLabel;
    ppLabel6: TppLabel;
    ppLabel7: TppLabel;
    ppLabel8: TppLabel;
    mem: TppMemo;
    ppDBText4: TppDBText;
    ppLabel4: TppLabel;
    ppLabel10: TppLabel;
    ppLabel11: TppLabel;
    ppGroupFooterBand1: TppGroupFooterBand;
    ppLine1: TppLine;
    ppDBCalc1: TppDBCalc;
    ppLabel3: TppLabel;
    ppDBCalc2: TppDBCalc;
    ppDesignLayers1: TppDesignLayers;
    ppDesignLayer1: TppDesignLayer;
    ppParameterList1: TppParameterList;
    dplGroups: TppDBPipeline;
    pupGroups: TPopupMenu;
    N1: TMenuItem;
    N2: TMenuItem;
    N3: TMenuItem;
    mnuReservationProfile: TMenuItem;
    mnuGuestProfile: TMenuItem;
    mnuPrintRegistrationForm: TMenuItem;
    mnuCheckin: TMenuItem;
    mnuCheckout: TMenuItem;
    mnuRoominvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    mAllReservations: TkbmMemTable;
    allReservationsDS: TDataSource;
    Panel3: TsPanel;
    rgrGroupreportStayType: TsRadioGroup;
    btnGroupReportExpandAll: TsButton;
    btnGroupreportCollapseAll: TsButton;
    btnGuestListExcel: TsButton;
    grbGroupReportProperties: TsGroupBox;
    chkNewPage: TsCheckBox;
    chkPrintMemo: TsCheckBox;
    btnGroupReportShow: TsButton;
    gAllReservations: TcxGrid;
    tvAllReservations: TcxGridDBTableView;
    tvAllReservationsArrivalDate: TcxGridDBColumn;
    tvAllReservationsDepartureDate: TcxGridDBColumn;
    tvAllReservationsRRGuestCount: TcxGridDBColumn;
    tvAllReservationsmainGuests: TcxGridDBColumn;
    tvAllReservationsRoom: TcxGridDBColumn;
    tvAllReservationsRoomType: TcxGridDBColumn;
    tvAllReservationsRoomDescription: TcxGridDBColumn;
    tvAllReservationsFloor: TcxGridDBColumn;
    tvAllReservationsLocationDescription: TcxGridDBColumn;
    tvAllReservationsStatustext: TcxGridDBColumn;
    tvAllReservationsmarketSegmentDescription: TcxGridDBColumn;
    tvAllReservationsGroupAccount: TcxGridDBColumn;
    tvAllReservationsCustomer: TcxGridDBColumn;
    tvAllReservationsPersonalID: TcxGridDBColumn;
    tvAllReservationsEmail: TcxGridDBColumn;
    tvAllReservationsWebsite: TcxGridDBColumn;
    tvAllReservationsRvGuestCount: TcxGridDBColumn;
    tvAllReservationsNoRoom: TcxGridDBColumn;
    tvAllReservationsBookable: TcxGridDBColumn;
    tvAllReservationsStatistics: TcxGridDBColumn;
    tvAllReservationsRoomReservation: TcxGridDBColumn;
    tvAllReservationsroomCount: TcxGridDBColumn;
    tvAllReservationsReservation: TcxGridDBColumn;
    tvAllReservationsStatus: TcxGridDBColumn;
    tvAllReservationsLocation: TcxGridDBColumn;
    tvAllReservationsmarketSegment: TcxGridDBColumn;
    tvAllReservationsresInfo: TcxGridDBColumn;
    tvAllReservationshidden: TcxGridDBColumn;
    tvAllReservationsEquipments: TcxGridDBColumn;
    tvAllReservationsGroupReservation: TcxGridDBColumn;
    tvAllReservationsResLine: TcxGridDBColumn;
    tvAllReservationsReservationName: TcxGridDBColumn;
    tvAllReservationsCustomerName: TcxGridDBColumn;
    tvAllReservationsGroupReservationName: TcxGridDBColumn;
    tvAllReservationsRoomNotes: TcxGridDBColumn;
    tvAllReservationsbreakfastGuests: TcxGridDBColumn;
    tvAllReservationsNights: TcxGridDBColumn;
    tvAllReservationsCurrency: TcxGridDBColumn;
    tvAllReservationsAverageRate: TcxGridDBColumn;
    tvAllReservationsTotalStayRate: TcxGridDBColumn;
    tvAllReservationsAdults: TcxGridDBColumn;
    tvAllReservationsChildren: TcxGridDBColumn;
    tvAllReservationsInfants: TcxGridDBColumn;
    tvAllReservationsBreakfast: TcxGridDBColumn;
    lvAllReservations: TcxGridLevel;
    m: TkbmMemTable;
    mDS: TDataSource;
    procedure tvAllReservationsAverageRateGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvAllReservationsTotalStayRateGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure pupGroupsPopup(Sender: TObject);
    procedure btnGroupreportCollapseAllClick(Sender: TObject);
    procedure btnGroupReportExpandAllClick(Sender: TObject);
    procedure btnGuestListExcelClick(Sender: TObject);
    procedure rgrGroupReportDateTypeClick(Sender: TObject);
    procedure rgrGroupreportStayTypeClick(Sender: TObject);
    procedure rgrTypePropertiesEditValueChanged(Sender: TObject);
    procedure rgrUsePropertiesEditValueChanged(Sender: TObject);
    procedure mnuCheckinClick(Sender: TObject);
    procedure mnuCheckoutClick(Sender: TObject);
    procedure mnuGroupInvoiceClick(Sender: TObject);
    procedure mnuRoomInvoiceClick(Sender: TObject);
    procedure mnuPrintRegistrationFormClick(Sender: TObject);
    procedure mnuReservationProfileClick(Sender: TObject);
    procedure mnuGuestprofileClick(Sender: TObject);
    procedure btnGroupReportShowClick(Sender: TObject);
    procedure ppGroupHeaderBand1BeforePrint(Sender: TObject);
    procedure ppHeaderBand1BeforePrint(Sender: TObject);
  private
    FDate: TDate;
    zGuestListFirstTime: boolean;
    function getRoomReservationsListSubQuery(aType: integer): string;
    function getSortField: string;
    function GetDate: TDate;
    procedure SetDate(const Value: TDate);
    function CheckInARoom(iReservation, iRoomReservation: integer): boolean;
    procedure CheckOutARoom(const Room: String; iRoomReservation, iReservation: integer);
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    procedure RefreshGuestList;
    procedure GuestListReport;

    property Date: TDate read GetDate write SetDate;
  end;

implementation

{$R *.dfm}

uses
  uD,
  uG,
  uSqlDefinitions,
  dxCore,
  uSQLUtils,
  uUtils,
  hData,
  cmpRoomerDataset,
  uRptbViewer,
  uBreakfastTypeDefinitions,
  cxGridExportLink,
  Winapi.ShellApi,
  uActivityLogs,
  uGuestProfiles
  , _Glob
  , uReservationProfile
  , uGuestProfile2
  , uGuestCheckInForm
  , ufrmInvoiceEdit
  , uInvoiceDefinitions, PrjConst, uReservationStateChangeHandler, uReservationStateDefinitions;

procedure TfrmGuestList.pupGroupsPopup(Sender: TObject);
begin
  mnuReservationProfile.Enabled := not mAllReservations.IsEmpty;
  mnuGuestProfile.Enabled := not mAllReservations.IsEmpty;
  mnuPrintRegistrationForm.Enabled := not mAllReservations.IsEmpty;
  mnuCheckin.Enabled := not mAllReservations.IsEmpty and (mAllReservations['Status'] = 'P');
  mnuCheckout.Enabled := not mAllReservations.IsEmpty and (mAllReservations['Status'] = 'G');
  mnuRoominvoice.Enabled := not mAllReservations.IsEmpty;
  mnuGroupInvoice.Enabled := not mAllReservations.IsEmpty;
end;

procedure TfrmGuestList.tvAllReservationsAverageRateGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(ARecord.Values[tvAllReservationsCurrency.index]);
end;

procedure TfrmGuestList.tvAllReservationsTotalStayRateGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(ARecord.Values[tvAllReservationsCurrency.index]);
end;

procedure TfrmGuestList.btnGroupreportCollapseAllClick(Sender: TObject);
begin
  tvAllReservations.DataController.Groups.FullCollapse;
end;

procedure TfrmGuestList.btnGroupReportExpandAllClick(Sender: TObject);
begin
  tvAllReservations.DataController.Groups.FullExpand;
end;

function TfrmGuestList.getSortField: string;
var
  i: integer;
  AColumn: TcxGridDBColumn;
  aName: string;
  s: string;
begin
  //
  s := '';
  for i := 0 to tvAllReservations.ColumnCount - 1 do
  begin
    AColumn := tvAllReservations.Columns[i];
    aName := AColumn.DataBinding.FieldName;
    s := aName;
    if AColumn.SortOrder = soNone then
    begin
    end
    else if AColumn.SortOrder = soAscending then
    begin
      s := s + ';a';
      result := s;
      exit;
    end
    else if AColumn.SortOrder = soDescending then
    begin
      s := s + ';d';
      result := s;
      exit;
    end;
  end;
end;

function TfrmGuestList.getRoomReservationsListSubQuery(aType: integer): string;
begin
  result := '';
  case aType of
    0:
      begin
        result := Format(GetListOfRoomReservationsPerArrivalDate, [_db(FDate, true)]);
      end;
    1:
      begin
        result := Format(GetListOfRoomReservationsPerDepartureDate, [_db(FDate, true)]);
      end;
    2:
      begin
        result := Format(GetListOfRoomReservationsFromToDate, [_db(FDate, true), _db(FDate, true)]);
      end;
  end;
  if not result.IsEmpty then
    result := result + ' ORDER BY Roomreservation';
end;

procedure TfrmGuestList.refreshGuestList;
var
  rSet: TRoomerDataSet;
  s: string;
  aType: integer;
  // Fields
  RoomReservation: integer;
  Reservation: integer;
  ReservationName: string;
  ArrivalDate: TDate;
  DepartureDate: TDate;
  Room: string;
  RoomType: string;
  status: string;
  Breakfast: TBreakfastType;
  noRoom: boolean;
  RoomDescription: string;
  Bookable: boolean;
  hidden: boolean;
  Location: string;
  Floor: integer;
  Equipments: string;
  LocationDescription: string;
  GroupAccount: boolean;
  marketSegment: string;
  marketSegmentDescription: string;
  Email: string;
  Website: string;
  customer: string;
  CustomerName: string;
  PersonalID: string;

  // calc Fields
  Statustext: string;
  ResInfo: string;
  RoomCount: integer;
  RvGuestCount: integer;
  RRGuestCount: integer;
  mainGuests: string;
  GroupReservation: integer;
  GroupReservationName: string;

  Currency: String;
  AverageRate, TotalRate: Double;
  numDays, Adults, Children, Infants: integer;

  ResLine: string;
  breakfastguests: integer;

  SubSql: String;
  zRoomReservationList: string;

begin

  aType := rgrGroupreportStayType.ItemIndex;
  zRoomReservationList := getRoomReservationsListSubQuery(aType);

  if zRoomReservationList = '' then
  begin
    if mAllReservations.active then
      mAllReservations.Close;
    mAllReservations.Open;
    exit;
  end;
  s := '';
  if mAllReservations.active then
    mAllReservations.Close;
  mAllReservations.Open;

  rSet := CreateNewDataSet;
  try
    Screen.Cursor := crHourglass;
    mAllReservations.DisableControls;
    try
      s := select_Main_refreshGuestList;
      SubSql := Format('(%s)', [zRoomReservationList]);
      s := Format(s, [SubSql]);

      uUtils.CopyToClipboard(s);
      // DebugMessage(s);

      hData.rSet_bySQL(rSet, s);

      rSet.first;
      while not rSet.eof do
      begin
        mAllReservations.append;
        RoomReservation := rSet.FieldByName('RoomReservation').asinteger;
        Reservation := rSet.FieldByName('Reservation').asinteger;
        ReservationName := rSet.FieldByName('ReservationName').asString;
        ArrivalDate := rSet.FieldByName('ArrivalDate').AsDateTime;
        DepartureDate := rSet.FieldByName('DepartureDate').AsDateTime;
        Room := rSet.FieldByName('Room').asString;
        RoomType := rSet.FieldByName('RoomType').asString;
        status := rSet.FieldByName('Status').asString;
        Breakfast := TBreakfastType.FromDBString(rSet['Breakfast']);
        noRoom := rSet['NoRoom'];
        RoomDescription := rSet.FieldByName('RoomDescription').asString;
        Bookable := rSet['Bookable'];
        hidden := rSet['hidden'];
        Location := rSet.FieldByName('Location').asString;
        Floor := rSet.FieldByName('Floor').asinteger;
        Equipments := rSet.FieldByName('Equipments').asString;
        LocationDescription := rSet.FieldByName('LocationDescription').asString;
        GroupAccount := rSet['GroupAccount'];
        marketSegment := rSet.FieldByName('marketSegment').asString;
        marketSegmentDescription := rSet.FieldByName('marketSegmentDescription').asString;
        Email := rSet.FieldByName('Email').asString;
        Website := rSet.FieldByName('Website').asString;
        customer := rSet.FieldByName('Customer').asString;
        CustomerName := rSet.FieldByName('CustomerName').asString;
        PersonalID := rSet.FieldByName('PersonalID').asString;
        Statustext := rSet.FieldByName('Statustext').asString;
        RoomCount := rSet.FieldByName('RoomCount').asinteger;
        RvGuestCount := rSet.FieldByName('RvGuestCount').asinteger;
        RRGuestCount := rSet.FieldByName('RRGuestCount').asinteger;
        mainGuests := rSet.FieldByName('MainGuests').asString;
        ResLine := mainGuests + ' / ' + ReservationName;

        Currency := rSet.FieldByName('Currency').asString;
        AverageRate := rSet.FieldByName('AverageRate').AsFloat;
        numDays := trunc(DepartureDate - ArrivalDate);
        TotalRate := numDays * AverageRate;
        Adults := rSet.FieldByName('NumGuests').asinteger;
        Children := rSet.FieldByName('NumChildren').asinteger;
        Infants := rSet.FieldByName('NumInfants').asinteger;

        breakfastguests := 0;
        if Breakfast in [TBreakfastType.Included, TBreakfastType.Excluded] then
          breakfastguests := RRGuestCount;

        if RoomCount < 2 then
        begin
          GroupReservation := 0;
          GroupReservationName := 'One Room Reservations';
          ResInfo := inttostr(GroupReservation) + ' | ' + GroupReservationName;
        end
        else
        begin
          GroupReservation := Reservation;
          GroupReservationName := ReservationName;
          ResInfo := inttostr(GroupReservation) + ' | ' + GroupReservationName + ' (' + inttostr(RvGuestCount) +
            ' guests in ' + inttostr(RoomCount) + ' rooms)';
        end;

        mAllReservations.FieldByName('RoomReservation').asinteger := RoomReservation;
        mAllReservations.FieldByName('Reservation').asinteger := Reservation;
        mAllReservations.FieldByName('ReservationName').asString := ReservationName;
        mAllReservations.FieldByName('ArrivalDate').AsDateTime := ArrivalDate;
        mAllReservations.FieldByName('DepartureDate').AsDateTime := DepartureDate;
        mAllReservations.FieldByName('Room').asString := Room;
        mAllReservations.FieldByName('RoomType').asString := RoomType;
        mAllReservations.FieldByName('Status').asString := status;
        mAllReservations['Breakfast'] := Breakfast.AsReadableString;
        mAllReservations.FieldByName('BreakfastGuests').asinteger := breakfastguests;
        mAllReservations['NoRoom'] := noRoom;
        mAllReservations.FieldByName('RoomDescription').asString := RoomDescription;
        mAllReservations['Bookable'] := Bookable;
        mAllReservations['hidden'] := hidden;
        mAllReservations.FieldByName('Location').asString := Location;
        mAllReservations.FieldByName('Floor').asinteger := Floor;
        mAllReservations.FieldByName('Equipments').asString := Equipments;
        mAllReservations.FieldByName('LocationDescription').asString := LocationDescription;
        mAllReservations['GroupAccount'] := GroupAccount;
        mAllReservations.FieldByName('marketSegment').asString := marketSegment;
        mAllReservations.FieldByName('marketSegmentDescription').asString := marketSegmentDescription;
        mAllReservations.FieldByName('Email').asString := Email;
        mAllReservations.FieldByName('Website').asString := Website;
        mAllReservations.FieldByName('Customer').asString := customer;
        mAllReservations.FieldByName('CustomerName').asString := CustomerName;
        mAllReservations.FieldByName('PersonalID').asString := PersonalID;
        mAllReservations.FieldByName('Statustext').asString := Statustext;
        mAllReservations.FieldByName('ResInfo').asString := ResInfo;
        mAllReservations.FieldByName('RoomCount').asinteger := RoomCount;
        mAllReservations.FieldByName('RvGuestCount').asinteger := RvGuestCount;
        mAllReservations.FieldByName('RRGuestCount').asinteger := RRGuestCount;
        mAllReservations.FieldByName('MainGuests').asString := Copy(mainGuests, 1, 100);
        mAllReservations.FieldByName('ResLine').asString := Copy(ResLine, 1, 100);
        mAllReservations.FieldByName('GroupReservation').asinteger := GroupReservation;
        mAllReservations.FieldByName('GroupReservationName').asString := GroupReservationName;

        mAllReservations.FieldByName('Currency').asString := Currency;
        mAllReservations.FieldByName('AverageRate').AsFloat := AverageRate;
        mAllReservations.FieldByName('Nights').asinteger := numDays;
        mAllReservations.FieldByName('TotalStayRate').AsFloat := TotalRate;
        mAllReservations.FieldByName('Adults').asinteger := Adults;
        mAllReservations.FieldByName('Children').asinteger := Children;
        mAllReservations.FieldByName('Infants').asinteger := Infants;
        mAllReservations.FieldByName('RoomNotes').asString := rSet.FieldByName('Hiddeninfo').asString;

        mAllReservations.Post;
        rSet.next;
      end;

      mAllReservations.first;
    finally
      Screen.Cursor := crDefault;
      mAllReservations.EnableControls;
      tvAllReservations.DataController.Groups.FullExpand;
    end;
  finally
    freeandNil(rSet);
  end;
  gAllReservations.SetFocus;
end;

procedure TfrmGuestList.rgrGroupReportDateTypeClick(Sender: TObject);
begin
  refreshGuestList;
  zGuestListFirstTime := false;
end;

procedure TfrmGuestList.rgrGroupreportStayTypeClick(Sender: TObject);
begin
  refreshGuestList;
  zGuestListFirstTime := false;
end;

procedure TfrmGuestList.rgrTypePropertiesEditValueChanged(Sender: TObject);
begin
  if not zGuestListFirstTime then
  begin
    refreshGuestList;
  end;
end;

procedure TfrmGuestList.rgrUsePropertiesEditValueChanged(Sender: TObject);
begin
  if not zGuestListFirstTime then
  begin
    refreshGuestList;
  end;
end;

procedure TfrmGuestList.SetDate(const Value: TDate);
begin
  FDate := Value;
  refreshGuestList;
end;

procedure TfrmGuestList.btnGuestListExcelClick(Sender: TObject);
var
  sFilename: string;
  s: string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Groups';
  ExportGridToExcel(sFilename, gAllReservations, true, true, true);
  ShellExecute(handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, SW_SHOWNORMAL);
end;

procedure TfrmGuestList.GuestListReport;
var
  sFilter: string;
  s: string;
  sortField: string;
  isDescending: boolean;
begin
  rptbGroups.Groups[0].NewPage := chkNewPage.Checked;

  if mAllReservations.RecordCount = 0 then
    exit;

  sFilter := tvAllReservations.DataController.Filter.FilterText;
  if m.active then
    m.Close;
  m.LoadFromDataSet(tvAllReservations.DataController.DataSource.DataSet, [mtcpoStructure]);

  m.Filtered := false;

  if sFilter <> '' then
  begin
    m.Filter := sFilter;
    m.Filtered := true;
    m.first;
  end;

  s := getSortField;

  sortField := 'Room';
  isDescending := false;

  if s <> '' then
  begin
    sortField := _strTokenAT(s, ';', 0);
    isDescending := (_strTokenAT(s, ';', 1) = 'd');
  end;

  m.SortFields := sortField;
  if not isDescending then
  begin
    m.Sort([]);
  end
  else
  begin
    m.Sort([mtcoDescending]);
  end;

  if frmRptbViewer <> nil then
    freeandNil(frmRptbViewer);
  frmRptbViewer := TfrmRptbViewer.Create(frmRptbViewer);
  try
    frmRptbViewer.Report := rptbGroups;
    frmRptbViewer.ShowModal;
  finally
    freeandNil(frmRptbViewer);
  end;

end;

procedure TfrmGuestList.mnuReservationProfileClick(Sender: TObject);
var
  iReservation: integer;
  iRoomReservation: integer;
begin
  if mAllReservations.IsEmpty then
    exit;
  iRoomReservation := mAllReservations['RoomReservation'];
  iReservation := mAllReservations['Reservation'];
  if EditReservation(iReservation, iRoomReservation) then
  begin
  end;
end;

procedure TfrmGuestList.mnuGuestprofileClick(Sender: TObject);
var
  theData: recPersonHolder;
begin
  if mAllReservations.IsEmpty then
    exit;

  initPersonHolder(theData);
  theData.RoomReservation := mAllReservations['RoomReservation'];
  theData.Reservation := mAllReservations['Reservation'];
  theData.name := mAllReservations['ReservationName'];

  if openGuestProfile(actNone, theData) then
    refreshGuestList;
end;

procedure TfrmGuestList.mnuPrintRegistrationFormClick(Sender: TObject);
var
  RoomResArray: IntegerArray;
  iRoomReservation: integer;
begin
  if mAllReservations.IsEmpty then
    exit;
  iRoomReservation := mAllReservations['RoomReservation'];
  SetLength(RoomResArray, 1);
  RoomResArray[LOW(RoomResArray)] := iRoomReservation;

  PrintRegistrationForm(RoomResArray);
end;

procedure TfrmGuestList.mnuCheckinClick(Sender: TObject);
var
  iRoomReservation: integer;
  iReservation: integer;
begin
  if mAllReservations.IsEmpty then
    exit;
  iRoomReservation := mAllReservations['RoomReservation'];
  iReservation := mAllReservations['Reservation'];

  CheckInARoom(iReservation, iRoomReservation);
end;

procedure TfrmGuestList.mnuCheckoutClick(Sender: TObject);
var
  iRoomReservation, iReservation: integer;
  Room: String;
begin
  if mAllReservations.IsEmpty then
    exit;
  iRoomReservation := mAllReservations['RoomReservation'];
  iReservation := mAllReservations['Reservation'];
  Room := mAllReservations['Room'];
  CheckOutARoom(Room, iRoomReservation, iReservation);
end;

constructor TfrmGuestList.Create(aOwner: TComponent);
begin
  inherited;
  zGuestListFirstTime := true;
end;

procedure TfrmGuestList.mnuRoomInvoiceClick(Sender: TObject);
var
  iReservation, iRoomReservation: integer;
begin
  if mAllReservations.IsEmpty then
    exit;
  iRoomReservation := mAllReservations['RoomReservation'];
  iReservation := mAllReservations['Reservation'];
  EditInvoice(iReservation, iRoomReservation, TInvoiceType.itDebitInvoice, 0, false);
  refreshGuestList;
end;

procedure TfrmGuestList.mnuGroupInvoiceClick(Sender: TObject);
var
  iReservation: integer;
begin
  if mAllReservations.IsEmpty then
    exit;
  iReservation := mAllReservations['Reservation'];
  EditInvoice(iReservation, 0, TInvoiceType.itDebitInvoice, 0, false);
  refreshGuestList;
end;

function TfrmGuestList.GetDate: TDate;
begin
  result := FDate;
end;

procedure TfrmGuestList.btnGroupReportShowClick(Sender: TObject);
begin
  GuestListReport;
end;

procedure TfrmGuestList.ppGroupHeaderBand1BeforePrint(Sender: TObject);
var
  Reservation: integer;
  Information, PMInfo: string;
begin
  if chkPrintMemo.Checked then
  begin
    Reservation := m.FieldByName('reservation').asinteger;
    d.RV_getMemos(Reservation, Information, PMInfo);
    mem.Text := Information;
  end;
end;

procedure TfrmGuestList.ppHeaderBand1BeforePrint(Sender: TObject);
var
  s: string;
begin
  dateTimeToString(s, 'dd.mm.yyyy', FDate);
  rlabFrom.Caption := s;

  s := g.qHotelName;
  rLabHotelName.Caption := s;

  dateTimeToString(s, 'dd mmm yyyy hh:nn', now);

  s := { 1098 } GetTranslatedText('shCreated') + ' : ' + s;
  rLabTimeCreated.Caption := s;

  s := { 1099 } GetTranslatedText('shUser') + ' : ' + g.qUser;
  if g.qUserName <> '' then
    s := s + ' - ' + g.qUserName;
  rlabUser.Caption := s;

  s := { 2000 } GetTranslatedText('shGroups') + ' ';

  case rgrGroupreportStayType.ItemIndex of
    0:
      s := { 2002 } GetTranslatedText('shArriving') + ' ' + s;
    1:
      s := { 2001 } GetTranslatedText('shDeparting') + ' ' + s;
    2:
      s := { 2003 } GetTranslatedText('shAll') + ' ' + s;
  end;

  rLabReportName.Caption := s;
end;


procedure TfrmGuestList.CheckOutARoom(const Room: String; iRoomReservation, iReservation: integer);
var
  lRoomStateCHanger: TRoomReservationStateChangeHandler;
begin

  lRoomStateCHanger := TRoomReservationStateChangeHandler.Create(iReservation, iRoomReservation);
  try
    if lRoomStateChanger.ChangeState(rsDeparted) then
      refreshGuestList;
  finally
    lRoomStateChanger.Free;
  end;
end;

function TfrmGuestList.CheckInARoom(iReservation, iRoomReservation: integer): boolean;
var
  lResStateChanger: TRoomReservationStateChangeHandler;
begin

  lResStateChanger := TRoomReservationStateChangeHandler.Create(iReservation, iRoomReservation) ;
  try
    Result := lResStateChanger.ChangeState(rsGuests);
  finally
    lResStateChanger.Free;
  end;
  if Result then
    refreshGuestList;

end;
end.
