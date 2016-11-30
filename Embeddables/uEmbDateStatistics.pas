unit uEmbDateStatistics;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sLabel, Vcl.Grids, AdvObj, BaseGrid, AdvGrid, VCLTee.TeEngine,
  VCLTee.Series, VCLTee.TeeProcs, VCLTee.Chart, Vcl.ExtCtrls, sPanel, Vcl.Menus
  , Generics.Collections, AdvUtil
  ;

type

  TRoomAvailabilityEntity = class
  private
    FRoom: String;
    FRoomType: STring;
    FRoomClass: String;
  public
    constructor Create(const Room, RoomType, RoomClass: String);

    property Room: String read FRoom;
    property RoomType: String read FRoomType;
    property RoomClass: String read FRoomClass;
  end;

  TRoomAvailabilityEntityList = TObjectList<TRoomAvailabilityEntity>;

  TRoomClassChannelAvailabilityContainer = class
  public
    RoomTypeGroup: String;
    NumRooms: integer;
    Reserved: integer;
    ChannelAvailable: integer;
    ChannelMaxAvailable: integer;
    GridIndex: integer;
    AnyStop: boolean;

    constructor Create(const _RoomTypeGroup: String; _NumRooms: integer; _Reserved: integer; _ChannelAvailable: integer;
      _ChannelMaxAvailable: integer;
      _GridIndex: integer; _AnyStop: boolean);
  end;

  TRoomClassChannelAvailabilityContainerList = TObjectList<TRoomClassChannelAvailabilityContainer>;


  TfrmEmbDateStatistics = class(TForm)
    pnlStatistics: TsPanel;
    chrtRoomStats: TChart;
    Series1: TBarSeries;
    grdRoomClasses: TAdvStringGrid;
    grdRoomStatusses: TAdvStringGrid;
    lblPropertyStatus: TsLabel;
    lblDateStatistics: TsLabel;
    pmnuChannelSettings: TPopupMenu;
    N01: TMenuItem;
    timGetRoomStatuses: TTimer;
    pgrStatisticsPanelGroup: TCategoryPanelGroup;
    cpnlRoomClasses: TCategoryPanel;
    cpnlChart: TCategoryPanel;
    cpnlRoomtypes: TCategoryPanel;
    procedure grdRoomClassesCanEditCell(Sender: TObject; ARow, ACol: integer; var CanEdit: boolean);
    procedure grdRoomClassesCellValidate(Sender: TObject; ACol, ARow: integer; var Value: string; var Valid: boolean);
    procedure grdRoomClassesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect; State: TGridDrawState);
    procedure grdRoomClassesGetCellBorder(Sender: TObject; ARow, ACol: integer; APen: TPen; var Borders: TCellBorders);
    procedure grdRoomClassesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure grdRoomClassesMouseMove(Sender: TObject; Shift: TShiftState; X, Y: integer);
    procedure grdRoomStatussesGetAlignment(Sender: TObject; ARow, ACol: integer; var HAlign: TAlignment;
      var VAlign: TVAlignment);
    procedure timGetRoomStatusesTimer(Sender: TObject);
    procedure grdResize(Sender: TObject);
  private
    availListContainer: TRoomClassChannelAvailabilityContainerList;
    FDate: TDate;
    iLastHintRow: integer;
    iLastHintCol: integer;
    zHintPoint: TPoint;
    zHintComp: TWinControl;
    procedure FillRoomTypesGrid;
    function CountRoomsOfSpecificType(const RoomType: String): integer;
    function GetShowChart: boolean;
    procedure SetShowChart(const Value: boolean);
    procedure DisplayRoomStatusses;
    function AnyCheckedStopItems: boolean;
    procedure PopulateChannelStopMenu;
    procedure SelectStopChannel(Sender: TObject);
    function GetDate: TDate;
    procedure SetDate(const Value: TDate);
    function GetAvailableCellText(Value: integer): String;
    function RoomTypeIndexInGrid(Grid: TAdvStringGrid; const RoomType: String): integer;
    procedure PlaceMouseClickToCell(Sender: TObject; X, Y: integer);
    procedure ActivateHint(HintPoint: TPoint; comp: TWinControl);
    { Private declarations }
  public
    constructor Create(aOwner: TCOmponent); override;
    destructor Destroy; override;

    procedure Refresh;
    { Public declarations }
    property ShowChart: boolean read GetShowChart write SetShowChart;
    property Date: TDate read GetDate write SetDate;
  end;

