unit uFinanceConnectService;

interface

uses
  UITypes
  , SysUtils
  , Classes
  , uD
  , Forms
  , Generics.Collections;

type
    TFinanceXmlListElements = record
      listName : String;
      rootName : String;
      codeName : String;
      descriptionName :String;

      constructor Create(list, root, code, description : String);
    end;

    TFinanceConnectSettings = record
      systemActive : Boolean;
      cashBalanceAccount,
      cashCode,
      companyGuid,
      hotelId,
      invoiceCode,
      officeCode,
      organizationId,
      password,
      receivableBalanceAccount,
      serviceUri,
      systemCode,
      usedCurrency,
      username,
      preceedingInvoiceNumber,
      succeedingInvoiceNumber,
      customersListUri,
      itemsListUri,
      vatListUri,
      payGroupsListUri,
      cashBooksListUri,
      systemName : String;

      constructor Create(_systemActive: Boolean;
                         _cashBalanceAccount,
                         _cashCode,
                         _companyGuid,
                         _hotelId,
                         _invoiceCode,
                         _officeCode,
                         _organizationId,
                         _password,
                         _receivableBalanceAccount,
                         _serviceUri,
                         _systemCode,
                         _usedCurrency,
                         _username,
                         _preceedingInvoiceNumber,
                         _succeedingInvoiceNumber,
                         _customersListUri,
                         _itemsListUri,
                         _vatListUri,
                         _payGroupsListUri,
                         _cashBooksListUri,
                         _systemName : String);
    end;

    TFinanceConnectService = class
    private
      CustomerXmlElements : TFinanceXmlListElements;
      ItemXmlElements : TFinanceXmlListElements;
      VatXmlElements : TFinanceXmlListElements;
      PayGroupsXmlElements : TFinanceXmlListElements;
      CashBooksXmlElements : TFinanceXmlListElements;

      SystemsXmlElements : TFinanceXmlListElements;

      MappingsXmlElements : TFinanceXmlListElements;

      procedure InitializeXmlElements;
    private
      FinanceConnectSettings : TFinanceConnectSettings;
    private
      procedure ParseList(XmlString: String; KeyPairList: TKeyPairList; XmlElements : TFinanceXmlListElements);
      procedure RetrieveFinanceConnectMappings;
      function ParseSettings(XmlString : String) : TFinanceConnectSettings;
    function RetrieveListForKeyPairAsString(url : String): String;
    public
      constructor Create;
      procedure PrepareForMapping;

      function SystemName: String;

      function RetrieveFinanceConnectKeypair(keyPairType: TKeyPairType): TKeyPairList;
      function RetrieveFinanceConnectAvailableSystems: TKeyPairList;
      procedure MapForFinanceConnect(keyPairType: TKeyPairType; RoomerCode, ExternalCode : String);
      function keyPairTypeByIndex(index : Integer) : TKeyPairType;
      function MappingCaptionByIndex(keyPairType : TKeyPairType) : String;
      function FinanceConnectConfiguration: TFinanceConnectSettings;
      function CreateSettingsXml(settings: TFinanceConnectSettings): String;
      procedure SaveFinanceConnectSettings(FinanceConnectSettings : TFinanceConnectSettings);
    end;

var
    CustomersLookupList : TKeyPairList;
    ItemsLookupList : TKeyPairList;
    VatsLookupList : TKeyPairList;
    PayGroupsBalanceAccountLookupList : TKeyPairList;
    PayGroupsCashBookLookupList : TKeyPairList;

    SystemsLookupList : TKeyPairList;

    MappingsLookupMap : TObjectDictionary<String,String>;

    ActiveFinanceConnectSystemCode : String;
    ActiveFinanceConnectSystemName : String;

const MAPPING_ENTITIES : Array[TKeyPairType] Of String = ('CUSTOMER','ITEM', 'PAYTYPE', 'VAT', 'PAYGROUP', 'PAYGROUP');

