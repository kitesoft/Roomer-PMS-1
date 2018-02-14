unit uHotelStatistics;

interface

uses
  Spring.Collections.Lists
  , Spring.Collections
  , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
  ;


type

  {$SCOPEDENUMS ON}
  TUnitOfMeasurement = (NativeCurrency, Percent, NoDimension);

  TUnitOfMeasurementHelper = record helper for TUnitOfMeasurement
  private const
    cUOMNames: array[TUnitOfMeasurement] of string = ('NATIVE_CURRENCY', 'PERCENT', 'NO_DIMENSION');
  public
    class function FromString(const aStr: String): TUnitOfMeasurement; static;
  end;

  THotelStatistic = class(TxsdBaseObject)
  private
    FName: string;
    FValue: double;
    FUOM: TUnitOfMeasurement;
    FDescription: string;
  protected
    class function GetNodeName: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  published
    property Name: string read FName write FName;
    property Value: double read FValue write FValue;
    property UOM: TUnitOfMeasurement read FUOM write FUOM;
    property Description: string read FDescription write FDescription;
  end;

  TStatisticsList = class(TxsdBaseObjectList<THotelStatistic>);

  TSingleDateStatistics = class(TxsdBaseObject)
  private
    FStatistics: IList<THotelStatistic>;
    FDate: TDate;
    function GetStatisticsList: TStatisticsList;
  protected
    class function GetNodeName: string; override;
  public
    constructor Create;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;

  published
    property Date: TDate read FDate;
    property StatisticsList: TStatisticsList read GetStatisticsList;
  end;


  TStatisticsPerDateList = class(TxsdBaseObjectList<TSingleDateStatistics>);

  THotelStatisticsList = class(TxsdBaseObject)
  private
    FStatsPerDateList: IList<TSingleDateStatistics>;
    function GetStatisticsPerDateList: TStatisticsPerDateList;
  protected
    class function GetNodeName: string; override;
  public
    constructor Create;

    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
   published
    property StatisticsPerDateList: TStatisticsPerDateList read GetStatisticsPerDateList;
  end;


implementation

uses
  SysUtils
  ;

{ THotelStatistic }

class function THotelStatistic.GetNodeName: string;
begin
  result := 'statistics';
end;

procedure THotelStatistic.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNode: PXMLNode;
begin
  inherited;

  if aNode.FindChild('name', lNode) then FName := lNode.Text;
  if aNode.FindChild('value', lNode) then FValue := StrToFloatDef(lNode.text, 0);
  if aNode.FindChild('unit', lNode) then FUOM := TUnitOfMeasurement.FromString(lNode.Text);
  if aNode.FindChild('description', lNode) then FDescription := lNode.Text;

end;


{ TStatistics }

procedure TSingleDateStatistics.Clear;
begin
  inherited;
  FStatistics.Clear;
end;

constructor TSingleDateStatistics.Create;
begin
  inherited;
  FStatistics := TStatisticsList.Create;
end;


class function TSingleDateStatistics.GetNodeName: string;
begin
  result := 'item';
end;

function TSingleDateStatistics.GetStatisticsList: TStatisticsList;
begin
  Result := FStatistics as TStatisticsList;
end;

procedure TSingleDateStatistics.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNode: PXMLNode;
  Year, Month, Day: integer;
begin
  inherited;
  Year := 1900;
  Month := 1;
  Day := 1;
  if aNode.FindChild('date', lNode) then
  begin
    lNode := lnode.FirstChild;
    while assigned(lNode) do
    begin
      if lNode.NodeName = 'year' then year := StrToInt(lnode.Text)
      else if lNode.NodeName = 'monthValue' then month := StrToInt(lnode.Text)
      else if lNode.NodeName = 'dayOfMonth' then day := StrToInt(lnode.Text);
      lNode := lNode.NextSibling;
    end;

    FDate := EncodeDate(Year, month, day);
  end;

  if aNode.FindChild('statistics', lNode) then
    StatisticsList.SetPropertiesFromXMLNode(lNode);
end;

{ THotelStatisticsList }

procedure THotelStatisticsList.Clear;
begin
  FStatsPerDateList.Clear;
end;

constructor THotelStatisticsList.Create;
begin
  inherited;
  FStatsPerDateList := TStatisticsPerDateList.Create;
end;

class function THotelStatisticsList.GetNodeName: string;
begin
  Result := 'ArrayList';
end;

function THotelStatisticsList.GetStatisticsPerDateList: TStatisticsPerDateList;
begin
  Result := FStatsPerDateList as TStatisticsPerDateList;
end;

procedure THotelStatisticsList.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  StatisticsPerDateList.SetPropertiesFromXMLNode(aNode);
end;

{ TUnitOfMeasurementHelper }

class function TUnitOfMeasurementHelper.FromString(const aStr: String): TUnitOfMeasurement;
begin
  for Result := low(TUnitOfMeasurement) to high(TUnitOfMeasurement) do
    if SameText(cUOMNames[Result], aStr) then
      Break;
end;

end.
