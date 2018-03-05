unit uReservationHintHolder;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, sPanel, Vcl.StdCtrls, sButton, sLabel,
  uPopupListEx, uAppGlobal, hData, uG, _Glob, uUtils, AdvShape, PrjConst, sMemo, HTMLabel, Vcl.Menus, sCheckBox, uAmount;

type

  THintButtonClicked = (hbcLogin, hbcLogOut);


  TFrmReservationHintHolder = class(TForm)
    pnlHint: TsPanel;

    __lbStatus: TsLabel;
    __lbName: TsLabel;
    __lbRoom: TsLabel;
    __lbGuests: TsLabel;
    __lbChannel: TsLabel;
    __lbRatePlan: TsLabel;
    __lbDeparture: TsLabel;
    __lbArrival: TsLabel;
    __lbNotes: TsMemo;
    __hlblTotal: THTMLabel;
    __hlblDaily: THTMLabel;

    clbStatus: TsLabel;
    clbName: TsLabel;
    clbRoom: TsLabel;
    clbGuests: TsLabel;
    clbChannel: TsLabel;
    clbRatePlan: TsLabel;
    clbDeparture: TsLabel;
    clbArrival: TsLabel;
    clbRate: TsLabel;
    clbNotes: TsLabel;
    clbTotal: TsLabel;
    clblDaily: TsLabel;
    timHide: TTimer;
    shpStatus: TShape;
    Shape1: TShape;
    sLabel1: TsLabel;
    __hlbBookingIds: THTMLabel;
    PopupMenu1: TPopupMenu;
    C1: TMenuItem;
    Shape2: TShape;
    __lbPAymentNotes: TsMemo;
    sLabel2: TsLabel;
    clbInvoiceStatus: TsLabel;
    HTMLabel1: THTMLabel;
    sLabel5: TsLabel;
    __hlblTotalInvoice: THTMLabel;
    clbRoomRentInvoice: TsLabel;
    hlbGuarantee: THTMLabel;
    sLabel3: TsLabel;
    Shape3: TShape;
    __labBlockNote: TsLabel;
    cbxBlocked: TsCheckBox;
    procedure timHideTimer(Sender: TObject);
    procedure C1Click(Sender: TObject);
    procedure pnlHintMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure pnlHintMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure PopupMenu1Popup(Sender: TObject);
    procedure pnlHintMouseEnter(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    currentControl : TObject;
    rri: RecRDInfo;
    procedure PlaceHint(X, Y, CellWidth, CellHeight: Integer);
    procedure ReadInfo(rri: RecRDInfo);
    procedure CM_MenuClosed(var msg: TMessage) ; message CM_MENU_CLOSED;
    procedure CM_ExitMenuLoop(var msg: TMessage) ; message CM_EXIT_MENU_LOOP;
    procedure GetPriceInfo(rri: RecRDInfo; var TotalPrice, TotalDiscount, TotalPriceNetto, PriceNight, DiscountNight,
      PriceNightNetto: TAmount);
    function GetBookingId(rri: RecRDInfo): String;
    function GetChannelName(rriChannel: Integer): String;
    function GetTrimmedPercentage(value: Double): String;

  public
    procedure CancelHint;
    procedure InitEmbededHint(prnt : TWinControl);
    procedure ActivateHint(X, Y, CellWidth, CellHeight : Integer; rri: RecRDInfo);
  end;

implementation

{$R *.dfm}

uses clipbrd
  , uMain
  , UITypes
  , uRoomerLanguage
  , Math
  , uDateTimeHelper
  , uCurrencyConstants;

{ TFrmReservationHintHolder }

procedure TFrmReservationHintHolder.ActivateHint(X, Y, CellWidth, CellHeight: Integer; rri: RecRDInfo);
begin
  self.rri := rri;
  pnlHint.Left := X + CellWidth - 4;
//  pnlHint.Top := (Y + CellHeight div 2) - (pnlHint.Height div 2);
  pnlHint.Top := Y - (pnlHint.Height div 2);

  PlaceHint(X, Y, CellWidth, CellHeight);
  ReadInfo(rri);

  pnlHint.Show;
  timHide.Enabled := True;
end;

procedure TFrmReservationHintHolder.GetPriceInfo(rri: RecRDInfo;
            var TotalPrice, TotalDiscount, TotalPriceNetto, PriceNight, DiscountNight, PriceNightNetto : TAmount);
var
  lNights: integer;
begin
  lNights := max(trunc(rri.Departure) - trunc(rri.Arrival), 1);
  PriceNight := TAmount.Create(rri.Price, rri.Currency);
  DiscountNight := TAmount.Create(rri.TotalDiscountAmount, rri.Currency)  / lNights;
  PriceNightNetto := PriceNight - DiscountNight;

  TotalPrice := PriceNight * lNights;
  TotalPriceNetto := PriceNightNetto * lNights;
  TotalDiscount := rri.TotalDiscountAmount;
end;

function TFrmReservationHintHolder.GetChannelName(rriChannel : Integer) : String;
begin
    if glb.LocateChannelById(rriChannel) then
      result := glb.ChannelsSet['name']
    else
      result := GetTranslatedText('shUI_ManuallyEnteredReservation');
end;

function TFrmReservationHintHolder.GetBookingId(rri: RecRDInfo) : String;
begin
  result := rri.BookingId;
  if trim(result) = '' then
    result := GetTranslatedText('shUI_NotAvailable');
end;

function TFrmReservationHintHolder.GetTrimmedPercentage(value : Double) : String;
begin
  if SameValue(value, trunc(value)) then
    result := trim(_floatToStr(value, 12, 0))
  else
    result := trim(_floatToStr(value, 12, 2));
end;

procedure TFrmReservationHintHolder.ReadInfo(rri: RecRDInfo);
var TotalPrice, TotalDiscount, TotalPriceNetto, PriceNight, DiscountNight, PriceNightNetto : TAmount;
    backColor, fontColor : TColor;
    sColor1, sColor2 : String;
    temp : String;
begin
  ResStatusToColor(rri.resFlag, backColor, fontColor);
  shpStatus.Brush.Color := BackColor;
  shpStatus.Pen.Color := BackColor;
  __lbStatus.Caption := Status2StatusTextForHints(rri.resFlag);
  __lbName.Caption := rri.GuestName;
  if copy(rri.Room, 1, 1) <> '<' then
    __lbRoom.Caption := format('%s / %s', [rri.Room, rri.RoomType])
  else
    __lbRoom.Caption := format('%s / %s', [GetTranslatedText('shUI_NotAvailable'), rri.RoomType]);
  __lbGuests.Caption := inttostr(rri.numGuests);
  __lbChannel.Caption := GetChannelName(rri.Channel);
  if rri.RoomClass = '' then
    __lbRatePlan.Caption := rri.PriceType
  else
    __lbRatePlan.Caption := rri.RoomClass;

  __lbArrival.Caption := Capitalize(FormatDateTime('ddd, ', rri.Arrival)) + DatetoStr(rri.Arrival);
  __lbDeparture.Caption := Format('%s, %s (%s %s)',
              [Capitalize(FormatDateTime('ddd, ', rri.Departure)),
               DateToStr(rri.Departure),
               IntToStr(trunc(rri.Departure - rri.Arrival)),
               GetTranslatedText('shUI_nights')
              ]);

  __hlbBookingIds.HTMLText.Text := format('Channel: <B>%s</B><br>Reservationid: <B>%d</B> (RoomresId: <B>%d</B>)<br>',
              [
                GetBookingId(rri),
                rri.Reservation,
                rri.RoomReservation
              ]);

  GetPriceInfo(rri, TotalPrice, TotalDiscount, TotalPriceNetto, PriceNight, DiscountNight, PriceNightNetto);
  // <P align="right">� 123.000,00<br><U>- (10) � 12.300,00</U><br><B>� 11.000,00</B></P>
  if rri.TotalDiscountAmount <> 0 then
  begin
      if rri.IsPercentage then
      begin
        __hlblTotal.HTMLText.Text := format('<P align="right">%s<br><U>(%s) -%s</U><br><B>%s</B><br></P>',
              [
                TotalPrice.AsDisplayStringWithCode,
                GetTrimmedPercentage( (TotalDiscount / TotalPrice)*100) + '%',
                TotalDiscount.AsDisplayStringWithCode,
                TotalPriceNetto.AsDisplayStringWithCode
              ]);
        __hlblDaily.HTMLText.Text := format('<P align="right">%s<br><U>(%s) -%s</U><br><B>%s</B><br></P>',
              [
                PriceNight.AsDisplayStringWithCode,
                GetTrimmedPercentage((DiscountNight / PriceNight)*100) + '%',
                DiscountNight.AsDisplayStringWithCode,
                PriceNightNetto.AsDisplayStringWithCode
              ]);
      end else
      begin
        __hlblTotal.HTMLText.Text := format('<P align="right">%s<br><U>-%s</U><br><B>%s</B><br></P>',
              [
                TotalPrice.AsDisplayStringWithCode,
                TotalDiscount.AsDisplayStringWithCode,
                TotalPriceNetto.AsDisplayStringWithCode
              ]);
        __hlblDaily.HTMLText.Text := format('<P align="right">%s<br><U>-%s</U><br><B>%s</B><br></P>',
              [
                PriceNight.AsDisplayStringWithCode,
                DiscountNight.AsDisplayStringWithCode,
                PriceNightNetto.AsDisplayStringWithCode
              ]);
      end;
  end else
  begin
        __hlblTotal.HTMLText.Text := format('<P align="right"><B>%s</B><br></P>',
              [
                TotalPriceNetto.AsDisplayStringWithCode //trim(_floatToStr(TotalPriceNetto, 12, 2))
              ]);
        __hlblDaily.HTMLText.Text := format('<P align="right"><B>%s</B><br></P>',
              [
                PriceNightNetto.AsDisplayStringWithCode //trim(_floatToStr(PriceNightNetto, 12, 2))
              ]);
  end;

  if Trim(rri.Invoices) <> '' then
    clbRoomRentInvoice.Caption := GetTranslatedText('shUI_RoomInvoices') + ' ' + inttostr(rri.PaymentInvoice)
  else
    clbRoomRentInvoice.Caption := '';

  if rri.OngoingSale + rri.OngoingRent > 0 then
  begin
    sColor1 := '<BLINK><FONT color="#FF0000">';
    sColor2 := '</FONT></BLINK>';
  end else
  begin
    sColor1 := '';
    sColor2 := '';
  end;
  __hlblTotalInvoice.HTMLText.Text := format('<P align="right">%s<br>%s<br>%s<br><U>%s</U><br><B>%s %s%s</B><br></P>',
              [
                TAmount(rri.OngoingSale).AsDisplayStringWithCode,
                IIF(rri.GroupAccount, '<I>' + GetTranslatedText('shUI_OnGroupInvoice') + '</I>', TAmount(rri.OngoingTaxes).AsDisplayStringWithCode),
                IIF(rri.GroupAccount, '<I>' + GetTranslatedText('shUI_OnGroupInvoice') + '</I>', TAmount(rri.OngoingRent).AsDisplayStringWithCode),
                TAmount(rri.Payments).AsDisplayStringWithCode,
                sColor1,
                TAmount(rri.OngoingSale +
                        IIF(rri.GroupAccount, 0.00, rri.OngoingTaxes) +
                        IIF(rri.GroupAccount, 0.00, rri.OngoingRent) -
                        rri.Payments).AsDisplayStringWithCode,
                sColor2
              ]);

  if rri.Guarantee = 'CREDIT_CARD' then
  begin
    sColor1 := '<BLINK><FONT color="#0000FF">';
    sColor2 := '</FONT></BLINK>';
    temp := GetTranslatedText('shUI_CreditCardGuarantee');
  end else
  if rri.Guarantee = 'DOWN_PAYMENT' then
  begin
    sColor1 := '<BLINK><FONT color="#FF8000">';
    sColor2 := '</FONT></BLINK>';
    temp := GetTranslatedText('shUI_DownpaymentGuarantee');
  end else
  begin
    sColor1 := '<BLINK><FONT color="#FF0000">';
    sColor2 := '</FONT></BLINK>';
    temp := GetTranslatedText('shUI_NoGuarantee');
  end;

  hlbGuarantee.HtmlText.Text := format('<B>%s%s%s</B>', [sColor1, temp, sColor2]);

  __lbNotes.Text := rri.Information;
  __lbPAymentNotes.Text := rri.PMInfo;

  __labBlockNote.Caption := '';
  cbxBlocked.Checked := rri.BlockMove;
  cbxBlocked.Visible := rri.BlockMove;
  __labBlockNote.Visible := rri.BlockMove;
  if rri.BlockMove then
    __labBlockNote.Caption := rri.BlockMoveReason;

end;

procedure TFrmReservationHintHolder.PlaceHint(X, Y, CellWidth, CellHeight: Integer);
var currMousePos : TPoint;
    routeCounter : Integer;
begin
  currMousePos := GetCursorPosForControl(pnlHint.Parent);
  if currMousePos.X < 0 then
    exit;
  routeCounter := 0;
  while pnlHint.Top + pnlHint.Height > pnlHint.Parent.Height - 30 do
  begin
    inc(routeCounter);
    if routeCounter > 2048 then
      Break;
     pnlHint.Top := pnlHint.Top - 1;
  end;

  routeCounter := 0;
  while pnlHint.Top < 0 do
  begin
    inc(routeCounter);
    if routeCounter > 2048 then
      Break;
     pnlHint.Top := pnlHint.Top + 10;
  end;

  routeCounter := 0;
  while pnlHint.Left + pnlHint.Width > pnlHint.Parent.Width - 10 do
  begin
    inc(routeCounter);
    if routeCounter > 2048 then
      Break;
     pnlHint.Left := X - pnlHint.Width;
  end;

  routeCounter := 0;
  while pnlHint.Left < 0 do
  begin
    inc(routeCounter);
    if routeCounter > 2048 then
      Break;
     pnlHint.Left := pnlHint.Left + 10;
  end;

  if ((currMousePos.X >= pnlHint.Left) AND (currMousePos.X <= pnlHint.Left + pnlHint.Width)) OR
     (ABS((currMousePos.X - pnlHint.Left)) > pnlHint.Width) then
  begin
    if currMousePos.X + pnlHint.Width + 30 > pnlHint.Parent.Width then
      pnlHint.Left := currMousePos.X - pnlHint.Width - 30
    else
      pnlHint.Left := currMousePos.X + 30
  end;


end;

procedure TFrmReservationHintHolder.pnlHintMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  currentControl := Sender;
  if Button = mbLeft then
    timHide.Enabled := False;
end;

procedure TFrmReservationHintHolder.pnlHintMouseEnter(Sender: TObject);
begin
  CancelHint;
end;

procedure TFrmReservationHintHolder.pnlHintMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if Button = mbLeft then
    timHide.Enabled := True;
end;

procedure TFrmReservationHintHolder.PopupMenu1Popup(Sender: TObject);
begin
  timHide.Enabled := False;
end;

procedure TFrmReservationHintHolder.C1Click(Sender: TObject);
begin
  if currentControl = nil then exit;

  if currentControl IS THTMLabel then
    Clipboard.AsText:= THTMLabel(currentControl).Text
  else
  if currentControl IS TsLabel then
    Clipboard.AsText:= TsLabel(currentControl).Caption
  else
  if currentControl IS TsMemo then
    Clipboard.AsText:= TsMemo(currentControl).Text;

  if (currentControl IS THtmLabel) OR (currentControl IS TsMemo) OR (currentControl IS TsLabel) then
    MessageDlg(GetTranslatedText('shUI_ValueCopiedToClipboard'), mtConfirmation, [mbOk], 0);
end;

procedure TFrmReservationHintHolder.CancelHint;
begin
  if frmMain.HintWindowShowing then exit;
  pnlHint.Hide;
  timHide.Enabled := False;
  PopupMenu1.CloseMenu;
end;


procedure TFrmReservationHintHolder.CM_ExitMenuLoop(var msg: TMessage);
begin
  //
  timHide.Enabled := True;
end;

procedure TFrmReservationHintHolder.CM_MenuClosed(var msg: TMessage);
begin
  //
  timHide.Enabled := True;
end;

procedure TFrmReservationHintHolder.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(Self);
end;

procedure TFrmReservationHintHolder.InitEmbededHint(prnt: TWinControl);
begin
  pnlHint.Hide;
  pnlHint.Parent := prnt;
end;


procedure TFrmReservationHintHolder.timHideTimer(Sender: TObject);
begin
  CancelHint;
end;

end.
