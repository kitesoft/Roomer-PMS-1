unit uRoomerDataConvertMain;

interface

uses
    Winapi.Windows
  , Generics.Collections
  , Winapi.Messages
  , System.SysUtils
  , System.Variants
  , System.Classes
  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , Data.DB
  , Data.Win.ADODB

  , cmpRoomerDataSet

  , Vcl.ExtCtrls
  , UbuntuProgress

  , sPanel

  , cxGraphics
  , cxControls
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , cxClasses
  , cxCustomData
  , cxStyles
  , cxEdit
  , dxSkinsCore
  , dxSkinCaramel
  , dxSkinCoffee
  , dxSkinDarkSide
  , dxSkinTheAsphaltWorld
  , dxSkinsDefaultPainters

  , Vcl.StdCtrls

  , sEdit
  , sLabel
  , sButton

  , kbmMemTable
  , dxmdaset
  , cxPivotGridCustomDataSet
  , cxPivotGridSummaryDataSet
  , cxCustomPivotGrid
  , cxDBPivotGrid
  , cxExportPivotGridLink

  , WinApi.ShellApi

  , sComboBox

  , dxSkinDarkRoom
  , sSkinProvider
  , sSkinManager
  , sCheckBox
  , sGroupBox, cxPropertiesStore, Vcl.Grids, Vcl.DBGrids, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit, Vcl.ComCtrls, sPageControl, sMemo, sSplitter,
  acProgressBar, sSpinEdit, HTMLabel
  ;

type
  TfrmRoomerDataConvertMain = class(TForm)
    RoomsDateDS: TDataSource;
    sLabel1: TsLabel;
    edtUsername: TsEdit;
    sLabel2: TsLabel;
    edtPassword: TsEdit;
    topPanel: TsPanel;
    bottomPanel: TsPanel;
    btnLogin: TsButton;
    btnLogout: TsButton;
    btnExcel: TsButton;
    sSkinManager1: TsSkinManager;
    sSkinProvider1: TsSkinProvider;
    StoreLogin: TcxPropertiesStore;
    edtHotel: TsEdit;
    sLabel3: TsLabel;
    btnProcessIntoRoomer: TsButton;
    prgWorking: TUbuntuProgress;
    sPageControl2: TsPageControl;
    sTabSheet1: TsTabSheet;
    sTabSheet3: TsTabSheet;
    sPanel1: TsPanel;
    sSplitter1: TsSplitter;
    sPageControl1: TsPageControl;
    sTabSheet2: TsTabSheet;
    sLabel4: TsLabel;
    sPanel5: TsPanel;
    btnImportReservations: TsButton;
    btnImportCustomers: TsButton;
    edFilename: TsFilenameEdit;
    sPanel2: TsPanel;
    memoResult: TsMemo;
    sPanel3: TsPanel;
    sButton2: TsButton;
    sPageControl3: TsPageControl;
    sTabSheet4: TsTabSheet;
    sTabSheet5: TsTabSheet;
    lbStatus: TsLabel;
    edtSheetIndex: TsSpinEdit;
    sLabel5: TsLabel;
    sButton1: TsButton;
    HTMLabel1: THTMLabel;
    procedure FormCreate(Sender: TObject);
    procedure btnLoginClick(Sender: TObject);
    procedure btnLogoutClick(Sender: TObject);
    procedure btnEuropa92Click(Sender: TObject);
    procedure btnStandardReservationImportClick(Sender: TObject);
    procedure btnProcessIntoRoomerClick(Sender: TObject);
    procedure btnImportCustomersClick(Sender: TObject);
    procedure edFilenameAfterDialog(Sender: TObject; var Name: string; var Action: Boolean);
    procedure sButton2Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure sButton1Click(Sender: TObject);
  private
    iHeaders : TList<Integer>;
    procedure getCounters(var ResId, PersId: Integer; RoomResIds : TStrings; NumRoomResIds : Integer);
    procedure saveCounters;
    procedure getCustomerInfo(var custNum, custPId: String; var defaultChannel : String);
    procedure ExecStandardCustomersImport(lines: TStrings);
    procedure PositionProgressBar;
    function sh1(Filename : String; SheetIndex:integer; var cols, rows : Integer; Preview : Boolean = False) : Variant;
    function getLine(line: Integer; arrData:Variant; checkName : String): String;
    function indexOfName(arrData: variant; name: String): Integer;

    { Private declarations }
  public
    { Public declarations }
    CSVFileContent : TStringList;
    procedure Breathe(iNum: Integer);
  end;

