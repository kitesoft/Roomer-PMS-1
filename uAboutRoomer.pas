unit uAboutRoomer;

interface

{$include roomer.inc}

uses
    Winapi.Windows
  , Winapi.Messages
  , ShellApi
  , System.SysUtils
  , System.Variants
  , System.Classes
  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , Vcl.Menus
  , Vcl.StdCtrls
  , Vcl.ExtCtrls
  , sLabel
  , acPNG
  , cmpRoomerDataSet
  , MSXML2_TLB
  , dxGDIPlusClasses

  ;

type
  TfrmAboutRoomer = class(TForm)
    LabDBVerName: TsLabel;
    LabCopyRight: TsLabel;
    labCopyright2: TsLabel;
    Label1: TsLabel;
    sLabel1: TsLabel;
    LabSupportHomepage: TsWebLabel;
    LabSupportEmail: TsWebLabel;
    sLabel2: TsLabel;
    sLabel3: TsLabel;
    sLabel4: TsLabel;
    lblEndpoint: TsLabel;
    Image1: TImage;
    sLabel5: TsLabel;
    procedure btnCloseClick(Sender: TObject);
    procedure LabSupportHomepageClick(Sender: TObject);
    procedure Label1Click(Sender: TObject);
    procedure LabSupportEmailClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure LabDBVerNameMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmAboutRoomer: TfrmAboutRoomer;

procedure ShowRoomerAboutBox;
procedure downloadCurrentVersion(Handle : THandle; RoomerDataSet : TRoomerDataSet);
function checkNewVersion(Handle : THandle; RoomerDataSet : TRoomerDataSet) : boolean;
function findVersionOfRoomerOnServer(xml: IXMLDOMDocument2; RoomerDataSet : TRoomerDataSet) : String;
procedure StartRemoteSupport(Handle : THandle; RoomerDataSet : TRoomerDataSet);
procedure ShowDashboard(Handle : THandle; RoomerDataSet : TRoomerDataSet);

implementation

{$R *.dfm}

uses uMain
     , ActiveX
     , uRunWithElevatedOption
     , uFileDependencyManager
     , System.IOUtils
     , uFileSystemUtils
     , uStringUtils
     , uAPIDataHandler
     , IdGlobalProtocols
     , uSplashRoomer
     , uD
     , uRoomerLanguage
     , uRegistryServices
     , PrjConst
     , uUtils
     , _Glob
     ;

const MAX_NUMBER_OF_IGNORES = 5;

procedure ShowRoomerAboutBox;
begin
  Application.CreateForm(TfrmAboutRoomer, frmAboutRoomer);
  try
    frmAboutRoomer.ShowModal;
  finally
    frmAboutRoomer.free;
  end;
end;

procedure TfrmAboutRoomer.btnCloseClick(Sender: TObject);
begin
  Close;
end;

procedure TfrmAboutRoomer.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
end;

procedure TfrmAboutRoomer.FormShow(Sender: TObject);
begin
  lblEndpoint.Caption := d.roomerMainDataSet.RoomerUri;
  LabDBVerName.Caption := getVersion(Application.ExeName);
end;

procedure TfrmAboutRoomer.LabDBVerNameMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if Button = mbRight then
  begin
    uStringUtils.ClipboardCopy(LabDBVerName.Caption);
    ShowMessage(GetTranslatedText('shTx_AboutRoomer_CopyPMSVersion'));
  end
  else
    btnCloseClick(Sender);
end;

procedure TfrmAboutRoomer.Label1Click(Sender: TObject);
begin
  checkNewVersion(handle, TRoomerDataSet.Create(nil));
end;

procedure ShowDashboard(Handle : THandle; RoomerDataSet : TRoomerDataSet);
var localFilename,
    remoteFilename : String;
    filename : String;
    FileInfo : TFileEntity;
    parameters : String;
    sPath,
    DashboardExeFilenameAndPath : String;
begin
  filename := 'RoomerDashboard.exe';
  sPath := TPath.Combine(LocalAppDataPath, 'Roomer');
  forceDirectories(sPath);

  parameters := format('hotel=%s host=%s port=%s user=%s pass=%s date=2014-01-01',
           [RoomerDataset.hotelId,
            _RoomerBase,
            _RoomerBasePort,
            RoomerDataset.Username,
            RoomerDataset.Password ]);

  DashboardExeFilenameAndPath := TPath.Combine(sPath, filename);
  FileInfo :=  RoomerDataSet.SystemRoomerFile(filename);
  getAnyFileFromRoomerStore(filename, DashboardExeFilenameAndPath);
