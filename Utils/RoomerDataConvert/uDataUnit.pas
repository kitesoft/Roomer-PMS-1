unit uDataUnit;

interface

uses Data.DB, Data.Win.ADODB, cmpRoomerDataSet;

procedure PrepareRoomerConnection;
function ParameterByName(name: String): String;

var
  RoomerDataSet: TRoomerDataSet;

implementation

uses SysUtils;

{$IFDEF LOCALRESOURCE}
  const RoomerBase : String = 'http://localhost';
  const RoomerStoreBase : String = 'http://localhost';
  const RoomerBasePort : String = '8080';
  const RoomerStoreBasePort : String = '8080';
{$ELSE}
  {$IFDEF ROOMERSSL}
    const RoomerBase : String = 'https://secure.roomercloud.net';
    const RoomerBasePort : String = '8443';
  {$ELSE}
    const RoomerBase : String = 'http://secure.roomercloud.net';
    const RoomerBasePort : String = '8080';
  {$ENDIF}
  const RoomerStoreBase : String = 'http://store.roomercloud.net';
  const RoomerStoreBasePort : String = '8080';
{$ENDIF}


var

  RoomerStoreUri : String;
  RoomerApiUri : String;
  RoomerApiEntitiesUri : String;
  RoomerApiDatasetsUri : String;

procedure CreateRoomerDataSet;
begin
  RoomerDataSet := TRoomerDataSet.Create(nil);
  RoomerDataSet.RoomerStoreUri := RoomerStoreUri;
  RoomerDataSet.RoomerUri := RoomerApiUri;
  RoomerDataSet.RoomerEntitiesUri := RoomerApiEntitiesUri;
  RoomerDataSet.RoomerDatasetsUri := RoomerApiDatasetsUri;
end;

procedure PrepareRoomerConnection;
var _RoomerBase,
    _RoomerBasePort,
    _RoomerStoreBase,
    _RoomerStoreBasePort : String;
begin

  _RoomerBase := ParameterByName('RoomerBase');
  if _RoomerBase = '' then
    _RoomerBase := RoomerBase;
  _RoomerBasePort := ParameterByName('Port');
  if _RoomerBasePort = '' then
    _RoomerBasePort := RoomerBasePort;

  _RoomerStoreBase := ParameterByName('RoomerStoreBase');
  if _RoomerStoreBase = '' then
    _RoomerStoreBase := RoomerStoreBase;
  _RoomerStoreBasePort := ParameterByName('RoomerStoreBasePort');
  if _RoomerStoreBasePort = '' then
    _RoomerStoreBasePort := RoomerStoreBasePort;

  RoomerStoreUri := _RoomerStoreBase + ':' + _RoomerStoreBasePort + '/services/';
  RoomerApiUri := _RoomerBase + ':' + _RoomerBasePort + '/services/';
  RoomerApiEntitiesUri := _RoomerBase + ':' + _RoomerBasePort + '/services/entities/';
  RoomerApiDatasetsUri := _RoomerBase + ':' + _RoomerBasePort + '/services/datasets/';

  CreateRoomerDataSet;
end;

procedure Login(hotel, username, password : String);
begin

end;

function ParameterByName(name: String): String;
var
  i, iNameLength: Integer;
  param: String;
begin
  Result := '';
  for i := 1 to ParamCount do
  begin
    // example=value
    // 1234567890123
    // ==> Name length = 7 + 1 = 8
    // Value location = Name length + 1 = 9
    iNameLength := length(name) + 1;
    param := ParamStr(i);
    if Lowercase(copy(param, 1, iNameLength)) = Lowercase(name) + '=' then
    begin
      Result := copy(param, iNameLength + 1, length(param));
    end;
  end;
end;

end.
