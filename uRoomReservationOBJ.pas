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
        s := 'SELECT ADate, ' +
             '    Room, ' +
             '    RoomType, ' +
             '    RoomReservation, ' +
             '    Reservation, ' +
             '    ResFlag, ' +
             '    Information, ' +
             '    OutOfOrderBlocking, ' +
             '    BlockMove, ' +
             '    BlockMoveReason, ' +
             '    TotalPayment, ' +
             '    TotalNoRent, ' +
             '    (IF(CityTaxIncl, 0, ' +
             ' 	  IF(taxPercentage, taxBaseAmount * taxAmount / 100, taxAmount) * ' +
             ' 		  IF(taxRoomNight, 1, ' +
             ' 			  IF(taxGuest, NumGuests, ' +
             ' 			    IF(taxGuestNight, NumGuests /  NumNights, ' +
             ' 				    IF(taxBooking, 1 / NumNights, 1 ) '+
             '              ) ' +
             '            ) ' +
             '          ) ' +
//             ' 	      ) / CurrencyRate) * numNights AS totalTaxes, ' +
             ' 	      ) * CurrencyRate ) * numNights AS totalTaxes, ' +
             '    TotalRent, ' +
             '    Guarantee, ' +
             '    InvoiceIndex, ' +
             '    Invoices, ' +
             '    RoomClass, ' +
             '    Fax, ' +
             '    BookingId, ' +
             '    PMInfo, ' +
             '    Tel2, ' +
             '    Tel1, ' +
             '    NumGuests, ' +
             '    MainName, ' +
             '    Price, ' +
             '    Discount, ' +
             '    to_bool(allIsPercentage) as AllIsPercentage, ' +
             '    PriceType, ' +
             '    Currency, ' +
             '    ItemsOnInvoice ' +
             ' ' +
             'FROM ( ' +

             'SELECT ';
        s := s + ' ADate ';
        s := s + ',rd.Room  ';
        s := s + ',rd.RoomType ';
        s := s + ',rd.RoomReservation ';
        s := s + ',rd.Reservation ';
        s := s + ',ResFlag ';
        s := s + ', rv.Information ';
        s := s + ', rv.OutOfOrderBlocking ';
        s := s + ', rr.BlockMove ';
        s := s + ', rr.BlockMoveReason ';
        s := s + ', cur.AValue AS CurrencyRate ';
        s := s + ', (SELECT SUM(pa.Amount) AS Total FROM payments pa WHERE (pa.Amount <> 0) AND (pa.InvoiceNumber = - 1) AND (pa.RoomReservation = rd.roomReservation)) AS TotalPayment ';
