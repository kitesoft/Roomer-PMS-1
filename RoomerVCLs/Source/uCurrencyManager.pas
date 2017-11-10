unit uCurrencyManager;

interface

uses
  Generics.Collections
  , uCurrencyDefinition
  , uCurrencyConstants
  , uAmount
  ;

type
  ECurrencyManagerException = class(ECurrencyException);
  ECurrencyConversionException = class(ECurrencyException);

  /// <summary>
  ///   Definition of an overall class (meant to be singleton but not enforced) for managing available currencies
  /// </summary>
  ///	<remarks>
  ///	  <para>
  ///	    Unittests are available in <c>Roomer-PMS-1\Unittests\CurrencyTests</c>
  ///	  </para>
  ///	</remarks>
  TCurrencyManager = class
  private
    type
      TCurrencyDefinitionDictionary = TObjectDictionary<TCurrencyCode, TCurrencyDefinition>;
      TCurrencyDefinitionDictionaryID = TDictionary<integer, TCurrencyDefinition>;
    const
      cDefaultCurrency: TCurrencyCode = 'EUR';
    var
      FCache: TCurrencyDefinitionDictionary;
      FIDCache: TCurrencyDefinitionDictionaryID;
      FDefault: TCurrencyCode;
      FDefaultDef: TCurrencyDefinition;
      function GetOrCreateCurrencyDefinition(const CurCode: TCurrencyCode; aCurID: integer = -1): TCurrencyDefinition;
      function GetCurrencyDefinitionByCode(const CurCode: TCurrencyCode): TCurrencyDefinition;
      function GetCurrencyDefinitionByID(CurID: integer): TCurrencyDefinition;
      procedure SetDefaultCurrency(const Value: TCurrencyCode);
      procedure CacheNotification(Sender: TObject; const Item: TCurrencyDefinition;  Action: TCollectionNotification);
      function GetDefaultCurrency: TCurrencyCode;
  protected
    function GetDefaultCurrencydefinition: TCurrencyDefinition;
    function CurrencyDefinitionClass: TCurrencyDefinitionClass; virtual;
    procedure Lock;
    procedure UnLock;
  public
    constructor Create(const aDefaultCurrency: TCurrencyCode); virtual;
    destructor Destroy; override;
    procedure ClearCache;
    function DefinitionExists(const aCurrCode: TCurrencyCode): boolean;
    function CreateDefinition(const CurCode: TCurrencyCode): TCurrencyDefinition; overload; virtual;
    function CreateDefinition(const CurCode: TCurrencyCode; aCurID: integer): TCurrencyDefinition; overload; virtual;

    /// <summary>
    ///   Calculate the value when converting aValue from aFromCurCode to aToCurrCode.
    ///  Note that this function does not use the TAmount types directly to avoid unneeded and circular dependencies
    /// </summary>
    function ConvertAmount(aValue: TAmount; const aToCurrCode: TCurrencyCode): TAmount;
    /// <summary>
    ///   Calculate the value when converting aValue to the default currency
    ///  Note that this function does not use the TAmount types directly to avoid unneeded and circular dependencies
    /// </summary>
    function ConvertAmountToDefault(aValue: TAmount): TAmount;

    property CurrencyDefinition[const CurCode: TCurrencyCode]: TCurrencyDefinition read GetCurrencyDefinitionByCode; default;
    property CurrencyDefinitionByID[CurID: integer]: TCurrencyDefinition read GetCurrencyDefinitionByID;
    property DefaultCurrency: TCurrencyCode read GetDefaultCurrency write SetDefaultCurrency;
    property DefaultCurrencyDefinition: TCurrencyDefinition read GetDefaultCurrencydefinition;
  end;

  TCurrencymanagerClass = class of TCurrencymanager;

/// <summary>
///   Global factory method for instantiating a currencymanager of a certain class
/// </summary>
procedure InitGlobalCurrencyManager(aClass: TCurrencymanagerClass; const aDefaultCurrency: TCurrencyCode);

/// <summary>
/// Global access method to a global currencymangere. If aDontInit = false (default) and non has been initialized with the InitGlobalCurrencymanager() method
/// then a Currencymanager of type TCurrencymanager will be instantiated
/// </summary>
function CurrencyManager(aDontInit: boolean = false): TCurrencyManager;

implementation

uses
  Math
  , SysUtils
  , uUtils
  , Generics.Defaults;

type
  TCurrencyCodeEqualityComparer = class(TEqualityComparer<TCurrencyCode>)
  public
    function Equals(const Left, Right: TCurrencyCode): Boolean; override;
    function GetHashCode(const Value: TCurrencyCode): Integer; override;
  end;

var
  gCurrencyManager: TCurrencyManager = nil;


procedure InitGlobalCurrencyManager(aClass: TCurrencymanagerClass; const aDefaultCurrency: TCurrencyCode);
begin
  gCurrencyManager.Free;
  gCurrencyManager := aClass.Create(aDefaultCurrency);
end;

function CurrencyManager(aDontInit: boolean = false): TCurrencyManager;
begin
  if not assigned(gCurrencyManager) and not aDontInit then
    InitGlobalCurrencyManager(TCurrencyManager, '   ');
  Result := gCurrencyManager;
end;


procedure TCurrencyManager.CacheNotification(Sender: TObject; const Item: TCurrencyDefinition;
  Action: TCollectionNotification);
