unit uDynamicRates;

interface

uses
  cmpRoomerDataSet,
  SysUtils,
  classes
  , uCurrencyHandlersMap
  ;

type
  TDynamicRates = class
  private
    chRates : TRoomerDataSet;
    arrival, departure : TDate;
    channelCode, chManCode : String;
    FCurrHandlers: TCurrencyHandlersMap;
    procedure Clear;
    procedure Deactivate;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Prepare(_arrival, _departure : TDate; _channelCode, _chManCode : String);
    function findRateByRateCode(ADate : TDate; numGuests : Integer; const rateId : String; var roomPrice : Double; var aCurrCode: string) : Boolean;
    function findRateForRoomType(ADate: TDate; RoomType: String; numGuests: Integer; var roomPrice: Double; var rateId: String; var aCurrCode: string): Boolean;
    procedure GetAllRateCodes(List: TStrings);
    function Active : Boolean;
    /// <summary>
    ///   Returns the average rate in native currency for a stay from arrival to departure in roomtype using RateplanCode
    /// </summary>
    function AverageRateStay(const aRatePlanCode : String; const roomType : String; arrival, departure : TDate) : Double;
    /// <summary>
    ///   Update Roomsdate and Roomreservations records for roomreservation with the actual nightrate resp average rate (in currency aCurrCode)
    /// </summary>
    procedure UpdateRoomReservation(RoomReservation: Integer; const aRatePlanCode: String; const roomType: String; arrival, departure: TDate; const aCurrCode: string);
  end;

implementation

uses
  uDateUtils,
  ud,
  System.Generics.Collections,
  _Glob, uSQLUtils
  , uG
  ;

function TDynamicRates.Active: Boolean;
begin
  result := assigned(chRates);
end;

function TDynamicRates.AverageRateStay(const aRatePlanCode : String; const roomType : String; arrival, departure: TDate): Double;
var numDays : Integer;
    Counter : Integer;
    lnativeRate: double;
begin
  result := 0.00;
  if NOT assigned(chRates) then exit;

  numDays := TRUNC(departure) - TRUNC(arrival);
  if numDays < 1 then exit;

  chRates.First;
  Counter := 0;
  while NOT chRates.Eof do
  begin
    if (chRates['rateCode'] = aRatePlanCode) AND
       (chRates['date'] >= arrival) AND
       (chRates['date'] < departure) then
    begin
      lnativeRate := FCurrHandlers.ConvertAmount(chRates['rate'], chRates['chCurrencyCode'], g.qNativeCurrency);
      result := result + lnativeRate;
      Inc(Counter);
    end;
    chRates.Next;
    if Counter >= numDays then
      Break;
  end;
  result := result / numDays;
end;

procedure TDynamicRates.UpdateRoomReservation(RoomReservation: Integer; const aRatePlanCode: String; const roomType: String; arrival, departure: TDate; const aCurrCode: string);
var SqlList : TList<String>;
    numDays : Integer;
    Total : Double;
    s : String;
    Counter : Integer;
    lRate: double;
begin
  numDays := TRUNC(departure) - TRUNC(arrival);
  Total := 0.00;
  if numDays < 1 then exit;

  if NOT assigned(chRates) then exit;

  SqlList := TList<String>.Create;
  try
    chRates.First;
    Counter := 0;
    while NOT chRates.Eof do
    begin
      if (chRates['rateCode'] = aRatePlanCode) AND
         (chRates['date'] >= arrival) AND
         (chRates['date'] < departure) then
      begin
        lRate := FCurrHandlers.ConvertAmount(chRates['rate'], chRates['chCurrencyCode'], aCurrCode);
        Total := Total + lRate;
        s := format('UPDATE roomsdate SET RoomRate=%s WHERE ADate=%s AND RoomReservation=%d',
                    [
                      _db(lRate),
                      _db(DateToSqlString(chRates['date'])),
                      RoomReservation
                    ]);
        SqlList.Add(s);
        inc(Counter);
      end;
      chRates.Next;
      if Counter >= numDays then
        Break;
    end;
    if SqlList.Count > 0 then
      d.roomerMainDataSet.SystemFreeExecuteMultiple(SqlList);
  finally
    SqlList.Free;
  end;
end;

procedure TDynamicRates.Clear;
begin
  if assigned(chRates) then
    FreeAndNil(chRates);
end;

constructor TDynamicRates.Create;
begin
  chRates := nil;
  arrival := Now;
  departure := arrival + 1;
  channelCode := '';
  chManCode := '';
  FCurrHandlers := TCurrencyHandlersMap.create;
end;

procedure TDynamicRates.Deactivate;
begin
  Clear;
end;

destructor TDynamicRates.Destroy;
begin
  Clear;
  FCurrHandlers.Free;
  inherited;
end;

function TDynamicRates.findRateByRateCode(ADate : TDate; numGuests : Integer; const rateId : String; var roomPrice : Double; var aCurrCode: string) : Boolean;
var iCount : Integer;
    finalized : Boolean;
begin
  result := False;
  if NOT assigned(chRates) then exit;

  iCount := 0;
  finalized := False;
  repeat
    chRates.First;
    while NOT chRates.Eof do
    begin
      if (chRates['rateCode']=rateId) AND (trunc(chRates['date'])=ADate) then
      begin
        if (chRates['numGuests']=numGuests) OR (iCount > 0) then
        begin
          roomPrice := chRates['rate'];
          aCurrCode := chRates['chCurrencyCode'];
          result := True;
          finalized := True;
          Break;
        end;
      end;
      chRates.Next;
    end;
    inc(iCount);
    if iCount > 1 then
      finalized := True;
  until finalized;
end;

function TDynamicRates.findRateForRoomType(ADate: TDate; RoomType: String; numGuests: Integer; var roomPrice: Double; var rateId: String; var aCurrCode: string): Boolean;
var iCount : Integer;
    finalized : Boolean;
begin
  result := False;
  if NOT assigned(chRates) then exit;

  iCount := 0;
  finalized := False;
  repeat
    chRates.First;
    while NOT chRates.Eof do
    begin
      if (chRates['RoomType']=RoomType) AND (trunc(chRates['date'])=ADate) then
      begin
        if (chRates['numGuests']=numGuests) OR (iCount > 0) then
        begin
          roomPrice := chRates['rate'];
          aCurrCode := chRates['chCurrencyCode'];
          rateId := chRates['rateCode'];
          result := True;
          finalized := True;
          Break;
        end;
      end;
      chRates.Next;
    end;
    inc(iCount);
    if iCount > 1 then
      finalized := True;
  until finalized;
end;

procedure TDynamicRates.GetAllRateCodes(List : TStrings);
var s : String;
begin
  chRates.First;
  try
    while NOT chRates.Eof do
    begin
      s := chRates['rateCode'];
      if List.IndexOf(s) < 0 then
      begin
        List.AddObject(s, TObject(chRates.FieldByName('channelId').AsInteger));
      end;
      chRates.Next;
    end;
  finally

  end;
end;

procedure TDynamicRates.Prepare(_arrival, _departure: TDate; _channelCode, _chManCode: String);
var
  sql : String;
begin
  Clear;
  arrival := _arrival;
  departure := _departure;
  channelCode := _channelCode;
  chManCode := _chManCode;
  sql := format('bookingapi/pmsAvailability?arrival=%s&departure=%s&channelCode=%s&channelManagerCode=%s', [uDateUtils.dateToSqlString(arrival), uDateUtils.dateToSqlString(departure), channelCode, chManCode]);

  chRates := d.roomerMainDataSet.ActivateNewDataset(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + sql));
end;

end.
