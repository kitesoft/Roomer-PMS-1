unit uSmtpService;

interface

type
  TSmtpService = class
  private
    FSmtpPort: Integer;
    FSmtpFromEmail: String;
    FSmtpAuthenticate: Boolean;
    FSmtpPassword: String;
    FSmtpTLS: Boolean;
    FSmtpUsername: String;
    FSmtpServer: String;
    FSmtpServiceActive: Boolean;

  private
    DataLoaded : Boolean;
    procedure LoadData;
    function buildExtraInfo: String;
  public
    constructor Create;
    destructor Destroy;

    procedure Save;

    property SmtpServiceActive : Boolean read FSmtpServiceActive write FSmtpServiceActive;
    property SmtpServer : String read FSmtpServer write FSmtpServer;
    property SmtpFromEmail : String read FSmtpFromEmail write FSmtpFromEmail;
    property SmtpPort : Integer read FSmtpPort write FSmtpPort;
    property SmtpUsername : String read FSmtpUsername write FSmtpUsername;
    property SmtpAuthenticate : Boolean read FSmtpAuthenticate write FSmtpAuthenticate;
    property SmtpPassword : String read FSmtpPassword write FSmtpPassword;
    property SmtpTLS : Boolean read FSmtpTLS write FSmtpTLS;
  end;

implementation

uses ud,
     cmpRoomerDataset,
     hData,
     SysUtils,
     Classes,
     uUtils
     ;


const
    SMTP_PROPERTIES : Array[0..7] Of String =
    (
       'SMTP_SERVICE_ACTIVE',
       'SMTP_SERVER',
       'SMTP_PORT',
       'SMTP_EMAIL_ADDRESS',
       'SMTP_SSL_TLS',
       'SMTP_AUTHENTICATE',
       'SMTP_USERNAME',
       'SMTP_PASSWORD'
    );

{ TSmtpService }

constructor TSmtpService.Create;
begin
  DataLoaded := False;

  FSmtpPort := 25;
  FSmtpFromEmail := '';
  FSmtpAuthenticate := False;
  FSmtpPassword := '';
  FSmtpTLS := False;
  FSmtpUsername := '';
  FSmtpServer := '';
  FSmtpServiceActive := False;
  LoadData;
end;

destructor TSmtpService.Destroy;
begin
  //
end;

function IndexOfProperty(_property : String) : Integer;
var i : Integer;
begin
  result := -1;
  for i := LOW(SMTP_PROPERTIES) to HIGH(SMTP_PROPERTIES) do
    if SMTP_PROPERTIES[i] = _property then
    begin
      result := i;
      break;
    end;
end;

procedure TSmtpService.LoadData;
var rSet : TRoomerDataSet;
    s, sql : String;
    extraInfo : TStringList;
    values : TStringList;
begin
  rSet := CreateNewDataSet;
  try
    sql := format('SELECT extraInfo FROM home100.hotelservices WHERE hotelId = ''%s'' AND service = ''EMAIL'' AND serviceType = ''SMTP_SETTINGS''', [d.roomerMainDataSet.hotelId]);
    rSet_bySQL(rSet, sql);
    rSet.First;
    if NOT rSet.Eof then
    begin
      DataLoaded := True;
      extraInfo := SplitStringToTStrings(';', rSet['extraInfo']);
      try
        for s IN extraInfo do
        begin
          values := SplitStringToTStrings('=', s);
          try
            case IndexOfProperty(values[0]) of
              0 : begin // SMTP_SERVICE_ACTIVE
                    FSmtpServiceActive := values[1] = 'TRUE';
                  end;
              1 : begin // SMTP_SERVER
                    FSmtpServer := values[1];
                  end;
              2 : begin // SMTP_PORT
                    FSmtpPort := StrToInt(values[1]);
                  end;
              3 : begin // SMTP_EMAIL_ADDRESS
                    FSmtpFromEmail := values[1];
                  end;
              4 : begin // SMTP_SSL_TLS
                    FSmtpTLS := values[1] = 'TRUE';
                  end;
              5 : begin // SMTP_AUTHENTICATE
                    FSmtpAuthenticate := values[1] = 'TRUE';
                  end;
              6 : begin // SMTP_USERNAME
                    FSmtpUsername := values[1];
                  end;
              7 : begin // SMTP_PASSWORD
                    FSmtpPassword := values[1];
                  end;
              end;

          finally
            values.Free;
          end;
        end;
      finally
        extraInfo.Free;
      end;
    end;
  finally
    rSet.Free;
  end;
end;

function TSmtpService.buildExtraInfo : String;
begin
  result :=
    SMTP_PROPERTIES[0] + '=' + IIF(FSmtpServiceActive, 'TRUE', 'FALSE') + ';' +
    SMTP_PROPERTIES[1] + '=' + FSmtpServer + ';' +
    SMTP_PROPERTIES[2] + '=' + IntToStr(FSmtpPort) + ';' +
    SMTP_PROPERTIES[3] + '=' + FSmtpFromEmail + ';' +
    SMTP_PROPERTIES[4] + '=' + IIF(FSmtpTLS, 'TRUE', 'FALSE') + ';' +
    SMTP_PROPERTIES[5] + '=' + IIF(FSmtpAuthenticate, 'TRUE', 'FALSE') + ';' +
    SMTP_PROPERTIES[6] + '=' + FSmtpUsername + ';' +
    SMTP_PROPERTIES[7] + '=' + FSmtpPassword;
  result := replaceString(result, '''', '\''');
end;

procedure TSmtpService.Save;
var s, sql : String;
begin
  if DataLoaded then
    sql := format('UPDATE home100.hotelservices ' +
                  'SET extraInfo=''%s'' ' +
                  'WHERE hotelId = ''%s'' AND service = ''EMAIL'' AND serviceType = ''SMTP_SETTINGS''', [buildExtraInfo, d.roomerMainDataSet.hotelId])
  else
    sql := format('INSERT INTO home100.hotelservices (active, hotelId, service, extraInfo, serviceType) ' +
                  'values(1, ''%s'', ''%s'', ''%s'', ''%s'')',
                  [d.roomerMainDataSet.hotelId, 'EMAIL', buildExtraInfo, 'SMTP_SETTINGS']);
  d.roomerMainDataSet.DoCommand(sql);
end;

end.
