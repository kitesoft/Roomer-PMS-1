unit uRoomerGridDBBandedTableView;

interface

uses
  cxGridDBBandedTableView
  , cxGridCustomTableView
  , cxGridTableView
  , VCL.Menus
  ;

type

  TRoomerGridDBBandedTableView = class;

  TRoomerGridDBBandedColumn = class(TcxGridDBBandedColumn)
  private
    FPopupMenu: TPopupMenu;
  protected
    procedure DoHeaderClick; override;

  published
    property Popupmenu: TPopupMenu read FPopupMenu write FPopUpMenu;
  end;

  TRoomerGridDBBandedTableView = class(TcxGridDBBandedTableView)
  private
    function GetColumn(Index: Integer): TRoomerGridDBBandedColumn;
    procedure SetColumn(Index: Integer; const Value: TRoomerGridDBBandedColumn);
  protected
    function GetItemClass: TcxCustomGridTableItemClass; override;
    procedure DoColumnHeaderClick(AColumn: TcxGridColumn); override;
  public
    function CreateColumn: TRoomerGridDBBandedColumn;
    function GetColumnByFieldName(const AFieldName: string): TRoomerGridDBBandedColumn;
    property Columns[Index: Integer]: TRoomerGridDBBandedColumn read GetColumn write SetColumn;
  published
  end;


implementation

uses
  cxGridCustomView
  , Classes
  ;

{ TRoomerGridDBBandedTableView }

function TRoomerGridDBBandedTableView.CreateColumn: TRoomerGridDBBandedColumn;
begin
  Result := TRoomerGridDBBandedColumn(inherited CreateColumn);
end;

procedure TRoomerGridDBBandedTableView.DoColumnHeaderClick(AColumn: TcxGridColumn);
var
  I: Integer;
  AInfo: TcxGridColumnHeaderGlyphViewInfo;
  lMousept: TPoint;
  pt: TPoint;
begin
  GetCursorPos(lMousePt);
  pt := Sender.Site.ScreenToClient(lMousePt);
  mnuRoomColumn.Tag := -1;
  for I := 0 to Sender.ViewInfo.HeaderViewInfo[AColumn.VisibleIndex].AreaViewInfoCount - 1 do
    if Sender.ViewInfo.HeaderViewInfo[AColumn.VisibleIndex].AreaViewInfos[i] is TcxGridColumnHeaderGlyphViewInfo then
    begin
      AInfo := TcxGridColumnHeaderGlyphViewInfo(Sender.ViewInfo.HeaderViewInfo[AColumn.VisibleIndex].AreaViewInfos[i]);
      if PtInRect(AInfo.Bounds, Pt) then
      begin
        mnuRoomColumn.Tag := aColumn.Index;
        mnuRoomColumn.Popup(lMousePt.X, lMousePt.y);
        Break;
      end;
    end;

  inherited;
end;

function TRoomerGridDBBandedTableView.GetColumn(Index: Integer): TRoomerGridDBBandedColumn;
begin
  Result := TRoomerGridDBBandedColumn(inherited Columns[Index]);
end;

function TRoomerGridDBBandedTableView.GetColumnByFieldName(const AFieldName: string): TRoomerGridDBBandedColumn;
begin
  Result := TRoomerGridDBBandedColumn(DataController.GetItemByFieldName(AFieldName));
end;

function TRoomerGridDBBandedTableView.GetItemClass: TcxCustomGridTableItemClass;
begin
  Result := TRoomerGridDBBandedColumn;
end;

procedure TRoomerGridDBBandedTableView.SetColumn(Index: Integer; const Value: TRoomerGridDBBandedColumn);
begin
  inherited Columns[Index] := Value;
end;

{ TRoomerGridDBBandedColumn }

procedure TRoomerGridDBBandedColumn.DoHeaderClick;
begin
  inherited;

end;

initialization
  cxGridRegisteredViews.Register(TRoomerGridDBBandedTableView, 'Roomer DB Banded Table');
  Classes.RegisterClass(TRoomerGridDBBandedColumn);

finalization
  cxGridRegisteredViews.Unregister(TcxGridDBBandedTableView);


end.
