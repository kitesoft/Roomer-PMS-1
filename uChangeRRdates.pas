unit uChangeRRdates;

(*
  121207 - checked for ww
*)

interface

uses
  Classes
    , Windows
    , Forms
    , PlannerDatePicker
    , sSkinProvider
    , sLabel
    , sGroupBox
    , sPanel
    , sButton
    , AdvEdit
    , AdvEdBtn
    , sEdit
    , sSpinEdit
    , Vcl.Mask
    , sMaskEdit
    , sCustomComboEdit
    , sToolEdit
    , acProgressBar
    , Vcl.Controls
    , Vcl.ExtCtrls
    , Vcl.StdCtrls
    , Vcl.ComCtrls
    , uRoomerDialogForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter,
  cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, dxStatusBar, sStatusBar, uMain,
  AdvSmoothProgressBar
    ;

type
  TfrmChangeRRdates = class(TfrmBaseRoomerDialogForm)
    sPanel1: TsPanel;
    gbrNextRR: TsGroupBox;
    labNextName: TsLabel;
    labNextGuest: TsLabel;
    LMDSimpleLabel3: TsLabel;
    LMDSimpleLabel4: TsLabel;
    LMDSimpleLabel5: TsLabel;
    labNextArrival: TsLabel;
    labNextDeparture: TsLabel;
    labNextStatus: TsLabel;
    labNextDays: TsLabel;
    gbrLastRR: TsGroupBox;
    labLastName: TsLabel;
    labLastGuest: TsLabel;
    LMDSimpleLabel6: TsLabel;
    LMDSimpleLabel7: TsLabel;
    LMDSimpleLabel8: TsLabel;
    LabLastArrival: TsLabel;
    labLastDeparture: TsLabel;
    labLastStatus: TsLabel;
    labLastDays: TsLabel;
    LMDSimplePanel1: TsPanel;
    gbxReservationsDates: TsGroupBox;
    labArrival: TsLabel;
    labDeparture: TsLabel;
    labNights: TsLabel;
    labWeekDayFrom: TsLabel;
    labWeekDayTo: TsLabel;
    labErr: TsLabel;
    sGroupBox1: TsGroupBox;
    Label1: TsLabel;
    sLabel1: TsLabel;
    btnSplit: TsButton;
    sLabel2: TsLabel;
    labPart1: TsLabel;
    labPart2: TsLabel;
    dtArrival: TsDateEdit;
    dtDeparture: TsDateEdit;
    edNightCount: TsSpinEdit;
    dtSplitAt: TsDateEdit;
    btnChangeDates: TsButton;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure btnChangeDatesClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure dtDepartureDblClick(Sender: TObject);
    procedure btnSplitClick(Sender: TObject);
    procedure dtUpdateControls(Sender: TObject);
  private
    { Private declarations }

    nextRoomReservation: integer;
    nextReservation: integer;
    nextName: string;
    nextGuest: string;

    nextArrival: Tdate;
    nextDeparture: Tdate;
    nextDays: integer;

    nextStatus: string;

    LastRoomReservation: integer;
    LastReservation: integer;
    LastName: string;
    LastGuest: string;

    LastArrival: Tdate;
    LastDeparture: Tdate;
    LastDays: integer;

    LastStatus: string;

    oldArrival: Tdate;
    oldDeparture: Tdate;

    zFirstTime: boolean;

    function RV_ChangeRoomDates(Reservation: integer): boolean;

  protected
    procedure DoUpdateControls; override;

  public
    { Public declarations }
    zArrival: Tdate;
    zDeparture: Tdate;

    zReservation: integer;
    zRoomReservation: integer;

    zNights: integer;

    zStartIn: integer;
    zDate: Tdate;
    zRoom: string;

    zCalcPrice: boolean;

    zIsPaid: boolean;

  end;

function RR_ChangeDates(RoomReservation: integer; newArrival, newDeparture: Tdate; PriceMedhod: integer;
  var isPaid: boolean; trx: boolean = true): boolean;

var
  frmChangeRRdates: TfrmChangeRRdates;

implementation

uses
  hData
    ,  Dialogs
    , uD
    , SysUtils
    , Graphics
    ,_glob
    , ug
    , uAppGlobal
    , ustringUtils
    , cmpRoomerDataSet
    , uProvideARoom2
    , uSqlDefinitions
    , PrjConst
    , uDateUtils
    , uRoomerDefinitions
    , uReservationStateDefinitions
    , uUtils
    , UITypes
    , uSQLUtils;