var
  frmRoomerDataConvertMain: TfrmRoomerDataConvertMain;

implementation

{$R *.dfm}

uses uDataUnit,
     DateUtils,
     uStringUtils,
     uDataBuilder,
     uCSVData,
     OleAuto,
     uUtils,
     uSqlUtils
    ;


procedure TfrmRoomerDataConvertMain.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  try
    if btnLogout.Enabled then
      btnLogout.Click;
  except
   // Ignore exceptions
  end;
  iHeaders.Free;
end;

procedure TfrmRoomerDataConvertMain.FormCreate(Sender: TObject);
begin
  PrepareRoomerConnection;
  CSVFileContent := TStringList.Create;
  iHeaders := TList<Integer>.Create;
end;

procedure TfrmRoomerDataConvertMain.FormResize(Sender: TObject);
begin
  PositionProgressBar;
end;

procedure TfrmRoomerDataConvertMain.FormShow(Sender: TObject);
begin
  PositionProgressBar;
end;

procedure TfrmRoomerDataConvertMain.saveCounters;
var rSet : TRoomerDataSet;
begin
  rSet := RoomerDataSet.CreateNewDataset;
  try
    rSet.CommandType := cmdText;
    RoomerDataSet.DoCommand('UPDATE control SET LastReservation=(SELECT MAX(Reservation) FROM reservations), LastRoomRes=(SELECT MAX(RoomReservation) FROM roomreservations), LastPerson=(SELECT MAX(Person) FROM persons)');
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmRoomerDataConvertMain.Breathe(iNum : Integer);
begin
  if iNum mod 10 = 0 then Application.ProcessMessages;
end;

function getVariantAsString(v : Variant; checkExistence : boolean) : String;
var s : String;
    bArrivalExisting : Boolean;
begin
  bArrivalExisting := False;
  s := '';
  if checkExistence then
    if String(v) = '' then
     raise Exception.Create('Arrival date missing');
  case vartype(v) of
    varEmpty      : s := '';
    varNull       : s := '';
    varAny        : s := '';
    varSmallint   : s := inttostr(v);
    varInteger    : s := inttostr(v);
    varSingle     : s := inttostr(v);
    varDouble     : s := floattostr(v);
    varCurrency   : s := floattostr(v);
    varDate       : s := _db(TDate(v), false);
    varOleStr     : s := v;
    varDispatch   : s := '';
    varError      : s := '';
    varBoolean    : s := IIF(v=true, 'true', 'false');
    varVariant    : s := '';
    varUnknown    : s := '';
    varShortInt   : s := inttostr(v);
    varByte       : s := inttostr(v);
    varWord       : s := inttostr(v);
    varLongWord   : s := inttostr(v);
    varInt64      : s := inttostr(v);
    varStrArg     : s := '';
    varString     : s := v;
    varArray      : s := '';
    varByRef      : s := '';
    varTypeMask   : s := '';
   end;
   result := s;;
end;

function TfrmRoomerDataConvertMain.sh1(Filename : String; SheetIndex:integer; var cols, rows : Integer; Preview : Boolean = False) : Variant;
Var
  Xlapp1, Sheet:Variant ;
  X, Y, i:integer ;
  str:string;
  arrData:Variant;
  s, sData : String;