procedure ClearFinanceConnectServices;
function FinanceConnectActive : Boolean;
procedure SendInvoiceToActiveFinanceConnector(invoiceNumber : Integer);

implementation

uses
  MSXML2_TLB
  , XmlUtils
  , msxmldom
  , XMLDoc
  , Xml.Xmldom
  , Xml.XMLIntf
  , uUtils
  , Dialogs
  , PrjConst;

function FinanceConnectActive : Boolean;
begin
  result := (trim(ActiveFinanceConnectSystemCode) <> '');
end;

procedure SendInvoiceToActiveFinanceConnector(invoiceNumber : Integer);
begin
  if FinanceConnectActive then
  begin
    d.roomerMainDataSet.downloadUrlAsStringUsingPut(d.roomerMainDataSet.RoomerUri + 'financeconnect/invoices/' + inttostr(invoiceNumber), '');
  end;
end;

const MAP_ENTITY_PATH = 'financeconnect/mappings/%s/%s/%s';

      XML_CONFIGURATION_ROOT = 'configuration';
      XML_CASH_BALANCE_ACCOUNT = 'cashBalanceAccount';
      XML_CASH_CODE = 'cashCode';
      XML_COMPANY_GUID = 'companyGuid';
      XML_HOTEL_ID = 'hotelId';
      XML_INVOICE_CODE = 'invoiceCode';
      XML_OFFICE_CODE = 'officeCode';
      XML_ORGANIZATION_ID = 'organizationId';
      XML_PASSWORD = 'password';
      XML_RECEIVABLE_BALANCE_ACCOUNT = 'receivableBalanceAccount';
      XML_SERVICE_URI = 'serviceUri';
      XML_SYSTEM_ACTIVE = 'systemActive';
      XML_SYSTEM_CODE = 'systemCode';
      XML_USED_CURRENCY = 'usedCurrency';
      XML_USERNAME = 'username';
      XML_PRE_INVOICE_NUMBER = 'preceedingInvoiceNumber';
      XML_SUC_INVOICE_NUMBER = 'succeedingInvoiceNumber';
      XML_CUST_LIST_URI = 'customersListUri';
      XML_ITEM_LIST_URI = 'itemsListUri';
      XML_VAT_LIST_URI = 'vatListUri';
      XML_PAY_LIST_URI = 'payGroupsListUri';
      XML_CASH_BOOK_LIST_URI = 'cashBooksListUri';
      XML_SYSTEM_NAME = 'systemName';

{ TFinanceConnectService }

constructor TFinanceConnectService.Create;
begin
  if ActiveFinanceConnectSystemCode = '' then
    ActiveFinanceConnectSystemCode := Utf8ToString(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'financeconnect'));

  if NOT assigned(SystemsLookupList) then
  begin
    InitializeXmlElements;
    SystemsLookupList := RetrieveFinanceConnectAvailableSystems;
  end;
end;

function TFinanceConnectService.SystemName : String;
var KeyAndValue : TKeyAndValue;
begin
  result := '';

  if ActiveFinanceConnectSystemCode <> '' then
    for KeyAndValue IN SystemsLookUpList do
      if KeyAndValue.Key = ActiveFinanceConnectSystemCode then
      begin
        result := KeyAndValue.Value;
        ActiveFinanceConnectSystemName := result;
        Break;
      end;
end;

