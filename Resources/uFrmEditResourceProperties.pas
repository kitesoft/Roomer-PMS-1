unit uFrmEditResourceProperties;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, sPanel, sEdit, sLabel, sComboBox
  , cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar
  , uResourceTypeDefinitions
  , uRoomerDialogForm
  ;

type
  TFrmEditResourceProperties = class(TfrmBaseRoomerDialogForm)
    lbResourceName: TsLabel;
    edtName: TsEdit;
    edtSubject: TsEdit;
    lbSubject: TsLabel;
    cbxResourceType: TsComboBox;
    lbResourceType: TsLabel;
    procedure cbxResourceTypeChange(Sender: TObject);
    procedure edtNameChange(Sender: TObject);
  private
    FResourceTypes: TResourceTypeSet;
    procedure SetResourceTypes(const Value: TResourceTypeSet);
    { Private declarations }
  protected
    procedure DoUpdateControls; override;
    procedure Loaded; override;
  public
    function SelectedResourceType: TResourceType;
    { Public declarations }
    property ResourceTypes: TResourceTypeSet read FResourceTypes write SetResourceTypes;
  end;


implementation

{$R *.dfm}

uses uRoomerLanguage,
     uAppGlobal
     , uUtils
     ;

procedure TFrmEditResourceProperties.cbxResourceTypeChange(Sender: TObject);
begin
  if cbxResourceType.ItemIndex >= 0 then
  begin
    if edtName.Text = '' then
      edtName.Text := TResourceType(cbxResourceType.Items.Objects[cbxResourceType.ItemIndex]).DefaultFilename;
  end
  else
    edtName.Text := '';

  UpdateControls;
end;

procedure TFrmEditResourceProperties.DoUpdateControls;
begin
  inherited;
  if cbxResourceType.Items.Count  = 1 then
    cbxResourceType.ItemIndex := 0;

  cbxResourceType.Enabled := cbxResourceType.Items.Count > 1;

  edtSubject.Enabled := SelectedResourceType in cEmailTemplateResourceTypes;
  btnOK.Enabled := (edtName.Text <> '') and (cbxResourceType.ItemIndex >= 0);
end;

procedure TFrmEditResourceProperties.edtNameChange(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmEditResourceProperties.Loaded;
begin
  inherited;
  // Load all resourcetypes by default, cna be overriden later by SetResourceType
  TResourceType.AsStrings(cbxResourceType.Items);
end;

function TFrmEditResourceProperties.SelectedResourceType: TResourceType;
begin
  if cbxResourceType.ItemIndex >= 0 then
    Result := TResourceType(cbxResourceType.Items.Objects[cbxResourceType.ItemIndex])
  else
    Result := rtAnyFile;
end;

procedure TFrmEditResourceProperties.SetResourceTypes(const Value: TResourceTypeSet);
begin
  FResourceTypes := Value;
  FResourceTypes.AsStrings(cbxResourceType.Items);
  UpdateControls;
end;

end.
