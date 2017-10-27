unit uRoomerCurrencyDefinition;

interface

uses
    uCurrencyDefinition
  , cxEdit
  , cxCurrencyEdit
  ;

type
  TRoomerCurrencyDefinition = class(TCurrencyDefinition)
  private
  public
    constructor Create(const aCurrencyCode: string); override;

    function GetcxEditProperties: TcxCurrencyEditProperties;
    function GetcxEditPropertiesKeepEvents(aOrigProperties: TcxCustomEditProperties): TcxCustomEditProperties;
  end;


implementation

uses
  uD
  , uAppGlobal
  , hData
  , DB
  , SysUtils
  ;

{ TRoomerCurrencyDefinition }


constructor TRoomerCurrencyDefinition.Create(const aCurrencyCode: string);
var
  lRec: recCurrencyHolder;
  lFormat: TFormatSettings;
begin
  inherited;
  with glb.CurrenciesSet do
  begin
    DisableControls;
    try
      if (fieldByName('currency').asstring = aCurrencyCode) or Locate('currency', aCurrencyCode, [loCaseInsensitive]) then
      begin
        lRec.ReadFromDataset(glb.CurrenciesSet);
        lFormat := CurrencyFormatSettings;
        lFormat.CurrencyString := lRec.CurrencySign;
        lFormat.CurrencyFormat := lRec.CurrencyFormat;
        lFormat.CurrencyDecimals := lRec.Decimals;
        CurrencyFormatSettings := lFormat;
        Rate := lRec.Value;
        FID := lRec.ID;
      end;
    finally
      EnableControls;
    end;
  end;

end;

function TRoomerCurrencyDefinition.GetcxEditProperties: TcxCurrencyEditProperties;
begin
  Result := TcxCurrencyEditProperties(d.getCurrencyProperties(String(CurrencyCode)));
end;

function TRoomerCurrencyDefinition.GetcxEditPropertiesKeepEvents(aOrigProperties: TcxCustomEditProperties): TcxCustomEditProperties;
begin
  Result := GetcxEditProperties;
  Result.OnChange := aOrigProperties.OnChange;
  Result.OnEditValueChanged := aOrigProperties.OnEditValueChanged;
  Result.OnValidate := aOrigProperties.OnValidate;
end;

end.


