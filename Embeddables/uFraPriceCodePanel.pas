unit uFraPriceCodePanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uFraLookupPanel, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraPriceCodePanel = class(TfraCustomLookupPanel)
  protected
    { Private declarations }
    procedure DoInternalSelect; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
  end;


implementation

{$R *.dfm}

uses
  hData
  , uAppGlobal
  , uG
  , uPriceCodes;

{ TfraPriceCodePanel }

constructor TfraPriceCodePanel.Create(aOwner: TComponent);
begin
  inherited;
  Dataset := glb.TblpricecodesSet;
  CodeField := 'pccode';
  DescriptionField := 'pcdescription';
end;

procedure TfraPriceCodePanel.DoInternalSelect;
var
  theData: recPriceCodeHolder;
begin
  inherited;
  theData.pcCode := Code;
  if priceCodes(actLookup, theData) then
    Code := theData.pcCode;
end;

end.