begin
  Cursor := crHourglass;
  lbStatus.Caption := 'Opening Excel sheet...';
  Application.ProcessMessages;
  try
    Str:=trim(Filename);

    XLApp1 := createoleobject('excel.application');
    XLApp1.Workbooks.open(Str) ;

    Sheet := XLApp1.WorkSheets[SheetIndex] ;
    try
    rows := Sheet.Usedrange.EntireRow.count ;
    cols := sheet.Usedrange.EntireColumn.count;

    //read the used range to a variant array
    arrData:= Sheet.UsedRange.Value;

    if Preview then
    begin
      lbStatus.Caption := 'Reading excel data...';
      Application.ProcessMessages;
      prgWorking.Max := rows;
      prgWorking.Position := 0;
      memoResult.Lines.BeginUpdate;
    end;
    try
      memoResult.Clear;

      iHeaders.Clear;
      for x:=1 to cols do
      begin
        //copy data to header
         s := arrData[1, x];
         if s <> '' then
         begin
          iHeaders.Add(x);
          sData := sData + IIF(sData = '', '', ROOMER_FIELD_DELIMITER) + s;
         end;
      end;
      if Preview then
        memoResult.Lines.Add(Sdata); // do note that the indices are reversed (y, x)

      if Preview then
        for y:=2 to rows do
        begin
          sData := '';
          for i:=0 to iHeaders.Count - 1 do
          begin
            //copy data to grid
            x := iHeaders[i];
            s := getVariantAsString(arrData[y, x], false);
            sData := sData + IIF(sData = '', '', ROOMER_FIELD_DELIMITER) + s;
          end;
          memoResult.Lines.Add(Sdata); // do note that the indices are reversed (y, x)
          Breathe(y);
          prgWorking.StepIt;
          prgWorking.Update;
        end;


      if Preview then
        arrData := null;

      result := arrData;
    finally
      if Preview then
        memoResult.Lines.EndUpdate;
    end;
    finally
      XLApp1.Workbooks.close;
      XLApp1 := null;
    end;
  finally
    lbStatus.Caption := 'Finished opening Excel sheet...';
    Cursor := crDefault;
    prgWorking.Position := 0;
    Application.ProcessMessages;
  end;
end;

function TfrmRoomerDataConvertMain.indexOfName(arrData : variant; name : String) : Integer;
var i, x : integer;
begin
  result := -1;
  for i := 0 to iHeaders.Count - 1 do
  begin
    x := iHeaders[i];
    if LowerCase(arrData[1, x]) = LowerCase(name) then
    begin
      result := x;
      Break;
    end;
  end;
end;

function TfrmRoomerDataConvertMain.getLine(line : Integer; arrData:Variant; checkName : String) : String;
var i, x : Integer;
    sTmp : String;
    indexOfCheckName : Integer;
begin
  result := '';
  indexOfCheckName := indexOfName(arrData, checkName);
  if indexOfCheckName = -1 then
    raise Exception.Create('Correction check cannot be perfomed on "' + checkName + '"');
  for i := 0 to iHeaders.Count - 1 do
  begin
     x := iHeaders[i];
     try
       sTmp := getVariantAsString(arrData[line, x], indexOfCheckName = x);
     except
       result := '';
       exit;
     end;
     result := result + IIF(result = '', '', ROOMER_FIELD_DELIMITER) + sTmp;
  end;
end;

procedure TfrmRoomerDataConvertMain.sButton1Click(Sender: TObject);
var rows, cols : Integer;
begin
  sh1(edFilename.FileName, edtSheetIndex.Value, cols, rows, true);
end;

procedure TfrmRoomerDataConvertMain.sButton2Click(Sender: TObject);
var
  aFilename : string;
begin
  aFilename := ChangeFileExt(edFilename.FileName, '.sql');
  memoresult.Lines.SaveToFile(afilename);
  MessageDlg('The SQL was saved to "' + aFilename + '"', mtInformation, [mbOk], 0);
end;

procedure TfrmRoomerDataConvertMain.btnProcessIntoRoomerClick(Sender: TObject);
var rSet : TRoomerDataSet;
    list : TList<String>;
  i: Integer;
    sList : TStrings;
    processed : TStringList;
