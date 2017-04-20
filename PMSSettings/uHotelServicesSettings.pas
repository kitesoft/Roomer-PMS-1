unit uHotelServicesSettings;

interface

uses
  cmpRoomerDataset
  , SysUtils
  ;

type

  EHotelServicesSettingIncompleteKey = class(Exception);
  EHotelServicesSettingCreateServiceException = class(Exception);

  THotelServicesSettingsGetSetOption = (psoExceptionOnNotFound);
  THotelServicesSettingsGetSetOptions = set of THotelServicesSettingsGetSetOption;


  /// <summary>
  ///   Settings accessor for settings stored in home100.HOTELSERVICES.
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

    procedure SetServiceEnabled(const aService, aServiceType: string; aEnabled: boolean);
    procedure SetServiceSettingAsInteger(const aService, aServiceType, aExtraInfoName: String; aNewValue: integer);
    procedure SetServiceSettingAsString(const aService, aServiceType, aExtraInfoName: String; const aNewValue: String);
  end;


  TBaseHotelServicesSettings = class abstract(TObject)
  protected
    FHotelServicesAccessor: THotelServicesAccessor;
  public
    constructor Create;
    destructor Destroy; override;
  end;

  TPreArrivalLCMailSettings = class(TBaseHotelServicesSettings)
  private const
    cLifeCycleMailerService = 'LCMAIL';
    cPreArrivalServiceType = 'PRE_ARRIVAL';

    cPReArrivalHoursBefore = 'HOURS_BEFORE';
    cPreArrivalMaiLFrom = 'from';
    cPreArrivalCCAddress = 'ccAddress';
  private
    procedure SetHoursBefore(const Value: integer);
    procedure SetPreArrivalMailerEnabled(const Value: boolean);
    function GetHoursBefore: integer;
    function GetPreArrivalMailerEnabled: boolean;
    function GetMailFromAddress: string;
    procedure SetMailFromAddress(const Value: string);
    function GetCCMailAddress: string;
    procedure SetCCMailAddress(const Value: string);
  public
    property PreArrivalMailerEnabled: boolean read GetPreArrivalMailerEnabled write SetPreArrivalMailerEnabled;
    property HoursBefore: integer read GetHoursBefore write SetHoursBefore;
    property MailFromAddress: string read GetMailFromAddress write SetMailFromAddress;
    property CCMailAddress: string read GetCCMailAddress write SetCCMailAddress;
  end;

  TPostDepartureLCMailSettings = class(TBaseHotelServicesSettings)
  private const
    cLifeCycleMailerService = 'LCMAIL';
    cPostDepartureServiceType = 'POST_DEPARTURE';

    cPostDepartureHoursAfter = 'HOURS_AFTER';
    cpostDepartureMaiLFrom = 'from';
    cPostDeparturenCCAddress = 'ccAddress';

  private
    procedure SetHoursAfter(const Value: integer);
    procedure SetPostDepartureMailerEnabled(const Value: boolean);
    function GetHoursAfter: integer;
    function GetPostDepartureMailerEnabled: boolean;
    function GetCCMailAddress: string;
    function GetMailFromAddress: string;
    procedure SetCCMailAddress(const Value: string);
    procedure SetMailFromAddress(const Value: string);
  public
    property PostDepartureMailerEnabled: boolean read GetPostDepartureMailerEnabled write SetPostDepartureMailerEnabled;
    property HoursAfter: integer read GetHoursAfter write SetHoursAfter;
    property MailFromAddress: string read GetMailFromAddress write SetMailFromAddress;
    property CCMailAddress: string read GetCCMailAddress write SetCCMailAddress;

  end;

  TLifeCycleMailerSettings = class
  private
    FPostDepartureMailSettings: TPostDepartureLCMailSettings;
    FPreArrivalMailSetttings: TPreArrivalLCMailSettings;
  public
    constructor Create;
    destructor Destroy; override;
    property PreArrivalMailSetttings: TPreArrivalLCMailSettings read FPreArrivalMailSetttings ;
    property PostDepartureMailSettings: TPostDepartureLCMailSettings read FPostDepartureMailSettings ;
  end;


  THotelServicesSettings = class
  private
    FLifeCycleMailerSettings: TLifeCycleMailerSettings;
  public
    constructor Create;
    destructor Destroy; override;
    property LifeCycleMailerSettings: TLifeCycleMailerSettings read FLifeCycleMailerSettings;
  end;



implementation

uses
  hData
  , Classes
  , uSQLUtils
  , uD
  , uUtils;


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
    raise EHotelServicesSettingCreateServiceException.CreateFmt('Failed to create hotelservice [%s]', [aKey.ToString]);

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

{ TLifeCycleMailerSettings }


{ TPreArrivalLCMailSettings }

