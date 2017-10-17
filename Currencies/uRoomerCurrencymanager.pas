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
    constructor Create; overload; override;

    procedure UpdateDefinitions(Sender: TObject);

    property DefaultCurrencyDefinition: TRoomerCurrencyDefinition read GetDefaultDefinition;
    property CurrencyDefinition[const CurCode: TCurrencyCode]: TRoomerCurrencyDefinition read GetDefinition;
  end;

function RoomerCurrencyManager: TRoomerCurrencyManager;


implementation

uses
    Data.DB
  , uAppGLobal
  , uG
  , Math
  ;

function RoomerCurrencyManager: TRoomerCurrencyManager;
begin
  if not assigned(CurrencyManager(True)) or not (Currencymanager is TRoomerCurrencyManager) then
  begin
    InitGlobalCurrencyManager(TRoomerCurrencymanager);
  end;
  Result := Currencymanager as TRoomerCurrencyManager;
end;

{ TRoomerCurrencyManager }

constructor TRoomerCurrencyManager.Create;
begin
  inherited ;
  if glb.TableList.ContainsKey('currencies') then
    glb.TableList['currencies'].RSet.DataSource.OnStateChange := (Currencymanager as TRoomerCurrencyManager).UpdateDefinitions;
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
var
  ds: TDataset;
  bm: TBookmark;
begin
  ds := (Sender as TDataSource).dataset;

  Lock;
  try
    ClearCache;
    if assigned(ds) and (ds.State = dsBrowse) then
      with ds do
        if Active then
        begin
          bm := ds.Bookmark;
          DisableControls;
          try
            First;
            while not Eof do
            begin
              if fieldbyName('active').asBoolean then
              begin
                CreateDefinition(fieldByName('currency').asString, fieldByName('ID').asInteger);
                if SameValue(fieldByName('rate').AsFLoat, 1.0, 0.01) then
                  DefaultCurrency := fieldByName('currency').asString;
              end;
              Next;
            end;
            DefaultCurrency := g.qNativeCurrency;
          finally
            BookMark := bm;
            EnableControls;
          end;
        end;
  finally
    Unlock;
  end;
end;

initialization

finalization

end.
