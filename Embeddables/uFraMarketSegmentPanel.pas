unit uFraMarketSegmentPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uFraLookupPanel, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraLookupMarketSegment = class(TfraCustomLookupPanel)
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
  , uCustomerTypes2
  , uAppGlobal
  , uG
  ;

{ TfraLookupMarketSegment }

constructor TfraLookupMarketSegment.Create(aOwner: TComponent);
begin
  inherited;
  Dataset := glb.CustomertypesSet;
  CodeField := 'customertype';
  DescriptionField := 'description';
end;

procedure TfraLookupMarketSegment.DoInternalSelect;
var
  theData: recCustomerTypeHolder;
begin
  inherited;
  theData.customerType := Code;
  if openCustomerTypes(actLookup, theData) then
    Code := theData.customerType;
end;

end.
