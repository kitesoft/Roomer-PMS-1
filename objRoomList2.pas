unit objRoomList2;

interface


uses
  Windows,
  Forms,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Contnrs,
  Dialogs,
  NativeXML,
  ADODB,
  hData
  , System.Generics.Collections
  , uUtils
  , cmpRoomerDataSet
  , cmpRoomerConnection, RoomerExceptionHandling
  ;

TYPE
  ERoomListException = class(ERoomerException);

  TRoomItem = class

    FRoom                : string    ;
    FRoomDescription     : string    ;
    FRoomType            : string    ;
    FRoomEquipments      : string    ;
    FBookable            : boolean   ;
    FUseInResStatistics  : boolean   ;
    FStatus              : string    ;
    FOrderIndex          : integer   ;
    Fhidden              : boolean   ;
    FLocation            : string    ;
    FFloor               : integer   ;
    FuseInNationalReport : boolean   ;

    FCleaningNotes       : string    ;
    FMaintenanceNotes    : string    ;
    FLostAndFound        : string    ;
    FReportUser          : string    ;
    FReportUserName      : string    ;
    FStatusDescripton    : String    ;


    function getRoom                : string    ;
    function getRoomDescription     : string    ;
    function getRoomType            : string    ;
    function getRoomEquipments      : string    ;
    function getBookable            : boolean   ;
    function getUseInResStatistics  : boolean   ;
    function getStatus              : string    ;
    function getOrderIndex          : integer   ;
    function gethidden              : boolean   ;
    function getLocation            : string    ;
    function getFloor               : integer   ;
    function getuseInNationalReport : boolean   ;

    procedure SetRoom(Value : string);
    procedure SetRoomDescription(Value : string);
    procedure SetRoomType(Value : string);
    procedure SetRoomEquipments(Value : string);
    procedure SetBookable(Value : boolean);
    procedure SetUseInResStatistics(Value : boolean);
    procedure SetStatus(Value : string);
    procedure SetOrderIndex(Value : integer);
    procedure Sethidden(Value : boolean);
    procedure SetLocation(Value : string);
    procedure SetFloor(Value : integer);
    procedure SetuseInNationalReport(Value : boolean);


  private
    function getCleaningNotes: string;
    function getLostAndFound: string;
    function getMaintenanceNotes: string;
    function getReportUser: string;
    function getReportUserName: string;
    procedure setCleaningNotes(const Value: string);
    procedure setLostAndFound(const Value: string);
    procedure setMaintenanceNotes(const Value: string);
    procedure setReportUser(const Value: string);
    procedure setReportUserName(const Value: string);
    function getStatusDescripton: string;
    procedure setStatusDescripton(const Value: string);
    // **
  public
    constructor Create;
    function IsNotClean: boolean;

    property Room               : string    read  getRoom                  write setRoom               ;
    property RoomDescription    : string    read  getRoomDescription       write setRoomDescription    ;
    property RoomType           : string    read  getRoomType              write setRoomType           ;
    property RoomEquipments     : string    read  getRoomEquipments        write setRoomEquipments     ;
    property Bookable           : boolean   read  getBookable              write setBookable           ;
    property UseInResStatistics : boolean   read  getUseInResStatistics    write setUseInResStatistics ;
    property Status             : string    read  getStatus                write setStatus             ;
    property OrderIndex         : integer   read  getOrderIndex            write setOrderIndex         ;
    property hidden             : boolean   read  gethidden                write sethidden             ;
    property Location           : string    read  getLocation              write setLocation           ;
    property Floor              : integer   read  getFloor                 write setFloor              ;
    property useInNationalReport: boolean   read  getuseInNationalReport   write setUseInNationalReport;

    property CleaningNotes       : string   read getCleaningNotes          write setCleaningNotes;
    property MaintenanceNotes    : string   read getMaintenanceNotes       write setMaintenanceNotes;
    property LostAndFound        : string   read getLostAndFound           write setLostAndFound ;
    property ReportUser          : string   read getReportUser             write setReportUser ;
    property ReportUserName      : string   read getReportUserName         write setReportUserName ;
    property StatusDescripton    : string   read getStatusDescripton       write setStatusDescripton ;

  end;

  TRooms = class (TObjectDictionary<String, TRoomItem>)
  private
    FHotelcode: string;
    procedure FillList;
  public
    constructor Create(const aHotelCode : string); overload;
    destructor Destroy; override;
    function FindRoomStatus(const RoomNumber: string): string;
  end;