begin
  Cursor := crHourglass;
  Application.ProcessMessages;
  try
    rSet := RoomerDataSet.CreateNewDataset;
    try
      rSet.SystemStartTransaction;
      try
        processed := TStringList.Create;
        list := TList<String>.Create;
        sList := TStringList.Create;
        sList.AddStrings(getCustomersSqlList);
        sList.AddStrings(getReservationsSqlList);
        if sList.Count=0 then exit;
        try
          lbStatus.Caption := 'Processing data into Roomer...'; lbStatus.Font.Color := clGreen; lbStatus.Update;
          prgWorking.Max := sList.Count;
          prgWorking.Position := 0;
          for i := 0 to sList.Count - 1 do
            if sList[i] <> '' then
            begin
              list.Add(sList[i]);
              prgWorking.StepIt; prgWorking.Update;
              Breathe(i);

              if list.Count > 200 then
              begin
                prgWorking.ColorSet := csBlue; prgWorking.Update;
                rSet.SystemFreeExecuteMultiple(list);
                list.Clear;
                prgWorking.ColorSet := csOriginal; prgWorking.Update;
              end;
            end;

          if list.Count > 0 then
          begin
            prgWorking.ColorSet := csBlue; prgWorking.Update;
            rSet.SystemFreeExecuteMultiple(list);
            list.Clear;
            prgWorking.ColorSet := csOriginal; prgWorking.Update;
          end;


          if packageDeals.Count > 0 then
          begin
            for i := 0 to PackageDeals.Count - 1 do
            if processed.IndexOf(PackageDeals[i].RefID) < 0 then
            begin
              rSet.CommandType := cmdText;
              rSet.CommandText := format('SELECT RoomReservation FROM roomreservations WHERE Reservation IN (SELECT Reservation FROM reservations WHERE invRefrence=''%s'')', [PackageDeals[i].RefID]) ;
              rSet.open(false);
              rSet.First;
              while NOT rSet.Eof do
              begin
                rSet.SystempackagesAdd(PackageDeals[i].Package, rSet['RoomReservation'], rSet['RoomReservation'], PackageDeals[i].Rate);
                rSet.Next;
              end;
              processed.Add(PackageDeals[i].RefID);
            end;
          end;
        finally
          sList.Free;
          list.Clear;
          list.Free;
          processed.Free;
        end;
        rSet.SystemCommitTransaction;
        lbStatus.Caption := 'Processing done!'; lbStatus.Font.Color := clBlue; lbStatus.Update;
      except
        rSet.SystemRollbackTransaction;
        lbStatus.Caption := 'ERROR: Not able to Process data into Roomer!'; lbStatus.Font.Color := clRed; lbStatus.Update;
      end;
    finally
      FreeAndNil(rSet);
    end;

    memoResult.Lines.Clear;

    memoResult.Lines.Add('');
    memoResult.Lines.Add('Import successful');

    btnLogout.Click;
  finally
    Cursor := crDefault;
    Application.ProcessMessages;
  end;
end;

procedure TfrmRoomerDataConvertMain.PositionProgressBar;
begin
  prgWorking.Left := btnExcel.Left + btnExcel.Width + 10;
  prgWorking.Width := btnProcessIntoRoomer.Left - (btnExcel.Left + btnExcel.Width) - 20;
end;

procedure TfrmRoomerDataConvertMain.getCounters(var ResId, PersId : Integer; RoomResIds : TStrings; NumRoomResIds : Integer);
var rSet : TRoomerDataSet;
    sList : String;
    list : TStrings;
begin
  rSet := RoomerDataSet.CreateNewDataset;
  try
    rSet.CommandType := cmdText;
    rSet.CommandText := 'SELECT (SELECT MAX(Reservation) FROM reservations) AS LastReservation, LastPerson FROM control LIMIT 1';
    rSet.open(false);

    ResId := rSet['LastReservation'];
    PersId := rSet['LastPerson'];

    sList := RoomerDataSet.SystemMultipleNewRoomReservationIds(NumRoomResIds);
    SplitString(sList, RoomResIds, ',');
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmRoomerDataConvertMain.getCustomerInfo(var custNum, custPId : String; var defaultChannel : String);
var rSet : TRoomerDataSet;
begin
  rSet := RoomerDataSet.CreateNewDataset;
  try
    rSet.CommandType := cmdText;
    rSet.CommandText := 'SELECT c.RackCustomer, ' +
                        '(SELECT PID FROM customers WHERE Customer=c.RackCustomer LIMIT 1) AS PID, ' +
                        '(SELECT channelManagerId FROM channels WHERE defaultchannel=1 LIMIT 1) AS defaultChannel ' +
                        'FROM control c LIMIT 1';
    rSet.open(false);

    custNum := rSet['RackCustomer'];
    custPID := rSet['PID'];
    defaultChannel := rSet['defaultChannel'];
  finally
    FreeAndNil(rSet);
  end;
end;


procedure TfrmRoomerDataConvertMain.ExecStandardCustomersImport(lines : TStrings);
var i : Integer;
begin
  start(lines[0], RoomerDataSet);
  for i := 1 to lines.Count - 1 do
     CreateStandardCustomerLine(Lines[i]);

  memoResult.lines.Clear;
  memoResult.Lines.Add('USE home100_' + Lowercase(edtHotel.Text) + ';');
  memoResult.Lines.Add('');
  memoResult.Lines.Add('-- Customers to add');
  memoResult.Lines.AddStrings(getCustomersSqlList);
