unit uConnectionsHagstofaService;

interface

uses
  UITypes
  , SysUtils
  , Classes
  , uD
  , uDateUtils
  , Generics.Collections;


type

  TConnectionsHagstofaService = class
  public
    function sendToHagstofa(fromDate, toDate : TDate; const location : String) : String;
  end;

implementation

uses uUtils;

function TConnectionsHagstofaService.sendToHagstofa(fromDate, toDate : TDate; const location : String) : String;
var url : String;
begin
  url := d.roomerMainDataSet.RoomerUri +
            format('statisticsConnect/hagstofa?fromDate=%s&toDate=%s&location=%s',
            [
              uDateUtils.dateToSqlString(fromDate),
              uDateUtils.dateToSqlString(toDate),
              location
            ]);
  result := d.roomerMainDataSet.downloadUrlAsString(url);
end;

end.