var
  frmEmbDateStatistics: TfrmEmbDateStatistics;

implementation

uses
  cmpRoomerDataset
  , PrjConst
  , uAppGlobal
  , uD
  , uDateUtils
  , uMain  // todo: refactor this dependency
  , Data.DB
  , uActivityLogs, hData, uDayNotes, uUtils;


{$R *.dfm}

const
  DEFAULT_UNPARSABLE_INT_VALUE: integer = -99999;



{ TRoomClassChannelAvailabilityContainer }

constructor TRoomClassChannelAvailabilityContainer.Create(const _RoomTypeGroup: String;
  _NumRooms, _Reserved, _ChannelAvailable, _ChannelMaxAvailable,
  _GridIndex: integer; _AnyStop: boolean);
begin
  RoomTypeGroup := _RoomTypeGroup;
  NumRooms := _NumRooms;
  Reserved := _Reserved;
  ChannelAvailable := _ChannelAvailable;
  ChannelMaxAvailable := _ChannelMaxAvailable;
  GridIndex := _GridIndex;
  AnyStop := _AnyStop;
end;

{ TRoomAvailabilityEntity }

constructor TRoomAvailabilityEntity.Create(const Room, RoomType, RoomClass: String);
begin
  FRoom := Room;
  FRoomType := RoomType;
  FRoomClass := RoomClass;
end;


procedure TfrmEmbDateStatistics.FillRoomTypesGrid;
 var
   rSet: TRoomerDataSet;
   idx: integer;
 begin
   availListContainer.Clear;
   grdRoomStatusses.ColCount := 3;
   grdRoomStatusses.RowCount := 2;
   grdRoomStatusses.cells[0, 0] := GetTranslatedText('shType');
   grdRoomStatusses.cells[1, 0] := GetTranslatedText('shRooms');
   grdRoomStatusses.cells[2, 0] := GetTranslatedText('shTx_Available');
   glb.RoomTypesSet.first;
   while not glb.RoomTypesSet.eof do
   begin
     if glb.RoomTypesSet['Active'] then
     begin
       grdRoomStatusses.cells[0, grdRoomStatusses.RowCount - 1] := glb.RoomTypesSet['RoomType'];
       grdRoomStatusses.cells[1, grdRoomStatusses.RowCount - 1] :=
         inttostr(CountRoomsOfSpecificType(glb.RoomTypesSet['RoomType']));
       grdRoomStatusses.RowCount := grdRoomStatusses.RowCount + 1;
     end;
     glb.RoomTypesSet.next;
   end;
   grdRoomStatusses.RowCount := grdRoomStatusses.RowCount - 1;
   grdRoomStatusses.Height := grdRoomStatusses.DefaultRowHeight * grdRoomStatusses.RowCount;

   if d.roomerMainDataSet.OffLineMode then
     exit;

   rSet := d.roomerMainDataSet.ActivateNewDataset
     (d.roomerMainDataSet.SystemFreeQuery(Format('SELECT rtg.Code, ' +
     '(SELECT COUNT(r.Room) FROM rooms r, roomtypes rt WHERE r.Active AND r.WildCard=0 AND r.RoomType=rt.RoomType AND rt.RoomTypeGroup=rtg.Code) AS NumRooms, '
     +
     '(SELECT availability FROM channelratesavailabilities WHERE date=_params._date AND roomClassId=rtg.id LIMIT 1) AS ChannelAvailable '
     +
     'FROM roomtypegroups rtg, ' + '     (SELECT ''%s'' AS _date) AS _params ' + 'WHERE active=1 ' +
     // '-- AND (SELECT COUNT(r.Room) FROM rooms r, roomtypes rt WHERE r.RoomType=rt.RoomType AND rt.RoomTypeGroup=rtg.Code) > 0 ' +
     'ORDER BY rtg.Code', [uDateUtils.dateToSqlString(FDate)])));
   try
     grdRoomClasses.ColCount := 4;
     grdRoomClasses.RowCount := 2;
     grdRoomClasses.cells[0, 0] := GetTranslatedText('shTx_Class');
     grdRoomClasses.cells[1, 0] := GetTranslatedText('shRooms');
     grdRoomClasses.cells[2, 0] := GetTranslatedText('shTx_Available');
     grdRoomClasses.cells[3, 0] := GetTranslatedText('shTx_ChannelAvailable');
     rSet.first;
     while not rSet.eof do
     begin
       if rSet['NumRooms'] > 0 then
       begin
         idx := grdRoomClasses.RowCount - 1;
         grdRoomClasses.cells[0, idx] := rSet['Code'];
         grdRoomClasses.cells[1, idx] := rSet['NumRooms'];
         grdRoomClasses.cells[2, idx] := '0';
         grdRoomClasses.cells[3, idx] := rSet['ChannelAvailable'];
         grdRoomClasses.Objects[3, idx] := Pointer(1);
         availListContainer.Add(TRoomClassChannelAvailabilityContainer.Create(rSet['Code'], rSet['NumRooms'], 0, 0, 0,
           idx, false));

         grdRoomClasses.RowCount := grdRoomClasses.RowCount + 1;
       end;
       rSet.next;
     end;
     grdRoomClasses.RowCount := grdRoomClasses.RowCount - 1;
     grdRoomClasses.Height := grdRoomClasses.DefaultRowHeight * grdRoomClasses.RowCount;
   finally
     freeandNil(rSet);
   end;
 end;



