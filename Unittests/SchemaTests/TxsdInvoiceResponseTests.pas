unit TxsdInvoiceResponseTests;

interface
uses
  DUnitX.TestFramework
  , RoomerBookingCommunicationModel_RequestsResponses
  ;

type

  {$M+}
  [TestFixture]
  TxsdInvoiceResponsetest = class(TObject)
  private
    FInvoiceresponse: TxsdInvoiceResponse;
  public
    [Setup]
    procedure Setup;
    [TearDown]
    procedure TearDown;
  published
    procedure TestInvoiceRequestResponse;
  end;

implementation

uses
  XMLIntf
  , OXmlPDOM
  ;

procedure TxsdInvoiceResponsetest.Setup;
begin
  FInvoiceResponse := TxsdInvoiceResponse.Create;
end;

procedure TxsdInvoiceResponsetest.TearDown;
begin
end;

procedure TxsdInvoiceResponsetest.TestInvoiceRequestResponse;
var
  xmlDoc: IXMLDocument;
  lNodeList: IXMLNodeList;
const
  cInvoiceResponseFile = '..\..\XMLData\InvoiceResponse.xml';
begin
  xmlDoc := TXMLDocument.Create;
  xmlDoc.LoadFromXML(cInvoiceResponseFile);

  Assert.IsNull(xmlDoc.ParseError);

  FInvoiceresponse.SetPropertiesFromXMLNode(xmlDoc.DocumentElement);
end;

initialization
  TDUnitX.RegisterTestFixture(TxsdInvoiceResponsetest);
end.
