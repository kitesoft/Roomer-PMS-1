unit uRoomServicesStatus;

interface

uses
  Spring.Collections.Lists
  , Spring.Collections
  , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
  ;


type
  TRoomServicesStatus = class(TxsdBaseObject)
  private
    FMaintenanceRemarks: string;
    FActivityStatus: string;
    FLostAndFound: string;
    FCleaningRemarks: string;
    FRoomNumber: string;
  protected
    class function GetNodeName: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure Clear; override;
  published
    property RoomNumber: string read FRoomNumber write FRoomNumber;
    property ActivityStatus: string read FActivityStatus write FActivityStatus;
    property CleaningRemarks: string read FCleaningRemarks write FCleaningRemarks;
    property MaintenanceRemarks: string read FMaintenanceRemarks write FMaintenanceRemarks;
    property LostAndFound: string read FLostAndFound write FLostAndFound;
  end;


implementation

uses
  SysUtils
  ;

{ TRoomServicesStatus }

procedure TRoomServicesStatus.Clear;
begin
  inherited;
  FMaintenanceRemarks := '';
  FActivityStatus := '';
  FLostAndFound := '';
  FCleaningRemarks := '';
  FRoomNumber := '';
end;

class function TRoomServicesStatus.GetNodeName: string;
begin
  result := 'room';
end;

procedure TRoomServicesStatus.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNode: PXMLNode;
begin
  inherited;
  if aNode.FindAttribute('roomNumber', lNode) then FRoomNumber := lNode.NodeValue;
  if aNode.FindAttribute('activityStatus', lNode) then FActivityStatus := lNode.NodeValue;
  if aNode.FindChild('cleaningRemarks', lNode) then FCleaningRemarks := lNode.Text;
  if aNode.FindChild('maintenanceRemarks', lNode) then FMaintenanceRemarks := lNode.text;
  if aNode.FindChild('lostAndFound', lNode) then FLostAndFound := lNode.Text;
end;

end.
