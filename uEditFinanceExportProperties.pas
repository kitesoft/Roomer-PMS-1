unit uEditFinanceExportProperties;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, sPanel, sCheckBox, sEdit, sLabel;

type
  TfrmEditFinanceExportProperties = class(TForm)
    sLabel1: TsLabel;
    lblExternalSystemsInvoiceNumber: TsLabel;
    edtExternalSystemsInvoiceNumber: TsEdit;
    __lblRoomerNumber: TsLabel;
    cbxExportableToFinance: TsCheckBox;
    pnlButtons: TsPanel;
    btnCancel: TsButton;
    BtnOk: TsButton;
    lblExportableToFinance: TsLabel;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmEditFinanceExportProperties: TfrmEditFinanceExportProperties;

procedure editFinanceExportProperties(invoiceNumber : Integer; var externalId : Integer; var exportable : Boolean);

implementation

{$R *.dfm}

uses uUtils, uD;

procedure editFinanceExportProperties(invoiceNumber : Integer; var externalId : Integer; var exportable : Boolean);
var frmEdit: TfrmEditFinanceExportProperties;
    sql : String;
begin
  frmEdit := TfrmEditFinanceExportProperties.Create(nil);
  try
    frmEdit.__lblRoomerNumber.Caption := inttostr(externalId);
    frmEdit.edtExternalSystemsInvoiceNumber.Text := inttostr(externalId);
    frmEdit.cbxExportableToFinance.Checked := exportable;
    if frmEdit.showModal = mrOk then
    begin
      externalId := StrToInt(frmEdit.edtExternalSystemsInvoiceNumber.Text);
      exportable := frmEdit.cbxExportableToFinance.Checked;
      sql := format('UPDATE invoiceheads SET externalInvoiceId=%d, exportAllowed=%d WHERE invoiceNumber=%d',
            [
              externalId,
              IIF(exportable, 1, 0),
              invoiceNumber
            ]);
      d.roomerMainDataSet.DoCommand(sql);
    end;
  finally
    FreeAndNil(frmEdit);
  end;
end;

end.
