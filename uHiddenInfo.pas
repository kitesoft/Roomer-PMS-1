unit uHiddenInfo;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,
  Menus,
  StdCtrls,

  _glob,
  ug,
  uAboutRoomer,

  cxGraphics,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxControls,
  cxContainer,
  cxEdit,
  ExtCtrls,
  cxMemo,
  cxPC,
  dxStatusBar,
  cxLabel,
  cxTextEdit,
  cxMaskEdit,
  cxDropDownEdit,
  cxCalendar,
  cxButtons, ADODB, ComCtrls, dxCore, cxDateUtils, dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin,
  dxSkinOffice2013White, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxPCdxBarPopupMenu, sMemo, sStatusBar, sButton, sLabel, sPanel,
  sPageControl, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit
  ;

type
  TfrmHiddenInfo = class(TForm)
    panTop: TsPanel;
    dxStatusBar1: TsStatusBar;
    cxPageControl1: TsPageControl;
    tabInformation: TsTabSheet;
    tabViewLog: TsTabSheet;
    panInformation: TsPanel;
    panViewLog: TsPanel;
    memNotes: TsMemo;
    memViewLog: TsMemo;
    btnClose: TsButton;
    dtDeleteOn: TsDateEdit;
    cxLabel1: TsLabel;
    timClose : TTimer;
    btnRevert: TsButton;
    procedure FormCreate(Sender : TObject);
    procedure FormDestroy(Sender : TObject);
    procedure FormShow(Sender : TObject);
    procedure FormClose(Sender : TObject; var Action : TCloseAction);
    procedure btnRevertClick(Sender : TObject);
    procedure btnCloseClick(Sender : TObject);
    procedure timCloseTimer(Sender : TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
  private
    { Private declarations }

    gIsCrypt : boolean;

    gId : integer;
    gNotes : string;
    gDeleteOn : TdateTime;
    gViewLog : string;
    gUserName : String;

    gRec : recHiddenInfoHolder;

//    function openLogin(var userName, password : string) : boolean;
    function isChanged : boolean;
    function addToLog(user, action : string) : boolean;



  public
    { Public declarations }
    zRefrence : integer;
    zRefrenceType : integer;
  end;

var
  frmHiddenInfo : TfrmHiddenInfo;

function OpenHiddenForm(Refrence, RefrenceType : integer) : Boolean;

implementation

uses
  uD,
  RoomerLoginForm,
  hData,
  uAppGlobal,
  uUtils,
  PrjConst
  , uDImages
  , UITypes
  , uRoomerVersionInfo, uSQLUtils
  , uRoomerLanguage
  ;

{$R *.dfm}

function openLogin(var userName, password : string) : boolean;
var hotelId : String;
begin
  hotelId     := g.qHotelCode;
  result := (AskUserForCredentials(userName, password, hotelId, '', 0)  in cLoginFormSuccesfull);
end;

function OpenHiddenForm(Refrence, RefrenceType : integer) : Boolean;
var _frmHiddenInfo : TfrmHiddenInfo;
    gUserName, gPassword : String;
begin
  Result := false;
  if openLogin(gUserName, gPassword) then
  begin
    _frmHiddenInfo := TfrmHiddenInfo.Create(nil);
    try
      _frmHiddenInfo.gUserName := gUserName;
      _frmHiddenInfo.zRefrence := Refrence;
      _frmHiddenInfo.zRefrenceType := RefrenceType;
      _frmHiddenInfo.ShowModal;
      if _frmHiddenInfo.modalresult = mrOK then
      begin
        result := true;
      end
      else
      begin
        result := false; // but who cares
      end;
    finally
      _frmHiddenInfo.free;
    end;
  end;
end;

  procedure TfrmHiddenInfo.timCloseTimer(Sender : TObject);
  begin
    close;
  end;

  // **********************************************************************
  //
  // Form
  //

  procedure TfrmHiddenInfo.FormCreate(Sender : TObject);
  begin
    RoomerLanguage.TranslateThisForm(self);
       glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
    gIsCrypt := false;

    gNotes := '';
    gDeleteOn := date + 3600;
    gViewLog := '';
    zRefrence := 0;
    zRefrenceType := 0;
    dtDeleteOn.date := gDeleteOn;
    g.initRecHiddenInfo(gRec);
  end;

  procedure TfrmHiddenInfo.FormShow(Sender : TObject);
  var

    outLst, innLst : TstringList;
  begin
    // **
    addToLog(gUserName, 'Logged in');
    gId := d.hiddenInfo_Exists(zRefrence, zRefrenceType);

    if gId > 0 then
    begin
      gRec := d.hiddenInfo_getData(gID);

      innLst := TstringList.Create;
      try
        innLst.Text := gRec.Notes;
        outLst := _lstNumDeCrypt(innLst, 5849);
        try
          memNotes.Text := outLst.Text;
        finally
          freeandNil(outLst);
        end;
      finally
        freeandNil(innLst);
      end;
      gRec.Notes := memNotes.Text;
    end else
    begin
      gRec.Refrence := zRefrence;
      gRec.RefrenceType := zRefrenceType;
      gRec.DeleteOn := date + 3600; // ca 10 ár
    end;

    memViewLog.lines.Text         := gRec.ViewLog;
    dtDeleteOn.Date         := gRec.DeleteOn;
  end;

function TfrmHiddenInfo.isChanged: boolean;
begin
  result := false;
  if memNotes.text <> gRec.Notes then result := true;
  if dtDeleteOn.date <> gRec.DeleteOn  then Result := true;
end;

procedure TfrmHiddenInfo.FormClose(Sender : TObject; var Action : TCloseAction);
  begin
    // **
  end;

  procedure TfrmHiddenInfo.FormDestroy(Sender : TObject);
  begin
    // **
  end;

procedure TfrmHiddenInfo.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    Close;
end;

// ***************************************************************************
  //
  //
  //

  function TfrmHiddenInfo.addToLog(user, action : string): boolean;
  var
    s : string;
    line : string;
  begin
    //**
    result := true;
    dateTimeTostring(s,'YYYY-mm-dd hh:nn',now);
    line := s+'  -  '+user+'  -  '+action;
    memViewLog.lines.Add(line);
  end;

procedure TfrmHiddenInfo.btnCloseClick(Sender : TObject);
  var
    s      : string;
    outLst : TstringList;
    innLst : TstringList;
  begin
    // **
   innLst := TstringList.Create;
   try
     innLst.text := memNotes.Text;
     outLst := _lstNumEnCrypt(innLst,5849);
     try
        gNotes := outLst.Text;
     finally
       freeandNil(outLst);
     end;

     gViewLog   :=  memViewLog.Text ;
     gDeleteOn  :=  dtDeleteOn.Date ;


        if isChanged then
        begin
          if gID = 0 then
          begin
            // Insert

            //s := 'Create New ?';
			s := GetTranslatedText('shTx_HiddenInfo_CreateNew');
            if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
            begin
              addToLog(gUserName, 'Added info');
              gViewLog := memViewLog.Text;

              s := '';
              s := s+' INSERT INTO tblhiddeninfo ( ';
              s := s+'     [Notes] ';
              s := s+'    ,[DeleteOn] ';
              s := s+'    ,[ViewLog] ';
              s := s+'    ,[Refrence] ';
              s := s+'    ,[RefrenceType] ';
              s := s+'    ) ';
              s := s+' VALUES ( ';
              s := s+'    '+_db(gNotes)+' ';
              s := s+'   ,'+_db(gDeleteOn)+' ';
              s := s+'   ,'+_db(gViewLog)+' ';
              s := s+'   ,'+_db(zRefrence)+' ';
              s := s+'   ,'+_db(zRefrenceType)+' ';
              s := s+'  ) ';
              if not cmd_bySQL(s) then
              begin
              end;
            end;
          end else
          begin

           // s := 'Save changes ?';
		   s := GetTranslatedText('shTx_HiddenInfo_SaveChanges');
            if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
            begin
              addToLog(gUserName, 'Added info');
              gViewLog := memViewLog.Text;

              s := '';
              s := s + ' UPDATE [tblhiddenInfo] ';
              s := s + ' SET ';
              s := s + ' Notes=' + _db(gNotes)+' ';
              s := s + ' ,DeleteON=' + _db(gDeleteOn)+' ';
              s := s + ' ,ViewLog=' + _db(gViewLog)+' ';
              s := s + ' WHERE (ID = ' + _db(gID) + ') ';
              if not cmd_bySQL(s) then
              begin
              end;
            end;
          end;
        end;
   finally
     freeandNil(innLst);
   end;
 end;

procedure TfrmHiddenInfo.btnRevertClick(Sender : TObject);
begin
  memNotes.Text := gRec.Notes;
end;


end.


