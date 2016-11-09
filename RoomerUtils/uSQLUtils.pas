unit uSQLUtils;

interface

uses
  SysUtils
  , uStringUtils
  ;


// Conversion of different datatypes to strings that can be used in SQL statements
//   All resulting strings are surrounded by single quotes and other quotes are escaped with a \

function _db(const aString : string)    : string; overload;
function _db(const aString : char)      : string; overload;
function _db(const aInt  : integer)     : string; overload;
function _db(const aBool : boolean)     : string; overload;
function _db(const aFloat : Extended)   : string; overload;
function _db(const aFloat : double)     : string; overload;
function _db(const aDate  : TDateTime)  : string; overload;
function _db(const aDate : TDate)       : string; overload;
function _db(const aTime: TTime)        : string; overload;


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

var
  // Fixed predefined formatsettings to be used when formatting from or to SQL strings
  SQLFormatSettings: TFormatSettings;


implementation

uses
  uFloatUtils
  , _Glob
  ;

const
  cSingleQuote = #39;
  cEscapedQuote = #92#39;

/// <summary>
///   Surround string with single quotes
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

function _db(const aString : char)   : string;
var s : String;
begin
  s := aString;
  result := RoomerQuotedString(StringReplace(s, #39, '\' + #39, [rfReplaceAll]));
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
var
  s : string;
begin
  s:=floatToStr(aFloat);
  result := _CommaToDot(S);
end;

function _db(const aFloat : double)  : string;
var
  s : string;
begin
  s:=floatToStr(aFloat);
  result := _CommaToDot(S);
end;

function _db(const aDate : TDate)  : string;
var
  S : string;
begin
  datetimetostring(S, 'yyyy-mm-dd', aDate);
  Result := quotedstr(S);
end;


function _db(const aDate : TDateTime)  : string;
var
  S : string;
begin
  datetimetostring(S, 'yyyy-mm-dd', aDate);
  Result := quotedstr(S);
end;

function _db(const aTime: TTime): string;
var
  S : string;
begin
  datetimetostring(S, 'hh:MM', aTime);
  if s = '00:00' then s := '';
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
  end;
end;

initialization
  initSQLFormatSettings;

end.
