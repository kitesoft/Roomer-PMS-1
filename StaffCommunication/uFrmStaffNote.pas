unit uFrmStaffNote;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sLabel, sButton, Vcl.ExtCtrls, sPanel, sMemo, sComboBox, cxClasses, cxPropertiesStore
  , uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, Vcl.ComCtrls, sStatusBar
  , uStaffCommunicationDefinitions, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, hData;

type
  TFrmStaffNote = class(TfrmBaseRoomerForm)
    panBtn: TsPanel;
    btnCancel: TsButton;
    BtnOk: TsButton;
    sPanel1: TsPanel;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    lblAuthor: TsLabel;
    lblWhen: TsLabel;
    sLabel6: TsLabel;
    sLabel3: TsLabel;
    sLabel4: TsLabel;
    __cbxAction: TsComboBox;
    mmoText: TsMemo;
    dtDateFrom: TsDateEdit;
    dtDateUntil: TsDateEdit;
    lblUntil: TsLabel;
    procedure dtDateFromChange(Sender: TObject);
  private
    FIsInsert: boolean;
  protected
    procedure Loaded; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    property IsInsert: boolean read FIsInsert write FIsInsert;
  end;

function EditDayNote(aDefDate: TDate; isInsert: boolean; var recNote: recDayNotesHolder; var FDateUntil: TDate) : Boolean;

implementation

{$R *.dfm}

uses  uRoomerLanguage, uAppGlobal, uUtils
      ,Math
      ;

function EditDayNote(aDefDate: TDate; isInsert: boolean; var recNote: recDayNotesHolder; var FDateUntil: TDate) : Boolean;
var _FrmStaffNote: TFrmStaffNote;
begin
  result := False;
  _FrmStaffNote := TFrmStaffNote.Create(nil);
  try
    _FrmStaffNote.dtDateFrom.Date := aDefDate;
    _FrmStaffNote.lblAuthor.Caption := recNote.LastChangedBy;
    _FrmStaffNote.lblWhen.Caption := DateTimeToStr(recNote.LastUpdate);

    _FrmStaffNote.__cbxAction.ItemIndex := recNote.AAction.ToItemIndex;
    _FrmStaffNote.mmoText.Lines.Text := recNote.Notes;
    _FrmStaffNote.IsInsert := IsInsert;

    if _FrmStaffNote.ShowModal = mrOk then
    begin
      result := True;
      recNote.AAction := TStaffCommAction.FromItemIndex(_FrmStaffNote.__cbxAction.ItemIndex);
      recNote.Notes := _FrmStaffNote.mmoText.Lines.Text;
      FDateUntil := Max(_FrmStaffNote.dtDateUntil.Date, _FrmStaffNote.dtDateFrom.Date);
    end;
  finally
    FreeAndNil(_FrmStaffNote)
  end;
end;

procedure TFrmStaffNote.DoUpdateControls;
begin
  inherited;
  lblUntil.Visible := FIsInsert;
  dtDateUntil.Visible := FIsInsert;
  dtDateFrom.ReadOnly := not FIsInsert;

  dtDateUntil.MinDate := dtDateFrom.Date;
  //dtDateUntil.Date := Max(dtDateUntil.Date, dtDateFrom.Date);
end;

procedure TFrmStaffNote.dtDateFromChange(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmStaffNote.Loaded;
begin
  inherited;
  TStaffCommAction.AsStrings(__cbxAction.Items);
end;

end.
