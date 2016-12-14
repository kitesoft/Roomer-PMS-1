unit uCurrencyHandler;

interface

uses
    hData
  , SysUtils
  , cxEdit
  , cxCurrencyEdit
  , Generics.Collections
  ;

type
  ECurrencyHandlerException = class(Exception);

  //TODO: Create a currencyhandler-factory and object cache to avoid recreating handlers


  /// <summary>
  ///   Object to handle conversions and display of amounts in a certain currency <br />
  ///  The handler is constructed for a certain currency code and initializes itself with
  ///  the currency properties from the glb.Currencies dataset
  /// </summary>
  TCurrencyHandler = class
  private
    FCurrencyRec: recCurrencyHolder;
    FFormatSettings: TFormatSettings;
    function GetRate: double;
    function GetCurrencyCode: string;
    function GetId: integer;
  public
    constructor Create(const aCurrencyCode: string);

    property ID: integer read GetId;
    property Rate: double read GetRate;
    property CurrencyCode: string read GetCurrencyCode;

    /// <summary>
    ///   Convert aAmount in the currency of this handler to the amount of the currency provided
    /// </summary>
    function ConvertTo(aAmount: double; const aOtherCurrency: string): double; overload;
    /// <summary>
    ///   Convert aAmount in the currency of this handler to the amount of the currency provided
    /// </summary>
    function ConvertTo(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double; overload;
    /// <summary>
    ///   Convert aAmount from the provided currency into the currency of this handler to the amount of the currency provided
    /// </summary>
    function ConvertFrom(aAmount: double; const aOtherCurrency: string): double;
    /// <summary>
    ///   Round aAmount to the number of decimals defined for the currency
    /// </summary>
    function RoundedValue(aAmount: double): double;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency
    /// </summary>
    function FormattedValue(aAmount: double): string;
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

  TCurrencyHandlerDictionary = TObjectDictionary<string, TCurrencyHandler>;

  TCurrencyHandlerFactory = class
  private
    class var FCache: TCurrencyHandlerDictionary;
    class constructor CreateCLass;
    class destructor DestroyClass;
    class function GetOrCreateCurrencyhandler(const CurCode: string): TCurrencyHandler; static;
  public
    class procedure ClearCache;
    class property CurrencyHandler[const CurCode: string]: TCurrencyHandler read GetOrCreateCurrencyhandler;
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
  lOtherCurrencyHandler: TCurrencyhandler;
begin
  lOtherCurrencyHandler := TCurrencyhandler.Create(aOtherCurrency);
  try
    Result := lOtherCurrencyHandler.ConvertTo(aAmount, Self);
  finally
    lOtherCurrencyHandler.Free;
  end;
end;

function TCurrencyHandler.ConvertTo(aAmount: double; aOtherCurrencyHandler: TCurrencyHandler): double;
begin
  Result := (aAmount * Rate) / aOtherCurrencyHandler.Rate;
end;

constructor TCurrencyHandler.Create(const aCurrencyCode: string);
begin
  if not glb.LocateCurrency(aCurrencyCode) then
    raise ECurrencyHandlerException.CreateFmt('Currency code [%s] not found', [aCurrencyCode]);

  FCurrencyRec.ReadFromDataset(glb.CurrenciesSet);

  FFormatSettings := TFormatSettings.Create; // System defaults
  FFormatSettings.CurrencyString := FCurrencyRec.CurrencySign;
  FFormatSettings.CurrencyFormat := FCurrencyRec.CurrencyFormat;
  FFormatSettings.CurrencyDecimals := FCurrencyRec.Decimals;
end;

function TCurrencyHandler.FormattedValue(aAmount: double): string;
begin
//  Result := Format('%s %s', [FCurrencyRec.CurrencySign, FormatCurr(FCurrencyRec.Displayformat, RoundedValue(aAmount), FFormatSettings)]);
//    Result := FormatCurr(FCurrencyRec.Displayformat, RoundedValue(aAmount), FFormatSettings);
    Result := CurrToStrF(RoundedValue(aAmount), ffCurrency, FFormatsettings.CurrencyDecimals, FFormatSettings);
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

function TCurrencyHandler.GetId: integer;
begin
  Result := FCurrencyRec.id;
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

{ TCurrencyHandlerFactory }

class procedure TCurrencyHandlerFactory.ClearCache;
begin
  FCache.Clear;
end;

class constructor TCurrencyHandlerFactory.CreateCLass;
begin
  FCache := TCurrencyHandlerDictionary.Create([doOwnsValues]);
end;

class destructor TCurrencyHandlerFactory.DestroyClass;
begin
  FCache.Free;
end;

class function TCurrencyHandlerFactory.GetOrCreateCurrencyhandler(const CurCode: string): TCurrencyHandler;
begin
  if not FCache.TryGetValue(CurCode, Result) then
  begin
    Result := TCurrencyHandler.Create(CurCode);
    FCache.Add(CurCode, Result);
  end;
end;

end.
