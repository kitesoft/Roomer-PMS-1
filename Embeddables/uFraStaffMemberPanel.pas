unit uFraStaffMemberPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uFraLookupPanel, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraStaffMemberPanel = class(TfraCustomLookupPanel)
  protected
    { Private declarations }
    procedure DoInternalSelect; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
  end;


implementation

{$R *.dfm}

uses
  hData
  , uAppGlobal
  , uG
  , uStaffMembers2;

{ TfraStaffMemberPanel }

constructor TfraStaffMemberPanel.Create(aOwner: TComponent);
begin
  inherited;
  Dataset := glb.Staffmembers;
  CodeField := 'initials';
  DescriptionField := 'name';
end;

procedure TfraStaffMemberPanel.DoInternalSelect;
var
  theData: recStaffMemberHolder;
begin
  inherited;
  theData.Initials := Code;
  if openStaffMembers(actLookup, theData) then
    Code := theData.Initials;
end;

end.
