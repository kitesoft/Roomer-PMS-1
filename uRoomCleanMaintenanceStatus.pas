unit uRoomCleanMaintenanceStatus;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, cmpRoomerDataSet, Vcl.StdCtrls, sEdit, sRadioButton, sLabel, Vcl.ExtCtrls, sPanel, sButton, sMemo;

type
  TfrmRoomCleanMaintenanceStatus = class(TForm)
    Label1: TsLabel;
    cbxC: TsRadioButton;
    cbxU: TsRadioButton;
    cbxO: TsRadioButton;
    edtC: TsEdit;
    edtU: TsEdit;
    edtO: TsEdit;
    cbxS: TsRadioButton;
    cbxF: TsRadioButton;
    cbxW: TsRadioButton;
    edtS: TsEdit;
    edtF: TsEdit;
    edtW: TsEdit;
    cbxR: TsRadioButton;
    cbxL: TsRadioButton;
    edtR: TsEdit;
    edtL: TsEdit;
    cbxD: TsRadioButton;
    cbxM: TsRadioButton;
    edtD: TsEdit;
    edtM: TsEdit;
    sButton1: TsButton;
    pnlCleaningNotes: TsPanel;
    lblCleaningNotes: TsLabelFX;
    shpCleaningNotes: TShape;
    mmoCleaningNotes: TsMemo;
    pnlCleaningNotes_Button: TsPanel;
    sButton2: TsButton;
    pnlLostAndFound: TsPanel;
    lblLostAndFound: TsLabelFX;
    shpLostAndFound: TShape;
    mmoLostAndFound: TsMemo;
    pnlLostAndFound_Button: TsPanel;
    sButton3: TsButton;
    pnlMaintenanceNotes: TsPanel;
    lblMaintenanceNotes: TsLabelFX;
    shpMaintenanceNotes: TShape;
    mmoMaintenanceNotes: TsMemo;
    pnlMaintenanceNotes_Button: TsPanel;
    sButton4: TsButton;
    btnAllClean: TsButton;
    btnAllUnClean: TsButton;
    procedure cbxCClick(Sender: TObject);
    procedure lblCleaningNotesClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure sButton2Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure btnAllCleanClick(Sender: TObject);
    procedure sButton6Click(Sender: TObject);
  private
    FStatus: string;
    procedure HideOtherPanels(pnl: TsPanel);
    procedure HideShowPanel(show: Boolean; pnl: TsPanel);
    procedure SetRadioButtons;
    function GetStatus: string;
    procedure SetStatus(const Value: string);
    function GetCleaningRemarks: string;
    function GetLostAndFound: string;
    function GetMaintenanceRemarks: string;
    procedure SetCleaningRemarks(const Value: string);
    procedure SetLostAndFound(const Value: string);
    procedure SetMaintenanceRemarks(const Value: string);
    { Private declarations }
  public
    { Public declarations }
    FormPosition : TPoint;
    property Status: string read GetStatus write SetStatus;
    property CleaningRemarks: string read GetCleaningRemarks write SetCleaningRemarks;
    property MaintenanceRemarks: string read GetMaintenanceRemarks write SetMaintenanceRemarks;
    property LostAndFound: string read GetLostAndFound write SetLostAndFound;
  end;

function SetRoomCleanAndMaintenanceStatus(sRoom : string; x, y : integer) : boolean;

implementation

uses
  uAppGlobal,
  Db,
  ADODB,
  DbTables,
  uD,
  hData,
  uG,
  _Glob,
  CompProd
  , uUtils
  , uSQLUtils
  , objRoomList2
  , uRoomerLanguage
  , uRoomServicesAPI, uRoomservicesStatus, PrjConst, uVCLUtils;

{$R *.dfm}

function SetRoomCleanAndMaintenanceStatus(sRoom : string; x, y : integer) : boolean;
var
  dsRoom: TRoomerDataSet;
  RoomItem : TRoomItem;
  lParams: RRoomServicesSetStatusParameters;
  frm: TfrmRoomCleanMaintenanceStatus;
  lRoomServicesdAPI: TRoomServicesMobileAPICaller;
