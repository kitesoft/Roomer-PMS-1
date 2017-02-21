unit uPMSSettingsAccessor;

interface

uses
  cmpRoomerDataset
  , Data.DB
  , SysUtils
  ;

type

  EPMSSettingsKeyValueNotFound = class(Exception);

  TPMSSettingsGetSetOption = (psoExceptionOnNotFound, psoCreateIfNotExists);
  TPMSSettingsGetSetOptions = set of TPMSSettingsGetSetOption;

  TPMSSettingsAccessor = class
  private
    FPMSDataset: TRoomerDataset;
    FKeyGroupField: TField;
    FKeyField: TField;
    FValueField: TField;
    procedure InternalSaveSetting(const aKeyGroup, aKey, aValue: String; aOptions: TPMSSettingsGetSetOptions);
    function GetKeyField: TField;
    function GetKeyGroupField: TField;
    function GetValueField: TField;
  protected
    property ValueField: TField read GetValueField;
    property KeyField: TField read GetKeyField;
    property KeyGroupField: TField read GetKeyGroupField;
  public
    constructor Create(aPMSDataset: TRoomerDataset);

    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: string; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: boolean; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: integer; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;

    function GetSettingsAsBoolean(KeyGroup, Key : String; Default : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
    function GetSettingsAsInteger(KeyGroup, Key : String; Default : Integer = 0; aOptions: TPMSSettingsGetSetOptions = []) : Integer;
    function GetSettingsAsString(KeyGroup, Key : String; Default : String = ''; aOptions: TPMSSettingsGetSetOptions = []) : String;
  end;

implementation

uses
  Variants
  , uUtils
  ;

procedure TPMSSettingsAccessor.InternalSaveSetting(const aKeyGroup, aKey, aValue : String; aOptions: TPMSSettingsGetSetOptions);
begin
  if FPMSDataset.Locate('KeyGroup;key', VarArrayOf([aKeyGroup, aKey]), [loCaseInsensitive]) then
  begin
    FPMSDataset.Edit;
    try
      ValueField.AsString := aValue;
      FPMSDataset.Post;
    except
      FPMSDataset.Cancel;
      raise;
    end;
  end else
  if (psoCreateIfNotExists in aOptions) then
  begin
    FPMSDataset.Insert;
    try
      KeyGroupField.AsString := aKeyGroup;
      KeyField.AsString := aKey;
      ValueField.AsString := aValue;
      FPMSDataset.Post;
    except
      FPMSDataset.Cancel;
      raise;
    end;
  end;
end;

constructor TPMSSettingsAccessor.Create(aPMSDataset: TRoomerDataset);
begin
  FPMSDataset := aPMSDataset;
end;

function TPMSSettingsAccessor.GetKeyField: TField;
begin
  if not assigned(FKeyField) then
    FKeyField :=  FPMSDataset.FieldByName('Key');
  Result := FKeyField;
end;

function TPMSSettingsAccessor.GetKeyGroupField: TField;
begin
  if not assigned(FKeyGroupField) then
    FKeyGroupField :=  FPMSDataset.FieldByName('KeyGroup');
  Result := FKeyGroupField;
end;

function TPMSSettingsAccessor.GetSettingsAsBoolean(KeyGroup, Key : String; Default : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
begin
  result := Default;
  if FPMSDataset.Locate('KeyGroup;key', VarArrayOf([KeyGroup, Key]), []) then
    result := ValueField.AsString = 'TRUE'
  else
    if (psoExceptionOnNotFound in aOptions)then
      raise EPMSSettingsKeyValueNotFound.Create('Key ' + Key + ' was not found in settings.');
end;

function TPMSSettingsAccessor.GetSettingsAsInteger(KeyGroup, Key : String; Default : Integer = 0; aOptions: TPMSSettingsGetSetOptions = []) : Integer;
begin
  result := Default;
  if FPMSDataset.Locate('KeyGroup;key', VarArrayOf([KeyGroup, Key]), []) then
    result := StrToIntDef(ValueField.AsString, Default)
  else
    if (psoExceptionOnNotFound in aOptions)then
      raise EPMSSettingsKeyValueNotFound.Create('Key ' + Key + ' was not found in settings.');
end;

function TPMSSettingsAccessor.GetSettingsAsString(KeyGroup, Key : String; Default : String = ''; aOptions: TPMSSettingsGetSetOptions = []) : String;
begin
  result := Default;
  if FPMSDataset.Locate('KeyGroup;key', VarArrayOf([KeyGroup, Key]), []) then
    result := ValueField.AsString
  else
    if (psoExceptionOnNotFound in aOptions)then
      raise EPMSSettingsKeyValueNotFound.Create('Key ' + Key + ' was not found in settings.');
end;


function TPMSSettingsAccessor.GetValueField: TField;
begin
  if not assigned(FValueField) then
    FValueField :=  FPMSDataset.FieldByName('Value');
  Result := FValueField;
end;

procedure TPMSSettingsAccessor.SaveSetting(const aKeyGroup, aKey: string; aValue: string; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  InternalSaveSetting(aKeyGroup, aKey, aValue, aOptions);
end;

procedure TPMSSettingsAccessor.SaveSetting(const aKeyGroup, aKey: string; aValue: boolean; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  InternalSaveSetting(aKeyGroup, aKey, IIF(aValue, 'TRUE', 'FALSE'), aOptions);
end;

procedure TPMSSettingsAccessor.SaveSetting(const aKeyGroup, aKey: string; aValue: integer; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]);
begin
  InternalSaveSetting(aKeyGroup, aKey, IntToStr(aValue), aOptions);
end;

end.
