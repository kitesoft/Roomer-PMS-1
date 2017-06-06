unit uCurrencyHandler;

interface

uses
    hData
  , SysUtils
  , cxEdit
  , cxCurrencyEdit
  ;

type
  ECurrencyHandlerException = class(Exception);

  // for future use ... maybe
//  TAmount = record
//    Value: double;
//    Currency: string;
//    function ConvertTo(const aOtherCurrency: string): TAmount;
//  end;

  /// <summary>
  ///   Object to handle conversions and display of amounts in a certain currency <br />
  ///  The handler is constructed for a certain currency code
  /// </summary>
  TCurrencyHandler = class
  private
    FCurrencyRec: recCurrencyHolder;
    FFormatSettings: TFormatSettings;
    function GetRate: double;
    function GetCurrencyCode: string;
  public
    constructor Create(const aCurrencyCode: string); OverLoad;
    constructor Create(const aCurrencyId: Integer); OverLoad;

    property Rate: double read GetRate;
    property CurrencyCode: string read GetCurrencyCode;
    property CurrencyRec : recCurrencyHolder read FCurrencyRec;

    /// <summary>
    ///   Convert aAmount in the currency of this handler to the amount of the currency provided
    /// </summary>
    function ConvertTo(aAmount: double; const aOtherCurrency: string): double; overload;
    function ConvertTo(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double; overload;
    /// <summary>
    ///   Convert aAmount in the currency of another handler to the amount in this currency
    /// </summary>
    function ConvertFrom(aAmount: double; const aOtherCurrency: string): double; overload;
    function ConvertFrom(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double; overload;
    /// <summary>
    ///   Round aAmount to the number of decimals defined for the currency
    /// </summary>
    function RoundedValue(aAmount: double): double;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency
    /// </summary>
    function FormattedValue(aAmount: double; aIncludeCurrencySign: boolean = true): string;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency, without currencyuSign and appending the 3 letter currencycode
    /// </summary>
    function FormattedValueWithCode(aAmount: double): string;
    /// <summary>
    ///   Get the CustomEditProperties component defined in uD , based on currencycode
    /// </summary>
    function GetcxEditProperties: TcxCurrencyEditProperties;
    /// <summary>
    ///   Get the CustomEditProperties component defined in uD , based on currencycode, and transfer the
    ///  event handlers of the origianlProperties to the returned one
    /// </summary>
    function GetcxEditPropertiesKeepEvents(aOriginalProperties: TcxCustomEditProperties): TcxCurrencyEditProperties;
    /// <summary>
    ///   Returns a formatted string with the currencycode and the exchange rate, used to display active currency in i.e. a labelcaption
    /// </summary>
    function ShortDescription: string;
  end;


implementation

uses
    uAppGlobal
  , uStringUtils
  , uFloatUtils
  , uD, PrjConst;

{ TCurrencyHandler }

function TCurrencyHandler.ConvertTo(aAmount: double; const aOtherCurrency: string): double;
var
  lrecOtherCurrency: recCurrencyHolder;
begin
  if not glb.LocateCurrency(aOtherCurrency) then
    raise ECurrencyHandlerException.CreateFmt('Currency code [%s] not found', [aOtherCurrency]);

  lrecOtherCurrency.ReadFromDataset(glb.CurrenciesSet);
  Result := (aAmount * Rate) / lrecOtherCurrency.Value;
end;

function TCurrencyHandler.ConvertFrom(aAmount: double; const aOtherCurrency: string): double;
var
  lrecOtherCurrency: recCurrencyHolder;
begin
  if not glb.LocateCurrency(aOtherCurrency) then
    raise ECurrencyHandlerException.CreateFmt('Currency code [%s] not found', [aOtherCurrency]);

  lrecOtherCurrency.ReadFromDataset(glb.CurrenciesSet);
  Result := (aAmount * lrecOtherCurrency.Value) / Rate;
end;

function TCurrencyHandler.ConvertFrom(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double;
begin
  Result := aOtherCurrencyHandler.ConvertTo(aAmount, Self);
end;

function TCurrencyHandler.ConvertTo(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double;
begin
  Result := (aAmount * Rate) / aOtherCurrencyHandler.Rate;
end;

constructor TCurrencyHandler.Create(const aCurrencyId: Integer);
begin
  if not glb.LocateSpecificRecord('currencies', 'id', aCurrencyId) then
    raise ECurrencyHandlerException.CreateFmt('Currency ID [%d] not found', [aCurrencyId]);

  FCurrencyRec.ReadFromDataset(glb.CurrenciesSet);

  FFormatSettings := TFormatSettings.Create; // System defaults
  FFormatSettings.CurrencyString := FCurrencyRec.CurrencySign;
  FFormatSettings.CurrencyDecimals := FCurrencyRec.Decimals;

  FFormatSettings.CurrencyFormat := 2;
  if FCurrencyRec.CurrencySign = 'kr.' then // quick fix
    FFormatSettings.CurrencyFormat := 3;
end;

constructor TCurrencyHandler.Create(const aCurrencyCode: string);
begin
  if not glb.LocateCurrency(aCurrencyCode) then
    raise ECurrencyHandlerException.CreateFmt('Currency code [%s] not found', [aCurrencyCode]);

  Create(glb.CurrenciesSet.FieldByName('id').AsInteger);
end;

function TCurrencyHandler.FormattedValue(aAmount: double; aIncludeCurrencySign: boolean = true): string;
begin
  if aIncludeCurrencySign then
    Result := CurrToStrF(aAMount, ffCurrency, FCurrencyRec.Decimals, FFormatSettings)
  else
    Result := CurrToStrF(aAMount, ffFixed, FCurrencyRec.Decimals, FFormatSettings);
end;

function TCurrencyHandler.FormattedValueWithCode(aAmount: double): string;
begin
  Result := Format('%s %s', [FormatCurr(FCurrencyRec.Displayformat, RoundedValue(aAmount), FFormatSettings), FCurrencyRec.Currency]);
end;

function TCurrencyHandler.GetCurrencyCode: string;
begin
  Result := FCurrencyRec.Currency;
end;

function TCurrencyHandler.GetcxEditProperties: TcxCurrencyEditProperties;
begin
  Result := TcxCurrencyEditProperties(d.getCurrencyProperties(FCurrencyRec.Currency));
end;

function TCurrencyHandler.GetcxEditPropertiesKeepEvents(aOriginalProperties: TcxCustomEditProperties): TcxCurrencyEditProperties;
begin
  Result := GetcxEditProperties;
  Result.OnChange := aOriginalProperties.OnChange;
  Result.OnEditValueChanged := aOriginalProperties.OnEditValueChanged;
  Result.OnValidate := aOriginalProperties.OnValidate;
end;

function TCurrencyHandler.GetRate: double;
begin
  Result := FCurrencyRec.Value;
end;

function TCurrencyHandler.ShortDescription: string;
const
  cFormat = '%s - %s: %s';
begin
  Result := Format(cFormat, [CurrencyCode, GetTranslatedText('shCurrencyRate'), FloatToStr(RoundDecimals(Rate, 4))]);
end;

function TCurrencyHandler.RoundedValue(aAmount: double): double;
begin
  Result := RoundDecimals(aAmount, FCurrencyRec.Decimals);
end;

{ TAmount }

//function TAmount.ConvertTo(const aOtherCurrency: string): TAmount;
//var
//  lrecOtherCurrency: recCurrencyHolder;
//begin
//  Result.Currency := aOthterCurrency;
//  lrecOtherCurrency.Currency := aOthterCurrency;
//  GET_CurrencyHolderByCurrency(lrecOtherCurrency, false);
//  Result.Value := (Self.Value * Self..Value) / lrecOtherCurrency.Value;
//end;

end.
