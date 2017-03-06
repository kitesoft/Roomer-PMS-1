unit uFrmBusyMessage;

interface

uses
  uRoomerForm, Vcl.Controls, Vcl.StdCtrls, sLabel, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk,
  cxClasses, cxPropertiesStore, System.Classes, Vcl.ComCtrls, sStatusBar
  ;

type
  TfrmBusyMessage = class(TfrmBaseRoomerForm)
    __lblMessage: TsLabel;
    __lblHeadline: TsLabel;
  private
  public
    procedure ShowMessage(AHeadline, AMessage : String);
    procedure ChangeMessage(AMessage : String);
    procedure HideMessage;
  end;

function frmBusyMessage: TfrmBusyMessage;

implementation

{$R *.dfm}

uses uRoomerLanguage
     , uUtils
     ;

var
  __frmBusyMessage: TfrmBusyMessage = nil;

function frmBusyMessage: TfrmBusyMessage;
begin
  if not assigned(__frmBusyMessage) then
    __frmBusyMessage := TfrmBusyMessage.Create(nil);

  Result := __frmBusyMessage;
end;

procedure TfrmBusyMessage.ChangeMessage(AMessage: String);
begin
  if NOT Visible then exit;

  __lblMessage.Caption := AMessage;
  __lblMessage.Update;
end;

procedure TfrmBusyMessage.HideMessage;
begin
  Hide;
end;

procedure TfrmBusyMessage.ShowMessage(AHeadline, AMessage: String);
begin
  __lblHeadline.Caption := AHeadline;
  __lblMessage.Caption := AMessage;
  Show;
end;


initialization

finalization
  __frmBusyMessage.Free;
end.
