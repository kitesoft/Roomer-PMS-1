unit uRptHouseKeeping;

interface

uses
  Winapi.Windows, Winapi.Messages
  , cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore,
  dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter,
  cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxSkinsdxStatusBarPainter,
  dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns,
  dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, cxLabel, cxTextEdit, cxTimeEdit, cxSpinEdit, cxMemo,
  cxGridCustomTableView, cxGridTableView, cxGridDBTableView, Vcl.Controls, Vcl.StdCtrls, sComboBox, Vcl.Mask, sMaskEdit,
  sCustomComboEdit, sToolEdit, sLabel, sGroupBox, System.Classes, System.Actions, Vcl.ActnList, dxPSCore, dxPScxCommon,
  cxClasses, kbmMemTable, cxPropertiesStore, dxStatusBar, cxGridLevel, cxGridCustomView, cxGrid, sButton, Vcl.ExtCtrls,
  sPanel
  , uRoomerGridForm, Vcl.Buttons, Vcl.Dialogs, sDialogs, uRoomerReportGridForm
  ;

type
  TfrmHouseKeepingReport = class(TfrmRoomerReportGridForm)
    gbxSelection: TsGroupBox;
    dtDate: TsDateEdit;
    cbxLocations: TsComboBox;
    lblDate: TsLabel;
    lblLocation: TsLabel;
    kbmGridDataroom: TStringField;
    kbmGridDataroomtype: TStringField;
    kbmGridDatafloor: TIntegerField;
    kbmGridDataLastGuests: TIntegerField;
    kbmGridDataArrivingGuests: TIntegerField;
    kbmGridDataexpectedcot: TTimeField;
    kbmGridDatahousekeepingstatus: TStringField;
    kbmGridDatalocation: TStringField;
    kbmGridDataexpectedtoa: TTimeField;
    kbmGridDataRoomnotes: TMemoField;
    kbmGridDatamaintenancenotes: TMemoField;
    kbmGridDatacleaningnotes: TMemoField;
    grDataDBTableView1roomtype: TcxGridDBColumn;
    grDataDBTableView1floor: TcxGridDBColumn;
    grDataDBTableView1LastGuests: TcxGridDBColumn;
    grDataDBTableView1ArrivingGuests: TcxGridDBColumn;
    grDataDBTableView1expectedcot: TcxGridDBColumn;
    grDataDBTableView1housekeepingstatus: TcxGridDBColumn;
    grDataDBTableView1location: TcxGridDBColumn;
    grDataDBTableView1expectedtoa: TcxGridDBColumn;
    grDataDBTableView1Roomnotes: TcxGridDBColumn;
    grDataDBTableView1maintenancenotes: TcxGridDBColumn;
    grDataDBTableView1cleaningnotes: TcxGridDBColumn;
    grDataDBTableView1Room: TcxGridDBColumn;
    procedure grDataDBTableView1ArrivingGuestsGetDisplayText(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AText: string);
  private
   { Private declarations }
    procedure UpdateLocations;
  protected
    procedure UpdateControls; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
  end;


/// <summary>
///   Global access point for showing the arrival report form, If Modalresult is OK then True is returned
/// </summary>
function ShowHouseKeepingReport(aDate: TDateTime): boolean;

implementation

{$R *.dfm}

uses
   uAppGlobal
  , uUtils
  , SysUtils
  , PrjConst
  , Math
  , _Glob
  , uReservationStateDefinitions
  , uRoomerDataProvider
  ;