//        s := s + ', ( ';
//        s := s + ' SELECT ';
//        s := s + ' SUM(il.Total) ';
//        s := s + '   FROM ';
//        s := s + '  invoicelines il ';
//        s := s + '   WHERE ';
//        s := s + ' (il.Total <> 0) AND (il.InvoiceNumber = -1) AND (il.RoomReservation = rd.roomReservation )) ';
//        s := s + '  AS TotalNoRent, ';

        s := s + ', IFNULL(( '#10;
        s := s + '        SELECT '#10;
        s := s + '          SUM(il.Total) AS Total '#10;
        s := s + '        FROM '#10;
        s := s + '          invoicelines il '#10;
        s := s + '        WHERE '#10;
        s := s + '          (il.Total <> 0) AND (il.InvoiceNumber = - 1) AND (il.RoomReservation = rr.roomReservation ) '#10;
        s := s + '          AND not (rr.status in (''X'', ''C'') and il.isPackage) -- exclude package items of cancelled bookings '#10;
        s := s + '       ), 0) '#10;
        s := s + '		+ -- include unpaid excluded breakfasts '#10;
        s := s + '		CASE WHEN rr.breakfast = ''EXCLUDED'' '#10;
        s := s + '            THEN rr.breakfastprice * (SELECT COUNT(id) FROM persons WHERE RoomReservation=rr.RoomReservation) '#10;
        s := s + '                 * (select count(id) from roomsdate rd1 '#10;
        s := s + '                    where rd1.roomreservation=rr.roomreservation '#10;
        s := s + '                      and rd1.resflag <> ''X'' '#10;
        s := s + '                      and not rd1.paid) '#10;
        s := s + '			ELSE 0 '#10;
        s := s + '		END AS TotalNoRent '#10;


        s := s + ',      to_bool(IF(tax.INCL_EXCL=''INCLUDED'' OR ' +
			       '(tax.INCL_EXCL=''PER_CUSTOMER'' AND IFNULL(cu.StayTaxIncluted, 1)), 1, 0)) AS CityTaxInCl, ' +
			       'tax.AMOUNT AS taxAmount, ' +
			       'to_bool(IF(tax.TAX_TYPE=''FIXED_AMOUNT'', 0, 1)) AS taxPercentage, ' +
			       'to_bool(IF(tax.RETAXABLE=''FALSE'', 0, 1)) AS taxRetaxable, ' +
			       'to_bool(IF(tax.TAX_BASE=''ROOM_NIGHT'', 1, 0)) AS taxRoomNight, ' +
			       'to_bool(IF(tax.TAX_BASE=''GUEST_NIGHT'', 1, 0)) AS taxGuestNight, ' +
			       'to_bool(IF(tax.TAX_BASE=''GUEST'', 1, 0)) AS taxGuest, ' +
			       'to_bool(IF(tax.TAX_BASE=''BOOKING'', 1, 0)) AS taxBooking, ' +
			       'to_bool(IF(tax.NETTO_AMOUNT_BASED=''FALSE'', 0, 1)) AS taxNettoAmountBased, ' +
			       'IF(tax.NETTO_AMOUNT_BASED=''FALSE'', RoomRate, RoomRate / (1 + vc.VATPercentage/100)) AS taxBaseAmount, ' +
			       '(SELECT COUNT(ID) FROM roomsdate rd1 WHERE rd1.ResFlag =rd.ResFlag AND (rd1.RoomReservation = rd.roomReservation)) AS NumNights, ';
        s := s + ' ';
        s := s + ' ( ';
        s := s + ' SELECT ';
        s := s + ' SUM((rd1.RoomRate - IF(rd1.isPercentage, rd1.RoomRate * rd1.Discount / 100, rd1.Discount)) * cu1.AValue * ABS(rd1.Paid-1)) ';
        s := s + '   FROM ';
        s := s + '  roomsdate rd1 ';
        s := s + '  INNER JOIN currencies cu1 ON cu1.Currency=rd1.Currency ';
        s := s + '   WHERE ';
        s := s + ' (NOT rd1.ResFlag IN (''X'',''C'',''W'',''Z'')) AND (rd1.RoomReservation = rd.roomReservation )) ';
        s := s + '  AS TotalRent ';

        s := s + ', rr.PaymentGuaranteeType AS Guarantee ';
        s := s + ', rr.InvoiceIndex AS InvoiceIndex ';
        s := s + ', (SELECT DISTINCT GROUP_CONCAT(InvoiceNumber) FROM invoiceheads WHERE RoomReservation=rd.RoomReservation AND InvoiceNumber>0 GROUP BY RoomReservation) AS Invoices ';
        s := s + ', rr.RoomClass AS RoomClass ';
        s := s + ', rv.Fax ';
        s := s + ', rv.invRefrence AS BookingId ';
        s := s + ', rv.Tel2 ';
        s := s + ', rv.Tel1 ';
        s := s + ', pe.NumPersons AS NumGuests ';
        s := s + ', pe.Name AS MainName ';
        s := s + ', rv.PMInfo ';
        s := s + ', (SELECT AVG(rd1.RoomRate) FROM roomsdate rd1 WHERE rd1.RoomReservation=rd.RoomReservation AND (rd1.ResFlag NOT IN (''X'',''C''))) AS Price ';
