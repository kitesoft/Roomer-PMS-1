unit uFrmResources;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, sPanel, uDImages, Vcl.StdCtrls, sButton,
  cmpRoomerDataSet, hData, Vcl.ComCtrls, sListView, Vcl.ExtDlgs, sDialogs, cxClasses, cxPropertiesStore,
  Vcl.Menus, uMailDrop, uAppGlobal
  , ComObj
  , MSXML
  , ActiveX
  , clipbrd
  , uResourceManagement
  , Soap.EncdDecd, DragDrop, DropTarget, DropComboTarget, DropSource, DragDropFile, sLabel
  , uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, sStatusBar, uResourceTypeDefinitions,
  cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCustomData, cxFilter, cxData,
  cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, Spring.Data.VirtualDataSet, Spring.Data.ObjectDataSet,
  cxGridLevel, cxGridCustomView, cxGridCustomTableView, cxGridDBTableView, cxGrid, cxTextEdit
  ;

type

  EFrmResourcesException = class(Exception);

  TFrmResources = class(TfrmBaseRoomerForm)
    sPanel1: TsPanel;
    btnInsert: TsButton;
    btnDelete: TsButton;
    btnClose: TsButton;
    btnView: TsButton;
    PopupMenu1: TPopupMenu;
    D1: TMenuItem;
    D2: TMenuItem;
    U1: TMenuItem;
    V1: TMenuItem;
    dlgSaveFile: TsSaveDialog;
    dlgOpenFile: TsOpenDialog;
    pnlHolder: TsPanel;
    btnEdit: TsButton;
    sPanel2: TsPanel;
    sButton1: TsButton;
    sButton2: TsButton;
    btnRename: TsButton;
    N1: TMenuItem;
    C1: TMenuItem;
    btnSource: TsButton;
    DropComboTarget1: TDropComboTarget;
    P1: TMenuItem;
    C2: TMenuItem;
    N2: TMenuItem;
    tvResources: TcxGridDBTableView;
    lvlResources: TcxGridLevel;
    grData: TcxGrid;
    dsResources: TObjectDataSet;
    dsGrid: TDataSource;
    tvResourcesID: TcxGridDBColumn;
    tvResourcesOriginalName: TcxGridDBColumn;
    tvResourcesResourceType: TcxGridDBColumn;
    tvResourcesExtraInfo: TcxGridDBColumn;
    tvResourcesURI: TcxGridDBColumn;
    tvResourcesUser: TcxGridDBColumn;
    tvResourcesLastModified: TcxGridDBColumn;
    DropFileSource1: TDropFileSource;
    tvResourcesColumn1: TcxGridDBColumn;
    procedure FormCreate(Sender: TObject);
    procedure btnInsertClick(Sender: TObject);
    procedure btnDeleteClick(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure D1Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnCloseClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure lvResourcesEdited(Sender: TObject; Item: TListItem; var S: string);
    procedure btnRenameClick(Sender: TObject);
    procedure C1Click(Sender: TObject);
    procedure btnSourceClick(Sender: TObject);
    procedure DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
    procedure P1Click(Sender: TObject);
    procedure C2Click(Sender: TObject);
    procedure PopupMenu1Popup(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure tvResourcesCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
    procedure dsResourcesAfterScroll(DataSet: TDataSet);
    procedure tvResourcesResourceTypeGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure btnViewClick(Sender: TObject);
    procedure dsResourcesBeforeDelete(DataSet: TDataSet);
    procedure tvResourcesColumn1GetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
  private
    { Private declarations }
    CollectionOfOpenedFiles : TStringList;
    FResourceManagement : TRoomerResourceManagement;
//    procedure WMDROPFILES(var msg : TWMDropFiles) ; message WM_DROPFILES;
    FAccess: TResourceAccessType;
    FResourceTypes: TResourceTypeSet;
    FSingleResourceType: TResourceType;
    FKeyStringParam: string;
    procedure DownloadAndOpenSelectedResource;
    function DownloadSelectedFile(destFilename: String): Boolean;
    function DownloadSelected: String;
    procedure DeleteSelected;
    procedure InitControls;
    procedure SetKeyString(const Value: string);
    function MakeFileNameUnique(const aOrgFilename: string): string;
    procedure SetResourceTypes(const Value: TResourceTypeSet);
    function GetCurrentResource: TResource; inline;
    function GetRoomerResourceManagement: TRoomerResourceManagement;

    property ResourceManagement: TRoomerResourceManagement read GetRoomerResourceManagement;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    { Public declarations }
    FResourceParameters : TResourceParameters;

    embedded : Boolean;
    EmbedWindowCloseEvent : TNotifyEvent;

    procedure BringWindowToFront;

    procedure RemoveFileForUpload(filename: String);

    property Keystring: string write SetKeyString; // deprated, use ResourceTypes
    property ResourceTypes: TResourceTypeSet read FResourceTypes write SetResourceTypes;
    property KeystringParameter: string read FKeyStringParam write FKeyStringParam;
    property Access: TResourceAccessType read FAccess write FAccess;
    property ResourceParameters : TResourceParameters read FResourceParameters write FResourceParameters;
  end;


var
  FrmResources: TFrmResources;
  FrmResourcesX: TFrmResources;

procedure StaticResources(const sCaption, keyString, access : String;
              _ResourceParameters : TResourceParameters = nil;
              embedPanel : TsPanel = nil;
              WindowCloseEvent : TNotifyEvent = nil); overload; deprecated 'Use StaticResources with TResourceTypeSet parameter';

procedure StaticResources(const sCaption: string; resourceTypes: TResourceTypeSet; accessType: TResourceAccessType; aKeystringparam: string = '';
              _ResourceParameters : TResourceParameters = nil); overload;

implementation

{$R *.dfm}

uses  uD
    , uG
    , PrjConst
    , uFileSystemUtils
    , uRunWithElevatedOption
    , ShellApi
    , uRoomerLanguage
    , uFileDependencyManager
    , uUtils
    , Jpeg
    , pngimage
    , GIFImg
    , uFrmEmbeddedHtmlEditor
    , uDateUtils
    , uFrmNotepad
    , uFrmEditEmailProperties
    , System.IOUtils
    , Spring.Collections
    ;

procedure StaticResources(const sCaption, keyString, access : String;
                _ResourceParameters : TResourceParameters = nil;
                embedPanel : TsPanel = nil;
                WindowCloseEvent : TNotifyEvent = nil);
var _FrmResources: TFrmResources;
begin
  _FrmResources := TFrmResources.Create(nil);
  try
    _FrmResources.Caption := sCaption;
    _FrmResources.keyString := keyString;
    _FrmResources.access := TResourceAccessType.FromString(access);
    _FrmResources.ResourceParameters := _ResourceParameters;
    _FrmResources.embedded := (embedPanel <> nil);
    _FrmResources.EmbedWindowCloseEvent := WindowCloseEvent;
    if _FrmResources.embedded then
    begin
      _FrmResources.pnlHolder.parent := embedPanel;
      embedPanel.Update;
      FrmResourcesX := _FrmResources;
    end
    else
    begin
      _FrmResources.ShowModal;
    end;
    FileDependencyManager.ResetDependencyFileList;
  finally
    if (embedPanel = nil) then
      FreeAndNil(_FrmResources);
  end;
end;

procedure StaticResources(const sCaption: string; resourceTypes: TResourceTypeSet; accessType: TResourceAccessType; aKeystringparam: string = '';
              _ResourceParameters : TResourceParameters = nil);
var
  frm : TFrmResources;
begin
  frm := TFrmResources.Create(nil);
  try
    frm.Caption := sCaption;
    frm.ResourceTypes := resourceTypes;
    frm.KeystringParameter := aKeyStringParam;
    frm.access := accessType;
    frm.ResourceParameters := _ResourceParameters;
    frm.ShowModal;
    FileDependencyManager.ResetDependencyFileList;
  finally
    frm.Free;
  end;
end;


function Download(url, filename : String) : String;
begin
  result := '';
  if d.roomerMainDataSet.DownloadFileResourceOpenAPI(url, filename) then
    result := filename;
end;

procedure TFrmResources.FormClose(Sender: TObject; var Action: TCloseAction);
var i : integer;
begin
  for i := 0 to Pred(CollectionOfOpenedFiles.Count) do
    if FileExists(CollectionOfOpenedFiles[i]) then
      if DeleteFile(CollectionOfOpenedFiles[i]) then
      ;

  Action := caFree;
  if embedded then
  begin
    pnlHolder.Parent := self;
    update;
    if Assigned(EmbedWindowCloseEvent) then
      EmbedWindowCloseEvent(self);
  end;
end;

procedure TFrmResources.FormCreate(Sender: TObject);
begin
  embedded := False;
  CollectionOfOpenedFiles := TStringList.Create;
end;

procedure TFrmResources.FormDestroy(Sender: TObject);
begin
  CollectionOfOpenedFiles.Free;
  FResourceManagement.Free;
end;

procedure TFrmResources.FormShow(Sender: TObject);
begin
  inherited;
  InitControls;
  LoadData;
end;

procedure TFrmResources.D1Click(Sender: TObject);
var filename : String;
begin
  if GetCurrentResource = nil then
    exit;

  if Assigned(ResourceParameters) then
    dlgSaveFile.Filter := ResourceParameters.DefaultFileFilter;

  dlgSaveFile.FileName := GetCurrentResource.ORIGINAL_NAME;
  if dlgSaveFile.Execute then
  begin
    filename := ExtractFilename(dlgSaveFile.FileName);
    if NOT DownloadSelectedFile(filename) then
      raise Exception.Create('Unable to download file.');
  end;
end;

procedure TFrmResources.BringWindowToFront;
begin
  pnlHolder.BringToFront;
end;

procedure TFrmResources.btnCloseClick(Sender: TObject);
begin
  if embedded then
    Close;
end;

procedure TFrmResources.btnDeleteClick(Sender: TObject);
begin
  dsResources.Delete;
end;

procedure TFrmResources.DeleteSelected;
var
    lRes: TResource;
begin
  dsResources.DisableControls;
  try
    lres := GetCurrentResource;
    if (lRes <> nil) then
    begin
      d.roomerMainDataSet.DeleteFileResourceOpenAPI(lRes.URI);
      d.roomerMainDataSet.SystemDeleteStaticResource(lRes.ID);
    end;
  finally
    dsResources.EnableControls;
  end;
end;

procedure ReCodeFile(filename : String);
var Strings : TStringList;
begin
  Strings := TStringList.Create;;
  try
    Strings.LoadFromFile(filename, TEncoding.UTF8);
    Strings.Text := ConvertToEncion(Strings.Text);
    Strings.SaveToFile(filename, TEncoding.UTF8);
  finally
    Strings.Free;
  end;
end;

function TFrmResources.GetCurrentResource: TResource;
begin
  Result := dsResources.GetCurrentModel<TResource>;
end;


function TFrmResources.GetRoomerResourceManagement: TRoomerResourceManagement;
begin
  if not assigned(FResourceManagement) then
    LoadData;

  Result := FResourceManagement;
end;

procedure TFrmResources.btnEditClick(Sender: TObject);
var filename : String;
    cmd,
    OrigName,
    Subject,
    path : String;
    lRes: TResource;
begin
  lRes := GetCurrentResource;
  if assigned(lres) then
  begin

    fileName := DownloadSelected;
    if filename <> '' then
    begin
      if (ResourceParameters IS THtmlResourceParameters) then
      begin
        Subject := lRes.EXTRA_INFO;
        OrigName := lRes.ORIGINAL_NAME;
        if EditHtmlFile(filename) then
        begin
          DeleteSelected;
          ReCodeFile(filename);
          path := UploadFileToResources(lRes.KEY_STRING, access.ToString, ExtractFilename(filename), filename, ResourceParameters);

          cmd := format('UPDATE home100.HOTEL_RESOURCES SET ORIGINAL_NAME=''%s'', EXTRA_INFO=''%s'' WHERE HOTEL_ID=''%s'' AND ORIGINAL_NAME=''%s'' AND URI=''%s'' AND KEY_STRING=''%s''',
                     [ OrigName,
                       Subject,
                       d.roomerMainDataSet.HotelId,
                       OrigName,
                       path,
                       lRes.KEY_STRING
                     ]);
          d.roomerMainDataSet.DoCommand(cmd);
        end;
      end;
    end;
  end;
end;


const NEW_RESERVATION_SOURCE = '<P style="TEXT-ALIGN: right" align=right><FONT face=Verdana><STRONG><FONT color=maroon><FONT size=5>Test Hotel Roomer</FONT><BR></FONT></STRONG> ' +
                                  '<FONT size=1>Bosscheweg 107&nbsp;12-14<BR>5282 WV Boxtel<BR>Netherlands<BR>Tel: +31 85 27 36 150<BR>date/time: ${currentDatetime}<BR>---<BR></FONT><FONT size=2>Booking date: ${bookingDatetime}<BR>Hotel Booking id: ${bookingRoomerId}</FONT></FONT></P> ' +
                                  '<P><FONT face=Verdana>Dear ${bookingGuestName},</FONT></P> ' +
                                  '<P><FONT face=Verdana>Thank you for choosing Test Hotel&nbsp;Roomer as a destination during your stay in the Netherlands. We hope that your stay will be a pleasant one.</FONT></P> ' +
                                  '<P><FONT face=Verdana>Below you can find the details of your booking and&nbsp;some&nbsp;information about our hotel.</FONT></P> ' +
                                  '<P><FONT face=Verdana>You will be arriving on the ${bookingArrival} and departing on ${bookingDeparture}.<BR>Your booking ID: ${bookingRoomerId}</FONT></P> ' +
                                  '<P><FONT face=Verdana>Booking details:<BR>${bookingGuestsRoomsPrices}</FONT></P> ' +
                                  '<P><FONT face=Verdana>Price and payment details:</FONT></P><BR> ' +
                                  '<P><FONT face=Verdana>Total price: ${bookingTotalPrice}<BR>Booking payment type: ${bookingPaymentType}<BR>Payment status: ${bookingPaymentStatus}<BR>Amount paid: ${bookingPaymentAmount}<BR>Credit card: ${bookingPaymentCreditCard}</FONT></P> ' +
                                  '<P><FONT face=Verdana>We would like to use the opportunity to send you some information about the hotel and help you arrange for you transfers, tours and dinner reservations.</FONT></P> ' +
                                  '<P><FONT face=Verdana>The Hotels restaurant is open daily from 18.00 - 22.00. Our renowned chef, Tom Dans, was one of the winners of the TopChef TV series. He will make sure that your stay at our hotel is an unforgettable one.  ' +
                                  'We highly reccommend reserving a table in advance as capacity is limited.</FONT></P> ' +
                                  '<P><FONT face=Verdana>Included in hotel prices is one way to- or from the airport taxi ride. If you would like to use this service on arrival at the&nbsp;Einhoven airport,  ' +
                                  'please take the nearest taxi and we will pay for it on your arrival to Test Hotel Roomer. Should you want to arrange your own personal limo please contact us.</FONT></P> ' +
                                  '<P><FONT face=Verdana>We have a fitness center with a sauna and solarium which guests are free to use during their stay at no extra charge.</FONT></P> ' +
                                  '<P><FONT face=Verdana>If you would like to arrange a dinner at our restaurant, tours or private pickup please contact us by replying to this e-mail.</FONT></P> ' +
                                  '<P><FONT face=Verdana>Best regards,</FONT></P> ' +
                                  '<P><FONT face=Verdana>Your concierge at Test Hotel Roomer</FONT></P> ' +
                                  '<P><FONT face=Verdana>T. 085 27 36 150</FONT></P></DIV>';

const CANCEL_RESERVATION_SOURCE = '<DIV class=WordSection1> ' +
                                  '<P style="TEXT-ALIGN: right" align=right><STRONG><FONT color=maroon size=5 face=Verdana>Test Hotel Roomer</FONT></STRONG><BR>' +
                                  '<FONT size=1 face=Verdana>Bosscheweg 107&nbsp;12-14<BR>5282 WV Boxtel<BR>Netherlands<BR>Tel: +31 85 27 36 150<BR> ' +
                                  'date/time: ${currentDatetime}<BR>---<BR></FONT><FONT face=Verdana><FONT size=2>Booking date: ${bookingDatetime}<BR>Hotel Booking id: ${bookingRoomerId}<?xml:namespace prefix = "o" /><o:p></o:p></FONT></FONT></P> ' +
                                  '<P><FONT face=Verdana>Dear ${bookingGuestName},<o:p></o:p></FONT></P> ' +
                                  '<P><FONT face=Verdana>We are sorry to hear that you will not be staying with us at Test Hotel Roomer. <BR>Please find the details of your cancelled booking listed below.</FONT></P> ' +
                                  '<P><FONT face=Verdana>Booking details:<BR></FONT></P> ' +
                                  '<P><FONT face=Verdana>Arrival:&nbsp;${bookingArrival}<BR>Departure: </FONT><FONT face=Verdana>${bookingDeparture}<BR>Booking ID: ${bookingRoomerId}<o:p></o:p></FONT></P> ' +
                                  '<P><FONT face=Verdana>${bookingGuestsRoomsPrices}<o:p></o:p></FONT></P> ' +
                                  '<P><FONT face=Verdana>Price and payment details:<o:p></o:p></FONT></P> ' +
                                  '<P><FONT face=Verdana>Total price: ${bookingTotalPrice}<BR>Booking payment type: ${bookingPaymentType}<BR>Payment status: ${bookingPaymentStatus}<BR>Amount paid: ${bookingPaymentAmount}<BR>Credit card: ${bookingPaymentCreditCard}<o:p></o:p></FONT></P> ' +
                                  '<P><FONT face=Verdana>At your service,</FONT></P> ' +
                                  '<P><FONT face=Verdana>Test Hotel Roomer</FONT></P> ' +
                                  '<P><FONT face=Verdana>T. 085 27 36 150</FONT></P>';

function TFrmResources.MakeFileNameUnique(const aOrgFilename: string): string;
var
  lPathAndFilename: string;
  lExtension: string;
  lTryFullPath: string;
  cnt: integer;
const
  cCntFmt = '(%d)';
begin
  lPathAndFIleName := TPath.Combine(TPath.GetTempPath, aOrgFilename);
  lExtension := TPath.GetExtension(lPathAndFilename);
  lPathAndFilename := TPath.GetFileNameWithoutExtension(lPathAndFilename);

  lTryFullPath := lPathAndFilename + lExtension;
  cnt := 0;
  while FileExists(lTryFullPath) or ResourceManagement.FilenameInList(TPath.GetFileName(lTryFullPath)) do
  begin
    inc(cnt);
    lTryFullPath := lPathAndFilename + Format(cCntFmt, [cnt]) + lExtension;

    if cnt > 1024 then
      raise EFrmResourcesException.Create('Cannot create unique filename for new resource');
  end;

  Result := lTryFullPath;
end;

procedure TFrmResources.btnInsertClick(Sender: TObject);
var filename, Subject : String;
    Strings : TStrings;
    frm : TFrmEditEmailProperties;
    cmd, uri : String;
    lResType: TResourceType;
begin
  if Assigned(ResourceParameters) AND
     (ResourceParameters IS THtmlResourceParameters) then
  begin
    Subject := '';

    frm := TFrmEditEmailProperties.Create(nil);
    try
      frm.ResourceTypes := ResourceTypes;
      if frm.ShowModal = mrOk then
      begin
        if frm.edtName.Text = '' then
          raise Exception.Create(GetTranslatedText('shUI_NameCannotBeEmpty'));

        Filename := MakeFilenameUnique(frm.edtName.Text);
        lResType := frm.SelectedResourceType;
        Strings := TStringList.Create;
        try
          if lResType = rtGuestEmailTemplate then
            Strings.Text := NEW_RESERVATION_SOURCE
          else
          if lResType = rtCancelEmailTemplate then
            Strings.Text := CANCEL_RESERVATION_SOURCE;
          Strings.SaveToFile(filename);
        finally
          Strings.Free;
        end;
        if EditHtmlFile(filename, true) then
        begin
          ReCodeFile(filename);
          uri := UploadFileToResources(lResType.ToKeyString(FKeyStringParam), access.ToString, ExtractFilename(filename), filename, ResourceParameters);

          cmd := format('UPDATE home100.HOTEL_RESOURCES SET EXTRA_INFO=''%s'' WHERE HOTEL_ID=''%s'' AND ORIGINAL_NAME=''%s'' AND URI=''%s'' AND KEY_STRING=''%s''',
                   [ frm.edtSubject.Text,
                     d.roomerMainDataSet.HotelId,
                     frm.edtName.Text,
                     uri, lResType.ToKeyString(FKeyStringParam)
                   ]);
          d.roomerMainDataSet.DoCommand(cmd);

          RefreshData;
        end;
      end;
    finally
      FreeAndNil(frm);
    end;
  end
  else
  begin

    if FResourceTypes.Count <> 1 then
      raise EFrmResourcesException.Create('Multiple resourcetypes set erroneously.')
    else
    if Assigned(ResourceParameters) then
      dlgSaveFile.Filter := ResourceParameters.DefaultFileFilter;

    if dlgOpenFile.Execute then
    begin
      for filename in dlgOpenFile.Files  do
      begin
        UploadFileToResources(FSingleResourceType.ToKeyString(FKeyStringParam), access.ToString, ExtractFilename(filename), filename, ResourceParameters);
      end;
      RefreshData;
    end;
  end;
end;

procedure TFrmResources.DoLoadData;
var
  IList: IObjectList;
begin
  inherited;
  dsResources.DisableControls;
  try
    FResourceManagement.Free;
    FResourceManagement := TRoomerResourceManagement.Create(FResourceTypes, Access, ResourceParameters, FKeyStringParam);

    if Supports(FResourceManagement.Resources, IObjectList, IList) then
    begin
      dsResources.DataList := Ilist;
      dsResources.Active := true;

    end
    else
      dsResources.Active := false;

  finally
    dsResources.EnableControls;
  end;
  tvResourcesResourceType.ApplyBestFit();
  tvResourcesOriginalName.ApplyBestFit();
  tvResourcesUser.ApplyBestFit();

end;


procedure TFrmResources.btnRenameClick(Sender: TObject);
var
  _FrmEditEmailProperties: TFrmEditEmailProperties;
  cmd : String;
  lRes: TResource;
begin
  lRes := GetCurrentResource;
  if lRes <> nil then
  begin
    _FrmEditEmailProperties := TFrmEditEmailProperties.Create(nil);
    try
      if ResourceParameters IS THtmlResourceParameters then
      begin
        _FrmEditEmailProperties.edtName.Text := lRes.ORIGINAL_NAME;
        _FrmEditEmailProperties.edtSubject.Text := lres.EXTRA_INFO;
        _FrmEditEmailProperties.ResourceTypes := [lres.ResourceType];
        if _FrmEditEmailProperties.ShowModal = mrOk then
        begin
          if _FrmEditEmailProperties.edtName.Text = '' then
            raise Exception.Create(GetTranslatedText('shUI_NameCannotBeEmpty'));

          cmd := format('UPDATE hotelconfigurations SET DefaultChannelConfirmationEmail=''%s'' WHERE DefaultChannelConfirmationEmail=''%s''',
                     [_FrmEditEmailProperties.edtName.Text, lRes.ORIGINAL_NAME]);
          d.roomerMainDataSet.DoCommand(cmd);

          cmd := format('UPDATE home100.HOTEL_RESOURCES SET ORIGINAL_NAME=''%s'', EXTRA_INFO=''%s'' WHERE HOTEL_ID=''%s'' AND ORIGINAL_NAME=''%s'' AND URI=''%s'' AND KEY_STRING=''%s''',
                     [ _FrmEditEmailProperties.edtName.Text,
                       _FrmEditEmailProperties.edtSubject.Text,
                       d.roomerMainDataSet.HotelId,
                       lRes.ORIGINAL_NAME,
                       lRes.URI,
                       lRes.KEY_STRING
                     ]);
          d.roomerMainDataSet.DoCommand(cmd);
          lRes.ORIGINAL_NAME := _FrmEditEmailProperties.edtName.Text;
          lRes.EXTRA_INFO := _FrmEditEmailProperties.edtSubject.Text;
          dsResources.Refresh;
        end;
      end;
    finally
      FreeAndNil(_FrmEditEmailProperties);
    end;
  end;
end;

procedure TFrmResources.btnSourceClick(Sender: TObject);
var filename : String;
    cmd,
    OrigName,
    Subject,
    path : String;
    lRes: TResource;
begin
  lRes := GetCurrentResource;
  if lRes <> nil then
  begin
    fileName := DownloadSelected;
    if filename <> '' then
    begin
      if (ResourceParameters IS THtmlResourceParameters) then
      begin
        Subject := lRes.EXTRA_INFO;
        OrigName := lRes.ORIGINAL_NAME;
        if EditHtmlSource(filename) then
        begin
          ReCodeFile(filename);
          path := UploadFileToResources(lRes.KEY_STRING, access.ToString, ExtractFilename(filename), filename, ResourceParameters);

          cmd := format('UPDATE home100.HOTEL_RESOURCES SET ORIGINAL_NAME=''%s'', EXTRA_INFO=''%s'' WHERE HOTEL_ID=''%s'' AND ORIGINAL_NAME=''%s'' AND URI=''%s'' AND KEY_STRING=''%s''',
                     [ OrigName,
                       Subject,
                       d.roomerMainDataSet.HotelId,
                       OrigName,
                       path,
                       lres.KEY_STRING
                     ]);
          d.roomerMainDataSet.DoCommand(cmd);

          Refreshdata;
        end;
      end;
    end;
  end;
end;

procedure TFrmResources.btnViewClick(Sender: TObject);
begin
  inherited;
  DownloadAndOpenSelectedResource;
end;

procedure TFrmResources.lvResourcesEdited(Sender: TObject; Item: TListItem; var S: string);
//var cmd : String;
begin
//  if S = '' then
//    raise Exception.Create(GetTranslatedText('shUI_NameCannotBeEmpty'));
//
//  cmd := format('UPDATE home100.HOTEL_RESOURCES SET ORIGINAL_NAME=''%s'' WHERE HOTEL_ID=''%s'' AND ORIGINAL_NAME=''%s'' AND URI=''%s'' AND KEY_STRING=''%s''',
//             [S, d.roomerMainDataSet.HotelId, item.Caption, item.SubItems[item.SubItems.Count - 1],
//              TResource(Item.data).KEY_STRING]);
//  d.roomerMainDataSet.DoCommand(cmd);
//
end;

procedure TFrmResources.DownloadAndOpenSelectedResource;
var filename, tmpFile : String;
begin
  Screen.Cursor := crHourglass;
  fileName := DownloadSelected;
  if filename <> '' then
  begin
    tmpFile := filename;
    if (ResourceParameters IS THtmlResourceParameters) then
    begin
      tmpFile := TPath.Combine(GetTempDir, changeFileExt(filename, '.html'));
      if UpperCase(tmpFile) <> UpperCase(filename) then
      begin
        if FileExists(tmpFile) then DeleteFile(tmpFile);
        TFile.Move(filename, tmpFile);
      end;
    end;
    CollectionOfOpenedFiles.Add(tmpFile);
  end;
end;

function TFrmResources.DownloadSelected : String;
var
  filename : String;
  lRes: TResource;
begin
  result := '';
  lRes := GetCurrentResource;
  if lRes <> nil then
  begin
    Screen.Cursor := crHourglass;
    try
      fileName := TPath.Combine(GetTempDir, lRes.ORIGINAL_NAME);
      if DownloadSelectedFile(filename) then
        result := filename;
    finally
      Screen.Cursor := crDefault;
    end;
  end;
end;

procedure TFrmResources.C1Click(Sender: TObject);
begin
  if GetCurrentResource <> nil then
    Clipboard.AsText := GetCurrentResource.URI;
end;

procedure TFrmResources.C2Click(Sender: TObject);
var filename : String;
begin
  fileName := DownloadSelected;
  DropFileSource1.Files.Clear;
  DropFileSource1.Files.Add(filename);
  DropFileSource1.CopyToClipboard;
end;

function TFrmResources.DownloadSelectedFile(destFilename : String) : Boolean;
var
  lRes: TResource;
begin
  Result := false;
  lRes := GetCurrentResource;
  if lRes <> nil then
  begin
    if FileExists(destFilename) then
      DeleteFile(destFilename);

    result := DownloadResource(lRes.URI, destFilename);
  end;
end;

procedure TFrmResources.DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
begin
  DropComboTargetDrop(FSingleResourceType.ToKeyString(FKeyStringParam) , access.ToString, Sender AS TDropComboTarget, ShiftState, APoint, Effect);
  RefreshData;
end;

procedure TFrmResources.dsResourcesAfterScroll(DataSet: TDataSet);
begin
  inherited;
  UpdateControls;
end;


procedure TFrmResources.dsResourcesBeforeDelete(DataSet: TDataSet);
begin
  inherited;
  if MessageDlg(GetTranslatedText('shTx_ResourceManager_Delete_Resource'), mtConfirmation, mbYesNo, 0) = mrYes then
  begin
    DeleteSelected;
    RefreshData;
  end
  else
    Abort;
end;

procedure TFrmResources.P1Click(Sender: TObject);
begin
  if DropComboTarget1.CanPasteFromClipboard then
    DropComboTarget1.PasteFromClipboard;
end;

procedure TFrmResources.PopupMenu1Popup(Sender: TObject);
begin
  P1.Enabled := DropComboTarget1.CanPasteFromClipboard;
end;

procedure TfrmResources.InitControls;
begin
//  if NOT (ResourceParameters IS THtmlResourceParameters) then
//  begin
//    lvResources.Columns.Clear;
//    col := lvResources.Columns.Add;
//    col.Width := 250;
//    col.Caption := '';
//
//    col := lvResources.Columns.Add;
//    col.Width := 50;
//    col.Caption := '';
//
//    col := lvResources.Columns.Add;
//    col.Width := 130;
//    col.Caption := '';
//
//    col := lvResources.Columns.Add;
//    col.Width := 450;
//    col.Caption := 'URI';
//
//  end else

//  lvResources.Columns[1].Caption := GetTranslatedText('shUI_Filename');
//  lvResources.Columns[2].Caption := GetTranslatedText('shUI_User');
//  lvResources.Columns[3].Caption := GetTranslatedText('shUI_DateTime');
//  lvResources.Columns[4].Caption := GetTranslatedText('shUI_Subject');
//
  tvResourcesExtraInfo.Visible := (ResourceTypes * cEmailTemplateResourceTypes <> []);

end;

procedure TFrmResources.DoUpdateControls;
var
  lRes: TResource;
begin
  inherited;
  lRes := GetCurrentResource;
  btnDelete.Enabled := lRes <> nil;
  btnRename.Enabled := lRes <> nil;

  btnEdit.Visible := Assigned(ResourceParameters) AND (ResourceParameters IS THtmlResourceParameters);
  btnEdit.Enabled := (lRes <> nil);

  btnSource.Visible :=  Assigned(ResourceParameters) AND (ResourceParameters IS THtmlResourceParameters);
  btnSource.Enabled := (lRes <> nil);

  btnView.Enabled := Assigned(ResourceParameters) AND (ResourceParameters IS THtmlResourceParameters) and (lRes <> nil);

  v1.Enabled := lRes <> nil;
  d1.Enabled := lRes <> nil;
  d2.Enabled := lRes <> nil;
  c2.Enabled := lRes <> nil;

end;

procedure TFrmResources.RemoveFileForUpload(filename: String);
begin
  ResourceManagement.RemoveFileForUpload(filename);
end;

procedure TFrmResources.SetKeyString(const Value: string);
begin
  ResourceTypes := [TResourceType.FromString(Value)];
end;

procedure TFrmResources.SetResourceTypes(const Value: TResourceTypeSet);
var
  lType: TResourceType;
begin
  FResourceTypes := Value;
  if FResourceTypes.Count = 1 then
    for lType in FResourceTypes do
      FSingleResourceType := lType
end;


procedure TFrmResources.tvResourcesCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  inherited;
  DownloadAndOpenSelectedResource;
end;

procedure TFrmResources.tvResourcesColumn1GetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AText: string);
begin
  inherited;
  aText := ResourceManagement.Resource[ARecord.Index].Access.AsReadableString;
end;

procedure TFrmResources.tvResourcesResourceTypeGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  aText := ResourceManagement.Resources[aRecord.Index].ResourceType.AsReadableString();
end;

end.
