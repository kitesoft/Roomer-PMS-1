unit uStaffCommunicationDefinitions;

interface

uses
  Classes
  ;

type

  TStaffCommAction = (scaNoActionNeeded, scaActionNeeded, scaActionFinished);

  TStaffCommActionHelper = record helper for TStaffCommAction
  private
  const
    /// <summary>
    ///   Strings used in the database to store TCleaningNoteServicetype
    /// </summary>
    cStaffCommActionStrings: array[TStaffCommAction] of string =
      ('NO_ACTION_NEEDED', 'ACTION_NEEDED', 'ACTION_FINISHED');

  public
    // constructor
    /// <summary>
    ///   Create a TStaffCommActionfrom a string
    /// </summary>
    class function FromString(const aType: string) : TStaffCommAction; static;
    /// <summary>
    ///   Return a TStaffCommAction based in index.
    /// </summary>
    class function FromItemIndex(aIndex: integer) : TStaffCommAction; static;

    /// <summary>
    ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
    /// </summary>
    class procedure AsStrings(aItemList: TStrings); static;

    /// <summary>
    ///   Return a TStaffCommAction based in index.
    /// </summary>
    function ToItemIndex: integer;

    /// <summary>
    ///   Return the string as this TStaffCommAction is stored in the database
    /// </summary>
    function ToDB: string;

    /// <summary>
    ///   Return the translated displaystring for a TStaffCommAction
    /// </summary>
    function AsReadableString : string;

  end;

implementation

uses
  SysUtils
  , PrjConst
  ;

{ TStaffCommActionHelper }

function TStaffCommActionHelper.AsReadableString: string;
begin
  case Self of
    scaNoActionNeeded:  Result := GetTranslatedText('shStaffCommAction_NoActionNeeded');
    scaActionNeeded:    Result := GetTranslatedText('shStaffCommAction_ActionNeeded');
    scaActionFinished:  Result := GetTranslatedText('shStaffCommAction_ActionFinished');
  end;
end;

class procedure TStaffCommActionHelper.AsStrings(aItemList: TStrings);
var
  s: TStaffCommAction;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    aItemList.Add(s.AsReadableString);
end;

class function TStaffCommActionHelper.FromItemIndex(aIndex: integer): TStaffCommAction;
begin
  Result := TStaffCommAction(aIndex);
end;

class function TStaffCommActionHelper.FromString(const aType: string): TStaffCommAction;
begin
  for Result := low(result) to high(result) do
    if cStaffCommActionStrings[Result].Equals(aType.ToUpper) then
      Break;
end;

function TStaffCommActionHelper.ToDB: string;
begin
  Result := cStaffCommActionStrings[self];
end;

function TStaffCommActionHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

end.
