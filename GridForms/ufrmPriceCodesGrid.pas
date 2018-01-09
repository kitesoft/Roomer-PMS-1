unit ufrmPriceCodesGrid;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.Menus, dxPSCore, dxPScxCommon, System.Actions, Vcl.ActnList,
  cxGridBandedTableView, cxGridTableView, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sButton, sEdit, sCheckBox, sLabel,
  Vcl.Buttons, sSpeedButton, Vcl.ExtCtrls, sPanel, cxGridLevel, cxGridCustomView, cxGridCustomTableView,
  cxGridDBBandedTableView, cxGrid, Vcl.ComCtrls, sStatusBar, dxmdaset
  , hData
  ;

type
  TfrmPriceCodesGrid = class(TfrmBaseRoomerGridForm)
    m_: TdxMemData;
    m_ID: TIntegerField;
    m_pcCode: TWideStringField;
    m_pcDescription: TWideStringField;
    m_pcRack: TBooleanField;
    m_pcRackCalc: TFloatField;
    m_pcShowDiscount: TBooleanField;
    m_pcDiscountText: TWideStringField;
    m_pcAutomatic: TBooleanField;
    m_pcLastUpdate: TDateTimeField;
    m_pcDiscountMethod: TIntegerField;
    m_pcDiscountPriceAfter: TFloatField;
    m_pcDiscountDaysAfter: TIntegerField;
    m_Active: TBooleanField;
    tvDataRecId: TcxGridDBBandedColumn;
    tvDataID: TcxGridDBBandedColumn;
    tvDatapcCode: TcxGridDBBandedColumn;
    tvDataActive: TcxGridDBBandedColumn;
    tvDatapcDescription: TcxGridDBBandedColumn;
    tvDatapcRack: TcxGridDBBandedColumn;
  private
    { Private declarations }
  public
    constructor Create(aOwner: TComponent); override;
    { Public declarations }
  end;

function PriceCodes(aMode: TRoomerGridFormMode; var theData : recPriceCodeHolder) : boolean;

implementation

{$R *.dfm}

uses
  uAppGlobal
  , uG
  ;

{ TfrmVatCodesGrid }

function PriceCodes(aMode: TRoomerGridFormMode; var theData: recPriceCodeHolder): boolean;
begin
  with TfrmPriceCodesGrid.Create(nil) do
  try
    glb.TableList['pricecodes'].RefreshEnabled := false;
    SelectedCode := theData.pcCode;
    Result := ShowModal(aMode) in [mrClose, mrOk];
    if Result then
      theData.pcCode := SelectedCode;

  finally
    glb.TableList['pricecodes'].RefreshEnabled := true;
    if aMode = TRoomerGridFormMode.Browse then
      glb.TableList['pricecodes'].RefreshFromServer;
    Free;
  end;
end;

constructor TfrmPriceCodesGrid.Create(aOwner: TComponent);
begin
  inherited;
  ActiveFieldName := 'active';
  CodeFieldName := 'pccode';
  dsData.DataSet := glb.TblpricecodesSet;
end;

end.
