unit uMessageList;

interface

uses uD,
     Generics.Collections,
     Generics.Defaults,
     cmpRoomerDataset,
     System.SysUtils,
     uDateUtils
     ;

Type

    TRoomerMessage = class
    private
      FRoomerMessageType : String;
      FMessageType : integer;
      FTheMessage : String;
      FId : integer;
      FConfirmation : Boolean;
      FShowUntil : TDateTime;

      FMarkedAsRead: Boolean;
      FHidden: Boolean;
    procedure MarkeAsRead(const Value: Boolean);
    procedure SetHidden(const Value: Boolean);

    public
      constructor Create(RoomerMessageType : String; MessageType : integer;
                         TheMessage : String;
                         id : integer;
                         Confirmation : Boolean;
                         ShowUntil : TDateTime);
      destructor Destroy; override;

      property RoomerMessageType : String read FRoomerMessageType;
      property MessageType : integer read FMessageType;
      property TheMessage : String read FTheMessage;
      property Id : integer read FId;
      property Confirmation : Boolean read FConfirmation;
      property ShowUntil : TDateTime read FShowUntil;

      property MarkedAsRead : Boolean read FMarkedAsRead write MarkeAsRead;
      property Hidden : Boolean read FHidden write SetHidden;
    end;

    TRoomerMessageList = TObjectList<TRoomermessage>;

    TMessageList = class
    private
      MessageList : TRoomerMessageList;

      function getActiveCount: integer;
      function getCount: integer;
      function GetMessage(index: integer): TRoomerMessage;
      function GetActiveMessage(index: integer): TRoomerMessage;
      procedure GetMessages(aRSet: TROomerDataset);
    public
      constructor Create;
      destructor Destroy; override;

      function MessageById(id : integer) : TRoomerMessage;
      procedure Delete(idx : Integer);
      procedure Clear;
      procedure Refresh;
      property Count : integer read getCount;
      property ActiveCount : integer read getActiveCount;
      property RoomerMessage[index : integer] : TRoomerMessage read GetMessage;
      property ActiveRoomerMessage[index : integer] : TRoomerMessage read GetActiveMessage;
    end;

var RoomerMessages : TMessageList;

implementation

{ TRoomerMessage }

uses uMain
    , uAppGlobal
    , DateUtils
    , PrjConst, uUtils;

constructor TRoomerMessage.Create(RoomerMessageType : String;
                                  MessageType: integer;
                                  TheMessage: String;
                                  id: integer;
                                  Confirmation: Boolean;
                                  ShowUntil: TDateTime);
begin
  inherited Create;
  FRoomerMessageType := RoomerMessageType;
  FMessageType := MessageType;
  FTheMessage := TheMessage;
  FId := id;
  FConfirmation := Confirmation;
  FShowUntil := ShowUntil;

  FMarkedAsRead := False;
  FHidden := False;
end;

destructor TRoomerMessage.Destroy;
begin
  inherited;
end;

procedure TRoomerMessage.MarkeAsRead(const Value: Boolean);
begin
  FMarkedAsRead := Value;
  d.roomerMainDataSet.markMessageAsRead(id);
end;

procedure TRoomerMessage.SetHidden(const Value: Boolean);
begin
  FHidden := Value;
end;

{ TMessageList }

procedure TMessageList.Clear;
begin
  MessageList.Clear;
end;

constructor TMessageList.Create;
begin
  inherited;
  MessageList := TRoomerMessageList.Create(True);
end;

procedure TMessageList.Delete(idx: Integer);
begin
  MessageList.Delete(idx);
end;

destructor TMessageList.Destroy;
begin
  MessageList.Free;
  inherited;
end;

function TMessageList.getActiveCount: integer;
var i: Integer;
begin
  result := 0;
  for i := 0 to Count - 1 do
    if NOT (MessageList[i].Hidden OR MessageList[i].FMarkedAsRead) then
      if MessageList[i].ShowUntil > now then
        inc(result);
end;

function TMessageList.GetActiveMessage(index: integer): TRoomerMessage;
var i, iCount: Integer;
begin
  result := nil;
  iCount := -1;
  for i := 0 to Count - 1 do
    if NOT (MessageList[i].Hidden OR MessageList[i].FMarkedAsRead) then
      if MessageList[i].ShowUntil > now then
      begin
        inc(iCount);
        if iCount=index then
        begin
          result := MessageList[i];
          Break;
        end;
      end;
end;

function TMessageList.getCount: integer;
begin
  result := MessageList.Count;
end;

function TMessageList.GetMessage(index: integer): TRoomerMessage;
begin
  result := MessageList[index];
end;

function TMessageList.MessageById(id: integer): TRoomerMessage;
var i: Integer;
begin
  result := nil;
  for i := 0 to Count - 1 do
    if MessageList[i].Id=id then
    begin
      result := MessageList[i];
      Break;
    end;
end;


procedure TMessageList.GetMessages(aRSet: TROomerDataset);
begin
  try
    if NOT aRSet.OfflineMode then
      aRSet.OpenDatasetFromUrlAsString('messaging/broadcastlist', false, 0, '');
  except
    // Ignore ...
  end;
end;

procedure TMessageList.Refresh;
var rSet : TRoomerDataset;

    RoomerMessage : TRoomerMessage;
    msgType : String;
begin
  if frmMain.OfflineMode then
    exit;
  rSet := createNewDataSet;
  try
    MessageList.Clear;
    rSet.RoomerDataSet := nil;
    GetMessages(rSet);
    rset.First;
    while not rset.Eof do
    begin
      if MessageById(rSet['id']) = nil then
      begin
        msgType := 'SYSTEM_MESSAGE';
        try msgType := rSet['RoomerMessageType']; except end;

        RoomerMessage := TRoomerMessage.Create(
                              msgType,
                              rSet['messageType'],
                              rSet.FieldByName('message').Text,
                              rSet['id'],
                              rSet['confirmation'],
                              rSet['validUntil']
                              );

        MessageList.Add(RoomerMessage);
      end;
      rset.Next;
    end;

  finally
    freeandnil(rset);
  end;
end;

initialization
  RoomerMessages := TMessageList.Create;

finalization
  RoomerMessages.free;

end.