end;

procedure TfrmRoomerDataConvertMain.btnEuropa92Click(Sender: TObject);
//var i : Integer;
//    ResId, RoomResId, PersId : Integer;
begin
//  getCounters(ResId, RoomResId, PersId);
//
//  start;
//  for i := 0 to memoEu92.Lines.Count - 1 do
//     CreateE92ReservationsLine(memoEu92.Lines[i], edtUsername.Text, ResId, RoomResId, PersId);
//
//  memoResult.Lines.Clear;
//  memoResult.Lines.AddStrings(getReservationsSqlList);
//  if MessageDlg('Update Control table?', mtConfirmation, [mbYes, mbNo], 0) = mrYes then
//  begin
//    saveCounters(ResId, RoomResId, PersId);
//  end;
end;

procedure TfrmRoomerDataConvertMain.btnImportCustomersClick(Sender: TObject);
var arrData:Variant;
    rows, cols : Integer;
    line : Integer;
    str : String;
begin
  Cursor := crHourglass;
  Application.ProcessMessages;
  try
    CSVFileContent.Clear;
    arrData := sh1(edFilename.FileName, edtSheetIndex.Value, cols, rows);
    for line := 1 to rows do
    begin
      str := getLine(line, arrData, 'Customer');
      if str <> '' then
        CSVFileContent.Add(str);
    end;
    ExecStandardCustomersImport(CSVFileContent);
    btnProcessIntoRoomer.Enabled := True;
  finally
    Cursor := crDefault;
    Application.ProcessMessages;
  end;
end;

procedure TfrmRoomerDataConvertMain.btnStandardReservationImportClick(Sender: TObject);
var l : Integer;
    ResId, PersId : Integer;
    RoomResIds : TStrings;
    defaultChannel, custNum, custPId : String;
    MissingField : String;

    max : integer;

    custList : TStrings;
    resList : TStrings;

    numRooms : Integer;
    RoomResList : TList<Integer>;


    sCurrent : String;

//    myFile : TextFile;

    Xlapp1, Sheet:Variant ;
    X, Y:integer ;
    str:string;
    arrData:Variant;
    rows, cols : Integer;