procedure TFinanceConnectService.PrepareForMapping;
const mappings : Array[0..4] OF TKeyPairType = (FKP_CUSTOMERS, FKP_PRODUCTS, FKP_VAT, FKP_PAYGROUPS, FKP_CASHBOOKS);
   function GetListUri(KeyPairType : TKeyPairType) : TKeyPairList;
   begin
     result := nil;
     case KeyPairType of
       FKP_CUSTOMERS : result := CustomersLookupList;
       FKP_PRODUCTS : result := ItemsLookupList;
       FKP_VAT : result := VatsLookupList;
       FKP_PAYGROUPS : result := PayGroupsBalanceAccountLookupList;
       FKP_CASHBOOKS : result := PayGroupsCashBookLookupList;
     end;
   end;
   procedure SetListUri(KeyPairType : TKeyPairType; list : TKeyPairList);
   begin
     case KeyPairType of
       FKP_CUSTOMERS : CustomersLookupList := list;
       FKP_PRODUCTS : ItemsLookupList := list;
       FKP_VAT : VatsLookupList := list;
       FKP_PAYGROUPS : PayGroupsBalanceAccountLookupList := list;
       FKP_CASHBOOKS : PayGroupsCashBookLookupList := list;
     end;
   end;
   function GetListName(KeyPairType : TKeyPairType) : String;
   begin
     result := 'UNKNOWN';
     case KeyPairType of
       FKP_CUSTOMERS : result := 'Customers';
       FKP_PRODUCTS : result := 'Items';
       FKP_VAT : result := 'Vats';
       FKP_PAYGROUPS : result := 'Pay Groups Balance Accounts';
       FKP_CASHBOOKS : result := 'Cash Books';
     end;
   end;
var
  i: Integer;
begin
  if ActiveFinanceConnectSystemCode <> '' then
  begin
    InitializeXmlElements;

    if NOT assigned(SystemsLookupList) then
      SystemsLookupList := RetrieveFinanceConnectAvailableSystems;

    if (NOT assigned(MappingsLookupMap)) then
         RetrieveFinanceConnectMappings;

    for i := LOW(mappings) to HIGH(mappings) do
    begin
      try
        if NOT assigned(GetListUri(mappings[i])) then
          SetListUri(mappings[i], RetrieveFinanceConnectKeypair(mappings[i]));
      except
        On e: Exception do
        begin
          MessageDlg(format(GetTranslatedText('shFinanceConnectUnableToRetrieveMapping'), [GetListName(mappings[i])]), mtError, [mbOk], 0);

          CustomersLookupList := TKeyPairList.Create(True);
          ItemsLookupList := TKeyPairList.Create(True);
          VatsLookupList := TKeyPairList.Create(True);
          PayGroupsBalanceAccountLookupList := TKeyPairList.Create(True);
          PayGroupsCashBookLookupList := TKeyPairList.Create(True);
        end;
      end;
    end;

  end;
end;

procedure TFinanceConnectService.ParseList(XmlString : String; KeyPairList : TKeyPairList; XmlElements : TFinanceXmlListElements);
var
  XML: IXMLDOMDocument2;
  listNode, rootNode, dataNode: IXMLDOmNode;
  i, l : Integer;
  code, name : String;
begin
  xml := CreateXmlDocument;
  xml.loadXML(XmlString);
  listNode := xml.documentElement;
  if listNode <> nil then
  begin
    if listNode.nodeName = XmlElements.listName then
    begin
      for i := 0 to listNode.childNodes.length - 1 do
        if listNode.childNodes.item[i].nodeName = XmlElements.rootName then
        begin
          code := '';
          name := '';
          rootNode := listNode.childNodes.item[i];
          for l := 0 to rootNode.childNodes.length - 1 do
          begin
            dataNode := rootNode.childNodes.item[l];
            if dataNode.nodeName = XmlElements.codeName then
            begin
              code := dataNode.text;
            end else
            if dataNode.nodeName = XmlElements.descriptionName then
            begin
              name := dataNode.text;
            end;
          end;
          if (code <> '') and (name <> '') then
          begin
            KeyPairList.Add(TKeyAndValue.Create(code, name));
          end;
        end;

    end;
  end;
end;

function TFinanceConnectService.ParseSettings(XmlString : String) : TFinanceConnectSettings;
var
  XML: IXMLDOMDocument2;
  listNode, rootNode: IXMLDOmNode;
  i : Integer;
