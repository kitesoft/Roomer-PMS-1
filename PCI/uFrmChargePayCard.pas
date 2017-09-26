unit uFrmChargePayCard;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Generics.Collections, uTokenHelpers, Vcl.StdCtrls, sLabel, Vcl.ExtCtrls, sPanel, sComboBox, sEdit, sButton,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sMemo,
  uRoomerForm, ufraCurrencyPanel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sCurrEdit, sCurrencyEdit
  , RoomerExceptionHandling;

type
  EChargePaycardException = class(ERoomerException);

  TPayCardOperationType = (PCO_CHARGE, PCO_PRE_AUTH, PCO_CAPTURE, PCO_REFUND, PCO_VOID);

  TFrmChargePayCard = class(TfrmBaseRoomerDialogForm)
    pnlTop: TsPanel;
    sLabel3: TsLabel;
    sLabel4: TsLabel;
    lbRoomReservation: TsLabel;
    lbReservation: TsLabel;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    sLabel5: TsLabel;
    cbxPaycards: TsComboBox;
    btnProceed: TsButton;
    pnlBottom: TsPanel;
    pnlResult: TsPanel;
    sLabel6: TsLabel;
    sLabel7: TsLabel;
    lblResRate: TsLabel;
    sLabel9: TsLabel;
    sLabel10: TsLabel;
    sLabel11: TsLabel;
    sLabel12: TsLabel;
    sLabel13: TsLabel;
    sLabel14: TsLabel;
    sLabel8: TsLabel;
    sLabel15: TsLabel;
    sLabel16: TsLabel;
    edResAmount: TsEdit;
    edResCurrency: TsEdit;
    edResOperationType: TsEdit;
    edResOperationResult: TsEdit;
    edResOperationResultDescription: TsEdit;
    edResPaymentReference: TsEdit;
    edResGatewayDescription: TsMemo;
    edResGatewayResult: TsEdit;
    edResGatewayName: TsEdit;
    fraCurrency: TfraCurrencyPanel;
    edAmount: TsCurrencyEdit;
    procedure FormShow(Sender: TObject);
    procedure btnProceedClick(Sender: TObject);
    procedure cbxPaycardsCloseUp(Sender: TObject);
    procedure edAmountChange(Sender: TObject);
    procedure cbxPaycardsChange(Sender: TObject);
  private
    { Private declarations }
    CurrencyRate : Double;
    FOperationResultingCharge: TTokenCharge;
    FPaycardOperationType: TPayCardOperationType;
    procedure ProcessChargeSuccess(token : TToken; msg: String);
    function ParseSettings(token : TToken; XmlString: String): TTokenCharge;
    procedure evtCurrencyChangedAndValid(Sender: TObject);
    procedure evtCurrencyChanged(Sender: TObject);
    procedure SetPaycardOperationType(const Value: TPayCardOperationType);
  protected
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    ReservationId : Integer;
    RoomReservationId : Integer;
    CardTokenId : Integer;
    Amount : Currency;
    Currency : String;
    refNumber : String;
    tokenCharge : TTokenCharge;
    token : TToken;
    tokenList : TObjectList<TToken>;
    property PayCardOperationType : TPayCardOperationType read FPaycardOperationType write SetPaycardOperationType;
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

function RefundChargeFromChargeId(ReservationId: integer; RoomReservationId: integer; ChargeId: integer): TTokenCharge;

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
     , UITypes;

const

  XML_PAYMENT_RESPONSE = 'paymentResponse';
  XML_GATEWAY_NAME = 'gatewayName';
  XML_OPERATION_RESULT_CODE = 'operationresultcode';
  XML_OPERATION_RESULT_DESCRIPTION = 'operationresultdescription';
  XML_AUTHORIZATION_CODE = 'authorizationcode';
  XML_GATEWAY_REFERENCE = 'gatewayreference';
  XML_GATEWAY_RESULT_CODE = 'gatewayresultcode';
  XML_GATEWAY_RESULT_DESCRIPTION = 'gatewayresultdescription';
  XML_OPERATON_TYPE = 'operationtype';
  XML_AMOUNT = 'amount';
  XML_CURRENCY = 'currency';
  XML_RESERVATION = 'reservation';
  XML_ROOMRESERVATION = 'roomreservation';


function RefundChargeFromChargeId(ReservationId: integer; RoomReservationId: integer; ChargeId: integer): TTokenCharge;
var
  xml: string;
  lCharge: TTokenCharge;
  rSet: TRoomerDataSet;
