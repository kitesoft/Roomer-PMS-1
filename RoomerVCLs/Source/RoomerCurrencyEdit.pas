unit RoomerCurrencyEdit;

interface

uses
  sCurrencyEdit
  , uCurrencyConstants
  , sCurrEdit
  ;

type
  /// <summary>
  /// Override of sCurrencyEdit component with the following addditions:
  ///  - Interpret both DOT ansd COMMA as decimal separator
  ///  - Added a CurrencCode property which is used to construct the DisplayText in the correct decimals
  /// </summary>
  TRoomerCurrencyEdit = class(TsCurrencyEdit)
  private
    FCurrencyCode: TCurrencyCode;
    procedure SetCurrencyCode(Value: TCurrencyCode);
  protected
    function GetDisplayText: string; override;
    procedure KeyPress(var Key: Char); override;
  public
    property CurrencyCode: TCurrencyCode read FCurrencyCode write SetCurrencyCode;
  end;

  // Override original component, no need for designtime installation
  // Note: Include RoomerCurrencyEdit AFTER sCurrencyEdit!
  TsCurrencyEdit = class(TROomerCurrencyEdit)
  end;


implementation

uses
  SysUtils
  , uRoomerCurrencymanager
  ;

{ TRoomerCurrencyEdit }

function TRoomerCurrencyEdit.GetDisplayText: string;
begin
  if not Focused then
    Result := RoomerCurrencyManager[FCurrencyCode].FormattedValue(Value)
  else
    Result := EditText;
end;

procedure TRoomerCurrencyEdit.KeyPress(var Key: Char);
begin
  if CharInSet(Key, [',', '.']) then
    Key := FormatSettings.DecimalSeparator;
  inherited;
end;

procedure TRoomerCurrencyEdit.SetCurrencyCode(Value: TCurrencyCode);
begin
  FCurrencyCode := Value;
  Invalidate;
end;

end.
