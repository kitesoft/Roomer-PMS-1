unit uFmrChargePayCard;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Generics.Collections, uTokenHelpers, Vcl.StdCtrls, sLabel, Vcl.ExtCtrls, sPanel, sComboBox, sEdit, sButton,
  uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sMemo;

type

  TPayCardOperationType = (PCO_CHARGE, PCO_PRE_AUTH, PCO_CAPTURE, PCO_REFUND, PCO_VOID);

  TFrmChargePayCard = class(TfrmBaseRoomerForm)
    sPanel1: TsPanel;
    sPanel2: TsPanel;
    sLabel3: TsLabel;
    sLabel4: TsLabel;
    lbRoomReservation: TsLabel;
    lbReservation: TsLabel;
    sLabel1: TsLabel;
    cbxPaycards: TsComboBox;
    sLabel2: TsLabel;
    edAmount: TsEdit;
    sLabel5: TsLabel;
    edCurrency: TsEdit;
    btnProceed: TsButton;
    btnGetCurrency: TsButton;
    lblRate: TsLabel;
    pnlResult: TsPanel;
    sLabel6: TsLabel;
    sLabel7: TsLabel;
    edResAmount: TsEdit;
    edResCurrency: TsEdit;
    lblResRate: TsLabel;
    edResOperationType: TsEdit;
    edResOperationResult: TsEdit;
    sLabel9: TsLabel;
    edResOperationResultDescription: TsEdit;
    sLabel10: TsLabel;
    edResPaymentReference: TsEdit;
    sLabel11: TsLabel;
    sLabel12: TsLabel;
    edResGatewayDescription: TsMemo;
    sLabel13: TsLabel;
    edResGatewayResult: TsEdit;
    sLabel14: TsLabel;
    sLabel8: TsLabel;
    sLabel15: TsLabel;
    sLabel16: TsLabel;
    edResGatewayName: TsEdit;
    procedure FormShow(Sender: TObject);
    procedure btnGetCurrencyClick(Sender: TObject);
    procedure btnProceedClick(Sender: TObject);
    procedure cbxPaycardsCloseUp(Sender: TObject);
  private
    { Private declarations }
    CurrencyRate : Double;
    FOperationResultingCharge: TTokenCharge;
    procedure DisplayRate;
    procedure ProcessChargeSuccess(token : TToken; msg: String);
    procedure CorrectInterface;
    function ParseSettings(token : TToken; XmlString: String): TTokenCharge;
  public
    { Public declarations }
    ReservationId : Integer;
    RoomReservationId : Integer;
    CardTokenId : Integer;
    Amount : Double;
    Currency : String;
    refNumber : String;
    tokenCharge : TTokenCharge;
    token : TToken;
    tokenList : TObjectList<TToken>;
    PayCardOperationType : TPayCardOperationType;
    procedure LoadCards;
    procedure DisplayTokens;

    property OperationResultingCharge : TTokenCharge read FOperationResultingCharge write FOperationResultingCharge;
  end;

const PAY_CARD_OPERATION_TYPE : Array[TPayCardOperationType] of String = ('CHARGE', 'PRE_AUTH', 'CAPTURE', 'REFUND', 'VOID');

function ChargePayCardForPayment(ReservationId : Integer;
                RoomReservationId : Integer;
                Amount : Double;
                Currency : String;
                PayCardOperationType : TPayCardOperationType) : TTokenCharge;

function ChargePayCard(tokenCharge : TTokenCharge;
                token : TToken;
                ReservationId : Integer;
                RoomReservationId : Integer;
                CardTokenId : Integer;
                Amount : Double;
                Currency : String;
                tokenList : TObjectList<TToken>;
                refNumber : String;
                PayCardOperationType : TPayCardOperationType) : TTokenCharge;

implementation

{$R *.dfm}

uses uD,
     cmpRoomerDataSet,
     hData,
     uG,
     uCurrencies,
     Math,
     PrjConst,
     MSXML2_TLB,
     XmlUtils,
     msxmldom,
     XMLDoc,
     Xml.Xmldom,
     Xml.XMLIntf,
     _Glob,
     uUtils
     , UITypes
     ;

