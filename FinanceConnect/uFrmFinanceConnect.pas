unit uFrmFinanceConnect;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics, System.Generics.Collections,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ComCtrls, sPageControl, Vcl.ExtCtrls, sPanel, sTabControl, cxGraphics, cxControls, cxLookAndFeels,
  cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter,
  cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, cxGridLevel, cxClasses, cxGridCustomView, cxGridCustomTableView,
  cxGridTableView, cxGridDBTableView, cxGrid,
  cmpRoomerDataSet, uRoomerForm, uD, uFinanceConnectService,
  uDImages, cxButtonEdit, dxmdaset, Vcl.StdCtrls, sComboBox, sLabel, sEdit, sCheckBox, sMemo, sButton;

type

  TFrmFinanceConnect = class(TfrmBaseRoomerForm)
    pgMain: TsPageControl;
    sTabSheet1: TsTabSheet;
    sTabSheet2: TsTabSheet;
    tabsMappings: TsTabControl;
    pnl0: TsPanel;
    tvCustomers: TcxGridDBTableView;
    glCustomers: TcxGridLevel;
    grCustomers: TcxGrid;
    memCustomers: TdxMemData;
    dsCustomers: TDataSource;
    tvCustomersCode: TcxGridDBColumn;
    tvCustomersName: TcxGridDBColumn;
    tvCustomersExternalCode: TcxGridDBColumn;
    pnl1: TsPanel;
    grItems: TcxGrid;
    tvItems: TcxGridDBTableView;
    cxGridDBColumn1: TcxGridDBColumn;
    cxGridDBColumn2: TcxGridDBColumn;
    cxGridDBColumn3: TcxGridDBColumn;
    glItems: TcxGridLevel;
    pnl2: TsPanel;
    grVats: TcxGrid;
    tvVats: TcxGridDBTableView;
    cxGridDBColumn4: TcxGridDBColumn;
    cxGridDBColumn5: TcxGridDBColumn;
    cxGridDBColumn6: TcxGridDBColumn;
    glVats: TcxGridLevel;
    memItems: TdxMemData;
    dsItems: TDataSource;
    memVats: TdxMemData;
    dsVats: TDataSource;
    memCustomersCode: TWideStringField;
    memCustomersName: TWideStringField;
    memCustomersExternalCode: TWideStringField;
    memItemsCode: TWideStringField;
    memItemsName: TWideStringField;
    memItemsExternalCode: TWideStringField;
    memVatsCode: TWideStringField;
    memVatsName: TWideStringField;
    memVatsExternalCode: TWideStringField;
    sLabel1: TsLabel;
    cbxSystemSelection: TsComboBox;
    cbxActive: TsCheckBox;
    sLabel2: TsLabel;
    edServiceUrl: TsEdit;
    sLabel3: TsLabel;
    edUsername: TsEdit;
    sLabel4: TsLabel;
    edPassword: TsEdit;
    sLabel5: TsLabel;
    edOrg: TsEdit;
    sLabel6: TsLabel;
    edOffice: TsEdit;
    sLabel7: TsLabel;
    edCompany: TsEdit;
    sLabel8: TsLabel;
    edSalesCode: TsEdit;
    sLabel9: TsLabel;
    sLabel10: TsLabel;
    edCashCode: TsEdit;
    sLabel11: TsLabel;
    edCashAccount: TsEdit;
    sLabel12: TsLabel;
    edReceivableAccount: TsEdit;
    sLabel13: TsLabel;
    edPreInvoiceNumber: TsEdit;
    sLabel14: TsLabel;
    edSuccInvoiceNumber: TsEdit;
    sButton1: TsButton;
    sMemo1: TsMemo;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure tabsMappingsChange(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure tvListExternalCodePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure sButton1Click(Sender: TObject);
  private
    FinanceConnectService : TFinanceConnectService;
    procedure LoadInfo;
    procedure PrepareTabs;
    procedure LoadSet(rSet: TRoomerDataSet; KeyPairType : TKeyPairType; mem: TdxMemData; CodeField, NameField, MappedField : String);
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmFinanceConnect: TFrmFinanceConnect;

procedure ManageFinanceConnect;

implementation

{$R *.dfm}

uses uAppGlobal,
     uFrmKeyPairSelector
    ;

const TAB_CUSTOMERS = 0;
      TAB_ITEMS = 1;
      TAB_VATS = 2;

procedure ManageFinanceConnect;
var _FrmFinanceConnect : TFrmFinanceConnect;
begin
  _FrmFinanceConnect := TFrmFinanceConnect.Create(nil);
  try
    _FrmFinanceConnect.ShowModal;
  finally
    FreeAndNil(_FrmFinanceConnect);
  end;
end;

procedure TFrmFinanceConnect.FormCreate(Sender: TObject);
begin
  inherited;
  pgMain.ActivePageIndex := 0;
  FinanceConnectService := TFinanceConnectService.Create;
  FinanceConnectService.PrepareForMapping;
end;

procedure TFrmFinanceConnect.FormDestroy(Sender: TObject);
begin
  inherited;
  FinanceConnectService.Free;
end;

procedure TFrmFinanceConnect.FormShow(Sender: TObject);
begin
  inherited;
  LoadInfo;
  PrepareTabs;
end;

procedure TFrmFinanceConnect.tabsMappingsChange(Sender: TObject);
begin
  pnl0.Visible := tabsMappings.TabIndex = TAB_CUSTOMERS;
  pnl1.Visible := tabsMappings.TabIndex = TAB_ITEMS;
  pnl2.Visible := tabsMappings.TabIndex = TAB_VATS;
end;

procedure TFrmFinanceConnect.tvListExternalCodePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var
  keyValue : TKeyAndValue;
  financeLookupList : TKeyPairList;
  memTable : TdxMemData;
  RoomerCode, ExternalCode: TWideStringField;
  Caption : String;
  keyPairType: TKeyPairType;
begin
  //
  keyPairType := FinanceConnectService.keyPairTypeByIndex(tabsMappings.TabIndex);
  Caption := FinanceConnectService.MappingCaptionByIndex(KeyPairType);


  case tabsMappings.TabIndex of
    TAB_CUSTOMERS : begin
                      financeLookupList := CustomersLookupList;
                      memTable := memCustomers;
                      ExternalCode := memCustomersExternalCode;
                      RoomerCode := memCustomersCode;
                    end;
    TAB_ITEMS     : begin
                      financeLookupList := ItemsLookupList;
                      memTable := memItems;
                      RoomerCode := memItemsCode;
                      ExternalCode := memItemsExternalCode;
                    end;
    TAB_VATS      : begin
                      financeLookupList := VatsLookupList;
                      memTable := memVats;
                      RoomerCode := memVatsCode;
                      ExternalCode := memVatsExternalCode;
                    end;
  end;

  keyValue := selectFromKeyValuePairs(Caption, ExternalCode.AsString, financeLookupList);
  if Assigned(keyValue) then
  begin
    FinanceConnectService.MapForFinanceConnect(keyPairType, RoomerCode.AsString, KeyValue.Key);
    MappingsLookupMap.AddOrSetValue(format('%s_%s', [MAPPING_ENTITIES[keyPairType], RoomerCode.AsString]), KeyValue.Key);
    memTable.Edit;
    try
      ExternalCode.AsString := keyValue.Key;
      memTable.Post;
    except
      memTable.Cancel;
      raise;
    end;
  end;
end;

//////////////////////////////////////////// Methods ///////////////////////////////////////////////

procedure TFrmFinanceConnect.LoadInfo;
var rSet : TRoomerDataSet;
    KeyAndValue : TKeyAndValue;
    i, index : Integer;
begin
 //
  LoadSet(glb.CustomersSet, FKP_CUSTOMERS, memCustomers, 'Customer', 'Surname', 'PID');
  LoadSet(glb.Items, FKP_PRODUCTS, memItems, 'Item', 'Description', 'BookKeepCode');
  LoadSet(glb.VAT, FKP_VAT, memVats, 'VATCode', 'Description', 'BookKeepCode');

  index := 0;
  cbxSystemSelection.Items.Clear;
  cbxSystemSelection.Items.Add('<None>');
  for KeyAndValue IN SystemsLookupList do
  begin
    i := cbxSystemSelection.Items.Add(format('%s (%s)', [KeyAndValue.Value, KeyAndValue.Key]));
    if KeyAndValue.Key = ActiveFinanceConnectSystemCode then index := i;
  end;
  cbxSystemSelection.ItemIndex := index;
end;

procedure TFrmFinanceConnect.LoadSet(rSet : TRoomerDataSet; KeyPairType : TKeyPairType; mem : TdxMemData; CodeField, NameField, MappedField : String);
var Code : String;
    Name : String;
    ExternalCode : String;
begin
 //
  mem.Close;
  mem.Open;
  rSet.First;
  mem.DisableControls;
  try
    while Not rSet.Eof do
    begin
      if rSet['Active'] then
      begin
        mem.Insert;
        mem['Code'] := rSet[CodeField];
        mem['Name'] := rSet[NameField];

        if NOT MappingsLookupMap.TryGetValue(format('%s_%s', [MAPPING_ENTITIES[KeyPairType], rSet.FieldByName(CodeField).AsString]), ExternalCode) then
          ExternalCode := '';

        mem['ExternalCode'] := ExternalCode;
        mem.Post;
      end;
      rSet.Next;
    end;
  finally
    mem.EnableControls;
  end;
end;

procedure TFrmFinanceConnect.PrepareTabs;
var FinanceConnectSettings : TFinanceConnectSettings;
begin
 //
  pnl0.Align := alClient;
  pnl1.Align := alClient;
  pnl2.Align := alClient;

  pnl0.Visible := False;
  pnl1.Visible := False;
  pnl2.Visible := False;

  tabsMappings.TabIndex := TAB_CUSTOMERS;
  tabsMappingsChange(tabsMappings);

  FinanceConnectSettings := FinanceConnectService.FinanceConnectConfiguration;
  cbxActive.Checked := FinanceConnectSettings.systemActive;
  edServiceUrl.Text := FinanceConnectSettings.serviceUri;
  edUsername.Text := FinanceConnectSettings.username;
  edPassword.Text := FinanceConnectSettings.password;
  edOrg.Text := FinanceConnectSettings.organizationId;
  edOffice.Text := FinanceConnectSettings.officeCode;
  edCompany.Text := FinanceConnectSettings.companyGuid;
  edSalesCode.Text := FinanceConnectSettings.invoiceCode;
  edCashCode.Text := FinanceConnectSettings.cashCode;
  edCashAccount.Text := FinanceConnectSettings.cashBalanceAccount;
  edReceivableAccount.Text := FinanceConnectSettings.receivableBalanceAccount;
  edPreInvoiceNumber.Text := FinanceConnectSettings.preceedingInvoiceNumber;
  edSuccInvoiceNumber.Text := FinanceConnectSettings.succeedingInvoiceNumber;
end;

procedure TFrmFinanceConnect.sButton1Click(Sender: TObject);
var FinanceConnectSettings : TFinanceConnectSettings;
begin
  FinanceConnectSettings := FinanceConnectService.FinanceConnectConfiguration;
  FinanceConnectSettings.systemActive := cbxActive.Checked;
  FinanceConnectSettings.serviceUri := edServiceUrl.Text;
  FinanceConnectSettings.username := edUsername.Text;
  FinanceConnectSettings.password := edPassword.Text;
  FinanceConnectSettings.organizationId := edOrg.Text;
  FinanceConnectSettings.officeCode := edOffice.Text;
  FinanceConnectSettings.companyGuid := edCompany.Text;
  FinanceConnectSettings.invoiceCode := edSalesCode.Text;
  FinanceConnectSettings.cashCode := edCashCode.Text;
  FinanceConnectSettings.cashBalanceAccount := edCashAccount.Text;
  FinanceConnectSettings.receivableBalanceAccount := edReceivableAccount.Text;
  FinanceConnectSettings.preceedingInvoiceNumber := edPreInvoiceNumber.Text;
  FinanceConnectSettings.succeedingInvoiceNumber := edSuccInvoiceNumber.Text;

  sMemo1.Lines.Text := FinanceConnectService.CreateSettingsXml(FinanceConnectSettings);
  FinanceConnectService.SaveFinanceConnectSettings(FinanceConnectSettings);
end;

end.
