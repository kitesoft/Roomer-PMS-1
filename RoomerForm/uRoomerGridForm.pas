unit uRoomerGridForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData,
  Vcl.ExtCtrls, sPanel, cxGridLevel, cxGridCustomView, cxGridCustomTableView, cxGridDBTableView, cxGrid,
  cxGridBandedTableView, cxGridDBBandedTableView
  ,uRoomerForm
  , uRoomerDialogForm, Vcl.StdCtrls, sButton
  ;

type
  /// <summary>
  ///   RoomerBaseForm extended with a Grid with a basic dataview.
  ///   The default view is connected to the global stylesheet and the columnorder and width of all defined views are saved
  ///   in the psRoomerBase properties store.
  ///  Notice that it is only possible for TcxGridDBBandedTableViews to persist the columnorder, columns in a normal TcxGridDBTableView
  ///  do not support this.
  /// </summary>
  TfrmBaseRoomerGridForm = class(TfrmBaseRoomerDialogForm)
    grData: TcxGrid;
    pnlTop: TsPanel;
    dsData: TDataSource;
    tvData: TcxGridDBBandedTableView;
    lvData: TcxGridLevel;
    cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet;
    procedure btnCloseClick(Sender: TObject);
  private
  protected
    procedure Loaded; override;
    /// <summary>
    ///   Adds columnindex and width of all columns of all TcxGridDBBandedTableViews in aGrid to the ppRoomerBase propertiesStore.
    ///   This will keep the user defined order and width of columns persistent
    /// </summary>
    procedure AddViewColumnPropsToStore(aGrid: TcxGrid);
    /// <summary>
    ///   Called from the Loaded procedure, sets the default settings of the Grid
    /// </summary>
    procedure InitializeGridProperties; virtual;
    procedure DoShow; override;
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  ;

{ TfrmBaseRoomerGridForm }

procedure TfrmBaseRoomerGridForm.Loaded;
begin
  inherited;
  AddViewColumnPropsToStore(grData);

  InitializeGridProperties;
end;

procedure TfrmBaseRoomerGridForm.btnCloseClick(Sender: TObject);
begin
  inherited;
  if assigned(dsData.DataSet) and (dsData.Dataset.Active) then
    dsData.DataSet.CheckBrowseMode;
end;

procedure TfrmBaseRoomerGridForm.DoShow;
begin
  inherited;
  DialogButtons := [mbClose];
end;

procedure TfrmBaseRoomerGridForm.InitializeGridProperties;
begin
  tvData.OptionsView.NoDataToDisplayInfoText := GetTranslatedText('shBaseGridForm_NoDataToDisplay');
end;

procedure TfrmBaseRoomerGridForm.AddViewColumnPropsToStore(aGrid: TcxGrid);
var
  v: integer;
  c: integer;
  lStoreComp: TcxPropertiesStoreComponent;
begin
  for v := 0 to aGrid.viewCount -1 do
    if aGrid.Views[v] is TcxGridDBBandedTableView then
      with TcxGridDBBandedTableView(aGrid.Views[v]) do
        for c := 0 to ColumnCount-1 do
        begin
          if not psRoomerBase.Components.FindComponentItemByComponent(Columns[c], lStoreComp) then
          begin
            lStoreComp := psRoomerBase.Components.Add;
            lStoreComp.Component := Columns[c];
            lStoreComp.Properties.Add('Position.ColumnIndex');
            lStoreComp.Properties.Add('Width');
          end;
        end;
end;

end.
