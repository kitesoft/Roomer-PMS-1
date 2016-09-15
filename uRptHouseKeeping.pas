unit uRptHouseKeeping;

interface

uses
  Winapi.Windows, Winapi.Messages
  , uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore,
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

  ;

type
  TfrmHouseKeepingReport = class(TfrmBaseRoomerGridForm)
    FormStore: TcxPropertiesStore;
    gbxSelection: TsGroupBox;
    dtDate: TsDateEdit;
    cbxLocations: TsComboBox;
    lblDate: TsLabel;
    lblLocation: TsLabel;
    grHouseKeepingListDBTableView1room: TcxGridDBColumn;
    grHouseKeepingListDBTableView1roomtype: TcxGridDBColumn;
    grHouseKeepingListDBTableView1floor: TcxGridDBColumn;
    grHouseKeepingListDBTableView1expectedcot: TcxGridDBColumn;
    grHouseKeepingListDBTableView1location: TcxGridDBColumn;
    grHouseKeepingListDBTableView1Roomnotes: TcxGridDBColumn;
    grHouseKeepingListDBTableView1LastGuests: TcxGridDBColumn;
    grHouseKeepingListDBTableView1ArrivingGuests: TcxGridDBColumn;
    grHouseKeepingListDBTableView1housekeepingstatus: TcxGridDBColumn;
    grHouseKeepingListDBTableView1expectedtoa: TcxGridDBColumn;
    grHouseKeepingListDBTableView1maintenancenotes: TcxGridDBColumn;
    grHouseKeepingListDBTableView1cleaningnotes: TcxGridDBColumn;
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
    procedure grHouseKeepingListDBTableView1ArrivingGuestsGetDisplayText(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AText: string);
  private
   { Private declarations }
    procedure UpdateLocations;
  protected
    procedure UpdateControls; override;
    function ConstructSQLStatement: string; override;
  public
    { Public declarations }
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
  ;

const
  cSQL =
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
      '			 where rrd.status not in (''C'', ''D'') and rrd.departure = {probedate} '#10+
      '			) departing on departing.room = r.room '#10+
      ' '#10+
      '		LEFT OUTER JOIN ( SELECT * '#10+
      '			 , (select count(*) from persons p where p.roomreservation = rra.RoomReservation)  + rra.numChildren + rra.numInfants as NumGuestsA '#10+
      '	         FROM roomreservations rra '#10+
      '			 where rra.status not in (''C'', ''D'') and rra.arrival= {probedate} '#10+
      '			) arriving on arriving.room = r.room '#10+
      ' '#10+
      '		LEFT OUTER JOIN ( SELECT * '#10+
      '			 , (select count(*) from persons p where p.roomreservation = rrs.RoomReservation)  + rrs.numChildren + rrs.numInfants as NumGuestsS '#10+
      '	         FROM roomreservations rrs '#10+
      '			 where rrs.status not in (''C'', ''D'') and rrs.arrival < {probedate} and rrs.departure > {probedate} '#10+
      '			) stayover on stayover.room=r.room '#10+
      '	 group by room, roomtype, floor, numberguests '#10+
      '	 order by floor, room ) x '#10+
      '	 where not x.HousekeepingStatus is null ';


function ShowHouseKeepingReport(aDate: TDateTime):  boolean;
var
  frm: TfrmHouseKeepingReport;
begin
  frm := TfrmHouseKeepingReport.Create(nil);
  try
    frm.dtDate.Date := aDate;
    frm.ShowModal;
    Result := (frm.modalresult = mrOk);
  finally
    frm.Free;
  end;
end;


function TfrmHouseKeepingReport.ConstructSQLStatement: string;
begin
  Result := ReplaceString(cSQL, '{probedate}', _db(dtDate.Date));
  Result := ReplaceString(Result, '{departure}', _db(GetTranslatedText('shTx_Housekeepinglist_Departure')));
  Result := ReplaceString(Result, '{arrival}', _db(GetTranslatedText('shTx_Housekeepinglist_Arriving')));
  Result := ReplaceString(Result, '{stayover}', _db(GetTranslatedText('shTx_Housekeepinglist_Stayover')));
  if cbxLocations.ItemIndex >= 0 then
    Result := Result + ' AND location = ' + _db(cbxLocations.Text);
  CopyToClipboard(Result);
end;


procedure TfrmHouseKeepingReport.grHouseKeepingListDBTableView1ArrivingGuestsGetDisplayText(
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
    cbxLocations.ItemIndex := -1
  else
    cbxLocations.ItemIndex := cbxLocations.Items.IndexOf(lCurrentSelection);
end;

end.
