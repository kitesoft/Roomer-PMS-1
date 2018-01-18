unit uFrmManagePCIConnection;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sCheckBox, uRoomerForm, sButton, Vcl.ExtCtrls, sPanel, cxGridTableView, cxStyles, dxPScxCommon,
  dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sComboBox, sLabel,
  Generics.Collections, uRoomerDialogForm
  , uPayCard
  ;

type
  TFrmManagePCIConnection = class(TfrmBaseRoomerDialogForm)
    pnlTop: TsPanel;
    cbxIsActive: TsCheckBox;
    pnlLeft: TsPanel;
    __lblVISA: TsLabel;
    __lbAMEX: TsLabel;
    __lbBC: TsLabel;
    __lbMastercard: TsLabel;
    __lbMC_Alaska: TsLabel;
    __lbMC_Canada: TsLabel;
    __lbUnionPay: TsLabel;
    __lbDiscover: TsLabel;
    __lbDinersclub: TsLabel;
    pnlRight: TsPanel;
    __lbCartaSi: TsLabel;
    __lbCarteBleue: TsLabel;
    __lbDankort: TsLabel;
    __lbDelta: TsLabel;
    __lbElectron: TsLabel;
    __lbJCB: TsLabel;
    __lbMaestro: TsLabel;
    __lbSwitch: TsLabel;
    __lbSolo: TsLabel;
    cbVISA: TsComboBox;
    cbAMEX: TsComboBox;
    cbBC: TsComboBox;
    cbMastercard: TsComboBox;
    cbMC_Alaska: TsComboBox;
    cbMC_Canada: TsComboBox;
    cbUnionPay: TsComboBox;
    cbDiscover: TsComboBox;
    cbDincersclub: TsComboBox;
    cbCartaSi: TsComboBox;
    cbCarteBleue: TsComboBox;
    cbDankort: TsComboBox;
    cbDelta: TsComboBox;
    cbElectron: TsComboBox;
    cbJCB: TsComboBox;
    cbMaestro: TsComboBox;
    cbSwitch: TsComboBox;
    cbSolo: TsComboBox;
    cbDefault: TsComboBox;
    pnlMapCaption: TsPanel;
    sLabel1: TsLabel;
    lbOtherCards: TsLabel;
    shpDefaultPaytypeEmpty: TShape;
    procedure FormDestroy(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
    procedure cbChange(Sender: TObject);
    procedure cbKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
  private
    combos : TDictionary<TPayCardType, TsComboBox>;
    procedure Save;
    function getComboBoxes: TDictionary<TPayCardType, TsComboBox>;
    { Private declarations }
  protected
    procedure DoShow; override;
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
  end;

procedure ManagePCIConnection;
function getMapForCardType(foreignCardType : String) : String;
function PCIBookingsActivated: boolean;
function PCIBookingConfigured: boolean;

implementation

{$R *.dfm}

uses uAppGlobal,
     uFrmOptInMessage,
     cmpRoomerDataset,
     uD,
     hData
     , Math
     , PrjConst
     , uSQLUtils;

const
  HS_PCI_BOOKING_UPG = 'PCIBOOKING_UPG';
  HS_PAYMENT = 'PAYMENT';
  HS_CARDTYPE_OTHER = 'DEFAULT';
  PMS_MAPPING_PREFIX = 'MAP_';


function PCIBookingConfigured: boolean;
begin
  Result := PCIBookingsActivated and not getMapForCardType(HS_CARDTYPE_OTHER).IsEmpty;
end;

function PCIBookingsActivated: boolean;
var
  rSet: TRoomerDataset;
  sql: string;
begin
  rSet := CreateNewDataSet;
  try
    sql := 'SELECT * FROM home100.hotelservices WHERE hotelId=''%s'' AND service=%s AND serviceType=%s AND active=1';
    sql := format(sql, [d.roomerMainDataSet.hotelId, _db(HS_PAYMENT), _db(HS_PCI_BOOKING_UPG)]);
    hData.rSet_bySQL(rSet, sql);
    Result := rSet.RecordCount > 0;
  finally
    rSet.Free;
  end;
end;

procedure ManagePCIConnection;
var _FrmManagePCIConnection: TFrmManagePCIConnection;
begin
  if glb.PCIContractOpenForChannel(-1) then
  begin
    _FrmManagePCIConnection := TFrmManagePCIConnection.Create(nil);
    try
      _FrmManagePCIConnection.ShowModal;
    finally
      _FrmManagePCIConnection.Free;
    end;
  end else
    OpenOptInDialog(OITPCI);
end;

function getMapForCardType(foreignCardType : String) : String;
var rSet : TRoomerDataSet;
    sql : String;
begin

  //TODO Move configuration of this to the payments table!
  result := '';
  sql := 'SELECT value FROM pms_settings WHERE keyGroup=''%s'' AND `key`=''MAP_%s'' ';
  sql := format(sql, [HS_PCI_BOOKING_UPG, foreignCardType]);
  rSet := CreateNewDataSet;
  try
    hData.rSet_bySQL(rSet, sql);
    rSet.first;
    if not rSet.eof then
    begin
      result := rSet['value'];
    end;
  finally
    rSet.Free;
  end;
end;

procedure TFrmManagePCIConnection.Save;
var
  sql : String;
  lComboPair: TPair<TpaycardType, TsComboBox>;
  lExecPlan: TRoomerExecutionPlan;
const
  sql_INS_template = 'INSERT INTO pms_settings ' +
                  '(keyGroup, ' +
                  '`key`, ' +
                  'value) ' +
                  'VALUES ' +
                  '(%s, ' +
                  '%s, ' +
                  '%s) ' +
                  'ON DUPLICATE KEY UPDATE value=%s ';

  sql_DEL_TEMPLATE = 'DELETE from pms_settings ' +
                      ' WHERE keyGroup=%s and `key`=%s';
begin

  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

    for lComboPair IN combos do
    begin

      if (lComboPair.Value = cbDefault) or (lComboPair.Value.ItemIndex > 0) then
      begin
        sql := format(sql_INS_template,
            [
              _db(HS_PCI_BOOKING_UPG),
              _db(PMS_MAPPING_PREFIX + lComboPair.Key.ToDB),
              _db(lComboPair.Value.Items[lComboPair.Value.ItemIndex]),
              _db(lComboPair.Value.Items[lComboPair.Value.ItemIndex])
            ]);

        lExecPlan.AddExec(sql);
      end
      else
      begin // itemidex = 0 or -1, remove setting
        sql := format(sql_DEL_template,
            [
              _db(HS_PCI_BOOKING_UPG),
              _db(PMS_MAPPING_PREFIX + lComboPair.Key.ToDB)
            ]);
        lExecPlan.AddExec(sql);
      end;
    end;

    lExecPLan.Execute(ptExec, true, true);
  finally
    lExecPlan.Free;
  end;
end;

procedure TFrmManagePCIConnection.DoShow;
begin
  DialogButtons := mbOKCancel;
  combos := getComboBoxes;

  inherited;
end;

procedure TFrmManagePCIConnection.FormDestroy(Sender: TObject);
begin
  inherited;
  combos.Free;
end;

function TFrmManagePCIConnection.getComboBoxes : TDictionary<TPayCardType, TsComboBox>;
var
  i: Integer;
begin
  result := TDictionary<TPayCardType, TsComboBox>.Create;
  for i := 0 to ComponentCount - 1 do
    if Components[i] IS TsComboBox then
      result.Add(TPaycardType(components[i].tag), Components[i] AS TsComboBox);
end;

procedure TFrmManagePCIConnection.DoUpdateControls;
begin
  inherited;
  pnlLeft.Enabled := cbxIsActive.Checked;
  pnlRight.Enabled := cbxIsActive.Checked;

  shpDefaultPaytypeEmpty.Visible := cbDefault.ItemIndex = -1;
  btnOK.Enabled := cbxIsActive.Checked and not shpDefaultPaytypeEmpty.Visible;
end;

procedure TFrmManagePCIConnection.btnOKClick(Sender: TObject);
begin
  inherited;
  Save;
end;

procedure TFrmManagePCIConnection.cbChange(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmManagePCIConnection.cbKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  inherited;
  if Key = VK_DELETE then
    TsCombobox(Sender).itemIndex := 0;
end;

procedure TFrmManagePCIConnection.DoLoadData;
var rSet : TRoomerDataset;
    sql : String;
    ptList : TStrings;
    sKey : String;
    sValue : String;
    combo: TsCombobox;

begin
  inherited;
  rSet := CreateNewDataSet;
  // Stop redrawing components
  SendMessage(Handle, WM_SETREDRAW, WPARAM(False), 0);
  try

    cbxIsActive.Checked := PCIBookingsActivated;
    if cbxIsActive.Checked then
      cbxIsActive.Caption := GetTranslatedText('shTx_PCIConnection_SettingActiveCaption')
    else
      cbxIsActive.Caption := GetTranslatedText('shTx_PCIConnection_SettingInActiveCaption');

    ptList := TStringList.Create;
    try
      ptList.Add(GetTranslatedText('shTx_PCIConnection_AsDefault'));
      glb.PaytypesSet.First;
      while NOT glb.PaytypesSet.Eof do
      begin
        if glb.PaytypesSet.FieldByName('active').AsBoolean then
          ptList.Add(glb.PaytypesSet['PayType']);
        glb.PaytypesSet.Next;
      end;
      for combo in combos.Values do
      begin
        combo.Items.BeginUpdate;
        try
          combo.Items.Clear;
          combo.Items.Assign(ptList);
          combo.ItemIndex := 0;
        finally
          combo.Items.EndUpdate;
        end;
      end;
    finally
      ptList.Free;
    end;

    cbDefault.Items.Delete(0); // cannot set default as default
    cbDefault.ItemIndex := -1; // cannot set default as default

    sql := 'SELECT `key`, value FROM pms_settings WHERE keyGroup=''%s'' ';
    sql := format(sql, [HS_PCI_BOOKING_UPG]);

    hData.rSet_bySQL(rSet, sql);
    rSet.first;
    while not rSet.eof do
    begin
      sKey := rSet['key'];
      sValue := rSet['value'];
      if combos.TryGetValue(TPayCardType.FromString(sKey.Substring(Length(PMS_MAPPING_PREFIX))), combo) then
        combo.ItemIndex := max(combo.Items.IndexOf(sValue), 0);
      rSet.Next;
    end;

  finally
    rSet.Free;
    // enable updating components again
    SendMessage(Handle, WM_SETREDRAW, WPARAM(True), 0);
  end;
end;

end.
