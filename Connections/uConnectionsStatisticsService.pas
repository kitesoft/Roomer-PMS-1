unit uConnectionsStatisticsService;

interface

uses
  UITypes
  , SysUtils
  , Classes
  , uD
  , Generics.Collections;


type

  TExportType = (etFull, etIncremental);

  TConnectionsStatisticsService = class
  private
    FSystemCode : String;
  public
    constructor Create(SystemCode : String);
    destructor Destroy;

    function GetSettings : String;
    function SaveSettings(settingsAsXml : String): String;
    procedure forceExport(ExportType : TExportType);
  end;

implementation

{ TConnectionsStatisticsService }

constructor TConnectionsStatisticsService.Create(SystemCode: String);
begin
  FSystemCode := SystemCode;
end;

destructor TConnectionsStatisticsService.Destroy;
begin
  //
end;

procedure TConnectionsStatisticsService.forceExport(ExportType: TExportType);
begin
  if ExportType = etFull then
    d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/force/FULL')
  else
    d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/force/INCREMENTAL');
end;

function TConnectionsStatisticsService.GetSettings: String;
begin
  result := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/' + FSystemCode);
end;

function TConnectionsStatisticsService.SaveSettings(settingsAsXml : String): String;
begin
  result := d.roomerMainDataSet.downloadUrlAsStringUsingPut(d.roomerMainDataSet.RoomerUri + 'statisticsConnect/' + FSystemCode, settingsAsXml);
end;

end.
