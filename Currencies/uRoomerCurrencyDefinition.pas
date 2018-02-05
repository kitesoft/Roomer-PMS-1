unit uRoomerCurrencyDefinition;

interface

uses
    uCurrencyDefinition
  , cxEdit
  , cxCurrencyEdit
  , RoomerExceptionHandling
  ;

type
  EInvalidCurrencyRateException = class(ERoomerUserException);

  TRoomerCurrencyDefinition = class(TCurrencyDefinition)
  private
  public
    constructor Create(const aCurrencyCode: string); override;

    function ShortDescription: string; override;

    function GetcxEditProperties: TcxCurrencyEditProperties;
    procedure SetcxEditProperties(aProperties: TcxCustomEditProperties);
    function GetcxEditPropertiesKeepEvents(aOrigProperties: TcxCustomEditProperties): TcxCustomEditProperties;
  end;


implementation

uses
  Classes
  , uD
  , uAppGlobal
  , hData
  , DB
  , SysUtils
  , Math
  , Types
  , PrjConst
  , uFloatUtils
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
        if CompareValue(lRec.Value, 0.000, 0.0001) = LessThanValue then
          raise EInvalidCurrencyRateException.createFmt('Invalid rate for currency [%s]: [%g]' + #13 + 'Correct rate and restart Roomer', [aCurrencyCode, lRec.Value]);
        lFormat := CurrencyFormatSettings;
        lFormat.CurrencyString := lRec.CurrencySign;
        lFormat.CurrencyFormat := lRec.CurrencyFormat;
        lFormat.CurrencyDecimals := lRec.Decimals;
        lFormat.NegCurrFormat := 2;
        CurrencyFormatSettings := lFormat;
        Rate := lRec.Value;
        FID := lRec.ID;
      end;
    finally
      EnableControls;
    end;
  end;

end;

function TRoomerCurrencyDefinition.ShortDescription: string;
const
  cFormat = '%s (%s: %s)';
begin
  Result := Format(cFormat, [Description, GetTranslatedText('shCurrencyRate'), FloatToStr(RoundDecimals(Rate, 4))]);
end;


function TRoomerCurrencyDefinition.GetcxEditProperties: TcxCurrencyEditProperties;
begin
  Result := TcxCurrencyEditProperties(d.getCurrencyProperties(String(CurrencyCode)));
end;

procedure TRoomerCurrencyDefinition.SetcxEditProperties(aProperties: TcxCustomEditProperties);
begin
  if aProperties is TcxCurrencyEditProperties then
  with TcxCurrencyEditProperties(aProperties) do
  begin
    Alignment.Horz := taRightJustify;
    DecimalPlaces  := CurrencyFormatSettings.CurrencyDecimals;
    DisplayFormat  := cxEditPropertiesCurrencyFormat(CurrencyFormatSettings);
  end;
end;

function TRoomerCurrencyDefinition.GetcxEditPropertiesKeepEvents(aOrigProperties: TcxCustomEditProperties): TcxCustomEditProperties;
begin
  Result := GetcxEditProperties;
  Result.OnChange := aOrigProperties.OnChange;
  Result.OnEditValueChanged := aOrigProperties.OnEditValueChanged;
  Result.OnValidate := aOrigProperties.OnValidate;
end;

end.


