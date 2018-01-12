unit uCachedPriceCodesTable;

interface

uses
  uTableEntityList
  , Data.DB
  ;

type
  TCachedPriceCodesTable = class(TCachedTableEntity)
  private
    procedure OnNewRecord(DataSet: TDataSet);
  public
    constructor Create(const tableName : String; aTimestampHandler: ICachedTimestampHandler; const sqlExtension : String = ''); override;
  end;

implementation

{ TCachedVATTable }

uses
  hData
  , PrjConst
  , Dialogs
  , SysUtils
  ;

constructor TCachedPriceCodesTable.Create(const tableName: String; aTimestampHandler: ICachedTimestampHandler;
  const sqlExtension: String);
begin
  inherited;
  RSet.OnNewRecord := OnNewRecord;
end;

procedure TCachedPriceCodesTable.OnNewRecord(DataSet: TDataSet);
begin
  Dataset.FieldByName('Active').asBoolean := true;
  Dataset.FieldByName('pcrack').asBoolean := false;
end;

end.