const

  XML_PAYMENT_RESPONSE = 'paymentResponse';
  XML_GATEWAY_NAME = 'GatewayName';
  XML_OPERATION_RESULT_CODE = 'OperationResultCode';
  XML_OPERATION_RESULT_DESCRIPTION = 'OperationResultDescription';
  XML_AUTHORIZATION_CODE = 'AuthorizationCode';
  XML_GATEWAY_REFERENCE = 'GatewayReference';
  XML_GATEWAY_RESULT_CODE = 'GatewayResultCode';
  XML_GATEWAY_RESULT_DESCRIPTION = 'GatewayResultDescription';
  XML_OPERATON_TYPE = 'OperationType';
  XML_AMOUNT = 'Amount';
  XML_CURRENCY = 'Currency';

function ChargePayCardForPayment(ReservationId : Integer;
                RoomReservationId : Integer;
                Amount : Double;
                Currency : String;
                PayCardOperationType : TPayCardOperationType) : TTokenCharge;
begin
  result := ChargePayCard(nil,
                nil,
                ReservationId,
                RoomReservationId,
                -9999999,
                Amount,
                Currency,
                nil,
                '',
                PayCardOperationType);
end;

function ChargePayCard(tokenCharge : TTokenCharge;
                token : TToken;
                ReservationId : Integer;
                RoomReservationId : Integer;
                CardTokenId : Integer;
                Amount : Double;
                Currency : String;
                tokenList : TObjectList<TToken>;
                refNumber : String;
                PayCardOperationType : TPayCardOperationType) : TTokenCharge;

var _FrmChargePayCard: TFrmChargePayCard;
begin
  _FrmChargePayCard := TFrmChargePayCard.Create(nil);
  try
    _FrmChargePayCard.token := token;
    _FrmChargePayCard.tokenCharge := tokenCharge;
    _FrmChargePayCard.ReservationId := ReservationId;
    _FrmChargePayCard.RoomReservationId := RoomReservationId;
    _FrmChargePayCard.CardTokenId := CardTokenId;
    _FrmChargePayCard.Amount := Amount;
    _FrmChargePayCard.Currency := Currency;
    _FrmChargePayCard.tokenList := tokenList;
    _FrmChargePayCard.refNumber := refNumber;

    _FrmChargePayCard.PayCardOperationType := PayCardOperationType;

    _FrmChargePayCard.ShowModal;
    result := _FrmChargePayCard.OperationResultingCharge;
  finally
    _FrmChargePayCard.Free;
  end;
end;

procedure TFrmChargePayCard.btnGetCurrencyClick(Sender: TObject);
var
  theData: recCurrencyHolder;
  oldCurrency: string;
  lFactor,
  lOldRate,
  lNewRate : Double;
begin
  oldCurrency := trim(edCurrency.Text);
  theData.Currency := oldCurrency;
  if Currencies(actLookup, theData) and (theData.Currency <> '') then
  begin
    lOldRate := GetRate(oldCurrency);
    lNewRate := GetRate(theData.Currency);

    if lNewRate = 0 then
      lNewRate := 1;
    lFactor := lOldRate / lNewRate;
    CurrencyRate := lNewRate;

    Amount := _StrToFloat(edAmount.Text);

    Amount := RoundTo(Amount * lFactor, 2);

    DisplayRate;
  end;
end;

procedure TFrmChargePayCard.CorrectInterface;
begin
  edAmount.Enabled := (NOT cbxPaycards.Enabled) AND (PayCardOperationType IN [PCO_CHARGE, PCO_PRE_AUTH, PCO_REFUND]);
  edCurrency.Enabled := (NOT cbxPaycards.Enabled) AND (PayCardOperationType IN [PCO_CHARGE, PCO_PRE_AUTH, PCO_REFUND]);
  lbReservation.Caption := inttostr(ReservationId);
  lbRoomReservation.Caption := inttostr(RoomReservationId);
end;

procedure TFrmChargePayCard.btnProceedClick(Sender: TObject);
var s : String;
    tokenId : Integer;
