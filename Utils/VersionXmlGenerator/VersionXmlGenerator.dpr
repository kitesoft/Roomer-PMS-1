program VersionXmlGenerator;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,
  uVersionXml in 'uVersionXml.pas';

begin
  try
    { TODO -oUser -cConsole Main : Insert code here }
    GenerateXml(ParamStr(1), StrToIntDef(Paramstr(2), 2880));
  except
    on E: Exception do
      Writeln(E.ClassName, ': ', E.Message);
  end;
end.