function TfrmEmbDateStatistics.GetDate: TDate;
begin
  Result := FDate;
end;

function TfrmEmbDateStatistics.GetShowChart: boolean;
begin
  Result := chrtRoomStats.Visible;
end;

procedure TfrmEmbDateStatistics.Refresh;
begin
  chrtRoomStats.Color := frmMain.sSkinManager1.GetGlobalColor;
  chrtRoomStats.LeftAxis.LabelsFont.Color := frmMain.sSkinManager1.GetGlobalFontColor;
  chrtRoomStats.BottomAxis.LabelsFont.Color := frmMain.sSkinManager1.GetGlobalFontColor;
  chrtRoomStats.Title.Font.Color := frmMain.sSkinManager1.GetHighLightFontColor;

  grdRoomStatusses.DefaultColWidth := (grdRoomStatusses.ClientWidth) div grdRoomStatusses.ColCount;
  grdRoomClasses.DefaultColWidth := (grdRoomClasses.ClientWidth) div grdRoomClasses.ColCount;

  lblDateStatistics.Caption := DateToStr(FDate) + ' ' + FormatDateTime('dddd', FDate);

  chrtRoomStats.Series[0].Clear;
  chrtRoomStats.Series[0].Add(frmMain.statNumRooms, GetTranslatedText('shMainFormStatisticsRooms'), clBlue);
  chrtRoomStats.Series[0].Add(frmMain.statTaken, GetTranslatedText('shTx_Taken'), clMaroon);
  chrtRoomStats.Series[0].Add(frmMain.statNumExternRooms, GetTranslatedText('shTx_NoRm'), clYellow);
  chrtRoomStats.Series[0].Add(frmMain.statNumRooms - frmMain.statTaken, GetTranslatedText('shTx_Free'), clGreen);
  chrtRoomStats.Series[0].Add(frmMain.statNumRooms - frmMain.statNumExternRooms - frmMain.statTaken, GetTranslatedText('shTx_Netto'), clRed);
  chrtRoomStats.Series[0].Add(frmMain.statCancelledExt + frmMain.statCancelledRm, GetTranslatedText('shTx_Cancelled'), clBlack);

  FillRoomTypesGrid;
  DisplayRoomStatusses;

end;

procedure TfrmEmbDateStatistics.SetDate(const Value: TDate);
begin
  FDate := Value;
  if ComponentRunning(Self) then
    Refresh;
end;

procedure TfrmEmbDateStatistics.SetShowChart(const Value: boolean);
begin
  chrtRoomStats.Visible := Value;
end;

function TfrmEmbDateStatistics.CountRoomsOfSpecificType(const RoomType: String): integer;
begin
  result := 0;
  glb.RoomsSet.first;
  while NOT glb.RoomsSet.eof do
  begin
    if (glb.RoomsSet['RoomType'] = RoomType) AND (glb.RoomsSet['Active']) AND (NOT glb.RoomsSet['Hidden']) then
      inc(result);
    glb.RoomsSet.next;
  end;
