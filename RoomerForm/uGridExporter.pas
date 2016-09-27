unit uGridExporter;

interface

uses
    cxGrid
  , SysUtils
  ;

type
  EGridExporterException = class(Exception);

  TGridExporterFormat = (gfXLS, gfXLSX, gfTXT, gfHTML, gfXML);

  TGridExporterOption = (geOpenFile);
  TGridExporterOptions = set of TGridExporterOption;

  /// <summary>
  ///   Class to export a grid with data to several file formats. <br />
  ///  On creation the exporter is bound to a specific grid (at the moment only TcxGrid but expansion possible)
  /// </summary>
  TGridExporter = class(TObject)
  private
    FcxGrid: TcxGrid;
    function AskFileName(const aBaseFileName: string): string;
    function MakeValidFileName(const aFileName: string): string;
  public
    constructor Create(aGrid: TcxGrid);

    procedure ExportToXLS(const aBaseFileName: string; aOptions: TGridExporterOptions);
  end;

implementation

uses
    cxGridExportLink
  , ShellApi
  , VCL.Dialogs
  , VCL.Forms
  , WinAPI.Windows
  , IOUtils
  , DateUtils
  , uDateTimeHelper
  , uG
  ;


{ TGridExporter }

function TGridExporter.AskFileName(const aBaseFileName: string): string;
var
  lDialog: TSaveDialog;
begin
  Result := '';
  lDialog := TSaveDialog.Create(nil);
  try
    lDialog.FileName := aBaseFileName;
    lDialog.InitialDir := g.qProgramPath;
    lDialog.DefaultExt := '.xls';
    lDialog.Options := lDialog.Options + [ofOverwritePrompt];

    if lDialog.Execute then
      Result := lDialog.FileName;
  finally
    lDialog.Free;
  end;
end;

constructor TGridExporter.Create(aGrid: TcxGrid);
begin
  FcxGrid := aGrid;
end;

procedure TGridExporter.ExportToXLS(const aBaseFileName: string; aOptions: TGridExporterOptions);
var
  lFilename : string;
const
  cFilenameReplaceChar: char = '_';
begin
  try
    lFileName := AskFileName( MakeValidFileName(aBaseFileName) + TDateTime.Now.ToString('yyyymmddhhnn'));
    if not lFileName.IsEmpty then
    begin
      ExportGridToExcel(lFileName, FcxGrid, true, true, true);

      if geOpenFile in aOptions then
        ShellExecute(Application.Handle, 'OPEN', PChar(lFilename), nil, nil, sw_shownormal);
    end;
  except
    on E: Exception do
    begin
      raise EGridExporterException.CreateFmt('Error during exporting of grid to Excel:'+ #10 + '%s', [E.Message]);
    end;

  end;
end;

function TGridExporter.MakeValidFileName(const aFileName: string): string;
var
  c: char;
begin
  Result := '';
  for c in aFileName do
    if TPath.IsValidFilenameChar(c) then
      Result := Result + c;
end;

end.
