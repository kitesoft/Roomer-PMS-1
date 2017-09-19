unit uFrmOptInMessage;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls, HTMLabel, sButton, uRoomerDialogForm,
  cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, sPanel, Vcl.ComCtrls, sStatusBar
  ;

type

  TOptInType = (OITPCI, OITOtaToggler);

  TFrmOptInMessage = class(TfrmBaseRoomerDialogForm)
    lblPleaseRead: THTMLabel;
    lblLink: TLinkLabel;
    lblDownload: TLinkLabel;
    procedure FormShow(Sender: TObject);
    procedure lblLinkLinkClick(Sender: TObject; const Link: string; LinkType: TSysLinkType);
  private
    procedure ShowOptInMessage;
    { Private declarations }
  public
    { Public declarations }
    OptInType : TOptInType;
  end;

procedure OpenOptInDialog(OptInType : TOptInType);

implementation

{$R *.dfm}

uses uUtils,
     ShellApi,
     PrjConst;

procedure OpenOptInDialog(OptInType : TOptInType);
var
  _FrmOptInMessage: TFrmOptInMessage;
begin
  _FrmOptInMessage := TFrmOptInMessage.Create(nil);
  try
    _FrmOptInMessage.OptInType := OptInType;
    _FrmOptInMessage.ShowModal;
  finally
    _FrmOptInMessage.Free;
  end;
end;

procedure TFrmOptInMessage.FormShow(Sender: TObject);
begin
  DialogButtons := [mbClose];
  ShowOptInMessage;
end;

procedure TFrmOptInMessage.lblLinkLinkClick(Sender: TObject; const Link: string; LinkType: TSysLinkType);
begin
  ShellExecute(Handle, 'OPEN', PChar(Link), nil, nil, sw_shownormal);
end;

procedure TFrmOptInMessage.ShowOptInMessage;
begin
  lblDownload.Visible := False;
  if OptInType = OITPCI then
  begin
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{PLEASE_NOTE}', GetTranslatedText('OPT_IN_PLEASE_NOTE'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{MESSAGE_1}', GetTranslatedText('OPT_IN_MESSAGE_1'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{MESSAGE_2}', GetTranslatedText('OPT_IN_MESSAGE_2'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{FROM_ROOMER}', GetTranslatedText('OPT_IN_FROM_ROOMER'));

    lblLink.Caption := ReplaceString(lblLink.Caption, '{emailSubject}', format(GetTranslatedText('OPT_IN_EMAIL_SUBJECT'), ['PCI Tokens']));
    lblLink.Caption := ReplaceString(lblLink.Caption, '{emailBody}', GetTranslatedText('OPT_IN_EMAIL_BODY'));
    lblDownload.Visible := True;
  end;
end;

end.