end;

constructor TfrmEmbDateStatistics.Create(aOwner: TCOmponent);
begin
  inherited;
  availListContainer := TRoomClassChannelAvailabilityContainerList.Create(true);

end;

function TfrmEmbDateStatistics.GetAvailableCellText(Value: integer): String;
var
  sColor, sText: String;
begin
  sText := inttostr(Value);
  if Value < 0 then
    sColor := '#FF0000'
  else if Value = 0 then
    sColor := '#000000'
  else
    sColor := '#0000FF';
  result := Format('<p align="right"><font color="%s" size="7"><b>%s</b></font></p>', [sColor, sText]);
end;


destructor TfrmEmbDateStatistics.Destroy;
begin
  availListContainer.Free;
  inherited;
end;

function TfrmEmbDateStatistics.RoomTypeIndexInGrid(Grid: TAdvStringGrid; const RoomType: String): integer;
var
  i: integer;
begin
  result := -1;
  for i := 0 to Grid.RowCount - 1 do
    if Grid.cells[0, i] = RoomType then
    begin
      result := i;
      break;
    end;
end;


procedure TfrmEmbDateStatistics.DisplayRoomStatusses;
var
  rSet: TRoomerDataSet;
  i, idx: integer;
  sText: String;
  StatusCont: TRoomClassChannelAvailabilityContainer;
  ChAvail, chAvailMax: integer;
  AnyStop: boolean;

  dcField: TField;
begin
  try
    dcField := nil;

    if d.roomerMainDataSet.OffLineMode then
      exit;

    grdRoomClasses.BeginUpdate;
    grdRoomStatusses.BeginUpdate;
    try
      grdRoomStatusses.DefaultColWidth := grdRoomStatusses.ClientWidth div grdRoomStatusses.ColCount;
      grdRoomClasses.DefaultColWidth := grdRoomClasses.ClientWidth div grdRoomClasses.ColCount;

      rSet := d.roomerMainDataSet.ActivateNewDataset(d.roomerMainDataSet.SystemGetRoomTypeStatus(Date, Date));
      try
        rSet.first;
        for i := 1 to grdRoomStatusses.RowCount - 1 do
          grdRoomStatusses.cells[2, i] := GetAvailableCellText(StrToInt(grdRoomStatusses.cells[1, i]));

        for i := 1 to grdRoomClasses.RowCount - 1 do
        begin
          grdRoomClasses.cells[2, i] := grdRoomClasses.cells[1, i];
          grdRoomClasses.cells[3, i] := inttostr(DEFAULT_UNPARSABLE_INT_VALUE);
          StatusCont := availListContainer[i - 1];
          StatusCont.Reserved := 0;
        end;

        while not rSet.eof do
        begin
          idx := RoomTypeIndexInGrid(grdRoomStatusses, rSet['RoomType']);
          if idx >= 0 then
          begin
            sText := inttostr(StrToInt(grdRoomStatusses.cells[1, idx]) - rSet['Reserved']);
            grdRoomStatusses.cells[2, idx] := sText;
          end;
          idx := RoomTypeIndexInGrid(grdRoomClasses, rSet['RoomTypeGroup']);
          if idx >= 0 then
          begin
            AnyStop := false;
            ChAvail := rSet['ChannelAvailable'];

            chAvailMax := rSet['ChannelMaxAvailable'];
            if rSet.Fields.FindField('anyStop') <> nil then
              AnyStop := rSet['anyStop'];
            StatusCont := availListContainer[idx - 1];
            // TRoomClassChannelAvailabilityContainer(grdRoomClasses.Objects[3, idx]);
            StatusCont.Reserved := StatusCont.Reserved + rSet['Reserved'];
            StatusCont.ChannelAvailable := ChAvail;
            StatusCont.ChannelMaxAvailable := chAvailMax;
            StatusCont.AnyStop := AnyStop;

            if (NOT assigned(dcField)) then
              grdRoomClasses.Objects[3, idx] := Pointer(1)
            else if rSet['directConnection'] then
              grdRoomClasses.Objects[3, idx] := Pointer(2)
            else
              grdRoomClasses.Objects[3, idx] := Pointer(1);

            sText := inttostr(StatusCont.NumRooms - StatusCont.Reserved);
            grdRoomClasses.cells[2, idx] := sText;
            sText := inttostr(StatusCont.ChannelAvailable);
            grdRoomClasses.cells[3, idx] := sText;
          end;
          rSet.next;
        end;
      finally
        freeandNil(rSet);
      end;
    finally
      grdRoomClasses.endUpdate;
      grdRoomStatusses.endUpdate;
    end;
  finally
    grdRoomClasses.Invalidate;
  end;
