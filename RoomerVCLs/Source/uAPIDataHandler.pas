unit uAPIDataHandler;

interface

uses MSXML2_TLB, Data.Win.ADODB, Data.DB, RoomerCloudEntities, System.Generics.Collections;

type

  TRoomerFileType = (rftTemplates, rftImages, rftContracts, rftRoomer);


  TFieldsAndValues = record
    field: string;
    dataType : string;
    Value: variant;
  end;
  array_of_TFieldsAndValues = array of TFieldsAndValues;

  TFileEntity = class
  private
    FName: String;
    FLastModified: TDateTime;
    FFileType: Char;
    FSize: integer;
  public
    constructor Create(filename : String;
                       size : integer;
                       lastModified : TDateTime;
                       fileType : char {'D'/'F' = Dir/File}
                       );
    destructor Destroy; override;

    property name : String read FName;
    property size : integer read FSize;
    property lastModified : TDateTime read FLastModified;
    property fileType : Char read FFileType;
  end;

  TFileList = class
  private
    FList : TObjectList<TFileEntity>;
    function GetCount: integer;
    function GetFiles(_index: integer): TFileEntity;
  public
    constructor Create(xmlList : String);
    destructor Destroy; override;

    function add(fileEntity : TFileEntity) : Integer;
    property Count : integer read GetCount;
    property Files[_index : integer] : TFileEntity read GetFiles;
  end;

function getXmlFromJavaEntity(recordSet: string): string;
function getXmlFromRecordSet(rs: _Recordset): string;
function XMLToRecordset(const someXML: string): _Recordset;
function generateRecordXml(data : array of TFieldsAndValues) : string;
function SQLToXML(const aConnection: TAdoConnection;
  const aSQLCommand: string): string;


implementation

uses ComObj, ActiveX, ADOInt, uStringUtils, uDateUtils, SysUtils, ExtCtrls,
     StdCtrls, Controls, Classes
     , XMLUtils;

const
  RECORDSET_SCHEMA_HEADER
    : string = '<xml xmlns:s="uuid:BDC6E3F0-6DA3-11d1-A2A3-00AA00C14882"' +
    '   xmlns:dt="uuid:C2F41010-65B3-11d1-A29F-00AA00C14882"' +
    '   xmlns:rs="urn:schemas-microsoft-com:rowset"' +
    '   xmlns:z="#RowsetSchema">' + '<s:Schema id="RowsetSchema">' +
    '<s:ElementType name="row" content="eltOnly" rs:updatable="true">';

const
  RECORDSET_SCHEMA_FOOTER: string = '</s:ElementType>' + '</s:Schema>' +
    '<rs:data>';

const
  RECORDSET_SCHEMA_COLUMN: string = '<s:AttributeType name="%s"' +
    ' rs:number="%d"' // field index
    + ' rs:nullable="%s"' // true/false
    + ' rs:writeunknown="%s"' // true/false
    + ' rs:basecatalog="%s"' // catalog (DB name) i.e. 'homeData'
    + ' rs:basetable="%s"' // table name
    + ' rs:basecolumn="%s">' // column name
    + '<s:datatype dt:type="%s"' // datatype, i.e. 'string'
    + ' dt:maxLength="%s"/>' // Maxlength of field
    + '</s:AttributeType>';

const
  RECORDSET_DATA_FOOTER: string = '</rs:data>' + '</xml>';

const
  RECORDSET_DATA_ROW: string = '<z:row %s />';

const
  RECORDSET_DATA_VALUE: string = '%s="%s" ';

function getXmlFromRecordSet(rs: _Recordset): string;
var
  xml: IXMLDOMDocument2;
begin
  // Streams _Recordset into XML
  xml := CreateXmlDocument; // CoDOMDocument40.Create;
  rs.Save(xml, adPersistXML);
  rs.Close;
  result := xml.xml;
end;

function SQLToXML(const aConnection: TAdoConnection;
  const aSQLCommand: string): string;
var
  rs: _Recordset;
begin
  // Creates a disconnected recordset that will be streamed into XML
  rs := CoRecordset.Create;
  rs.CursorLocation := adUseClient;
  rs.Open(aSQLCommand, aConnection.ConnectionObject, adOpenForwardOnly,
    adLockBatchOptimistic, 0);
  result := getXmlFromRecordSet(rs);
end;

function XMLToRecordset(const someXML: string): _Recordset;
var
  xml: IXMLDOMDocument2;
  rs: OleVariant;
begin
  xml := CreateXmlDocument; // CoDOMDocument40.Create;

  try
    xml.LoadXML(someXML);
  except
    on E: Exception do
      raise Exception.CreateFmt('Error ocurred while interpreting result from server [%s].', [e.Message]);
  end;
  rs := CoRecordset.Create;
  rs.Open(xml);

  result := IUnknown(rs) as _Recordset;
end;

// ************************************************************************

