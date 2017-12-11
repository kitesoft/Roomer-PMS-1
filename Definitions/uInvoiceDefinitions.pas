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
(*  TInvoiceIndex = record
  type
    TInvoiceindexDomain = 0..9;
  private
    Value: TInvoiceindexDomain;
  public
    class operator Implicit(v: integer): TInvoiceIndex;
    class operator Implicit(i: TInvoiceIndex): integer;
    class operator Explicit(i: TInvoiceIndex): integer;
    class operator Equal(a, b: TInvoiceIndex): boolean;
    class operator NotEqual(a, b: TInvoiceIndex): boolean;
  end;

*)
implementation
(*
{ TinvoiceIndexHelper }

class operator TinvoiceIndex.Implicit(v: integer): TInvoiceIndex;
begin
  if (v >= Low(TInvoiceindexDomain)) and (v <= High(TInvoiceindexDomain)) then
    Result.value := v
  else
    raise EInvoiceIndexException.CreateFmt('Invalid invoiceindex [%d]', [v]);
end;

class operator TInvoiceIndex.Equal(a, b: TInvoiceIndex): boolean;
begin
  Result := a.Value = b.Value;
end;

class operator TInvoiceIndex.Explicit(i: TInvoiceIndex): integer;
begin
  Result := i.Value;
end;

class operator TInvoiceIndex.Implicit(i: TInvoiceIndex): integer;
begin
  Result := i.Value;
end;

class operator TInvoiceIndex.NotEqual(a, b: TInvoiceIndex): boolean;
begin
  Result := not (a = b);
end;
*)
end.
