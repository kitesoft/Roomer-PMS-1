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
    function GetKeyField: TField;
    function GetKeyGroupField: TField;
    function GetValueField: TField;
  protected
    procedure InternalSaveSetting(const aKeyGroup, aKey, aValue: String; aOptions: TPMSSettingsGetSetOptions); virtual;
    function InternalGetSetting(const aKeyGroup, aKey: String; aOptions: TPMSSettingsGetSetOptions; var aSetting: string): boolean; virtual;
    // Optimized access to ValueField in PMSDataset
    property ValueField: TField read GetValueField;
    // Optimized access to KeyField in PMSDataset
    property KeyField: TField read GetKeyField;
    // Optimized access to KeyGroupField in PMSDataset
    property KeyGroupField: TField read GetKeyGroupField;
  public
    constructor Create(aPMSDataset: TRoomerDataset); virtual;

    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: string; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: boolean; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;
    procedure SaveSetting(const aKeyGroup, aKey: string; aValue: integer; aOptions: TPMSSettingsGetSetOptions = [psoCreateIfNotExists]); overload;

    function GetSettingsAsBoolean(const KeyGroup, Key : String; Default : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
    function GetSettingsAsInteger(const KeyGroup, Key : String; Default : Integer = 0; aOptions: TPMSSettingsGetSetOptions = []) : Integer;
    function GetSettingsAsString(const KeyGroup, Key : String; Default : String = ''; aOptions: TPMSSettingsGetSetOptions = []) : String;
  end;

implementation

uses
  Variants
  , uUtils
  , hData
  , Classes
  , uSQLUtils;

function TPMSSettingsAccessor.InternalGetSetting(const aKeyGroup, aKey: String; aOptions: TPMSSettingsGetSetOptions; var aSetting: string): boolean;
begin
  Result := FPMSDataset.Locate('KeyGroup;key', VarArrayOf([aKeyGroup, aKey]), []);
  if Result then
    aSetting := ValueField.AsString
  else
    if (psoExceptionOnNotFound in aOptions)then
      raise EPMSSettingsKeyValueNotFound.Create('Key ' + aKey + ' was not found in settings.');
end;

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

function TPMSSettingsAccessor.GetSettingsAsBoolean(const KeyGroup, Key : String; Default : Boolean = False; aOptions: TPMSSettingsGetSetOptions = []) : Boolean;
var
  lSetting: string;
begin
  if InternalGetSetting(KeyGroup, Key, aOptions, lSetting) then
    Result := lSetting.ToUpper.Equals('TRUE')
  else
    result := Default;
end;

function TPMSSettingsAccessor.GetSettingsAsInteger(const KeyGroup, Key : String; Default : Integer = 0; aOptions: TPMSSettingsGetSetOptions = []) : Integer;
var
  lSetting: string;
begin
  if InternalGetSetting(KeyGroup, Key, aOptions, lSetting) then
    Result := StrToIntDef(lSetting, Default)
  else
    result := Default;
end;

function TPMSSettingsAccessor.GetSettingsAsString(const KeyGroup, Key : String; Default : String = ''; aOptions: TPMSSettingsGetSetOptions = []) : String;
begin
  if not InternalGetSetting(KeyGroup, Key, aOptions, Result) then
    result := Default;
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