end;

procedure TfrmEmbDateStatistics.grdRoomClassesCanEditCell(Sender: TObject; ARow, ACol: integer; var CanEdit: boolean);
begin
  CanEdit := (ACol = 3) AND (ARow > 0) AND (grdRoomClasses.cells[ACol, ARow] <> inttostr(DEFAULT_UNPARSABLE_INT_VALUE));
end;


procedure TfrmEmbDateStatistics.grdRoomClassesCellValidate(Sender: TObject; ACol, ARow: integer; var Value: string;
  var Valid: boolean);
var
  iValue: integer;
  StatusCont: TRoomClassChannelAvailabilityContainer;
  temp: String;
begin
  //
  StatusCont := availListContainer[ARow - 1];
  iValue := strtointDef(Value, DEFAULT_UNPARSABLE_INT_VALUE);
  if iValue = DEFAULT_UNPARSABLE_INT_VALUE then
  begin
    if ANSIUpperCase(Copy(Value, 1, 1)) = 'M' then
    begin
      iValue := strtointDef(Copy(Value, 2, maxint), DEFAULT_UNPARSABLE_INT_VALUE);
      if iValue < -1 then
        raise Exception.Create(GetTranslatedText('shTx_FrmMain_WrongValueEntered'));
      temp := Format
        ('(grdRoomClassesCellValidate 1) Manual change of MAX availability for RoomClass=%s, SetMaxAvailability=%d, Date=%s',
        [grdRoomClasses.cells[0, ARow], iValue, dateToSqlString(FDate)]);
      d.roomerMainDataSet.SystemSetChannelAvailability(uDateUtils.dateToSqlString(FDate),
        grdRoomClasses.cells[0, ARow], 1, -2, iValue, -1, -1, temp);
      StatusCont.ChannelMaxAvailable := iValue;

      timGetRoomStatuses.Enabled := true;

//      ShowTimelyMessage(Format(GetTranslatedText('shTx_FrmMain_ChannelChangedMaxAvail'), [grdRoomClasses.cells[0, ARow],
//        iValue]));
      exit;
    end
    else
    begin
      Valid := false;
      raise Exception.Create(GetTranslatedText('shTx_FrmMain_WrongValueEntered'));
    end;
  end;
  if iValue < -1 then
    raise Exception.Create(GetTranslatedText('shTx_FrmMain_WrongValueEntered'));

  temp := Format
    ('(grdRoomClassesCellValidate 2) Manual change of availability for RoomClass=%s, SetAvailability=%d, Date=%s',
    [grdRoomClasses.cells[0, ARow], iValue, dateToSqlString(FDate)]);

  d.roomerMainDataSet.SystemSetChannelAvailability(uDateUtils.dateToSqlString(FDate), grdRoomClasses.cells[0, ARow], 1, iValue, -1, -1, -1, temp);

  AddAvailabilityActivityLog(d.roomerMainDataSet.userName, EDIT, grdRoomClasses.cells[0, ARow], iValue,  FDate, 'Edited in' + Classname);

//    ShowTimelyMessage(Format(GetTranslatedText('shTx_FrmMain_ChannelChangedAvail'), [grdRoomClasses.cells[0, ARow], iValue]));
  StatusCont.ChannelAvailable := iValue;
  grdRoomClasses.Invalidate;
end;

procedure TfrmEmbDateStatistics.grdRoomClassesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect; State: TGridDrawState);
var
  Text: String;
  dx: integer;
  iValue: integer;
  StatusCont: TRoomClassChannelAvailabilityContainer;
