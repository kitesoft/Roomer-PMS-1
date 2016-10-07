unit uRoomerReportGridForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs,
  uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCustomData,
  cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxSkinsdxStatusBarPainter, dxPSGlbl, dxPSUtl,
  dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.StdCtrls, sButton, System.Actions, Vcl.ActnList, dxPScxCommon,
  cxClasses, dxPSCore, kbmMemTable, cxPropertiesStore, dxStatusBar, cxGridLevel, cxGridCustomView,
  cxGridCustomTableView, cxGridTableView, cxGridDBTableView, cxGrid, Vcl.ExtCtrls, sPanel
  ;

type
  /// <summary>
  ///   Base roomer form with a non-editable wgrid usable for report etc <br />
  ///  Adds action buttons for refresh, Excel and Printing (Report)
  /// </summary>
  TfrmRoomerReportGridForm = class(TfrmBaseRoomerGridForm)
    btnRefresh: TsButton;
    btnExcel: TsButton;
    btnReport: TsButton;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

end.
