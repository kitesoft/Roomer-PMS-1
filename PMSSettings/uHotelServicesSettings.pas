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


  THagstofaSettings = class(TBaseHotelServicesSettings)
  private const
    cHagstofaService = 'NATIONSTAT';
    cHagstofaServiceType = 'HAGSTOFAN';

    cHAGSTOFA_ID = 'HAGSTOFA_ID';
    cCIVIL_ID = 'CIVIL_ID';
    cLOCATION = 'LOCATION';
    cNAME = 'NAME';
    cEMAIL = 'EMAIL';
    cTELEPHONE = 'TELEPHONE';
    cPOSTCODE = 'POSTCODE';
    cHOMEPAGE = 'HOMEPAGE';
    cADDRESS01 = 'ADDRESS01';
    cADDRESS02 = 'ADDRESS02';
  private
    function GetAddress01: string;
    function GetAddress02: string;
    function GetCivilId: string;
    function GetEmail: string;
    function GetHagstofaEnabled: boolean;
    function GetHagstofaId: String;
    function GetHomepage: string;
    function GetLocation: string;
    function GetName: string;
    function GetPostcode: string;
    function GetTelephone: string;
    procedure SetAddress01(const Value: string);
    procedure SetAddress02(const Value: string);
    procedure SetCivilId(const Value: string);
    procedure SetEmail(const Value: string);
    procedure SetHagstofaEnabled(const Value: boolean);
    procedure SetHagstofaId(const Value: String);
    procedure SetHomepage(const Value: string);
    procedure SetLocation(const Value: string);
    procedure SetName(const Value: string);
    procedure SetPostcode(const Value: string);
    procedure SetTelephone(const Value: string);
  public
    property HagstofaEnabled: boolean read GetHagstofaEnabled write SetHagstofaEnabled;
    property HagstofaId: String read GetHagstofaId write SetHagstofaId;
    property CivilId: string read GetCivilId write SetCivilId;
    property Location: string read GetLocation write SetLocation;
    property Name: string read GetName write SetName;
    property Email: string read GetEmail write SetEmail;
    property Telephone: string read GetTelephone write SetTelephone;
    property Postcode: string read GetPostcode write SetPostcode;
    property Homepage: string read GetHomepage write SetHomepage;
    property Address01: string read GetAddress01 write SetAddress01;
    property Address02: string read GetAddress02 write SetAddress02;
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
    FHagstofaServiceSettings: THagstofaSettings;
  public
    constructor Create;
    destructor Destroy; override;
    property LifeCycleMailerSettings: TLifeCycleMailerSettings read FLifeCycleMailerSettings;
    property SmtpServiceSettings: TSmtpServiceSettings read FSmtpServiceSetting;
    property HagstofaServiceSettings: THagstofaSettings read FHagstofaServiceSettings;
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
  FHagstofaServiceSettings := THagstofaSettings.Create;
end;

destructor THotelServicesSettings.Destroy;
begin
  FLifeCycleMailerSettings.Free;
  FSmtpServiceSetting.Free;
  FHagstofaServiceSettings.Free;

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

{ THagstofaSettings }

function THagstofaSettings.GetAddress01: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cADDRESS01);
end;

function THagstofaSettings.GetAddress02: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cADDRESS02);
end;

function THagstofaSettings.GetCivilId: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cCIVIL_ID);
end;

function THagstofaSettings.GetEmail: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cEMAIL);
end;

function THagstofaSettings.GetHagstofaEnabled: boolean;
begin
  Result := FHotelServicesAccessor.GetServiceEnabled(cHagstofaService, cHagstofaServiceType);
end;

function THagstofaSettings.GetHagstofaId: String;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cHAGSTOFA_ID);
end;

function THagstofaSettings.GetHomepage: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cHOMEPAGE);
end;

function THagstofaSettings.GetLocation: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cLOCATION);
end;

function THagstofaSettings.GetName: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cNAME);
end;

function THagstofaSettings.GetPostcode: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cPOSTCODE);
end;

function THagstofaSettings.GetTelephone: string;
begin
  Result := FHotelServicesAccessor.GetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cTELEPHONE);
end;

procedure THagstofaSettings.SetAddress01(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cADDRESS01, value);
end;

procedure THagstofaSettings.SetAddress02(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cADDRESS02, value);
end;

procedure THagstofaSettings.SetCivilId(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cCIVIL_ID, value);
end;

procedure THagstofaSettings.SetEmail(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cEMAIL, value);
end;

procedure THagstofaSettings.SetHagstofaEnabled(const Value: boolean);
begin
  FHotelServicesAccessor.SetServiceEnabled(cHagstofaService, cHagstofaServiceType, Value);
end;

procedure THagstofaSettings.SetHagstofaId(const Value: String);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cHAGSTOFA_ID, value);
end;

procedure THagstofaSettings.SetHomepage(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cHOMEPAGE, value);
end;

procedure THagstofaSettings.SetLocation(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cLOCATION, value);
end;

procedure THagstofaSettings.SetName(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cNAME, value);
end;

procedure THagstofaSettings.SetPostcode(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cPOSTCODE, value);
end;

procedure THagstofaSettings.SetTelephone(const Value: string);
begin
  FHotelServicesAccessor.SetServiceSettingAsString(cHagstofaService, cHagstofaServiceType, cTELEPHONE, value);
end;

end.
