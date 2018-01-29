unit uCustomerEdit2;

interface

uses
    Winapi.Windows
  , Winapi.Messages
  , System.SysUtils
  , System.Variants
  , System.Classes
  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , Vcl.StdCtrls

  , _Glob
  , Hdata
  , PrjConst
  , ug
  , uD
  , cmpRoomerDataSet
  , uFrmKeyPairSelector
  , uCustomerDepartments
  , Generics.Collections

  , sCheckBox
  , sEdit
  , sGroupBox
  , sButton
  , Vcl.ExtCtrls
  , sPanel
  , sLabel

  , Vcl.Buttons
  , sSpeedButton
  , Vcl.Mask
  , sMaskEdit
  , sCustomComboEdit
  , sCurrEdit
  , sSkinProvider, sMemo, Vcl.ComCtrls, sPageControl, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, cxContainer, cxEdit, cxTreeView, Vcl.Menus, sListView, sSplitter, DragDrop, DropTarget,
  DropComboTarget, uFraLookupPanel, ufraCurrencyPanel, uFraCountryPanel, uFraMarketSegmentPanel, ufraChannelPanel,
  uFraPriceCodePanel

  ;

type
  TfrmCustomerEdit2 = class(TForm)
    panBtn: TsPanel;
    btnCancel: TsButton;
    BtnOk: TsButton;
    pgMain: TsPageControl;
    SheetMain: TsTabSheet;
    SheetExtra: TsTabSheet;
    gbxAddress: TsGroupBox;
    sLabel4: TsLabel;
    sLabel5: TsLabel;
    edAddress1: TsEdit;
    edAddress2: TsEdit;
    edAddress3: TsEdit;
    edAddress4: TsEdit;
    cbxName: TsGroupBox;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    sLabel3: TsLabel;
    sSpeedButton1: TsSpeedButton;
    sSpeedButton2: TsSpeedButton;
    edCustomer: TsEdit;
    edSurName: TsEdit;
    chkActive: TsCheckBox;
    edPID: TsEdit;
    chkTravelAgency: TsCheckBox;
    LMDGroupBox5: TsGroupBox;
    gbxContact: TsLabel;
    LMDSimpleLabel10: TsLabel;
    LMDSimpleLabel11: TsLabel;
    LMDSimpleLabel14: TsLabel;
    LMDSimpleLabel13: TsLabel;
    LMDSimpleLabel19: TsLabel;
    edFax: TsEdit;
    edTel2: TsEdit;
    edTel1: TsEdit;
    edEmailAddress: TsEdit;
    edContactPerson: TsEdit;
    edHomepage: TsEdit;
    gbxGuest: TsGroupBox;
    clabMarkedSegment: TsLabel;
    LMDSimpleLabel7: TsLabel;
    LMDSimpleLabel8: TsLabel;
    LMDSimpleLabel5: TsLabel;
    LMDSimpleLabel12: TsLabel;
    edDiscountPercent: TsCalcEdit;
    chkStayTaxIncluted: TsCheckBox;
    sGroupBox1: TsGroupBox;
    memNotes: TsMemo;
    lblRatePlan: TsLabel;
    tabDepartments: TsTabSheet;
    PopupMenu1: TPopupMenu;
    D1: TMenuItem;
    C1: TMenuItem;
    sSplitter1: TsSplitter;
    pnlDepartments: TsPanel;
    pnlContacts: TsPanel;
    lvDepartments: TsListView;
    lvContacts: TsListView;
    sPanel3: TsPanel;
    btnAddDepartment: TsButton;
    btnEditDepartment: TsButton;
    btnDeleteDepartment: TsButton;
    sLabel6: TsLabel;
    sPanel4: TsPanel;
    sLabel7: TsLabel;
    btnAddContact: TsButton;
    btnEditContact: TsButton;
    btnDeleteContact: TsButton;
    pnlDocs: TsPanel;
    btnDocuments: TsButton;
    DropComboTarget1: TDropComboTarget;
    timBlink: TTimer;
    btnPasteFile: TsButton;
    fraLookupMarketSegment: TfraLookupMarketSegment;
    fraCountryPanel: TfraCountryPanel;
    fraCurrencyPanel: TfraCurrencyPanel;
    fraChannelPanel: TfraChannelPanel;
    fraPriceCodePanel: TfraPriceCodePanel;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOkClick(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure btnCancelClick(Sender: TObject);
    procedure sSpeedButton1Click(Sender: TObject);
    procedure sSpeedButton2Click(Sender: TObject);
    procedure edPIDDblClick(Sender: TObject);
    procedure pgMainChange(Sender: TObject);
    procedure tvDepartmentsChange(Sender: TObject; Node: TTreeNode);
    procedure lvDepartmentsSelectItem(Sender: TObject; Item: TListItem; Selected: Boolean);
    procedure lvContactsSelectItem(Sender: TObject; Item: TListItem; Selected: Boolean);
    procedure btnAddDepartmentClick(Sender: TObject);
    procedure btnAddContactClick(Sender: TObject);
    procedure btnEditDepartmentClick(Sender: TObject);
    procedure btnEditContactClick(Sender: TObject);
    procedure lvContactsDblClick(Sender: TObject);
    procedure lvDepartmentsDblClick(Sender: TObject);
    procedure btnDeleteContactClick(Sender: TObject);
    procedure btnDeleteDepartmentClick(Sender: TObject);
    procedure btnDocumentsClick(Sender: TObject);
    procedure edCustomerChange(Sender: TObject);
    procedure DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
    procedure timBlinkTimer(Sender: TObject);
    procedure btnPasteFileClick(Sender: TObject);
    procedure DropComboTarget1DragOver(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
  private
    { Private declarations }

    financeCustomerList : TKeyPairList;
    tmpHolder : recCustomerHolder;
    zCanClose  : boolean;

    procedure initEdits;
    procedure DisplayCustomerDepartments;
//    function SelectedCustomerDepartmentId: Integer;
    procedure ListContacts;
    procedure ActivateButtons;

  public
    { Public declarations }
    zData   : recCustomerHolder;
    zInsert : boolean;
  end;


  function openCustomerEdit(var theData : recCustomerHolder; isInsert : boolean; _financeCustomerList : TKeyPairList = nil) : boolean;


var
  frmCustomerEdit2: TfrmCustomerEdit2;

implementation

{$R *.dfm}

uses
  uCurrencies
  , uCountries
  , ufrmPriceCodesGrid
  , uCustomerTypes2
  , uAppGlobal
  , uChannels
  , uPersons
  , uFrmCustomerDepartmentEdit
  , uGuestPortfolioEdit
  , uFrmResources
  , uResourceManagement
  , uDImages
  , uUtils
  , uResourceTypeDefinitions
  , UITypes, uRoomerGridForm, uRoomerCurrencymanager;


function openCustomerEdit(var theData : recCustomerHolder; isInsert : boolean; _financeCustomerList : TKeyPairList = nil) : boolean;
begin
  result := false;
  frmCustomerEdit2 := TfrmCustomerEdit2.Create(frmCustomerEdit2);
  try
    frmCustomerEdit2.zData := theData;
    frmCustomerEdit2.zInsert := isInsert;
    frmCustomerEdit2.financeCustomerList := _financeCustomerList;
    frmCustomerEdit2.ShowModal;
    if frmCustomerEdit2.modalresult = mrOk then
    begin
      theData := frmCustomerEdit2.zData;
      result := true;
    end
  finally
    freeandnil(frmCustomerEdit2);
  end;
end;



procedure TfrmCustomerEdit2.initEdits;
begin

  // Customer
  edCustomer.MaxLength := 15;
//  edCustomer.CharCase  := ecUpperCase;
  edCustomer.Enabled := zInsert;
  sSpeedButton1.Enabled := zInsert;

  edPID.MaxLength      := 15;
//  edPID.CharCase  := ecUpperCase;

  edSurName.MaxLength  := 100;

  edAddress1.MaxLength  := 100;
  edAddress2.MaxLength  := 100;
  edAddress3.MaxLength  := 100;
  edAddress4.MaxLength  := 100;

  edTel1.MaxLength          := 15;
  edTel2.MaxLength          := 15;
  edFax.MaxLength           := 15;
  edHomePage.MaxLength      := 100;
  edEmailAddress.MaxLength  := 100;
  edContactPerson.MaxLength := 100;

end;


procedure TfrmCustomerEdit2.lvContactsDblClick(Sender: TObject);
begin
  if NOT Assigned(lvContacts.Selected) then exit;
  btnEditContact.Click;
end;

procedure TfrmCustomerEdit2.lvContactsSelectItem(Sender: TObject; Item: TListItem; Selected: Boolean);
begin
  ActivateButtons;
end;

procedure TfrmCustomerEdit2.lvDepartmentsDblClick(Sender: TObject);
begin
  if NOT Assigned(lvDepartments.Selected) then exit;
  btnEditDepartment.Click;
end;

procedure TfrmCustomerEdit2.lvDepartmentsSelectItem(Sender: TObject; Item: TListItem; Selected: Boolean);
begin
  ListContacts;
  ActivateButtons;
end;

procedure TfrmCustomerEdit2.ActivateButtons;
begin
  btnEditDepartment.Enabled := Assigned(lvDepartments.Selected);
  btnDeleteDepartment.Enabled := Assigned(lvDepartments.Selected);

  btnEditContact.Enabled := Assigned(lvContacts.Selected);
  btnDeleteContact.Enabled := Assigned(lvContacts.Selected);

  btnAddContact.Enabled := Assigned(lvDepartments.Selected);

end;

procedure TfrmCustomerEdit2.ListContacts;
var
  i: Integer;
  Item  : TListItem;
  CustomerDepartment : TCustomerDepartment;
begin
  lvContacts.Items.Clear;
  if lvDepartments.Selected = nil then exit;

  CustomerDepartment := TCustomerDepartment(lvDepartments.Selected.Data);
  for i := 0 to CustomerDepartment.Contacts.Count - 1 do
  begin
    Item := lvContacts.Items.Add;
    Item.Caption := CustomerDepartment.Contacts[i].Title;
    Item.SubItems.Add(CustomerDepartment.Contacts[i].FullName);
    Item.SubItems.Add(CustomerDepartment.Contacts[i].LastName);
    Item.Data := CustomerDepartment.Contacts[i];
    Item.ImageIndex := 85;
  end;
  lvContacts.Selected := NIL;
  ActivateButtons;
end;

procedure TfrmCustomerEdit2.DisplayCustomerDepartments;
var
  i: Integer;
  Item  : TListItem;
begin
  lvContacts.Items.Clear;
  lvDepartments.Items.Clear;
  for i := 0 to CustomerDepartments.Count - 1 do
  begin
    Item := lvDepartments.Items.Add;
    Item.Caption := CustomerDepartments[i].DepartmentName;
    Item.Data := CustomerDepartments[i];
    Item.ImageIndex := 114;
  end;
  lvDepartments.Selected := NIL;

  ActivateButtons;
end;

procedure TfrmCustomerEdit2.DropComboTarget1DragOver(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
begin
  Effect := DROPEFFECT_COPY;
end;

procedure TfrmCustomerEdit2.DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
begin
  if btnDocuments.Enabled then
  begin
    Effect := DROPEFFECT_COPY;
    DropComboTargetDrop(format(CUSTOMER_DOCUMENTS_STATIC_RESOURCE_PATTERN, [edCustomer.Text]),
                        ACCESS_RESTRICTED, Sender AS TDropComboTarget, ShiftState, APoint, Effect);
    timBlink.Tag := 0;
    timBlink.Enabled := False;
    timBlink.Interval := 100;
    timBlink.Enabled := True;
  end;
end;

procedure TfrmCustomerEdit2.pgMainChange(Sender: TObject);
begin
  if pgMain.ActivePageIndex = 2 then
    DisplayCustomerDepartments;
end;

procedure TfrmCustomerEdit2.btnDocumentsClick(Sender: TObject);
begin
  StaticResources('Customer Resources',[TResourceType.rtCustomerDocument], TResourceAccessType.ratRestricted, edCustomer.Text);
end;

(*
function TfrmCustomerEdit2.SelectedCustomerDepartmentId : Integer;
var dep : TCustomerDepartment;
begin
  result := 0;
  if NOT Assigned(lvDepartments.Selected) then exit;
  dep := TCustomerDepartment(lvDepartments.Selected.Data);
  result := dep.ID;
end;
*)
procedure TfrmCustomerEdit2.sSpeedButton1Click(Sender: TObject);
var
  s : string;
  sNext : string;
begin
  sNext := D.getTblINC_nextCustomerNumber;
  s := '';
  if zInsert then
  begin
    edCustomer.Text := sNext;
  end else
  begin
    exit;
  end;

end;

procedure TfrmCustomerEdit2.sSpeedButton2Click(Sender: TObject);
var
  pIdValue : string;
  keyValue : TKeyAndValue;
  CursorWas : SmallInt;
begin
  CursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass; Application.ProcessMessages;
  try
    if NOT assigned(financeCustomerList) then
      financeCustomerList := d.RetrieveFinancesKeypair(FKP_CUSTOMERS);

    pIdValue := trim(edPID.text);
    keyValue := selectFromKeyValuePairs('Customers', pIdValue, financeCustomerList);
    if Assigned(keyValue) then
    begin
      edPID.text := keyValue.Key;
    end else
    begin
      //NotOK
    end;
  finally
    Screen.Cursor := CursorWas; Application.ProcessMessages;
  end;
end;

procedure TfrmCustomerEdit2.timBlinkTimer(Sender: TObject);
begin
  timBlink.Enabled := False;
  timBlink.Tag := timBlink.Tag + 1;
  if timBlink.Tag < 7 then
  begin
    btnDocuments.SkinData.CustomColor := NOT (timBlink.Tag div 2 = timBlink.Tag / 2);
    if btnDocuments.SkinData.CustomColor then
    begin
      btnDocuments.SkinData.ColorTone := clRed;
      timBlink.Interval := 500;
    end else
    begin
      btnDocuments.SkinData.ColorTone := clNone;
      timBlink.Interval := 250;
    end;
    timBlink.Enabled := True;
  end else
  begin
    btnDocuments.SkinData.ColorTone := clNone;
    btnDocuments.SkinData.CustomColor := False;
  end;
end;

procedure TfrmCustomerEdit2.tvDepartmentsChange(Sender: TObject; Node: TTreeNode);
begin
end;

///////////////////////////////////////////////////////////////////////////////////
///
///
///////////////////////////////////////////////////////////////////////////////////


procedure TfrmCustomerEdit2.FormCreate(Sender: TObject);
begin
  financeCustomerList := nil;
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  pgMain.ActivePageIndex := 0;

  btnDocuments.Enabled := False;
  btnPasteFile.Enabled := False;
  //**
end;

procedure TfrmCustomerEdit2.FormShow(Sender: TObject);
begin
  //**

  zcanClose := true;

  tmpHolder := zData;
  initEdits;

  if zInsert then
  begin
    activeControl := edCustomer;
  end else
  begin
    activeControl := edSurName;
  end;


  chkActive.checked       := zData.Active;
  edCustomer.Text         := zData.Customer;
  edSurname.Text          := zData.Surname;
  edPID.Text              := zData.PID;
  fraLookupMarketSegment.Code := zData.CustomerType;
  edAddress1.Text         := zData.Address1;
  edAddress2.Text         := zData.Address2;
  edAddress3.Text         := zData.Address3;
  edAddress4.Text         := zData.Address4;
  fraCountryPanel.Code   := zData.Country;
  edTel1.Text             := zData.Tel1;
  edTel2.Text             := zData.Tel2;
  edFax.Text              := zData.Fax;
  edDiscountPercent.Value := zData.DiscountPercent;
  edEmailAddress.Text     := zData.EmailAddress;
  edContactPerson.Text    := zData.ContactPerson;
  chkTravelAgency.checked := zData.TravelAgency;
  fraCurrencyPanel.Code   := iif(zData.Currency.IsEmpty, RoomerCurrencyManager.DefaultCurrencyDefinition.CurrencyCode, zData.Currency);
  edHomepage.Text            := zData.Homepage;
  memNotes.lines.Text              := zData.notes;
  fraPriceCodePanel.Code  := zData.pcCode;
  chkStayTaxIncluted.Checked := zData.stayTaxIncluted;

  fraChannelPanel.ChannelId := zData.RatePlanId;

  pgMain.ActivePageIndex := 0;

  tabDepartments.TabVisible := NOT zInsert;
end;

procedure TfrmCustomerEdit2.edCustomerChange(Sender: TObject);
begin
  btnDocuments.Enabled := TRIM(edCustomer.Text) <> '';
  btnPasteFile.Enabled := btnDocuments.Enabled;
end;

procedure TfrmCustomerEdit2.edPIDDblClick(Sender: TObject);
begin
  if not _chkPID(edPID.Text) then
  begin
    showmessage('Not valid')
  end else
  begin
    showmessage('valid')
  end;
end;

procedure TfrmCustomerEdit2.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  canclose := zCanClose;
end;

procedure TfrmCustomerEdit2.btnAddContactClick(Sender: TObject);
var id : Integer;
    rSet : TRoomerDataset;
begin
  rSet := CreateNewDataSet;
  try
    id := CreateNewGuest(rSet);
    if id > 0 then
    begin
      TCustomerDepartment(lvDepartments.Selected.Data).AddContact(id);
      ListContacts;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmCustomerEdit2.btnAddDepartmentClick(Sender: TObject);
var CustomerDepartment : TCustomerDepartment;
begin
  CustomerDepartment := TCustomerDepartment.Create;
  if EditCustomerDepartment(CustomerDepartment) then
    CustomerDepartments.Add(CustomerDepartment);
  DisplayCustomerDepartments;
end;

procedure TfrmCustomerEdit2.btnCancelClick(Sender: TObject);
begin
  zCanClose := true;
end;

procedure TfrmCustomerEdit2.btnDeleteContactClick(Sender: TObject);
var Person : TPerson;
begin
  if Assigned(lvContacts.Selected) then
  begin
    Person := TPerson(lvContacts.Selected.Data);
    Person.Delete;
    TCustomerDepartment(lvDepartments.Selected.Data).Contacts.Remove(Person);
    ListContacts;
  end;
end;

procedure TfrmCustomerEdit2.btnDeleteDepartmentClick(Sender: TObject);
var CustomerDepartment : TCustomerDepartment;
    mr : Integer;
begin
  if Assigned(lvDepartments.Selected) then
  begin
    CustomerDepartment := TCustomerDepartment(lvDepartments.Selected.Data);
    mr := mrYes;
    if (CustomerDepartment.Contacts.Count > 0) then
       mr := MessageDlg('This departments has ' + inttostr(CustomerDepartment.Contacts.Count) + ' contacts attached.'#10'Do you want to delete the contacts as well?',
                        mtConfirmation, [mbYes, mbNo, mbCancel], 0);
    if mr = mrCancel then exit;
    if mr = mrYes then
      while CustomerDepartment.Contacts.Count > 0 do
      begin
        CustomerDepartment.Contacts[0].Delete;
        CustomerDepartment.Contacts.delete(0);
      end;
    CustomerDepartment.Delete;
    CustomerDepartments.Remove(CustomerDepartment);
    DisplayCustomerDepartments;
  end;
end;

procedure TfrmCustomerEdit2.btnEditContactClick(Sender: TObject);
var id : Integer;
begin
  if Assigned(lvContacts.Selected) then
  begin
    id := TPerson(lvContacts.Selected.Data).ID;
    OpenGuestPortfolioEdit(glb.PersonProfiles, id);
    UpdatePersonsFromID(TPerson(lvContacts.Selected.Data), id);
    ListContacts;
  end;

end;

procedure TfrmCustomerEdit2.btnEditDepartmentClick(Sender: TObject);
begin
  if Assigned(lvDepartments.Selected) then
  begin
    if EditCustomerDepartment(TCustomerDepartment(lvDepartments.Selected.Data)) then
    begin
      DisplayCustomerDepartments;
    end;
  end;

end;

procedure TfrmCustomerEdit2.BtnOkClick(Sender: TObject);
begin
   zCanClose := false;

  if trim(edCustomer.Text) = '' then
  begin
    //showmessage('Customer is required');
	showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerRequired'));
    edCustomer.SetFocus;
    Exit;
  end;

  if edCustomer.text <> UPPERCase(tmpHolder.Customer) then
  begin
    if CustomerExist(edCustomer.text) then
    begin
      //showmessage('This customer exists ');
  	  showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerExists'));
      edCustomer.SetFocus;
      exit;
    end;
  end;

  if trim(edSurName.Text) = '' then
  begin
    //showmessage('Name is required');
	showmessage(GetTranslatedText('shTx_CustomerEdit2_NameRequired'));
    edSurName.SetFocus;
    Exit;
  end;


  if not fraLookupMarketSegment.IsValid then
  begin
    //showmessage('Customer is required');
	  showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerTypeRequired'));
    fraLookupMarketSegment.SetFocus;
    Exit;
  end;


  if not fraCountryPanel.IsValid then
  begin
    //showmessage('Customer is required');
	  showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerCountryRequired'));
    fraCountryPanel.SetFocus;
    Exit;
  end;

  if not fraCurrencyPanel.IsValid then
  begin
    //showmessage('Customer is required');
	  showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerCurrencyRequired'));
    fraCurrencyPanel.SetFocus;
    Exit;
  end;

  if not fraPriceCodePanel.IsValid then
  begin
    //showmessage('Customer is required');
	  showmessage(GetTranslatedText('shTx_CustomerEdit2_CustomerPriceCoceRequired'));
    fraPriceCodePanel.SetFocus;
    Exit;
  end;

   zCanClose := true;

  zData.Active           :=  chkActive.checked        ;
  zData.Customer         :=  TRIM(edCustomer.Text)    ;
  zData.Surname          :=  edSurname.Text           ;
  zData.PID              :=  edPID.Text               ;
  zData.CustomerType     :=  fraLookupMarketSegment.Code;
  zData.Address1         :=  edAddress1.Text          ;
  zData.Address2         :=  edAddress2.Text          ;
  zData.Address3         :=  edAddress3.Text          ;
  zData.Address4         :=  edAddress4.Text          ;
  zData.Country          :=  fraCountryPanel.Code    ;
  zData.Tel1             :=  edTel1.Text              ;
  zData.Tel2             :=  edTel2.Text              ;
  zData.Fax              :=  edFax.Text               ;
  zData.DiscountPercent  :=  edDiscountPercent.Value  ;
  zData.EmailAddress     :=  edEmailAddress.Text      ;
  zData.ContactPerson    :=  edContactPerson.Text     ;
  zData.pcID             :=  PriceCode_ID(fraPriceCodePanel.Code);
  zData.TravelAgency     :=  chkTravelAgency.checked  ;
  zData.Currency         :=  fraCurrencyPanel.Code    ;
  zData.Homepage         :=  edHomepage.Text          ;
  zData.notes            :=  memNotes.lines.Text          ;
  zData.CountryName              := fraCountryPanel.Description;
  zData.CustomerTypeDescription  := fraLookupMarketSegment.Description;
  zData.PcCode                   := fraPriceCodePanel.Code;
  zData.stayTaxIncluted          := chkStayTaxIncluted.Checked  ;
  zData.RatePlanId       := fraChannelPanel.ChannelId;

end;



procedure TfrmCustomerEdit2.btnPasteFileClick(Sender: TObject);
begin
  if DropComboTarget1.CanPasteFromClipboard then
    DropComboTarget1.PasteFromClipboard;
end;

end.
