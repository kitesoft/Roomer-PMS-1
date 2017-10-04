unit uHotelServicesSettings;

interface

uses
  cmpRoomerDataset
  , SysUtils
  , uHotelServicesAccessor
  ;

type

  EHotelServicesSettingIncompleteKey = class(Exception);

  /// <summary>
  ///   Base object to access a sepcific type of settings in HotelServices
  ///  Future improvements:
  ///   Optimize db access by storing last retrieved values and only updating when needed
  ///   pref. by a RTTI based retrieve()
  /// </summary>
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


  TSmtpServiceSettings = class (TBaseHotelServicesSettings)
  private const
    cSmtpService = 'EMAIL';
    cSmtpServiceType = 'SMTP_SETTINGS';
    cSmtpServer = 'SMTP_SERVER';
    cSmtpPort = 'SMTP_PORT';
    cSmtpPortDefault = 25;
    cSmtpEmailAddress = 'SMTP_EMAIL_ADDRESS';
    cSmtpSSLTLS = 'SMTP_SSL_TLS';
    cSmtpSTARTTLS = 'SMTP_STARTTLS';
    cSmtpAuthenticate = 'SMTP_AUTHENTICATE';
    cSmtpUsername = 'SMTP_USERNAME';
    cSmtpPassword = 'SMTP_PASSWORD';
    cSmtpTransportProtocol = 'SMTP_TRANSPORT_PROTOCOL';
  private
    function GetSmtpAuthenticate: Boolean;
    function GetSmtpFromEmail: String;
    function GetSmtpPassword: String;
    function GetSmtpPort: Integer;
    function GetSmtpServer: String;
    function GetSmtpServiceActive: Boolean;
    function GetSmtpSSLTLS: Boolean;
    function GetSmtpUsername: String;
    procedure SetSmtpAuthenticate(const Value: Boolean);
    procedure SetSmtpFromEmail(const Value: String);
    procedure SetSmtpPassword(const Value: String);
    procedure SetSmtpPort(const Value: Integer);
    procedure SetSmtpServer(const Value: String);
    procedure SetSmtpServiceActive(const Value: Boolean);
    procedure SetSmtpSSLTLS(const Value: Boolean);
    procedure SetSmtpUsername(const Value: String);
    function GetSmtpStartTLS: Boolean;
    procedure SetSmtpStartTLS(const Value: Boolean);
  public
    property SmtpServiceActive : Boolean read GetSmtpServiceActive write SetSmtpServiceActive;
    property SmtpServer : String read GetSmtpServer write SetSmtpServer;
    property SmtpFromEmail : String read GetSmtpFromEmail write SetSmtpFromEmail;
    property SmtpPort : Integer read GetSmtpPort write SetSmtpPort;
    property SmtpUsername : String read GetSmtpUsername write SetSmtpUsername;
    property SmtpAuthenticate : Boolean read GetSmtpAuthenticate write SetSmtpAuthenticate;
    property SmtpPassword : String read GetSmtpPassword write SetSmtpPassword;
    property SmtpSSLTLS : Boolean read GetSmtpSSLTLS write SetSmtpSSLTLS;
    property SmtpStartTLS: Boolean read GetSmtpStartTLS write SetSmtpStartTLS;
 end;


  THotelServicesSettings = class
  private
    FLifeCycleMailerSettings: TLifeCycleMailerSettings;
    FSmtpServiceSetting: TSmtpServiceSettings;
  public
    constructor Create;
    destructor Destroy; override;
    property LifeCycleMailerSettings: TLifeCycleMailerSettings read FLifeCycleMailerSettings;
    property SmtpServiceSettings: TSmtpServiceSettings read FSmtpServiceSetting;
  end;



implementation

uses
  hData
  , Classes
  , uSQLUtils
  , uD
  , uUtils;


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
  FSmtpServiceSetting := TSmtpServiceSettings.Create;
end;

destructor THotelServicesSettings.Destroy;
begin
  FLifeCycleMailerSettings.Free;
  FSmtpServiceSetting.Free;
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


{ TSmtpServiceSettings }

function TSmtpServiceSettings.GetSmtpAuthenticate: Boolean;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpAuthenticate, False);
end;

function TSmtpServiceSettings.GetSmtpFromEmail: String;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpEmailAddress);
end;

function TSmtpServiceSettings.GetSmtpPassword: String;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpPassword);
end;

function TSmtpServiceSettings.GetSmtpPort: Integer;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsInteger(cSmtpService, cSmtpServiceType, cSmtpPort, cSmtpPortDefault);
end;

function TSmtpServiceSettings.GetSmtpServer: String;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpServer);
end;

function TSmtpServiceSettings.GetSmtpServiceActive: Boolean;
begin
  Result := FHotelServicesAccessor.GetServiceEnabled(cSmtpService, cSmtpServiceType);
end;

function TSmtpServiceSettings.GetSmtpSSLTLS: Boolean;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpSSLTLS);
end;

function TSmtpServiceSettings.GetSmtpStartTLS: Boolean;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpSTARTTLS);
end;

function TSmtpServiceSettings.GetSmtpUsername: String;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpUsername);
end;

procedure TSmtpServiceSettings.SetSmtpAuthenticate(const Value: Boolean);
begin
  FHotelServicesAccessor.SetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpAuthenticate, value);
end;

procedure TSmtpServiceSettings.SetSmtpFromEmail(const Value: String);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpEmailAddress, Value);
end;

procedure TSmtpServiceSettings.SetSmtpPassword(const Value: String);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpPassword, Value);
end;

procedure TSmtpServiceSettings.SetSmtpPort(const Value: Integer);
begin
  FHotelServicesAccessor.SetServiceSettingAsInteger(cSmtpService, cSmtpServiceType, cSmtpPort, Value);
end;

procedure TSmtpServiceSettings.SetSmtpServer(const Value: String);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpServer, Value);
end;

procedure TSmtpServiceSettings.SetSmtpServiceActive(const Value: Boolean);
begin
  FHotelServicesAccessor.SetServiceEnabled(cSmtpService, cSmtpServiceType, Value);
end;

procedure TSmtpServiceSettings.SetSmtpSSLTLS(const Value: Boolean);
begin
  FHotelServicesAccessor.SetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpSSLTLS, Value);
end;

procedure TSmtpServiceSettings.SetSmtpStartTLS(const Value: Boolean);
begin
  FHotelServicesAccessor.SetServiceSettingAsBoolean(cSmtpService, cSmtpServiceType, cSmtpSTARTTLS, Value);
end;

procedure TSmtpServiceSettings.SetSmtpUsername(const Value: String);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cSmtpService, cSmtpServiceType, cSmtpUsername, Value);
end;

end.
