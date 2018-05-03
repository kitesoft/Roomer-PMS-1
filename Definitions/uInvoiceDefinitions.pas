unit uInvoiceDefinitions;

interface

uses
  Classes,
  SysUtils
  ;

const
  cEmptyConfirmDate: TDateTime = 2.0; //'1900-01-01 00:00';
  cMaxFinalInvoiceNr = 999999999;

type
  EInvoiceIndexException = class(Exception);

  {$SCOPEDENUMS ON}
  // Type of invoice, used to be called SplitNumber (and still is in the db)
  TInvoiceType = (itDebitInvoice = 0, itCreditInvoice = 1, itCashInvoice = 2);

  TInvoiceIndex = integer;

  TInvoiceAddressType = (Customer=0, ReservationCustomer=1, RoomGuest=2, LastSaved=3, FreeText=4, Cash=5);
  TInvoiceAddressTypeHelper = record helper for TInvoiceAddressType
  private
    /// <summary>
    ///   Strings used in the database to store TInvoiceAddressType
    /// </summary>
    const cInvoiceAddressTypeStrings: array[TInvoiceAddressType] of string =
      ('CUSTOMER', ' RESERVATIONCUSTOMER' , 'ROOMGUEST', 'LASTSAVED', 'FREETEXT', 'CASH');
  public
      // constructor
      /// <summary>
      ///   Create a TInvoiceAddressType from a string
      /// </summary>
      class function FromString(const aInvoiceAddressType: string) : TInvoiceAddressType; static;
      class function FromItemIndex(aIndex: integer): TInvoiceAddressType; static;
      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TInvoiceAddressType as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;
      /// <summary>
      ///   Return as a string for db
      /// </summary>
      function AsDB: string;
      /// <summary>
      ///   Return the translated displaystring for a TInvoiceAddressType
      /// </summary>
      function AsReadableString : string;
  end;


implementation

uses PrjConst;

function TInvoiceAddressTypeHelper.AsDB: string;
begin
  Result := cInvoiceAddressTypeStrings[Self];
end;

function TInvoiceAddressTypeHelper.AsReadableString: string;
begin
  case Self of
    TInvoiceAddressType.Customer:             Result := GetTranslatedText('shInvoiceAddressType_Customer');
    TInvoiceAddressType.ReservationCustomer:  Result := GetTranslatedText('shInvoiceAddressType_ReservationCustomer');
    TInvoiceAddressType.RoomGuest:            Result := GetTranslatedText('shInvoiceAddressType_RoomGuest');
    TInvoiceAddressType.LastSaved:            Result := GetTranslatedText('shInvoiceAddressType_LastSaved');
    TInvoiceAddressType.FreeText:             Result := GetTranslatedText('shInvoiceAddressType_FreeText');
    TInvoiceAddressType.Cash:                 Result := GetTranslatedText('shInvoiceAddressType_Cash');
  end;
end;

class procedure TInvoiceAddressTypeHelper.AsStrings(aItemList: TStrings);
var
  lSetting: TInvoiceAddressType;
begin
  aItemList.BeginUpdate;
  try
    aItemList.Clear;
    for lSetting := low(lSetting) to high(lSetting) do
      aItemList.Add(lSetting.AsReadableString);
  finally
    aItemList.EndUpdate;
  end;
end;

class function TInvoiceAddressTypeHelper.FromItemIndex(aIndex: integer): TInvoiceAddressType;
begin
  Result := TInvoiceAddressType(aIndex);
end;

class function TInvoiceAddressTypeHelper.FromString(const aInvoiceAddressType: string): TInvoiceAddressType;
var
  lSetting: TInvoiceAddressType;
begin
  Result := TinvoiceAddressType.Customer;
  for lSetting := low(TInvoiceAddressType) to high(TInvoiceAddressType) do
    if lSetting.AsDB.equals(aInvoiceAddressType) then
    begin
      Result := lSetting;
      Break;
    end;
end;

function TInvoiceAddressTypeHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;



end.
