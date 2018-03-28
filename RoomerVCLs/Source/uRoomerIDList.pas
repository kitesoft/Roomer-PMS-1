unit uRoomerIDList;

interface

uses
  Spring.Collections.Lists
  , SysUtils
  ;

type
  EIDListException = class(Exception);


  /// <summary>
  ///   Implements a List of integers (i.e. of IDs) to be used i.e. when creating a number of objects and this list
  ///  contains the IDs obtained form the server. A single ID can be extracted with the ExtractNext method
  /// </summary>
  TIDList = class(TList<Integer>)
  public
    /// <summary>
    ///   Get the First ID in the list, and remove it from the list, raises exception if the list is empty
    /// </summary>
    function ExtractNext: integer;
    /// <summary>
    ///   Clear and populate the list with integer values in a '|'-separated string.
    ///  Returns the number of integers added to the list
    /// </summary>
    function FillFromString(const aValue: string): integer;
    /// <summary>
    ///   Returns a string with all numbers in the list
    /// </summary>
    function CommaText: string;
  end;

implementation

uses
  Classes
  ;

{ TIDList }

function TIDList.CommaText: string;
var
  lLst: TStringlist;
  i: integer;
begin
  Result := '';
  lLst := TStringList.Create;
  try
    for i in Self do
      lLst.Add(IntToStr(i));
    result := lLst.CommaText;
  finally
    lLst.Free;
  end;
end;

function TIDList.ExtractNext: integer;
begin
  if IsEmpty then
    raise EIDListException.Create('Cannot extract next ID, IDList is empty');

  Result := ExtractAt(0);
end;

function TIDList.FillFromString(const aValue: string): integer;
var
  lLst: TStringlist;
  lToken: string;
  lID: integer;
begin
  Clear;

  lLst := TStringList.Create;
  try
    lLst.Delimiter := '|';
    lLst.DelimitedText := aValue;

    for lToken in lLst do
    begin
      if TryStrToInt(lToken, lID) then
        Add(lId);
    end;
    Result := Count;
  finally
    lLst.Free;
  end;
end;

end.
