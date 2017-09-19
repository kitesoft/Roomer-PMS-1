unit uFrmViewPayCardDetails;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uTokenHelpers, Vcl.StdCtrls, sEdit, sLabel, sButton, Vcl.ExtCtrls, sPanel,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sMemo,
  uRoomerForm;

type
  TFrmViewPayCardDetails = class(TfrmBaseRoomerDialogForm)
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    edCardNumber: TsEdit;
    edNameOnCard: TsEdit;
    sLabel3: TsLabel;
    edExpirationDate: TsEdit;
    sLabel4: TsLabel;
    edUser: TsEdit;
    sLabel5: TsLabel;
    edDescription: TsMemo;
    sLabel10: TsLabel;
    edWhen: TsEdit;
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
    token : TToken;
  public
    { Public declarations }
  end;

var
  FrmViewPayCardDetails: TFrmViewPayCardDetails;

procedure DisplayTokenDetails(token : TToken);

implementation

{$R *.dfm}

uses uDateUtils
     ;

procedure DisplayTokenDetails(token : TToken);
var
  _FrmViewPayCardDetails: TFrmViewPayCardDetails;
begin
  _FrmViewPayCardDetails:= TFrmViewPayCardDetails.Create(nil);
  try
    _FrmViewPayCardDetails.token := token;
    _FrmViewPayCardDetails.ShowModal;
  finally
    _FrmViewPayCardDetails.Free;
  end;
end;

function GetFormattedExpirationDate(expirationDate : String) : String;
begin
  if length(expirationDate) < 6 then
    result := expirationDate
  else
    result := copy(expirationDate, 1, 2) + '-' + copy(expirationDate, 3, 4);
end;

procedure TFrmViewPayCardDetails.FormShow(Sender: TObject);
begin
  DialogButtons := [mbClose];

  edWhen.Text := uDateUtils.RoomerDateTimeToString(token.created);
  edCardNumber.Text := token.CardNumber;
  edNameOnCard.Text := token.NameOnCard;
  edExpirationDate.Text := GetFormattedExpirationDate(token.ExpireDate);
  edUser.Text := token.UserId;
  edDescription.Text := token.Description;
end;

end.