begin
  xml := CreateXmlDocument;
  xml.loadXML(XmlString);
  listNode := xml.documentElement;
  if listNode <> nil then
  begin
    if listNode.nodeName = XML_CONFIGURATION_ROOT then
    begin
      with result do
      begin
        for i := 0 to listNode.childNodes.length - 1 do
        begin
          rootNode := listNode.childNodes.item[i];
          with rootNode do
          begin
            if rootNode.nodeName = XML_CASH_BALANCE_ACCOUNT then
               cashBalanceAccount := rootNode.text
            else
            if rootNode.nodeName = XML_CASH_CODE then
               cashCode := rootNode.text
            else
            if rootNode.nodeName = XML_COMPANY_GUID then
               companyGuid := rootNode.text
            else
            if rootNode.nodeName = XML_HOTEL_ID then
               hotelId := rootNode.text
            else
            if rootNode.nodeName = XML_INVOICE_CODE then
               invoiceCode := rootNode.text
            else
            if rootNode.nodeName = XML_OFFICE_CODE then
               officeCode := rootNode.text
            else
            if rootNode.nodeName = XML_ORGANIZATION_ID then
               organizationId := rootNode.text
            else
            if rootNode.nodeName = XML_PASSWORD then
               password := rootNode.text
            else
            if rootNode.nodeName = XML_RECEIVABLE_BALANCE_ACCOUNT then
               receivableBalanceAccount := rootNode.text
            else
            if rootNode.nodeName = XML_SERVICE_URI then
               serviceUri := rootNode.text
            else
            if rootNode.nodeName = XML_SYSTEM_ACTIVE then
               systemActive := LowerCase(rootNode.text) = 'true'
            else
            if rootNode.nodeName = XML_SYSTEM_CODE then
               systemCode := rootNode.text
            else
            if rootNode.nodeName = XML_USED_CURRENCY then
               usedCurrency := rootNode.text
            else
            if rootNode.nodeName = XML_USERNAME then
               username := rootNode.text
            else
            if rootNode.nodeName = XML_PRE_INVOICE_NUMBER then
               preceedingInvoiceNumber := rootNode.text
            else
            if rootNode.nodeName = XML_SUC_INVOICE_NUMBER then
               succeedingInvoiceNumber := rootNode.text
            else
            if rootNode.nodeName = XML_CUST_LIST_URI then
               customersListUri := rootNode.text
            else
            if rootNode.nodeName = XML_ITEM_LIST_URI then
               itemsListUri := rootNode.text
            else
            if rootNode.nodeName = XML_VAT_LIST_URI then
               vatListUri := rootNode.text
            else
            if rootNode.nodeName = XML_PAY_LIST_URI then
               payGroupsListUri := rootNode.text
            else
            if rootNode.nodeName = XML_CASH_BOOK_LIST_URI then
               cashBooksListUri := rootNode.text
            else
            if rootNode.nodeName = XML_SYSTEM_NAME then
               systemName := rootNode.text;
          end;
        end;
      end;
    end;
  end;
end;

function TFinanceConnectService.CreateSettingsXml(settings :  TFinanceConnectSettings) : String;
var
  iRoot : IXMLNode;
  XMLDoc: TXMLDocument;

  procedure AddDataElement(name, data : String);
  var iNode : IXMLNode;
  begin
    iNode := iRoot.addChild(name);
    iNode.Text := data;
  end;

begin
  XMLDoc := TXMLDocument.Create(nil);
  XMLDoc.Active := False;
  XMLDoc.XML.Text := '';
  XMLDoc.Active := True;