begin
//  if FAppClosing then
//    exit;
  Text := grdRoomClasses.cells[ACol, ARow];
  if (ACol = 3) AND (ARow > 0) then
  begin
    try
      if ARow - 1 < availListContainer.Count then
      begin
        StatusCont := availListContainer[ARow - 1];
        with grdRoomClasses.Canvas do
        begin
          Brush.Color := frmMain.sSkinManager1.GetGlobalColor; // clWhite; // $00EAEAEA;
          Font.Style := [fsBold];
          iValue := strtointDef(Text, DEFAULT_UNPARSABLE_INT_VALUE);
          if iValue > 0 then
            Font.Color := clBlue
          else if iValue = 0 then
            Font.Color := $000080FF // Orange
          else if iValue = DEFAULT_UNPARSABLE_INT_VALUE then
          begin
            Font.Color := clBlack;
            Brush.Color := $00EAEAEA;
            Text := 'n/a';
          end
          else
            Font.Color := frmMain.sSkinManager1.GetGlobalFontColor; // clBlue;
          if (iValue > 0) AND (StrToInt(grdRoomClasses.cells[2, ARow]) - iValue < 0) then
          begin
            Font.Color := clWhite;
            Brush.Color := $000080FF;
            Font.Style := [fsBold, fsItalic];
          end;
          Font.size := 7;
          FillRect(Rect);
          if iValue = -1 then
            Text := 'auto'
          else if iValue <> DEFAULT_UNPARSABLE_INT_VALUE then
            Text := Format('%d/%d', [StatusCont.ChannelAvailable, StatusCont.ChannelMaxAvailable]);
          dx := TextWidth(Text) + 2;
          TextOut(Rect.Right - dx, Rect.Top, Text);
        end;
      end;
    except
    end;
  end
  else if (ACol = 2) AND (ARow > 0) then
  begin
    with grdRoomClasses.Canvas do
    begin
      iValue := strtointDef(Text, DEFAULT_UNPARSABLE_INT_VALUE);
      Brush.Color := frmMain.sSkinManager1.GetGlobalColor; // $00EAEAEA;
      if iValue > 0 then
        Font.Color := frmMain.sSkinManager1.GetGlobalFontColor // clBlue
      else if iValue = 0 then
        Font.Color := frmMain.sSkinManager1.GetGlobalFontColor // clBlack
      else
      begin
        Font.Color := clRed;
        Brush.Color := clWhite
      end;
      Font.Style := [fsBold];
      Font.size := 7;
      FillRect(Rect);
      dx := TextWidth(Text) + 2;
      TextOut(Rect.Right - dx, Rect.Top, Text);
    end;
  end;
  if (ACol = 1) AND (ARow > 0) then
  begin
    with grdRoomClasses.Canvas do
    begin
      Brush.Color := frmMain.sSkinManager1.GetGlobalColor; // $00EAEAEA;
      Font.Color := frmMain.sSkinManager1.GetGlobalFontColor; // clBlack;
      Font.Style := [];
      Font.size := 7;
      FillRect(Rect);
      dx := TextWidth(Text) + 2;
      TextOut(Rect.Right - dx, Rect.Top, Text);
    end;
  end;
end;

procedure TfrmEmbDateStatistics.grdRoomClassesGetCellBorder(Sender: TObject; ARow, ACol: integer; APen: TPen;
  var Borders: TCellBorders);
var
  iValue: integer;
  StatusCont: TRoomClassChannelAvailabilityContainer;
begin
//  if FAppClosing then
//    exit;

  if (ARow > 0) AND (ACol = 3) then
  begin
    if (ARow < grdRoomClasses.RowCount) AND (ACol < grdRoomClasses.ColCount) then
      try
        iValue := strtointDef(grdRoomClasses.cells[3, ARow], DEFAULT_UNPARSABLE_INT_VALUE);
        if iValue <> DEFAULT_UNPARSABLE_INT_VALUE then
          if ARow - 1 < availListContainer.Count then
          begin
            StatusCont := availListContainer[ARow - 1];
            // TRoomClassChannelAvailabilityContainer(grdRoomClasses.Objects[3, aRow]);
            if StatusCont.AnyStop then
            begin
              APen.Color := clRed;
              APen.Width := 4;
              Borders := [cbTop, cbLeft, cbRight, cbBottom];
            end;
          end;
      except
      end;
  end;
end;

procedure TfrmEmbDateStatistics.PlaceMouseClickToCell(Sender: TObject; X, Y: integer);
var
  ACol: integer;
  ARow: integer;