{$R *.dfm}


function RR_ChangeDates(RoomReservation: integer; newArrival, newDeparture: Tdate; PriceMedhod: integer;
  var isPaid: boolean; trx: boolean = true): boolean;
var
  lst: TStringlist;
  iNumErrors: integer;

  s: string;

  Reservation: integer;

  Room: string;
  RoomType: string;
  status: string;

  Currency: string;

  sNewArrival: string;
  sNewDeparture: string;

  sOldArrival: string;
  sOldDeparture: string;

  NumDays: integer;

  Rset: TRoomerDataSet;

  doIt: boolean;
  ii: integer;

  conflict_RoomReservation: integer;
  sConflict_Roomreservation: string;
  chkDate: Tdate;

  DayCount: integer;
  Processed: integer;
  FirstDate: Tdate;
  LastDate: Tdate;

  rate: double;
  sDate: string;

  priceType: string;

  Discount: double;
  isPercentage: boolean;
  showDiscount: boolean;

  rd_: TRoomerDataSet;
  rec: recRoomsDateHolder;
  recFirst: recRoomsDateHolder;
  recLast: recRoomsDateHolder;

  rdCount: integer;
  roomRateTotal: double;
  lstPrices: tstringlist;
  roomRate: double;
  discountTotal: double;
  averageRate: double;
  avrageDiscount: double;
  rateCount: integer;


  oldDayCount: integer;
  newDayCount: integer;

  paidCount: integer;
  isNoRoom: boolean;
  temp: String;

  ExePlan: TRoomerExecutionPlan;
  lSplit: TStringList;
  lDate: TDate;