//  iXml := XMLDoc.DOMDocument;
  iRoot := XMLDoc.addChild(XML_CONFIGURATION_ROOT);
  with settings do begin
    AddDataElement(XML_CASH_BALANCE_ACCOUNT, cashBalanceAccount);
    AddDataElement(XML_CASH_CODE, cashCode);
    AddDataElement(XML_COMPANY_GUID, companyGuid);
    AddDataElement(XML_HOTEL_ID, hotelId);
    AddDataElement(XML_INVOICE_CODE, invoiceCode);
    AddDataElement(XML_ORGANIZATION_ID, organizationId);
    AddDataElement(XML_PASSWORD, password);
    AddDataElement(XML_OFFICE_CODE, officeCode);
    AddDataElement(XML_RECEIVABLE_BALANCE_ACCOUNT, receivableBalanceAccount);
    AddDataElement(XML_SERVICE_URI, serviceUri);
    AddDataElement(XML_SYSTEM_ACTIVE, IIF(systemActive, 'true', 'false'));
    AddDataElement(XML_SYSTEM_CODE, systemCode);
    AddDataElement(XML_USED_CURRENCY, usedCurrency);
    AddDataElement(XML_USERNAME, username);
    AddDataElement(XML_PRE_INVOICE_NUMBER, preceedingInvoiceNumber);
    AddDataElement(XML_SUC_INVOICE_NUMBER, succeedingInvoiceNumber);
    AddDataElement(XML_CUST_LIST_URI, customersListUri);
    AddDataElement(XML_ITEM_LIST_URI, itemsListUri);
    AddDataElement(XML_VAT_LIST_URI, vatListUri);
    AddDataElement(XML_PAY_LIST_URI, payGroupsListUri);
    AddDataElement(XML_CASH_BOOK_LIST_URI, cashBooksListUri);
    AddDataElement(XML_SYSTEM_NAME, systemName);
  end;
  xmlDoc.SaveToXML(result);
end;

procedure TFinanceConnectService.SaveFinanceConnectSettings(FinanceConnectSettings : TFinanceConnectSettings);
var s : String;
begin
  s := CreateSettingsXml(FinanceConnectSettings);
  s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsStringUsingPut(d.roomerMainDataSet.RoomerUri + 'financeconnect', s));
end;

function TFinanceConnectService.RetrieveListForKeyPairAsString(url : String): String;
var s : String;
begin
  s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + url));
  result := s;
end;

