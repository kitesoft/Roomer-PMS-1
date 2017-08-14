unit ucxGridPopupMenuActivator;

interface

uses
    VCL.Menus
  ;

type
  /// <summary>
  ///  Class to add Popupmenu functionality to the header of a TcxGridColumn.
  ///  The class must be instantiated with the PopupMenu to activate when a column header is clicked.
  ///  The OnHeaderClick event of the column must be set to the onCxHeaderClick method if this class
  ///
  ///  The popup menu is shown if the header of the column contains an image in the glyph area and the click is done in that GLyph area.
  /// </summary>
  TcxGridColumnHeaderPopupMenuActivator = class(TObject)
  private
    FPopup: TPopupMenu;
  public
    constructor Create(aPopupMenu: TPopupMenu);

    /// <summary>
    ///   Event handler for OnHeaderClick event of a column of a TcxGrid
    ///  If a click is detected in the Glyph area of a columnheader, then the column.Index is placed in the Tag property of the popupmenu
    ///  and the popup menu is activated
    /// </summary>
    procedure OnCxColumnHeaderClick(Sender: TObject);
  end;

implementation

uses
    cxGridTableView
  , Windows
  ;

constructor TcxGridColumnHeaderPopupMenuActivator.Create(aPopupMenu: TPopupMenu);
begin
  FPopup := aPopupMenu;
  FPopup.Tag := -1;
end;

procedure TcxGridColumnHeaderPopupMenuActivator.OnCxColumnHeaderClick(Sender: TObject);
var
  lColumn: TcxGridColumn;
  lView: TcxGridTableView;
  I: Integer;
  AInfo: TcxGridColumnHeaderGlyphViewInfo;
  lMousept: TPoint;
  pt: TPoint;
begin
  Assert(Sender is TcxGridColumn, 'OnCxColumnHeaderClick: Wrong sender type class');

  lColumn := TcxGridColumn(Sender);
  lView := lColumn.GridView;

  GetCursorPos(lMousePt);
  pt := lView.Site.ScreenToClient(lMousePt);
  FPopup.Tag := -1;

  for I := 0 to lView.ViewInfo.HeaderViewInfo[lColumn.VisibleIndex].AreaViewInfoCount - 1 do
    if lView.ViewInfo.HeaderViewInfo[lColumn.VisibleIndex].AreaViewInfos[i] is TcxGridColumnHeaderGlyphViewInfo then
    begin
      AInfo := TcxGridColumnHeaderGlyphViewInfo(lView.ViewInfo.HeaderViewInfo[lColumn.VisibleIndex].AreaViewInfos[i]);
      if PtInRect(AInfo.Bounds, Pt) then
      begin
        FPopup.Tag := lColumn.Index;
        FPopup.Popup(lMousePt.X, lMousePt.y);
        Break;
      end;
    end;
end;



end.
