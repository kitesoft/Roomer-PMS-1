unit uReleaseNotes;

interface

type
  TReleaseNotesViewer = class
  private
    class function GetReleaseNotesLink(aLanguageId: Integer): string; static;
  public
    class procedure OpenReleaseNotes(languageId: integer); static;
  end;


implementation

uses
  ShellApi
  , PrjConst
  , uRoomerLanguage
  , SysUtils
  , Windows
  ;

{ TReleaseNotesViewer }

class function TReleaseNotesViewer.GetReleaseNotesLink(aLanguageId: Integer): string;
var
  language: TRoomerLanguageItem;
begin
  Result := '';
  language := RoomerLanguage.LanguageById[aLanguageId];
  if assigned(language) then
    Result := GetTranslatedText(Format('shReleaseNotes_%s', [language.EnglishName]));
  if not Result.StartsWith('http') then
    Result := GetTranslatedText('shReleaseNotes_English');
end;

class procedure TReleaseNotesViewer.OpenReleaseNotes(languageId: integer);
var
  lURL: string;
begin
  lUrl := GetReleaseNotesLink(languageId);
  ShellExecute(0, 'open', PChar(lUrl), nil, nil, SW_SHOWNORMAL);
end;

end.
