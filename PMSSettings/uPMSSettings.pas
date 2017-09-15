unit uPMSSettings;

interface

uses
  SysUtils
  , Classes
  , cmpRoomerDataset
  , uMandatoryFIeldDefinitions
  , uPMSSettingsAccessor
  ;

type

  TPMSSettingsGroup = class
  private
    FPMSAccessor: TPMSSettingsAccessor;
  protected
    function GetKeyGroup: string; virtual; abstract;
    procedure SaveSetting(const aKey: string; const aValue: string; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKey: string; const aValue: boolean; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKey: string; const aValue: integer; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    function GetSettingsAsBoolean(const aKey : String; aDefault : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
    function GetSettingsAsInteger(const aKey : String; aDefault : Integer = 0; aOptions: TPMSSettingsGetSetOptions = []) : Integer;
    function GetSettingsAsString(const aKey : String; const aDefault : String = ''; aOptions: TPMSSettingsGetSetOptions = []) : String;
  public
    constructor Create(aAccessor: TPMSSettingsAccessor);
  end;


  TRoomRentPerDaySetting = (rpdNever, rpdAsk, rpdAlways);
  TRoomRentPerDaySettingHelper = record helper for TRoomrentPerDaySetting
  private
    /// <summary>
    ///   Strings used in the database to store TCleaningNoteServicetype
    /// </summary>
    const cRoomRentPerDayStrings: array[TRoomRentPerDaySetting] of string =
      ('NEVER', ' ASK' , 'ALWAYS');

  public
      // constructor
      /// <summary>
      ///   Create a TRoomrentPerDaySetting from a string
      /// </summary>
      class function FromString(const aRoomRentPerDay: string) : TRoomrentPerDaySetting; static;
      class function FromItemIndex(aIndex: integer): TRoomRentPerDaySetting; static;
      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TReservationState as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;

      /// <summary>
      ///   Return as a string for db
      /// </summary>
      function AsDB: string;
      /// <summary>
      ///   Return the translated displaystring for a TAccountType
      /// </summary>
      function AsReadableString : string;
  end;


  TPMSSettingsInvoice = class(TPMSSettingsGroup)
  private const
    cInvoiceHandlingGroup = 'INVOICE_HANDLING_FUNCTIONS';
    cInvoiceHandlingShowAsPaidWhenZero = 'SHOW_AS_PAID_WHEN_ZERO';
    cAllowPaymentModifications = 'ALLOW_PAYMENT_MODIFICATIONS';
    cAllowDeletingItemsFromInvoice = 'ALLOW_DELETING_FROM_INVOICE';
    cAllowTogglingOfCityTaxes = 'ALLOW_TOGGLING_OF_CITY_TAXES_INVOICE';
    cShowIncludedBreakfastOnInvoice = 'SHOW_INCLUDED_BREAKFAST_ON_INVOICE';
    cShowRoomRentPerDay = 'SHOW_ROOMRENT_PER_DAY';
  private
    function GetShowInvoiceAsPaidWhenStatusIsZero: boolean;
    procedure SetShowInvoiceAsPaidWhenStatusIsZero(const Value: boolean);
    function GetAllowDeletingItemsFromInvoice: boolean;
    function GetAllowPaymentModification: boolean;
    function GetAllowTogglingOfCityTaxes: boolean;
    function GetShowIncludedBreakfastOnInvoice: boolean;
    procedure SetAllowDeletingItemsFromInvoice(const Value: boolean);
    procedure SetAllowPaymentModification(const Value: boolean);
    procedure SetAllowTogglingOfCityTaxes(const Value: boolean);
    procedure SetShowIncludedBreakfastOnInvoice(const Value: boolean);
    function GetRoomRentPerDayOninvoice: TRoomrentPerDaySetting;
    procedure SetRoomRentPerDayOninvoice(const Value: TRoomrentPerDaySetting);
  protected
    function GetKeyGroup: string; override;
  public
    property ShowInvoiceAsPaidWhenStatusIsZero: boolean read GetShowInvoiceAsPaidWhenStatusIsZero write SetShowInvoiceAsPaidWhenStatusIsZero;
    property ShowIncludedBreakfastOnInvoice: boolean read GetShowIncludedBreakfastOnInvoice write SetShowIncludedBreakfastOnInvoice;
    property AllowPaymentModification: boolean read GetAllowPaymentModification write SetAllowPaymentModification;
    property AllowDeletingItemsFromInvoice: boolean read GetAllowDeletingItemsFromInvoice write SetAllowDeletingItemsFromInvoice;
    property AllowTogglingOfCityTaxes: boolean read GetAllowTogglingOfCityTaxes write SetAllowTogglingOfCityTaxes;
    property RoomRentPerDayOninvoice: TRoomrentPerDaySetting read GetRoomRentPerDayOninvoice write SetRoomRentPerDayOninvoice;
  end;

  TPMSSettingsRatesAvailabilities = class(TPMSSettingsGroup)
  private const
    cRatesAndAvailabilitiesGroup = 'RATES_AND_AVAILABILITY_FUNCTIONS';
    cTopClassAvailabilityOrderActive = 'TOP_CLASS_AVAILABILITY_ORDER_ACTIVE';
    cMasterRateDefaultsActive = 'MASTER_RATE_DEFAULTS_ACTIVE';
    cMasterRateCurrency = 'MASTER_RATE_CURRENCY';
    cMasterRateCurrencyActive = 'MASTER_RATE_CURRENCY_CONERT_ACTIVE';
  private
    function GetTopClassAvaiabilityOrderActive: boolean;
    procedure SetTopClassAvaiabilityOrderActive(const Value: boolean);
    function GetMasterRateDefaultsActive: boolean;
    procedure SetMasterRateDefaultsActive(const Value: boolean);
    function GetMasterRateCurrency: String;
    procedure SetMasterRateCurrency(const Value: String);
    function GetMasterRateCurrencyConvert: boolean;
    procedure SetMasterRateCurrencyConvert(const Value: boolean);

  protected
    function GetKeyGroup: string; override;
  public
    property TopClassAvaiabilityOrderActive: boolean read GetTopClassAvaiabilityOrderActive write SetTopClassAvaiabilityOrderActive;
    property MasterRateDefaultsActive: boolean read GetMasterRateDefaultsActive write SetMasterRateDefaultsActive;
    property MasterRateCurrency: String read GetMasterRateCurrency write SetMasterRateCurrency;
    property MasterRateCurrencyConvert: boolean read GetMasterRateCurrencyConvert write SetMasterRateCurrencyConvert;
  end;

  TPMSSettingsVariousOptions = class(TPMSSettingsGroup)
  private const
    cVariousOptionsGroup = 'VARIOUS_OPTIONAL_SETTINGS';
    cPreloadListOfPreviousGuests = 'PRELOAD_LIST_OF_PREVIOUS_GUESTS';
  private
    function GetPreloadListOfPreviousGuests: boolean;
    procedure SetPreloadListOfPreviousGuests(const Value: boolean);
  protected
    function GetKeyGroup: string; override;
  public
    property PreloadListOfPreviousGuests: boolean read GetPreloadListOfPreviousGuests write SetPreloadListOfPreviousGuests;
  end;

  TPMSFinanceConnectOptions = class(TPMSSettingsGroup)
  private const
    cFinanceConnectOptionsGroup = 'FINANCE_CONNECT';
    cFinanceConnectSystemCode = 'SYSTEM_CODE';
  private
    function GetFinanceConnectSystemCode: String;
    procedure SetFinanceConnectSystemCode(const Value: String);
  protected
    function GetKeyGroup: string; override;
  public
    property FinanceConnectSystemCode: String read GetFinanceConnectSystemCode write SetFinanceConnectSystemCode;
  end;

  TPMSSettingsReservationProfile = class(TPMSSettingsGroup)
  private const
    cReservationProfileGroup = 'RESERVATIONPROFILE_FUNCTIONS';
    cAllGuestsNationality = 'EDIT_ALLGUESTS_NATIONALITY';
    cAllowAllotmentStateChange = 'ALLOW_ALLOTMENT_STATECHANGE';

  private
    function GetEditAllGuestsNationality: boolean;
    procedure SetEditAllGuestsNationality(const Value: boolean);
    function GetAllowAllotmentStateChange: boolean;
    procedure SetAllowAllotmentStateChange(const Value: boolean);
  protected
    function GetKeyGroup: string; override;
  public
    /// <summary>
    ///   If true then the reservation profile window contains function to change nationality of all guests
    /// </summary>
    property EditAllGuestsNationality: boolean read GetEditAllGuestsNationality write SetEditAllGuestsNationality;
    /// <summary>
    ///   If true then roomreservations with stsate Allotment can be changed into Reservation and back
    /// </summary>
    property AllowAllotmentStateChange: boolean read GetAllowAllotmentStateChange write SetAllowAllotmentStateChange;
  end;

  TPMSSettingsBetaFunctionality = class(TPMSSettingsGroup)
  private const
    cBetaFunctionsGroup = 'BETA_FUNCTIONS';
    cBetaFunctionsAvailableName = 'BETA_FUNCTIONS_AVAILABLE';
    cBetaFunctionUseNewTaxcalcMethod = 'USE_NEW_TAXCALC_METHOD';

  private
    function GetBetaFunctionsAvailable: boolean;
    procedure SetBetaFunctionsAvailable(const Value: boolean);
    function GetUseInvocieOnObjectsForm: boolean;
    procedure SetUseInvocieOnObjectsForm(const Value: boolean);
  protected
    function GetKeyGroup: string; override;
  public
    /// <summary>
    ///   If true then functions marked as Beta are available in the PMS
    ///  This setting can only be enabled directly in the database and not via the controldata form
    /// </summary>
    property BetaFunctionsAvailable: boolean read GetBetaFunctionsAvailable write SetBetaFunctionsAvailable;
    property UseNewTaxcalcMethod: boolean read GetUseInvocieOnObjectsForm write SetUseInvocieOnObjectsForm;
  end;

  TPMSPMSSpecificSettings = class(TPMSSettingsGroup)
  private const
    cUserSpecific = 'PMS_SPECIFIC_SETTINGS';
    cUserSpecificHomePage = 'HOME_PAGE';

  private
    function GetUserHomePage: Integer;
    procedure SetUserHomePage(const Value: Integer);
  protected
    function GetKeyGroup: string; override;
  public
    /// <summary>
    ///   If true then functions marked as Beta are available in the PMS
    /// </summary>
    property UserHomePage: Integer read GetUserHomePage write SetUserHomePage;
  end;

  /// <summary>
  ///   Provides access to PMS configuration-items stored in PMSSettings table in database
  /// </summary>
  TPMSSettings = class
  private
    FPMSSettingsAccessor: TPMSSettingsAccessor;
    FInvoiceSettings: TPMSSettingsInvoice;
    FMasterRatesSettings: TPMSSettingsRatesAvailabilities;
    FReservationProfileSettngs: TPMSSettingsReservationProfile;
    FBetaFunctionality: TPMSSettingsBetaFunctionality;
    FPMSSpecificSettings: TPMSPMSSpecificSettings;
    FVariousOptions: TPMSSettingsVariousOptions;
    FFinanceConnectOptions: TPMSFinanceConnectOptions;
  protected

    function GetMandatoryCheckinFields: TMandatoryCheckInFieldSet;
    procedure SetMandatoryCheckinFields(const Value: TMandatoryCheckInFieldSet);

  public
    constructor Create(aPMSDataset: TRoomerDataset);
    destructor Destroy; override;

    property InvoiceSettings: TPMSSettingsInvoice read FInvoiceSettings;
    property MasterRatesSettings: TPMSSettingsRatesAvailabilities read FMasterRatesSettings;
    property ReservationProfileSettings: TPMSSettingsReservationProfile read FReservationProfileSettngs;
    property BetaFunctionality: TPMSSettingsBetaFunctionality read FBetaFunctionality;
    property PMSSpecificSettings: TPMSPMSSpecificSettings read FPMSSpecificSettings;
    property VariousOptions : TPMSSettingsVariousOptions read FVariousOptions;
    property FinanceConnect : TPMSFinanceConnectOptions read FFinanceConnectOptions;

    /// <summary>
    ///   Currently enabled TMandatoryCheckinFields in PMS settings
    /// </summary>
    property MandatoryCheckinFields: TMandatoryCheckInFieldSet read GetMandatoryCheckinFields write SetMandatoryCheckinFields;
  end;


implementation

uses
  Variants
  , uUtils
  , hData
  , PrjConst;

constructor TPmsSettings.Create(aPMSDataset: TRoomerDataset);
begin
  FPMSSettingsAccessor := TPMSSettingsAccessor.Create(aPMSDataset);

  FInvoiceSettings := TPMSSettingsInvoice.Create(FPMSSettingsAccessor);
  FMasterRatesSettings := TPMSSettingsRatesAvailabilities.Create(FPMSSettingsAccessor);
  FReservationProfileSettngs := TPMSSettingsReservationProfile.Create(FPMSSettingsAccessor);
  FBetaFunctionality := TPMSSettingsBetaFunctionality.Create(FPMSSettingsAccessor);
  FPMSSpecificSettings := TPMSPMSSpecificSettings.Create(FPMSSettingsAccessor);
  FVariousOptions := TPMSSettingsVariousOptions.Create(FPMSSettingsAccessor);
  FFinanceConnectOptions := TPMSFinanceConnectOptions.Create(FPMSSettingsAccessor);
end;

destructor TPmsSettings.Destroy;
begin
  FPMSSettingsAccessor.Free;
  FInvoiceSettings.Free;
  FMasterRatesSettings.Free;
  FReservationProfileSettngs.Free;
  FBetaFunctionality.Free;
  FPMSSpecificSettings.Free;
  FVariousOptions.Free;
  FFinanceConnectOptions.Free;
  inherited;
end;


procedure TPMSSettingsRatesAvailabilities.SetTopClassAvaiabilityOrderActive(const Value: boolean);
begin
  SaveSetting(cTopClassAvailabilityOrderActive, Value);
end;

procedure TPmsSettings.SetMandatoryCheckinFields(const Value: TMandatoryCheckInFieldSet);
var
  lMF: TMandatoryCheckinField;
begin
  for lMF := low(lMF) to high(lMF) do
    FPMSSettingsAccessor.SaveSetting(lMF.PMSSettingGroup, lMF.PMSSettingName, (lMF in Value));
end;

procedure TPMSSettingsRatesAvailabilities.SetMasterRateCurrency(const Value: String);
begin
  SaveSetting(cMasterRateCurrency, Value);
end;

procedure TPMSSettingsRatesAvailabilities.SetMasterRateCurrencyConvert(const Value: boolean);
begin
  SaveSetting(cMasterRateCurrencyActive, Value);
end;

procedure TPMSSettingsRatesAvailabilities.SetMasterRateDefaultsActive(const Value: boolean);
begin
  SaveSetting(cMasterRateDefaultsActive, Value);
end;

function TPMSSettingsRatesAvailabilities.GetTopClassAvaiabilityOrderActive: boolean;
begin
  Result := GetSettingsAsBoolean(cTopClassAvailabilityOrderActive, False);
end;

function TPmsSettings.GetMandatoryCheckinFields: TMandatoryCheckInFieldSet;
var
  lMF: TMandatoryCheckinField;
begin
  Result := [];
  for lMF := low(lMF) to high(lMF) do
    if FPMSSettingsAccessor.GetSettingsAsBoolean(lMF.PMsSettingGroup, lMF.PMSSettingName, True) then
      Include(Result, lMF);
end;

function TPMSSettingsRatesAvailabilities.GetKeyGroup: string;
begin
  Result := cRatesAndAvailabilitiesGroup;
end;

function TPMSSettingsRatesAvailabilities.GetMasterRateCurrency: String;
begin
  Result := GetSettingsAsString(cMasterRateCurrency, ctrlGetString('NativeCurrency'));
end;

function TPMSSettingsRatesAvailabilities.GetMasterRateCurrencyConvert: boolean;
begin
  Result := GetSettingsAsBoolean(cMasterRateCurrencyActive, False);
end;

function TPMSSettingsRatesAvailabilities.GetMasterRateDefaultsActive: boolean;
begin
  Result := GetSettingsAsBoolean(cMasterRateDefaultsActive, False);
end;



{ TPMSSettingsInvoice }

function TPMSSettingsInvoice.GetKeyGroup: string;
begin
  Result := cInvoiceHandlingGroup;
end;

function TPMSSettingsInvoice.GetRoomRentPerDayOninvoice: TRoomrentPerDaySetting;
begin
  result := TRoomRentPerDaySetting.FromString(GetSettingsAsString(cShowRoomRentPerDay, rpdNever.AsDB));
end;

function TPMSSettingsInvoice.GetAllowDeletingItemsFromInvoice: boolean;
begin
  Result := GetSettingsAsBoolean(cAllowDeletingItemsFromInvoice, True);
end;

function TPMSSettingsInvoice.GetAllowPaymentModification: boolean;
begin
  Result := GetSettingsAsBoolean(cAllowPaymentModifications, True);
end;

function TPMSSettingsInvoice.GetAllowTogglingOfCityTaxes: boolean;
begin
  Result := GetSettingsAsBoolean(cAllowTogglingOfCityTaxes, True);
end;

function TPMSSettingsInvoice.GetShowIncludedBreakfastOnInvoice: boolean;
begin
  Result := GetSettingsAsBoolean(cShowIncludedBreakfastOnInvoice, False);
end;

function TPMSSettingsInvoice.GetShowInvoiceAsPaidWhenStatusIsZero: boolean;
begin
  Result := GetSettingsAsBoolean(cInvoiceHandlingShowAsPaidWhenZero, False);
end;

procedure TPMSSettingsInvoice.SetAllowDeletingItemsFromInvoice(const Value: boolean);
begin
  SaveSetting(cAllowDeletingItemsFromInvoice, Value);
end;

procedure TPMSSettingsInvoice.SetAllowPaymentModification(const Value: boolean);
begin
  SaveSetting(cAllowPaymentModifications, Value);
end;

procedure TPMSSettingsInvoice.SetAllowTogglingOfCityTaxes(const Value: boolean);
begin
  SaveSetting(cAllowTogglingOfCityTaxes, Value);
end;

procedure TPMSSettingsInvoice.SetRoomRentPerDayOninvoice(const Value: TRoomrentPerDaySetting);
begin
  SaveSetting(cShowRoomRentPerDay, Value.AsDB);
end;

procedure TPMSSettingsInvoice.SetShowIncludedBreakfastOnInvoice(const Value: boolean);
begin
  SaveSetting(cShowIncludedBreakfastOnInvoice, Value);
end;

procedure TPMSSettingsInvoice.SetShowInvoiceAsPaidWhenStatusIsZero(const Value: boolean);
begin
  SaveSetting(cInvoiceHandlingShowAsPaidWhenZero, Value);
end;

{ TPMSSettingsGroup }

constructor TPMSSettingsGroup.Create(aAccessor: TPMSSettingsAccessor);
begin
  FPMSAccessor := aAccessor;
end;

procedure TPMSSettingsGroup.SaveSetting(const aKey, aValue: string; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  FPMSAccessor.SaveSetting(GetKeyGroup, aKey, aValue, aOptions);
end;

procedure TPMSSettingsGroup.SaveSetting(const aKey: string; const aValue: boolean; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  FPMSAccessor.SaveSetting(GetKeyGroup, aKey, aValue, aOptions);
end;

function TPMSSettingsGroup.GetSettingsAsBoolean(const aKey : String; aDefault : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
begin
  Result := FPMSAccessor.GetSettingsAsBoolean(GetKeyGroup, aKey, aDefault, aOptions);
end;

function TPMSSettingsGroup.GetSettingsAsInteger(const aKey: String; aDefault: Integer; aOptions: TPMSSettingsGetSetOptions): Integer;
begin
  Result := FPMSAccessor.GetSettingsAsInteger(GetKeyGroup, aKey, aDefault, aOptions);
end;

function TPMSSettingsGroup.GetSettingsAsString(const aKey: String; const aDefault: String; aOptions: TPMSSettingsGetSetOptions): String;
begin
  Result := FPMSAccessor.GetSettingsAsString(GetKeyGroup, aKey, aDefault, aOptions);
end;

procedure TPMSSettingsGroup.SaveSetting(const aKey: string; const aValue: integer; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  FPMSAccessor.SaveSetting(GetKeyGroup, aKey, aValue, aOptions);
end;

{ TPMSsettingsReservationProfile }

function TPMSSettingsReservationProfile.GetAllowAllotmentStateChange: boolean;
begin
  Result :=  GetSettingsAsBoolean(cAllowAllotmentStateChange, True);
end;

function TPMSsettingsReservationProfile.GetEditAllGuestsNationality: boolean;
begin
  Result := GetSettingsAsBoolean(cAllGuestsNationality, False);
end;

function TPMSsettingsReservationProfile.GetKeyGroup: string;
begin
  Result := cReservationProfileGroup;
end;

procedure TPMSSettingsReservationProfile.SetAllowAllotmentStateChange(const Value: boolean);
begin
  SaveSetting(cAllowAllotmentStateChange, Value);
end;

procedure TPMSsettingsReservationProfile.SetEditAllGuestsNationality(const Value: boolean);
begin
  SaveSetting(cAllGuestsNationality, Value);
end;

{ TPMSSettingsBetaFunctions }

function TPMSSettingsBetaFunctionality.GetBetaFunctionsAvailable: boolean;
begin
  Result := GetSettingsAsBoolean(cBetaFunctionsAvailableName, False);
end;

function TPMSSettingsBetaFunctionality.GetKeyGroup: string;
begin
  Result := cBetaFunctionsGroup;
end;

function TPMSSettingsBetaFunctionality.GetUseInvocieOnObjectsForm: boolean;
begin
  Result := GetSettingsAsBoolean(cBetaFunctionUseNewTaxcalcMethod, false);
end;

procedure TPMSSettingsBetaFunctionality.SetBetaFunctionsAvailable(const Value: boolean);
begin
  SaveSetting(cBetaFunctionsAvailableName, Value);
end;

procedure TPMSSettingsBetaFunctionality.SetUseInvocieOnObjectsForm(const Value: boolean);
begin
  SaveSetting(cBetaFunctionUseNewTaxcalcMethod, Value);
end;

{ TPMSPMSSpecificSettings }

function TPMSPMSSpecificSettings.GetKeyGroup: string;
begin
  Result := cUserSpecific;
end;

function TPMSPMSSpecificSettings.GetUserHomePage: Integer;
begin
  Result := GetSettingsAsInteger(cUserSpecificHomePage, 1);
end;

procedure TPMSPMSSpecificSettings.SetUserHomePage(const Value: Integer);
begin
  SaveSetting(cUserSpecificHomePage, Value);
end;

{ TRoomRentPerDaySettingHelper }

function TRoomRentPerDaySettingHelper.AsDB: string;
begin
  Result := cRoomRentPerDayStrings[Self];
end;

function TRoomRentPerDaySettingHelper.AsReadableString: string;
begin
  case Self of
    rpdNever:   Result := GetTranslatedText('shRoomRentPErDaySetting_Never');
    rpdAsk:     Result := GetTranslatedText('shRoomRentPErDaySetting_Ask');
    rpdAlways:  Result := GetTranslatedText('shRoomRentPErDaySetting_Always');
  end;
end;

class procedure TRoomRentPerDaySettingHelper.AsStrings(aItemList: TStrings);
var
  lSetting: TRoomRentPerDaySetting;
begin
  for lSetting := low(lSetting) to high(lSetting) do
    aItemList.Add(lSetting.AsReadableString);
end;

class function TRoomRentPerDaySettingHelper.FromItemIndex(aIndex: integer): TRoomRentPerDaySetting;
begin
  Result := TRoomRentPerDaySetting(aIndex);
end;

class function TRoomRentPerDaySettingHelper.FromString(const aRoomRentPerDay: string): TRoomrentPerDaySetting;
var
  lSetting: TRoomRentPerDaySetting;
begin
  Result := rpdNever;
  for lSetting := low(TRoomRentPerDaySetting) to high(TRoomRentPerDaySetting) do
    if lSetting.AsDB.equals(aRoomRentPerDay) then
    begin
      Result := lSetting;
      Break;
    end;
end;

function TRoomRentPerDaySettingHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

{ TPMSSettingsVariousOptions }

function TPMSSettingsVariousOptions.GetKeyGroup: string;
begin
  result := cVariousOptionsGroup;
end;

function TPMSSettingsVariousOptions.GetPreloadListOfPreviousGuests: boolean;
begin
  Result := GetSettingsAsBoolean(cPreloadListOfPreviousGuests, False);
end;

procedure TPMSSettingsVariousOptions.SetPreloadListOfPreviousGuests(const Value: boolean);
begin
  SaveSetting(cPreloadListOfPreviousGuests, Value);
end;

{ TPMSFinanceConnectOptions }

function TPMSFinanceConnectOptions.GetKeyGroup: string;
begin
  result := cFinanceConnectOptionsGroup;
end;

function TPMSFinanceConnectOptions.GetFinanceConnectSystemCode: String;
begin
  Result := GetSettingsAsString(cFinanceConnectSystemCode, '');
end;

procedure TPMSFinanceConnectOptions.SetFinanceConnectSystemCode(const Value: String);
begin
  SaveSetting(cFinanceConnectSystemCode, Value);
end;

end.
