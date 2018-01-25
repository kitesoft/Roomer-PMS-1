unit uFloatUtils;

interface

uses
  SysUtils
  ;


function SystemDecimalSeparator: char;
function SystemThousandsSeparator: char;
function LocalizedFloatToString(number: Double): String;
function LocalizedFloatValue(value: String; save: boolean = true): Double;
function RoundDecimals(value: Double; Decimals: Integer): Double;

/// <summary>
///   Construct a displayformat string based on the supplied formatSettings
/// </summary>
function DefaultCurrencyFormat(aFormatSettings: TFormatSettings): String;
/// <summary>
///   Construct a displayformat string based on the suppied formatSettings, using fixed decimal and thousandsseparator
///  This format can be used as a DisplayFormat setting in a TcxCurrencyEditProperties
/// </summary>
function cxEditPropertiesCurrencyFormat(aFormatSettings: TFormatSettings): string;


implementation

uses
    Math
  ;

function RoundDecimals(value: Double; Decimals: Integer): Double;
begin
  result := Power10( Round(Power10(value, Decimals)), -Decimals);
end;

function SystemDecimalSeparator: char;
begin
  Result := TFormatSettings.Create.DecimalSeparator;
end;

function SystemThousandsSeparator: char;
begin
  Result := TFormatSettings.Create.ThousandSeparator;
end;

function LocalizedFloatToString(number: Double): String;
begin
  result := Trim(StringReplace(StringReplace(FloatToStr(number), '.', SystemDecimalSeparator, [rfReplaceAll]), ',', SystemDecimalSeparator, [rfReplaceAll]));
end;

function LocalizedFloatValue(value: String; save: boolean = true): Double;
var
  S: String;
begin
  if not TryStrToFloat(Value, Result) then
    if not TryStrToFloat(StringReplace(value, '.', ',', [rfReplaceAll]), Result) then
      if not TryStrToFloat(StringReplace(value, '.', '·', [rfReplaceAll]), Result) then
        if not TryStrToFloat(StringReplace(value, '.', '''', [rfReplaceAll]), Result) then
          if not TryStrToFloat(StringReplace(value, ',', '.', [rfReplaceAll]), Result) then
            if not TryStrToFloat(StringReplace(value, ',', '·', [rfReplaceAll]), Result) then
              if not TryStrToFloat(StringReplace(value, ',', '''', [rfReplaceAll]), Result) then
                if not TryStrToFloat(StringReplace(value, '''', '.', [rfReplaceAll]), Result) then
                  if not TryStrToFloat(StringReplace(value, '''', '·', [rfReplaceAll]), Result) then
                    if not TryStrToFloat(StringReplace(value, '''', ',', [rfReplaceAll]), Result) then
                      if not TryStrToFloat(StringReplace(value, '·', '.', [rfReplaceAll]), Result) then
                        if not TryStrToFloat(StringReplace(value, '·', ',', [rfReplaceAll]), Result) then
                          if not TryStrToFloat(StringReplace(value, '·', '''', [rfReplaceAll]), Result) then
                          begin
                            S := Trim(StringReplace(StringReplace(value, '.', SystemDecimalSeparator, [rfReplaceAll]), ',', SystemDecimalSeparator,
                              [rfReplaceAll]));
                            if save then
                              result := StrToFloatDef(StringReplace(S, '.', SystemDecimalSeparator, [rfReplaceAll]), 0)
                            else
                              result := StrToFloat(StringReplace(S, '.', SystemDecimalSeparator, [rfReplaceAll]));
                          end;
end;


function AddCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  case CurrFormat of
    0: Result := Format('%s%s', [CurrSymbol, Value]);
    1: Result := Format('%s%s', [Value, CurrSymbol]);
    2: Result := Format('%s %s', [CurrSymbol, Value]);
    3: Result := Format('%s %s', [Value, CurrSymbol]);
  end;
end;

{   0 = '($1)'      4 = '(1$)'      8 = '-1 $'      12 = '$ -1'
    1 = '-$1'       5 = '-1$'       9 = '-$ 1'      13 = '1- $'
    2 = '$-1'       6 = '1-$'      10 = '1 $-'      14 = '($ 1)'
    3 = '$1-'       7 = '1$-'      11 = '$ 1-'      15 = '(1 $)'  }
function AddNegCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  case CurrFormat of
    0: Result := Format('(%s%s)', [CurrSymbol, Value]);
    1: Result := Format('-%s%s', [CurrSymbol, Value]);
    2: Result := Format('%s-%s', [CurrSymbol, Value]);
    3: Result := Format('%s%s-', [CurrSymbol, Value]);
    4: Result := Format('(%s%s)', [Value, CurrSymbol]);
    5: Result := Format('-%s%s', [Value, CurrSymbol]);
    6: Result := Format('%s-%s', [Value, CurrSymbol]);
    7: Result := Format('%s%s-', [Value, CurrSymbol]);
    8: Result := Format('-%s %s', [Value, CurrSymbol]);
    9: Result := Format('-%s %s', [CurrSymbol, Value]);
   10: Result := Format('%s %s-', [Value, CurrSymbol]);
   11: Result := Format('%s %s-', [CurrSymbol, Value]);
   12: Result := Format('%s %s', [CurrSymbol, Value]);
   13: Result := Format('%s -%s', [Value, CurrSymbol]);
   14: Result := Format('(%s- %s)', [CurrSymbol, Value]);
   15: Result := Format('(%s %s)', [Value, CurrSymbol]);
  end;
end;

function cxEditPropertiesCurrencyFormat(aFormatSettings: TFormatSettings): string;
begin
  aFormatSettings.DecimalSeparator := '.';
  aFormatSettings.ThousandSeparator := ',';
  Result := DefaultCurrencyFormat(aFormatSettings);
end;

function DefaultCurrencyFormat(aFormatSettings: TFormatSettings): String;
begin

 if aFormatSettings.CurrencyDecimals > 0 then
   Result := '0' + aFormatSettings.DecimalSeparator + StringOfChar('0', aFormatSettings.CurrencyDecimals)
 else
   Result := '0';

 Result := aFormatSettings.ThousandSeparator + Result;

 Result := AddCurrencySymbol(Result, aFormatSettings.CurrencyString, aFormatSettings.CurrencyFormat)
        + ';' + AddNegCurrencySymbol(Result, aFormatSettings.CurrencyString, aFormatSettings.NegCurrFormat)

end;


end.
