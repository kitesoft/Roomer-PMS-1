unit uRoomerHttpClient;

interface

uses
    Classes
  , SysUtils
  , ALWininetHttpClient
  , AlHttpCommon
  , ALHttpClient
  , ALStringlist
    ;

type
  THttpResultCode = record
    StatusCode: integer;
    StatusString: string;

    class operator Implicit(aInt: integer): THttpResultCode;
    class operator Implicit(aStr: String): THttpResultCode;
    class operator Implicit(aCode: THttpResultCode): integer;
  end;


  TRoomerHttpQueryparams = class(TStringlist)
  private
  public
    constructor Create; reintroduce;
    function AsUrltext: string;
  end;

  TRoomerHttpClient = class(TALWinInetHTTPClient)
  private
    FQueryParams: TRoomerHttpQueryParams;
    function GetContentType: string;
    procedure SetContentType(const Value: string);
    function GetAcceptEncoding: string;
    procedure SetAcceptEncoding(const Value: string);
  protected
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    procedure AddAuthenticationHeaders(const aHotel, aUser, aPassword, aAppName, aAppVersion, aExtraBuild: String);
    function DeleteWithStatus(const aURL: String; var aResponse: String): THttpResultCode;
    function GetWithStatus(const aUrl: String; var aResponse: String): THttpResultCode;
    function PostWithStatus(const aUrl:String; aPostDataStream: TStream): THttpResultCode;
    function PutWithStatus(const aURL: String; aPutDataStream: TStream; var aResponse: String): THttpResultCode;
    procedure Execute(const aRequestDataStream: TStream; aResponseContentStream: TStream; aResponseContentHeader: TALHTTPResponseHeader); override;

    property ContentType: string read GetContentType write SetContentType;
    property AcceptEncoding: string read GetAcceptEncoding write SetAcceptEncoding;
    property QueryParams: TRoomerHttpQueryparams read FQueryParams;
  end;

implementation

uses
  Windows
  , VCL.Forms
  , VCL.Controls
  ;

{ TRoomerHttpClient }
function RunningInMainThread: boolean;
begin
  Result := (GetCurrentThreadId() = MainThreadID);
end;


procedure TRoomerHttpClient.AddAuthenticationHeaders(const aHotel, aUser, aPassword, aAppName, aAppVersion, aExtraBuild: String);
begin
  with RequestHeader.CustomHeaders do
  begin
    Clear;
    Add(AnsiString(format('%s: %s', ['hotel', ahotel])));
    Add(AnsiString(format('%s: %s', ['Username', aUser])));
    Add(AnsiString(format('%s: %s', ['Password', aPassword])));
    Add(AnsiString(format('%s: %s', ['AppName', aAppName])));
    Add(AnsiString(format('%s: %s', ['AppVersion', aAppVersion])));
    Add(AnsiString(format('%s: %s', ['DatasetType', '0'])));
    Add(AnsiString(format('%s: %s', ['ExtraBuild', aExtraBuild])));
  end;

end;

constructor TRoomerHttpClient.Create(aOwner: TComponent);
begin
  inherited;
  SendTimeout := 900000;
  ReceiveTimeout := 900000;
  ConnectTimeout := 10000;
  AccessType := wHttpAt_Direct;
  InternetOptions := [whttpIo_IGNORE_CERT_CN_INVALID,
    whttpIo_IGNORE_CERT_DATE_INVALID, whttpIo_KEEP_CONNECTION,
    whttpIo_NO_CACHE_WRITE, whttpIo_NO_UI, whttpIo_PRAGMA_NOCACHE,
    whttpIo_RELOAD, whttpIo_RESYNCHRONIZE];

  FQueryParams := TRoomerHttpQueryParams.Create;
  FQueryParams.Delimiter := '&';
  FQueryParams.Duplicates := dupIgnore;
  FQueryParams.CaseSensitive := false;
end;

function TRoomerHttpClient.DeleteWithStatus(const aURL: String; var aResponse: String): THttpResultCode;
var
  lResponseContentStream: TStringStream;
  lResponseContentHeader: TALHTTPResponseHeader;
begin
  Result := -1;
  lResponseContentStream := nil;
  lResponseContentHeader := nil;
  try
    lResponseContentStream := TStringStream.Create('');
    lResponseContentHeader := TALHTTPResponseHeader.Create();
    try
      inherited Delete(AnsiString(aURL), lResponseContentStream, lResponseContentHeader);
      Result := lResponseContentHeader.StatusCode;
      aResponse := lResponseContentStream.DataString;
    except
      on E: EALHTTPClientException do
      begin
        if E.StatusCode > 0 then
          Result := E.StatusCode
      end
      else
        raise;
    end;
  finally
    lResponseContentStream.Free;
    lResponseContentHeader.Free;
  end;
end;

