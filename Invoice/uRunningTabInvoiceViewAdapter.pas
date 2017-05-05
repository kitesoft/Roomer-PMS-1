unit uRunningTabInvoiceViewAdapter;

interface

uses
  Classes
  , RoomerBookingCommunicationModel_RequestsResponses
  , RoomerFinancialDataModel_ModelObjects
  , Spring.Collections.Lists
  , Spring.Collections
  ;

type

  TRunningTabInvoiceViewItem = class(TPersistent)
  private
    FID: integer;
    FLineType: TxsdInvoiceLineType;
    function GetDescription: string;
    function GetItemType: string;
    function GetIndex: integer;
    function GetId: integer;
  public
    constructor Create(aLineType: TxsdInvoiceLineType; aID: integer);
  published
    property ID: integer read GetId;
    property Index_: integer read GetIndex;
    property ItemType: string read GetItemType;
    property Description: string read GetDescription;
  end;

  TRunningTabInvoiceViewList = class(TObjectList<TRunningTabinvoiceViewItem>)
  private
    FLinesList: TxsdInvoiceLineTypeList;
    procedure Additems;
  public
    constructor Create(aLinesList: TxsdInvoiceLineTypeList); overload;
  end;

  /// <summary>
  ///   Class adapting the runningtab result for use in the invoiceOnObjects form
  /// </summary>
  TRunningTabInvoiceViewAdapter = class
  private
    FRunningTabsOverview: TxsdInvoiceResponse;
    function GetInvoicelinesList(aIndex: integer): IObjectList;
    function GetPaymentsList(aIndex: integer): IObjectList;

  public
    constructor Create;
    destructor Destroy; override;

    function TotalInvoiceLinesGrossAmount(aIndex: integer): double;
    function InvoiceIndexNotEmpty(aIndex: integer): boolean;

    property RunningTabsOverview: TxsdInvoiceResponse read FRunningTabsOverview;
    property InvoicelinesList[aIndex: integer]: IObjectList read GetInvoicelinesList;
    property PaymentsList[aIndex: integer]: IObjectList read GetPaymentsList;
  end;


implementation

uses
  SysUtils
  ;

{ TRunningTabInvoiceViewAdapter }

constructor TRunningTabInvoiceViewAdapter.Create;
begin
  FRunningTabsOverview := TxsdInvoiceResponse.Create;
end;

destructor TRunningTabInvoiceViewAdapter.Destroy;
begin
  FRunningTabsOverview.Free;
  inherited;
end;

function TRunningTabInvoiceViewAdapter.GetInvoicelinesList(aIndex: integer): IObjectList;
begin
  if InvoiceIndexNotEmpty(aIndex) then
    Supports(TRunningTabInvoiceViewList.Create(FRunningTabsOverview.Items[aIndex].LineItemList), IObjectList, Result)
  else
    Result := nil;
end;

function TRunningTabInvoiceViewAdapter.GetPaymentsList(aIndex: integer): IObjectList;
begin

end;

function TRunningTabInvoiceViewAdapter.InvoiceIndexNotEmpty(aIndex: integer): boolean;
begin
  Result := (FRunningTabsOverview.Count >= aIndex) and (FRunningTabsOverview.Items[aIndex].LineItemList.Count > 0);
end;

function TRunningTabInvoiceViewAdapter.TotalInvoiceLinesGrossAmount(aIndex: integer): double;
begin

end;

{ TRunningTabInvoiceViewList }

constructor TRunningTabInvoiceViewList.Create(aLinesList: TxsdInvoiceLineTypeList);
begin
  Create;
  FLinesList := aLinesList;
  AddItems;
end;

procedure TRunningTabInvoiceViewList.Additems;
var
  lItem: TxsdInvoiceLineType;
  cnt: integer;
begin
  cnt := 0;
  for lItem in FLinesList do
  begin
    Add(TRunningTabInvoiceViewItem.Create(lItem, cnt));
    inc(cnt);
  end;
end;


{ TRunningTabInvoiceViewItem }

constructor TRunningTabInvoiceViewItem.Create(aLinetype: TxsdInvoiceLineType; aID: integer);
begin
  FLineType := aLineType;
  FID := aID;
end;

function TRunningTabInvoiceViewItem.GetDescription: string;
begin
  if FLineType.Item is TxsdBillableEntryType then
    Result := TxsdBillableEntryType(FLineType.Item).Description
  else
    Result := '';
end;

function TRunningTabInvoiceViewItem.GetId: integer;
begin
  Result := FId;
end;

function TRunningTabInvoiceViewItem.GetIndex: integer;
begin
  Result := FLineType.index_;
end;

function TRunningTabInvoiceViewItem.GetItemType: string;
begin
  if FLineType.Item is TxsdBillableEntryType then
    Result := TxsdBillableEntryType(FLineType.Item).ProductID
  else
    Result := '';
end;

end.
