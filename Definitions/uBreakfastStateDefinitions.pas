unit uBreakfastStateDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions
  ;

type
  {$SCOPEDENUMS ON}
  ///	<summary>
  ///	  Possible states of a breakfast as part of a reservation
  ///	</summary>
  TBreakfastState= (
    None,
    Included,
    NotIncluded
  );

    TBreakfastStateHelper = record helper for TBreakfastState
    public
      class function FromBool(const aBreakfast: boolean): TBreakfastState; static; deprecated;

      /// <summary>
      ///   Return a TBreakfastState based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TBreakfastState; static;

      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TReservationState as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;

      /// <summary>
      ///   Return a single character statusstring
      /// </summary>
      function AsBoolean: boolean; deprecated;

      /// <summary>
      ///   Return the translated displaystring for a TBreakfastState
      /// </summary>
      function AsReadableString : string;

    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TBreakfastStateHelper.AsStrings(aItemList: TStrings);
var
  s: TBreakfastState;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    aItemList.Add(s.AsReadableString);
end;

class function TBreakfastStateHelper.FromItemIndex(aIndex: integer): TBreakfastState;
begin
  Result := TBreakfastState(aIndex);
end;

class function TBreakfastStateHelper.FromBool(const aBreakfast: boolean): TBreakfastState;
begin
  if aBreakfast then
    Result := TBreakfastState.Included
  else
    Result := TBreakfastState.None;
end;

function TBreakfastStateHelper.AsBoolean: boolean;
begin
  Result := Self = TBreakfastState.Included;
end;

function TBreakfastStateHelper.AsReadableString : string;
begin
  case Self of
    TBreakfastState.None:         Result := GetTranslatedText('shTx_ReservationProfile_NoBreakfast');
    TBreakfastState.Included:     Result := GetTranslatedText('shTx_ReservationProfile_Included');
    TBreakfastState.notIncluded:  Result := GetTranslatedText('shTx_ReservationProfile_NotIncluded');
  else
    Result := '';
  end;
end;


function TBreakfastStateHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

end.
