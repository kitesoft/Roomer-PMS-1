unit uRoomReservationOBJ;
interface

uses
    Windows
  , Classes
  , kbmMemTable
  , cmpRoomerDataSet
  , Generics.Collections
  , uReservationStateDefinitions
  ;

//******************************************************************************
type

  /// <summary>
  ///   Basic representation of a Roomreservation, containing only basic information
  /// </summary>
  TRoomReservationBasicObj = class
  public
    Reservation: integer;
    Roomreservation: integer;
    Room: string;
    State: TReservationState;
  end;

  TRoomResBasicObjList = TObjectList<TRoomreservationBasicObj>;

  TRoomReservation = class
  private
    FIdx         : integer;
    FFilter       : string;
    FSortOn       : string;
    function getCount : integer;
  public
    qMT_ : TkbmMemTable;

    constructor Create(Filter, SortOn : string);
    destructor Destroy; override;

    function getListFromDB(var list :  TStringlist) : integer;
    function getListFromDBViaDates(fromDate, toDate : TDateTime; var rExtraSet : TRoomerDataSet; skipCancelledBookings : Boolean) : integer;
    function Refresh(filter, sortOn : string) : integer;
    function DateOrders(RoomReservation: integer;
                                     Adate: Tdate;
                                     var
                                     Channel,
                                     PaymentInvoice,
                                     AscIndex,
                                     DescIndex: integer;
                                     var
                                     GroupAccount : Boolean;
                                     var
                                     Customer
                                    ,CustomerName
                                    ,GuestName : string
                                     ): integer;


    property Filter : string
        read FFilter
       write FFilter;

    property SortOn : string
        read FSortOn
       write FSortOn;

    property Count : integer
         read getCount;    // read only
  end;

implementation

uses
    Data.DB
  , SysUtils
  , hData
  , uSqlDefinitions
  , uRoomerDefinitions
  , uSQLUtils
  , cmpRoomerConnection
  , uG
  , uD
  , uDateUtils
  , uUtils

;

//******************************************************************************
//*
//*
//*
//------------------------------------------------------------------------------

constructor TRoomReservation.Create(filter, sortOn : string);
begin
  inherited Create;
  FIdx    := 0;
  qMT_    := TkbmMemTable.Create(nil);
  FFilter := filter;
  FSortOn := sortOn;

  if qMt_.Active then qMt_.Close;
  qMt_.FieldDefs.Clear;

  qMt_.FieldDefs.Add('RoomReservation' , ftInteger);
  qMt_.FieldDefs.Add('Room'            , ftString,20);
  qMt_.FieldDefs.Add('Reservation'     , ftInteger);
  qMt_.FieldDefs.Add('Channel'         , ftInteger);
  qMt_.FieldDefs.Add('resFlag'         , ftString,1);
  qMt_.FieldDefs.Add('Arrival'         , ftDate);
  qMt_.FieldDefs.Add('Departure'       , ftDate);
  qMt_.FieldDefs.Add('Customer'        , ftString,30);
  qMt_.FieldDefs.Add('CustomerName'    , ftString,60);
  qMt_.FieldDefs.Add('GuestName'       , ftString,60);
  qMt_.FieldDefs.Add('PaymentInvoice'  , ftInteger);
  qMt_.FieldDefs.Add('GroupAccount'    , ftBoolean);
  qMt_.FieldDefs.Add('NumGuests'       , ftInteger);


  qMt_.CreateTable;
  qMt_.Open;

  Refresh(FFilter,FSortOn); // read from database into FroomList
end;

destructor TRoomReservation.Destroy;
begin
  if qMt_.active then qMt_.close;
  FreeAndNil(qMT_);
  inherited Destroy;
end;

function TRoomReservation.getCount: integer;
begin
  result := qMT_.recordCount;
end;