destructor TRoomerHttpClient.Destroy;
begin
  FQueryParams.Free;
  inherited;
end;

procedure TRoomerHttpClient.Execute(const aRequestDataStream: TStream; aResponseContentStream: TStream;
  aResponseContentHeader: TALHTTPResponseHeader);
var
  lOldCursor: TCursor;
begin
  lOldCursor := SCreen.cursor;

  if RunningInMainThread then
    Screen.Cursor := crHourGlass;

  try
    inherited;
  finally
    if RunningInMainThread then
      Screen.Cursor := lOldCursor;
  end;
end;

function TRoomerHttpClient.GetAcceptEncoding: string;
begin
  Result := String(RequestHeader.AcceptEncoding);
end;

function TRoomerHttpClient.GetContentType: string;
begin
  Result := string(RequestHeader.ContentType);
end;

function TRoomerHttpClient.GetWithStatus(const aUrl: String; var aResponse: String): THttpResultCode;
var
  lResponseContentStream: TStringStream;
  lResponseContentHeader: TALHTTPResponseHeader;
  lURL: Ansistring;
begin
  Result := -1;
  lResponseContentStream := nil;
  lResponseContentHeader := nil;
  try
    lResponseContentStream := TStringStream.Create('');
    lResponseContentHeader := TALHTTPResponseHeader.Create();
    lUrl := AnsiString(aUrl + FQueryParams.AsUrltext);
    try
      inherited Get(AnsiString(lURL), lResponseContentStream, lResponseContentHeader);
      Result := StrToInt(lResponseContentHeader.StatusCode);
      aResponse := lResponseContentStream.DataString;
    except
      on E: EALHTTPClientException do
      begin
        if E.StatusCode > 0 then
          Result := E.StatusCode
      end
      else
        raise;
    end;
  finally
    lResponseContentStream.Free;
    lResponseContentHeader.Free;
  end;
end;

function TRoomerHttpClient.PostWithStatus(const aUrl: String; aPostDataStream: TStream): THttpResultCode;
var
  lResponseContentHeader: TALHTTPResponseHeader;
  lURL: Ansistring;
begin
  Result := -1;
  lResponseContentHeader := TALHTTPResponseHeader.Create;
  try
    lUrl := AnsiString(aUrl + FQueryParams.AsUrltext);
    try
      inherited Post(AnsiString(lURL), aPostDataStream, lResponseContentHeader);
      Result := lResponseContentHeader.StatusCode;
    except
      on E: EALHTTPClientException do
      begin
        if E.StatusCode > 0 then
          Result := E.StatusCode
      end
      else
        raise;
    end;
  finally
    lResponseContentHeader.Free;
  end;
end;

function TRoomerHttpClient.PutWithStatus(const aURL: string; aPutDataStream: TStream; var aResponse: String): THttpResultCode;
var
  lResponseContentStream: TStringStream;
  lResponseContentHeader: TALHTTPResponseHeader;
  lURL: Ansistring;
begin
  Result := -1;
  lResponseContentStream := nil;
  lResponseContentHeader := nil;
  try
    lUrl := AnsiString(aUrl + FQueryParams.AsUrltext);
    lResponseContentStream := TStringStream.Create;
    lResponseContentHeader := TALHTTPResponseHeader.Create();
    try
      inherited Put(AnsiString(lURL), aPutDataStream, lResponseContentStream, lResponseContentHeader);
      Result := lResponseContentHeader.StatusCode;
      aResponse := lResponseContentStream.DataString;
    except
      on E: EALHTTPClientException do
      begin
        if E.StatusCode > 0 then
          Result := E.StatusCode
      end
      else
        raise;
    end;
  finally
    lResponseContentHeader.Free;
  end;
end;

procedure TRoomerHttpClient.SetAcceptEncoding(const Value: string);
begin
  RequestHeader.AcceptEncoding := AnsiString(Value);
end;

procedure TRoomerHttpClient.SetContentType(const Value: string);
begin
  RequestHeader.ContentType := AnsiString(value);
end;


{ TRoomerHttpQueryparams }

function TRoomerHttpQueryparams.AsUrltext: string;
begin
  Result := '';
  if Count > 0 then
    Result := '?' + DelimitedText;
end;

constructor TRoomerHttpQueryparams.Create;
begin
  inherited Create;
  Delimiter := '&';
end;

{ THttpResultCode }

class operator THttpResultCode.Implicit(aCode: THttpResultCode): integer;
begin
  Result := aCode.StatusCode;
end;

class operator THttpResultCode.Implicit(aInt: integer): THttpResultCode;
begin
  Result.StatusCode := aInt;
  result.StatusString := intToStr(aInt);
end;

class operator THttpResultCode.Implicit(aStr: String): THttpResultCode;
begin
  Result.StatusString := aStr;
  Result.StatusCode := StrToInt(aStr.Split( ['.'])[0]);
end;

end.
