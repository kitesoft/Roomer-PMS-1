unit uReservationStateChangeHandler;

interface

uses
    Classes
  , SysUtils
  , uReservationStateDefinitions
  , Generics.Collections
  , uRoomReservationObj
  ;


type
  EInvalidReservationStateChange = class(Exception)
  public
    constructor CreateForStates(aFromState, aToState: TReservationState); virtual;
  end;

  EInvalidRoomReservationStateChange = class(EInvalidReservationStateChange)
  public
    constructor CreateForStates(aFromState, aToState: TReservationState); override;
  end;

  EReservationHasUnPaidInvocieLines = class(Exception)
  public
    constructor Create(aReservation: integer); reintroduce;
  end;

  ERoomReservationHasUnPaidInvocieLines = class(Exception)
  public
    constructor Create(aRoomReservation: integer); reintroduce;
  end;

  /// <summary>
  ///   Function type to execute a specific state change on the item identified by aId.
  ///  Returns true if the statechange has been successfull
  /// </summary>
  TStateChangeHandlerFunc = reference to function(aReservationId: integer; aRoomReservationId: integer): boolean;

  TBaseReservationStateChangeHandler = class abstract(TObject)
  strict private
    FCurrentStateDirty: boolean;
  protected
    FReservation: integer;
    FRoomReservation: integer;
    FNewState : TReservationState;
    FCurrentState: TReservationState;
    function Checkin(aReservationId: integer; aRoomReservationId: integer): boolean; virtual; abstract;
    function CheckOut(aReservationId: integer; aRoomReservationId: integer): boolean; virtual; abstract;
    function Cancel(aReservationId: integer; aRoomReservationId: integer): boolean; virtual; abstract;
    function DispatchChangeHandler(aOldState, aNewState: TReservationState): TStateChangeHandlerFunc; virtual;
    function CatchAll(aReservationId: integer; aRoomReservationId: integer): boolean; virtual; abstract;
    function GetReservationState: TReservationState; virtual;
    procedure UpdateCurrentState; virtual; abstract;
    procedure AddChangeToUserActivityLog(aOldvalue, aNewValue: TReservationState); virtual; abstract;
    procedure SetCurrentStateDirty(const Value: boolean); virtual;
    property CurrentStateDirty: boolean read FCurrentStateDirty write SetCurrentStateDirty;
  public
    constructor Create;
    function ChangeIsAllowed(aNewState: TReservationState; aRaiseExceptionOnFail: boolean=false): boolean; virtual; abstract;
    function ChangeState(aNewState: TReservationState): boolean; overload; virtual;
    /// <summary>
    ///   Try to change the state to aNewState, using the provided aFunc handler functions. This bypasses the default DispatchChangeHandler;
    /// </summary>
    function ChangeState(aNewState: TReservationState; aHandler: TStateChangeHandlerFunc): boolean; overload; virtual;
    property CurrentState: TReservationState read GetReservationState;
  end;

  TRoomReservationStateChangeHandler = class(TBaseReservationStateChangeHandler)
  private
    function RoomReservationHasUnPaidInvoiceItems(aRoomReservation: integer): boolean;
  protected
    FRoom: string;
    function Checkin(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function CheckOut(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function Cancel(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function CatchAll(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    procedure UpdateCurrentState; override;
    procedure AddChangeToUserActivityLog(aOldvalue, aNewValue: TReservationState); override;
  public
    constructor Create(aReservation, aRoomReservation: integer); overload;
    constructor Create(aRoomresObj: TRoomReservationBasicObj); overload;
    function ChangeIsAllowed(aNewState: TReservationState; aRaiseExceptionOnFail: boolean=false): boolean; override;

    property Room: string read FRoom;
  end;

  TReservationStateChangeHandler = class(TBaseReservationStateChangeHandler)
  private
    FConfirmed : Boolean;
    FRoomStateChangers: TObjectDictionary<integer, TRoomReservationStateChangeHandler>;
    function GetRoomstateChangeHandler(aRoomRes: integer): TRoomReservationStateChangeHandler;
    procedure AddRoomResChangeSetHandlers;
    function ReservationHasUnPaidInvoiceItems(aReservation: integer): boolean;
  protected
    function Checkin(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function CheckOut(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function Cancel(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    function CatchAll(aReservationId: integer; aRoomReservationId: integer ): boolean; override;
    procedure UpdateCurrentState; override;
    procedure AddChangeToUserActivityLog(aOldValue, aNewValue: TReservationState); override;
    procedure SetCurrentStateDirty(const Value: boolean); override;
  public
    constructor Create(aReservation: integer); reintroduce;
    destructor Destroy; override;
    procedure AddRoomStateChangeHandler(aHandler: TRoomReservationStateChangeHandler);
    procedure UpdateRoomResStateChangeHandlers;
    procedure Clear;
    function ChangeState(aNewState: TReservationState): boolean; override;
    /// <summary>
    ///   For a full reservation the change is allowed if for at least one of the rooms the change is allowed
    ///  Unless the change is into Cancelled or Deleted then for all roomreservation it must be allowed to cancel / delete
    /// </summary>
    function ChangeIsAllowed(aNewState: TReservationState; aRaiseExceptionOnFail: boolean=false): boolean; override;
    property RoomStateChangeHandler[aRoomRes: integer]: TRoomReservationStateChangeHandler read GetRoomstateChangeHandler;
  end;


implementation

uses
  uD
  , hData
  , Dialogs
  , PrjConst
  , uAlerts
  , uGuestCheckinForm
  , UITypes
  , uFrmCheckOut
  , uProvideARoom2
  , uAppGlobal
  , uG
  , Windows
  , uActivityLogs
  , uUtils
  ,uFrmRoomReservationCancellationDialog
  ,uFrmReservationCancellationDialog
  ;

{ TReservationStateChangeHandler }

function TBaseReservationStateChangeHandler.ChangeState(aNewState: TReservationState; aHandler: TStateChangeHandlerFunc): boolean;
var
  lOldState: TReservationState;
begin
  result := false;
  FNewState := aNewState;
  lOldState := CurrentState;
  if ChangeIsAllowed(aNewState, true) then
  begin
    if Assigned(aHandler) and aHandler(FReservation, FRoomReservation) then
    begin
      AddChangeToUserActivityLog(lOldState, aNewState);
      Result := True;
    end;

    CurrentStateDirty := Result;
  end;
end;

function TBaseReservationStateChangeHandler.ChangeState(aNewState: TReservationState): boolean;
begin
  Result := ChangeState(aNewState, DispatchChangeHandler(CurrentState, aNewState));
end;

constructor TBaseReservationStateChangeHandler.Create;
begin
  FCurrentStateDirty := True;
end;

function TReservationStateChangeHandler.ChangeIsAllowed(aNewState: TReservationState; aRaiseExceptionOnFail: boolean=false): boolean;
var
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  // inherited; // no call to inherited!

  Result := True; // if no roomreservations present then its ok
  for lRoomHandler in FRoomStateChangers.Values do
  begin
    // WHen cancelling or deleting show exception if there are invoicelines unpaid
    Result := lRoomHandler.ChangeIsAllowed(aNewState, aRaiseExceptionOnFail and (aNewState in [rsCancelled, rsRemoved]));
    if (aNewState in [rsCancelled, rsRemoved]) xor Result then
      Break;
  end;

  if (aNewState in [rsCancelled, rsRemoved]) then
  begin
    Result := Result and not ReservationHasUnPaidInvoiceItems(FReservation);
    if not Result and aRaiseExceptionOnFail then
      raise EReservationHasUnPaidInvocieLines.Create(FReservation);
  end
  else if not Result and aRaiseExceptionOnFail then
    raise EInvalidReservationStateChange.CreateForStates(CurrentState, aNewState);

end;

function TReservationStateChangeHandler.Checkin(aReservationId: integer; aRoomReservationId: integer ): boolean;
var
  lRoom: string;
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  Result := false;
  if FRoomStateChangers.Count = 0 then
    Result := true
  else
  begin

    ShowAlertsForReservation(aReservationId, 0, atCHECK_IN);

    lRoom := FRoomStateChangers.Values.ToArray[0].Room;
    if FConfirmed OR (MessageDlg(Format(GetTranslatedText('shCheckInGroupOfRoom'), [lRoom]), mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
    begin

      for lRoomHandler in FRoomStateChangers.Values do
      begin
        if lRoomHandler.ChangeIsAllowed(rsGuests) then
        begin
          ShowAlertsForReservation(0, lRoomhandler.FRoomReservation, atCHECK_IN);
          lRoomHandler.CurrentStateDirty := True;
        end;
      end;
      d.CheckInReservation(aReservationId);

      g.updateCurrentGuestlist;
      Result := True;
    end;
  end;
end;

function TReservationStateChangeHandler.CheckOut(aReservationId: integer; aRoomReservationId: integer ): boolean;
var
  lRoom: string;
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  Result := false;
  if FRoomStateChangers.Count < 1 then
    Result := true
  else
  begin

    ShowAlertsForReservation(aReservationId, 0, atCHECK_OUT);

    lRoom := FRoomStateChangers.Values.ToArray[0].Room;
    if FConfirmed OR (MessageDlg(Format(GetTranslatedText('shCheckOutGroupOfRoom'), [lRoom]), mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
    begin
      FConfirmed := True;
      for lRoomHandler in FRoomStateChangers.Values do
      begin
        if lRoomHandler.ChangeIsAllowed(rsDeparted) then
        begin
          ShowAlertsForReservation(0, lRoomhandler.FRoomReservation, atCHECK_OUT);
          lRoomHandler.CurrentStateDirty := True;
        end;
      end;
      d.CheckOutReservation(aReservationId);
      g.updateCurrentGuestlist;
      Result := True;
    end;
  end;
end;

procedure TReservationStateChangeHandler.Clear;
begin
  FRoomStateChangers.Clear;
end;

constructor TReservationStateChangeHandler.Create(aReservation: integer);
begin
  inherited Create;
  FConfirmed := False;
  FReservation := aReservation;
  FConfirmed := False;
  FRoomStateChangers:= TObjectDictionary<integer, TRoomReservationStateChangeHandler>.Create([doOwnsValues]);
  AddRoomResChangeSetHandlers;
end;

procedure TReservationStateChangeHandler.AddChangeToUserActivityLog(aOldValue, aNewValue: TReservationState);
begin
  AddReservationActivityLog(g.qUser, FReservation, 0, CHANGE_ROOMRESERVATION_STATUS, aOldValue.AsReadableString, aNewValue.AsReadableString);
end;

procedure TReservationStateChangehandler.AddRoomResChangeSetHandlers;
var
  lRoomResList: TRoomResBasicObjList;
  lRoomresObj: TRoomReservationBasicObj;
begin
  lRoomResList := TRoomResBasicObjList.Create;
  try
    GetReservationRRList(FReservation, lRoomResList);
    for lRoomResObj in lRoomResList do
      AddRoomStateChangeHandler(TRoomReservationStateChangeHandler.Create(lRoomResObj));
  finally
    lRoomResList.Free;
  end;
end;

destructor TReservationStateChangeHandler.Destroy;
begin
  FRoomStateChangers.Free;
  inherited;
end;

procedure TReservationStateChangeHandler.UpdateCurrentState;
var
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  inherited;
  FCurrentState := rsUnKnown;
  for lRoomHandler in FRoomStateChangers.Values do
    if (FCurrentState = rsUnKnown) then
      FCurrentState := lRoomhandler.CurrentState
    else if (lRoomhandler.CurrentState <> FCurrentState ) then
    begin
      FCurrentState := rsMixed;
      Break;
    end;
end;

procedure TReservationStateChangeHandler.UpdateRoomResStateChangeHandlers;
begin
  FRoomStateChangers.Clear;
  AddRoomResChangeSetHandlers;
end;

function TReservationStateChangeHandler.GetRoomstateChangeHandler(aRoomRes: Integer): TRoomReservationStateChangeHandler;
begin
  Result := FRoomStateChangers.Items[aRoomRes];
end;

function TReservationStateChangeHandler.ReservationHasUnPaidInvoiceItems(aReservation: integer): boolean;
begin
  Result := UnpaidGroupInvoiceLineItems_exist(aReservation);
end;

procedure TReservationStateChangeHandler.SetCurrentStateDirty(const Value: boolean);
var
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  inherited;
  for lRoomHandler in FRoomStateChangers.Values do
    lRoomHandler.CurrentStateDirty := Value;
end;

function TRoomReservationStateChangeHandler.RoomReservationHasUnPaidInvoiceItems(aRoomReservation: integer): boolean;
begin
  Result := UnpaidInvoiceLineItems_exist(aRoomReservation);
end;

function TRoomReservationStateChangeHandler.ChangeIsAllowed(aNewState: TReservationState; aRaiseExceptionOnFail: boolean): boolean;
begin
  Result := CurrentState.CanChangeTo(aNewState);

  if Result and (aNewState in [rsCancelled, rsRemoved]) then
  begin
    Result := not RoomReservationHasUnPaidInvoiceItems(FRoomReservation);
    if not Result and aRaiseExceptionOnFail then
      raise ERoomReservationHasUnPaidInvocieLines.Create(FRoomReservation);
  end;

  if not Result and aRaiseExceptionOnFail then
    raise EInvalidRoomReservationStateChange.CreateForStates(CurrentState, aNewState);
end;

function TRoomReservationStateChangeHandler.Checkin(aReservationId: integer; aRoomReservationId: integer ): boolean;
begin
  Result := false;
  // Allocate room if needed
  if FRoom.StartsWith('<') then
    FRoom := ProvideARoom2(aRoomReservationId, False); // clean rooms only

  if FRoom = '' then
    Exit;

  // warn dirty room
  if g.qWarnCheckInDirtyRoom AND g.oRooms.Room[FRoom].IsDirty then
    if MessageDlg(Format(GetTranslatedText('shTx_Various_RoomNotClean'), [FRoom]), mtWarning, [mbYes, mbCancel], 0) <> mrYes then
      exit;

  if ctrlGetBoolean('CheckinWithDetailsDialog') OR
    (MessageDlg(Format(GetTranslatedText('shCheckRoom'), [FRoom]), mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  begin
    ShowAlertsForReservation(aReservationId, aRoomReservationId, atCHECK_IN);
    if (NOT ctrlGetBoolean('CheckinWithDetailsDialog')) OR OpenGuestCheckInForm(aRoomReservationId) then
    begin
      d.CheckInGuest(aRoomReservationId);
      g.updateCurrentGuestlist;
      Result := true;
    end;
  end;

end;

function TRoomReservationStateChangeHandler.CheckOut(aReservationId: integer; aRoomReservationId: integer ): boolean;
begin
  Result := false;
  if ctrlGetBoolean('CheckOutWithPaymentsDialog') OR
    (MessageDlg(Format(GetTranslatedText('shCheckOutSelectedRoom'), [FRoom]), mtConfirmation, [mbYes, mbNo], 0) = mrYes)
  then
  begin
    ShowAlertsForReservation(aReservationId, aRoomReservationId, atCHECK_OUT);
    if ctrlGetBoolean('CheckOutWithPaymentsDialog') then
      CheckoutGuestWithDialog(aReservationId, aRoomReservationId, FRoom)
    else
      d.CheckOutGuest(aRoomReservationId, FRoom);
    Result := True;
  end;
end;


constructor TRoomReservationStateChangeHandler.Create(aReservation, aRoomReservation: integer);
begin
  Create;
  FReservation := aReservation;
  FRoomReservation := aRoomReservation;
  FRoom := d.RR_GetRoomNr(FRoomReservation);
end;

constructor TRoomReservationStateChangeHandler.Create(aRoomresObj: TRoomReservationBasicObj);
begin
  Create;
  FReservation := aRoomResObj.Reservation;
  FRoomReservation := aRoomResObj.RoomReservation;
  FRoom := aRoomResObj.Room;
  FCurrentState := aRoomResObj.State;
  CurrentStateDirty := False;
end;


procedure TRoomReservationStateChangeHandler.UpdateCurrentState;
begin
  inherited;
  FCurrentState := TReservationState.FromResStatus( d.RR_GetStatus(FRoomReservation));
  CurrentStateDirty := False;
end;

function TBaseReservationStateChangeHandler.DispatchChangeHandler(aOldState,
  aNewState: TReservationState): TStateChangeHandlerFunc;
begin
  Result := nil;
  case aNewState of
    rsGuests:     Result := Checkin;
    rsDeparted:   Result := Checkout;
    rsCancelled:  Result := Cancel;
  else
    Result := Catchall;
  end;
end;

function TBaseReservationStateChangeHandler.GetReservationState: TReservationState;
begin
  if CurrentStateDirty then
    UpdateCurrentState;

  Result := FCurrentState;
end;

procedure TBaseReservationStateChangeHandler.SetCurrentStateDirty(const Value: boolean);
begin
  FCurrentStateDirty := Value;
end;

procedure TReservationStateChangeHandler.AddRoomStateChangeHandler(aHandler: TRoomReservationStateChangeHandler);
begin
  FRoomStateChangers.AddOrSetValue(aHandler.FRoomReservation, aHandler);
end;

function TReservationStateChangeHandler.Cancel(aReservationId, aRoomReservationId: integer): boolean;
begin
  result := TfrmReservationCancellationDialog.CancelBookingDialog(aReservationId);
end;

function TReservationStateChangeHandler.Catchall(aReservationId: integer; aRoomReservationId: integer ): boolean;
var
  lRoomHandler: TRoomReservationStateChangeHandler;
begin
  Result := False;
  if MessageDlg(Format(GetTranslatedtext('shChangeStateOfFullReservation'), [aReservationId, FNewState.AsReadableString]), mtConfirmation, mbOKCancel, 0) = mrOK then
  begin
     d.roomerMaindataset.SystemSetRoomStatusOfReservation(aReservationId, FNewstate.AsStatusChar);
     for lRoomHandler in FRoomStateChangers.Values do
        lRoomHandler.CurrentStateDirty := True;
     Result := True;
  end;
end;

function TReservationStateChangeHandler.ChangeState(aNewState: TReservationState): boolean;
begin
  FConfirmed := False;
  Result := inherited;
end;


procedure TRoomReservationStateChangeHandler.AddChangeToUserActivityLog(aOldvalue, aNewValue: TReservationState);
begin
  AddReservationActivityLog(g.qUser, FReservation, FRoomReservation, CHANGE_ROOMRESERVATION_STATUS, aOldValue.AsReadableString, aNewValue.AsReadableString);
end;

function TRoomReservationStateChangeHandler.Cancel(aReservationId, aRoomReservationId: integer): boolean;
begin
  result := TFrmRoomReservationCancellationDialog.CancelRoomBookingDialog(aRoomReservationId);
end;

function TRoomreservationStateChangeHandler.Catchall(aReservationId: integer; aRoomReservationId: integer ): boolean;
begin
  Result := False;
  if ChangeIsAllowed(FNewState) then
  begin
    d.UpdateStatusSimple(aReservationId, aRoomReservationId, FNewState.AsStatusChar);
    Result := True;
  end;
end;

{ EInvalidReservationStateChange }

constructor EInvalidReservationStateChange.CreateForStates(aFromState, aToState: TReservationState);
begin
  inherited CreateFmt(GetTranslatedtext('shTx_G_ResStateChangeNotAllowed'), [aFromState.AsReadableString, aToState.AsReadableString]);
end;

{ EInvalidRoomReservationStateChange }

constructor EInvalidRoomReservationStateChange.CreateForStates(aFromState, aToState: TReservationState);
begin
  inherited CreateFmt(GetTranslatedtext('shTx_G_RoomResStateChangeNotAllowed'), [aFromState.AsReadableString, aToState.AsReadableString]);
end;

{ ERoomReservationHasUnPaidInvocieLines }

constructor ERoomReservationHasUnPaidInvocieLines.Create(aRoomReservation: integer);
begin
  inherited CreateFmt(GetTranslatedtext('shTx_G_RoomResStateChangeNotAllowedOpenInvoice'), [aRoomReservation]);
end;

{ EReservationHasUnPaidInvocieLines }

constructor EReservationHasUnPaidInvocieLines.Create(aReservation: integer);
begin
  inherited CreateFmt(GetTranslatedtext('shTx_G_ResStateChangeNotAllowedOpenInvoice'), [aReservation]);
end;

end.
