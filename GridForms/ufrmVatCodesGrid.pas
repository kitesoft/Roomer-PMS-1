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
    { Private declarations }
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
  end;


function VatCodes(aMode: TRoomerGridFormMode; var theData : recVatCodeHolder) : boolean;

implementation

{$R *.dfm}

uses
  uAppGlobal
  , uBookKeepingCodes, uG;

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

  finally
    glb.TableList['vatcodes'].RefreshEnabled := true;
    if aMode = TRoomerGridFormMode.Browse then
      glb.TableList['vatcodes'].RefreshFromServer;
    Free;
  end;

//
//  result := false;
//  frmVatCodes := TfrmVatCodes.Create(frmVatCodes);
//  try
//    frmVatCodes.zData := theData;
//    frmVatCodes.zAct := act;
//    frmVatCodes.ShowModal;
//    if ((act <> actLookup) AND frmVatCodes.VatCodeAdded AND (ActiveFinanceConnectSystemCode <> '')) AND
//       (MessageDlg(format(GetTranslatedText('Vat_FinanceConnect_AddedCode'), [ActiveFinanceConnectSystemName]),
//                    mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
//      begin
//        ManageFinanceConnect(PAGE_MAPPING, TAB_VATS);
//      end;
//    if frmVatCodes.modalresult = mrOk then
//    begin
//      theData := frmVatCodes.zData;
//      result := true;
//    end
//    else
//    begin
//      initVatCodeHolder(theData);
//    end;
//  finally
//    freeandnil(frmVatCodes);
//  end;
end;


constructor TfrmVatCodesGrid.Create(aOwner: TComponent);
begin
  inherited;
  ActiveFieldName := 'active';
  CodeFieldName := 'vatcode';
  dsData.DataSet := glb.VAT;
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