implementation

uses //uDSp
  ug
  , _glob
  , uD
  , uAppGlobal
  , uSqlDefinitions
  , UITypes
  ;


constructor  TRoomItem.Create;
begin
  FCleaningNotes       := '';
  FMaintenanceNotes    := '';
  FLostAndFound        := '';
  FReportUser          := '';
  FReportUserName      := '';
  FStatusDescripton    := '';
end;


function TRoomItem.getBookable: boolean;
begin
  result := FBookable
end;

function TRoomItem.getCleaningNotes: string;
begin
  result := FCleaningNotes;
end;

function TRoomItem.getFloor: integer;
begin
  result := FFloor
end;

function TRoomItem.getHidden: boolean;
begin
  result := FHidden
end;

function TRoomItem.getLocation: string;
begin
  result := FLocation
end;

function TRoomItem.getLostAndFound: string;
begin
  result := FLostAndFound;
end;

function TRoomItem.getMaintenanceNotes: string;
begin
  result := FMaintenanceNotes;
end;

function TRoomItem.getOrderIndex: integer;
begin
  result := FOrderIndex
end;

function TRoomItem.getReportUser: string;
begin
  result := FReportUser;
end;

function TRoomItem.getReportUserName: string;
begin
  result := FReportUserName;
end;

function TRoomItem.getRoom: string;
begin
  result := FRoom
end;

function TRoomItem.getRoomDescription: string;
begin
  result := FRoomDescription
end;

function TRoomItem.getRoomEquipments: string;
begin
  result := FRoomEquipments
end;

function TRoomItem.getRoomType: string;
begin
  result := FRoomType
end;

function TRoomItem.getStatus: string;
begin
  result := FStatus
end;

function TRoomItem.getStatusDescripton: string;
begin
  result := FStatusDescripton;
end;

function TRoomItem.getUseInNationalReport: boolean;
begin
  result := FUseInNationalReport
end;

function TRoomItem.getUseInResStatistics: boolean;
begin
  result := FUseInResStatistics
end;



function TRoomItem.IsNotClean: boolean;
begin
  Result := not CharInSet(Status[1], ['C', 'R']);
end;


procedure TRoomItem.SetBookable(Value: boolean);
begin
  FBookable := value;
end;

procedure TRoomItem.setCleaningNotes(const Value: string);
begin
  FCleaningNotes := Value;
end;

procedure TRoomItem.SetFloor(Value: integer);
begin
  FFloor := value
end;

procedure TRoomItem.SetHidden(Value: boolean);
begin
  FHidden := value
end;

procedure TRoomItem.SetLocation(Value: string);
begin
  FLocation := value
end;

procedure TRoomItem.setLostAndFound(const Value: string);
begin
  FLostAndFound := Value;
end;

procedure TRoomItem.setMaintenanceNotes(const Value: string);
begin
  FMaintenanceNotes := Value;
end;

procedure TRoomItem.SetOrderIndex(Value: integer);
begin
  FOrderIndex := value
end;

procedure TRoomItem.setReportUser(const Value: string);
begin
  FReportUser := Value;
end;

procedure TRoomItem.setReportUserName(const Value: string);
begin
  FReportUserName := Value;
end;

procedure TRoomItem.SetRoom(Value: string);
begin
  FRoom := value
end;

procedure TRoomItem.SetRoomDescription(Value: string);
begin
  FRoomDescription := value
end;

procedure TRoomItem.SetRoomEquipments(Value: string);
begin
  FRoomEquipments := value
end;

procedure TRoomItem.SetRoomType(Value: string);
begin
  FRoomType := value
end;

procedure TRoomItem.SetStatus(Value: string);
begin
  FStatus := value
end;

procedure TRoomItem.setStatusDescripton(const Value: string);
begin
  FStatusDescripton := Value;
end;

procedure TRoomItem.SetUseInNationalReport(Value: boolean);
begin
  FUseInNationalReport := value
end;

