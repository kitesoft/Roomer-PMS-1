unit uFrmChargePayCard;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Generics.Collections, uTokenHelpers, Vcl.StdCtrls, sLabel, Vcl.ExtCtrls, sPanel, sComboBox, sEdit, sButton,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sMemo,
  uRoomerForm, ufraCurrencyPanel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sCurrEdit, sCurrencyEdit
  , RoomerExceptionHandling;

type
  EChargePaycardException = class(ERoomerUserException);

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
    FAmountIsFixed: boolean;
    FExternalTokenList: TObjectList<TToken>;
    FOwnedTokenList: TObjectList<TToken>;
    procedure ProcessChargeSuccess(token : TToken; msg: String);
    function ParseSettings(token : TToken; XmlString: String): TTokenCharge;
    procedure evtCurrencyChangedAndValid(Sender: TObject);
    procedure evtCurrencyChanged(Sender: TObject);
    procedure SetPaycardOperationType(const Value: TPayCardOperationType);
    procedure SetTokenList(const Value: TObjectList<TToken>);
    function GetTokenList: TObjectList<TToken>;
    procedure LoadCards;
    procedure DisplayTokens;
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

    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;

    /// <summary>
    ///   List of tokens defined for the set reservation. If not provided extrnally, a local one is created and populated
    /// </summary>
    property TokenList: TObjectList<TToken> read GetTokenList write SetTokenList;
    property PayCardOperationType : TPayCardOperationType read FPaycardOperationType write SetPaycardOperationType;
    property AmountIsFixed: boolean read FAmountIsFixed write FAMountIsFixed;

    property OperationResultingCharge : TTokenCharge read FOperationResultingCharge write FOperationResultingCharge;
  end;

const PAY_CARD_OPERATION_TYPE : Array[TPayCardOperationType] of String = ('CHARGE', 'PRE_AUTH', 'CAPTURE', 'REFUND', 'VOID');

function ChargePayCardForPayment(ReservationId : Integer;
                RoomReservationId : Integer;
                Amount : Double;
                Currency : String;
                PayCardOperationType : TPayCardOperationType;
                AmountIsFixed: boolean = false) : TTokenCharge;

function ChargePayCard(tokenCharge : TTokenCharge;
                token : TToken;
                ReservationId : Integer;
                RoomReservationId : Integer;
                CardTokenId : Integer;
                Amount : Double;
                Currency : String;
                tokenList : TObjectList<TToken>;
                refNumber : String;
                PayCardOperationType : TPayCardOperationType;
                AmountIsFixed: boolean = false) : TTokenCharge;

function RefundChargeFromChargeId(ReservationId: integer; RoomReservationId: integer; ChargeId: integer): TTokenCharge;

implementation

{$R *.dfm}

uses Data.DB,
     uD,
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
     , Types
     , uFrmManagePCIConnection;

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

  NO_TOKEN_ID = -9999999;

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
      if not rSet.IsEmpty then
      begin
        rSet.First;
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
                      ReservationId,
                      RoomReservationId,
                      NO_TOKEN_ID,
                      lcharge.amount,
                      lcharge.currency,
                      nil,
                      lcharge.gatewayReference,
                      PCO_REFUND,
                      False);

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
                PayCardOperationType : TPayCardOperationType;
                AmountIsFixed: boolean) : TTokenCharge;
begin
  result := ChargePayCard(nil,
                nil,
                ReservationId,
                RoomReservationId,
                NO_TOKEN_ID,
                Amount,
                Currency,
                nil,
                '',
                PayCardOperationType,
                AmountIsFixed);
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
                PayCardOperationType : TPayCardOperationType;
                AmountIsFixed: boolean) : TTokenCharge;

var
  _FrmChargePayCard: TFrmChargePayCard;
begin
  Result := nil;

  if not PCIBookingConfigured then
  begin
    ManagePCIConnection;
    if not PCIBookingConfigured then
      Exit;
  end;


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
    _FrmChargePayCard.AmountIsFixed := AmountIsFixed;

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

  edAmount.Enabled := (NOT AmountIsFixed) AND (PayCardOperationType IN [PCO_CHARGE, PCO_PRE_AUTH, PCO_REFUND]);
  fraCurrency.Enabled := edAmount.Enabled;

  btnProceed.Enabled := (edAmount.value > 0) and fraCurrency.IsValid and (cbxPaycards.ItemIndex >= 0);
end;

procedure TFrmChargePayCard.btnProceedClick(Sender: TObject);
var s : String;
    tokenId : Integer;
begin
  inherited;

  if (PayCardOperationType = PCO_REFUND) AND (CompareValue(edAmount.Value, tokenCharge.amount, 0.01) = GreaterThanValue) then
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
                 FloatToXML(edAmount.Value, 2),
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

constructor TFrmChargePayCard.Create(aOwner: TComponent);
begin
  inherited;
  FOwnedTokenList :=  TObjectList<TToken>.Create();
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

procedure TFrmChargePayCard.SetTokenList(const Value: TObjectList<TToken>);
begin
  FExternalTokenList := Value;
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
      result := TTokenCharge.Create(-1,
                          token,
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


destructor TFrmChargePayCard.Destroy;
begin
  FOwnedTokenList.Free;
  inherited;
end;

procedure TFrmChargePayCard.DisplayTokens;
var
  idx : Integer;
  cbxIndex : Integer;
  token : TToken;
begin
  idx := -1;
  cbxPaycards.Items.BeginUpdate;
  try
    cbxPaycards.Enabled := false;
    cbxPaycards.Items.clear;
    for token IN TokenList do
    begin
      cbxIndex := cbxPaycards.Items.AddObject(format('(%s) %s, %s [%s]', [token.CardType, token.CardNumber, token.ExpireDate, token.NameOnCard]), token);
      if token.id = CardTokenId then
        idx := cbxIndex;
    end;
    cbxPaycards.ItemIndex := idx;
  finally
    cbxPaycards.Items.EndUpdate;
    cbxPaycards.Enabled := true;
  end;
end;

procedure TFrmChargePayCard.FormShow(Sender: TObject);
begin
  inherited;
  FOperationResultingCharge := nil;
  pnlBottom.Visible := False;
  cbxPaycards.Enabled := False;
  if (TokenList.Count > 0) then
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

function TFrmChargePayCard.GetTokenList: TObjectList<TToken>;
begin
  if assigned(FExternalTokenList) then
    Result := FExternalTokenList
  else
    Result := FOwnedTokenList;
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
begin
  LoadAllTokens(ReservationId, RoomReservationId, Tokenlist);
  DisplayTokens;
end;


end.
