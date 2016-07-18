unit uDateSelPreset;

interface

uses
  Classes
  ;

type
  {$ScopedEnums ON}
  TDateSelPreset = (Today, Tomorrow, Yesterday, ThisWeek, ThisMonth, ThisYear, Manual);
  TDateSelPresetHelper = record helper for TDateSelPreset
  protected
    /// <summary>
    ///   Constants as they are stored in the translation dictionarytable, to be used for displaying translated texts
    /// </summary>
    const cTranslateConstants: array[TDateSelPreset] of string = ( 'shDateSelPreset_Today',
                                                        'shDateSelPreset_Tomorrow',
                                                        'shDateSelPreset_Yesterday',
                                                        'shDateSelPreset_ThisWeek',
                                                        'shDateSelPreset_ThisMonth',
                                                        'shDateSelPreset_ThisYear',
                                                        'shDateSelPreset_Manual'
                                                      );
  public
    class function FromItemIndex(idx: integer): TDateSelPreset; static;
    class procedure SetStrings(aStrings: TStrings); static;
    /// <summary>
    ///   Gets the enum-text for the current TDateSelPreset
    /// </summary>
    function AsString: string;
    /// <summary>
    ///   Gets the translated text from the dictionarytable for the current TDateSelPreset
    /// </summary>
    function AsTranslatedString: string;
  end;

implementation

uses
    uRoomerLanguage
  , DateUtils
  , SysUtils
  , uDateTimeHelper
  , TypInfo
  ;

{ TDateSelPresetHelper }

function TDateSelPresetHelper.AsTranslatedString: string;
begin
  Result := RoomerLanguage.GetTranslatedText(cTranslateConstants[Self]);
end;

class function TDateSelPresetHelper.FromItemIndex(idx: integer): TDateSelPreset;
begin
  Result := TDateSelPreset(idx);
end;

class procedure TDateSelPresetHelper.SetStrings(aStrings: TStrings);
var
  d: TDateSelPreset;
begin
  aStrings.BeginUpdate;
  try
    aStrings.Clear;
    for d := low(d) to high(d) do
      aStrings.Insert(ord(d), d.AsTranslatedString);
  finally
    aStrings.EndUpdate;
  end;
end;

function TDateSelPresetHelper.AsString: string;
begin
  Result := GetEnumName(TypeInfo(TDateSelPreset), Ord(Self));
end;

procedure AddRoomerLanguageConstants;
var
  d: TDateSelPreset;
begin
  for d := low(d) to high(d) do
    ConstantsDictionary.Add(d.cTranslateConstants[d], d.AsString);
end;

initialization
  AddRoomerLanguageConstants;


end.
