unit uFraCountryPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel,
  uFraLookupPanel;

type
  TfraCountryPanel = class(TfraCustomLookupPanel)
  protected
    procedure DoInternalSelect; override;
  public
    constructor Create(aOwner: TCOmponent); override;
  end;

implementation

{$R *.dfm}

uses
    hData
  , uAppGlobal
  , uCountries
  , Math
  , uG
  ;

constructor TfraCountryPanel.Create(aOwner: TCOmponent);
begin
  inherited;
  Dataset := glb.Countries;
  CodeField := 'country';
  DescriptionField := 'countryname';
end;

procedure TfraCountryPanel.DoInternalSelect;
var
  theData : recCountryHolder;
begin
  theData.Country := Code;
  if Countries(actLookup, theData) then
    Code := theData.Country;
end;

end.
