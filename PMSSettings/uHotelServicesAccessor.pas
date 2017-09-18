unit uHotelServicesAccessor;

interface

uses
  cmpRoomerDataset
  , SysUtils
  ;

type

  EHotelServicesAccessorCreateServiceException = class(Exception);

  THotelServicesSettingsGetSetOption = (psoExceptionOnNotFound);
  THotelServicesSettingsGetSetOptions = set of THotelServicesSettingsGetSetOption;

  /// <summary>
  ///   Settings accessor for settings stored in home100.HOTELSERVICES.
  ///
  ///  Future Improvement:
  ///     Allow setting to postpone writing updates to database, using a DisableUpdates/EnableUpdates pattern
  ///     Use the (already present) Dataset to optimize database access, only reading and writing when needed
  ///
  /// </summary>
  THotelServicesAccessor = class
  private type
    THotelServicesKeys = record
      hotelId: string;
      Service: string;
      ServiceType: string;
      function ToString: string;
    end;
  private
    FDataset: TRoomerDataset;
    function GetHotelServicesData(const aKey: THotelServicesKeys): boolean;
    function GetExtraInfo(const aKey: THotelServicesKeys): string;
    procedure CreateHotelServicesKey(const aKey: THotelServicesKeys);
  protected
    procedure InternalSaveSetting(const aService, aServiceType, aExtraInfoName, aValue: String; aOptions: THotelServicesSettingsGetSetOptions); virtual;
    function InternalGetSetting(const aService, aServiceType, aExtraInfoName: String; aOptions: THotelServicesSettingsGetSetOptions; var aSetting: string): boolean; virtual;
  public
    constructor Create;
    destructor Destroy; override;

    function GetServiceEnabled(const aService, aServiceType: string): boolean;
    function GetServiceSettingAsString(const aService, aServiceType, aExtraInfoName: String; Default: string=''): string;
    function GetServiceSettingAsInteger(const aService, aServiceType, aExtraInfoName: String; Default: integer=0): integer;
    function GetServiceSettingAsBoolean(const aService, aServiceType, aExtraInfoName: String; Default: boolean=False): boolean;

    procedure SetServiceEnabled(const aService, aServiceType: string; aEnabled: boolean);
    procedure SetServiceSettingAsInteger(const aService, aServiceType, aExtraInfoName: String; aNewValue: integer);
    procedure SetServiceSettingAsString(const aService, aServiceType, aExtraInfoName: String; const aNewValue: String);
    procedure SetServiceSettingAsBoolean(const aService, aServiceType, aExtraInfoName: String; const aNewValue: boolean);
  end;


implementation

uses
  Classes
  , uSQLUtils
  , uUtils
  , uD
  , hData
  ;

{ THotelServicesAccessor }

function THotelServicesAccessor.InternalGetSetting(const aService, aServiceType, aExtraInfoName: String; aOptions: THotelServicesSettingsGetSetOptions; var aSetting: string): boolean;
var
  lKey: THotelServicesKeys;
  lList: TStringList;
begin
  lKey.hotelId := FDataset.hotelId;
  lKey.Service := aService;
  lKey.ServiceType := aServiceType;

  lList := TStringList.Create;
  try
   lList.Delimiter := ';';
   lList.StrictDelimiter := true;
   lList.DelimitedText := GetExtraInfo(lKey);
   if (lList.IndexOfName(aExtraInfoName) >= 0) then
   begin
     Result := true;
     aSetting := lList.Values[aExtraInfoName];
   end
   else
    Result := false;

  finally
    lList.Free;
  end;

end;

procedure THotelServicesAccessor.InternalSaveSetting(const aService, aServiceType, aExtraInfoName, aValue: String; aOptions: THotelServicesSettingsGetSetOptions);
var
  sql: string;
  lList: TStringlist;
  lKey: THotelServicesKeys;
begin
//  inherited;
  lKey.hotelId := FDataset.hotelId;
  lKey.Service := aService;
  lKey.ServiceType := aServiceType;

  lList := TStringlist.Create;
  try
    lList.Delimiter := ';';
    lList.StrictDelimiter := true;
    lList.DelimitedText := GetExtraInfo(lKey);
    lList.Values[aExtraInfoName] := aValue;

    sql := Format('UPDATE home100.hotelservices SET extraInfo=%s where hotelId=%s and Service=%s and ServiceType=%s',
                  [ _db(lList.DelimitedText), _db(lKey.hotelId), _db(lKey.Service), _db(lKey.ServiceType)]);
    FDataset.DoCommand(sql)
  finally
    lList.Free;
  end;
end;


