unit uDataSetFilterUtils;

interface

uses Data.DB,
     Vcl.ExtCtrls,
     cxGridDBTableView,
     cxFilter
     ;

procedure applyFilter(ds : TDataSet; text : String; timer : TTimer; tableView : TcxGridDBTableView);
procedure StopFilter(ds : TDataSet; timer : TTimer; tableView : TcxGridDBTableView);

implementation

procedure applyFilter(ds : TDataSet; text : String; timer : TTimer; tableView : TcxGridDBTableView);
var i : Integer;

    procedure RestartTimer;
    begin
      timer.Enabled := False;
      timer.Interval := 500;
      timer.Interval := 30;
      timer.Enabled := True;
    end;
begin
  if tableView.DataController.Filter.AutoDataSetFilter then
  begin
    ds.filtered := False;
    RestartTimer;
  end else
  begin
    tableView.DataController.Filter.Options := [fcoCaseInsensitive];
    tableView.DataController.Filter.Root.BoolOperatorKind := fboOr;
    tableView.DataController.Filter.Root.Clear;
    for i := 0 to tableView.ColumnCount - 1 do
      if tableView.Columns[i].DataBinding.ValueType = 'String' then
        tableView.DataController.Filter.Root.AddItem(tableView.Columns[i], foLike, '%'+text+'%', '%'+text+'%');
    tableView.DataController.Filter.Active := True;
  end;
end;

procedure StopFilter(ds : TDataSet; timer : TTimer; tableView : TcxGridDBTableView);
begin
  if tableView.DataController.Filter.AutoDataSetFilter then
  begin
    timer.Enabled := False;
    ds.filtered := False;
    tableView.DataController.Filter.Active := False;
    tableView.DataController.Filter.Changed;
  end else
  begin
    tableView.DataController.Filter.Root.Clear;
    tableView.DataController.Filter.Active := false;
    tableView.Invalidate(true);
  end;
end;


end.