begin
  inherited;

  if (PayCardOperationType = PCO_REFUND) AND (_StrToFloat(edAmount.Text) > tokenCharge.amount) then
  begin
      MessageDlg(GetTranslatedText('PCI_REFUND_TOO_HIGH_AMOUNT'), mtError, [mbOk], 0);
      exit;
  end;

  btnProceed.Enabled := False;
  cbxPaycards.Enabled := False;
  edAmount.Enabled := False;
  edCurrency.Enabled := False;
  edAmount.Enabled := False;
  if cbxPayCards.ItemIndex < 0 then exit;
  token := TToken(cbxPayCards.Items.Objects[cbxPayCards.ItemIndex]);
  tokenId := token.id;
  s := d.roomerMainDataSet.downloadUrlAsStringUsingPost(d.roomerMainDataSet.RoomerUri + format('paycard/bookings/%d/paycardcharges', [ReservationId]),
      format('amount=%s&' +
             'currency=%s&' +
             'description=%s&' +
             'tokenId=%d&' +
             'chargeType=%s&' +
             'gateWayReference=%s',
             [
               edAmount.Text,
               edCurrency.Text,
               '', // description
               tokenId,
               PAY_CARD_OPERATION_TYPE[PayCardOperationType],
               refNumber
             ]
      )
      );
  ProcessChargeSuccess(token, s);
  pnlResult.Visible := True;
end;

procedure TFrmChargePayCard.cbxPaycardsCloseUp(Sender: TObject);
begin
  inherited;
  token := TToken(cbxPaycards.Items.Objects[cbxPaycards.ItemIndex]);
end;

procedure TFrmChargePayCard.ProcessChargeSuccess(token : TToken; msg : String);
var charge : TTokenCharge;
begin
  charge := ParseSettings(token, msg);

  edResAmount.Text := trim(_floattostr(charge.amount, 20, 2));
  edCurrency.Text := charge.currency;
  lblRate.Caption := format('(Rate: %s)', [FloatToStr(charge.currencyRate)]);
  edResOperationType.Text := charge.operationType;

  edResOperationResult.Text := charge.operationResultCode;
  edResOperationResultDescription.Text := charge.operationResultDescription;
  edResPaymentReference.Text := charge.gatewayReference;

  edResGatewayDescription.Text := charge.gatewayResultDescription;
  edResGatewayResult.Text := charge.gatewayResultCode;
  edResGatewayName.Text := charge.gatewayName;

  if LowerCase(charge.operationResultCode) = 'success' then
    FOperationResultingCharge := charge
  else
    FOperationResultingCharge := nil;
end;

function TFrmChargePayCard.ParseSettings(token : TToken; XmlString : String) : TTokenCharge;
var
  XML: IXMLDOMDocument2;
  listNode, rootNode: IXMLDOmNode;
  i : Integer;
  _XML_PAYMENT_RESPONSE,
  _XML_GATEWAY_NAME,
  _XML_OPERATION_RESULT_CODE,
  _XML_OPERATION_RESULT_DESCRIPTION,
  _XML_AUTHORIZATION_CODE,
  _XML_GATEWAY_REFERENCE,
  _XML_GATEWAY_RESULT_CODE,
  _XML_GATEWAY_RESULT_DESCRIPTION,
  _XML_OPERATON_TYPE,
  _XML_CURRENCY : String;
  _XML_AMOUNT : Double;
begin
  xml := CreateXmlDocument;
  xml.loadXML(XmlString);
  listNode := xml.documentElement;
  result := nil;
  _XML_AMOUNT := 0;
  if listNode <> nil then
  begin
    if listNode.nodeName = 'paymentResponse' then
    begin
      with result do
      begin
        for i := 0 to listNode.childNodes.length - 1 do
        begin
          rootNode := listNode.childNodes.item[i];
          with rootNode do
          begin
            if rootNode.nodeName = XML_PAYMENT_RESPONSE then
               _XML_PAYMENT_RESPONSE := rootNode.text
            else
            if rootNode.nodeName = XML_GATEWAY_NAME then
               _XML_GATEWAY_NAME := rootNode.text
            else
            if rootNode.nodeName = XML_OPERATION_RESULT_CODE then
               _XML_OPERATION_RESULT_CODE := rootNode.text
            else
            if rootNode.nodeName = XML_OPERATION_RESULT_DESCRIPTION then
               _XML_OPERATION_RESULT_DESCRIPTION := rootNode.text
            else
            if rootNode.nodeName = XML_AUTHORIZATION_CODE then
               _XML_AUTHORIZATION_CODE := rootNode.text
            else
            if rootNode.nodeName = XML_GATEWAY_REFERENCE then
               _XML_GATEWAY_REFERENCE := rootNode.text
            else
            if rootNode.nodeName = XML_GATEWAY_RESULT_CODE then
               _XML_GATEWAY_RESULT_CODE := rootNode.text
            else
            if rootNode.nodeName = XML_GATEWAY_RESULT_DESCRIPTION then
               _XML_GATEWAY_RESULT_DESCRIPTION := rootNode.text
            else
            if rootNode.nodeName = XML_OPERATON_TYPE then
               _XML_OPERATON_TYPE := rootNode.text
            else
            if rootNode.nodeName = XML_AMOUNT then
               _XML_AMOUNT := _StrToFloat(rootNode.text)
            else
            if rootNode.nodeName = XML_CURRENCY then
               _XML_CURRENCY := rootNode.text;
          end;
        end;
      end;
      result := TTokenCharge.Create(-1, token, _XML_AMOUNT,
                          _XML_CURRENCY, 1.00,
                          _XML_AUTHORIZATION_CODE,
                          _XML_OPERATON_TYPE,
                          _XML_OPERATION_RESULT_CODE,
                          _XML_OPERATION_RESULT_DESCRIPTION,
                          _XML_GATEWAY_NAME,
                          _XML_GATEWAY_REFERENCE,
                          _XML_GATEWAY_RESULT_CODE,
                          _XML_GATEWAY_RESULT_DESCRIPTION,
                          now);
    end;

  end;
