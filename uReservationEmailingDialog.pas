unit uReservationEmailingDialog;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, sPanel, Vcl.StdCtrls, sComboBox, sLabel, Vcl.OleCtrls, SHDocVw, sButton, sEdit, cxClasses, cxPropertiesStore
  , uResourceTypeDefinitions
  , uResourceManagement
  ;

type

  TEmailType = (EMAIL_TYPE_NEW_RESERVATION_CONFIRMATION, EMAIL_TYPE_CANCEL_RESERVATION_CONFIRMATION);

  TFrmReservationEmailingDialog = class(TForm)
    sPanel1: TsPanel;
    sPanel2: TsPanel;
    sLabel1: TsLabel;
    edTemplate: TsComboBox;
    btnOk: TsButton;
    btnResources: TsButton;
    btnEdit: TsButton;
    FormStore: TcxPropertiesStore;
    sLabel2: TsLabel;
    edTo: TsComboBox;
    sLabel3: TsLabel;
    edCC: TsComboBox;
    sLabel4: TsLabel;
    edSubject: TsEdit;
    shpTemplate: TShape;
    shpTo: TShape;
    shpSubject: TShape;
    WebBrowser: TWebBrowser;
    btnCancel: TsButton;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure edTemplateCloseUp(Sender: TObject);
    procedure btnResourcesClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure edToCloseUp(Sender: TObject);
    procedure edSubjectChange(Sender: TObject);
    procedure edToChange(Sender: TObject);
    procedure btnOkClick(Sender: TObject);
  private
    FEmailType: TEmailType;
    FResourceType: TResourceType;
    tempFilename,
    filename : String;
    SubjectTemplate : String;
    FRoomerResourceManagement : TRoomerResourceManagement;
    procedure SetEmailType(const Value: TEmailType);
    procedure NavigateToFile;
    procedure EnableDisableOKButton;
    procedure GetEmailAddresses;
    procedure RefreshTemplateList;
    procedure SendConfirmationEmail;
    { Private declarations }
  public
    ReservationId : Integer;

    destructor Destroy; override;
    property EmailType : TEmailType read FEmailType write SetEmailType;
  end;


function SendNewReservationConfirmation(ReservationId : Integer) : Boolean;
function SendCancellationConfirmation(ReservationId : Integer) : Boolean;

implementation

{$R *.dfm}

uses PrjConst,
     uAppGlobal,
     IOUtils,
     uRoomerLanguage,
     uFrmResources,
     uMain,
     uFrmEmbeddedHtmlEditor,
     uTemplateFiller,
     ActiveX,
     uFileSystemUtils,
     cmpRoomerDataset,
     uD,
     uG,
     HData,
     uUtils,
     uStringUtils
     ;

function SendNewReservationConfirmation(ReservationId : Integer) : Boolean;
var
  _FrmReservationEmailingDialog: TFrmReservationEmailingDialog;
begin
  _FrmReservationEmailingDialog := TFrmReservationEmailingDialog.Create(nil);
  try
    _FrmReservationEmailingDialog.EmailType := EMAIL_TYPE_NEW_RESERVATION_CONFIRMATION;
    _FrmReservationEmailingDialog.ReservationId := ReservationId;
    Result := _FrmReservationEmailingDialog.ShowModal = mrOK;
  finally
    FreeAndNil(_FrmReservationEmailingDialog);
  end;
end;

function SendCancellationConfirmation(ReservationId : Integer) : Boolean;
var
  _FrmReservationEmailingDialog: TFrmReservationEmailingDialog;
begin
  _FrmReservationEmailingDialog := TFrmReservationEmailingDialog.Create(nil);
  try
    _FrmReservationEmailingDialog.EmailType := EMAIL_TYPE_CANCEL_RESERVATION_CONFIRMATION;
    _FrmReservationEmailingDialog.ReservationId := ReservationId;
    result := _FrmReservationEmailingDialog.ShowModal = mrOk;
  finally
    FreeAndNil(_FrmReservationEmailingDialog);
  end;
end;

{ TFrmReservationEmailingDialog }

procedure TFrmReservationEmailingDialog.SendConfirmationEmail;
var lMessage: TStringlist;
    bcc : String;
begin
  lMessage := TStringlist.Create;
  Screen.Cursor := crHourGlass;
  try
    lMessage.LoadFromFile(tempFilename, TEncoding.UTF8);

    bcc := '';
    if g.qDefaultSendCCEmailToHotel then
      bcc := ctrlGetString('CompanyEmail');

    d.RoomerMainDataset.sendEmailOpenAPI(edSubject.Text, hData.ctrlGetString('CompanyEmail'),
        edTo.Text, edCc.Text, bcc, '', ConvertToEncion(lMessage.Text));
  finally
    lMessage.Free;
    Screen.Cursor := crDefault;
  end;
end;

procedure TFrmReservationEmailingDialog.RefreshTemplateList;
var idx : Integer;
begin
  idx := edTemplate.ItemIndex;
  edTemplate.items.BeginUpdate;
  try
    edTemplate.Items.Clear;
    FRoomerResourceManagement.Free;
    FRoomerResourceManagement := TRoomerResourceManagement.Create(FResourceType, TResourceAccessType.ratOpen);
    FRoomerResourceManagement.AddStaticResourcesAsStrings(edTemplate.Items);
    edTemplate.ItemIndex := idx;
  finally
    edTemplate.Items.EndUpdate;
  end;