function TFinanceConnectService.RetrieveFinanceConnectKeypair(keyPairType: TKeyPairType): TKeyPairList;
var
  cursorWas : SmallInt;
  s: String;
  XmlElements : TFinanceXmlListElements;
  FinanceConnectSettings : TFinanceConnectSettings;

  function RetrieveAsFile(url : String) : TKeyPairList;
  var filename : String;
      stl, line : TStrings;
      s: String;
  begin
    result := nil;
    if Lowercase(Copy(url, 1, 8)) = 'file:///' then
    begin
      result := TKeyPairList.Create(True);
      filename := ReplaceString(copy(url, 9, MAXINT), '/', '\');
      stl := TStringList.Create;
      try
        stl.LoadFromFile(filename);
        for s IN stl do
        begin
          line := Split(s, '=');
          try
            if line.Count > 0 then
            begin
              if line[0] <> '' then
                result.Add(TKeyAndValue.Create(line[0], line[1]));
            end;
          finally
            line.Free;
          end;
        end;

      finally
        stl.Free;
      end;
    end;
  end;

begin
  cursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass;
  Application.ProcessMessages;
  try
    FinanceConnectSettings := FinanceConnectConfiguration;
    case keyPairType of
      FKP_CUSTOMERS: begin
                       result := RetrieveAsFile(FinanceConnectSettings.customersListUri);
                       if Assigned(result) then exit;
                       s := RetrieveListForKeyPairAsString('financeconnect/customers');
                       XmlElements := CustomerXmlElements;
                     end;
      FKP_PRODUCTS : begin
                       result := RetrieveAsFile(FinanceConnectSettings.itemsListUri);
                       if Assigned(result) then exit;
                       s := RetrieveListForKeyPairAsString('financeconnect/items');
                       XmlElements := ItemXmlElements;
                     end;
      FKP_VAT      : begin
                       result := RetrieveAsFile(FinanceConnectSettings.vatListUri);
                       if Assigned(result) then exit;
                       s := RetrieveListForKeyPairAsString('financeconnect/vatcodes');
                       XmlElements := VatXmlElements;
                     end;
      FKP_PAYGROUPS: begin
                       result := RetrieveAsFile(FinanceConnectSettings.payGroupsListUri);
                       if Assigned(result) then exit;
                       s := RetrieveListForKeyPairAsString('financeconnect/paygroups');
                       XmlElements := PayGroupsXmlElements;
                     end;
      FKP_CASHBOOKS: begin
                       result := RetrieveAsFile(FinanceConnectSettings.cashBooksListUri);
                       if Assigned(result) then exit;
                       s := RetrieveListForKeyPairAsString('financeconnect/cashbooks');
                       XmlElements := CashBooksXmlElements;
                     end;
    end;

    result := TKeyPairList.Create(True);
    ParseList(s, result, XmlElements);
  finally
    Screen.Cursor := cursorWas;
    Application.ProcessMessages;
  end;
end;

function TFinanceConnectService.RetrieveFinanceConnectAvailableSystems: TKeyPairList;
var
  cursorWas : SmallInt;
  s: String;
begin
  cursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass;
  Application.ProcessMessages;
  try
    result := TKeyPairList.Create(True);
    try
      s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'financeconnect/availablesystems'));
      ParseList(s, result, SystemsXmlElements);
    except
      MessageDlg('Error occured trying to reach FinanceConnect service.'#10 + 'Roomer will continue without connection to accounting system.', mtWarning, [mbOk], 0);
    end;
  finally
    Screen.Cursor := cursorWas;
    Application.ProcessMessages;
  end;
end;

procedure TFinanceConnectService.RetrieveFinanceConnectMappings;

  procedure saveInMap(entity : String; LookupList : TKeyPairList);
  var KeyAndValue : TKeyAndValue;
  begin
    for KeyAndValue IN LookupList do
      MappingsLookupMap.AddOrSetValue(format('%s_%s', [entity, KeyAndValue.Key]), KeyAndValue.Value);
  end;

var
  cursorWas : SmallInt;
  s: String;
  LookupList : TKeyPairList;
  entity : String;

begin
  cursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass;
  Application.ProcessMessages;
  try
    MappingsLookupMap := TObjectDictionary<String,String>.Create;
    for entity IN MAPPING_ENTITIES do
    begin
      if entity <> 'PAYTYPE' then
      begin
        LookupList := TKeyPairList.Create(True);
        try
          s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'financeconnect/mappings/' + entity));
          MappingsXmlElements.listName := format('%sMap', [LowerCase(entity)]);
          ParseList(s, LookupList, MappingsXmlElements);
          saveInMap(entity, LookupList);
        finally
          LookupList.Free;
        end;
      end;
    end;
  finally
    Screen.Cursor := cursorWas;
    Application.ProcessMessages;
  end;
end;

function TFinanceConnectService.FinanceConnectConfiguration : TFinanceConnectSettings;
var
  cursorWas : SmallInt;
  s: String;
begin
  cursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass;
  Application.ProcessMessages;
  try
    s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + 'financeconnect/' + ActiveFinanceConnectSystemCode));
    FinanceConnectSettings := ParseSettings(s);
    result := FinanceConnectSettings;
  finally
    Screen.Cursor := cursorWas;
    Application.ProcessMessages;
  end;
end;

procedure TFinanceConnectService.MapForFinanceConnect(keyPairType: TKeyPairType; RoomerCode, ExternalCode : String);
var
  cursorWas : SmallInt;
  s, MapType: String;
begin
  cursorWas := Screen.Cursor;
  Screen.Cursor := crHourglass;
  Application.ProcessMessages;
  MapType := MAPPING_ENTITIES[keyPairType];
  try
    s := Utf8ToString(d.roomerMainDataSet.downloadUrlAsStringUsingPut(d.roomerMainDataSet.RoomerUri +
                      format(MAP_ENTITY_PATH, [MapType, RoomerCode, ExternalCode]), ''));
  finally
    Screen.Cursor := cursorWas;
    Application.ProcessMessages;
  end;
end;

