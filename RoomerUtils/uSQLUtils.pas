unit uSQLUtils;

interface

uses
  SysUtils
  ;

function FloatToSQL(aValue: double; aDecimals: integer = 0): string;
function SQLToFloat(const aStringValue: string; aDefault: extended = 0.00): extended;

var
  // Fixed predefined formatsettings to be used when formatting from or to SQL strings
  SQLFormatSettings: TFormatSettings;


implementation

uses
  uFloatUtils
  ;


function FloatToSQL(aValue: double; aDecimals: integer = 0): string;
begin
  Result := FloatToStr(RoundDecimals(aValue, aDecimals), SQLFormatSettings);
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