function TRoomReservation.Refresh(filter, sorton : string) : integer;
begin
  result := -1;

  IF (Filter <> FFilter) or (Fidx = 0) then
  begin
    if filter > '' then
    begin
      try
        qMT_.Filter := Filter;
        qMT_.Filtered := true;
      except
      end;
    end else
    begin
      qMT_.Filtered := false;
    end;
  end;

  IF (sortON <> FSortOn) or (Fidx = 0) then
  begin
    if sortOn > '' then
    begin
      try
        qMT_.SortFields := sortON;
        qMT_.Sort([]);
      except
      end;
    end;
  end;

  FFilter := Filter;
  FSortOn := SortOn;
  inc(Fidx);
end;



function TRoomReservation.getListFromDB(var list :  TStringlist) : integer;
var
  RoomReservation   : integer ;
  s    : string;
  rSet : TRoomerDataSet;
  i    : integer;
  rrList : string;
begin
  RoomReservation := 0;
  result := 0;
  rSet := CreateNewDataSet;
  try
    rrList := '';
    for i := 0 to list.Count-1 do
    begin
      try
        RoomReservation := strToInt(list[i]);
      except
        continue;
      end;
      rrList := rrList+inttostr(RoomReservation)+','
    end;

    if length(rrList) = 0 then exit;
    delete(rrList,length(rrList),1);

      s := format(select_RoomReservationOBJ_RoomReservation_getListFromDB , [rrList]);
      // CopyToClipboard(s);
      // DebugMessage(''#10#10+s);
      hData.rSet_bySQL(rSet,s );

     if not rSet.Eof then
     begin
       while not rSet.Eof do
       begin
         inc(result);
         qMt_.append;
         qMt_.ClearFields;
         RoomReservation := rSet.FieldByName('RoomReservation').asInteger;
         qMt_.FieldByName( 'RoomReservation' ).asInteger  := RoomReservation  ;
         qMt_.FieldByName( 'Room'            ).asString   := rSet.FieldByName('Room').asString  ;
         qMt_.FieldByName( 'Reservation'     ).asInteger  := rSet.FieldByName('Reservation').asInteger  ;
         qMt_.FieldByName( 'Channel'         ).asInteger  := rSet.FieldByName('Channel').asInteger  ;
         qMt_.FieldByName( 'PaymentInvoice'  ).asInteger  := rSet.FieldByName('PaymentInvoice').asInteger  ;
         qMt_.FieldByName( 'GroupAccount'    ).asBoolean  := rSet.FieldByName('GroupAccount').asBoolean  ;
         qMt_.FieldByName( 'resFlag'         ).asString   := rSet.FieldByName('Status').asString  ;
         qMt_.FieldByName( 'Arrival'         ).asDateTime := rSet.FieldByName('Arrival').asDateTime;
         qMt_.FieldByName( 'Departure'       ).asDateTime := rSet.FieldByName('Departure').asDateTime;
         qMt_.FieldByName( 'Customer'        ).asString   := rSet.FieldByName('Customer').asString;
         qMt_.FieldByName( 'CustomerName'    ).asString   := rSet.FieldByName('CustomerName').asString;
         qMt_.FieldByName( 'GuestName'       ).asString   := rSet.FieldByName('GuestName').asString;
         qMt_.FieldByName( 'NumGuests'       ).asInteger  := rSet.FieldByName('NumGuests').asInteger;
         qMt_.Post;
         rSet.Next;
       end;
     end;
   finally
    freeandnil(rSet);
  end;

  refresh(FFilter,FSortOn);
end;

function TRoomReservation.getListFromDBViaDates(fromDate, toDate : TDateTime; var rExtraSet : TRoomerDataSet; skipCancelledBookings : Boolean) : integer;
var
  RoomReservation   : integer ;
  s    : string;
  rSet : TRoomerDataSet;
  sql : string;
  exePlan : TRoomerExecutionPlan;