procedure TFinanceConnectService.InitializeXmlElements;
begin
  CustomerXmlElements := TFinanceXmlListElements.Create('customers', 'customer', 'customerCode', 'customerName');
  ItemXmlElements := TFinanceXmlListElements.Create('items', 'item', 'itemCode', 'itemName');
  VatXmlElements := TFinanceXmlListElements.Create('vatCodes', 'vatCode', 'vatCode', 'vatName');
  PayGroupsXmlElements := TFinanceXmlListElements.Create('items', 'item', 'itemCode', 'itemName');
  CashBooksXmlElements := TFinanceXmlListElements.Create('cashBooks', 'book', 'bookCode', 'bookName');

  SystemsXmlElements := TFinanceXmlListElements.Create('availableSystems', 'systemCode', 'code', 'name');

  MappingsXmlElements := TFinanceXmlListElements.Create('%sMap', 'map', 'roomerCode', 'externalCode');

end;

function TFinanceConnectService.keyPairTypeByIndex(index : Integer) : TKeyPairType;
begin
  result := FKP_CUSTOMERS;
  case index of
    0 : result := FKP_CUSTOMERS;
    1 : result := FKP_PRODUCTS;
    2 : result := FKP_VAT;
    3 : result := FKP_PAYGROUPS;
  end;
end;

function TFinanceConnectService.MappingCaptionByIndex(keyPairType : TKeyPairType) : String;
begin
  result := '';
  case keyPairType of
    FKP_CUSTOMERS : result := 'CSTOMERS';
    FKP_PRODUCTS : result := 'PRODUCTS';
    FKP_VAT : result := 'VAT CODES';
    FKP_PAYGROUPS : result := 'PAY GROUPS';
  end;
end;


{ TFinanceXmlListElements }

constructor TFinanceXmlListElements.Create(list, root, code, description: String);
begin
  listName := list;
  rootName := root;
  codeName := code;
  descriptionName := description;
end;

/////////////////////////// Global methods ////////////////////////////////

procedure ClearFinanceConnectServices;
begin
  ActiveFinanceConnectSystemCode := '';
  ActiveFinanceConnectSystemName := '';

  FreeAndNil(CustomersLookupList);
  FreeAndNil(ItemsLookupList);
  FreeAndNil(VatsLookupList);
  FreeAndNil(PayGroupsBalanceAccountLookupList);
  FreeAndNil(PayGroupsCashBookLookupList);

  FreeAndNil(SystemsLookupList);

  FreeAndNil(MappingsLookupMap);
end;

{ TFinanceConnectSettings }

constructor TFinanceConnectSettings.Create(_systemActive: Boolean;
                         _cashBalanceAccount,
                         _cashCode,
                         _companyGuid,
                         _hotelId,
                         _invoiceCode,
                         _officeCode,
                         _organizationId,
                         _password,
                         _receivableBalanceAccount,
                         _serviceUri,
                         _systemCode,
                         _usedCurrency,
                         _username,
                         _preceedingInvoiceNumber,
                         _succeedingInvoiceNumber,
                         _customersListUri,
                         _itemsListUri,
                         _vatListUri,
                         _payGroupsListUri,
                         _cashBooksListUri,
                         _systemName : String);
begin
  cashBalanceAccount := _cashBalanceAccount;
  cashCode := _cashCode;
  companyGuid := _companyGuid;
  hotelId := _hotelId;
  invoiceCode := _invoiceCode;
  officeCode := _officeCode;
  organizationId := _organizationId;
  password := _password;
  receivableBalanceAccount := _receivableBalanceAccount;
  serviceUri := _serviceUri;
  systemActive := _systemActive;
  systemCode := _systemCode;
  usedCurrency := _usedCurrency;
  username := _username;
  preceedingInvoiceNumber := _preceedingInvoiceNumber;
  succeedingInvoiceNumber := _succeedingInvoiceNumber;
  customersListUri := _customersListUri;
  itemsListUri := _itemsListUri;
  vatListUri := _vatListUri;
  payGroupsListUri := _payGroupsListUri;
  cashBooksListUri := _cashBooksListUri;
  systemName := _systemName;
end;

initialization
  ClearFinanceConnectServices;

finalization
  ClearFinanceConnectServices;

end.