function getXmlFromJavaEntity(recordSet: string): string;
var
  col: integer;
  row: string;
  lbl: String;
  dataAsString: string;

  XML : IXMLDOMDocument2;

  nlistData,
  nlist               : IXMLDOMNodelist;

  i : Integer;

  entity : ShortString;
  strTemp : ShortString;

BEGIN
  XML := CreateXmlDocument; //CreateOleObject('MSXML2.DOMDocument.6.0') as IXMLDOMDocument2;
  XML.async := false;
  XML.SetProperty('SelectionLanguage','XPath');
  XML.loadXml(recordSet);

  nlist := XML.getElementsByTagName('column');

  result := RECORDSET_SCHEMA_HEADER;

  for i:=0 to nlist.Get_length-1 do
  begin
    result := result + format(RECORDSET_SCHEMA_COLUMN,
      [nlist.Get_item(i).attributes.getNamedItem('name').text,
      i + 1,
      'true',
      'false',
      'roomer', 'roomer',
      nlist.Get_item(i).attributes.getNamedItem('name').text,
      nlist.Get_item(i).attributes.getNamedItem('type').text,
      nlist.Get_item(i).attributes.getNamedItem('length').text]);
      if entity = '' then
      begin
        entity := ShortString(nlist.Get_item(i).attributes.getNamedItem(WideString('entity')).text);
        strTemp := ShortString(entity[1] + ShortString(' '));
        strTemp := ShortString(LowerCase(String(strTemp)));
        entity[1] := (strTemp[1]);
      end;

  end;
  result := result + RECORDSET_SCHEMA_FOOTER;

  nlist := XML.getElementsByTagName(WideString(entity));

  for i:=0 to nlist.Get_length-1 do
  begin
    row := '';
    nlistData := nlist.Get_item(i).childNodes;
    for col := 0 to nlistData.Get_length-1 do
    begin
      lbl := nlistData.Get_item(col).nodeName;
      dataAsString := nlistData.Get_item(col).text;
      dataAsString := XMLEncode_ex(dataAsString, dataAsString);
      row := row + format(RECORDSET_DATA_VALUE, [lbl, dataAsString]);
    end;
    result := result + format(RECORDSET_DATA_ROW, [row]);
  end;

  result := result + RECORDSET_DATA_FOOTER;
end;


function generateRecordXml(data : array of TFieldsAndValues) : string;
var
  col: integer;
  counter : integer;

  row: string;
  dataAsString: string;
begin
  result := RECORDSET_SCHEMA_HEADER;

  counter := 0;
  row := '';
  for col := Low(data) to High(data) do
  begin
    inc(counter);
    result := result + format(RECORDSET_SCHEMA_COLUMN,
      [data[col].field, counter,
      'true', 'true', '', '',
      data[col].field, data[col].dataType,
      0]);

    dataAsString := data[col].Value;
    row := row + format(RECORDSET_DATA_VALUE, [data[col].field, dataAsString]);

  end;
  result := result +  RECORDSET_SCHEMA_FOOTER +
                      format(RECORDSET_DATA_ROW, [row]) +
                      RECORDSET_DATA_FOOTER;
end;

// ************************************************************************

procedure getFileListFromXml(fileList : TFileList; recordSet: string);
var
  XML : IXMLDOMDocument2;
  nlist               : IXMLDOMNodelist;
  i : Integer;
  _type : char;
BEGIN
  XML := CreateXmlDocument; // CreateOleObject('MSXML2.DOMDocument.6.0') as IXMLDOMDocument2;
  XML.async := false;
  XML.SetProperty('SelectionLanguage','XPath');
  XML.loadXml(recordSet);

  nlist := XML.getElementsByTagName('file');

  for i:=0 to nlist.Get_length-1 do
  begin
    _type := 'F';
    if nlist.Get_item(i).attributes.getNamedItem('name').text = 'dir' then
      _type := 'D';
    fileList.Add(TFileEntity.Create(
        nlist.Get_item(i).attributes.getNamedItem('name').text,
        strtoint(nlist.Get_item(i).attributes.getNamedItem('size').text),
        XmlStringToDate(nlist.Get_item(i).attributes.getNamedItem('lastModified').text),
        _type
        )
    );
  end;

end;


{ TFileEntity }

constructor TFileEntity.Create(filename: String; size: integer; lastModified: TDateTime; fileType: char);
begin
  inherited Create;
  FName := filename;
  FSize := size;
  FLastModified := lastModified;
  FFileType := fileType;
end;

destructor TFileEntity.Destroy;
begin
  inherited;
end;

{ TFileList }

function TFileList.add(fileEntity: TFileEntity): Integer;
begin
  result := FList.Add(fileEntity);
end;

constructor TFileList.Create(xmlList: String);
begin
  inherited Create;
  FList := TObjectList<TFileEntity>.Create;
  getFileListFromXml(self, xmlList);
end;

destructor TFileList.Destroy;
begin
  FList.Free;
  inherited;
end;

function TFileList.GetCount: integer;
begin
  result := FList.Count;
end;

function TFileList.GetFiles(_index: integer) : TFileEntity;
begin
  result := FList[_index];
end;

end.