begin
  TAdvStringGrid(Sender).MouseToCell(X, Y, ACol, ARow);
  TAdvStringGrid(Sender).col := ACol;
  TAdvStringGrid(Sender).row := ARow;
end;

procedure TfrmEmbDateStatistics.grdRoomClassesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
var
  PpUp: TPoint;
begin
//  if FAppClosing then
//    exit;
  PlaceMouseClickToCell(Sender, X, Y);
  if Button = mbRight then
  begin
    PpUp.X := X;
    PpUp.Y := Y;
    PpUp := grdRoomClasses.ClientToScreen(PpUp);
    PopulateChannelStopMenu;
    pmnuChannelSettings.Popup(PpUp.X, PpUp.Y);
  end;
end;

procedure TfrmEmbDateStatistics.grdRoomClassesMouseMove(Sender: TObject; Shift: TShiftState; X, Y: integer);
var
  Text: String;
  ARow, ACol, iValue: integer;
  APoint: TPoint;
  StatusCont: TRoomClassChannelAvailabilityContainer;
  availColor, maxColor, HintStr: String;
begin
//  if FAppClosing then
//    exit;
  grdRoomClasses.MouseToCell(X, Y, ACol, ARow);
  Application.ProcessMessages;
  if (iLastHintRow = ARow) and (iLastHintCol = ACol) then
    exit;

  if (ACol = 3) AND (ARow > 0) then
  begin
    StatusCont := availListContainer[ARow - 1];
    // TRoomClassChannelAvailabilityContainer(grdRoomClasses.Objects[3, aRow]);
    // ATitle := GetTranslatedText('shTx_FrmMain_Explanation');
    Text := TAdvStringGrid(Sender).cells[ACol, ARow];
    // AIcon := ORD(biInfo);
    maxColor := '#0000ff';
    if StatusCont.ChannelMaxAvailable < 1 then
      maxColor := '#ff0000';

    HintStr := GetTranslatedText('shTx_FrmMain_ChannelAvailabilityClassesHintHeader');
    iValue := strtointDef(Text, DEFAULT_UNPARSABLE_INT_VALUE);
    availColor := '#0000ff';
    if iValue < 1 then
      availColor := '#ff0000';

    if ((iValue > 0) AND (StrToInt(grdRoomClasses.cells[2, ARow]) - iValue < 0)) then
      HintStr := HintStr + GetTranslatedText('shTx_FrmMain_WarningIncorrectAvailability')
    else if iValue >= 0 then
      HintStr := HintStr + Format(GetTranslatedText('shTx_FrmMain_RoomsAvailableFromChannels'), [availColor, iValue]) +
        Format(GetTranslatedText('shTx_FrmMain_ChannelMaxAvailability'), [maxColor, StatusCont.ChannelMaxAvailable])
      // else
      // if iValue = 0 then
      // HintStr := HintStr + GetTranslatedText('shTx_FrmMain_NoRoomsAvailableFromChannels') +
      // format(GetTranslatedText('shTx_FrmMain_ChannelMaxAvailability'), [maxColor, statusCont.ChannelMaxAvailable])
    else if iValue = DEFAULT_UNPARSABLE_INT_VALUE then
      HintStr := GetTranslatedText('shTx_FrmMain_RoomClassNotAvailableOnChannels')
    else
      HintStr := GetTranslatedText('shTx_FrmMain_AutoAvailabilityOnChannels');

    if StatusCont.AnyStop then
      HintStr := HintStr + '<hr>' + GetTranslatedText('shTx_FrmMain_StopSaleActiveOnOneOrMoreChannels');

    HintStr := '<font size="10">' + HintStr + '</font>';

    grdRoomClasses.Hint := HintStr;
    APoint.X := X;
    APoint.Y := Y;
    APoint := grdRoomClasses.ClientToScreen(APoint);
    ActivateHint(APoint, grdRoomClasses);

    iLastHintRow := ARow;
    iLastHintCol := ACol;

  end;
end;

procedure TfrmEmbDateStatistics.grdRoomStatussesGetAlignment(Sender: TObject; ARow, ACol: integer; var HAlign: TAlignment;
  var VAlign: TVAlignment);