end;


procedure TFrmChargePayCard.DisplayRate;
begin
  edAmount.Text := FloatToStr(Amount);
  CurrencyRate := GetRate(edCurrency.Text);
  lblRate.Caption := format('(Rate: %s)', [FloatToStr(CurrencyRate)]);
end;

procedure TFrmChargePayCard.DisplayTokens;
var
  idx : Integer;
  cbxIndex : Integer;
  token : TToken;
begin
  edCurrency.Text := Currency;
  DisplayRate;

  idx := -1;
  for token IN tokenList do
  begin
    cbxIndex := cbxPaycards.Items.AddObject(format('(%s) %s, %s [%s]', [token.CardType, token.CardNumber, token.ExpireDate, token.NameOnCard]), token);
    if token.id = CardTokenId then
      idx := cbxIndex;
  end;
  cbxPaycards.ItemIndex := idx;
end;

procedure TFrmChargePayCard.FormShow(Sender: TObject);
begin
  inherited;
  FOperationResultingCharge := nil;
  pnlResult.Visible := False;
  cbxPaycards.Enabled := False;
  if Assigned(tokenList) then
    DisplayTokens
  else
    LoadCards;

  CorrectInterface;
end;

procedure TFrmChargePayCard.LoadCards;
var
  rSet: TRoomerDataSet;
  xml : String;
  token : TToken;
begin
  if Assigned(tokenList) then
    tokenList.Free;
  tokenList := TObjectList<TToken>.Create;

  lbReservation.Caption := inttostr(ReservationId);
  lbRoomReservation.Caption := inttostr(RoomReservationId);

  rSet := CreateNewDataSet;
  xml := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + format('paycard/bookings/%d/tokens', [ReservationId]));
  rSet := d.roomerMainDataSet.ActivateNewDataset(xml);
  try
    cbxPaycards.Items.BeginUpdate;
    try
      cbxPaycards.Items.Clear;
      rSet.First;
      while NOT rSet.Eof do
      begin
        if (rSet['ID'] = -1) OR (rSet['ROOM_RESERVATION'] = RoomReservationId) OR (rSet['ROOM_RESERVATION'] <= 0) then
        begin
          token := TToken.Create(rSet['ID'],
                        rSet['RESERVATION'],
                        rSet['ROOM_RESERVATION'],
                        rSet['PAYCARD_TOKEN'],
                        rSet['ENABLED'],
                        rSet['NAME_ON_CARD'],
                        rSet['CARD_TYPE'],
                        rSet['USER_ID'],
                        rSet['DESCRIPTION'],
                        rSet['NOTES'],
                        rSet['CREATE_TSTAMP'],

                        rSet['ROOM'],
                        rSet['SOURCE'],

                        rSet['CARD_NUMBER'],
                        rSet['EXP_DATE']);

          tokenList.Add(token);
        end;
        rSet.Next;
      end;
    finally
      cbxPaycards.Items.EndUpdate;
    end;
  finally
    freeandNil(rSet);
  end;
  DisplayTokens;
  cbxPaycards.Enabled := True;
end;


end.
