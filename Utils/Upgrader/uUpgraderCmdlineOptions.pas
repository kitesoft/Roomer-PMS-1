unit uUpgraderCmdlineOptions;

interface

type
  TUpgraderCmdlineOptions = class
  protected
    const cDefaultURL = ' http://roomerstore.com/';
  public
    class var RoomerStoreURL: string;
    class var ExeName: string;
    class var SkipClearLanguages: boolean;
    class var SkipClearCache: boolean;

    class function ParseCommandLine: boolean;
  end;

implementation

uses
  VSoft.Commandline.Options,
  Dialogs,
  SysUtils,
  UITypes
  ;

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
      if value <> '' then
        TUpgraderCmdlineOptions.RoomerStoreURL :=  value
      else
        TUpgraderCmdlineOptions.RoomerStoreURL := TUpgraderCmdlineOptions.cDefaultURL;

      if not TUpgraderCmdlineOptions.RoomerStoreURL.EndsWith('/') then
        TUpgraderCmdlineOptions.RoomerStoreURL := TUpgraderCmdlineOptions.RoomerStoreURL + '/';
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
