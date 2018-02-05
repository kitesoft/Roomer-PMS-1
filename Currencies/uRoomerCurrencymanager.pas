unit uRoomerCurrencymanager;

interface

uses
  uCurrencymanager
  , uCurrencyConstants
  , uCurrencyDefinition
  , uRoomerCurrencyDefinition
  , uTableEntityList
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
    constructor Create(const aDefaultCurrency: TCurrencyCode); override;

    procedure UpdateDefinitions(aTable: TCachedTableEntity);

    property DefaultCurrencyDefinition: TRoomerCurrencyDefinition read GetDefaultDefinition;
    property CurrencyDefinition[const CurCode: TCurrencyCode]: TRoomerCurrencyDefinition read GetDefinition; default;
  end;

function RoomerCurrencyManager: TRoomerCurrencyManager;


implementation

uses
    Data.DB
  , uAppGLobal
  , uG
  , Math
  , cmpRoomerDataset
  ;

function RoomerCurrencyManager: TRoomerCurrencyManager;
begin
  if not assigned(CurrencyManager(True)) or not (Currencymanager is TRoomerCurrencyManager) then
  begin
    InitGlobalCurrencyManager(TRoomerCurrencymanager, '   ');
  end;
  Result := Currencymanager as TRoomerCurrencyManager;
end;

{ TRoomerCurrencyManager }

constructor TRoomerCurrencyManager.Create;
begin
  inherited ;
  glb.TableList['currencies'].OnRefresh := UpdateDefinitions;
  UpdateDefinitions(glb.TableList['currencies']);
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
  Result := inherited CurrencyDefinition[CurCode] as TRoomerCurrencyDefinition
end;

procedure TRoomerCurrencyManager.UpdateDefinitions(aTable: TCachedTableEntity);
var
  ds: TRoomerDataset;
  bm: TBookmark;
  lCurDef: TCurrencyDefinition;
begin
  ds := aTable.RSet;

  Lock;
  try
    ClearDefinitions;
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
                lCurDef := CreateDefinition(TCurrencyCode(fieldByName('currency').asString), fieldByName('ID').asInteger);
                lCurDef.Description := fieldByName('description').asString;
              end;
              Next;
            end;
            DefaultCurrency := TCurrencyCode(glb.ControlSet.fieldByname('nativecurrency').AsString);
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
