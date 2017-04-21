unit objDayFreeRooms;

interface


uses
    System.Generics.Collections
  , hData
  , cmpRoomerDataSet
  ;

{$M+}
TYPE

  TFreeRoomItem = class
  private
    FRoom                : string    ;
    FStatus              : string    ;
    FNextOcc             : string    ;
  public
    property Room               : string    read  FRoom                  write FRoom               ;
    property Status             : string    read  FStatus                write FStatus             ;
    property NextOcc            : string    read  FNextOcc               write FNextOcc            ;
  end;


  TFreeRoomItemsList = TObjectDictionary<String,TFreeRoomItem>;

  TFreeRooms = class
  private
    FRoomList : TFreeRoomItemsList;
    function getRoomCount : integer;
    procedure FillList(sDate : TDateTime; const occRooms : string); overload;
    procedure FillList(rSet : TRoomerDataSet); overload;
    procedure ClearRoomList;
    function FindFreeRoomFromRoomNumber(const RoomNumber: string): TFreeRoomItem;
  public
    constructor Create(sDate : TDateTime; const occRooms : string);
    destructor Destroy; override;

    function FindRoomNextOcc(const RoomNumber: string): string;

    property RoomItemsList : TFreeRoomItemsList read FRoomList write FRoomList;
    property RoomCount : integer read getRoomCount;
  end;

implementation

uses
    uD
  , uMain
  , SysUtils
  ;

constructor TFreeRooms.Create(sDate : TDateTime; const occRooms : string);
begin
  inherited Create;

  FRoomList := TFreeRoomItemsList.Create([doOwnsValues]);
  FillList(sDate,occRooms);

end;

destructor TFreeRooms.Destroy;
begin
  ClearRoomList;
  freeandnil(FRoomList);
  inherited;
end;

procedure TFreeRooms.ClearRoomList;
begin
  FRoomList.Clear;
end;

procedure TFreeRooms.FillList(sDate : TDateTime; const occRooms : string);
var
  rSet : TRoomerDataSet;
begin
  ClearRoomList;
  if frmMain.OfflineMode then
    exit;
  rSet := d.roomerMainDataSet.ActivateNewDataset(d.roomerMainDataSet.SystemNextBookingDates(sDate, occRooms));
  try
    FillList(rSet);
  finally
    freeandNil(rSet);
  end;
end;

procedure TFreeRooms.FillList(rSet : TRoomerDataSet);
var
  RoomItem : TFreeRoomItem;
begin
  ClearRoomList;
  if frmMain.OfflineMode then
    exit;

  Rset.First;
  while not rSet.Eof do
  begin
    RoomItem := TFreeRoomItem.Create;
    RoomItem.Room := LowerCase(Rset.fieldbyname('Room').asString);
    RoomItem.Status := Rset.fieldbyname('Status').asString;
    RoomItem.NextOcc := Rset.fieldbyname('NextOcc').asString;
    FRoomList.AddOrSetValue(RoomItem.Room, RoomItem);
    rSet.Next;
  end;
end;


function TFreeRooms.FindFreeRoomFromRoomNumber(const RoomNumber: string): TFreeRoomItem;
var
  FreeRoomItem : TFreeRoomItem;
begin
  result := nil;
  if FRoomList.TryGetValue(LowerCase(RoomNumber), FreeRoomItem) then
    result := FreeRoomITem;
end;


function TFreeRooms.FindRoomNextOcc(const RoomNumber: string): string;
var
  FreeRoomItem : TFreeRoomItem;
begin
  result := '';

  FreeRoomItem := FindFreeRoomFromRoomNumber(Lowercase(RoomNumber));
  if Assigned(FreeRoomItem) then
    result := FreeRoomItem.NextOcc;

end;

function TFreeRooms.getRoomCount: integer;
begin
  result := FRoomList.Count;
end;

end.
