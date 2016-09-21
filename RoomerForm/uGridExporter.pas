unit uGridExporter;

interface

uses
    cxGrid
  ;

type

  TGridExporterOption = (geOpenFile);
  TGridExporterOptions = set of TGridExporterOption;

  TGridExporter = class(TObject)
  private
    FcxGrid: TcxGrid;
  public
    constructor Create(aGrid: TcxGrid);

    procedure ExportToXLS(aOptions: TGridExporterOptions);
  end;

implementation

uses
    cxGridExportLink
  , ShellApi
  ;


{ TGridExporter }

constructor TGridExporter.Create(aGrid: TcxGrid);
begin
  FcxGrid := aGrid;
end;

procedure TGridExporter.ExportToXLS(aOptions: TGridExporterOptions);
var
  lFilename : string;
  s         : string;
  c : char;
const
  cFilenameReplaceChar: char = '_';
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFileName := TPath.Combine(g.qProgramPath, s);

  s := Caption;
  for c in Caption do
    if not TPath.IsValidFileNameChar(c) then
      s := s.Replace(c, cFilenameReplaceChar);

  sFilename := sFileName + s;
  ExportGridToExcel(sFilename, FcxGrid, true, true, true);

  if geOpenFile in aOptions then
    ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

end.