begin
  Result := nil;
  try
    xml := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri+ format('paycard/bookings/charges/%d', [chargeId]));
    rSet := d.roomerMainDataSet.ActivateNewDataset(xml);
    try
      rSet.First;
      if rSet.Locate('ID, Reservation, Room_reservation', VarArrayOf([chargeid, ReservationId, RoomReservationid]), []) then
      begin
        lCharge := TTokenCharge.Create(
                      chargeId,
                      nil,
                      ReservationId,
                      RoomreservationId,
                      rSet['AMOUNT'],
                      rSet['CURRENCY'],
                      rSet['CURRENCY_RATE'],
                      rSet['AUTHORIZATION_CODE'],
                      rSet['OPERATION_TYPE'],
                      rSet['OPERATION_RESULT_CODE'],
                      rSet['OPERATION_RESULT_DESCRIPTION'],
                      rSet['GATEWAY_NAME'],
                      rSet['GATEWAY_REFERENCE'],
                      rSet['GATEWAY_RESULT_CODE'],
                      rSet['GATEWAY_RESULT_DESCRIPTION'],
                      rSet['TSTAMP']);

        result := ChargePayCard(lcharge,
                      lcharge.token,
                      lcharge.token.Reservation,
                      lcharge.token.RoomReservation,
                      lcharge.token.id,
                      lcharge.amount,
                      lcharge.currency,
                      nil,
                      lcharge.gatewayReference,
                      PCO_REFUND);

      end
      else
        raise EChargePaycardException.CreateFmt('Paycard charge [%d] not found for reservation [%d/%d]', [chargeId, ReservationId, RoomReservationid]);
    finally
      rSet.Free;
    end;

  except
    on E: Exception do
      raise EChargePaycardException.CreateFmt('Error occured while refunding for Reservation [%d/%d]' +#13 + e.Message, [ ReservationId, RoomReservationid]);
  end;
end;


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



procedure TFrmChargePayCard.DoUpdateControls;
begin
  inherited;
  lbReservation.Caption := inttostr(ReservationId);

  if RoomReservationId > 0 then
    lbRoomReservation.Caption := inttostr(RoomReservationId)
  else
    lbRoomReservation.Caption := '(Group)';


  edAmount.Enabled := (NOT cbxPaycards.Enabled) AND (PayCardOperationType IN [PCO_CHARGE, PCO_PRE_AUTH, PCO_REFUND]);
  fraCurrency.Enabled :=  (NOT cbxPaycards.Enabled) AND (PayCardOperationType IN [PCO_CHARGE, PCO_PRE_AUTH, PCO_REFUND]);

  btnProceed.Enabled := (edAmount.value > 0) and fraCurrency.IsValid and (cbxPaycards.ItemIndex >= 0);
end;

procedure TFrmChargePayCard.btnProceedClick(Sender: TObject);
var s : String;
    tokenId : Integer;
begin
  inherited;

  if (PayCardOperationType = PCO_REFUND) AND (edAmount.Value > tokenCharge.amount) then
  begin
      MessageDlg(GetTranslatedText('PCI_REFUND_TOO_HIGH_AMOUNT'), mtError, [mbOk], 0);
      exit;
  end;

  if cbxPayCards.ItemIndex < 0 then exit;

  btnProceed.Enabled := False;
  cbxPaycards.Enabled := False;
  edAmount.Enabled := False;
  fraCurrency.Enabled := False;
  edAmount.Enabled := False;
  try
    token := TToken(cbxPayCards.Items.Objects[cbxPayCards.ItemIndex]);
    tokenId := token.id;
    s := d.roomerMainDataSet.downloadUrlAsStringUsingPost(d.roomerMainDataSet.RoomerUri + format('paycard/bookings/%d/%d/paycardcharges', [ReservationId, RoomReservationId]),
        format('amount=%s&' +
               'currency=%s&' +
               'description=%s&' +
               'tokenId=%d&' +
               'chargeType=%s&' +
               'gateWayReference=%s',
               [
                 edAmount.Text,
                 fraCurrency.CurrencyCode,
                 '', // description
                 tokenId,
                 PAY_CARD_OPERATION_TYPE[PayCardOperationType],
                 refNumber
               ]
        )
        );
    ProcessChargeSuccess(token, s);
    pnlBottom.Visible := True;
  finally
    btnProceed.Enabled := False;
    cbxPaycards.Enabled := False;
    edAmount.Enabled := False;
    fraCurrency.Enabled := False;
    edAmount.Enabled := False;
  end;
end;

procedure TFrmChargePayCard.cbxPaycardsChange(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmChargePayCard.cbxPaycardsCloseUp(Sender: TObject);
begin
  inherited;
  if (cbxPaycards.ItemIndex >= 0) and assigned(cbxPaycards.Items.Objects[cbxPaycards.ItemIndex]) then
    token := TToken(cbxPaycards.Items.Objects[cbxPaycards.ItemIndex])
  else
    token := nil;
end;

procedure TFrmChargePayCard.ProcessChargeSuccess(token : TToken; msg : String);
var charge : TTokenCharge;
begin
  charge := ParseSettings(token, msg);

  edResAmount.Text := trim(_floattostr(charge.amount, 20, 2));
  edResCurrency.Text := charge.currency;
  lblResRate.Caption := format('(Rate: %s)', [FloatToStr(charge.currencyRate)]);
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

procedure TFrmChargePayCard.SetPaycardOperationType(const Value: TPayCardOperationType);
begin
  FPaycardOperationType := Value;
  btnProceed.Caption := PAY_CARD_OPERATION_TYPE[Value];
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
  _XML_ROOMRESERVATION : integer;
begin
  xml := CreateXmlDocument;
  xml.loadXML(XmlString);
  listNode := xml.documentElement;
  result := nil;
  _XML_AMOUNT := 0;
  _XML_ROOMRESERVATION := 0;
  if listNode <> nil then
  begin
    if Sametext(listNode.nodeName, 'paymentresponse') then
    begin
      with result do
      begin
        for i := 0 to listNode.childNodes.length - 1 do
        begin
          rootNode := listNode.childNodes.item[i];
          with rootNode do
          begin
            if SameText(rootNode.nodeName, XML_PAYMENT_RESPONSE) then
               _XML_PAYMENT_RESPONSE := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_GATEWAY_NAME) then
               _XML_GATEWAY_NAME := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_OPERATION_RESULT_CODE) then
               _XML_OPERATION_RESULT_CODE := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_OPERATION_RESULT_DESCRIPTION) then
               _XML_OPERATION_RESULT_DESCRIPTION := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_AUTHORIZATION_CODE) then
               _XML_AUTHORIZATION_CODE := rootNode.text
            else
            if SameText(rootNode.nodeName,  XML_GATEWAY_REFERENCE) then
               _XML_GATEWAY_REFERENCE := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_GATEWAY_RESULT_CODE) then
               _XML_GATEWAY_RESULT_CODE := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_GATEWAY_RESULT_DESCRIPTION) then
               _XML_GATEWAY_RESULT_DESCRIPTION := rootNode.text
            else
            if SameText(rootNode.nodeName,  XML_OPERATON_TYPE) then
               _XML_OPERATON_TYPE := rootNode.text
            else
            if SameText(rootNode.nodeName, XML_AMOUNT) then
               _XML_AMOUNT := _StrToFloat(rootNode.text)
            else
            if SameText(rootNode.nodeName,  XML_ROOMRESERVATION) then
               _XML_ROOMRESERVATION := StrToIntDef(rootNode.text, 0)
            else
            if SameText(rootNode.nodeName, XML_CURRENCY) then
               _XML_CURRENCY := rootNode.text;
          end;
        end;
      end;
      result := TTokenCharge.Create(-1, token,
                          ReservationId,
                          _XML_ROOMRESERVATION,
                          _XML_AMOUNT,
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


procedure TFrmChargePayCard.DisplayTokens;
var
  idx : Integer;
  cbxIndex : Integer;
  token : TToken;
begin
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
  pnlBottom.Visible := False;
  cbxPaycards.Enabled := False;
  if Assigned(tokenList) then
    DisplayTokens
  else
    LoadCards;

  fraCurrency.DisableEvents;
  try
    fraCurrency.CurrencyCode := Currency;
    CurrencyRate := fraCurrency.CurrencyRate;
  finally
    fraCurrency.EnableEvents;
  end;

  edAmount.Value := Amount;
  DialogButtons := [mbClose];
  fraCurrency.OnCurrencyChangeAndValid := evtCurrencyChangedAndValid;
  fraCurrency.OnCurrencyChange := evtCurrencyChanged;
end;

procedure TFrmChargePayCard.edAmountChange(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TFrmChargePayCard.evtCurrencyChanged(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmChargePayCard.evtCurrencyChangedAndValid(Sender: TObject);
begin
  if not SameValue(fraCurrency.CurrencyRate, CurrencyRate) then
  begin
    edAmount.value := edAmount.Value * CurrencyRate / fraCurrency.CurrencyRate;
    CurrencyRate := fraCurrency.CurrencyRate;
  end;
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
