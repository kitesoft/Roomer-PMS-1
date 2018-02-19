unit uConnectionsStatisticsService;

interface

uses
  UITypes
  , SysUtils
  , Classes
  , uD
  , uDateUtils
  , Generics.Collections;


type

  TExportType = (etFull, etIncremental);

  TConnectionsStatisticsService = class
  private
    FSystemCode : String;
  public
    constructor Create(const SystemCode : String);

    function GetSettings : String;
    function SaveSettings(const settingsAsXml : String): String;
    procedure forceExport(ExportType : TExportType);
    function sendToHagstofa(fromDate, toDate : TDate; location : String) : String;
  end;

implementation

{ TConnectionsStatisticsService }

uses uUtils;

constructor TConnectionsStatisticsService.Create(const SystemCode: String);
begin
  FSystemCode := SystemCode;
end;

procedure TConnectionsStatisticsService.forceExport(ExportType: TExportType);
begin
  if ExportType = etFull then
    d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/force/FULL')
  else
    d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/force/INCREMENTAL');
end;

function TConnectionsStatisticsService.sendToHagstofa(fromDate, toDate : TDate; location : String) : String;
var url : String;
begin
  url := d.roomerMainDataSet.RoomerUri +
            format('statisticsConnect/hagstofa?fromDate=%s&toDate=%s&location=%s',
            [
              uDateUtils.dateToSqlString(fromDate),
              uDateUtils.dateToSqlString(toDate),
              location
            ]);
  CopyToClipboard(url);
  result := d.roomerMainDataSet.downloadUrlAsString(url);
//  if LowerCase(result) <> 'success' then
//    raise Exception.Create('Error message from Hagstofa: ' + #10#10 + result);
end;

function TConnectionsStatisticsService.GetSettings: String;
begin
  result := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/' + FSystemCode);
end;

function TConnectionsStatisticsService.SaveSettings(const settingsAsXml : String): String;
begin
  result := d.roomerMainDataSet.downloadUrlAsStringUsingPut(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/' + FSystemCode, settingsAsXml);
end;

end.
