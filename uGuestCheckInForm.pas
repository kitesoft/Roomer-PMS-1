unit uGuestCheckInForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sEdit,
  sLabel, Vcl.ComCtrls, sPageControl, sButton, Vcl.ExtCtrls, sPanel, sComboBox, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit, sCheckBox, cmpRoomerDataSet,
  hData, uG, frxDesgn, frxClass, frxDBSet, System.Generics.Collections, uRoomerFilterComboBox
  , uFraCountryPanel, uTokenHelpers, udImages, sCurrEdit, uFraLookupPanel
  , uCurrencyDefinition
    ;

type
  TFrmGuestCheckInForm = class(TForm)
    sPageControl1: TsPageControl;
    sTabSheet1: TsTabSheet;
    sPanel1: TsPanel;
    sPageControl2: TsPageControl;
    sTabSheet2: TsTabSheet;
    sLabel6: TsLabel;
    edCardId: TsEdit;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    edLastName: TsEdit;
    edAddress1: TsEdit;
    sLabel3: TsLabel;
    edAddress2: TsEdit;
    edZipcode: TsEdit;
    sLabel4: TsLabel;
    sLabel5: TsLabel;
    sLabel7: TsLabel;
    sPanel2: TsPanel;
    sLabel8: TsLabel;
    sLabel10: TsLabel;
    cbxGuaranteeTypes: TsComboBox;
    pgGuaranteeTypes: TsPageControl;
    sTabSheet3: TsTabSheet;
    sTabSheet4: TsTabSheet;
    sLabel15: TsLabel;
    edDateOfBirth: TsDateEdit;
    sLabel16: TsLabel;
    edAmount: TsCalcEdit;
    sTabSheet5: TsTabSheet;
    cbCreditCard: TsCheckBox;
    panBtn: TsPanel;
    btnCancel: TsButton;
    BtnOk: TsButton;
    sButton2: TsButton;
    sLabel9: TsLabel;
    edCity: TsEdit;
    sLabel11: TsLabel;
    sLabel12: TsLabel;
    sLabel13: TsLabel;
    edTel1: TsEdit;
    sLabel14: TsLabel;
    edEmail: TsEdit;
    sLabel17: TsLabel;
    edMobile: TsEdit;
    sLabel18: TsLabel;
    sLabel19: TsLabel;
    sLabel20: TsLabel;
    sLabel21: TsLabel;
    sTabSheet6: TsTabSheet;
    sLabel22: TsLabel;
    sLabel23: TsLabel;
    edCompany: TsEdit;
    sLabel24: TsLabel;
    sLabel25: TsLabel;
    edCompAddress1: TsEdit;
    edCompAddress2: TsEdit;
    edCompZipcode: TsEdit;
    sLabel26: TsLabel;
    sLabel27: TsLabel;
    edCompCity: TsEdit;
    sLabel28: TsLabel;
    sLabel29: TsLabel;
    edCompEmail: TsEdit;
    sLabel30: TsLabel;
    sLabel31: TsLabel;
    edCompTelNumber: TsEdit;
    sButton5: TsButton;
    lbPayment: TsLabel;
    rptForm: TfrxReport;
    fdRegFormDesigner: TfrxDesigner;
    sLabel32: TsLabel;
    edTitle: TsEdit;
    sLabel33: TsLabel;
    lbRoomRent: TsLabel;
    sLabel35: TsLabel;
    sLabel36: TsLabel;
    lbSales: TsLabel;
    sLabel38: TsLabel;
    lbSubTotal: TsLabel;
    Shape1: TShape;
    sLabel40: TsLabel;
    lbPAyments: TsLabel;
    Shape2: TShape;
    sLabel42: TsLabel;
    lbBalance: TsLabel;
    sLabel44: TsLabel;
    sButton6: TsButton;
    btnPortfolio: TsButton;
    btNoPortfolio: TsButton;
    shpFirstname: TShape;
    shpLastname: TShape;
    shpCity: TShape;
    shpCountry: TShape;
    shpGuarantee: TShape;
    shpCC: TShape;
    shpCash: TShape;
    edFirstname: TRoomerFilterComboBox;
    edSSN: TsEdit;
    sLabel34: TsLabel;
    sLabel37: TsLabel;
    edFax: TsEdit;
    sLabel39: TsLabel;
    edVAT: TsEdit;
    cbActiveLiveSearch: TsCheckBox;
    sLabel41: TsLabel;
    lbTaxes: TsLabel;
    pnlHidePayment: TsPanel;
    lblMarket: TsLabel;
    cbxMarket: TsComboBox;
    shpMarket: TShape;
    dsForm: TfrxDBDataset;
    chkCountryForAllGuests: TsCheckBox;
    shpNationality: TShape;
    fraNationality: TfraCountryPanel;
    fraCountry: TfraCountryPanel;
    fraCompCountry: TfraCountryPanel;
    cbPaycards: TsComboBox;
    btnManagePayCards: TsButton;
    chkNationalityForAllGuests: TsCheckBox;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure edLastNameChange(Sender: TObject);
    procedure cbCreditCardClick(Sender: TObject);
    procedure sButton5Click(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure sButton2Click(Sender: TObject);
    procedure sButton6Click(Sender: TObject);
    procedure btnPortfolioClick(Sender: TObject);
    procedure btNoPortfolioClick(Sender: TObject);
    procedure edFirstnameCloseUp(Sender: TObject);
    procedure edFirstnameKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure cbActiveLiveSearchClick(Sender: TObject);
    procedure cbxMarketChange(Sender: TObject);
    procedure cbxMarketKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    function fdRegFormDesignerSaveReport(Report: TfrxReport; SaveAs: Boolean): Boolean;
    procedure btnManagePayCardsClick(Sender: TObject);
    procedure cbPaycardsCloseUp(Sender: TObject);
    procedure cbPaycardsChange(Sender: TObject);
    procedure cbxGuaranteeTypesChange(Sender: TObject);
  private
    FisCheckIn: Boolean;
    FCurrentRealBalance: Double;
    ResSetGuest: TRoomerDataSet;
    rec: recDownPayment;
    theDownPaymentData: recPaymentHolder;
    FInvoiceCurrency: TCurrencyDefinition;

    procedure Prepare;
    procedure UpdateControls;
    procedure FormDesignMode;
    procedure SetIsCheckIn(const Value: Boolean);
    procedure FillQuickFind;
    function GetGuestInfoRSet(aRSet: TROomerDataset; aRoomReservation: integer; const  aRoomNumberList: string=''): boolean;
    procedure CheckMandatoryFields;
    procedure SetShapeStatus(Tag : Integer; VisibleStatus: Boolean);
    function AnyTShapeVisible: Boolean;
    procedure UpdateGuaranteeTags;
    procedure Changed(Sender: TObject);
    function GetTotalTaxesForRoomreservation(aReservation, aRoomReservation: integer): double;
    procedure LoadPaycardInfo(aSelectTokenId: integer);
    { Private declarations }
  public
    { Public declarations }
    Reservation, RoomReservation: Integer;
    PersonId: Integer;
    Customer: String;
    tokens : TObjectList<TToken>;
    procedure WndProc(var message: TMessage); override;
    procedure SaveGuestInfo;

    procedure LoadGuestInfo;
    procedure PrintReport;
    procedure PrintReportForRoomList(const aRoomList: string);
    procedure Release;

    property isCheckIn: Boolean read FisCheckIn write SetIsCheckIn;
  end;

function OpenGuestCheckInForm(_RoomReservation: Integer; GuestCheckin: Boolean = True): Boolean;
function PrintRegistrationForm(_RoomReservations: IntegerArray): Boolean;

const
//  GET_RESERVATION_CHECKIN_CHECKOUT = 'SELECT * FROM reservations WHERE Reservation=(SELECT Reservation FROM roomreservations WHERE RoomReservation=%d)';

  GET_GUEST_CHECKIN_CHECKOUT = 'SELECT ID, title, Reservation, (SELECT NativeCurrency FROM control LIMIT 1) AS NativeCurrency, ' +
    '(SELECT Customer FROM reservations WHERE Reservation=persons.Reservation) AS Customer, ' +
    '(SELECT PAYCARD_TOKEN_ID FROM roomreservations WHERE RoomReservation=persons.RoomReservation) AS PAYCARD_TOKEN_ID, ' +
    '(SELECT Currency FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS Currency, ' +
    '(SELECT market from reservations WHERE Reservation=persons.Reservation) AS Market, ' +
    '(SELECT roomtype from roomreservations WHERE roomReservation=persons.roomReservation LIMIT 1) AS Roomtype, ' +
    '(SELECT Description from roomtypes WHERE roomtype = (SELECT Roomtype from roomreservations WHERE roomReservation=persons.roomReservation LIMIT 1)) AS RoomtypeDescription, ' +
    '(SELECT Avalue FROM currencies WHERE Currency=(SELECT Currency FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) LIMIT 1) AS CurrencyRate, '
    +

    '(SELECT CCMaskedCreditCard FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS MaskedCreditCard, ' +
    '(SELECT CCExpiry FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS CreditCardExpiry, ' +
    '(SELECT CCNameOnCard FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS NameOnCreditCard, ' +
    '(SELECT CCCardType FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS CreditCardType, ' +

    '(SELECT PaymentGuaranteeType FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS PaymentGuaranteeType, ' +
    '(SELECT Status FROM roomreservations WHERE RoomReservation=persons.RoomReservation LIMIT 1) AS ResStatus, ' +

    '(SELECT AVG(RoomRate - IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X''))) AS AverageRoomRate, '
    + '(SELECT SUM(RoomRate - IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X''))) AS TotalPrice, '
    + 'DATE((SELECT ADate FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')) ORDER BY ADate LIMIT 1)) AS Arrival, ' +
    'DATE_ADD(DATE((SELECT ADate FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')) ORDER BY ADate DESC LIMIT 1)), INTERVAL 1 DAY) AS Departure, ' +
    'DATEDIFF(DATE_ADD(DATE((SELECT ADate FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')) ORDER BY ADate DESC LIMIT 1)), INTERVAL 1 DAY), ' +
    'DATE((SELECT ADate FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')) ORDER BY ADate LIMIT 1))) AS Nights, ' +
    '(SELECT COUNT(ID) FROM persons p1 WHERE RoomReservation=persons.RoomReservation) AS NumberOfGuests, ' +
    '(SELECT Room FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')) LIMIT 1) AS RoomNumber, ' +

    'IF(ISNULL((SELECT SUM((Price - (Price*IF(Discount_IsPrecent,Discount/100,Discount)))*Number) FROM invoicelines WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)), 0, '
    + '  (SELECT SUM((Price - (Price*IF(Discount_IsPrecent,Discount/100,Discount)))*Number) FROM invoicelines WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)) AS CurrentSales, '
    + 'IF(ISNULL((SELECT SUM(Amount) FROM payments WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)), 0, '
    + '  (SELECT SUM(Amount) FROM payments WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)) AS CurrentPayments, '
    +

    'IF(ISNULL((SELECT SUM(RoomRate - IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')))), 0, ' +
    '  (SELECT SUM(RoomRate - IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE RoomReservation=persons.RoomReservation AND (NOT ResFlag In (''C'',''X'')))) + ' +
    'IF(ISNULL((SELECT SUM((Price - (Price*IF(Discount_IsPrecent,Discount/100,Discount)))*Number) FROM invoicelines WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)), 0, '
    + '  (SELECT SUM((Price - (Price*IF(Discount_IsPrecent,Discount/100,Discount)))*Number) FROM invoicelines WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)) - '
    + 'IF(ISNULL((SELECT SUM(Amount) FROM payments WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)), 0, '
    + '  (SELECT SUM(Amount) FROM payments WHERE RoomReservation=persons.RoomReservation AND Reservation=persons.Reservation AND InvoiceNumber=-1)) AS CurrentBalance, '
    +

    'Name AS FullName, ' + 'LEFT(Name, CHAR_LENGTH(Name) - CHAR_LENGTH(SUBSTRING_INDEX(Name,'' '',-1))-1) AS FirstName, ' +
    'SUBSTRING_INDEX(Name,'' '',-1) AS LastName, ' +
    'IF(Address1 != '''', Address1, (SELECT ContactAddress1 FROM reservations WHERE Reservation=persons.Reservation)) AS Address1, ' +
    'IF(Address2 != '''', Address2, (SELECT ContactAddress2 FROM reservations WHERE Reservation=persons.Reservation)) AS Address2, ' +
    'IF(Address3 != '''', Address3, (SELECT ContactAddress3 FROM reservations WHERE Reservation=persons.Reservation)) AS ZIPCode, ' +
    'IF(Address4 != '''', Address4, (SELECT ContactAddress4 FROM reservations WHERE Reservation=persons.Reservation)) AS City, ' +

    'Country, ' +

    'Tel1 AS Telephone, Tel2 AS MobileNumber, Email AS GuestEmail, ' +

    'Nationality, ' +

    'CompanyName, ' + 'CompAddress1, ' + 'CompAddress2, ' + 'CompZip, ' + 'CompCity, ' + 'CompCountry, ' + 'CompTel, ' + 'CompEmail, ' +

    'CompFax, ' + 'CompVATNumber, ' + 'SocialSecurityNumber, ' +
    'PersonsProfilesId, ' +

    '(SELECT CountryName FROM countries WHERE Country=persons.Country) AS CountryName, ' +
    '(SELECT CountryName FROM countries WHERE Country=persons.Nationality) AS NationalityName, ' +
    '(SELECT CountryName FROM countries WHERE Country=persons.CompCountry) AS CompCountryName, ' +


    'PersonalIdentificationId, ' + 'DateOfBirth ' + 'FROM persons ' + 'WHERE RoomReservation IN (%s) ' +
    'AND ID=(SELECT ID FROM persons pe WHERE pe.RoomReservation=persons.RoomReservation ORDER BY MainName DESC, ID LIMIT 1) ' + 'GROUP BY RoomReservation';

  PUT_GUEST_CHECKIN_CHECKOUT = 'UPDATE persons p, roomreservations r ' +
    ' SET Title=%s, ' + ' p.Name=%s, ' + '	p.Address1=%s, ' + '	p.Address2=%s, ' + '	p.Address3=%s, ' +
    '	p.Address4=%s, ' + '	p.Country=%s, ' +

    '	p.Tel1=%s, ' + '	p.Tel2=%s, ' + '	p.Email=%s, ' +

    ' p.Nationality=%s, ' +

    '	p.CompanyName=%s, ' + '	p.CompAddress1=%s, ' + '	p.CompAddress2=%s, ' + '	p.CompZip=%s, ' + '	p.CompCity=%s, ' + '	p.CompCountry=%s, ' +
    '	p.CompTel=%s, ' + '	p.CompEmail=%s, ' + ' p.PersonsProfilesId=%s, ' +

    ' p.CompFax=%s, ' + ' p.CompVATNumber=%s, ' + ' p.SocialSecurityNumber=%s, ' +

    '	p.PersonalIdentificationId=%s, ' + '	p.DateOfBirth=%s, ' + '	r.PaymentGuaranteeType=%s ' +
    'WHERE p.ID=%d AND r.RoomReservation=p.RoomReservation ';

  PUT_GUESTsCOUNTRY_CHECKIN_CHECKOUT = 'UPDATE persons p ' +
    ' SET p.Country=%s ' +
    ' WHERE p.roomreservation=%d AND Coalesce(p.Country, ''00'')=''00'' ';

  PUT_GUESTsNATIONALITY_CHECKIN_CHECKOUT = 'UPDATE persons p ' +
    ' SET p.Nationality=%s ' +
    ' WHERE p.roomreservation=%d AND coalesce(p.Nationality, ''0'')=''00'' ';

  UPDATE_PROFILE_FROM_PERSON = 'UPDATE persons pe ' +
                  'JOIN personprofiles pp ON pp.Id = pe.PersonsProfilesId ' +
                  'SET pp.title = pe.title, ' +
                  'pp.Firstname = LEFT(Name, CHAR_LENGTH(Name) - CHAR_LENGTH(SUBSTRING_INDEX(Name,'' '',-1))-1), ' +
                  'pp.Lastname = SUBSTRING_INDEX(Name,'' '',-1), ' +
                  'pp.Address1 = pe.Address1, ' +
                  'pp.Address2 = pe.Address2, ' +
                  'pp.Zip = pe.Address3, ' +
                  'pp.City = pe.Address4, ' +
                  'pp.Country = pe.Country, ' +
                  'pp.TelLandLine = pe.Tel1, ' +
                  'pp.TelMobile = pe.Tel2, ' +
                  'pp.TelFax = pe.Fax, ' +
                  'pp.Email = pe.Email, ' +
                  'pp.Information = pe.Information, ' +
                  'pp.Nationality = pe.Nationality, ' +
                  'pp.CustomerCode = pe.Customer, ' +
                  'pp.CompanyName = pe.CompanyName, ' +
                  'pp.CompAddress1 = pe.CompAddress1, ' +
                  'pp.CompAddress2 = pe.CompAddress2, ' +
                  'pp.CompZip = pe.CompZip, ' +
                  'pp.CompCity = pe.CompCity, ' +
                  'pp.CompCountry = pe.CompCountry, ' +
                  'pp.CompTel = pe.CompTel, ' +
                  'pp.CompEmail = pe.CompEmail, ' +
                  'pp.state = pe.state, ' +
                  'pp.DateOfBirth = pe.DateOfBirth, ' +
                  'pp.CompFax=pe.CompFax, ' +
                  'pp.CompVATNumber=pe.CompVATNumber, ' +
                  'pp.PassportNumber=pe.PersonalIdentificationId, ' +
                  'pp.SocialSecurityNumber=pe.SocialSecurityNumber ' +

                  'WHERE pe.MainName=1 AND pe.RoomReservation=%d';

