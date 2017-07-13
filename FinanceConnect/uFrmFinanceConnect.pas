unit uFrmFinanceConnect;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics, System.Generics.Collections,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ComCtrls, sPageControl, Vcl.ExtCtrls, sPanel, sTabControl, cxGraphics, cxControls, cxLookAndFeels,
  cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter,
  cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, cxGridLevel, cxClasses, cxGridCustomView, cxGridCustomTableView,
  cxGridTableView, cxGridDBTableView, cxGrid, Vcl.Controls, kbmMemTable,
  cmpRoomerDataSet,
  uDImages, cxButtonEdit;

type

  TLookUpPair = class
  private
    FName: String;
    FCode: String;
  public
    constructor Create(_Code, _Name : String);
    property Code : String read FCode;
    property Name : String read FName;
  end;

  TFrmFinanceConnect = class(TForm)
    pgMain: TsPageControl;
    sTabSheet1: TsTabSheet;
    sTabSheet2: TsTabSheet;
    tabsMappings: TsTabControl;
    pnl0: TsPanel;
    tvList: TcxGridDBTableView;
    glList: TcxGridLevel;
    grList: TcxGrid;
    memCustomers: TkbmMemTable;
    dsCustomers: TDataSource;
    tvListCode: TcxGridDBColumn;
    tvListName: TcxGridDBColumn;
    tvListExternalCode: TcxGridDBColumn;
    memItems: TkbmMemTable;
    dsItems: TDataSource;
    memVats: TkbmMemTable;
    dsVats: TDataSource;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure tabsMappingsChange(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    FCustomers : TObjectList<TLookUpPair>;
    FItems : TObjectList<TLookUpPair>;
    FVats : TObjectList<TLookUpPair>;
  private
    procedure LoadInfo;
    procedure PrepareTabs;
    procedure LoadSet(rSet: TRoomerDataSet; mem: TkbmMemTable; CodeField, NameField, MappedField);
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmFinanceConnect: TFrmFinanceConnect;

implementation

{$R *.dfm}

uses uAppGlobal
    ;

const TAB_CUSTOMERS = 0;
      TAB_ITEMS = 1;
      TAB_VATS = 2;

procedure TFrmFinanceConnect.FormCreate(Sender: TObject);
begin
  FCustomers := TObjectList<TLookUpPair>.Create;
  FItems := TObjectList<TLookUpPair>.Create;
  FVats := TObjectList<TLookUpPair>.Create;
  pgMain.ActivePageIndex := 0;
end;

procedure TFrmFinanceConnect.FormDestroy(Sender: TObject);
begin
  FCustomers.Free;
  FItems.Free;
  FVats.Free;
end;

procedure TFrmFinanceConnect.FormShow(Sender: TObject);
begin
  LoadInfo;
end;

procedure TFrmFinanceConnect.tabsMappingsChange(Sender: TObject);
begin
  tvList.DataController.DataSource.DataSet.Active := False;
  case tabsMappings.TabIndex of
    TAB_CUSTOMERS : begin
                      tvList.DataController.DataSource := dsCustomers;
                    end;
    TAB_ITEMS     : begin
                      tvList.DataController.DataSource := dsItems;
                    end;
    TAB_VATS      : begin
                      tvList.DataController.DataSource := dsVats;
                    end;
  end;
  tvList.DataController.DataSource.DataSet.Active := False;
end;

//////////////////////////////////////////// Methods ///////////////////////////////////////////////

procedure TFrmFinanceConnect.LoadInfo;
var rSet : TRoomerDataSet;
begin
 //
  LoadSet(glb.CustomersSet, memCustomers, 'Customer', 'Surname', 'PID');
  LoadSet(glb.Items, memItems, 'Item', 'Description', 'BookKeepCode');
  LoadSet(glb.VAT, memVats, 'VATCode', 'Description', 'BookKeepCode');
end;

procedure TFrmFinanceConnect.LoadSet(rSet : TRoomerDataSet; mem : TkbmMemTable; CodeField, NameField, MappedField);
var Code : String;
    Name : String;
    External : String;
begin
 //
  rSet.First;
  mem.DisableControls;
  try
    while Not rSet.Eof do
    begin
      mem.Insert;
      mem['Code'] := rSet[CodeField];
      mem['Name'] := rSet[NameField];
      mem['ExternalCode'] := rSet[MappedField];
      mem.Post;

      rSet.Next;
    end;
  finally
    mem.EnableControls;
  end;
end;

procedure TFrmFinanceConnect.PrepareTabs;
begin
 //
  tabsMappings.TabIndex := 0;
  tabsMappingsChange(tabsMappings);
end;

{ TLookUpPair }

constructor TLookUpPair.Create(_Code, _Name: String);
begin
  FCode := _Code;
  FName := _Name;
end;

end.