end;

procedure TFrmReservationEmailingDialog.btnOkClick(Sender: TObject);
begin
  SendConfirmationEmail;
  Close;
end;

procedure TFrmReservationEmailingDialog.btnResourcesClick(Sender: TObject);
begin
  StaticResources(FResourceType.AsReadableString, [FResourceType], TResourceAccessType.ratOpen);
  RefreshTemplateList;
end;

destructor TFrmReservationEmailingDialog.Destroy;
begin
  FRoomerResourceManagement.Free;
  inherited;
end;

procedure TFrmReservationEmailingDialog.EnableDisableOKButton;
begin
  btnOk.Enabled := ((edTemplate.ItemIndex >= 0) OR (edTemplate.Text <> '')) AND
                   ((edTo.ItemIndex >= 0) OR (edTo.Text <> '')) AND
                   (Trim(edSubject.Text) <> '');

  shpTemplate.Visible := NOT ((edTemplate.ItemIndex >= 0) OR (edTemplate.Text <> ''));
  shpTo.Visible := NOT ((edTo.ItemIndex >= 0) OR (edTo.Text <> ''));
  shpSubject.Visible := (Trim(edSubject.Text) = '');
  btnEdit.Enabled := (edTemplate.ItemIndex >= 0);
end;

procedure TFrmReservationEmailingDialog.edSubjectChange(Sender: TObject);
begin
  EnableDisableOKButton;
end;

procedure TFrmReservationEmailingDialog.edTemplateCloseUp(Sender: TObject);
var Strings : TStrings;
begin
  if edTemplate.ItemIndex = -1 then
    Exit;

  try
    filename := FRoomerResourceManagement.DownloadResourceByName(edTemplate.Items[edTemplate.ItemIndex], SubjectTemplate);

    Strings := TStringlist.Create;
    try
      Strings.LoadFromFile(filename, TEncoding.UTF8);
      Strings.SaveToFile(tempFilename, TEncoding.UTF8);
    finally
      Strings.Free;
    end;

    NavigateToFile;
    EnableDisableOKButton;
  except
    edTemplate.ItemIndex := -1;
  end;
end;

procedure TFrmReservationEmailingDialog.edToChange(Sender: TObject);
begin
  EnableDisableOKButton;
end;

procedure TFrmReservationEmailingDialog.edToCloseUp(Sender: TObject);
begin
  EnableDisableOKButton;
end;

procedure TFrmReservationEmailingDialog.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
  tempFilename := GetTempFileName('.html');
end;

procedure TFrmReservationEmailingDialog.FormDestroy(Sender: TObject);
begin
  try DeleteFile(tempFilename); except end;
end;

procedure TFrmReservationEmailingDialog.GetEmailAddresses;
var s : String;
    rSet : TRoomerDataset;
begin
  s := format(
       'SELECT DISTINCT Email FROM ' +
       '( ' +
       'SELECT ContactEmail AS Email FROM reservations WHERE Reservation=%d AND ContactEmail<>'''' AND (NOT ISNULL(ContactEmail)) ' +
       'UNION ALL ' +
       'SELECT Email FROM persons WHERE Reservation=%d AND Email<>'''' AND (NOT ISNULL(Email)) ' +
       ') xxx', [ReservationId, ReservationId]);
  rSet := CreateNewDataset;
  edTo.Items.Clear;
  edCC.Items.Clear;
  if hData.rSet_bySQL(rSet, s) then
  begin
    rSet.First;
    while NOT rSet.Eof do
    begin
      edTo.Items.Add(rSet['Email']);
      edCC.Items.Add(rSet['Email']);
      rSet.Next;
    end;
  end;
end;

procedure TFrmReservationEmailingDialog.FormShow(Sender: TObject);
begin
  RefreshTemplateList;
  EnableDisableOKButton;
  GetEmailAddresses;
end;


procedure TFrmReservationEmailingDialog.NavigateToFile;
var Strings : TStrings;
    Subject : String;
begin
  Strings := TStringlist.Create;
  try
    Strings.LoadFromFile(filename, TEncoding.UTF8);
    Subject := SubjectTemplate;
    Strings.Text := fillInBookingInformation(ReservationId, Strings.Text, Subject, EmailType = EMAIL_TYPE_NEW_RESERVATION_CONFIRMATION);
    Strings.SaveToFile(tempFilename, TEncoding.UTF8);
    WebBrowser.Navigate2(tempFilename);
    edSubject.Text := Subject;
//    LoadHtmlIntoBrowser(WebBrowser, src);
  finally
    Strings.Free;
  end;
end;

procedure TFrmReservationEmailingDialog.btnEditClick(Sender: TObject);
begin
  if EditHtmlFile(tempFilename) then
    WebBrowser.Navigate2(tempFilename);
end;

procedure TFrmReservationEmailingDialog.SetEmailType(const Value: TEmailType);
begin
  FEmailType := Value;
  if Value = EMAIL_TYPE_NEW_RESERVATION_CONFIRMATION then
  begin
    Caption := GetTranslatedText('shUI_NewReservationConfirmationEmail');
    FResourceType := rtGuestEmailTemplate;
  end else
  if Value = EMAIL_TYPE_CANCEL_RESERVATION_CONFIRMATION then
  begin
    Caption := GetTranslatedText('shUI_CancelReservationConfirmationEmail');
    FResourceType := rtCancelEmailTemplate;
  end;
end;

end.
