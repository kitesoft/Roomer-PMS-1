unit uCurrencyHandlersMap;

interface

uses System.Generics.Collections
     , SysUtils
     , Classes
     , uCurrencyHandler
     ;

type

  TCurrencyHandlersMap = class
  private
    FMapById : TObjectDictionary<Integer,TCurrencyHandler>;
    FMapByCode : TObjectDictionary<String,TCurrencyHandler>;

  private
    function ListOfCurrencies : TStrings;
    procedure prepareCurrencyHandlers(List : TStrings);
  public
    constructor Create(currencyCodes : TStrings); overload;
    constructor Create; overload;

    destructor Destroy;

    function ConvertAmount(Amount : Double; FromCurrency, ToCurrency : String) : Double; overload;
    function ConvertAmount(Amount : Double; FromCurrencyId, ToCurrencyId : Integer) : Double; overload;
  end;


implementation

uses uAppGlobal
     ;


{ TCurrencyHandlersMap }

function TCurrencyHandlersMap.ConvertAmount(Amount: Double; FromCurrency, ToCurrency: String): Double;
var HandlerFrom, HandlerTo : TCurrencyHandler;
begin
  result := Amount;
  if FMapByCode.TryGetValue(FromCurrency, HandlerFrom) AND
     FMapByCode.TryGetValue(ToCurrency, HandlerTo) then
       result := HandlerFrom.ConvertTo(Amount, HandlerTo);
end;

function TCurrencyHandlersMap.ConvertAmount(Amount: Double; FromCurrencyId, ToCurrencyId: Integer): Double;
var HandlerFrom, HandlerTo : TCurrencyHandler;
begin
  result := Amount;
  if FMapById.TryGetValue(FromCurrencyId, HandlerFrom) AND
     FMapById.TryGetValue(ToCurrencyId, HandlerTo) then
       result := HandlerFrom.ConvertTo(Amount, HandlerTo);
end;

constructor TCurrencyHandlersMap.Create;
var currencyCodes : TStrings;
begin
  currencyCodes := ListOfCurrencies;
  try
    prepareCurrencyHandlers(currencyCodes);
  finally
    currencyCodes.Free;
  end;
end;

constructor TCurrencyHandlersMap.Create(currencyCodes: TStrings);
begin
  prepareCurrencyHandlers(currencyCodes);
end;

destructor TCurrencyHandlersMap.Destroy;
begin
  FMapById.Free;
  FMapByCode.Free;
end;

function TCurrencyHandlersMap.ListOfCurrencies: TStrings;
begin
  result := TStringList.Create;
  glb.CurrenciesSet.First;
  while NOT glb.CurrenciesSet.Eof do
  begin
    result.Add(glb.CurrenciesSet['Currency']);
    glb.CurrenciesSet.Next;
  end;
end;

procedure TCurrencyHandlersMap.prepareCurrencyHandlers(List: TStrings);
var entry : TCurrencyHandler;
  i: Integer;
begin
  FMapById := TObjectDictionary<Integer,TCurrencyHandler>.Create;
  FMapByCode := TObjectDictionary<String,TCurrencyHandler>.Create;

  for i := 0 to List.Count - 1 do
  begin
    entry := TCurrencyHandler.Create(List[i]);
    FMapByCode.Add(List[i], entry);

    entry := TCurrencyHandler.Create(entry.CurrencyRec.id);
    FMapById.Add(entry.CurrencyRec.id, entry);
  end;

end;

end.