function TPreArrivalLCMailSettings.GetCCMailAddress: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cLifeCycleMailerService, cPreArrivalServiceType, cPreArrivalCCAddress);
end;

function TPreArrivalLCMailSettings.GetMailFromAddress: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cLifeCycleMailerService, cPreArrivalServiceType, cPReArrivalMailFrom);
end;

function TPreArrivalLCMailSettings.GetHoursBefore: integer;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsInteger(cLifeCycleMailerService, cPreArrivalServiceType, cPReArrivalHoursBefore, 24);
end;

function TPreArrivalLCMailSettings.GetPreArrivalMailerEnabled: boolean;
begin
  Result := FHotelServicesAccessor.GetServiceEnabled(cLifeCycleMailerService, cPreArrivalServiceType);
end;

procedure TPreArrivalLCMailSettings.SetCCMailAddress(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cLifeCycleMailerService, cPreArrivalServiceType, cPreArrivalCCAddress, Value);
end;

procedure TPreArrivalLCMailSettings.SetMailFromAddress(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cLifeCycleMailerService, cPreArrivalServiceType, cPreArrivalMaiLFrom, Value);
end;

procedure TPreArrivalLCMailSettings.SetHoursBefore(const Value: integer);
begin
  FHotelServicesAccessor.SetServiceSettingAsInteger(cLifeCycleMailerService, cPreArrivalServiceType, cPReArrivalHoursBefore, Value);
end;

procedure TPreArrivalLCMailSettings.SetPreArrivalMailerEnabled(const Value: boolean);
begin
  FHotelServicesAccessor.SetServiceEnabled(cLifeCycleMailerService, cPreArrivalServiceType, Value);
end;

{ TPostDepartureLCMailSettings }

function TPostDepartureLCMailSettings.GetCCMailAddress: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cLifeCycleMailerService, cPostDepartureServiceType, cPostDeparturenCCAddress);
end;

function TPostDepartureLCMailSettings.GetHoursAfter: integer;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsInteger(cLifeCycleMailerService, cPostDepartureServiceType, cPostDepartureHoursAfter, 24);
end;

function TPostDepartureLCMailSettings.GetMailFromAddress: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cLifeCycleMailerService, cPostDepartureServiceType, cpostDepartureMaiLFrom);
end;

function TPostDepartureLCMailSettings.GetPostDepartureMailerEnabled: boolean;
begin
  Result := FHotelServicesAccessor.GetServiceEnabled(cLifeCycleMailerService, cPostDepartureServiceType);
end;

procedure TPostDepartureLCMailSettings.SetCCMailAddress(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cLifeCycleMailerService, cPostDepartureServiceType, cPostDeparturenCCAddress, Value);
end;

procedure TPostDepartureLCMailSettings.SetHoursAfter(const Value: integer);
begin
  FHotelServicesAccessor.SetServiceSettingAsInteger(cLifeCycleMailerService, cPostDepartureServiceType, cPostDepartureHoursAfter, Value);
end;

procedure TPostDepartureLCMailSettings.SetMailFromAddress(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cLifeCycleMailerService, cPostDepartureServiceType, cpostDepartureMaiLFrom, Value);
end;

procedure TPostDepartureLCMailSettings.SetPostDepartureMailerEnabled(const Value: boolean);
begin
  FHotelServicesAccessor.SetServiceEnabled(cLifeCycleMailerService, cPostDepartureServiceType, Value);
end;

{ THotelServicesSettings }

constructor TBaseHotelServicesSettings.Create;
begin
  FHotelServicesAccessor := THotelServicesAccessor.Create;
end;

destructor TBaseHotelServicesSettings.Destroy;
begin
  FHotelServicesAccessor.Free;
  inherited;
end;

{ THotelServicesSettings }

constructor THotelServicesSettings.Create;
begin
  FLifeCycleMailerSettings := TLifeCycleMailerSettings.Create;
end;

destructor THotelServicesSettings.Destroy;
begin
  FLifeCycleMailerSettings.Free;
  inherited;
end;

{ TLifeCycleMailerSettings }

constructor TLifeCycleMailerSettings.Create;
begin
  FPostDepartureMailSettings := TPostDepartureLCMailSettings.Create;
  FPreArrivalMailSetttings := TPreArrivalLCMailSettings.Create;
end;

destructor TLifeCycleMailerSettings.Destroy;
begin
  FPostDepartureMailSettings.Free;
  FPreArrivalMailSetttings.Free;
  inherited;
end;

{ THotelServicesAccessor.THotelServicesKeys }

function THotelServicesAccessor.THotelServicesKeys.ToString: string;
begin
  Result := Format('HotelId: %s, Service: %s, ServiceType: %s', [hotelId, Service, ServiceType]);
end;

end.
