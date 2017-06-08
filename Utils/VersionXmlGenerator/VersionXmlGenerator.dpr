program VersionXmlGenerator;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,
  uVersionXml in 'uVersionXml.pas',
  XmlUtils in '..\..\RoomerUtils\XmlUtils.pas';

procedure WriteHelp;
begin
  writeln;
  writeln('Incorrect number of command line parameters.');
  writeln('  parameter 1 = directory (i.e. ".")');
  writeln('  parameter 2 = TTL value');
  writeln('  parameter 3 = Path and name of XML file');
  writeln('  parameter 4 = Only MD5 (true/false)?');
  writeln;
  writeln('Example:');
  writeln('  VersionXmlGenerator . 2880 .\Roomer.xml false');
  writeln;
end;

begin
  try
    { TODO -oUser -cConsole Main : Insert code here }
    if ParamCount <> 4 then
      WriteHelp
    else
      GenerateXml(ParamStr(1), StrToIntDef(Paramstr(2), 2880), Paramstr(3), LowerCase(Paramstr(4)) = 'true');
  except
    on E: Exception do
      Writeln(E.ClassName, ': ', E.Message);
  end;
end.
