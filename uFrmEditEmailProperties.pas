unit uFrmEditEmailProperties;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, sPanel, sEdit, sLabel, sComboBox
     , uResourceTypeDefinitions
  ;

type
  TFrmEditEmailProperties = class(TForm)
    sPanel2: TsPanel;
    sButton1: TsButton;
    sButton2: TsButton;
    sLabel1: TsLabel;
    edtName: TsEdit;
    edtSubject: TsEdit;
    sLabel2: TsLabel;
    cbxResourceType: TsComboBox;
    sLabel3: TsLabel;
    procedure FormCreate(Sender: TObject);
    procedure cbxResourceTypeChange(Sender: TObject);
  private
    FResourceTypes: TResourceTypeSet;
    procedure SetResourceTypes(const Value: TResourceTypeSet);
    { Private declarations }
  public
    function SelectedResourceType: TResourceType;
    { Public declarations }
    property ResourceTypes: TResourceTypeSet read FResourceTypes write SetResourceTypes;
  end;

var
  FrmEditEmailProperties: TFrmEditEmailProperties;

implementation

{$R *.dfm}

uses uRoomerLanguage,
     uAppGlobal
     , uUtils
     ;

procedure TFrmEditEmailProperties.cbxResourceTypeChange(Sender: TObject);
begin
  if cbxResourceType.ItemIndex >= 0 then
  begin
    if edtName.Text = '' then
      edtName.Text := TResourceType(cbxResourceType.Items.Objects[cbxResourceType.ItemIndex]).DefaultFilename;
  end
  else
    edtName.Text := '';
end;

procedure TFrmEditEmailProperties.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  TResourceType.AsStrings(cbxResourceType.Items);
end;

function TFrmEditEmailProperties.SelectedResourceType: TResourceType;
begin
  if cbxResourceType.ItemIndex >= 0 then
    Result := TResourceType(cbxResourceType.Items.Objects[cbxResourceType.ItemIndex])
  else
    Result := rtAnyFile;
end;

procedure TFrmEditEmailProperties.SetResourceTypes(const Value: TResourceTypeSet);
begin
  FResourceTypes := Value;
  FResourceTypes.AsStrings(cbxResourceType.Items);
  if FResourceTypes.Count = 1 then
  begin
    cbxResourceType.ItemIndex := 0;
    cbxResourceType.Enabled := false;
  end;
end;

end.
