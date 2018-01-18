unit uFrmConnectionsStatistics;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.StdCtrls,
  sButton, Vcl.ExtCtrls, sPanel, Vcl.ComCtrls, sStatusBar, sEdit, sCheckBox, sLabel, sGroupBox, sPageControl,
  uConnectionsStatisticsService;

type
  TFrmConnectionsStatistics = class(TfrmBaseRoomerDialogForm)
    sPageControl1: TsPageControl;
    sTabSheet1: TsTabSheet;
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
    sGroupBox1: TsGroupBox;
    btnForceFull: TsButton;
    btnForceIncremental: TsButton;
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
    procedure btnForceFullClick(Sender: TObject);
    procedure btnForceIncrementalClick(Sender: TObject);
    procedure cbxActiveClick(Sender: TObject);
  private
    { Private declarations }
    ConnectionsStatisticsService : TConnectionsStatisticsService;
    procedure DisplayData;
    procedure SaveSnapshotSettings;
  public
    { Public declarations }
  end;

var
  FrmConnectionsStatistics: TFrmConnectionsStatistics;

procedure ShowStatisticsSettings;

implementation

{$R *.dfm}
uses uSnapshotService
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

const SYSTEM_CODE = 'SNAPSHOT';

procedure TFrmConnectionsStatistics.btnForceFullClick(Sender: TObject);
begin
  inherited;
  ConnectionsStatisticsService.forceExport(etFull);
end;

procedure TFrmConnectionsStatistics.btnForceIncrementalClick(Sender: TObject);
begin
  inherited;
  ConnectionsStatisticsService.forceExport(etIncremental);
end;

procedure TFrmConnectionsStatistics.btnOKClick(Sender: TObject);
begin
  inherited;
  SaveSnapshotSettings;
end;

procedure TFrmConnectionsStatistics.cbxActiveClick(Sender: TObject);
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
  sGroupBox1.Enabled := cbxActive.Checked;
  btnForceFull.Enabled := cbxActive.Checked;
  btnForceIncremental.Enabled := cbxActive.Checked;
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

procedure TFrmConnectionsStatistics.DisplayData;
begin
  With ParseConnectionSettingsXml(ConnectionsStatisticsService.GetSettings) do
  begin
    edServiceUrl.Tag := id;
    edServiceUrl.Text := systemUrl;
    edUsername.Text := username;
    edPassword.Text := password;
    edApiKey.Text := apiKey;

    cbxActive.Checked := active;
  end;
  cbxActiveClick(cbxActive);
end;

procedure TFrmConnectionsStatistics.FormCreate(Sender: TObject);
begin
  inherited;
  ConnectionsStatisticsService := TConnectionsStatisticsService.Create(SYSTEM_CODE);
end;

procedure TFrmConnectionsStatistics.FormShow(Sender: TObject);
begin
  inherited;
  edServiceUrl.Tag := 0;
  DisplayData;
end;

end.