procedure TRoomItem.SetUseInResStatistics(Value: boolean);
begin
  FUseInResStatistics := value
end;

constructor TRooms.Create(const aHotelCode : string);
begin
  inherited Create([doOwnsValues]);
  FHotelCode := aHotelCode;
  try
    FillList;
  except
    Clear;
    raise;
  end;
end;

destructor TRooms.Destroy;
begin
  Clear;
  inherited;
end;

procedure TRooms.FillList();
var
  RoomItem : TRoomItem;

  rSet : TRoomerDataSet;

  Room                : string  ;
  RoomDescription     : string  ;
  RoomType            : string  ;
  RoomEquipments      : string  ;
  Bookable            : boolean ;
  useInResStatistics  : boolean ;
  Status              : string  ;
  OrderIndex          : integer ;
  hidden              : boolean ;
  Location            : string  ;
  Floor               : integer ;
  useInNationalReport : boolean ;

  maintNotes : TRoomerDataSet;
  maintCodes : TRoomerDataSet;
  maintStaff : TRoomerDataSet;

begin
  Clear;
  if NOT d.roomerMainDataSet.LoggedIn then exit;

  glb.RefreshTablesWhenNeeded;

  maintNotes := glb.Maintenanceroomnotes;
  maintCodes := glb.MaintenanceCodes;
  maintStaff := glb.Staffmembers;

  rSet := glb.RoomsSet;

  Rset.First;
  While not rSet.Eof do
  begin
    hidden               := Rset['hidden'];
    if not hidden then
    begin
      RoomItem := TRoomItem.Create;
      try
        Room                 := Rset.fieldbyname('Room').asString;
        RoomDescription      := Rset.fieldbyname('Description').asString;
        RoomType             := Rset.fieldbyname('RoomType').asString;
        RoomEquipments       := Rset.fieldbyname('Equipments').asString;
        Location             := Rset.fieldbyname('Location').asString;
        Floor                := Rset.fieldbyname('Floor').asInteger;
        Bookable             := Rset['Bookable'];
        useinResStatistics   := Rset['Statistics'];
        useInNationalReport  := Rset['useInNationalReport'];
        Status               := Rset.fieldbyname('Status').asString;
        OrderIndex           := Rset.fieldbyname('OrderIndex').asInteger;

        RoomItem.SetRoom(Room);
        RoomItem.SetRoomDescription(RoomDescription);
        RoomItem.SetRoomType(RoomType);
        RoomItem.SetRoomEquipments(RoomEquipments);
        RoomItem.SetBookable(Bookable);
        RoomItem.SetUseInResStatistics(UseInResStatistics);
        RoomItem.SetStatus(Status);
        RoomItem.SetOrderIndex(OrderIndex);
        RoomItem.Sethidden(hidden);
        RoomItem.SetLocation(Location);
        RoomItem.SetFloor(Floor);
        RoomItem.SetUseInNationalReport(UseInNationalReport);

        if glb.LocateSpecificRecord('maintenanceroomnotes', 'Room', Room) then
        begin
          RoomItem.CleaningNotes := maintNotes['CleaningNotes'];
          RoomItem.MaintenanceNotes := maintNotes['MaintenanceNotes'];
          RoomItem.LostAndFound := maintNotes['LostAndFound'];

          if glb.LocateSpecificRecord('staffmembers', 'id', maintNotes.FieldByName('StaffIdReported').AsInteger) then
          begin
            RoomItem.ReportUser := maintStaff['Initials'];
            RoomItem.ReportUserName := maintStaff['Name'];
          end;

          if glb.LocateSpecificRecord('maintenancecodes', 'Code', Status) then
            RoomItem.StatusDescripton := maintCodes['name'];
        end;

        Add(Lowercase(Room), RoomItem);
      except
          on E: Exception do
            ERoomListException.Create('Exception during update of roomslist: ' + e.message);
      end;
    end;
    rSet.Next;
  end;
end;

function TRooms.FindRoomStatus(const RoomNumber: string): string;
var
  RoomItem : TRoomItem;
begin
  if Application.Terminated then exit;
  result := '';

  if TryGetValue(RoomNumber, RoomItem) then
    result := RoomItem.FStatus;
end;

end.