implementation

{$R *.dfm}

uses uRoomerLanguage,
  uAppGlobal,
  uD,
  uDateUtils,
  uCountries,
  _Glob,
  uUtils,
  PrjConst,
  uFileDependencyManager,
  uGuestProfiles,
  uStringUtils,
  uTaxCalc,
  DateUtils,
  uRoomerDefinitions,
  uInvoiceContainer,
  uMandatoryFieldDefinitions
  , uSQLUtils
  , uBookingsTaxesAPICaller
  , uRoomerBookingDataModel_ModelObjects
  , uRoomerCanonicalDataModel_SimpleTypes
  , uFrmTokenChargeHistory
  , uMarketDefinitions, uRoomerCurrencymanager, uAmount, uCurrencyConstants;

const
  WM_SET_COMBO_TEXT = WM_User + 101;

function OpenGuestCheckInForm(_RoomReservation: Integer; GuestCheckin: Boolean = True): Boolean;
var
  _FrmGuestCheckInForm: TFrmGuestCheckInForm;
begin
  result := false;
  _FrmGuestCheckInForm := TFrmGuestCheckInForm.Create(nil);
  with _FrmGuestCheckInForm do
    try
      _FrmGuestCheckInForm.RoomReservation := _RoomReservation;
      _FrmGuestCheckInForm.isCheckIn := GuestCheckin;
      if NOT GuestCheckin then
        _FrmGuestCheckInForm.Caption := GetTranslatedText('shUI_GuestDetailsDialog');
      ShowModal;
      if modalresult = mrOk then
      begin
        SaveGuestInfo;
        result := True;
      end;
    finally
      freeandnil(_FrmGuestCheckInForm);
    end;