type
  THouseKeepingDataProvider = class(TRoomerSQLDataProvider)
  private
    const
      cRemovedReservations: TReservationStateSet = [rsCancelled];
      cSQL =
        {$REGION 'SQL statement'}
        '	select * '#10+
        '	from '#10+
        '	( '#10+
        '	select '#10+
        '	 r.room, '#10+
        '	 r.roomtype, '#10+
        '	 r.floor, '#10+
        '	 l.description as location, '#10+
        '	 coalesce(departing.NumGuestsD, stayover.NumGuestsS) as LastGuests, '#10+
        '	 arriving.NumGuestsA as ArrivingGuests, '#10+
        '	 departing.ExpectedCheckOutTime as expectedCOT, '#10+
        '	 arriving.ExpectedTimeOfArrival as expectedTOA, '#10+
        '	 arriving.hiddeninfo as Roomnotes, '#10+
        '	 rm.CleaningNotes, '#10+
        '	 rm.MaintenanceNotes, '#10+
        '	 case '#10+
        '	   when (not IsNUll(departing.room) and not IsNull(arriving.room)) then CONCAT({departure}, '' + '', {arrival}) '#10+
        '	   when (not IsNUll(departing.room)) then {departure} '#10+
        '	   when (not IsNUll(arriving.room)) then {arrival} '#10+
        '	   when (not IsnUll(stayover.room)) then {stayover} '#10+
        '    when (r.Status in (''U'', ''R'')) then (Select name from maintenancecodes mc where mc.code= r.Status) '#10+
        '	 end as HousekeepingStatus '#10+
        '	from '#10+
        '	  rooms r '#10+
        '	  JOIN roomtypes rt on rt.roomtype=r.roomtype '#10+
        '	  JOIN locations l on l.Location=r.location '#10+
        '   LEFT JOIN maintenanceroomnotes rm ON rm.Room=r.Room '#10+
        ' '#10+
        '	  LEFT OUTER JOIN ( SELECT * '#10+
        '			 , (select count(*) from persons p where p.roomreservation = rrd.RoomReservation)  + rrd.numChildren + rrd.numInfants as NumGuestsD '#10+
        '	         FROM roomreservations rrd '#10+
        '			 where rrd.status not in {excludedStates} and rrd.departure = {probedate} '#10+
        '			) departing on departing.room = r.room '#10+
        ' '#10+
        '		LEFT OUTER JOIN ( SELECT * '#10+
        '			 , (select count(*) from persons p where p.roomreservation = rra.RoomReservation)  + rra.numChildren + rra.numInfants as NumGuestsA '#10+
        '	         FROM roomreservations rra '#10+
        '			 where rra.status not in {excludedStates} and rra.arrival= {probedate} '#10+
        '			) arriving on arriving.room = r.room '#10+
        ' '#10+
        '		LEFT OUTER JOIN ( SELECT * '#10+
        '			 , (select count(*) from persons p where p.roomreservation = rrs.RoomReservation)  + rrs.numChildren + rrs.numInfants as NumGuestsS '#10+
        '	         FROM roomreservations rrs '#10+
        '			 where rrs.status not in {excludedStates} and rrs.arrival < {probedate} and rrs.departure > {probedate} '#10+
        '			) stayover on stayover.room=r.room '#10+
        '	 group by room, roomtype, floor, numberguests '#10+
        '	 order by floor, room ) x '#10+
        '	 where not x.HousekeepingStatus is null ';
        {$ENDREGION}
    var
      FForm: TfrmHouseKeepingReport;
  protected
    function ConstructSQLStatement: string; override;
  public
    property Form: TfrmHouseKeepingReport read FForm write FForm; // hmmm not a very neat solution. must be improved
  end;




function ShowHouseKeepingReport(aDate: TDateTime):  boolean;
var
  frm: TfrmHouseKeepingReport;
begin
  frm := TfrmHouseKeepingReport.Create(nil);
  try
    frm.ShowModal;
    Result := (frm.modalresult = mrOk);
  finally
    frm.Free;
  end;
end;


constructor TfrmHouseKeepingReport.Create(aOwner: TComponent);
begin
  FDataProviderClass := THouseKeepingDataProvider;
  inherited;
  THouseKeepingDataProvider(FDataProviderClass).Form := Self;
end;

procedure TfrmHouseKeepingReport.grDataDBTableView1ArrivingGuestsGetDisplayText(
  Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  if aText = '0'then aText := '';
end;

procedure TfrmHouseKeepingReport.UpdateControls;
begin
  inherited;
  UpdateLocations;
end;

procedure TfrmHouseKeepingReport.UpdateLocations;
var
  lCurrentSelection: string;
begin

  lCurrentSelection := '';
  if cbxLocations.ItemIndex >= 0 then
    lCurrentSelection := cbxLocations.Text;

  cbxLocations.Clear;

  glb.Locations.First;
  while not glb.Locations.Eof do
  begin
    cbxLocations.Items.Add(glb.Locations['Description']);
    glb.Locations.Next;
  end;

  if lCurrentSelection.IsEmpty then
    if cbxLocations.Items.Count = 1 then
      cbxLocations.ItemIndex := 0
    else
      cbxLocations.ItemIndex := -1
  else
    cbxLocations.ItemIndex := cbxLocations.Items.IndexOf(lCurrentSelection);
end;

function THouseKeepingDataProvider.ConstructSQLStatement: string;
begin
  Result := ReplaceString(cSQL, '{probedate}', _db(Form.dtDate.Date));
  Result := ReplaceString(Result, '{departure}', _db(GetTranslatedText('shTx_Housekeepinglist_Departure')));
  Result := ReplaceString(Result, '{arrival}', _db(GetTranslatedText('shTx_Housekeepinglist_Arriving')));
  Result := ReplaceString(Result, '{stayover}', _db(GetTranslatedText('shTx_Housekeepinglist_Stayover')));
  Result := ReplaceString(Result, '{excludedStates}', cRemovedReservations.AsSQLString);

  if Form.cbxLocations.ItemIndex >= 0 then
    Result := Result + ' AND location = ' + _db(Form.cbxLocations.Text);
  CopyToClipboard(Result);
end;



end.
