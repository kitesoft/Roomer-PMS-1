unit uFrmStaffNote;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sLabel, sButton, Vcl.ExtCtrls, sPanel, sMemo, sComboBox, cxClasses, cxPropertiesStore
  , uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, Vcl.ComCtrls, sStatusBar
  , uStaffCommunicationDefinitions, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, hData
  , uRoomerDialogForm
  ;

type
  TFrmStaffNote = class(TfrmBaseRoomerDialogForm)
    sPanel1: TsPanel;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    lblAuthor: TsLabel;
    lblWhen: TsLabel;
    sLabel6: TsLabel;
    dtDateFrom: TsDateEdit;
    dtDateUntil: TsDateEdit;
    lblUntil: TsLabel;
    sPanel2: TsPanel;
    sLabel3: TsLabel;
    sLabel4: TsLabel;
    __cbxAction: TsComboBox;
    mmoText: TsMemo;
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
var frm: TFrmStaffNote;
begin
  result := False;
  frm := TFrmStaffNote.Create(nil);
  try
    frm.dtDateFrom.Date := aDefDate;
    frm.lblAuthor.Caption := recNote.LastChangedBy;
    frm.lblWhen.Caption := DateTimeToStr(recNote.LastUpdate);

    frm.__cbxAction.ItemIndex := recNote.AAction.ToItemIndex;
    frm.mmoText.Lines.Text := recNote.Notes;
    frm.IsInsert := IsInsert;

    if frm.ShowModal = mrOk then
    begin
      result := True;
      recNote.AAction := TStaffCommAction.FromItemIndex(frm.__cbxAction.ItemIndex);
      recNote.Notes := frm.mmoText.Lines.Text;
      FDateUntil := Max(frm.dtDateUntil.Date, frm.dtDateFrom.Date);
    end;
  finally
    FreeAndNil(frm)
  end;
end;

procedure TFrmStaffNote.DoUpdateControls;
begin
  inherited;
  lblUntil.Visible := FIsInsert;
  dtDateUntil.Visible := FIsInsert;
  dtDateFrom.ReadOnly := not FIsInsert;

  dtDateUntil.MinDate := dtDateFrom.Date;
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
