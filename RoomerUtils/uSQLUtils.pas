unit uSQLUtils;

interface

uses
  SysUtils
  , uStringUtils
  ;


// Conversion of different datatypes to strings that can be used in SQL statements

function _db(const aString : string)    : string; overload;
function _db(const aInt  : integer)     : string; overload;
function _db(const aBool : boolean)     : string; overload;
function _db(const aFloat : Extended)   : string; overload;
function _db(const aFloat : double)     : string; overload;
function _db(const aDate: TDateTime; aQuoted: boolean = true)  : string; overload;
function _db(const aDate: TDate; aQuoted: boolean = true)     : string; overload;
function _db(const aTime: TTime)        : string; overload;
function _db(const aTimeStamp: TTimeStamp): string; overload;


/// <summary>
///   Format a float for use in SQL statement
/// </summary>
function FloatToSQL(aValue: double): string; overload;
/// <summary>
///   Format a float, rounded at aDecimals for use in SQL statement
/// </summary>
function FloatToSQL(aValue: double; aDecimals: integer): string; overload;
/// <summary>
///   Convert a SQl string to a float
/// </summary>
function SQLToFloat(const aStringValue: string; aDefault: extended = 0.00): extended;

function SQLToDate(const aStringvalue: string): TDate;
function SQLToDateTime(const aStringvalue: string): TDateTime;

var
  // Fixed predefined formatsettings to be used when formatting from or to SQL strings
  SQLFormatSettings: TFormatSettings;


implementation

uses
  uFloatUtils
  ;

const
  cSingleQuote = #39;
  cEscapedQuote = #92#39;

/// <summary>
///   Surround string with single quotes, take escaped quotes at the end of the string into account
/// </summary>
function RoomerQuotedString(s : String) : String;
begin
  if s = '' then
    s := ''''''
  else
  begin
    if not s.StartsWith(cSingleQuote) then
       s := cSingleQuote + s;
    if not s.EndsWith(cSingleQuote) or s.EndsWith(cEscapedQuote) then
       s := s + cSingleQuote;
  end;
  result := s;
end;

function _db(const aString : string)   : string;
begin
  result := RoomerQuotedString(StringReplace(aString, #39, '\' + #39, [rfReplaceAll]));
end;

function _db(const aInt  : integer)    : string;
begin
  result := inttostr(aInt);
end;

function _db(const aBool : boolean)    : string;
begin
  result := BoolToString_0_1(aBool);
  if result = '-1' then result := '1';
end;

function _db(const aFloat : Extended)  : string;
begin
  Result := FloatToSQL(aFloat);
end;

function _db(const aFloat : double)  : string;
begin
  Result := FloatToSQL(aFloat);
end;

function _db(const aDate : TDate; aQuoted: boolean = true)  : string;
begin
  // Shortdate
  Result := DateToStr(aDate, SQLFormatSettings);
  if aQuoted then
    Result := quotedstr(Result);
end;

function _db(const aDate : TDateTime; aQuoted: boolean)  : string;
begin
  //ShortDate + Shorttime
//  Result := DateTimeToStr(aDate, SQLFormatSettings);
//  DateTimeToString(result, SQLFormatSettings.ShortDateFormat + ' ' + SQLFormatSettings.ShortTimeFormat, aDate, SQLFormatSettings);
  Result := DateToStr(aDate, SQLFormatSettings);
  if aQuoted then
    Result := quotedstr(Result);
end;

function _db(const aTime: TTime): string;
var
  S : string;
begin
  // Shorttime
  //s := TimeToStr(aTime, SQLFormatSettings);
  DateTimeToString(s, SQLFormatSettings.ShortTimeFormat, aTime, SQLFormatSettings);
  if s = '00:00' then s := '';
  Result := quotedstr(S);
end;

function _db(const aTimeStamp: TTimeStamp): string; overload;
var
  S : string;
begin
  // Longtime
  s := TimeToStr(TimeStampToDateTime(aTimeStamp), SQLFormatSettings);
  if s.StartsWith('00:00') then s := '';
  Result := quotedstr(S);
end;

function FloatToSQL(aValue: double): string;
begin
  Result := FloatToStr(aValue, SQLFormatSettings);
end;

function FloatToSQL(aValue: double; aDecimals: integer): string;
begin
  Result := FloatToSQL(RoundDecimals(aValue, aDecimals));
end;

function SQLToFloat(const aStringValue: string; aDefault: extended = 0.00): extended;
begin
  Result := StrToFloatDef(aStringValue, aDefault, SQLFormatSettings);
end;

function SQLToDate(const aStringvalue: string): TDate;
begin
  Result := StrToDate(aStringValue, SQLFormatSettings);
end;

function SQLToDateTime(const aStringvalue: string): TDateTime;
begin
  Result := StrToDateTime(aStringValue, SQLFormatSettings);
end;



procedure InitSQLFormatSettings;
begin
  with SQLFormatSettings do
  begin
    DecimalSeparator := '.';
    ThousandSeparator := ',';
    DateSeparator := '-';
    TimeSeparator := ':';
    ShortDateFormat := 'yyyy-mm-dd';
    ShortTimeFormat := 'HH:mm';
    LongTimeFormat :=  'HH:mm:ss.zzz';
  end;
end;

initialization
  initSQLFormatSettings;

end.