begin
  case Action of
    cnAdded:      if Item.ID >= 0 then
                    FIDCache.AddOrSetValue(Item.ID, Item);
    cnRemoved,
    cnExtracted:  begin
                    if FDefaultDef = Item then
                      FDefaultDef := nil;
                    if FIDCache.ContainsValue(Item) then
                      FIDCache.Remove(Item.ID);
                  end;
  end;
end;

procedure TCurrencyManager.ClearCache;
begin
  Lock;
  try
    FDefaultDef := nil;
    FCache.Clear;
    DefaultCurrency := FDefault;
  finally
    UnLock;
  end;
end;

function TCurrencyManager.ConvertAmount(aValue: TAmount; const aToCurrCode: TCurrencyCode): TAmount;
var
  lNewValue: Currency;
begin
  if not DefinitionExists(aToCurrCode) then
    raise ECurrencyConversionException.CreateFmt('Converting to an unknown currency [%s]', [aToCurrCode]);

  lNewValue := aValue * CurrencyDefinition[aValue.CurrencyCode].Rate / CurrencyDefinition[aToCurrCode].Rate;
  Result := TAmount.Create(lNewValue, aToCurrCode);
end;

function TCurrencyManager.ConvertAmountToDefault(aValue: TAmount): TAmount;
begin
  Result := ConvertAmount(aValue, DefaultCurrency);
end;

constructor TCurrencyManager.Create(const aDefaultCurrency: TCurrencyCode);
begin
  FCache := TCurrencyDefinitionDictionary.Create([doOwnsValues], TCurrencyCodeEqualityComparer.Create);
  FIDCache := TCurrencyDefinitionDictionaryID.Create;
  FCache.OnValueNotify := CacheNotification;
  if (aDefaultCurrency <> '   ') then
    DefaultCurrency := aDefaultCurrency;
end;

function TCurrencyManager.CreateDefinition(const CurCode: TCurrencyCode; aCurID: integer): TCurrencyDefinition;
begin
  Lock;
  try
    Result := GetOrCreateCurrencyDefinition(CurCode, aCurId);
  finally
    Unlock;
  end;
end;

function TCurrencyManager.CreateDefinition(const CurCode: TCurrencyCode): TCurrencyDefinition;
begin
  Lock;
  try
    Result := GetOrCreateCurrencyDefinition(CurCode);
  finally
    Unlock;
  end;
end;

function TCurrencyManager.CurrencyDefinitionClass: TCurrencyDefinitionClass;
begin
  Result := TCurrencyDefinition;
end;

destructor TCurrencyManager.Destroy;
begin
  FCache.Free;
  FIDCache.Free;
  inherited;
end;

function TCurrencyManager.GetCurrencyDefinitionByCode(const CurCode: TCurrencyCode): TCurrencyDefinition;
begin
  Result := FCache.Items[CurCode];
end;

function TCurrencyManager.GetCurrencyDefinitionByID(CurID: integer): TCurrencyDefinition;
begin
  Result := FIDCache.Items[CurID];
end;

function TCurrencyManager.GetDefaultCurrency: TCurrencyCode;
begin
  Result := FDefault;
end;

function TCurrencyManager.GetDefaultCurrencydefinition: TCurrencyDefinition;
begin
  if not assigned(FDefaultDef) then
    FDefaultDef := CurrencyDefinition[DefaultCurrency];
  Result := FDefaultDef;
end;

function TCurrencyManager.GetOrCreateCurrencyDefinition(const CurCode: TCurrencyCode; aCurID: integer = -1): TCurrencyDefinition;
begin
  if String(CurCode).trim = '' then
    raise ECurrencyManagerException.Create('No currencycode provided');

  Lock;
  try
    if not FCache.TryGetValue(CurCode, Result) then
    begin
      Result := CurrencyDefinitionClass.Create(CurCode, aCurId);
      FCache.Add(CurCode, Result);
    end;
  finally
    Unlock;
  end;
end;

function TCurrencyManager.DefinitionExists(const aCurrCode: TCurrencyCode): boolean;
begin
  Result := FCache.ContainsKey(aCurrCode);
end;

procedure TCurrencyManager.Lock;
begin
  MonitorEnter(Self);
end;

procedure TCurrencyManager.SetDefaultCurrency(const Value: TCurrencyCode);
var
  lCorrection: double;
  lCurrency: TCurrencyDefinition;
begin
  Lock;
  try
    FDefaultDef := nil;
    if DefinitionExists(value) then
    begin
      lCorrection := CurrencyDefinition[value].Rate;
      if not SameValue(lCorrection, 1.0) then
        for lCurrency in FCache.Values do
          lCurrency.Rate := lCurrency.Rate / lCorrection;
    end
    else
      CreateDefinition(Value);
    FDefault := value;
  finally
    Unlock;
  end;
end;

procedure TCurrencyManager.UnLock;
begin
  MonitorExit(Self);
end;

{ TCurrencyCodeEqualityComparer }

function TCurrencyCodeEqualityComparer.Equals(const Left, Right: TCurrencyCode): Boolean;
begin
  Result := SameText(Left, Right);
end;

function TCurrencyCodeEqualityComparer.GetHashCode(const Value: TCurrencyCode): Integer;
var
  s: string;
begin
  s := UpperCase(String(Value));
  Result := BobJenkinsHash(s[1], Length(s) * SizeOf(s[1]), 0);
end;

initialization

finalization
  gCurrencyManager.Free;
end.
