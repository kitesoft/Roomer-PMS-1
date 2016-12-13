unit uAmountConfigurator;

interface

type
  TCurrencyCode = string[5];

  TAmountConfigurator = class
  private
    class var FDefCurCode: TCurrencyCode;
  private
    class function GetDefaultCurrency: TCurrencyCode; static;
    class procedure SetDefaultCurrency(const Value: TCurrencyCode); static;
  public
    class property DefaultCurrency: TCurrencyCode read GetDefaultCurrency write SetDefaultCurrency;
  end;

implementation

{ TAmountConfigurator }

class function TAmountConfigurator.GetDefaultCurrency: TCurrencyCode;
begin
  Result := FDefCurCode;
end;

class procedure TAmountConfigurator.SetDefaultCurrency(const Value: TCurrencyCode);
begin
  FDefCurCode := Value;
end;

initialization
  TAmountConfigurator.DefaultCurrency := 'EUR';

end.
