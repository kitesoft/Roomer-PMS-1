unit uRoomServicesAPI;

interface
uses
    cmpRoomerDataset
  , uMobileAPI
  , SysUtils
  , Classes, uRoomservicesStatus
  ;

type
  ERoomServicesMobileAPICallerException = class(EMobileAPICallerException);

  RRoomServicesSetStatusParameters = record
    Status: string;
    setStatus: boolean;
    CleaningNotes: string;
    setCleaningNotes: boolean;
    MaintenanceNotes: string;
    setMaintenanceNotes: boolean;
    lostAndFound: string;
    setLostAndFound: boolean;

    procedure Clear;
  end;

  TRoomServicesMobileAPICaller = class(TBaseMobileAPICaller)
  private const
    cRoomServicesURI = '/roomservices';
  protected
    function getURI: string; override;
  public
    /// <summary>
    ///   Implementation of /roomservices/setstatus mobile api endpoint, changing the room cleaning state
    /// </summary>
    procedure SetStatus(const aRoom: string; aDate: TDate; const aParams: RRoomServicesSetStatusParameters);
    procedure GetRoomDetails(const aRoom: string; aRoomDetails: TRoomServicesStatus);
  end;

implementation

uses
  uD
  , uDateUtils
  , WinAPI.Windows
  ;

{ TRoomServicesMobileAPICaller }

procedure TRoomServicesMobileAPICaller.GetRoomDetails(const aRoom: string; aRoomDetails: TRoomServicesStatus);
const
  cGetRoomDetailsURI = '/roomdetails';
var
  lResponse: string;
begin
  Assert(assigned(aRoomDetails));
  aRoomDetails.Clear;
  try
    lResponse := d.roomerMainDataSet.downloadRoomerUrlAsString(getURI + cGetRoomDetailsURI + '?room=' +
                      d.roomerMainDataSet.ForcedUrlEncode(aRoom));
    aRoomDetails.LoadFromXML(lResponse);
  except
    on E: Exception do
    begin
      aRoomDetails.Clear;
      raise ERoomServicesMobileAPICallerException.CreateFmt('Error while retrieving roomstatus details: [%s]', [e.Message]);
    end;
  end;
end;

function TRoomServicesMobileAPICaller.getURI: string;
begin
  Result := inherited + cRoomServicesURI;
end;

procedure TRoomServicesMobileAPICaller.SetStatus(const aRoom: string; aDate: TDate; const aParams: RRoomServicesSetStatusParameters);
const
  cSetStatusURI = '/setstatus';
var
  lData: TStringList;
  lResponse: string;
//  @FormParam("room") final String room,
//  @FormParam("dt") final String date,
//	@FormParam("st") final String status,
//	@FormParam("cn") final String cleaningNotes,
//	@FormParam("mn") final String maintenanceNotes,
//	@FormParam("lf") final String lostAndFound)
begin
  lData := TStringlist.Create;
  try
    lData.Delimiter := '&';
    lData.StrictDelimiter := true;

    lData.Add(Format('room=%s', [d.roomerMainDataSet.ForcedUrlEncode(aRoom)]));
    lData.Add(Format('dt=%s', [dateToSqlString(aDate)]));
    if aParams.setStatus then
      lData.Add(Format('st=%s', [aParams.Status]));
    if aParams.setCleaningNotes then
      lData.Add(Format('cn=%s', [d.roomerMainDataSet.ForcedUrlEncode(aParams.CleaningNotes)]));
    if aParams.setMaintenanceNotes then
      lData.Add(Format('mn=%s', [d.roomerMainDataSet.ForcedUrlEncode(aParams.MaintenanceNotes)]));
    if aParams.setLostAndFound then
      lData.Add(Format('lf=%s', [d.roomerMainDataSet.ForcedUrlEncode(aParams.lostAndFound)]));

    if lData.Count > 2 then
      lResponse := d.roomerMainDataSet.PostData(getURI + cSetStatusURI, lData.DelimitedText);

  finally
    lData.Free;
  end;

end;

{ RRoomServicesSetStatusParameters }

procedure RRoomServicesSetStatusParameters.Clear;
begin
  Status := '';
  setStatus := false;;
  CleaningNotes := '';
  setCleaningNotes := false;;
  MaintenanceNotes := '';
  setMaintenanceNotes := false;;
  lostAndFound := '';
  setLostAndFound := false;;
end;

end.