begin
  // --
  result := false;
  dsRoom := nil;
  frm := TfrmRoomCleanMaintenanceStatus.Create(nil);
  try
    dsRoom := createNewDataSet;
    hData.rSet_bySQL(dsRoom,
       format('SELECT status, rooms.ID, ' +
//		          '  maintenanceroomnotes.DateAndTime, ' +
//		          '  maintenanceroomnotes.Active, ' +
		          '  maintenanceroomnotes.CleaningNotes, ' +
		          '  maintenanceroomnotes.MaintenanceNotes, ' +
		          '  maintenanceroomnotes.LostAndFound, ' +
		          '  maintenanceroomnotes.staffIdReported, ' +
		          '  maintenanceroomnotes.staffIdFixed, ' +
		          '  smreport.initials AS reportUser, ' +
		          '  smreport.Name AS reportUserName, ' +
		          '  smfix.initials AS fixUser, ' +
		          '  smfix.Name AS fixUserName ' +
		          'FROM rooms ' +
		          '     LEFT JOIN maintenanceroomnotes ON maintenanceroomnotes.Room=rooms.Room ' +
		          '     LEFT JOIN staffmembers smreport ON smreport.id=maintenanceroomnotes.staffIdReported ' +
		          '     LEFT JOIN staffmembers smfix ON smfix.id=maintenanceroomnotes.staffIdFixed ' +
		          'WHERE rooms.Room=''%s''', [sRoom])
              );
    dsRoom.First;
    frm.Status := dsRoom['status'];

    frm.CleaningRemarks := dsRoom['CleaningNotes'];
    frm.LostAndFound := dsRoom['LostAndFound'];
    frm.MaintenanceRemarks := dsRoom['MaintenanceNotes'];

    frm.FormPosition.X := x;
    frm.FormPosition.Y := y;

    frm.Caption := frm.Caption + format(' [%s]', [sRoom]);
    frm.ShowModal;

    lParams.Clear;
    if not frm.CleaningRemarks.Equals(dsRoom['CleaningNotes']) then
    begin
      lParams.setCleaningNotes := true;
      lParams.CleaningNotes := frm.CleaningRemarks;
    end;

    if not frm.MaintenanceRemarks.Equals(dsRoom['MaintenanceNotes']) then
    begin
      lParams.setMaintenanceNotes := true;
      lParams.MaintenanceNotes := frm.MaintenanceRemarks;
    end;

    if not frm.LostAndFound.Equals(dsRoom['LostAndFound']) then
    begin
      lParams.setLostAndFound := true;
      lParams.lostAndFound := frm.LostAndFound;
    end;

    if not frm.Status.Equals(dsRoom['Status']) then
    begin
      lParams.setStatus := true;
      lParams.Status := frm.Status;

      RoomItem := g.oRooms.FindRoomFromRoomNumber(sRoom);
      RoomItem.Status := frm.Status;
    end;

    if lParams.AnythingToSet then
    begin
      lRoomServicesdAPI := TRoomServicesMobileAPICaller.Create;
      try
        lRoomServicesdAPI.SetStatus(sRoom, Now, lParams);
      finally
        lRoomServicesdAPI.Free;
      end;
    end;

    // Always refresh, AllClean could have been used
    glb.RefreshTableByName('rooms');

  finally
    dsRoom.Free;
    frm.free;
  end;
end;


procedure TfrmRoomCleanMaintenanceStatus.cbxCClick(Sender: TObject);
var
  rb: TRadioButton;
begin
  rb := Sender as TRadioButton;
  if assigned(rb) then
  begin
    FStatus := Copy(rb.Name, 4, 1);
    Close;
  end;
end;

procedure TfrmRoomCleanMaintenanceStatus.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  pnlCleaningNotes.Height := 29;
  pnlMaintenanceNotes.Height := 29;
  pnlLostAndFound.Height := 29;
  SetRadioButtons;
end;

procedure TfrmRoomCleanMaintenanceStatus.FormShow(Sender: TObject);
begin
  if FormPosition.Y + Height > Screen.Height then
    FormPosition.Y := Screen.Height - Height - 20;

  Left := FormPosition.x;
  Top := FormPosition.y;

end;

function TfrmRoomCleanMaintenanceStatus.GetCleaningRemarks: string;
begin
  Result := mmoCleaningNotes.Lines.Text;
end;

function TfrmRoomCleanMaintenanceStatus.GetLostAndFound: string;
begin
  Result := mmoLostAndFound.Lines.Text;
end;

function TfrmRoomCleanMaintenanceStatus.GetMaintenanceRemarks: string;
begin
  Result := mmoMaintenanceNotes.Lines.Text;
end;

function TfrmRoomCleanMaintenanceStatus.GetStatus: string;
begin
  Result := FStatus.ToUpper;
end;