// if (NOT FileExists(UpgradeManagerPath)) OR (FileInfo=nil) OR  (FileSizeByName(UpgradeManagerPath) <> FileInfo.Size) then
//  begin
//    RoomerDataSet.roomerClient.{$IFDEF USE_INDY}OnWork := frmMain.IdHTTP1Work{$ELSE}OnDownloadProgress := frmMain.DownloadProgress{$ENDIF};
//    frmMain.lblBusyDownloading.Caption := GetTranslatedText('shTx_Main_Downloading');
//    frmMain.lblBusyDownloading.Visible := True;
//    try
//      RoomerDataSet.SystemDownloadRoomerFile(filename, UpgradeManagerPath);
//    finally
//      frmRoomerSplash.NilInternetEvents;
//     // lblBusyDownloading.Caption := 'Ready.';
//	    frmMain.lblBusyDownloading.Caption := GetTranslatedText('shTx_Main_Ready');
//      frmMain.lblBusyDownloading.Update;
//      Sleep(1000);
//      frmMain.lblBusyDownloading.Visible := False;
//    end;
//  end;
  ExecuteFile(Handle, DashboardExeFilenameAndPath, parameters, []);
end;



procedure TfrmAboutRoomer.LabSupportEmailClick(Sender: TObject);
begin
  ShellExecute(Self.WindowHandle, 'open', PChar('mailto:' + TsWebLabel(Sender).Caption), nil, nil, SW_SHOWNORMAL);
end;

procedure TfrmAboutRoomer.LabSupportHomepageClick(Sender: TObject);
begin
  ShellExecute(Self.WindowHandle, 'open', PChar('http://' + TsWebLabel(Sender).Caption), nil, nil, SW_SHOWNORMAL);
end;

procedure StartRemoteSupport(Handle : THandle; RoomerDataSet : TRoomerDataSet);
var localFilename,
    remoteFilename : String;
    filename : String;
    language : String;
    FileInfo : TFileEntity;
    sPath,
    RemoteSupportFilenameAndPath : String;
begin
  language := LowerCase(copy(RoomerLanguage.LanguageCode, 1, 2));
  if trim(language) = '' then
    language := 'en';
  filename := format('RoomerQS%s.exe', [language]);
  sPath := TPath.Combine(LocalAppDataPath, 'Roomer');
  forceDirectories(sPath);
  RemoteSupportFilenameAndPath := TPath.Combine(sPath, filename);
  getAnyFileFromRoomerStore(filename, RemoteSupportFilenameAndPath);
//  FileInfo :=  RoomerDataSet.SystemRoomerFile(filename);
//  if (NOT FileExists(UpgradeManagerPath)) OR (FileInfo=nil) OR  (FileSizeByName(UpgradeManagerPath) <> FileInfo.Size) then
//    RoomerDataSet.SystemDownloadRoomerFile(filename, UpgradeManagerPath);
  ExecuteFile(Handle, RemoteSupportFilenameAndPath, '', []);
end;

{$IFDEF ROOMERSTORE}

procedure downloadCurrentVersion(Handle : THandle; RoomerDataSet : TRoomerDataSet);
var FileInfo : TFileEntity;
    sPath,
    UpgradeManagerPath : String;
begin
  try
    frmMain.RemoveLanguagesFilesAndRefresh;
    sPath := TPath.Combine(LocalAppDataPath, 'Roomer');
    forceDirectories(sPath);
    UpgradeManagerPath := TPath.Combine(sPath, 'RoomerUpgradeAgent.exe');
    getRoomerUpgradeAgentFilePath(UpgradeManagerPath);
    ExecuteFile(Handle, UpgradeManagerPath, '"' + Application.ExeName + '"', [eoElevate]);
  except
  end;
end;

function checkNewVersion(Handle : THandle; RoomerDataSet : TRoomerDataSet) : boolean;
var sTempName : String;
    xml: IXMLDOMDocument2;
    node : IXMLDomNode;
    currentVersion, version : String;
    FileInfo : TFileEntity;
    sPath,
    UpgradeManagerPath : String;
    NumDialogShown : Integer;
    s : String;
    Buttons: TMsgDlgButtons;
