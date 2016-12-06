unit uUpgraderCmdlineOptions;

interface

type
  TUpgraderCmdlineOptions = class
  private
    class var FRoomerStoreURL: string;
    class var FExeName: string;
    class var FSkipClearLanguages: boolean;
    class var FSkipClearCache: boolean;
    class function GetExeName: string; static;
    class function GetRoomerStoreURL: string; static;
    class procedure SetRoomerStoreURL(const Value: string); static;
  protected
    const cDefaultURL = 'http://roomerstore.com/';
  public
    class property RoomerStoreURL: string read GetRoomerStoreURL write SetRoomerStoreURL;
    class property ExeName: string read GetExeName write FExeName;
    class property SkipClearLanguages: boolean read FSkipClearLanguages write FSkipClearLanguages;
    class property SkipClearCache: boolean read FSkipClearCache write FSkipClearCache;
    class function ParseCommandLine: boolean;
  end;

implementation

uses
  VSoft.Commandline.Options,
  Dialogs,
  SysUtils,
  UITypes
  ;

class function TUpgraderCmdlineOptions.GetExeName: string;
begin
  Result := FExeName;
end;

class function TUpgraderCmdlineOptions.GetRoomerStoreURL: string;
begin
  if FRoomerStoreURL.IsEmpty then
    Result := cDefaultURL
  else
    Result := FRoomerStoreURL;
end;

class function TUpgraderCmdlineOptions.ParseCommandLine: boolean;
var
  ParsedCmd: ICommandLineParseResult;
  Msg: TStringbuilder;
begin
  ParsedCmd := TOptionsRegistry.Parse;
  result := not parsedCmd.HasErrors;

  if ParsedCmd.HasErrors then
  begin
    Msg := TStringBuilder.Create;
    try
      Msg.Append('Error: ' + ParsedCmd.ErrorText + #10);
      Msg.Append( 'Usage: ');
      TOptionsRegistry.PrintUsage(
        procedure(const value: string)
        begin
          Msg.Append(Value + #10);
        end);
        ShowMessage(Msg.ToString);
    finally
      Msg.Free;
    end;
  end;
end;

class procedure TUpgraderCmdlineOptions.SetRoomerStoreURL(const Value: string);
begin
  if not Value.EndsWith('/') then
    FRoomerStoreURL := Value + '/'
  else
    FRoomerStoreURL := Value;
end;

procedure ConfigureCommandlineOptions;
var
  option : IOptionDefintion;
begin
  option := TOptionsRegistry.RegisterOption<string>('executable', 'e', 'Full path to Executable to be replaced with download',
    procedure(const value : string)
    begin
        TUpgraderCmdlineOptions.ExeName := value;
    end);
  option.Required := True;

  option := TOptionsRegistry.RegisterOption<string>('store','s','URL of roomerstore, defaults to http://roomerstore.com/',
    procedure(const value : string)
    begin
      TUpgraderCmdlineOptions.RoomerStoreURL :=  value
    end);
  option.Required := false;

  option := TOptionsRegistry.RegisterOption<boolean>('noclrlang', 'l', 'Skip clearing all language files, default False',
    procedure(const value : boolean)
    begin
        TUpgraderCmdlineOptions.SkipClearLanguages := value;
    end);
  option.Required := False;

  option := TOptionsRegistry.RegisterOption<boolean>('noclrcache', 'c', 'Skip clearing the data cache, default False',
    procedure(const value : boolean)
    begin
        TUpgraderCmdlineOptions.SkipClearCache := value;
    end);
  option.Required := False;
end;

initialization
  ConfigureCommandLineOptions;

end.