begin
  result := 0;
  exePlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

      sql :=
      ' SELECT '#10 +
      '       roomreservations.RoomReservation '#10 +
      '     , roomreservations.Room  '#10 +
      '     , roomreservations.Reservation '#10 +
      '     , roomreservations.Status '#10 +
      '     , RR_Arrival(roomreservations.Roomreservation, not params.skipCancelledBookings) as Arrival '#10 +
      '     , RR_Departure(roomreservations.Roomreservation, not params.skipCancelledBookings) as Departure '#10 +
      '     , roomreservations.RoomRentPaymentInvoice AS PaymentInvoice '#10 +
      '     , roomreservations.GroupAccount '#10 +
      '     , reservations.Customer '#10 +
      '     , reservations.Channel '#10 +
      '     , reservations.Name As CustomerName '#10 +
      '     , persons.name As GuestName '#10 +
      '     , (SELECT COUNT(id) FROM persons p WHERE p.RoomReservation=roomreservations.RoomReservation) AS NumGuests '#10 +
      ' FROM '#10 +
      '   (select ' + _db(skipCancelledBookings) + ' as skipCancelledBookings) params, '#10 +
      '   roomreservations '#10 +
      '   RIGHT OUTER JOIN '#10 +
      '         reservations ON roomreservations.Reservation = reservations.Reservation '#10 +
      '   LEFT OUTER JOIN persons ON roomreservations.roomreservation = persons.roomreservation AND persons.MainName=1'#10 +
      ' WHERE (roomreservations.RoomReservation in ( SELECT DISTINCT '#10 +
      '    RoomReservation '#10 +
      '  FROM  roomsdate '#10 +
      '  WHERE (( ADate >= ''%s'' ) '#10 +
      '   AND (ADate < ''%s'' )) '#10 +
      '   AND (ResFlag <> ' +_db(STATUS_DELETED)+' ) '#10 +
      '   AND (not params.skipCancelledBookings OR (ResFlag <> ' +_db(STATUS_CANCELLED)+' )) '#10 +
      '  ORDER BY RoomReservation '#10 +
      ' ) ) '#10 +
      ' GROUP BY roomreservations.RoomReservation'; // rrList

      s := format(sql,[uDateUtils.dateToSqlString(fromDate), uDateUtils.dateToSqlString(toDate)]);

      {$ifdef DEBUG}
      CopyToClipboard(s);
      {$endif}
      exePlan.AddQuery(s);

      if Assigned(rExtraSet) then
      begin

        s := 'SELECT '#10;
        s := s + ' ADate, '#10;
        s := s + ' Room, '#10;
        s := s + ' RoomType, '#10;
        s := s + '     RoomReservation, '#10;
        s := s + '     Reservation, '#10;
        s := s + '     ResFlag, '#10;
        s := s + '     Information, '#10;
        s := s + '     OutOfOrderBlocking, '#10;
        s := s + '     BlockMove, '#10;
        s := s + '     BlockMoveReason, '#10;
        s := s + '     TotalPayment, '#10;
        s := s + '     TotalNoRent, '#10;
        s := s + '     TotalRent, '#10;
        s := s + '   IF(xxx.useStayTax AND (tax.INCL_EXCL = ''EXCLUDED'' OR (tax.INCL_EXCL = ''PER_CUSTOMER'' AND (SELECT StayTaxIncluted FROM customers WHERE Customer = xxx.Customer LIMIT 1) = 0)), '#10;
        s := s + '      IF(tax.TAX_BASE = ''GUEST_NIGHT'', '#10;
        s := s + '         IF(tax.TAX_TYPE=''PERCENTAGE'', tax.AMOUNT * IF(tax.NETTO_AMOUNT_BASED=''TRUE'', ';
        s := s + '              (AverageRoomRateNative - IncludedBreakfastPrice * NumGuests) / (1+vc.VATPercentage/100), (AverageRoomRateNative - IncludedBreakfastPrice * NumGuests)) / 100, tax.AMOUNT) * NumNights * NumGuests, '#10;
        s := s + '         IF(tax.TAX_TYPE=''PERCENTAGE'', tax.AMOUNT * IF(tax.NETTO_AMOUNT_BASED=''TRUE'', ';
        s := s + '              (TotalRent - IncludedBreakfastPrice * NumGuests * NumNights) / (1+vc.VATPercentage/100), (TotalRent - IncludedBreakfastPrice * NumGuests * NumNights)) / 100, tax.AMOUNT)), '#10;
        s := s + '      0) * IF(TotalRent > 0, 1, 0) AS totalTaxes, '#10;
        s := s + ' '#10;
        s := s + '     Guarantee, '#10;
        s := s + '     InvoiceIndex, '#10;
        s := s + '     Invoices, '#10;
        s := s + '     RoomClass, '#10;
        s := s + '     rvFax as Fax, '#10;
        s := s + '     BookingId, '#10;
        s := s + '     PMInfo, '#10;
        s := s + '     Tel2, '#10;
        s := s + '     Tel1, '#10;
        s := s + '     NumGuests, '#10;
        s := s + '     MainName, '#10;
        s := s + '     Discount, '#10;
        s := s + '     TO_BOOL(allIsPercentage) AS AllIsPercentage, '#10;
        s := s + '     PriceType, '#10;
        s := s + '     AverageRoomRate as Price, '#10;
        s := s + '     rdCurrency as Currency, '#10;
        s := s + '     ItemsOnInvoice '#10;
        s := s + ' FROM '#10;
        s := s + '     (SELECT  -- xxx '#10;
        s := s + '         ADate, '#10;
        s := s + '             rd.Room, '#10;
        s := s + '             rd.RoomType, '#10;
        s := s + '             rd.RoomReservation, '#10;
        s := s + '             rd.Reservation, '#10;
        s := s + '             ResFlag, '#10;
        s := s + '             rv.Information, '#10;
        s := s + '             rv.OutOfOrderBlocking, '#10;
        s := s + '             rv.useStayTax, '#10;
        s := s + '             rv.Customer, '#10;
        s := s + '             rr.BlockMove, '#10;
        s := s + '             rr.BlockMoveReason, '#10;
        s := s + '             cur.AValue AS CurrencyRate, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     SUM(pa.Amount) AS Total '#10;
        s := s + '                 FROM '#10;
        s := s + '                     payments pa '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     (pa.Amount <> 0) '#10;
        s := s + '                         AND (pa.InvoiceNumber = - 1) '#10;
        s := s + '                         AND (pa.RoomReservation = rd.roomReservation)) AS TotalPayment, '#10;
        s := s + '             IFNULL((SELECT '#10;
        s := s + '                     SUM(il.Total) AS Total '#10;
        s := s + '                 FROM '#10;
        s := s + '                     invoicelines il '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     (il.Total <> 0) '#10;
        s := s + '                         AND (il.InvoiceNumber = - 1) '#10;
        s := s + '                         AND (il.RoomReservation = rr.roomReservation) '#10;
        s := s + '                         AND NOT (rr.status IN (''X'' , ''C'') '#10;
        s := s + '                         AND il.isPackage)), 0) + CASE '#10;
        s := s + '                 WHEN '#10;
        s := s + '                     rr.breakfast = ''EXCLUDED'' '#10;
        s := s + '                 THEN '#10;
        s := s + '                     rr.breakfastprice * (SELECT '#10;
        s := s + '                             COUNT(id) '#10;
        s := s + '                         FROM '#10;
        s := s + '                             persons '#10;
        s := s + '                         WHERE '#10;
        s := s + '                             RoomReservation = rr.RoomReservation) * (SELECT '#10;
        s := s + '                             COUNT(id) '#10;
        s := s + '                         FROM '#10;
        s := s + '                             roomsdate rd1 '#10;
        s := s + '                         WHERE '#10;
        s := s + '                             rd1.roomreservation = rr.roomreservation '#10;
        s := s + '                                 AND rd1.resflag <> ''X'' '#10;
        s := s + '                                 AND NOT rd1.paid) '#10;
        s := s + '                 ELSE 0 '#10;
        s := s + '             END AS TotalNoRent, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     COUNT(ID) '#10;
        s := s + '                 FROM '#10;
        s := s + '                     roomsdate rd1 '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     rd1.ResFlag = rd.ResFlag '#10;
        s := s + '                         AND (rd1.RoomReservation = rd.roomReservation)) AS NumNights, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     SUM((rd1.RoomRate - IF(rd1.isPercentage, rd1.RoomRate * rd1.Discount / 100, rd1.Discount)) * cu1.AValue * ABS(rd1.Paid - 1)) '#10;
        s := s + '                 FROM '#10;
        s := s + '                     roomsdate rd1 '#10;
        s := s + '                 INNER JOIN currencies cu1 ON cu1.Currency = rd1.Currency '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     (NOT rd1.ResFlag IN (''X'' , ''C'', ''W'', ''Z'')) '#10;
        s := s + '                         AND (rd1.RoomReservation = rd.roomReservation)) AS TotalRent, '#10;
        s := s + '             (SELECT AVG(rd1.RoomRate) FROM roomsdate rd1 WHERE rd1.RoomReservation=rr.RoomReservation AND (rd1.ResFlag NOT IN (''X'',''C''))) AS AverageRoomRate, '#10;
        s := s + '             (SELECT AVG(rd1.RoomRate * cu1.AValue) '#10;
        s := s + '                FROM roomsdate rd1 '#10;
        s := s + '                INNER JOIN currencies cu1 ON cu1.Currency = rd1.Currency '#10;
        s := s + '                WHERE rd1.RoomReservation=rr.RoomReservation AND (rd1.ResFlag NOT IN (''X'',''C'')) '#10;
        s := s + '             ) AS AverageRoomRateNative, '#10;
        s := s + '             rr.PaymentGuaranteeType AS Guarantee, '#10;
        s := s + '             rr.InvoiceIndex AS InvoiceIndex, '#10;
        s := s + '             (SELECT DISTINCT '#10;
        s := s + '                     GROUP_CONCAT(InvoiceNumber) '#10;
        s := s + '                 FROM '#10;
        s := s + '                     invoiceheads '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     RoomReservation = rd.RoomReservation '#10;
        s := s + '                         AND InvoiceNumber > 0 '#10;
        s := s + '                 GROUP BY RoomReservation) AS Invoices, '#10;
        s := s + '             rr.RoomClass AS RoomClass, '#10;
        s := s + '             rv.Fax as rvFax, '#10;
        s := s + '             rv.invRefrence AS BookingId, '#10;
        s := s + '             rv.Tel2, '#10;
        s := s + '             rv.Tel1, '#10;
        s := s + '             pe.NumPersons AS NumGuests, '#10;
        s := s + '             pe.Name AS MainName, '#10;
        s := s + '             rv.PMInfo, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     SUM((IF(rd1.isPercentage, rd1.RoomRate * rd1.Discount / 100, rd1.Discount)) * cu1.AValue * ABS(rd1.Paid - 1)) '#10;
        s := s + '                 FROM '#10;
        s := s + '                     roomsdate rd1 '#10;
        s := s + '                 INNER JOIN currencies cu1 ON cu1.Currency = rd1.Currency '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     (NOT rd1.ResFlag IN (''X'' , ''C'', ''W'', ''Z'')) '#10;
        s := s + '                         AND (rd1.RoomReservation = rr.roomReservation)) AS Discount, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     MIN(rd1.isPercentage) '#10;
        s := s + '                 FROM '#10;
        s := s + '                     roomsdate rd1 '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     (NOT rd1.ResFlag IN (''X'' , ''C'', ''W'', ''Z'')) '#10;
        s := s + '                         AND (rd1.RoomReservation = rr.roomReservation)) AS AllIsPercentage, '#10;
        s := s + '             rr.PriceType AS PriceType, '#10;
        s := s + '             rd.Currency AS rdCurrency, '#10;
        s := s + '             (SELECT '#10;
        s := s + '                     id '#10;
        s := s + '                 FROM '#10;
        s := s + '                     invoicelines '#10;
        s := s + '                 WHERE '#10;
        s := s + '                     InvoiceNumber = - 1 '#10;
        s := s + '                         AND roomreservation = rd.roomreservation '#10;
        s := s + '                         AND NOT (rd.resflag = ''C'' AND isPackage) -- exclude package items on cancelled bookings '#10;
        s := s + '                 LIMIT 1) AS ItemsOnInvoice, '#10;
        s := s + '             CASE WHEN Breakfast = ''INCLUDED'' '#10;
        s := s + '               THEN BreakfastPrice '#10;
        s := s + '               ELSE 0 '#10;
        s := s + '             END as IncludedBreakfastPrice '#10;
        s := s + '     FROM '#10;
        s := s + '         roomsdate rd '#10;
        s := s + '     LEFT JOIN rooms ro ON ro.Room = rd.Room '#10;
        s := s + '     JOIN currencies cur ON cur.Currency = rd.Currency '#10;
        s := s + '     JOIN (SELECT -- pe'#10;
        s := s + '             COUNT(id) AS NumPersons, '#10;
        s := s + '             RoomReservation, '#10;
        s := s + '             IF(MainName, Name, '''') AS Name '#10;
        s := s + '           FROM persons '#10;
        s := s + '           WHERE '#10;
        s := s + '             RoomReservation IN (SELECT RoomReservation '#10;
        s := s + '                                 FROM roomsdate rd1 '#10;
        s := s + '                                 WHERE '#10;
        s := s + '                                    rd1.ADate >= ' + _db(fromDate) + ' '#10;
        s := s + '                                    AND rd1.ADate < ' + _db(toDate) + ' '#10;
        s := s + '                                    AND rd1.ResFlag NOT IN (''X'')) '#10;
        s := s + '           GROUP BY RoomReservation '#10;
        s := s + '           ORDER BY MainName DESC) pe ON pe.roomreservation = rd.roomreservation '#10;
        s := s + '     JOIN roomreservations rr ON rr.RoomReservation = rd.RoomReservation '#10;
        s := s + '     JOIN reservations rv ON rv.Reservation = rd.Reservation '#10;
        s := s + '     LEFT JOIN customers cu ON cu.Customer = rv.Customer '#10;
        s := s + '     WHERE '#10;
        s := s + '         ((ADate >= ' + _db(fromDate) + ') '#10;
        s := s + '             AND (ADate < ' + _db(toDate) + ')) '#10;
        s := s + '             AND (ResFlag <> ''X'') '#10;
        if skipCancelledBookings then
          s := s + '   AND (ResFlag <> '+_db(STATUS_CANCELLED)+' ) '#10;
        s := s + '             AND (ISNULL(ro.Room) OR NOT ro.Hidden) '#10;
        s := s + '     ORDER BY RoomReservation) xxx '#10;
        s := s + ' JOIN control co '#10;
        s := s + ' JOIN items i ON i.Item = co.RoomRentItem '#10;
        s := s + ' JOIN itemtypes it ON it.ItemType = i.ItemType '#10;
        s := s + ' JOIN vatcodes vc ON vc.VATCode = it.VATCode '#10;
        s := s + ' LEFT JOIN home100.TAXES tax ON HOTEL_ID = co.CompanyID '#10;
        s := s + '         AND VALID_FROM <= xxx.ADate '#10;
        s := s + '         AND VALID_TO >= xxx.ADate '#10;

        CopyToClipboard(s);
        exePlan.AddQuery(s);
      end;

      if NOT exePlan.Execute(ptQuery) then
         raise Exception.Create('Unable to retrieve from Roomer platform: ' + exePlan.ExecException);

      if Assigned(rExtraSet) then
      begin
        // Resultset are owned by execeutionplan, cannot just copy the link because executionplan is freed at the end of this method
        //        FreeAndNil(rExtraSet);
        //        rExtraSet := exePlan.Results[1]
        rExtraSet.Recordset := exePlan.Results[1].CloneToRecordset;
        rExtraSet.First;
      end;

     rSet := exePlan.Results[0];
     rSet.First;

     if not rSet.Eof then
     begin
       while not rSet.Eof do
       begin
         inc(result);
         qMt_.append;
         qMt_.ClearFields;
         RoomReservation := rSet.FieldByName('RoomReservation').asInteger;
         qMt_.FieldByName( 'RoomReservation' ).asInteger  := RoomReservation  ;
         qMt_.FieldByName( 'Room'            ).asString   := rSet.FieldByName('Room').asString  ;
         qMt_.FieldByName( 'Reservation'     ).asInteger  := rSet.FieldByName('Reservation').asInteger  ;
         qMt_.FieldByName( 'Channel'         ).asInteger  := rSet.FieldByName('Channel').asInteger  ;
         qMt_.FieldByName( 'PaymentInvoice'  ).asInteger  := rSet.FieldByName('PaymentInvoice').asInteger  ;
         qMt_.FieldByName( 'GroupAccount'    ).asBoolean  := rSet.FieldByName('GroupAccount').asBoolean  ;
         qMt_.FieldByName( 'resFlag'         ).asString   := rSet.FieldByName('Status').asString  ;
         qMt_.FieldByName( 'Arrival'         ).asDateTime := rSet.FieldByName('Arrival').asDateTime;
         qMt_.FieldByName( 'Departure'       ).asDateTime := rSet.FieldByName('Departure').asDateTime;
         qMt_.FieldByName( 'Customer'        ).asString   := rSet.FieldByName('Customer').asString;
         qMt_.FieldByName( 'CustomerName'    ).asString   := rSet.FieldByName('CustomerName').asString;
         qMt_.FieldByName( 'GuestName'       ).asString   := rSet.FieldByName('GuestName').asString;
         qMt_.FieldByName( 'NumGuests'       ).asInteger  := rSet.FieldByName('NumGuests').asInteger;
         qMt_.Post;
         rSet.Next;
       end;
     end;
  finally
    exePlan.Free;
  end;

  refresh(FFilter,FSortOn);
end;



function TRoomReservation.DateOrders(RoomReservation: integer;
                                     Adate: Tdate;
                                     var
                                     Channel,
                                     PaymentInvoice,
                                     AscIndex,
                                     DescIndex: integer;
                                     var
                                     GroupAccount : Boolean;
                                     var
                                     Customer
                                    ,CustomerName
                                    ,GuestName : string
                                     ): integer;
var
  Arrival       : Tdate;
  Departure     : Tdate;
begin
  result := 0;
  ascIndex  := -1;
  descIndex := -1;
//  Filter := 'RoomReservation='+inttostr(RoomReservation);

  if qMT_.Locate('RoomReservation',RoomReservation,[]) then
  begin
    Arrival      := qMt_.FieldByName('Arrival').asDateTime;
    Departure    := qMt_.FieldByName('Departure').asDateTime;
    Channel      := qMt_.FieldByName('Channel').asInteger;
    PaymentInvoice:= qMt_.FieldByName('PaymentInvoice').asInteger;
    GroupAccount := qMt_.FieldByName('GroupAccount').asBoolean;

    AscIndex     := Trunc((ADate - Arrival));
    DescIndex    := Trunc((Departure - Adate)-1);
    Customer     := qMt_.FieldByName('Customer').asString;
    customerName := qMt_.FieldByName('CustomerName').asString;
    GuestName    := qMt_.FieldByName('GuestName').asString;
  end;
end;


end.