begin
  Result := False;
  DoIt := false;
  screen.Cursor := crHourglass;

  avrageDiscount := 0;
  averageRate := 0;
  rateCount := 0;
  paidCount := 0;

  rd_ := nil;
  Rset := nil;
  lstPrices := TStringlist.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    sNewArrival := _db(newArrival, false);
    sNewDeparture := _db(newDeparture, false);
    NumDays := trunc(newDeparture) - trunc(newArrival);

    if NumDays < 1 then
    begin
      Showmessage(GetTranslatedText('shTx_ChangeRRdates_CheckDates'));
      exit;
    end;

    rd_ := CreateNewDataSet;

    s := '';
    s := s + 'SELECT * '#10;
    s := s + 'FROM roomsdate '#10;
    s := s + 'WHERE '#10;
    s := s + '  (roomreservation = %d) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // zxhj line added
    s := s + 'ORDER BY '#10;
    s := s + '  ADate '#10;
    s := format(s, [RoomReservation]);
    if hData.rSet_bySQL(rd_, s) then
    begin
      roomRateTotal := 0;
      discountTotal := 0;
      rdCount := 0;
      while not rd_.eof do
      begin
        inc(rdCount);
        if rd_.FieldByName('paid').asBoolean = true then
          inc(paidCount);

        roomRate := rd_.FieldByName('RoomRate').AsFloat;
        Discount := rd_.FieldByName('Discount').AsFloat;
        lstPrices.Add(floatTostr(roomRate) + floatTostr(Discount));
        roomRateTotal := roomRateTotal + roomRate;
        discountTotal := discountTotal + Discount;
        rd_.Next;
      end;
      averageRate := roomRateTotal / rdCount;
      avrageDiscount := discountTotal / rdCount;
      rateCount := lstPrices.Count;
    end;

    Rset := CreateNewDataSet;
    s := '';
    s := s + 'SELECT rr.*, '#10;
    s := s + '(SELECT GROUP_CONCAT(RoomReservation) ' +
      'FROM roomsdate ' +
      'WHERE ADate BETWEEN ''%s'' AND ''%s'' ' +
      'AND Room=rr.Room ' +
      'AND NOT (ResFlag IN (''X'',''C'')) ' +
      'AND RoomReservation != %d ' +
      'GROUP BY Room) AS Conflicts,'#10;
    s := s + '(SELECT GROUP_CONCAT(ADate) ' +
      'FROM roomsdate ' +
      'WHERE ADate BETWEEN ''%s'' AND ''%s'' ' +
      'AND RoomReservation = %d) AS existingDates ';
    s := s + 'FROM `roomreservations` rr '#10;
    s := s + 'WHERE '#10;
    s := s + '  (rr.roomreservation = %d) '#10;
    s := format(s, [dateToSqlString(newArrival),
      dateToSqlString(newArrival + NumDays - 1),
      RoomReservation,
      dateToSqlString(newArrival),
      dateToSqlString(newArrival + NumDays - 1),
      RoomReservation,
      RoomReservation]);

    if hData.rSet_bySQL(Rset, s) then
    begin
      Room := trim(Rset.FieldByName('Room').asString);
      Reservation := Rset.FieldByName('Reservation').asInteger;
      RoomType := trim(Rset.FieldByName('RoomType').asString);
      status := Rset.FieldByName('Status').asString;
      priceType := trim(Rset.FieldByName('PriceType').asString);
      Currency := trim(Rset.FieldByName('Currency').asString);

      temp := Rset.FieldByName('Conflicts').asString;
      lst := SplitStringToTStrings(',', temp);
      try
        doIt := true;
        isNoRoom := false;
        if lst.Count > 0 then
        begin
          case g.OpenRoomDateProblem(lst) of
            0:
              begin
                Room := '';
                isNoRoom := true;
                doIt := true;
              end;
            1:
              begin
                for ii := 0 to lst.Count - 1 do
                begin
                  conflict_RoomReservation := strToInt(lst[ii]);
                  MoveToRoomEnh2(conflict_RoomReservation, '');
                end;
                doIt := true;
              end;
            2:
              begin
                doIt := false;
              end;
          end;
        end;
      finally
        lst.Free;
      end;

      if doIt then
      begin
        iNumErrors := 0;

        Lst := nil;
        ExePlan := d.roomerMainDataSet.CreateExecutionPlan;
        try
          temp := Rset.FieldByName('existingDates').asString;
          lst := SplitStringToTStrings(',', temp);

          if trx then
            Rset.SystemStartTransaction;

          try
            if TReservationState.FromResStatus(status).InfluencesAvailability then
              d.roomerMainDataSet.SystemChangeAvailabilityForRoom(RoomReservation, false); //Increase availability

            ExePlan.AddExec('UPDATE roomsdate SET ResFlag =' + _db(STATUS_DELETED) + ' WHERE RoomReservation = ' +
              inttostr(RoomReservation));

            for ii := trunc(newArrival) to trunc(newArrival) + NumDays - 1 do
            begin
              lDate := ii;
              sDate := _db(lDate, false);
              if rateCount = 1 then // same rate all days 5 11 4 12 3 13 2 14 1 15 0 16 -1
              begin
                rd_.First;
                initRoomsDateHolderRec(rec);
                rec.ADate := sDate;
                if Room = '' then
                begin
                  Room := '<' + inttostr(RoomReservation) + '>';
                  isNoRoom := true;
                end;
                rec.Room := Room;
                rec.isNoRoom := isNoRoom;
                rec.RoomType := RoomType;
                rec.RoomReservation := RoomReservation;
                rec.ResFlag := status;
                rec.Reservation := Reservation;
                rec.PriceCode := priceType;
                rec.roomRate := rd_.FieldByName('RoomRate').AsFloat;
                rec.Discount := rd_.FieldByName('Discount').AsFloat;
                rec.isPercentage := rd_.FieldByName('isPercentage').asBoolean;
                rec.showDiscount := rd_.FieldByName('showDiscount').asBoolean;
                if paidCount > 0 then
                begin
                  rec.Paid := true;
                  dec(paidCount);
                end
                else
                begin
                  rec.Paid := false;
                end;
                rec.Currency := rd_.FieldByName('Currency').asString;

                if lst.IndexOf(sDate) >= 0 then
                begin
                  s := ' UPDATE roomsdate ' + #10;
                  s := s + ' SET ' + #10;
                  s := s + '     resFlag  = ' + _db(status) + ' ' + #10;
                  s := s + '     , Room  = ' + _db(Room) + ' ' + #10;
                  if rec.Paid then
                    s := s + '     , Paid  = 1' + #10
                  else
                    s := s + '     , Paid  = 0' + #10;
                  s := s + ' WHERE ' + #10;
                  s := s + '       (roomreservation= ' + _db(RoomReservation) + ') and (Adate=' + _db(sDate) +
                    ') ' + #10;
                  ExePlan.AddExec(s);
                end
                else
                begin
                  ExePlan.AddExec(hData.SQL_INS_RoomsDate(rec));
                end;
              end
              else
              begin
                rd_.First;
                initRoomsDateHolderRec(rec);
                rec.ADate := sDate;
                if Room = '' then
                begin
                  Room := '<' + inttostr(RoomReservation) + '>';
                  isNoRoom := true;
                end;
                rec.Room := Room;
                rec.isNoRoom := isNoRoom;
                rec.RoomType := RoomType;
                rec.RoomReservation := RoomReservation;
                rec.ResFlag := status;
                rec.Reservation := Reservation;
                rec.PriceCode := priceType;
                rec.roomRate := averageRate;
                rec.Discount := avrageDiscount;
                rec.isPercentage := rd_.FieldByName('isPercentage').asBoolean;
                rec.showDiscount := rd_.FieldByName('showDiscount').asBoolean;
                if paidCount > 0 then
                begin
                  rec.Paid := true;
                  dec(paidCount);
                end
                else
                begin
                  rec.Paid := false;
                end;
                rec.Currency := rd_.FieldByName('Currency').asString;

                if lst.IndexOf(sDate) >= 0 then
                begin
                  s := ' UPDATE roomsdate ' + #10;
                  s := s + ' SET ' + #10;
                  s := s + '     resFlag  = ' + _db(status) + ' ' + #10;
                  s := s + '     , Room  = ' + _db(Room) + ' ' + #10;
                  s := s + ' WHERE ' + #10;
                  s := s + '       (roomreservation= ' + _db(RoomReservation) + ') and (Adate=' + _db(sDate) +
                    ') ' + #10;
                  ExePlan.AddExec(s);
                end
                else
                begin
                  ExePlan.AddExec(hData.SQL_INS_RoomsDate(rec));
                end;
              end;
            end;

            s := ' DELETE FROM roomsdate where ResFlag =' + _db(STATUS_DELETED) + ' AND RoomReservation = ' + _db(RoomReservation) + #10;
            ExePlan.AddExec(s);

            s := format('UPDATE roomreservations SET Arrival=%s, departure=%s, rrArrival=%s, rrDeparture=%s WHERE RoomReservation = %d',
                [
                  _db(newArrival, true),
                  _db(newDeparture, true),
                  _db(newArrival, true),
                  _db(newDeparture, true),
                  RoomReservation
                ]);
            ExePlan.AddExec(s);

            ExePlan.Execute(ptExec, false, false);
            if TReservationState.FromResStatus(status).InfluencesAvailability then
              d.roomerMainDataSet.SystemChangeAvailabilityForRoom(RoomReservation, true); //decrease availability

            if trx then
              Rset.SystemCommitTransaction;
          except
            if trx then
              Rset.SystemRollbackTransaction;
            raise;
          end;
        finally
          lst.Free;
          FreeAndNil(ExePlan);
        end;

        if iNumErrors > 0 then
        begin
          s := '';
          s := s + GetTranslatedText('shTx_ChangeRRdates_SomeErrors') + #10;
          s := s + inttostr(iNumErrors) + GetTranslatedText('shTx_ChangeRRdates_Total') + #10 + #10;
          MessageDlg(s, mtWarning, [mbOK], 0);
        end
        else
        begin
          Rset.edit;
          Rset.FieldByName('Room').asString := Room;
          Rset.FieldByName('Arrival').asString := sNewArrival;
          Rset.FieldByName('Departure').asString := sNewDeparture;
          Rset.FieldByName('rrDeparture').asDateTime := newDeparture;
          Rset.FieldByName('rrArrival').asDateTime := newArrival;
          Rset.Post;
        end;

        d.roomerMainDataSet.SystemCorrectDoorCodeSettings(RoomReservation);
      end;
    end;
    result := doIt;
  finally
    rd_.Free;
    Rset.Free;
    lstPrices.Free;
    screen.Cursor := crDefault;
  end;