procedure THotelServicesAccessor.SetServiceEnabled(const aService, aServiceType: string; aEnabled: boolean);
var
  lKey: THotelServicesKeys;
  sql: string;
begin
  lKey.hotelId := FDataset.hotelId;
  lKey.Service := aService;
  lKey.ServiceType := aServiceType;

  sql := Format('UPDATE home100.hotelservices SET active=%d where hotelId=%s and Service=%s and ServiceType=%s',
                  [ iif(aEnabled, 1, 0), _db(lKey.hotelId), _db(lKey.Service), _db(lKey.ServiceType)]);
  FDataset.DoCommand(sql)
end;

procedure THotelServicesAccessor.SetServiceSettingAsBoolean(const aService, aServiceType, aExtraInfoName: String;
  const aNewValue: boolean);
begin
  InternalSaveSetting(aService, aServiceType, aExtraInfoName, BoolToStr(aNewValue, True).ToUpper, []);
end;

procedure THotelServicesAccessor.SetServiceSettingAsInteger(const aService, aServiceType, aExtraInfoName: String;
  aNewValue: integer);
begin
  InternalSaveSetting(aService, aServiceType, aExtraInfoName, IntToStr(aNewValue), []);
end;

procedure THotelServicesAccessor.SetServiceSettingAsString(const aService, aServiceType, aExtraInfoName, aNewValue: String);
begin
  InternalSaveSetting(aService, aServiceType, aExtraInfoName, aNewValue, []);
end;

constructor THotelServicesAccessor.Create;
begin
  FDataset := d.roomerMainDataSet.CreateNewDataset;
end;

destructor THotelServicesAccessor.Destroy;
begin
  FDataset.Free;
  inherited;
end;

procedure THotelServicesAccessor.CreateHotelServicesKey(const aKey: THotelServicesKeys);
var
  sql: string;
begin
  sql := Format('INSERT INTO home100.hotelservices (hotelId, service, serviceType, active) VALUES (%s, %s, %s, 0)',
                [ _db(aKey.hotelId), _db(aKey.Service), _db(aKey.ServiceType)]);
  if not hData.cmd_bySQL(sql) then
    raise EHotelServicesAccessorCreateServiceException.CreateFmt('Failed to create hotelservice [%s]', [aKey.ToString]);

end;

function THotelServicesAccessor.GetExtraInfo(const aKey: THotelServicesKeys): string;
begin
  Result := '';
  if GetHotelServicesData(aKey) then
    Result := FDataset.FieldByName('extraInfo').asString
  else
    CreateHotelServicesKey(aKey);
end;

function THotelServicesAccessor.GetHotelServicesData(const aKey: THotelServicesKeys): boolean;
var
  sql: string;
begin
  sql := Format('SELECT * FROM home100.hotelservices where hotelId=%s and service=%s and serviceType=%s',
                [ _db(aKey.hotelId), _db(aKey.Service), _db(aKey.ServiceType)]);
  Result := hData.rSet_bySQL(FDataset, sql);
end;


function THotelServicesAccessor.GetServiceEnabled(const aService, aServiceType: string): boolean;
var
  lKey: THotelServicesKeys;
begin
  lKey.hotelId := FDataset.hotelId;
  lKey.Service := aService;
  lKey.ServiceType := aServiceType;
  if GetHotelServicesData(lKey) then
    Result := FDataset.FieldByName('active').AsBoolean
  else
    Result := false;
end;

function THotelServicesAccessor.GetServiceSettingAsBoolean(const aService, aServiceType, aExtraInfoName: String; Default: boolean): boolean;
var
  lSetting: string;
begin
  if not InternalGetSetting(aService, aServiceType, aExtraInfoName, [], lSetting) or not TryStrToBool(lSetting, Result) then
    Result := Default;
end;

function THotelServicesAccessor.GetServiceSettingAsInteger(const aService, aServiceType,  aExtraInfoName: String; Default: integer): integer;
var
  lSetting: string;
begin

  if InternalGetSetting(aService, aServiceType, aExtraInfoName, [], lSetting) then
    Result := StrToIntDef(lSetting, Default)
  else
    Result := Default;
end;

function THotelServicesAccessor.GetServiceSettingAsString(const aService, aServiceType, aExtraInfoName: String;
  Default: string): string;
begin
  if not InternalGetSetting(aService, aServiceType, aExtraInfoName, [], Result) then
    Result := Default;
end;


function THotelServicesAccessor.THotelServicesKeys.ToString: string;
begin
  Result := Format('HotelId: %s, Service: %s, ServiceType: %s', [hotelId, Service, ServiceType]);
end;

end.
