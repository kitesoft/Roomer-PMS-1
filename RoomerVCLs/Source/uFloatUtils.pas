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



end.