end;

procedure TfrmChangeRRdates.DoUpdateControls;
var
  iNights: integer;
  lErrorMessage: string;
  lOverlapMessage: string;
begin
  inherited;

  if dtArrival.CheckValidDate(False) and dtDeparture.CheckValidDate(false) then
  begin

    lErrorMessage := '';

    labWeekDayFrom.caption := _strTokenAt(GetTranslatedText('dayStr1'), ';', DayOfWeek(dtArrival.date) - 1);
    labWeekDayTo.caption := _strTokenAt(GetTranslatedText('dayStr1'), ';', DayOfWeek(dtDeparture.date) - 1);

    // Adjust other controls to the active one
    if Screen.ActiveControl = dtArrival then
      dtDeparture.Date := dtArrival.Date + edNightCount.Value
    else if Screen.ActiveControl = dtDeparture then
      edNightCount.Value := trunc(dtDeparture.Date - dtArrival.Date)
    else if Screen.ActiveControl = edNightCount then
      dtDeparture.Date := dtArrival.Date + edNightCount.Value;

    iNights := trunc(dtDeparture.date) - trunc(dtArrival.date);


    if iNights = 0 then
      lErrorMessage := GetTranslatedText('shTx_ChangeRRdates_ErrorSameDate')
    else if iNights < 0 then
      lErrorMessage := GetTranslatedText('shTx_ChangeRRdates_CheckinAfterCheckout');


    gbrNextRR.Color := clBtnface;
    gbrLastRR.Color := clBtnface;
    if dtDeparture.date > nextArrival then
    begin
      gbrNextRR.Color := clRed;
      lOverlapMessage := GetTranslatedText('shTx_ChangeRRdates_BookingOverlap');
    end;
    if dtArrival.date < LastDeparture then
    begin
      gbrLastRR.Color := clRed;
      lOverlapMessage := GetTranslatedText('shTx_ChangeRRdates_BookingOverlap');
    end;


    if not lErrorMessage.IsEmpty then
    begin
      labErr.Font.Color := clRed;
      labErr.Color := clYellow;

      labErr.caption := lErrorMessage;
      btnOK.Enabled := false;
    end
    else if not lOverlapMessage.IsEmpty then
    begin
      labErr.Font.Color := clBlack;
      labErr.Color := clYellow;

      gbrNextRR.Color := clRed;
      labErr.caption := lOverlapMessage;
      btnOk.Enabled  := true;
    end
    else
    begin
      labErr.caption := '';
      labErr.Font.Color := clBlack;
      labErr.Color := clBtnface;

      btnOK.Enabled := true;
    end;

    labErr.Left := edNightCount.Left + (edNightCount.Width div 2) - (labErr.Width div 2);


  end
  else
    btnOk.Enabled := False;

  btnSplit.Enabled := dtSplitAt.CheckValidDate(false) and (zArrival < dtSplitAt.date) and (dtSplitAt.Date <= zDeparture);
