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
    function MakeListOfCurrencies : TStrings;
    procedure prepareCurrencyHandlers(List : TStrings);
  public
    constructor Create(currencyCodes : TStrings = nil); overload;

    destructor Destroy; override;

    function ConvertAmount(Amount : Double; const FromCurrency, ToCurrency : String) : Double; overload;
    function ConvertAmount(Amount : Double; FromCurrencyId, ToCurrencyId : Integer) : Double; overload;
  end;


implementation

uses uAppGlobal
     ;


{ TCurrencyHandlersMap }

function TCurrencyHandlersMap.ConvertAmount(Amount: Double; const FromCurrency, ToCurrency: String): Double;
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

constructor TCurrencyHandlersMap.Create(currencyCodes: TStrings = nil);
var
  lCodes: TStrings;
begin
  FMapById := TObjectDictionary<Integer,TCurrencyHandler>.Create([doOwnsValues]);
  FMapByCode := TObjectDictionary<String,TCurrencyHandler>.Create([]);

  if currencyCodes = nil then
  begin
    lCodes := MakeListOfCurrencies;
    try
      prepareCurrencyHandlers(lCodes);
    finally
      lCodes.Free;
    end;
  end
  else
    prepareCurrencyHandlers(currencyCodes);
end;

destructor TCurrencyHandlersMap.Destroy;
begin
  FMapById.Free;
  FMapByCode.Free;
  inherited;
end;

function TCurrencyHandlersMap.MakeListOfCurrencies: TStrings;
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

  for i := 0 to List.Count - 1 do
  begin
    entry := TCurrencyHandler.Create(List[i]);
    FMapByCode.Add(List[i], entry);

    entry := TCurrencyHandler.Create(entry.CurrencyCode);
    FMapById.Add(entry.id, entry);
  end;

end;

end.