begin
//  if FAppClosing then
//    exit;
  if (ACol IN [1, 2, 3]) then
    HAlign := taRightJustify
  else if (ACol = 0) AND (ARow > 0) then
    HAlign := taRightJustify
  else if (ACol = 0) AND (ARow = 0) then
    HAlign := taCenter;
end;

procedure TfrmEmbDateStatistics.grdResize(Sender: TObject);
var
  lCatPanel: TCategoryPanel;
begin
  lCatPanel := TCategoryPanel(TWinControl(Sender).Parent);
  if not lCatPanel.Collapsed then
    lCatPanel.Height := TWinControl(Sender).Height + 26;
end;

procedure TfrmEmbDateStatistics.SelectStopChannel(Sender: TObject);
var
  s: String;
  Value: integer;
  StatusCont: TRoomClassChannelAvailabilityContainer;
begin
  TMenuItem(Sender).Checked := NOT TMenuItem(Sender).Checked;
  if TMenuItem(Sender).Checked then
    Value := 1
  else
    Value := 0;

  StatusCont := availListContainer[grdRoomClasses.row - 1];
  StatusCont.AnyStop := AnyCheckedStopItems;

  s := Format('UPDATE channelrates SET dirty=1, Stop=%d ' + 'WHERE id=%d', [Value, TMenuItem(Sender).Tag]);
  if not cmd_bySQL(s) then
  begin
    raise Exception.Create('Channel Stop-Sale update failed.');
  end;
  grdRoomClasses.Update;
  grdRoomClasses.Invalidate;
end;

Function TfrmEmbDateStatistics.AnyCheckedStopItems: boolean;
var
  i: integer;
begin
  result := false;
  for i := 0 to pmnuChannelSettings.Items.Count - 1 do
    if pmnuChannelSettings.Items[i].Checked then
    begin
      result := true;
      break;
    end;
end;

procedure TfrmEmbDateStatistics.PopulateChannelStopMenu;
var
  rSet: TRoomerDataSet;
  item: TMenuItem;
  iValue: integer;
begin
  if (grdRoomClasses.row > 0) then
  begin

    pmnuChannelSettings.Items.Clear;
    iValue := strtointDef(grdRoomClasses.cells[3, grdRoomClasses.row], DEFAULT_UNPARSABLE_INT_VALUE);
    if iValue = DEFAULT_UNPARSABLE_INT_VALUE then
      exit;

    rSet := d.roomerMainDataSet.ActivateNewDataset
      (d.roomerMainDataSet.SystemFreeQuery(Format('SELECT id, Stop, ' +
      '       (SELECT Code FROM roomtypegroups WHERE id=roomClassId) AS roomClass, ' +
      '       channelId, ' + '       (SELECT name FROM channels WHERE id=channelId) AS channelName ' +
      'FROM channelrates ' +
      'WHERE roomClassId=(SELECT id FROM roomtypegroups WHERE Code=''%s'' LIMIT 1) ' +
      'AND to_bool((SELECT Active FROM channels WHERE id=channelId)) ' +
      'AND date=''%s'' ' + 'ORDER BY channelName', [grdRoomClasses.cells[0, grdRoomClasses.row],
      uDateUtils.dateToSqlString(FDate)])));
    try
      rSet.first;
      while not rSet.eof do
      begin
        item := TMenuItem.Create(pmnuChannelSettings);
        item.Caption := 'Stop on ' + rSet['channelName'];
        item.Checked := rSet['Stop'];
        item.Tag := rSet['id'];
        item.OnClick := SelectStopChannel;
        pmnuChannelSettings.Items.Add(item);
        rSet.next;
      end;
    finally
      freeandNil(rSet);
    end;
  end;
end;



procedure TfrmEmbDateStatistics.timGetRoomStatusesTimer(Sender: TObject);
var
  f: double;
begin
  timGetRoomStatuses.Enabled := false;
  try
    frmDayNotes.edCurrentDate.Text := DateToStr(timGetRoomStatuses.Tag);
    f := timGetRoomStatuses.tag;
    Date := TDateTime(f);
  Except
  end;

end;



procedure TfrmEmbDateStatistics.ActivateHint(HintPoint: TPoint; comp: TWinControl);
begin
  zHintPoint := HintPoint;
  zHintComp := comp;
  // Application.CancelHint;
  comp.ShowHint := true;
  Application.ActivateHint(zHintPoint);
end;



end.