end;

procedure TfrmChangeRRdates.FormCreate(Sender: TObject);
begin
  zFirstTime := true;
  zCalcPrice := false;
end;

procedure TfrmChangeRRdates.FormShow(Sender: TObject);
var
  resInfo: recResDateHolder;
begin
  DialogButtons := [mbClose];

  oldArrival := zArrival;
  oldDeparture := zDeparture;

  nextArrival := zDeparture + 10; // init to save zone
  LastDeparture := zArrival - 10; // init to save zone

  dtArrival.date := zArrival;
  dtDeparture.date := zDeparture;
  edNightCount.Value := trunc(dtDeparture.date - dtArrival.Date);
  dtSplitAt.date := zArrival + 1;

  zIsPaid := false;

  zRoom := '';
  if zRoomReservation > 0 then
  begin
    zRoom := RR_GetRoomNumber(zRoomReservation);

    if rd_Ispaid(zRoomReservation) then
    begin
      Showmessage(GetTranslatedText('shTx_ChangeRRdates_PaidInvoicesReviewAfterChange'));
      zIsPaid := true;
    end;
  end;

  nextRoomReservation := d.NextRoomReservatiaon(zRoom, zRoomReservation, zArrival + 1);

  if nextRoomReservation > 1 then
  begin
    resInfo := d.RR_getDates(nextRoomReservation);

    nextReservation := resInfo.Reservation;
    nextArrival := resInfo.Arrival;
    nextDeparture := resInfo.Departure;
    nextStatus := resInfo.status;

    nextName := d.RR_GetReservationName(nextRoomReservation);
    nextGuest := d.RR_GetFirstGuestName(nextRoomReservation);

    nextDays := 0;
  end
  else
  begin
    nextReservation := 0;
    nextArrival := zArrival + 700;
    nextDeparture := zDeparture + 700;
    nextStatus := 'No Reservation';
    nextDays := 0;
    nextName := '';
    nextGuest := '';
  end;

  labNextArrival.caption := dateTostr(nextArrival);
  labNextDeparture.caption := dateTostr(nextDeparture);
  labNextStatus.caption := nextStatus;
  labNextDays.caption := inttostr(nextDays);
  labNextName.caption := nextName;
  labNextGuest.caption := nextGuest;


  // ****************************************************************************

  LastRoomReservation := d.LastRoomReservatiaon(zRoom, zRoomReservation, zArrival + 1);

  if LastRoomReservation > 1 then
  begin
    resInfo := d.RR_getDates(LastRoomReservation);

    LastReservation := resInfo.Reservation;
    LastArrival := resInfo.Arrival;
    LastDeparture := resInfo.Departure;
    LastStatus := resInfo.status;

    LastName := d.RR_GetReservationName(LastRoomReservation);
    LastGuest := d.RR_GetFirstGuestName(LastRoomReservation);

    LastDays := 0;
  end
  else
  begin
    LastReservation := 0;
    LastArrival := zArrival - 700;
    LastDeparture := zDeparture - 700;
    LastStatus := 'No Reservation';
    LastDays := 0;
    LastName := '';
    LastGuest := '';
  end;

  LabLastArrival.caption := dateTostr(LastArrival);
  labLastDeparture.caption := dateTostr(LastDeparture);
  labLastStatus.caption := LastStatus;
  labLastDays.caption := inttostr(LastDays);
  labLastName.caption := LastName;
  labLastGuest.caption := LastGuest;

  case self.zStartIn of
    1:
      ActiveControl := dtArrival;
    2:
      ActiveControl := dtDeparture;
    3:
      ActiveControl := edNightCount;
  end;

  zFirstTime := false;

