unit uFrmManagePCIConnection;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sCheckBox, uRoomerForm, sButton, Vcl.ExtCtrls, sPanel, cxGridTableView, cxStyles, dxPScxCommon,
  dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sComboBox, sLabel,
  Generics.Collections, uRoomerDialogForm
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
    cbVISA: TsComboBox;
    cbAMEX: TsComboBox;
    cbBC: TsComboBox;
    cbMastercard: TsComboBox;
    cbMC_Alaska: TsComboBox;
    cbMC_Canada: TsComboBox;
    cbUnionPay: TsComboBox;
    cbDiscover: TsComboBox;
    cbDincersclub: TsComboBox;
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
    cbCartaSi: TsComboBox;
    cbCarteBleue: TsComboBox;
    cbDankort: TsComboBox;
    cbDelta: TsComboBox;
    cbElectron: TsComboBox;
    cbJCB: TsComboBox;
    cbMaestro: TsComboBox;
    cbSwitch: TsComboBox;
    cbSolo: TsComboBox;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
  private
    labels : TObjectlist<TsLabel>;
    combos : TObjectlist<TsComboBox>;
    procedure Save;
    function getComboBoxes: TObjectlist<TsComboBox>;
    function getLabels: TObjectlist<TsLabel>;
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

implementation

{$R *.dfm}

uses uAppGlobal,
     uFrmOptInMessage,
     cmpRoomerDataset,
     uD,
     hData
     ;

const PCI_BOOKING_UPG = 'PCIBOOKING_UPG';

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
  result := '';
  sql := 'SELECT value FROM pms_settings WHERE keyGroup=''%s'' AND `key`=''MAP_%s'' ';
  sql := format(sql, [PCI_BOOKING_UPG, foreignCardType]);
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
var ACombo : TsComboBox;
    sql_template, sql : String;
begin
  sql_template := 'INSERT INTO pms_settings ' +
                  '(keyGroup, ' +
                  '`key`, ' +
                  'value) ' +
                  'VALUES ' +
                  '(''%s'', ' +
                  '''%s'', ' +
                  '''%s'') ' +
                  'ON DUPLICATE KEY UPDATE value=''%s'' ';
  for ACombo IN combos do
  begin
    if ACombo.ItemIndex > -1 then
    begin
      sql := format(sql_template,
          [
            PCI_BOOKING_UPG,
            'MAP_' + copy(ACombo.Name, 3, MAXINT),
            ACombo.Items[ACombo.ItemIndex],
            ACombo.Items[ACombo.ItemIndex]
          ]);
      cmd_bySQL(sql, false);
    end;
  end;
end;

procedure TFrmManagePCIConnection.DoShow;
begin
  inherited;
  DialogButtons := mbOKCancel;
  RefreshData;
end;

procedure TFrmManagePCIConnection.FormCreate(Sender: TObject);
begin
  inherited;
  labels := getLabels;
  combos := getComboBoxes;
end;

procedure TFrmManagePCIConnection.FormDestroy(Sender: TObject);
begin
  inherited;
  labels.Free;
  combos.Free;
end;

function TFrmManagePCIConnection.getComboBoxes : TObjectlist<TsComboBox>;
var
  i: Integer;
begin
  result := TObjectlist<TsComboBox>.Create;
  for i := 0 to ComponentCount - 1 do
    if Components[i] IS TsComboBox then
      result.Add(Components[i] AS TsComboBox);
end;

function TFrmManagePCIConnection.getLabels : TObjectlist<TsLabel>;
var
  i: Integer;
begin
  result := TObjectlist<TsLabel>.Create;
  for i := 0 to ComponentCount - 1 do
    if Components[i] IS TsLabel then
      result.Add(Components[i] AS TsLabel);
end;

procedure TFrmManagePCIConnection.DoUpdateControls;
var ALabel : TsLabel;
    ACombo : TsComboBox;
begin
  inherited;
  for ALabel IN labels do
    ALabel.Enabled := cbxIsActive.Checked;
  for ACombo IN combos do
    ACombo.Enabled := cbxIsActive.Checked;
end;

procedure TFrmManagePCIConnection.btnOKClick(Sender: TObject);
begin
  inherited;
  Save;
end;

procedure TFrmManagePCIConnection.DoLoadData;
var rSet : TRoomerDataset;
    sql, s : String;
    ptList : TStrings;
    sKey : String;
    sValue : String;
    i, idx : Integer;

    function getComboIndex(partName : String) : Integer;
    var i : Integer;
    begin
      result := -1;
      for i := 0 to combos.Count - 1 do
        if combos[i].Name = 'cb' + partName then
        begin
          result := i;
          Break;
        end;
    end;
begin
  inherited;
  rSet := CreateNewDataSet;
  try
    sql := 'SELECT * FROM home100.hotelservices WHERE hotelId=''%s'' AND service=''PAYMENT'' AND serviceType=''PCIBOOKING_UPG'' AND active=1';
    sql := format(sql, [d.roomerMainDataSet.hotelId]);
    hData.rSet_bySQL(rSet, sql);
    rSet.first;
    cbxIsActive.Checked := not rSet.eof;

      ptList := TStringList.Create;
      try
        ptList.Add('< SELECT >');
        glb.PaytypesSet.First;
        while NOT glb.PaytypesSet.Eof do
        begin
          ptList.Add(glb.PaytypesSet['PayType']);
          glb.PaytypesSet.Next;
        end;
        for i := 0 to combos.Count - 1 do
        begin
          combos[i].Items.Clear;
          combos[i].Items.Assign(ptList);
        end;
      finally
        ptList.Free;
      end;


      sql := 'SELECT `key`, value FROM pms_settings WHERE keyGroup=''%s'' ';
      sql := format(sql, [PCI_BOOKING_UPG]);
      rSet.Free;
      rSet := CreateNewDataSet;
      hData.rSet_bySQL(rSet, sql);
      rSet.first;
      while not rSet.eof do
      begin
        sKey := rSet['key'];
        sValue := rSet['value'];
        // MAP_AMEX
        s := copy(sKey, 5, MAXINT);
        idx := getComboIndex(s);
        if idx > -1 then
        begin
          combos[idx].ItemIndex := combos[idx].Items.IndexOf(sValue);
          if combos[idx].ItemIndex < 0 then
            combos[idx].ItemIndex := 0;
        end;
        rSet.Next;
      end;

  finally
    rSet.Free;
  end;
end;

end.
