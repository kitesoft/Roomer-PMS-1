unit ufrmVatCodesGrid;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPSCore, dxPScxCommon, System.Actions, Vcl.ActnList,
  cxGridBandedTableView, cxGridTableView, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sButton, sEdit, sCheckBox, sLabel,
  Vcl.Buttons, sSpeedButton, Vcl.ExtCtrls, sPanel, cxGridLevel, cxGridCustomView, cxGridCustomTableView,
  cxGridDBBandedTableView, cxGrid, Vcl.ComCtrls, sStatusBar
  , hData, Vcl.Menus, dxmdaset, cxTextEdit, cxCalc, cxButtonEdit;

type
  TfrmVatCodesGrid = class(TfrmBaseRoomerGridForm)
    m_: TdxMemData;
    m_VATCode: TWideStringField;
    m_Description: TWideStringField;
    m_VATPercentage: TFloatField;
    m_BookKeepCode: TWideStringField;
    m_valueFormula: TWideStringField;
    m_active: TBooleanField;
    tvDataRecId: TcxGridDBBandedColumn;
    tvDataVATCode: TcxGridDBBandedColumn;
    tvDataDescription: TcxGridDBBandedColumn;
    tvDataVATPercentage: TcxGridDBBandedColumn;
    tvDataBookKeepCode: TcxGridDBBandedColumn;
    tvDatavalueFormula: TcxGridDBBandedColumn;
    tvDataactive: TcxGridDBBandedColumn;
    procedure tvDataBookKeepCodePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
  private
    FVatCodesAdded: Boolean;
    procedure evtVatCodeInserted(Sender: TDataset);
    { Private declarations }
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
  end;


function VatCodes(aMode: TRoomerGridFormMode; var theData : recVatCodeHolder) : boolean;

implementation

{$R *.dfm}

uses
  uAppGlobal
  , uBookKeepingCodes
  , uG
  , uFinanceConnectService
  , uFrmFinanceConnect
  , PrjConst
  ;

{ TfrmVatCodesGrid }

function VatCodes(aMode: TRoomerGridFormMode; var theData: recVatCodeHolder): boolean;
begin
  with TfrmVatCodesGrid.Create(nil) do
  try
    glb.TableList['vatcodes'].RefreshEnabled := false;
    SelectedCode := theData.VatCode;
    Result := ShowModal(aMode) in [mrClose, mrOk];
    if Result then
      theData.VatCode := SelectedCode;

    if ((aMode <> TRoomerGridFormMode.SelectSingle) AND FVatCodesAdded AND (ActiveFinanceConnectSystemCode <> '')) AND
       (MessageDlg(format(GetTranslatedText('Vat_FinanceConnect_AddedCode'), [ActiveFinanceConnectSystemName]),
                    mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
        ManageFinanceConnect(PAGE_MAPPING, TAB_VATS);

  finally
    glb.TableList['vatcodes'].RefreshEnabled := true;
    if aMode = TRoomerGridFormMode.Browse then
      glb.TableList['vatcodes'].RefreshFromServer;
    Free;
  end;
end;


constructor TfrmVatCodesGrid.Create(aOwner: TComponent);
begin
  inherited;
  FVatCodesAdded := false;
  ActiveFieldName := 'active';
  CodeFieldName := 'vatcode';
  dsData.DataSet := glb.VAT;
  Assert(not assigned(dsData.Dataset.AfterInsert));
  dsData.Dataset.AfterInsert := evtVatCodeInserted;
end;

destructor TfrmVatCodesGrid.Destroy;
begin
  dsData.Dataset.AfterInsert := nil;
  inherited;
end;

procedure TfrmVatCodesGrid.evtVatCodeInserted(Sender: TDataset);
begin
  FVatCodesAdded := true;
end;

procedure TfrmVatCodesGrid.tvDataBookKeepCodePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var s : String;
begin
  s := '';
  if NOT dsData.Dataset.Eof then
    s := dsData.Dataset['BookKeepCode'];
  s := BookKeepingCodes(actLookUp, s);
  if s <> '' then
  begin
    dsData.Dataset.Edit;
    dsData.Dataset['BookKeepCode'] := s;
    dsData.Dataset.Post;
  end;
end;

end.
