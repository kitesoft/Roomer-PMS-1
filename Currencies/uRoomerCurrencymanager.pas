unit uRoomerCurrencymanager;

interface

uses
  uCurrencymanager
  , uCurrencyConstants
  , uCurrencyDefinition
  , uRoomerCurrencyDefinition
  ;

type
  /// <summary>
  ///   Implementation of TCurrencymanager that uses the TGlobalSettings.CurrenciesSet dataset to populate the
  ///   dictionary with active definitions
  /// </summary>
  TRoomerCurrencyManager = class(TCurrencyManager)
  private
    function GetDefinition(const CurCode: TCurrencyCode): TRoomerCurrencyDefinition;
    function GetDefaultDefinition: TRoomerCurrencyDefinition;
  protected
    function CurrencyDefinitionClass: TCurrencyDefinitionClass; override;

  public
    constructor Create; override;

    procedure UpdateDefinitions(Sender: TObject);

    property DefaultCurrencyDefinition: TRoomerCurrencyDefinition read GetDefaultDefinition;
    property CurrencyDefinition[const CurCode: TCurrencyCode]: TRoomerCurrencyDefinition read GetDefinition;
  end;

function RoomerCurrencyManager: TRoomerCurrencyManager;


implementation

uses
    uAppGLobal
  , uG;

function RoomerCurrencyManager: TRoomerCurrencyManager;
begin
  if not assigned(CurrencyManager(True)) then
  begin
    InitGlobalCurrencyManager(TRoomerCurrencymanager);
    glb.TableEntity['currencies'].OnDataChanged := (Currencymanager as TRoomerCurrencyManager).UpdateDefinitions;
  end;
  Result := Currencymanager as TRoomerCurrencyManager;
end;
{ TRoomerCurrencyManager }

constructor TRoomerCurrencyManager.Create;
begin
  inherited;
  UpdateDefinitions(nil);
end;

function TRoomerCurrencyManager.CurrencyDefinitionClass: TCurrencyDefinitionClass;
begin
  Result := TRoomerCurrencyDefinition;
end;


function TRoomerCurrencyManager.GetDefaultDefinition: TRoomerCurrencyDefinition;
begin
  Result := inherited GetDefaultCurrencydefinition as TRoomerCurrencyDefinition;
end;

function TRoomerCurrencyManager.GetDefinition(const CurCode: TCurrencyCode): TRoomerCurrencyDefinition;
begin
  Result := inherited CurrencyDefinition[CurCode] as TRoomerCurrencyDefinition;
end;

procedure TRoomerCurrencyManager.UpdateDefinitions(Sender: TObject);
begin
  Lock;
  try
    ClearCache;
    with glb.CurrenciesSet do
      if Active then
      begin
        DisableControls;
        try
          First;
          while not Eof do
          begin
            if fieldbyName('active').asBoolean then
              CreateDefinition(fieldByName('currency').asString);
            Next;
          end;
          DefaultCurrency := g.qNativeCurrency;
        finally
          EnableControls;
        end;
      end;
  finally
    Unlock;
  end;
end;

end.
