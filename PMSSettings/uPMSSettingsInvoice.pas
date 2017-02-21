unit uPMSSettingsInvoice;

interface

uses
  uPMSSettings
  ;

type
/ </summary>

  end;

implementation

{ TPMSSettingsInvoice }

function TPMSSettingsInvoice.GetShowInvoiceAsPaidWhenStatusIsZero: boolean;
begin
  Result := GetSettingsAsBoolean(cInvoiceHandlingGroup, cInvoiceHandlingShowAsPaidWhenZero, False);
end;


end;

procedure TPMSSettingsInvoice.SetShowInvoiceAsPaidWhenStatusIsZero(const Value: boolean);
begin

end;

end.