end;

procedure TfrmChangeRRdates.btnChangeDatesClick(Sender: TObject);
var
  isPaid: boolean;
  rr: integer;

begin
  // **
  if MessageDlg('Change room dates ', mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    zArrival := dtArrival.date;
    zDeparture := dtDeparture.date;

    if (oldArrival <> zArrival) or (oldDeparture <> zDeparture) then
    begin
      if zRoomReservation = 0 then
      begin
        if not RV_ChangeRoomDates(zReservation) then
        begin
          zArrival := 1;
          zDeparture := 1;
        end;
      end
      else
      begin
        isPaid := false;
        if not RR_ChangeDates(zRoomReservation, zArrival, zDeparture, 0, isPaid) then
        begin
          zArrival := 1;
          zDeparture := 1;
        end
        else
        begin
          if d.isGroup(zRoomReservation) then
            rr := 0
          else
            rr := zRoomReservation;
          d.roomerMainDataSet.SystempackagesRecalcInvoice(rr, zRoomReservation);
          if isPaid then
          begin
            //
          end;
        end;
      end;
    end;
  end;
end;

procedure TfrmChangeRRdates.btnCancelClick(Sender: TObject);
begin
  // **
  zArrival := 1;
  zDeparture := 1;
end;

procedure TfrmChangeRRdates.dtDepartureDblClick(Sender: TObject);
begin
  dtDeparture.date := dtArrival.date + edNightCount.Value;
end;

procedure TfrmChangeRRdates.dtUpdateControls(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

function TfrmChangeRRdates.RV_ChangeRoomDates(Reservation: integer): boolean;
var
  bAll: boolean;
  noOfRooms: integer;
  s: string;
  NumDays: integer;
  Rset: TRoomerDataSet;
  RoomReservation: integer;
  changeCount: integer;

  dateHolder: recResDateHolder;
  isPaid: boolean;
  rr,
    iCount: integer;

begin
  result := false;
  bAll := true;

  changeCount := 0;
  noOfRooms := d.RR_GetNumberOfRooms(Reservation);

  dateHolder := d.RV_getDates(Reservation);

  if noOfRooms > 1 then
  begin
    if not d.isAllDatesSameInRes(Reservation) then
    begin
      s := GetTranslatedText('shTx_ChangeRRdates_RoomDatesChangeAll') + #10;
      bAll := MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes;
    end;
  end;

  Rset := CreateNewDataSet;
  try
    s := '';
    s := select_ReservationProfile_RegulateRoomDates(bAll);
    if NOT bAll then
      s := format(s, [Reservation, _db(dateHolder.Arrival, true),
        _db(dateHolder.Departure, true)])
    else
      s := format(s, [Reservation]);

    Rset.SystemStartTransaction;
    try
      screen.Cursor := crHourglass;
      try
        hData.rSet_bySQL(Rset, s);
      finally
        screen.Cursor := crDefault;
      end;

      NumDays := trunc(dtDeparture.date) - trunc(dtArrival.date);

      if NumDays < 1 then
      begin
        Showmessage(GetTranslatedText('shTx_ChangeRRdates_MustBe1Day'));

      end
      else
      begin
        screen.Cursor := crHourglass;
        try
          iCount := 0;
          Rset.First;
          while not Rset.eof do
          begin
            inc(iCount);
            Rset.Next;
          end;

          ProgressBar.Maximum := iCount * 2;
          ProgressBar.Position := 0;
          iCount := 0;

          Rset.First;
          while not Rset.eof do
          begin
            RoomReservation := Rset.FieldByName('RoomReservation').asInteger;

            changeCount := changeCount + 1;
            isPaid := false;
            RR_ChangeDates(RoomReservation, dtArrival.date, dtDeparture.date, 0, isPaid, false);

            inc(iCount);
            ProgressBar.Position := iCount;
            Rset.Next;
          end;

          Rset.First;
          while not Rset.eof do
          begin
            RoomReservation := Rset.FieldByName('RoomReservation').asInteger;
            if Rset['Groupaccount'] then
              rr := 0
            else
              rr := RoomReservation;

            d.roomerMainDataSet.SystempackagesRecalcInvoice(rr, RoomReservation);

            inc(iCount);
            ProgressBar.Position := iCount;
            Rset.Next;
          end;
        finally
          screen.Cursor := crDefault;
        end;
      end;
      Rset.SystemCommitTransaction;
    except
      Rset.SystemRollbackTransaction;
      raise;
    end;
  finally
    FreeAndNil(Rset);
  end;

  if changeCount > 0 then
  begin
    result := true;
    zArrival := dtArrival.date;
    zDeparture := dtDeparture.date;
  end;

  BringToFront;
end;

procedure TfrmChangeRRdates.btnSplitClick(Sender: TObject);
var
  Rset: TRoomerDataSet;

  Arrival1: TdateTime;
  Departure1: TdateTime;

  Arrival2: TdateTime;
  Departure2: TdateTime;

  roomHolder: recRoomReservationHolder;

  firstHolder: recRoomReservationHolder;

  newRrId: integer;
  s: string;

  ExecutionPlan: TRoomerExecutionPlan;
  sDate: string;
  iDayCount: integer;
  ii: integer;
  personData: RecPersonHolder;
  package: string;
  rr: integer;
  lDate: TDate;

begin
  // **
  if MessageDlg('Split reservation at ' + dateTostr(dtSplitAt.date), mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    roomHolder := SP_GET_RoomReservation(zRoomReservation);
    firstHolder := roomHolder;
    package := roomHolder.package;

    Arrival1 := zArrival;
    Departure1 := dtSplitAt.date;
    Arrival2 := dtSplitAt.date;
    Departure2 := zDeparture;

    ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try
      ExecutionPlan.BeginTransaction;
      try

        newRrId := RR_SetNewID();
        firstHolder.RoomReservation := newRrId;
        firstHolder.Arrival := Arrival1;
        firstHolder.Departure := Departure1;

        Rset := CreateNewDataSet;
        try
          s := '';
          s := s + ' SELECT '#10;
          s := s + '  AVG(RoomRate) AS averageRate '#10;
          s := s + '  ,count(distinct RoomRate) AS rateCount '#10;
          s := s + ' FROM  '#10;
          s := s + '   roomsdate '#10;
          s := s + ' WHERE (ADate >= %s '#10;
          s := s + '  and ADate < %s) '#10;
          s := s + ' AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '#10;
          s := s + ' AND (roomreservation = ' + _db(roomHolder.RoomReservation) + ') '#10;
          s := format(s, [_db(Arrival1, true), _db(Departure1, true)]);

          if hData.rSet_bySQL(Rset, s) then
          begin
            firstHolder.averageRate := Rset.FieldByName('averageRate').AsFloat;
            firstHolder.rateCount := Rset.FieldByName('rateCount').asInteger;
          end;
        finally
          FreeAndNil(Rset);
        end;

        s := SQL_UPDATE_RoomReservation(firstHolder);
        // copyToClipboard(s);
        // DebugMessage('invoicelines '#10#10+s);
        ExecutionPlan.AddExec(s);

        roomHolder.Arrival := Arrival2;
        roomHolder.Departure := Departure2;

        Rset := CreateNewDataSet;
        try
          s := '';
          s := s + ' SELECT '#10;
          s := s + '  AVG(RoomRate) AS averageRate '#10;
          s := s + '  ,count(distinct RoomRate) AS rateCount '#10;
          s := s + ' FROM  '#10;
          s := s + '   roomsdate '#10;
          s := s + ' WHERE (ADate >= %s '#10;
          s := s + '  and ADate < %s) '#10;
          s := s + ' AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '#10;
          s := s + ' AND (roomreservation = ' + _db(roomHolder.RoomReservation) + ') '#10;
          s := format(s, [_db(Arrival2, true), _db(Departure2, true)]);

          if hData.rSet_bySQL(Rset, s) then
          begin
            roomHolder.averageRate := Rset.FieldByName('averageRate').AsFloat;
            roomHolder.rateCount := Rset.FieldByName('rateCount').asInteger;
          end;
        finally
          FreeAndNil(Rset);
        end;

        s := '';
        s := s + ' UPDATE roomreservations ';
        s := s + ' SET ';
        s := s + '  Arrival = ' + _db(Arrival2) + ' ';
        s := s + ' ,Departure = ' + _db(Departure2) + ' ';
        s := s + ' ,rateCount = ' + _db(roomHolder.rateCount) + ' ';

        s := s + ' WHERE ';
        s := s + '   (roomreservation=' + _db(roomHolder.RoomReservation) + ') ';
        // copyToClipboard(s);
        // DebugMessage('invoicelines '#10#10+s);
        ExecutionPlan.AddExec(s);

        iDayCount := trunc(Departure1) - trunc(Arrival1);
        for ii := trunc(Arrival1) to trunc(Arrival1) + iDayCount - 1 do
        begin
          lDate := ii;
          sDate := _db(lDate, false);
          s := '';
          s := s + ' UPDATE roomsdate ';
          s := s + ' SET ';
          s := s + ' roomreservation = ' + _db(newRrId) + ' ';
          s := s + ' WHERE ';
          s := s + '   (Adate = ' + _db(sDate) + ') ';
          s := s + '  AND (roomreservation=' + _db(roomHolder.RoomReservation) + ') ';

          // copyToClipboard(s);
          // DebugMessage(s);
          ExecutionPlan.AddExec(s);
        end;

        Rset := CreateNewDataSet;
        try
          s := '';
          s := s + ' SELECT '#10;
          s := s + '  * '#10;
          s := s + ' FROM  '#10;
          s := s + '   persons '#10;
          s := s + ' WHERE '#10;
          s := s + ' (roomreservation = ' + _db(roomHolder.RoomReservation) + ') '#10;

          if hData.rSet_bySQL(Rset, s) then
          begin
            while not Rset.eof do
            begin
              initPersonHolder(personData);
              personData.Person := Rset.FieldByName('person').asInteger;
              personData.RoomReservation := newRrId;
              personData.Reservation := Rset.FieldByName('Reservation').asInteger;
              personData.name := Rset.FieldByName('name').asString;
              personData.Surname := Rset.FieldByName('Surname').asString;
              personData.Address1 := Rset.FieldByName('Address1').asString;
              personData.Address2 := Rset.FieldByName('Address2').asString;
              personData.Address3 := Rset.FieldByName('Address3').asString;
              personData.Address4 := Rset.FieldByName('Address4').asString;
              personData.Country := Rset.FieldByName('Country').asString;
              personData.Company := Rset.FieldByName('Company').asString;
              personData.GuestType := Rset.FieldByName('GuestType').asString;
              personData.Information := Rset.FieldByName('Information').asString;
              personData.PID := Rset.FieldByName('PID').asString;
              personData.MainName := Rset.FieldByName('MainName').asBoolean;
              personData.Customer := Rset.FieldByName('Customer').asString;
              personData.peTmp := Rset.FieldByName('peTmp').asString;
              s := SQL_INS_Person(personData);
              // copyToClipboard(s);
              // DebugMessage('invoicelines '#10#10+s);
              ExecutionPlan.AddExec(s);
              Rset.Next;
            end;
          end;

        finally
          FreeAndNil(Rset);
        end;

        if ExecutionPlan.Execute(ptExec, false, true) then
          ExecutionPlan.CommitTransaction
        else
          raise Exception.Create(ExecutionPlan.ExecException);

        if package <> '' then
        begin
          if d.isGroup(zRoomReservation) then
            rr := 0
          else
            rr := zRoomReservation;

          d.roomerMainDataSet.SystempackagesRecalcInvoice(rr, zRoomReservation);
        end;

      except
        on e: Exception do
        begin
          ExecutionPlan.RollbackTransaction;
          Showmessage('Splitting reservation: ' + e.message);
        end;
      end;
    finally
      FreeAndNil(ExecutionPlan);
    end;
  end;
end;

end.
