unit uFrmConnectionsStatistics;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.StdCtrls,
  sButton, Vcl.ExtCtrls, sPanel, Vcl.ComCtrls, sStatusBar, sEdit, sCheckBox, sLabel, sGroupBox, sPageControl,
  uConnectionsStatisticsService, uDImages;

type
  TFrmConnectionsStatistics = class(TfrmBaseRoomerDialogForm)
    sPageControl1: TsPageControl;
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
    procedure FormCreate(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
    procedure btnForceFullClick(Sender: TObject);
    procedure btnForceIncrementalClick(Sender: TObject);
    procedure cbxActiveClick(Sender: TObject);
    procedure __btnViePasswordMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure __btnViePasswordMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
  private
    { Private declarations }
    ConnectionsStatisticsService : TConnectionsStatisticsService;
    procedure SaveSnapshotSettings;
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
  Screen.Cursor := crHourGlass;
  try
    ConnectionsStatisticsService.forceExport(etFull);
  finally
    Screen.Cursor := crDefault;
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
end;

procedure TFrmConnectionsStatistics.cbxActiveClick(Sender: TObject);
begin
  inherited;
  UpdateControls;
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
end;

procedure TFrmConnectionsStatistics.FormCreate(Sender: TObject);
begin
  inherited;
  ConnectionsStatisticsService := TConnectionsStatisticsService.Create(SYSTEM_CODE);
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

end.