//        s := s + ', rr.Discount AS Discount ';

        s := s + ', (SELECT '#10;
        s := s + '   SUM((IF(rd1.isPercentage, rd1.RoomRate * rd1.Discount / 100, rd1.Discount)) * cu1.AValue * ABS(rd1.Paid-1)) '#10;
        s := s + ' FROM '#10;
        s := s + '   roomsdate rd1 '#10;
        s := s + '   INNER JOIN currencies cu1 ON cu1.Currency=rd1.Currency '#10;
        s := s + ' WHERE '#10;
        s := s + '   (NOT rd1.ResFlag IN (''X'',''C'',''W'',''Z'')) AND (rd1.RoomReservation = rr.roomReservation ) '#10;
		 		s := s + ') as Discount '#10;

        s := s + ', (SELECT MIN(rd1.isPercentage) '#10;
        s := s + '     FROM roomsdate rd1 '#10;
        s := s + '     WHERE (NOT rd1.ResFlag IN (''X'',''C'',''W'',''Z'')) AND (rd1.RoomReservation = rr.roomReservation ) '#10;
        s := s + '  ) as AllIsPercentage '#10;

        s := s + ', rr.PriceType AS PriceType ';
        s := s + ', rd.Currency AS Currency ';

        s := s + ', (SELECT id FROM invoicelines WHERE InvoiceNumber=-1 AND roomreservation=rd.roomreservation '#10;
        s := s + '   AND not (rd.resflag = ''C'' and isPackage) LIMIT 1) AS ItemsOnInvoice '; // skip invoicelines of packages in cancelled reservations

        s := s + '  FROM ';
        s := s + ' roomsdate rd ';
        s := s + 'LEFT JOIN rooms ro ON ro.Room=rd.Room ' +
                 'JOIN currencies cur ON cur.Currency=rd.Currency ' +
                 'JOIN (SELECT COUNT(id) AS NumPersons, ' +
                 'RoomReservation, ' +
                 'IF(MainName, Name, '''') AS Name ' +
                 'FROM ' +
                 'persons ' +
                 'WHERE ' +
                 'RoomReservation IN (SELECT RoomReservation FROM roomsdate rd1 WHERE rd1.ADate>=' +
                      _db(fromDate, true) + ' AND rd1.ADate<' + _db(toDate, true) + ' AND rd1.ResFlag NOT IN (''X'')) ' +
                 'GROUP BY RoomReservation ' +
                 'ORDER BY MainName DESC ' +
                 ') pe ON pe.roomreservation = rd.roomreservation ' +
             'JOIN roomreservations rr ON rr.RoomReservation = rd.RoomReservation ' +
             'JOIN reservations rv ON rv.Reservation = rd.Reservation ' +
             'LEFT JOIN customers cu ON cu.Customer=rv.Customer ' +
             'JOIN control co ' +
             'JOIN items i ON i.Item=co.RoomRentItem ' +
             'JOIN itemtypes it ON it.ItemType=i.ItemType ' +
             'JOIN vatcodes vc ON vc.VATCode=it.VATCode ' +
             'LEFT JOIN home100.TAXES tax ON HOTEL_ID = co.CompanyID ' +
             'AND VALID_FROM <= rd.ADate ' +
             'AND VALID_TO >= rd.ADate ';

        s := s + '  WHERE (( ADate >= ' + _db(fromDate, true) + ' ) ';
        s := s + '   AND (ADate < ' + _db(toDate, true) + ' )) ';
        s := s + '   AND (ResFlag <> '+_db(STATUS_DELETED)+' ) '; //**zxhj line added

        if skipCancelledBookings then
          s := s +
                 '   AND (ResFlag <> '+_db(STATUS_CANCELLED)+' ) ';

        s := s + '   AND (ISNULL(ro.Room) OR NOT ro.Hidden) ';

        s := s + '  ORDER BY RoomReservation';
        s := s + ') xxx';

        {$ifdef DEBUG}
        CopyToClipboard(s);
        {$endif}
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