begin
  result := false;
  {$IFNDEF DEBUG}
  sTempName := GetEnvironmentVariable('TEMP') + '\roomerversion.xml';

  try
    getRoomerVersionXmlFilePath(sTempName);
  except
    exit;
  end;

  currentVersion := getVersion(Application.ExeName);
  xml := CreateXmlDocument; // CoDOMDocument40.Create;
  xml.Load(sTempName);
  try

    version := findVersionOfRoomerOnServer(xml, RoomerDataSet);
    if version <> currentVersion then
    begin
    (*  if MessageDlg('There is a new version of ROOMER (' + version + ').' + #13#10 +
                    'ROOMER needs to be updated.' + #13#10#13#10 +
                    'Click [OK] to perform the update now.'+ #13#10 +
                    'Click [Cancel] to do this later', mtConfirmation, [mbOK,mbCancel], 0) = mrOk then *)
      with TRoomerRegistryIniFile.Create(GetRoomerIniFilename) do
      try
        NumDialogShown := ReadInteger('RoomerPMSVersion', version, 0) + 1;
      finally
        Free;
      end;

      if NumDialogShown > MAX_NUMBER_OF_IGNORES then
      begin
        s := format(GetTranslatedText('shTx_AboutRoomer_NewVersionAvailableExpired'), [version, MAX_NUMBER_OF_IGNORES]);
        Buttons := [mbOK];
      end else
      begin
        s := format(GetTranslatedText('shTx_AboutRoomer_NewVersionAvailable'), [version]);
        Buttons := [mbOK,mbCancel];
      end;

      if MessageDlg(s, mtConfirmation, Buttons, 0) = mrOk then
      begin
        downloadCurrentVersion(Handle, RoomerDataSet);
        result := true;
      end
      else
        with TRoomerRegistryIniFile.Create(GetRoomerIniFilename) do
        try
          WriteInteger('RoomerPMSVersion', version, NumDialogShown);
        finally
          Free;
        end;
    end;

  except

  end;
  {$ENDIF}
end;

{$ELSE}

function checkNewVersion(Handle : THandle; RoomerDataSet : TRoomerDataSet) : boolean;
var sTempName : String;
    xml: IXMLDOMDocument2;
    node : IXMLDomNode;
    currentVersion, version : String;
    FileInfo : TFileEntity;
    sPath,
    UpgradeManagerPath : String;
begin
  result := false;
  {$IFNDEF DEBUG}
  sTempName := GetEnvironmentVariable('TEMP') + '\roomerversion.xml';

  //ATH-HJ130301 Ef skr�in finnst ekki �� kemur villa
  RoomerDataSet.SystemDownloadRoomerFile(
      'Roomer.xml',
      sTempName);

  currentVersion := getVersion(Application.ExeName);
  xml := CreateXmlDocument; // CoDOMDocument40.Create;
  xml.Load(sTempName);
  try

    version := findVersionOfRoomerOnServer(xml, RoomerDataSet);
    if version <> currentVersion then
    begin
    (*  if MessageDlg('There is a new version of ROOMER (' + version + ').' + #13#10 +
                    'ROOMER needs to be updated.' + #13#10#13#10 +
                    'Click [OK] to perform the update now.'+ #13#10 +
                    'Click [Cancel] to do this later', mtConfirmation, [mbOK,mbCancel], 0) = mrOk then *)
		if MessageDlg(format(GetTranslatedText('shTx_AboutRoomer_NewVersionAvailable'), [version]), mtConfirmation, [mbOK,mbCancel], 0) = mrOk then
      begin
        downloadCurrentVersion(Handle, RoomerDataSet);
        result := true;
      end;
    end;

  except
  end;
  {$ENDIF}
end;


{$ENDIF}


function findVersionOfRoomerOnServer(xml: IXMLDOMDocument2; RoomerDataSet : TRoomerDataSet) : String;
var node : IXMLDomNode;
    currentVersion : String;
begin
  result := '';
  node := xml.documentElement.firstChild;
  while node <> nil do
  begin
    if RoomerDataSet.GetAttributeValue(node, 'filename', '') = 'Roomer.exe' then
    begin
      result := RoomerDataSet.GetAttributeValue(node, 'version', currentVersion);
      Break;
    end;
    node := node.nextSibling;
  end;
end;

end.
