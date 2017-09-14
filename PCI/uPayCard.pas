unit uPayCard;

interface

uses cmpRoomerDataSet;

type TPCIToken = class
  private
    FENABLED: Boolean;
    FROOM_RESERVATION: Integer;
    FNOTES: String;
    FRESERVATION: Integer;
    FID: Integer;
    FCREATE_TSTAMP: TDateTime;
    FPAYCARD_TOKEN: String;
    FDESCRIPTION: String;
    FHOTEL_ID: String;
    FUSER_ID: String;
    FROOM: String;
    FSOURCE: String;
  public
    constructor Create(data : TRoomerDataSet);
    property ID : Integer read FID write FID;
    property HOTEL_ID : String read FHOTEL_ID write FHOTEL_ID;
    property RESERVATION : Integer read FRESERVATION write FRESERVATION;
    property ROOM_RESERVATION : Integer read FROOM_RESERVATION write FROOM_RESERVATION;
    property PAYCARD_TOKEN : String read FPAYCARD_TOKEN write FPAYCARD_TOKEN;
    property ENABLED : Boolean read FENABLED write FENABLED;
    property DESCRIPTION : String read FDESCRIPTION write FDESCRIPTION;
    property NOTES : String read FNOTES write FNOTES;
    property USER_ID : String read FUSER_ID write FUSER_ID;
    property CREATE_TSTAMP : TDateTime read FCREATE_TSTAMP write FCREATE_TSTAMP;
    property SOURCE : String read FSOURCE write FSOURCE;
    property ROOM : String read FROOM write FROOM;
end;



implementation

{ TPCIToken }

constructor TPCIToken.Create(data: TRoomerDataSet);
begin
  if data.FieldByName('ENABLED') <> nil then
    FENABLED := data.FieldByName('ENABLED').AsBoolean;
  if data.FieldByName('ROOM_RESERVATION') <> nil then
    FROOM_RESERVATION := data.FieldByName('ROOM_RESERVATION').AsInteger;
  if data.FieldByName('NOTES') <> nil then
    FNOTES := data.FieldByName('NOTES').AsString;
  if data.FieldByName('RESERVATION') <> nil then
    FRESERVATION := data.FieldByName('RESERVATION').AsInteger;
  if data.FieldByName('ID') <> nil then
    FID := data.FieldByName('ID').AsInteger;
  if data.FieldByName('CREATE_TSTAMP') <> nil then
    FCREATE_TSTAMP := data.FieldByName('CREATE_TSTAMP').AsDateTime;
  if data.FieldByName('PAYCARD_TOKEN') <> nil then
    FPAYCARD_TOKEN := data.FieldByName('PAYCARD_TOKEN').AsString;
  if data.FieldByName('DESCRIPTION') <> nil then
    FDESCRIPTION := data.FieldByName('DESCRIPTION').AsString;
  if data.FieldByName('HOTEL_ID') <> nil then
    FHOTEL_ID := data.FieldByName('HOTEL_ID').AsString;
  if data.FieldByName('USER_ID') <> nil then
    FUSER_ID := data.FieldByName('USER_ID').AsString;
  if data.FieldByName('SOURCE') <> nil then
    FHOTEL_ID := data.FieldByName('SOURCE').AsString;
  if data.FieldByName('ROOM') <> nil then
    FHOTEL_ID := data.FieldByName('ROOM').AsString;
end;

end.