var line : Integer;
begin
  RoomResIds := TStringList.Create;
  try
    CSVFileContent.Clear;
    arrData := sh1(edFilename.FileName, edtSheetIndex.Value, cols, rows);
    Cursor := crHourglass;

    // Read all lines into CSV
    lbStatus.Caption := 'Preparing list...'; lbStatus.Font.Color := clBlue; lbStatus.Update;
    prgWorking.Max := rows;
    prgWorking.Position := 0;
    Application.ProcessMessages;
    for line := 1 to rows do
    begin
      str := getLine(line, arrData, 'Arrival');
      if str <> '' then
        CSVFileContent.Add(str);
      prgWorking.StepIt;
      Application.ProcessMessages;
    end;
    start(CSVFileContent[0], RoomerDataSet);
    numRooms := 0;

    // Read total number of rooms
    lbStatus.Caption := 'Calculating total number or rooms...'; lbStatus.Font.Color := clBlack; lbStatus.Update;
    prgWorking.Max := CSVFileContent.Count - 1;
    prgWorking.Position := 0;
    Application.ProcessMessages;
    for line := 1 to CSVFileContent.Count - 1 do
    begin
      sCurrent := CSVFileContent[line];
      numRooms := numRooms + NumRoomsOfLine(sCurrent);
      prgWorking.Position := line;
      Application.ProcessMessages;
    end;
    lbStatus.Caption := 'Retrieving Reservation id''s from Roomer backend...'; lbStatus.Font.Color := clBlue; lbStatus.Update;
    getCounters(ResId, PersId, RoomResIds, numRooms);
    getCustomerInfo(custNum, custPId, defaultChannel);

    // Check correctness...
    memoResult.Lines.Clear;
    lbStatus.Caption := 'Checking correctness of data...'; lbStatus.Font.Color := clBlack; lbStatus.Update;
    prgWorking.Max := CSVFileContent.Count - 1;
    prgWorking.Position := 0;
    Application.ProcessMessages;
    for line := 1 to CSVFileContent.Count - 1 do
    begin
      sCurrent := CSVFileContent[line];
      MissingField := CheckReservationOfLine(sCurrent);
      if MissingField <> '' then
      begin
        ShowMessage('Cannot continue because field(s) is/are missing: ' + #13#13);
        exit;
      end;
      prgWorking.Position := line;
      Application.ProcessMessages;
    end;

    lbStatus.Caption := 'Reading reservations...'; lbStatus.Font.Color := clGreen; lbStatus.Update;
    prgWorking.Max := CSVFileContent.Count;
    prgWorking.Position := 0;

    PrepareCollect;
    memoResult.Lines.BeginUpdate;
    try

      for line := 1 to CSVFileContent.Count - 1 do
      begin
        sCurrent := CSVFileContent[line];
        numRooms := numRooms + NumRoomsOfLine(sCurrent);
        memoResult.Text := ''; // inttostr(i);
        memoResult.Text := memoResult.Text + '  ' + sCurrent;
        numRooms := NumRoomsOfLine(sCurrent);
        RoomResList := TList<Integer>.Create;
        try
          for l := 0 to numRooms - 1 do
          begin
            RoomResList.Add(StrToInt(RoomResIds[0]));
            RoomResIds.Delete(0);
          end;
          CreateStandardReservationsLine(RoomerDataSet, sCurrent, edtUsername.Text, PersId, RoomResList, custNum, custPID, defaultChannel, false);
        finally
          RoomResList.Free;
        end;
        prgWorking.StepIt; prgWorking.Update;
//        Breathe(0);
      end;
    finally
      memoResult.Lines.EndUpdate;
    end;
//    showmessage('Ok to continue');
    memoResult.Lines.Clear;
    memoResult.Lines.Add('USE home100_' + Lowercase(edtHotel.Text) + ';');
    memoResult.Lines.Add('');
    custList := getCustomersSqlList;
    if custList.Count > 0 then
    begin
      memoResult.Lines.Add('-- Customers to add');
      memoResult.Lines.AddStrings(custList);
    end;
    memoResult.Lines.Add('');
    resList := getReservationsSqlList;
    if resList.Count > 0 then
    begin
      memoResult.Lines.Add('-- Reservations to add');
      lbStatus.Caption := 'Creation done. Reading SQL statements into list...'; lbStatus.Font.Color := clPurple; lbStatus.Update;
      memoResult.Lines.BeginUpdate;
      try
        memoResult.Lines.AddStrings(resList);
      finally
        memoResult.Lines.EndUpdate;
      end;
    end;

  //  if MessageDlg('Update Control table?', mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  //  begin
    lbStatus.Caption := 'Reading SQL statements done. Saving new reservation counter...'; lbStatus.Font.Color := clGreen; lbStatus.Update;
    saveCounters;
    btnProcessIntoRoomer.Enabled := True;

    lbStatus.Caption := 'Preparation done - ready for [Process into Roomer]!';
    lbStatus.Font.Color := clBlue; lbStatus.Update;
  //  end;
  finally
    lbStatus.Caption := 'Idle...'; lbStatus.Font.Color := clBlack; lbStatus.Update;
    Cursor := crDefault;
    Application.ProcessMessages;
    RoomResIds.Free;
  end;
end;

procedure TfrmRoomerDataConvertMain.edFilenameAfterDialog(Sender: TObject; var Name: string; var Action: Boolean);
begin
  if LowerCase(ExtractFileExt(Name)) = '.csv' then
    memoResult.Lines.LoadFromFile(Name);
end;

procedure TfrmRoomerDataConvertMain.btnLoginClick(Sender: TObject);
begin
  RoomerDataSet.ApplicationId := 'DATA_CONVERT';
  RoomerDataSet.Login(edtHotel.Text, edtUsername.Text, edtPassword.Text, '1.0.0.0');
  btnLogout.Enabled := True;
  btnLogin.Enabled := NOT btnLogout.Enabled;
  btnImportCustomers.Enabled := btnLogout.Enabled;
  btnImportReservations.Enabled := btnLogout.Enabled;
end;

procedure TfrmRoomerDataConvertMain.btnLogoutClick(Sender: TObject);
begin
  RoomerDataSet.Logout;
  btnLogin.Enabled := True;
  btnLogout.Enabled := NOT btnLogin.Enabled;
  btnImportCustomers.Enabled := btnLogout.Enabled;
  btnImportReservations.Enabled := btnLogout.Enabled;
end;


end.
