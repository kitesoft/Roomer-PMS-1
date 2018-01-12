unit uRoomerGridExporters;

interface

uses
  cxGrid
  , VCL.Menus
  ;

type
  TRoomerGridExporters = class
  private
    FmnuExportMenu: TMenuItem;
    FmnuiGridToExcel: TMenuItem;
    FmnuiGridToHtml: TMenuItem;
    FmnuiGridToText: TMenuItem;
    FmnuiGridToXml: TMenuItem;
    FCaption: string;
    FGrid: TcxGrid;

    procedure mnuiGridToExcelClick(Sender: TObject);
    procedure mnuiGridToHtmlClick(Sender: TObject);
    procedure mnuiGridToTextClick(Sender: TObject);
    procedure mnuiGridToXmlClick(Sender: TObject);
    procedure ConstructMenu;
  public
    constructor Create(aGrid: TcxGrid; const aCaption: string = '');
    destructor Destroy; override;

    procedure ExportToExcel;
    procedure ExportToHtml;
    procedure ExportToText;
    procedure ExportToXml;
    property ExportSubMenu: TMenuItem read FmnuExportMenu;
    property Caption: string read FCaption write FCaption;
  end;

implementation

uses
  uG
  , cxGridExportLink
  , ShellApi
  , PrjConst
  , VCL.Forms
  , Windows
  ;

constructor TRoomerGridExporters.Create(aGrid: TcxGrid; const aCaption: string = '');
begin
  FGrid := aGrid;
  FCaption := aCaption;
  ConstructMenu;
end;

destructor TRoomerGridExporters.Destroy;
begin
  inherited;
  FmnuExportMenu.Free;
end;

procedure TRoomerGridExporters.ExportToExcel;
begin
  FmnuiGridToExcel.Click;
end;

procedure TRoomerGridExporters.ExportToHtml;
begin
  FmnuiGridToHtml.Click;
end;

procedure TRoomerGridExporters.ExportToText;
begin
  FmnuiGridToText.Click;
end;

procedure TRoomerGridExporters.ExportToXml;
begin
  FmnuiGridToXml.Click;
end;

procedure TRoomerGridExporters.ConstructMenu;
begin
  FmnuExportMenu := TMenuItem.Create(nil);
  FmnuiGridToExcel := TMenuItem.Create(nil);
  FmnuiGridToHtml := TMenuItem.Create(nil);
  FmnuiGridToText := TMenuItem.Create(nil);
  FmnuiGridToXml := TMenuItem.Create(nil);

  FmnuExportMenu.Caption := GetTranslatedText('shExportMenuCaption');

  with FmnuiGridToExcel do
  begin
    Caption := 'Excel';
    OnClick := mnuiGridToExcelClick;
  end;
  with FmnuiGridToHtml do
  begin
    Caption := 'Html';
    OnClick := mnuiGridToHtmlClick;
  end;
  with FmnuiGridToText do
  begin
    Caption := 'Text';
    OnClick := mnuiGridToTextClick;
  end;
  with FmnuiGridToXml do
  begin
    Caption := 'XML';
    OnClick := mnuiGridToXmlClick;
  end;

  FmnuExportMenu.Add(FmnuiGridToExcel);
  FmnuExportMenu.Add(FmnuiGridToHtml);
  FmnuExportMenu.Add(FmnuiGridToText);
  FmnuExportMenu.Add(FmnuiGridToXml);
end;

procedure TRoomerGridExporters.mnuiGridToExcelClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToExcel(sFilename, FGrid, true, true, true);
  ShellExecute(Application.Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TRoomerGridExporters.mnuiGridToHtmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToHtml(sFilename, FGrid, true, true);
  ShellExecute(Application.Handle, 'OPEN', PChar(sFilename + '.html'), nil, nil, sw_shownormal);
end;

procedure TRoomerGridExporters.mnuiGridToTextClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToText(sFilename, FGrid, true, true,';','','','txt');
  ShellExecute(Application.Handle, 'OPEN', PChar(sFilename + '.txt'), nil, nil, sw_shownormal);
end;

procedure TRoomerGridExporters.mnuiGridToXmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToXml(sFilename, FGrid, true, true);
  ShellExecute(Application.Handle, 'OPEN', PChar(sFilename + '.xml'), nil, nil, sw_shownormal);
end;

end.



