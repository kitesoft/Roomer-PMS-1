unit uTokenHelpers;

interface

uses Generics.Collections, sComboBox;

type

  TPCITokenOperationType = (PRE_AUTH, CAPTURE, CHARGE, REFUND, VOID);
  TPCITokenOperationTypeHelper = record helper for TPCITokenOperationType
    class function FromString(const value: String): TPCITokenOperationType; static;
    function ToString: string;
  end;

  TToken = class
  private
    FEnabled: Boolean;
    FRoom: String;
    FSource: String;
    FNotes: String;
    FUserId: String;
    FCardType: String;
    FReservation: Integer;
    FCreated: TDateTime;
    Fid: Integer;
    FToken: String;
    FRoomReservation: Integer;
    FDescription: String;
    FNameOnCard: String;
    FExpireDate: String;
    FCardNumber: String;
    function GetCardNumber: String;
     public
       constructor Create(id : Integer;
                  Reservation : Integer;
                  RoomReservation : Integer;
                  Token : String;
                  Enabled : Boolean;
                  NameOnCard : String;
                  CardType : String;
                  UserId : String;
                  Description : String;
                  Notes : String;
                  Created : TDateTime;
                  Room : String;
                  Source : String;
                  CardNumber : String;
                  ExpireDate : String);

       property id : Integer read Fid write Fid;
       property Reservation : Integer read FReservation write FReservation;
       property RoomReservation : Integer read FRoomReservation write FRoomReservation;
       property Token : String read FToken write FToken;
       property Enabled : Boolean read FEnabled write FEnabled;
       property NameOnCard : String read FNameOnCard write FNameOnCard;
       property CardType : String read FCardType write FCardType;
       property UserId : String read FUserId write FUserId;
       property Description : String read FDescription write FDescription;
       property Notes : String read FNotes write FNotes;
       property Created : TDateTime read FCreated write FCreated;
       property Room : String read FRoom write FRoom;
       property Source : String read FSource write FSource;
       property CardNumber : String read GetCardNumber write FCardNumber;
       property ExpireDate : String read FExpireDate write FExpireDate;
     end;

  TTokenCharge = class
  private
    Ftoken : TToken;
    FoperationResultDescription: String;
    FgatewayResultDescription: String;
    FcurrencyRate: Double;
    Fcreated: TDateTime;
    Fid: Integer;
    Famount: Double;
    FgatewayReference: String;
    FoperationResultCode: String;
    FgatewayName: String;
    FgatewayResultCode: String;
    Fcurrency: String;
    FoperationType: String;
    FauthCode: String;
  public
    constructor Create(id : Integer; token : TToken; amount : Double; currency : String; currencyRate : Double;
        authCode : String; operationType : String; operationResultCode : String; operationResultDescription : String;
        gatewayName : String; gatewayReference : String; gatewayResultCode : String; gatewayResultDescription : String;
        created : TDateTime);

    property id: Integer read Fid write Fid;
    property token : TToken read Ftoken write Ftoken;
    property amount: Double read Famount write Famount;
    property currency: String read Fcurrency write Fcurrency;
    property currencyRate: Double read FcurrencyRate write FcurrencyRate;
    property authCode: String read FauthCode write FauthCode;
    property operationType: String read FoperationType write FoperationType;
    property operationResultCode: String read FoperationResultCode write FoperationResultCode;
    property operationResultDescription: String read FoperationResultDescription write FoperationResultDescription;
    property gatewayName: String read FgatewayName write FgatewayName;
    property gatewayReference: String read FgatewayReference write FgatewayReference;
    property gatewayResultCode: String read FgatewayResultCode write FgatewayResultCode;
    property gatewayResultDescription: String read FgatewayResultDescription write FgatewayResultDescription;
    property created: TDateTime read Fcreated write Fcreated;
  end;

function LoadAllTokens(ReservationId, RoomReservationId : Integer) : TObjectList<TToken>;
procedure FillTokenComboBox(cb : TsComboBox; tokens :TObjectList<TToken>; selectedToken : Integer);

implementation

uses TypInfo, uD, cmpRoomerDataset, SysUtils;

{ TToken }

constructor TToken.Create(id, Reservation, RoomReservation: Integer; Token: String; Enabled: Boolean; NameOnCard, CardType, UserId, Description, Notes: String;
  Created: TDateTime; Room, Source: String;
                  CardNumber : String;
                  ExpireDate : String);
begin
  FEnabled := Enabled;
  FRoom := Room;
  FSource := Source;
  FNotes := Notes;
  FUserId := UserId;
  FCardType := CardType;
  FReservation := Reservation;
  FCreated := Created;
  Fid := id;
  FToken := Token;
  FRoomReservation := RoomReservation;
  FDescription := Description;
  FNameOnCard := NameOnCard;
  FCardNumber := CardNumber;
  FExpireDate := ExpireDate;
end;

function TToken.GetCardNumber: String;
begin
  Result := FCardNumber;
  if FCardNumber = '' then
    Result := 'Card example not available';
end;

{ TTokenCharge }

constructor TTokenCharge.Create(id: Integer; token : TToken; amount: Double; currency: String; currencyRate: Double; authCode, operationType,
  operationResultCode, operationResultDescription, gatewayName, gatewayReference, gatewayResultCode, gatewayResultDescription: String; created: TDateTime);
begin
  Ftoken := token;
  FoperationResultDescription := operationResultDescription;
  FgatewayResultDescription := gatewayResultDescription;
  FcurrencyRate := currencyRate;
  Fcreated := created;
  Fid := id;
  Famount := amount;
  FgatewayReference := gatewayReference;
  FoperationResultCode := operationResultCode;
  FgatewayName := gatewayName;
  FgatewayResultCode := gatewayResultCode;
  Fcurrency := currency;
  FoperationType := operationType;
  FauthCode := authCode;
end;

////////////////////////////////////////////////////////////////////////////////////////
///
///

function LoadAllTokens(ReservationId, RoomReservationId : Integer) : TObjectList<TToken>;
var
  rSet: TRoomerDataSet;
  xml : String;
  token : TToken;
begin
  result := TObjectList<TToken>.Create;
  xml := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + format('paycard/bookings/%d/tokens', [ReservationId]));
  rSet := d.roomerMainDataSet.ActivateNewDataset(xml);
  try
    result.Clear;
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

        result.Add(token);
      end;
      rSet.Next;
    end;
  finally
    freeandNil(rSet);
  end;
end;

procedure FillTokenComboBox(cb : TsComboBox; tokens :TObjectList<TToken>; selectedToken : Integer);
var i, idx: Integer;
    token : TToken;
begin
  cb.Clear;
  idx := -1;
  cb.Items.AddObject('', nil);
  for i := 0 to tokens.Count - 1 do
  begin
    token := tokens[i];
    cb.Items.AddObject(token.CardNumber, token);
    if token.id = selectedToken then
      idx := i + 1;
  end;
  cb.ItemIndex := idx;
{ TOperationTypeHelper }

class function TPCITokenOperationTypeHelper.FromString(const value: String): TPCITokenOperationType;
begin
  result := TPCITokenOperationType(GetEnumValue(TypeInfo(TPCITokenOperationType),value));
end;

function TPCITokenOperationTypeHelper.ToString: string;
begin
  result := GetEnumName(TypeInfo(TPCITokenOperationType), Ord(Self));
end;

end.
