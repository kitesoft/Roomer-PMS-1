unit uTopClassAvailabilityOrder;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, sPanel, Vcl.ComCtrls, sListView, cxClasses, cxPropertiesStore,
  uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, sStatusBar
  ;

type
  ETopClassAvailabilityOrderException = class(Exception);

  TFrmTopClassAvailabilityOrder = class(TfrmBaseRoomerForm)
    panBtn: TsPanel;
    BtnOk: TsButton;
    sPanel1: TsPanel;
    pnlOrder: TsPanel;
    btnUp: TsButton;
    btnDown: TsButton;
    lvRates: TsListView;
    btnCancel: TsButton;
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure lvRatesDragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
    procedure btnUpClick(Sender: TObject);
    procedure btnDownClick(Sender: TObject);
    procedure lvRatesDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure lvRatesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
    procedure BtnOkClick(Sender: TObject);
  private
    FDirty : Boolean;
    procedure SaveRates;
    function MoveListViewItem(ListView: TsListView; ItemFrom, ItemTo: Word): Boolean;
    { Private declarations }
  protected
    procedure DoLoadData; override;
  public
    { Public declarations }
  end;

procedure EditAvailabilityOrder;

implementation

{$R *.dfm}

uses ud
    , cmpRoomerDataSet
    , hData
    , udImages
    ;

procedure EditAvailabilityOrder;
var
  FrmTopClassAvailabilityOrder: TFrmTopClassAvailabilityOrder;
begin
  FrmTopClassAvailabilityOrder := TFrmTopClassAvailabilityOrder.Create(nil);
  try
    FrmTopClassAvailabilityOrder.ShowModal;
  finally
    FrmTopClassAvailabilityOrder.Free;
  end;
end;


procedure TFrmTopClassAvailabilityOrder.btnDownClick(Sender: TObject);
begin
  FDirty := lvRates.Selected <> nil;
//Move Down
 if lvRates.Selected <> nil then
  MoveListViewItem(lvRates, lvRates.Selected.Index, lvRates.Selected.Index + 2);
end;

procedure TFrmTopClassAvailabilityOrder.BtnOkClick(Sender: TObject);
begin
  if FDirty then
    SaveRates;
end;

procedure TFrmTopClassAvailabilityOrder.btnUpClick(Sender: TObject);
begin
  FDirty := lvRates.Selected <> nil;
//Move Up
 if lvRates.Selected <> nil then
  MoveListViewItem(lvRates, lvRates.Selected.Index, lvRates.Selected.Index -1);
end;


procedure TFrmTopClassAvailabilityOrder.FormCreate(Sender: TObject);
begin
  FDirty := False;
end;

procedure TFrmTopClassAvailabilityOrder.FormShow(Sender: TObject);
begin
  RefreshData;
end;

procedure TFrmTopClassAvailabilityOrder.DoLoadData;
var s : String;
    rSet : TRoomerDataSet;
    lv : TListItem;
begin
  inherited;

  s := 'SELECT IFNULL(tao.`order`, @CNT:=IF(ISNULL(@CNT) OR @CNT=0, 90000, @CNT)+1) AS availabilityOrder, ' +
       'rtg.id AS roomClassId, rtg.Code, rtg.description ' +
       'FROM roomtypegroups rtg ' +
       'LEFT JOIN topclassavailabilityorder tao ON tao.roomClassId=rtg.id ' +
       'WHERE rtg.Code=rtg.TopClass ' +
       'AND rtg.Active ' +
       'ORDER BY availabilityOrder, Code';
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, s) then
    begin
      rSet.First;
      while NOT rSet.Eof do
      begin
        lv := lvRates.Items.Add;
        lv.Caption := rSet['Code'];
        lv.SubITems.Add(rSet['description']);
        lv.Data := Pointer(rSet.FieldByName('roomClassId').AsInteger);
        rSet.Next;
      end;
    end;
  finally
    rSet.Free;
  end;

end;

procedure TFrmTopClassAvailabilityOrder.lvRatesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
begin
 btnUp.Enabled := Assigned(lvRates.Selected) AND (lvRates.Selected.Index > 0);
 btnDown.Enabled := Assigned(lvRates.Selected) AND (lvRates.Selected.Index < lvRates.Items.Count - 1);
end;

procedure TFrmTopClassAvailabilityOrder.lvRatesDragDrop(Sender, Source: TObject; X, Y: Integer);
var
  DragItem, DropItem, CurrentItem, NextItem: TListItem;
begin
  if Sender = Source then
    with TListView(Sender) do
    begin
      DropItem    := GetItemAt(X, Y);
      CurrentItem := Selected;
      while CurrentItem <> nil do
      begin
        NextItem := GetNextItem(CurrentItem, SdAll, [IsSelected]);
        if DropItem = nil then DragItem := Items.Add
        else
          DragItem := Items.Insert(DropItem.Index);
        DragItem.Assign(CurrentItem);
        CurrentItem.Free;
        CurrentItem := NextItem;
      end;
    end;
end;

procedure TFrmTopClassAvailabilityOrder.lvRatesDragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
begin
  Accept := Sender = lvRates;
end;

procedure TFrmTopClassAvailabilityOrder.SaveRates;
var s : String;
    ExecutionPlan : TRoomerExecutionPlan;
    i, id: Integer;
begin
  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    s := 'DELETE FROM topclassavailabilityorder';
    ExecutionPlan.AddExec(s);

    s := 'INSERT INTO topclassavailabilityorder (roomClassId, `order`) VALUES(%d, %d) ';
    for i := 0 to lvRates.Items.Count - 1 do
    begin
      id := INTEGER(lvRates.Items[i].Data);
      ExecutionPlan.AddExec(format(s, [id, i]));
    end;
    try
      ExecutionPlan.Execute(ptExec, True, True);
    except on E: Exception do
      raise ETopClassAvailabilityOrderException.CreateFmt('Error during saving of data:'+ #10 + '%s', [e.Message]);
    end;
  finally
    ExecutionPlan.Free;
  end;
end;

function TFrmTopClassAvailabilityOrder.MoveListViewItem(ListView: TsListView; ItemFrom, ItemTo: Word): Boolean;
var
  Source, Target: TListItem;
begin
  listview.Items.BeginUpdate;
  try
    Source := ListView.Items[ItemFrom];
    Target := ListView.Items.Insert(ItemTo);
    Target.Assign(Source);
    Target.Selected := True;
    Source.Free;
    Result := True;
  finally
    ListView.Items.EndUpdate;
  end;
end;

end.
