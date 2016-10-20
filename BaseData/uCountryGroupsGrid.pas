unit uCountryGroupsGrid;

interface

uses
    Windows
  , Messages
  , SysUtils
  , uRoomerEditableGridForm
  , dxSkinsdxStatusBarPainter, kbmMemTable, System.Actions, Vcl.ActnList, dxStatusBar,
  cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCustomData, cxFilter, cxData,
  cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap,
  dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils,
  dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk,
  dxPScxEditorProducers, dxPScxExtEditorProducers, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.Menus, dxPSCore,
  dxPScxCommon, System.Classes, cxGridTableView, cxClasses, cxPropertiesStore, cxGridLevel, cxGridCustomView,
  cxGridCustomTableView, cxGridDBTableView, cxGrid, Vcl.StdCtrls, sButton, Vcl.Controls, Vcl.ExtCtrls, sPanel

  ;

type
  TfrmCountryGroupsGrid = class(TfrmRoomerEditableGridForm)
    kbmGridDataad: TIntegerField;
  private
  protected
    function ValidateCurrentData: boolean; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
  end;


function CountryGroupsGrid({act : TActTableAction; var theData : recCountryGroupHolder} ) : boolean;

implementation

uses
    uD
  , uSqlDefinitions
  , UITypes
  , uRoomerDataProvider
  ;

{$R *.dfm}


type
  TCountryGroupsDataProvider = class(TRoomerTableEntityDataProvider)
  public
    constructor Create; override;
  end;


constructor TCountryGroupsDataProvider.Create;
begin
  FBaseTableName := 'countrygroups';
  inherited;
end;



function CountryGroupsGrid({act : TActTableAction; var theData : recCountryGroupHolder }) : boolean;
var
  frm: TfrmCountryGroupsGrid;
begin
  result := false;
  frm := TfrmCountryGroupsGrid.Create(nil);
  try
    if (frm.ShowModal in [mrOK, mrYes]) then
    begin

    end;
//    frmCountryGroups.zData := theData;
//    frmCountryGroups.zAct := act;
//    frmCountryGroups.ShowModal;
//    if frmCountryGroups.modalresult = mrOk then
//    begin
//      theData := frmCountryGroups.zData;
//      result := true;
//    end
//    else
//    begin
//      initCountryGroupHolder(theData);
//    end;
  finally
    frm.Free;
  end;
end;


constructor TfrmCountryGroupsGrid.Create(aOwner: TComponent);
begin
  FDataProviderClass := TCountryGroupsDataProvider;
  inherited;
  // Todo: Use translations!
  Caption := 'Country Groups';
end;


function TfrmCountryGroupsGrid.ValidateCurrentData: boolean;
begin
  Result := inherited;
end;

end.
