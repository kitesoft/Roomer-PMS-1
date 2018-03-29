unit uFrmConnectionsStatistics;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.StdCtrls,
  sButton, Vcl.ExtCtrls, sPanel, Vcl.ComCtrls, sStatusBar, sEdit, sCheckBox, sLabel, sGroupBox, sPageControl,
  uConnectionsStatisticsService, uDImages;

type
  TFrmConnectionsStatistics = class(TfrmBaseRoomerDialogForm)
    pcPages: TsPageControl;
    tsSnapshot: TsTabSheet;
    gbxConnectionSettings: TsGroupBox;
    lbServiceUrl: TsLabel;
    lbUsername: TsLabel;
    lbPassword: TsLabel;
    cbxActive: TsCheckBox;
    edServiceUrl: TsEdit;
    edUsername: TsEdit;
    edPassword: TsEdit;
    lbApiKey: TsLabel;
    edApiKey: TsEdit;
    gbxActions: TsGroupBox;
    btnForceFull: TsButton;
    btnForceIncremental: TsButton;
    __btnViePassword: TsButton;
    tsHagstofan: TsTabSheet;
    sGroupBox1: TsGroupBox;
    lbHsId: TsLabel;
    lbHsKennitala: TsLabel;
    lbHsName: TsLabel;
    lbHsEmail: TsLabel;
    cbxHsActive: TsCheckBox;
    edHsId: TsEdit;
    edHsKennitala: TsEdit;
    edHsName: TsEdit;
    edHsEmail: TsEdit;
    lbHsAddress: TsLabel;
    edHsAddress1: TsEdit;
    edHsAddress2: TsEdit;
    lbHsPostCode: TsLabel;
    edHsPostCode: TsEdit;
    lbHsTelephone: TsLabel;
    edHsTelephone: TsEdit;
    edHsHomepage: TsEdit;
    lbHsHomepage: TsLabel;
    sLabel1: TsLabel;
    procedure FormCreate(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
    procedure btnForceFullClick(Sender: TObject);
    procedure btnForceIncrementalClick(Sender: TObject);
    procedure cbxActiveClick(Sender: TObject);
    procedure __btnViePasswordMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure __btnViePasswordMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure cbxHsActiveClick(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    { Private declarations }
    ConnectionsStatisticsService : TConnectionsStatisticsService;
    procedure SaveSnapshotSettings;
    procedure UpdateControlsHagstofa;
    procedure SaveHagstofaSettings;
  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
    { Public declarations }
  end;


procedure ShowStatisticsSettings;

implementation

{$R *.dfm}
uses uSnapshotService, uD, uRoomerConfirmationDialogs
     ;


procedure ShowStatisticsSettings;
var _FrmConnectionsStatistics: TFrmConnectionsStatistics;
begin
  _FrmConnectionsStatistics := TFrmConnectionsStatistics.Create(nil);
  try
    _FrmConnectionsStatistics.ShowModal;
  finally
    _FrmConnectionsStatistics.Free;
  end;
end;

const SNAPSHOT_SYSTEM_CODE = 'SNAPSHOT';

procedure TFrmConnectionsStatistics.btnForceFullClick(Sender: TObject);
begin
  inherited;
  if openLogin(d.roomerMainDataSet.Username, '', 7) then
  begin
  Screen.Cursor := crHourGlass;
  try
    ConnectionsStatisticsService.forceExport(etFull);
  finally
    Screen.Cursor := crDefault;
  end;
  end;
end;

procedure TFrmConnectionsStatistics.btnForceIncrementalClick(Sender: TObject);
begin
  inherited;
  try
    ConnectionsStatisticsService.forceExport(etIncremental);
  finally
    Screen.Cursor := crDefault;
  end;
end;

procedure TFrmConnectionsStatistics.btnOKClick(Sender: TObject);
begin
  inherited;
  SaveSnapshotSettings;
  SaveHagstofaSettings;
end;

procedure TFrmConnectionsStatistics.SaveHagstofaSettings;
begin
  with d.HotelServicesSettings.HagstofaServiceSettings do
  begin
    HagstofaEnabled := cbxHsActive.Checked;
    HagstofaId := edHsId.Text;
    CivilId := edHsKennitala.Text;
    Name := edHsName.Text;
    Email := edHsEmail.Text;
    Address01 := edHsAddress1.Text;
    Address02 := edHsAddress2.Text;
    PostCode := edHsPostCode.Text;
    Telephone := edHsTelephone.Text;
    Homepage := edHsHomepage.Text;

    cbxHsActiveClick(cbxHsActive);
  end;
end;

procedure TFrmConnectionsStatistics.cbxActiveClick(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmConnectionsStatistics.cbxHsActiveClick(Sender: TObject);
begin
  inherited;
  UpdateControlsHagstofa;
end;

procedure TFrmConnectionsStatistics.SaveSnapshotSettings;
var settings : TSnapshotSettings;
begin
  With settings do
  begin
    id := edServiceUrl.Tag;
    systemUrl := edServiceUrl.Text;
    username := edUsername.Text;
    password := edPassword.Text;
    apiKey := edApiKey.Text;

    active := cbxActive.Checked;
  end;
  ConnectionsStatisticsService.SaveSettings(CreateConnectionSettingsXml(settings));
end;

procedure TFrmConnectionsStatistics.__btnViePasswordMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited;
  edPassword.PasswordChar := #0;
  edPassword.Update;
end;

procedure TFrmConnectionsStatistics.__btnViePasswordMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited;
  edPassword.PasswordChar := '*';
  edPassword.Update;
end;

procedure TFrmConnectionsStatistics.DoLoadData;
begin
  inherited;
  With ParseConnectionSettingsXml(ConnectionsStatisticsService.GetSettings) do
  begin
    edServiceUrl.Tag := id;
    edServiceUrl.Text := systemUrl;
    edUsername.Text := username;
    edPassword.Text := password;
    edApiKey.Text := apiKey;

    cbxActive.Checked := active;
  end;

  with d.HotelServicesSettings.HagstofaServiceSettings do
  begin
    cbxHsActive.Checked := HagstofaEnabled;
    edHsId.Text := HagstofaId;
    edHsKennitala.Text := CivilId;
    edHsName.Text := Name;
    edHsEmail.Text := Email;
    edHsAddress1.Text := Address01;
    edHsAddress2.Text := Address02;
    edHsPostCode.Text := PostCode;
    edHsTelephone.Text := Telephone;
    edHsHomepage.Text := Homepage;
  end;
end;

procedure TFrmConnectionsStatistics.FormCreate(Sender: TObject);
begin
  inherited;
  pcPages.ActivePageIndex := 0;
  ConnectionsStatisticsService := TConnectionsStatisticsService.Create(SNAPSHOT_SYSTEM_CODE);
end;

procedure TFrmConnectionsStatistics.FormDestroy(Sender: TObject);
begin
  ConnectionsStatisticsService.Free;
  inherited;
end;

procedure TFrmConnectionsStatistics.DoShow;
begin
  inherited;
  edServiceUrl.Tag := 0;
  RefreshData;
  DialogButtons := mbOKCancel;
end;

procedure TFrmConnectionsStatistics.DoUpdateControls;
begin
  inherited;
  lbServiceUrl.Enabled := cbxActive.Checked;
  lbUsername.Enabled := cbxActive.Checked;
  lbPassword.Enabled := cbxActive.Checked;
  edServiceUrl.Enabled := cbxActive.Checked;
  edUsername.Enabled := cbxActive.Checked;
  edPassword.Enabled := cbxActive.Checked;
  lbApiKey.Enabled := cbxActive.Checked;
  edApiKey.Enabled := cbxActive.Checked;
  gbxActions.Enabled := cbxActive.Checked;
  btnForceFull.Enabled := cbxActive.Checked;
  btnForceIncremental.Enabled := cbxActive.Checked;
end;

procedure TFrmConnectionsStatistics.UpdateControlsHagstofa;
begin
  inherited;
  lbHsId.Enabled := cbxHsActive.Checked;
  lbHsKennitala.Enabled := cbxHsActive.Checked;
  lbHsName.Enabled := cbxHsActive.Checked;
  lbHsEmail.Enabled := cbxHsActive.Checked;
  lbHsAddress.Enabled := cbxHsActive.Checked;
  lbHsPostCode.Enabled := cbxHsActive.Checked;
  lbHsTelephone.Enabled := cbxHsActive.Checked;
  lbHsHomepage.Enabled := cbxHsActive.Checked;

  edHsId.Enabled := cbxHsActive.Checked;
  edHsKennitala.Enabled := cbxHsActive.Checked;
  edHsName.Enabled := cbxHsActive.Checked;
  edHsEmail.Enabled := cbxHsActive.Checked;
  edHsAddress1.Enabled := cbxHsActive.Checked;
  edHsAddress2.Enabled := cbxHsActive.Checked;
  edHsPostCode.Enabled := cbxHsActive.Checked;
  edHsTelephone.Enabled := cbxHsActive.Checked;
  edHsHomepage.Enabled := cbxHsActive.Checked;
end;

end.
