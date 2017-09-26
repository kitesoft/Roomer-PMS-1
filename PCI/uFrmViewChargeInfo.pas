unit uFrmViewChargeInfo;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uTokenHelpers, Vcl.StdCtrls, sEdit, sLabel, sButton, Vcl.ExtCtrls, sPanel,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sMemo, Vcl.Menus,
  uRoomerForm, Vcl.Mask, sMaskEdit, sCustomComboEdit, sCurrEdit, sCurrencyEdit;

type
  TFrmViewChargeInfo = class(TfrmBaseRoomerDialogForm)
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    edOperation: TsEdit;
    edAutCode: TsEdit;
    sLabel3: TsLabel;
    edAmount: TsCurrencyEdit;
    edCurrency: TsEdit;
    sLabel4: TsLabel;
    edOperationResult: TsEdit;
    sLabel5: TsLabel;
    edOperationResultDescription: TsMemo;
    sLabel6: TsLabel;
    edGatewayName: TsEdit;
    sLabel7: TsLabel;
    edGatewayReference: TsEdit;
    sLabel8: TsLabel;
    edGatewayResultCode: TsEdit;
    sLabel9: TsLabel;
    edGatewayResultDescription: TsMemo;
    sLabel10: TsLabel;
    edWhen: TsEdit;
    pupCharge: TPopupMenu;
    mnuCapture: TMenuItem;
    mnuVoid: TMenuItem;
    mnyRefund: TMenuItem;
    btnRefundOrCapture: TsButton;
    sLabel11: TsLabel;
    sLabel12: TsLabel;
    edReservation: TsEdit;
    procedure FormShow(Sender: TObject);
    procedure pupChargePopup(Sender: TObject);
    procedure mnuCaptureClick(Sender: TObject);
    procedure mnuVoidClick(Sender: TObject);
    procedure mnyRefundClick(Sender: TObject);
  private
    { Private declarations }
    charge : TTokenCharge;
  public
    { Public declarations }
  end;

procedure DisplayCharge(charge : TTokenCharge);

implementation

{$R *.dfm}

uses uDateUtils,
     uFrmChargePayCard
     , hData;

procedure DisplayCharge(charge : TTokenCharge);
var
  _FrmViewChargeInfo: TFrmViewChargeInfo;
begin
  _FrmViewChargeInfo:= TFrmViewChargeInfo.Create(nil);
  try
    _FrmViewChargeInfo.charge := charge;
    _FrmViewChargeInfo.ShowModal;
  finally
    _FrmViewChargeInfo.Free;
  end;
end;

procedure TFrmViewChargeInfo.FormShow(Sender: TObject);
var
  lRoom: string;
begin
  DialogButtons := [mbClose];

    if (charge.RoomReservation) > 0 then
      lRoom := 'Room ' + hData.RR_GetRoomNumber(charge.RoomReservation)
    else
      lRoom := 'Group';

  edReservation.Text := Format('%d / %s', [charge.Reservation, lRoom]);
  edWhen.Text := uDateUtils.RoomerDateTimeToString(charge.created);
  edOperation.Text := charge.operationType;
  edAutCode.Text := charge.authCode;
  edAmount.Value:= charge.amount;
  edCurrency.Text := charge.currency;
  edOperationResult.Text := charge.operationResultCode;
  edOperationResultDescription.Text := charge.operationResultDescription;
  edGatewayName.Text := charge.gatewayName;
  edGatewayReference.Text := charge.gatewayReference;
  edGatewayResultCode.Text := charge.gatewayResultCode;
  edGatewayResultDescription.Text := charge.gatewayResultDescription;
  if charge.operationType = 'CHARGE' then
    btnRefundOrCapture.Caption := 'Refund'
  else if charge.operationType = 'PRE_AUTH' then
    btnRefundOrCapture.Caption := 'CAPTURE';

  btnRefundOrCapture.Visible := (charge.operationType = 'CHARGE') OR (charge.operationType = 'PRE_AUTH');

end;

procedure TFrmViewChargeInfo.mnuCaptureClick(Sender: TObject);
begin
  inherited;
  ChargePayCard(charge,
                charge.token,
                charge.token.Reservation,
                charge.token.RoomReservation,
                charge.token.id,
                charge.amount,
                charge.currency,
                nil,
                charge.gatewayReference,
                PCO_CAPTURE,
                False);
end;

procedure TFrmViewChargeInfo.mnuVoidClick(Sender: TObject);
begin
  inherited;
  ChargePayCard(charge,
                charge.token,
                charge.token.Reservation,
                charge.token.RoomReservation,
                charge.token.id,
                charge.amount,
                charge.currency,
                nil,
                charge.gatewayReference,
                PCO_VOID,
                False);
end;

procedure TFrmViewChargeInfo.mnyRefundClick(Sender: TObject);
begin
  inherited;
  ChargePayCard(charge,
                charge.token,
                charge.token.Reservation,
                charge.token.RoomReservation,
                charge.token.id,
                charge.amount,
                charge.currency,
                nil,
                charge.gatewayReference,
                PCO_REFUND,
                False);
end;

procedure TFrmViewChargeInfo.pupChargePopup(Sender: TObject);
begin
  inherited;
  mnyRefund.Enabled := (LowerCase(charge.operationResultCode) = 'success') AND
                       ((LowerCase(charge.operationType) = 'charge') OR
                        (LowerCase(charge.operationType) = 'capture'));
  mnuVoid.Enabled := (LowerCase(charge.operationResultCode) = 'success') AND
                        (LowerCase(charge.operationType) = 'capture');
  mnuCapture.Enabled := (LowerCase(charge.operationResultCode) = 'success') AND
                        (LowerCase(charge.operationType) = 'preauth');
end;

end.
