unit RoomerLoginForm;

interface

{$include roomer.inc}

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls, acPNG, cxLookAndFeels, sSkinProvider, cxPropertiesStore, sLabel, cxClasses, dxGDIPlusClasses, cxGraphics, cxLookAndFeelPainters, Vcl.Menus, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, cxButtons, dxSkinsDefaultPainters, sSkinManager, sButton;

type
  // Dialog asking user for credentials, When closed the result is stored in the Tag property, using ord(TLoginformResult)
  TfrmRoomerLoginForm = class(TForm)
    lbHotel: TLabel;
    edtHotelCode: TEdit;
    lbUsername: TLabel;
    edtUsername: TEdit;
    lbPassword: TLabel;
    edtPassword: TEdit;
    pnlButtons: TPanel;
    btLogin: TsButton;
    btCancel: TsButton;
    imgRoomer: TImage;
    StoreLogin: TcxPropertiesStore;
    lblMessage: TsLabel;
    lblServerProblem: TsLabel;
    timTopmostOff: TTimer;
    tmrCheckConnection: TTimer;
    procedure btLoginClick(Sender: TObject);
    procedure btCancelClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure timTopmostOffTimer(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure FormActivate(Sender: TObject);
    procedure tmrCheckConnectionTimer(Sender: TObject);
  private
    { Private declarations }
    FNoInternet: boolean;
    FServerUnreachable : Boolean;
    procedure SetNoInternet(const Value: boolean);
    procedure SetServerUnreachable(const Value: boolean);
    procedure UpdateControls;
    procedure CheckConnections;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    function GetLoginParameters(var aUsername, aPassword, aHotelId: String): Boolean;
    property NoInternet: boolean read FNoInternet write SetNoInternet;
    property ServerUnreachable: boolean read FServerUnreachable write SetServerUnreachable;
  public
    { Public declarations }
  end;

  // Possible outcomes of AskUserForCredentials()
  TLoginFormResult = (lrCancel = 0, lrLogin {, lrOffLine});



// Ask the user for authentication credentials using the RoomerLoginForm
function AskUserForCredentials(var aUsername: String; var aPassword: String; var aHotelId : String; aLastMessage : String; AuthValueIndex : Integer = -1): TLoginFormResult;


const
  // TLoginFormResults when login dialog is confirmed
  cLoginFormSuccesfull: set of TLoginFormResult = [lrLogin {, lrOffline}];

var
  lLoginForm: TfrmRoomerLoginForm;

implementation

{$R *.dfm}

uses uUtils,
     uRoomerLanguage, uDImages,
     ud,
     IOUtils,
     uStringUtils,
     uMain,
     uAboutRoomer,
     uSqlUtils,
     cmpRoomerDataSet,
     hData;

function AskUserForCredentials(var aUsername: String; var aPassword: String; var aHotelId : String; aLastMessage : String; AuthValueIndex : Integer = -1): TLoginFormResult;

  function CheckLoginCorrectness : Boolean;
  var sql : String;
      rSet : TRoomerDataset;
  begin
    result := True;
    if AuthValueIndex = -1 then exit;

    sql := format(
           'SELECT sm.id FROM staffmembers sm ' +
           'LEFT JOIN stafftypes st1 ON st1.StaffType=sm.StaffType ' +
           'LEFT JOIN stafftypes st2 ON st2.StaffType=sm.StaffType1 ' +
           'LEFT JOIN stafftypes st3 ON st3.StaffType=sm.StaffType2 ' +
           'LEFT JOIN stafftypes st4 ON st4.StaffType=sm.StaffType3 ' +
           'LEFT JOIN stafftypes st5 ON st5.StaffType=sm.StaffType4 ' +
           'WHERE Initials=%s AND Password=%s ' +
           'AND (%d=0 ' +
           'OR (%d>0 AND SUBSTR(IFNULL(st1.AuthValue, ''0''), %d, 1)=''1'') ' +
           'OR (%d>0 AND SUBSTR(IFNULL(st2.AuthValue, ''0''), %d, 1)=''1'') ' +
           'OR (%d>0 AND SUBSTR(IFNULL(st3.AuthValue, ''0''), %d, 1)=''1'') ' +
           'OR (%d>0 AND SUBSTR(IFNULL(st4.AuthValue, ''0''), %d, 1)=''1'') ' +
           'OR (%d>0 AND SUBSTR(IFNULL(st5.AuthValue, ''0''), %d, 1)=''1'')) ',
           [
            _db(aUsername), _db(aPassword),

            AuthValueIndex, AuthValueIndex,

            AuthValueIndex, AuthValueIndex,
            AuthValueIndex, AuthValueIndex,
            AuthValueIndex, AuthValueIndex,
            AuthValueIndex, AuthValueIndex,
            AuthValueIndex, AuthValueIndex

           ]);
    rSet := CreateNewDataSet;
    CopyToClipboard(sql);
    hData.rSet_bySQL(rSet,sql);
    rSet.First;
    result := NOT rSet.Eof;
  end;
begin
  lLoginForm := TfrmRoomerLoginForm.Create(nil);
  try
    // Disable use of commandline parameters if previous login failed
    if (aLastMessage = '') and lLoginForm.GetLoginParameters(aUsername, aPassword, aHotelId) then
    begin
      result := lrLogin;
      exit;
    end;

    if (aHotelId <> '') then lLoginForm.edtHotelCode.Text := aHotelId;
    if (aUsername <> '') then lLoginForm.edtUsername.Text := aUsername;
    lLoginForm.edtPassword.Text := '';
    lLoginForm.lblMessage.Caption := aLastMessage;
    lLoginForm.lblMessage.Visible := aLastMessage <> '';
    lLoginForm.edtHotelCode.Enabled := AuthValueIndex = -1;

    lLoginForm.ShowModal;
    Result := TLoginFormResult(lLoginForm.Tag);
    if (Result in cLoginFormSuccesfull) then
    begin
      aHotelId := UpperCase(lLoginForm.edtHotelCode.Text);
      aUsername := lLoginForm.edtUsername.Text;
      aPassword := lLoginForm.edtPassword.Text;
      if NOT CheckLoginCorrectness then
        result := lrCancel;
    end;
  finally
    lLoginForm.Free;
    lLoginForm := NIL;
  end;
end;

// Get credentials from commandline parameters, return true if all three neeeded parameters are filled in
function TfrmRoomerLoginForm.GetLoginParameters(var aUsername, aPassword, aHotelId : String) : Boolean;
var temp : String;
begin
  temp := ParameterByName('username');
  if temp <> '' then aUsername := temp;

  temp := ParameterByName('password');
  if temp <> '' then aPassword := temp;

  temp := ParameterByName('hotelId');
  if temp <> '' then aHotelId := temp;

  result := (aUsername<>'') AND (aPassword<>'') AND (aHotelId<>'');
end;


procedure TfrmRoomerLoginForm.SetNoInternet(const Value: boolean);
begin
  FNoInternet := Value;
  UpdateControls;
end;

procedure TfrmRoomerLoginForm.SetServerUnreachable(const Value: boolean);
begin
  FServerUnreachable := Value;
  UpdateControls;
end;

procedure TfrmRoomerLoginForm.timTopmostOffTimer(Sender: TObject);
begin
  timTopmostOff.Enabled := false;
  SetFormTopmostOff(self);
end;

procedure TfrmRoomerLoginForm.tmrCheckConnectionTimer(Sender: TObject);
begin
  tmrCheckConnection.Enabled := false;
  try
    CheckConnections;
  finally
    tmrCheckConnection.Interval := 20000;
    tmrCheckConnection.Enabled := true;
  end;
end;

procedure TfrmRoomerLoginForm.CheckConnections;
begin
  NoInternet := NOT d.roomerMainDataSet.IsConnectedToInternet;
  if NoInternet then
    ServerUnreachable := True
  else
    ServerUnreachable := NOT d.roomerMainDataSet.RoomerPlatformAvailable;
end;

procedure TfrmRoomerLoginForm.UpdateControls;
var
  lOffLine: boolean;
const
  cNoInternet = 'No internet connection. ';
  cPlatformUnreachable = 'Roomer platform unreachable. ';
  cOfflineMessage = 'Roomer will not be able to work normally';
begin
  lOffLine := NoInternet or ServerUnreachable;
  btLogin.Enabled := not lOffLine;
  btLogin.Default := not lOffLine;

  if NoInternet then
    lblServerProblem.Caption := cNoInternet + cOfflineMessage
  else if ServerUnreachable then
    lblServerProblem.Caption := cPlatformUnreachable + cOfflineMessage
  else
    lblServerProblem.Caption := '';
end;

procedure TfrmRoomerLoginForm.btLoginClick(Sender: TObject);
begin
  CheckConnections;
  if NoInternet or ServerUnreachable then
    Exit;

  Tag := ord(lrLogin);
  if IsControlKeyPressed then
     SetIgnoresToZero(d.roomerMainDataSet);
  Close;
end;

procedure TfrmRoomerLoginForm.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.ExStyle := Params.ExStyle or WS_EX_APPWINDOW;
  Params.WndParent := Application.Handle;
end;

procedure TfrmRoomerLoginForm.btCancelClick(Sender: TObject);
begin
  Tag := ord(lrCancel);
  Close;
end;

procedure TfrmRoomerLoginForm.FormActivate(Sender: TObject);
begin
  if not d.roomerMainDataSet.RoomerUri.StartsWith(cRoomerBase) then
    Caption := 'Roomer Login (' + d.roomerMainDataSet.RoomerUri + ')';
end;

procedure TfrmRoomerLoginForm.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
end;

procedure TfrmRoomerLoginForm.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    btCancelClick(Sender);
end;

procedure TfrmRoomerLoginForm.FormShow(Sender: TObject);
begin
  PlaceFormOnVisibleMonitor(Self);
  if edtHotelCode.Text <> '' then
     ActiveControl := edtUsername;
  SetFormTopmostOn(self);
  timTopmostOff.Enabled := True;
  NoInternet := NOT d.roomerMainDataSet.IsConnectedToInternet;
  ServerUnreachable := NOT d.roomerMainDataSet.RoomerPlatformAvailable;
end;

end.