procedure TfrmRoomCleanMaintenanceStatus.SetCleaningRemarks(const Value: string);
begin
  mmoCleaningNotes.Lines.Text := Value;
  if Value.IsEmpty then
    shpCleaningNotes.Brush.Color := clGray
  else
    shpCleaningNotes.Brush.Color := clRed;
end;

procedure TfrmRoomCleanMaintenanceStatus.SetLostAndFound(const Value: string);
begin
  mmoLostAndFound.Lines.Text := Value;
  if Value.IsEmpty then
    shpLostAndFound.Brush.Color := clGray
  else
    shpLostAndFound.Brush.Color := clRed;
end;

procedure TfrmRoomCleanMaintenanceStatus.SetMaintenanceRemarks(const Value: string);
begin
  mmoMaintenanceNotes.Lines.Text := Value;
  if Value.IsEmpty then
    shpMaintenanceNotes.Brush.Color := clGray
  else
    shpMaintenanceNotes.Brush.Color := clRed;
end;

procedure TfrmRoomCleanMaintenanceStatus.SetRadioButtons;
var
  dsCodes: TRoomerDataSet;
  obj: TComponent;
begin
  dsCodes := CreateNewDataset;
  try
    hData.rSet_bySQL(dsCodes,
       'SELECT name, code, color, id FROM maintenancecodes');

    dsCodes.first;
    while not dsCodes.Eof do
    begin
      obj := findComponent('cbx' + dsCodes['code']);
      if assigned(obj) then
        TRadioButton(obj).Caption := dsCodes['name'];

      obj := findComponent('edt' + dsCodes['code']);
      if assigned(obj) then
        TEdit(obj).Color := HtmlToColor(dsCodes['color'], clWhite);

      dsCodes.Next;
    end;

  finally
    dsCodes.Free;
  end;
end;

procedure TfrmRoomCleanMaintenanceStatus.SetStatus(const Value: string);
var
  obj: TRadioButton;
begin
  obj := findComponent('cbx' + Value) as TRadioButton;
  if assigned(obj) then
    obj.Checked := true;
end;

procedure TfrmRoomCleanMaintenanceStatus.HideOtherPanels(pnl : TsPanel);
begin
  if pnl <> lblCleaningNotes.Parent then
    HideShowPanel(false, TsPanel(lblCleaningNotes.Parent));
  if pnl <> lblMaintenanceNotes.Parent then
    HideShowPanel(false, TsPanel(lblMaintenanceNotes.Parent));
  if pnl <> lblLostAndFound.Parent then
    HideShowPanel(false, TsPanel(lblLostAndFound.Parent));
end;

procedure TfrmRoomCleanMaintenanceStatus.HideShowPanel(show : Boolean; pnl : TsPanel);
begin
  if show then
  begin
    TsPanel(findComponent(pnl.Name + '_Button')).Show;
    pnl.Align := alClient;
    pnl.Tag := 1;
  end else
  begin
    TsPanel(findComponent(pnl.Name + '_Button')).Hide;
    pnl.Align := alTop;
    pnl.Tag := 0;
    pnl.height :=29;
  end;
end;

procedure TfrmRoomCleanMaintenanceStatus.lblCleaningNotesClick(Sender: TObject);
var pnl : TsPanel;
begin
  pnl := TsPanel(TsLabel(Sender).Parent);
  if assigned(pnl) then
  begin
    if pnl.Tag = 0 then
    begin
      HideShowPanel(true, pnl);
      HideOtherPanels(pnl);
    end else
    begin
      HideShowPanel(false, pnl);
    end;
  end;
end;

procedure TfrmRoomCleanMaintenanceStatus.sButton2Click(Sender: TObject);
begin
  HideShowPanel(false, TsPanel(TsButton(Sender).Parent.Parent));
end;

procedure TfrmRoomCleanMaintenanceStatus.btnAllCleanClick(Sender: TObject);
begin
  if MessageDlg(GetTranslatedtext('shTx_SetAllRoomsCleanConfirmation'), mtConfirmation, mbYesNo, 0) = mrYes then
    d.SetAllClean
  else
    ModalResult := mrNone;
end;

procedure TfrmRoomCleanMaintenanceStatus.sButton6Click(Sender: TObject);
begin
  if MessageDlg(GetTranslatedtext('shTx_SetAllRoomsUnCleanConfirmation'), mtConfirmation, mbYesNo, 0) = mrYes then
    d.SetAllunClean
  else
    ModalResult := mrNone;
end;

end.