end;

function PrintRegistrationForm(_RoomReservations: IntegerArray): Boolean;
var
  i: Integer;
  sRoomResList: String;
  lForm: TFrmGuestCheckInForm;
begin
  result := false;
  lForm := TFrmGuestCheckInForm.Create(nil);
  try
    sRoomResList := '';
    for i := Low(_RoomReservations) to High(_RoomReservations) do
      if sRoomResList = '' then
        sRoomResList := inttostr(_RoomReservations[i])
      else
        sRoomResList := sRoomResList + ',' + inttostr(_RoomReservations[i]);

      lForm.PrintReportForRoomList(sRoomResList);
  finally
    lForm.Free;
  end;
end;

procedure TFrmGuestCheckInForm.cbCreditCardClick(Sender: TObject);
begin
  UpdateControls;
end;


procedure TFrmGuestCheckInForm.cbPaycardsChange(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.cbPaycardsCloseUp(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.UpdateGuaranteeTags;
begin
  if cbxGuaranteeTypes.ItemIndex = 1 then
  begin
    shpCash.Tag := mfGuarantee.AsTagid;
    edAmount.Tag := mfGuarantee.AsTagid;
  end else
  begin
    shpCash.Tag := 0;
    edAmount.Tag := 0;
  end;
  if (cbxGuaranteeTypes.ItemIndex = 0) and (cbPaycards.ItemIndex > 0) then
  begin
    shpCC.Tag := mfGuarantee.AsTagid;
    cbPaycards.Tag := mfGuarantee.AsTagid;
    cbCreditCard.Tag := 0;
  end else
  begin
    shpCC.Tag := mfGuarantee.AsTagid;
    cbPaycards.Tag := 0;
    cbCreditCard.Tag := mfGuarantee.AsTagid;
  end;
end;

procedure TFrmGuestCheckInForm.cbxGuaranteeTypesChange(Sender: TObject);
begin
  pgGuaranteeTypes.ActivePageIndex := cbxGuaranteeTypes.ItemIndex;

  UpdateGuaranteeTags;
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.cbxMarketChange(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.cbxMarketKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_DELETE then
  begin
    cbxMarket.ItemIndex := -1;
    UpdateControls;
  end;
end;

procedure TFrmGuestCheckInForm.FillQuickFind;
var
  rSet: TRoomerDataSet;

  function getFullname: String;
  begin
    result := Trim(rSet['FirstName'] + ' ' + rSet['Lastname']);
  end;

  function getField(fName: String): String;
  var
    s: String;
  begin
    s := rSet[fName];
    if s = '' then
      result := ''
    else
      result := ', ' + s;
  end;

var
  item: TRoomerFilterItem;

begin
  rSet := glb.PersonProfiles;
  edFirstname.StoredItems.Clear;
  rSet.First;
  while NOT rSet.Eof do
  begin
    item := TRoomerFilterItem.Create;
    item.Key := inttostr(rSet['ID']);
    item.Line := format('%s%s%s%s', [getFullname, getField('City'), getField('Country'), getField('Address1')]);
    edFirstname.StoredItems.Add(item);
    rSet.Next;
  end;

  if Assigned(glb.PreviousGuestsSet) then
  begin
    rSet := glb.PreviousGuestsSet;
    rSet.First;
    while NOT rSet.Eof do
    begin
      item := TRoomerFilterItem.Create;
      item.Key := rSet['ID'];
      item.Line := format('%s%s%s%s', [rSet['Name'], getField('Address4'), getField('Country'), getField('Address1')]);
      edFirstname.StoredItems.Add(item);
      rSet.Next;
    end;
  end;

  cbActiveLiveSearch.Checked := false;
  cbActiveLiveSearchClick(cbActiveLiveSearch);
  // if edFirstname.StoredItems.Count > 0 then
  // edFirstname.Start;
end;

procedure TFrmGuestCheckInForm.WndProc(var message: TMessage);
var
  s, s1: String;
begin
  inherited;
  if message.Msg = WM_SET_COMBO_TEXT then
  begin
    if message.WParam = 1 then
    begin
      if Assigned(glb.PreviousGuestsSet) then
      begin
        parseFirstAndLastNameFromFullname(glb.PreviousGuestsSet['Name'], s, s1);
        edFirstname.Text := Trim(s);
        edLastName.Text := Trim(s1);
        edTitle.Text := glb.PreviousGuestsSet['title'];
        edSSN.Text := glb.PreviousGuestsSet['SocialSecurityNumber'];
        edVAT.Text := glb.PreviousGuestsSet['CompVATNumber'];
        edFax.Text := glb.PreviousGuestsSet['CompFax'];
        edAddress1.Text := glb.PreviousGuestsSet['Address1'];
        edAddress2.Text := glb.PreviousGuestsSet['Address2'];
        edZipcode.Text := glb.PreviousGuestsSet['Address3'];
        edCity.Text := glb.PreviousGuestsSet['Address4'];
        fraCountry.Code := glb.PreviousGuestsSet['Country'];
        edTel1.Text := glb.PreviousGuestsSet['Tel1'];
        edMobile.Text := glb.PreviousGuestsSet['Tel2'];
        edEmail.Text := glb.PreviousGuestsSet['Email'];
        edCardId.Text := ResSetGuest['PassPortNumber'];

        if edCity.Text = '' then
          try edCity.Text := glb.PersonProfiles['City']; except end;
      end;
    end
    else
    begin
      btnPortfolio.Tag := glb.PersonProfiles['Id'];
      edFirstname.Text := Trim(glb.PersonProfiles['Firstname']);
      edLastName.Text := Trim(glb.PersonProfiles['Lastname']);

      edTitle.Text := glb.PersonProfiles['title'];
      edSSN.Text := glb.PersonProfiles['SocialSecurityNumber'];
      edVAT.Text := glb.PersonProfiles['CompVATNumber'];
      edFax.Text := glb.PersonProfiles['CompFax'];

      edCardId.Text := glb.PersonProfiles['PassportNumber'];

      edAddress1.Text := glb.PersonProfiles['Address1'];
      edAddress2.Text := glb.PersonProfiles['Address2'];
      edZipcode.Text := glb.PersonProfiles['Zip'];
      edCity.Text := glb.PersonProfiles['City'];
      fraCountry.Code := glb.PersonProfiles['Country'];
      edTel1.Text := glb.PersonProfiles['TelLandLine'];
      edMobile.Text := glb.PersonProfiles['TelMobile'];
      edEmail.Text := glb.PersonProfiles['Email'];

      if edCity.Text = '' then
        try edCity.Text := glb.PreviousGuestsSet['Address4']; except end;
    end;

    if fraCountry.Code = '' then
      fraCountry.Code := glb.PersonProfiles['Country'];

  end;
end;

procedure TFrmGuestCheckInForm.edFirstnameCloseUp(Sender: TObject);
var
  Key: String;
begin
  if edFirstname.Items.IndexOf(edFirstname.Text) >= 0 then
  begin
    Key := TRoomerFilterItem(edFirstname.Items.Objects[edFirstname.ItemIndex]).Key; // edContactPerson.FKeys[idx];
    if Assigned(glb.PreviousGuestsSet) AND glb.LocateSpecificRecord(glb.PreviousGuestsSet, 'ID', Key) then
    begin
      postMessage(handle, WM_SET_COMBO_TEXT, 1, 0);
    end
    else if glb.LocateSpecificRecord(glb.PersonProfiles, 'ID', Key) then
    begin
      postMessage(handle, WM_SET_COMBO_TEXT, 2, 0);
    end;
  end;
end;

procedure TFrmGuestCheckInForm.edFirstnameKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if (Key IN [VK_RETURN, VK_TAB]) AND (edFirstname.Items.IndexOf(edFirstname.Text) < 0) then
  begin
    ActiveControl := edLastName;
  end;
end;

procedure TFrmGuestCheckInForm.edLastNameChange(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.UpdateControls;
begin
  cbCreditCard.Visible := (cbPaycards.ItemIndex = 0);
  sLabel12.Visible := (cbPaycards.ItemIndex = 0);

  CheckMandatoryFields;

  // Overriden by 3P connection? (Amsterdam Gemeente)
  if g.qStayd3pActive then
  begin
    shpMarket.Visible := (cbxMarket.ItemIndex < 0);
  end;


  BtnOk.Enabled := Not isCheckIn or NOT AnyTShapeVisible;
end;

procedure TFrmGuestCheckInForm.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  fraNationality.OnChange := Changed;
  fraNationality.RejectedCodes := '00';

  fraCountry.OnChange := Changed;
  fraCountry.RejectedCodes := '00';

  tokens := TObjectList<TToken>.Create;
  Prepare;

end;

procedure TFrmGuestCheckInForm.Changed(Sender: TObject);
begin
  UpdateControls;
end;

procedure TFrmGuestCheckInForm.FormDestroy(Sender: TObject);
begin
  tokens.Free;
  Release;
end;

procedure TFrmGuestCheckInForm.Release;
begin
  freeandnil(ResSetGuest);
end;

function TFrmGuestCheckInForm.GetGuestInfoRSet(aRSet: TROomerDataset; aRoomReservation: integer; const  aRoomNumberList: string=''): boolean;
var
  lRoomnumbersList: String;
  sql: string;
begin
  if aRoomNumberList = '' then
    lRoomnumbersList := inttostr(aRoomReservation)
  else
    lRoomnumbersList := aRoomNumberList;

  sql := format(GET_GUEST_CHECKIN_CHECKOUT, [lRoomnumbersList]);
  CopyToClipboard(sql);
  aRSet.Close;
  Result := rSet_bySQL(aRSet, sql);
end;

function TFrmGuestCheckInForm.GetTotalTaxesForRoomreservation(aReservation: integer; aRoomReservation: integer): double;
var
  lResponse: TxsdRoomRentTaxReceiptList;
  lCaller: TBookingsTaxesTabAPICaller;
  lCityTaxAmount: TAmount;
begin
  Result := 0.00;
  lResponse := nil;
  lCaller := TBookingsTaxesTabAPICaller.Create;
  try
    lResponse := TxsdRoomRentTaxReceiptList.Create;
    if lCaller.GetRoomReservationTaxes(aReservation, aRoomReservation, lResponse) then
    begin
      lCityTaxAmount := TAmount.Create(lResponse.TotalCityTax.Amount, lResponse.TotalCityTax.Currency.AsString);
      Result := RoomerCurrencyManager.ConvertAmount(lCityTaxAmount, FInvoiceCurrency.CurrencyCode);
    end;
  finally
    lResponse.Free;
    lCaller.Free;
  end;

end;

procedure TFrmGuestCheckInForm.LoadPaycardInfo(aSelectTokenId: integer);
begin
  LoadAllTokens(Reservation, RoomReservation, tokens);
  FillTokenComboBox(cbPaycards, tokens, aSelectTokenId);
end;

procedure TFrmGuestCheckInForm.LoadGuestInfo;
var
  lRoomInvoice: TInvoice;
begin
  if GetGuestInfoRSet(ResSetGuest, RoomReservation) then
  begin
    Reservation := ResSetGuest['Reservation'];

    lRoomInvoice := TInvoice.Create(ritRoom, -1, Reservation, RoomReservation, 0, -1, ResSetGuest['RoomNumber'], false);
    try
      LoadPayCardInfo(ResSetGuest['PAYCARD_TOKEN_ID']);
      PersonId := ResSetGuest['ID'];
      Customer := ResSetGuest['Customer'];

      FInvoiceCurrency := RoomerCurrencymanager[lRoomInvoice.Currency]; // RoomerCurrencymanager[ResSetGuest['Currency']];

      sTabSheet1.Caption := GetTranslatedText('shTx_RoomEdit_Room') + ResSetGuest['RoomNumber'];

      lbRoomRent.Caption :=  FInvoiceCurrency.FormattedValue(lRoomInvoice.TotalRoomRent); //Trim(_floatToStr(ResSetGuest['TotalPrice'], 12, 2));
      lbSales.Caption := FInvoiceCurrency.FormattedValue(lRoomInvoice.TotalSales); //Trim(_floatToStr(ResSetGuest['CurrentSales'], 12, 2));
      lbSubTotal.Caption := FInvoiceCurrency.FormattedValue(lRoomInvoice.TotalRoomRent
                                                             + lRoomInvoice.TotalSales
                                                             + lRoomInvoice.TotalTaxes); // Trim(_floatToStr(ResSetGuest['TotalPrice'] + ResSetGuest['CurrentSales'], 12, 2));
      lbPAyments.Caption := FInvoiceCurrency.FormattedValue(lRoomInvoice.TotalPayments); //Trim(_floatToStr(ResSetGuest['CurrentPayments'], 12, 2));

      if glb.PMSSettings.BetaFunctionality.UseNewTaxcalcMethod then
        lbTaxes.Caption := FInvoiceCurrency.FormattedValue(GetTotalTaxesForRoomreservation(Reservation, RoomReservation))
      else
        lbTaxes.Caption := FInvoiceCurrency.FormattedValue(lRoomInvoice.TotalTaxes); //Trim(_floatToStr(ExtraTaxes, 12, 2));

      lbBalance.Caption := FInvoiceCurrency.FormattedValue(lRoomInvoice.Balance);// Trim(_floatToStr(CurrentRealBalance, 12, 2));
      FCurrentRealBalance := lRoomInvoice.balance;

      edFax.Text := ResSetGuest['CompFax'];
      edVAT.Text := ResSetGuest['CompVATNumber'];
      edSSN.Text := ResSetGuest['SocialSecurityNumber'];

      edCardId.Text := ResSetGuest['PersonalIdentificationId'];
      btnPortfolio.Tag := ResSetGuest['PersonsProfilesId'];
      edTitle.Text := ResSetGuest['title'];
      edFirstname.Text := ResSetGuest['FirstName'];
      edLastName.Text := ResSetGuest['LastName'];
      edAddress1.Text := ResSetGuest['Address1'];
      edAddress2.Text := ResSetGuest['Address2'];
      edZipcode.Text := ResSetGuest['ZIPCode'];
      edCity.Text := ResSetGuest['City'];
      fraCountry.Code := ResSetGuest['Country'];

      edTel1.Text := ResSetGuest['Telephone'];
      edMobile.Text := ResSetGuest['MobileNumber'];
      edEmail.Text := ResSetGuest['GuestEmail'];

      fraNationality.Code := ResSetGuest['Nationality'];

      cbxMarket.ItemIndex := TReservationMarketType.FromDBString(ResSetGuest['market'], TReservationMarketType.mtUnknown).ToItemIndex;

      edCompany.Text := ResSetGuest['CompanyName'];
      edCompAddress1.Text := ResSetGuest['CompAddress1'];
      edCompAddress2.Text := ResSetGuest['CompAddress2'];
      edCompZipcode.Text := ResSetGuest['CompZip'];
      edCompCity.Text := ResSetGuest['CompCity'];
      fraCompCountry.Code := ResSetGuest['CompCountry'];
      edCompTelNumber.Text := ResSetGuest['CompTel'];
      edCompEmail.Text := ResSetGuest['CompEmail'];

      edDateOfBirth.Date := ResSetGuest['DateOfBirth'];

      cbxGuaranteeTypes.ItemIndex := IndexOfArray(PAYMENT_GUARANTEE_TYPE, ResSetGuest['PaymentGuaranteeType'], 3);
//      cbxGuaranteeTypesCloseUp(cbxGuaranteeTypes);
      case cbxGuaranteeTypes.ItemIndex of
        0:
          cbCreditCard.Checked := (ResSetGuest['ResStatus'] = 'G') OR (ResSetGuest['ResStatus'] = 'D');
        1:
          begin
            pnlHidePayment.Visible := (ResSetGuest['ResStatus'] = 'G') OR (ResSetGuest['ResStatus'] = 'D');
            if pnlHidePayment.Visible then
              pnlHidePayment.Align := alClient;
          end;
        2:
          ;
      end;

    finally
      lRoomInvoice.Free;
    end;
  end;

  UpdateControls;
end;

procedure TFrmGuestCheckInForm.SaveGuestInfo;
var
  s: String;
  NewId: Integer;
  lExecPlan: TRoomerExecutionPlan;
begin
  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

    s := format(PUT_GUEST_CHECKIN_CHECKOUT, [_DB(edTitle.Text), _DB(Trim(edFirstname.Text + ' ' + edLastName.Text)), _DB(edAddress1.Text), _DB(edAddress2.Text),
      _DB(edZipcode.Text), _DB(edCity.Text), _DB(fraCountry.Code),

      _DB(edTel1.Text), _DB(edMobile.Text), _DB(edEmail.Text),

      _DB(fraNationality.Code),

      _DB(edCompany.Text), _DB(edCompAddress1.Text), _DB(edCompAddress2.Text), _DB(edCompZipcode.Text), _DB(edCompCity.Text), _DB(fraCompCountry.Code),
      _DB(edCompTelNumber.Text), _DB(edCompEmail.Text), _DB(inttostr(btnPortfolio.Tag)),

      _DB(edFax.Text), _DB(edVAT.Text), _DB(edSSN.Text),

      _DB(edCardId.Text), _DB(uDateUtils.dateToSqlString(edDateOfBirth.Date)),

      _DB(PAYMENT_GUARANTEE_TYPE[cbxGuaranteeTypes.ItemIndex]), PersonId]);


    CopyToClipboard(s);
    lExecPlan.AddExec(s);

    s := format(UPDATE_PROFILE_FROM_PERSON, [RoomReservation]);
    CopyToClipboard(s);
    lExecPlan.AddExec(s);


    if chkCountryForAllGuests.Checked then
    begin
      s := format(PUT_GUESTsCOUNTRY_CHECKIN_CHECKOUT, [_db(fraCountry.Code), RoomReservation]);
      CopyToClipboard(s);
      lExecPlan.AddExec(s);
    end;

    if chkNationalityForAllGuests.Checked then
    begin
      s := format(PUT_GUESTsNATIONALITY_CHECKIN_CHECKOUT, [_db(fraNationality.Code), RoomReservation]);
      CopyToClipboard(s);
      lExecPlan.AddExec(s);
    end;

    d.roomerMainDataSet.SystemStartTransaction;
    try
      if not lExecPlan.Execute(ptAll) then
        raise Exception.CreateFmt('Unable to save checkin data. Message: [%s]', [lExecPLan.ExecException]);

      d.UpdateReservationMarket(Reservation, TReservationmarketType(cbxMarket.itemIndex));

      if (cbxGuaranteeTypes.ItemIndex = 1) AND (edAmount.Value <> 0) and not theDownPaymentData.IsStored then
      begin
        NewId := 0;
        if NOT INS_Payment(theDownPaymentData, NewId) then
          raise Exception.Create('Unable to save down-payment.');
      end;

      d.roomerMainDataSet.SystemCommitTransaction;
    except
      d.roomerMainDataSet.SystemRollbackTransaction;
    end;

  finally
    lExecPlan.Free;
  end;
end;

procedure TFrmGuestCheckInForm.btnManagePayCardsClick(Sender: TObject);
var currIdx : Integer;
begin
  currIdx := cbPayCards.ItemIndex;
  ManagePaymentCards(Reservation, RoomReservation);
  LoadAllTokens(Reservation, RoomReservation, tokens);
  FillTokenComboBox(cbPaycards, tokens, -1);
  cbPayCards.ItemIndex := currIdx;
end;

procedure TFrmGuestCheckInForm.sButton2Click(Sender: TObject);
begin
  SaveGuestInfo;
  if GetGuestInfoRSet(ResSetGuest, Roomreservation, '') then
    PrintReport;
end;

procedure TFrmGuestCheckInForm.PrintReportForRoomList(const aRoomList: string);
begin
  if GetGuestInfoRSet(ResSetGuest, Roomreservation, aRoomList) then
    PrintReport;
end;

procedure TFrmGuestCheckInForm.PrintReport;
begin
  dsForm.DataSet := ResSetGuest;
  dsForm.Open;
  rptForm.DataSets.Add(dsForm);
  try
    rptForm.LoadFromFile(FileDependencyManager.getRegistrationFormFilePath);
    rptForm.PrepareReport(True);
    rptForm.Print;
  finally
    rptForm.DataSets.Clear;
  end;
end;

procedure TFrmGuestCheckInForm.sButton5Click(Sender: TObject);
var
  Rate: double;
begin
  g.initRecDownPayment(rec);

  rec.Reservation := Reservation;
  rec.RoomReservation := RoomReservation;
  rec.Description := GetTranslatedText('shTx_CheckIn_PaymentGuarantee_Downpayment');
  rec.Invoice := -1;
  rec.AmountInCurrency := 0;

  rec.InvoiceBalanceInCurrency := FCurrentRealBalance; // ResSetGuest['CurrentBalance'];
  rec.NotInvoice := True;

  if g.OpenDownPayment(actInsert, true, rec) then
  begin
    lbPayment.Caption := rec.PaymentType;
    rate := GetRate(rec.Currency);
    edAmount.Value:= rec.AmountInCurrency * Rate;

    theDownPaymentData.Reservation := Reservation;
    theDownPaymentData.RoomReservation := RoomReservation;
    theDownPaymentData.Person := 0;
    theDownPaymentData.TypeIndex := ORD(ptDownPayment);
    theDownPaymentData.invoiceNumber := -1;
    theDownPaymentData.Customer := Customer;
    theDownPaymentData.PayDate := _db(now, false);
    theDownPaymentData.NativeAmount := rec.AmountInCurrency * Rate;
    theDownPaymentData.Description := rec.Description;
    theDownPaymentData.CurrencyRate := 1.00; // ATH
    theDownPaymentData.Currency := RoomerCurrencyManager.DefaultCurrency;
    theDownPaymentData.confirmDate := 2; // _db('1900-01-01 00:00:00');
    theDownPaymentData.Notes := rec.Notes;
    theDownPaymentData.PayType := rec.PaymentType;
    theDownPaymentData.staff := d.roomerMainDataSet.username;
    theDownPaymentData.AutoGen := CreateAGUID;
    theDownPaymentData.Ayear := YearOf(now);
    theDownPaymentData.Amon := MonthOf(now);
    theDownPaymentData.Aday := DayOf(now);
    theDownPaymentData.IsStored:= rec.IsStored;
  end;

end;

procedure TFrmGuestCheckInForm.sButton6Click(Sender: TObject);
begin
  FormDesignMode;
end;

procedure TFrmGuestCheckInForm.cbActiveLiveSearchClick(Sender: TObject);
begin
  if TsCheckBox(Sender).Checked AND (edFirstname.StoredItems.Count > 0) then
    edFirstname.Start
  else
    edFirstname.Stop;
end;

procedure TFrmGuestCheckInForm.SetIsCheckIn(const Value: Boolean);
begin
  FisCheckIn := Value;
  if NOT Value then
  begin
    shpGuarantee.Brush.Color := clBlue;
    shpCC.Brush.Color := clBlue;
    shpCash.Brush.Color := clBlue;
    shpGuarantee.Pen.Color := clBlue;
    shpCC.Pen.Color := clBlue;
    shpCash.Pen.Color := clBlue;
  end;
end;

procedure TFrmGuestCheckInForm.btNoPortfolioClick(Sender: TObject);
begin
  btnPortfolio.Tag := 0;

  btNoPortfolio.Visible := false;
  edCardId.Text := ''; // glb.PersonProfiles['PassportNumber'];

  edTitle.Text := '';
  edFirstname.Text := '';
  edLastName.Text := '';

  fraNationality.Code := '';

  edDateOfBirth.Date := 0;
  edTel1.Text := '';
  edMobile.Text := '';
  edEmail.Text := '';

  edAddress1.Text := '';
  edAddress2.Text := '';
  edZipcode.Text := '';
  edCity.Text := '';
  fraCountry.Code := '';

  edCompany.Text := '';
  edCompTelNumber.Text := '';
  edCompEmail.Text := '';

  edCompAddress1.Text := '';
  edCompAddress2.Text := '';
  edCompZipcode.Text := '';
  edCompCity.Text := '';
  fraCompCountry.Code := '';

  LoadGuestInfo;

end;

procedure TFrmGuestCheckInForm.btnPortfolioClick(Sender: TObject);
var
  iId: Integer;
begin
  iId := GuestProfiles(actLookup, btnPortfolio.Tag);
  if iId > 0 then
  begin
    if glb.LocateSpecificRecord('personprofiles', 'ID', inttostr(iId)) then
    begin
      btnPortfolio.Tag := iId;

      edCardId.Text := glb.PersonProfiles['PassportNumber'];

      edTitle.Text := glb.PersonProfiles['title'];
      edSSN.Text := glb.PersonProfiles['SocialSecurityNumber'];
      edFirstname.Text := glb.PersonProfiles['Firstname'];
      edLastName.Text := glb.PersonProfiles['LastName'];

      fraNationality.Code := glb.PersonProfiles['Nationality'];

      edDateOfBirth.Date := glb.PersonProfiles['DateOfBirth'];
      edTel1.Text := glb.PersonProfiles['TelLandLine'];
      edMobile.Text := glb.PersonProfiles['TelMobile'];
      edEmail.Text := glb.PersonProfiles['Email'];

      edAddress1.Text := glb.PersonProfiles['Address1'];
      edAddress2.Text := glb.PersonProfiles['Address2'];
      edZipcode.Text := glb.PersonProfiles['Zip'];
      edCity.Text := glb.PersonProfiles['City'];
      fraCountry.Code := glb.PersonProfiles['Country'];

      edCompany.Text := glb.PersonProfiles['CompanyName'];
      edVAT.Text := glb.PersonProfiles['CompVATNumber'];
      edCompTelNumber.Text := glb.PersonProfiles['CompTel'];
      edFax.Text := glb.PersonProfiles['CompFax'];
      edCompEmail.Text := glb.PersonProfiles['CompEmail'];

      edCompAddress1.Text := glb.PersonProfiles['CompAddress1'];
      edCompAddress2.Text := glb.PersonProfiles['CompAddress2'];
      edCompZipcode.Text := glb.PersonProfiles['CompZip'];
      edCompCity.Text := glb.PersonProfiles['CompCity'];
      fraCompCountry.Code  := glb.PersonProfiles['CompCountry'];

    end;
  end;

  btNoPortfolio.Visible := btnPortfolio.Tag > 0;
end;

procedure TFrmGuestCheckInForm.FormDesignMode;
var
  filename: String;
begin
  filename := FileDependencyManager.getRegistrationFormFilePath;
  dsForm.DataSet := ResSetGuest;
  dsForm.Open;
  rptForm.DataSets.Add(dsForm);
  try
    rptForm.LoadFromFile(filename);
    rptForm.DesignReport(True);
    FileDependencyManager.sendChangedFile(filename);
  finally
    rptForm.DataSets.Clear;
  end;
end;

procedure TFrmGuestCheckInForm.FormShow(Sender: TObject);
begin
  TReservationMarketType.AsStrings(cbxMarket.Items);

  LoadGuestInfo;
  FillQuickFind;
  cbxGuaranteeTypes.ItemIndex := 0;
  if cbPaycards.Items.Count > 1 then
    cbPayCards.ItemIndex := -1
  else
    cbPaycards.ItemIndex := 0;
  pgGuaranteeTypes.ActivePageIndex := 0;

  UpdateControls;
end;

function TFrmGuestCheckInForm.fdRegFormDesignerSaveReport(Report: TfrxReport; SaveAs: Boolean): Boolean;
begin
  if (not SaveAs) and Report.FileName.ToLower.Equals(FileDependencyManager.getRegistrationFormFilePath.ToLower) then
  begin
    Report.SaveToFile(Report.FileName);
    FileDependencyManager.sendChangedFile(Report.FileName);
    Result := true;
  end
  else
  begin
    Result := ((rptForm.Designer as TfrxDesignerForm) <> nil) and TfrxDesignerForm(rptForm.Designer).SaveFile(SaveAs, false);
    if Result and Report.FileName.ToLower.Equals(FileDependencyManager.getRegistrationFormFilePath.ToLower) then
      FileDependencyManager.sendChangedFile(Report.FileName);
  end;
end;

procedure TFrmGuestCheckInForm.Prepare;
var
  page: Integer;
begin
  for page := 0 to pgGuaranteeTypes.PageCount - 1 do
    pgGuaranteeTypes.Pages[page].TabVisible := false;
  cbxGuaranteeTypes.ItemIndex := 3;
  pgGuaranteeTypes.ActivePageIndex := cbxGuaranteeTypes.ItemIndex;
  ResSetGuest := CreateNewDataset;

  // Set tags for components that could be set as mandatory and for shapes that are made visible when component is not filled
  edFirstname.Tag := mfFirstName.AsTagId;
  shpFirstname.Tag := mfFirstName.AsTagId;

  edLastName.Tag := mfSurName.AsTagId;
  shpLastname.Tag := mfSurName.AsTagId;

  fraNationality.Tag := mfNationality.AsTagId;
  shpNationality.Tag := mfNationality.AsTagId;

  cbxMarket.Tag := mfMarket.AsTagid;
  shpMarket.Tag := mfMarket.AsTagid;

  edCity.Tag := mfCity.AsTagId;
  shpCity.Tag := mfCity.AsTagId;

  fraCountry.Tag := mfCountry.AsTagid;
  shpCountry.Tag := mfCountry.AsTagid;

  cbxGuaranteeTypes.Tag := mfGuarantee.AsTagId;
  shpGuarantee.Tag := mfGuarantee.AsTagId;

  UpdateGuaranteeTags;
end;

procedure TFrmGuestCheckInForm.CheckMandatoryFields;
var
  i: Integer;
  lGaranteed: boolean;
begin
  for i := 0 to ComponentCount - 1 do
  begin
      if (Components[i] is TWinControl) and (Components[i].Tag >= TMandatoryCheckinField.MinimumTagId) then
      begin
        if ((Components[i] IS TCustomEdit) AND ((Components[i] AS TCustomEdit).Text = '')) OR
           ((Components[i] IS TRoomerFilterComboBox) AND ((Components[i] AS TRoomerFilterComboBox).Text = '')) OR
           ((Components[i] IS TsCheckBox) AND (NOT (Components[i] AS TsCheckBox).Checked)) OR
           ((Components[i] IS TsComboBox) AND ((Components[i] AS TsComboBox).Showing AND ((Components[i] AS TsComboBox).Text = '') AND ((Components[i] AS TsComboBox).ItemIndex < 1))) OR
           ((Components[i] IS TfraCountryPanel) AND not (Components[i] as TfraCountryPanel).IsValid)
            then
             SetShapeStatus(Components[i].Tag, TMandatoryCheckinField.FromTagId(Components[i].Tag).IsCurrentlyOn)
        else
          SetShapeStatus(Components[i].Tag, False);
      end;

  end;

  // Special case for credit card garantee
  shpCC.Visible := False;
  if TMandatoryCheckinField.mfGuarantee.IsCurrentlyOn then
  begin
    case cbxGuaranteeTypes.ItemIndex of
      0:  begin //Credit card
            lGaranteed := ((cbPaycards.ItemIndex = 0) and cbCreditCard.Checked)
                         or (cbPayCards.ItemIndex > 0);
            shpCC.Visible := (cbPaycards.ItemIndex = 0) and not cbCreditCard.Checked;
          end;
      1:  begin //Down payment
            lGaranteed := edAmount.Value > 0;
          end;
      2:  lGaranteed := True;  //No guarantee provided
    else
          lGaranteed := False; // Nothing Selected
    end;
    shpGuarantee.Visible := not lGaranteed;
  end;
end;

procedure TFrmGuestCheckInForm.SetShapeStatus(Tag : Integer; VisibleStatus : Boolean);
var
  i: Integer;
begin
  for i := 0 to ComponentCount - 1 do
  begin
    if Components[i] IS TShape then
      if TShape(Components[i]).Tag = Tag then
        TShape(Components[i]).Visible :=  VisibleStatus OR
        ((Tag = TMandatoryCheckinField.mfNationality.AsTagid) AND d.HotelServicesSettings.HagstofaServiceSettings.HagstofaEnabled);
  end;
end;

function TFrmGuestCheckInForm.AnyTShapeVisible : Boolean;
var
  i: Integer;
begin
  result := False;
  for i := 0 to ComponentCount - 1 do
  begin
    if Components[i] IS TShape then
      if (TShape(Components[i]).Tag > 10) AND
         TShape(Components[i]).Visible then
      begin
        result := True;
        Break;
      end;
  end;
end;

end.
