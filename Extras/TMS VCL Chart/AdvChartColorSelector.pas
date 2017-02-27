{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright © 2016                                        }
{            Email : info@tmssoftware.com                            }
{            Web : http://www.tmssoftware.com                        }
{                                                                    }
{ The source code is given as is. The author is not responsible      }
{ for any possible damage done due to the use of this code.          }
{ The complete source code remains property of the author and may    }
{ not be distributed, published, given or sold in any form as such.  }
{ No parts of the source code can be included in any other component }
{ or application without written authorization of the author.        }
{********************************************************************}

unit AdvChartColorSelector;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  Classes, AdvChartGraphics, AdvChartCustomSelector, Controls,
  AdvChartTypes, ExtCtrls
  {$IFDEF FMXLIB}
  ,FMX.Types, FMX.Colors
  {$ENDIF}
  {$IFNDEF LCLLIB}
  ,Types, StdCtrls
  {$ENDIF}
  ;

const
  MAJ_VER = 1; // Major version nr.
  MIN_VER = 0; // Minor version nr.
  REL_VER = 0; // Release nr.
  BLD_VER = 0; // Build nr.

  //v1.0.0.0: First release

const
  AdvChartColorSelectorColorSet: array[0..15] of TAdvChartGraphicsColor = (gcBlack, gcMaroon, gcGreen, gcOlive,
    gcNavy, gcPurple, gcTeal, gcSilver, gcGray, gcRed,
    gcLime, gcYellow, gcBlue, gcFuchsia, gcAqua, gcWhite);

  {$IFDEF FMXLIB}
  AdvChartColorSelectorExtendedColorSet: array[0..39] of TAdvChartGraphicsColor = (gcBlack, $FF003399, $FF003333, $FF003300, $FF663300, gcNavy,
    $FF353333, $FF333333, $FF800000, $FFFF6600, $FF808000, $FF008000, $FF008080, $FF0000FF,
    $FF666699, $FF808080, $FFFF0000, $FFFF9900, $FF99CC00, $FF339966, $FF33CCCC,
    $FF3366FF, $FF800080, $FF999999, $FFFF00FF, $FFFFCC00, $FFFFFF00, $FF00FF00,
    $FF00FFFF, $FF00CCFF, $FF993366, $FFC0C0C0, $FFFF99CC, $FFFFCC99, $FFFFFF99,
    $FFCCFFCC, $FFCCFFFF, $FF99CCFF, $FFCC99FF, $FFFFFFFF);
  {$ENDIF}

  {$IFDEF CMNLIB}
  AdvChartColorSelectorExtendedColorSet: array[0..39] of TAdvChartGraphicsColor = (gcBlack, $993300, $333300, $003300, $003366, gcNavy,
    $333335, $333333, $000080, $0066FF, $008080, $008000, $808000, $FF0000,
    $996666, $808080, $0000FF, $0099FF, $00CC99, $669933, $CCCC33,
    $FF6633, $800080, $999999, $FF00FF, $00CCFF, $00FFFF, $00FF00,
    $FFFF00, $FFCC00, $663399, $C0C0C0, $CC99FF, $99CCFF, $99FFFF,
    $CCFFCC, $FFFFCC, $FFCC99, $FF99CC, $FFFFFF);
  {$ENDIF}


type
  TAdvChartCustomColorSelector = class;

  TAdvChartColorSelectorItem = class(TAdvChartCustomSelectorItem)
  private
    FOwner: TAdvChartCustomColorSelector;
    FColor: TAdvChartGraphicsColor;
    procedure SetColor(const Value: TAdvChartGraphicsColor);
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Source: TPersistent); override;
  published
    property Color: TAdvChartGraphicsColor read FColor write SetColor default gcNull;
  end;

  TAdvChartColorSelectorItems = class(TAdvChartCustomSelectorItems)
  private
    FOwner: TAdvChartCustomColorSelector;
    function GetItem(Index: integer): TAdvChartColorSelectorItem;
    procedure SetItem(Index: integer; const Value: TAdvChartColorSelectorItem);
  protected
    function CreateItemClass: TCollectionItemClass; override;
  public
    constructor Create(AOwner: TAdvChartCustomSelector); override;
    property Items[Index: integer]:TAdvChartColorSelectorItem read GetItem write SetItem; default;
  end;

  TAdvChartCustomSelectorColorSelected = procedure(Sender: TObject; AColor: TAdvChartGraphicsColor) of object;
  TAdvChartCustomSelectorColorDeselected = procedure(Sender: TObject; AColor: TAdvChartGraphicsColor) of object;
  TAdvChartCustomSelectorColorClick = procedure(Sender: TObject; AColor: TAdvChartGraphicsColor) of object;

  TAdvChartCustomColorSelectorMode = (csmSimple, csmExtended{$IFDEF FMXLIB}, csmExtendedMore{$ENDIF});

  TAdvChartCustomColorSelector = class(TAdvChartDefaultSelector)
  private
    {$IFDEF FMXLIB}
    FPanel: TPanel;
    FBackButton: TButton;
    FColorPanel: TColorPanel;
    {$ENDIF}
    FOnColorSelected: TAdvChartCustomSelectorColorSelected;
    FOnColorDeselected: TAdvChartCustomSelectorColorDeselected;
    FMode: TAdvChartCustomColorSelectorMode;
    procedure SetSelectedColor(const Value: TAdvChartGraphicsColor);
    function GetSelectedColor: TAdvChartGraphicsColor;
    function GetItems: TAdvChartColorSelectorItems;
    procedure SetItems(const Value: TAdvChartColorSelectorItems);
    procedure SetMode(const Value: TAdvChartCustomColorSelectorMode);
  protected
    function GetVersion: String; override;
    {$IFDEF FMXLIB}
    procedure BackButtonClicked(Sender: TObject);
    procedure ColorPanelChange(Sender: TObject);
    {$ENDIF}
    procedure DoItemClick(AItemIndex: Integer); override;
    procedure DoItemSelected(AItemIndex: Integer); override;
    procedure DoItemDeselected(AItemIndex: Integer); override;
    function CreateItemsCollection: TAdvChartCustomSelectorItems; override;
    procedure DoItemBeforeDrawContent(AGraphics: TAdvChartGraphics; ARect: TRectF; AItemIndex: Integer; var ADefaultDraw: Boolean); override;
    procedure DrawItemContent(AGraphics: TAdvChartGraphics; ADisplayItem: TAdvChartCustomSelectorDisplayItem); override;
    property OnColorSelected: TAdvChartCustomSelectorColorSelected read FOnColorSelected write FOnColorSelected;
    property OnColorDeselected: TAdvChartCustomSelectorColorDeselected read FOnColorDeselected write FOnColorDeselected;
    property SelectedColor: TAdvChartGraphicsColor read GetSelectedColor write SetSelectedColor default gcNull;
    property Items: TAdvChartColorSelectorItems read GetItems write SetItems;
    property Mode: TAdvChartCustomColorSelectorMode read FMode write SetMode default csmSimple;
    procedure AddColors;
  public
    constructor Create(AOwner: TComponent); override;
    function FindItemByColor(AColor: TAdvChartGraphicsColor): Integer;
    function FindColorByItem(AItem: Integer): TAdvChartGraphicsColor;
    procedure InitializeDefault; override;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartColorSelector = class(TAdvChartCustomColorSelector)
  published
    property Appearance;
    property Rows;
    property Columns;
    property Items;
    property Mode;
    property OnColorSelected;
    property OnColorDeselected;
    property SelectedColor;
    property OnItemSelected;
    property OnItemDeselected;
    property OnItemClick;
    property SelectedItemIndex;
    property OnItemBeforeDrawBackground;
    property OnItemAfterDrawBackground;
    property OnItemBeforeDrawContent;
    property OnItemAfterDrawContent;
    property OnBeforeDraw;
    property OnAfterDraw;
    property OnItemBeforeDrawText;
    property OnItemAfterDrawText;
  end;

implementation

uses
  SysUtils, AdvChartUtils;

{ TAdvChartCustomColorSelector }

procedure TAdvChartCustomColorSelector.AddColors;
var
  I: Integer;
  {$IFDEF FMXLIB}
  it: TAdvChartCustomSelectorItem;
  {$ENDIF}
begin
  BeginUpdate;
  Items.Clear;
  case Mode of
    csmSimple:
    begin
      Columns := 4;
      Rows := 4;
      for I := 0 to Length(AdvChartColorSelectorColorSet) - 1 do
        TAdvChartColorSelectorItem(Items.Add).Color := AdvChartColorSelectorColorSet[I];
    end;
    csmExtended:
    begin
      Columns := 8;
      Rows := 5;
      for I := 0 to Length(AdvChartColorSelectorExtendedColorSet) - 1 do
        TAdvChartColorSelectorItem(Items.Add).Color := AdvChartColorSelectorExtendedColorSet[I];
    end;
    {$IFDEF FMXLIB}
    csmExtendedMore:
    begin
      Columns := 8;
      Rows := 7;
      for I := 0 to Length(AdvChartColorSelectorExtendedColorSet) - 1 do
        TAdvChartColorSelectorItem(Items.Add).Color := AdvChartColorSelectorExtendedColorSet[I];

      it := Items.Insert(0);
      TAdvChartColorSelectorItem(it).Color := gcBlack;
      it.ColumnSpan := 8;
      it.Text := 'Automatic';

      it := Items.Add;
      it.ColumnSpan := 8;
      it.Text := 'More Colors...';
      it.CanSelect := False;

      Items.Add.Visible := False;
    end;
    {$ENDIF}
  end;
  EndUpdate;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomColorSelector.BackButtonClicked(Sender: TObject);
begin
  if Assigned(FPanel) then
    FPanel.Visible := False;
end;

procedure TAdvChartCustomColorSelector.ColorPanelChange(Sender: TObject);
begin
  if BlockChange then
    Exit;

  BlockChange := True;
  SelectedItemIndex := -1;
  Items[Items.Count - 1].Color := FColorPanel.Color;
  SelectedColor := FColorPanel.Color;
  DoItemSelected(SelectedItemIndex);
  Invalidate;
  BlockChange := False;
end;
{$ENDIF}

constructor TAdvChartCustomColorSelector.Create(AOwner: TComponent);
begin
  inherited;
  Width := 135;
  Height := 135;
  FMode := csmSimple;

  {$IFDEF FMXLIB}
  FPanel := TPanel.Create(Self);
  FPanel.Visible := False;
  FPanel.Stored := False;
  FPanel.Parent := Self;
  FPanel.Align := TAlignLayout.Client;
  FBackButton := TButton.Create(FPanel);
  FBackButton.Margins.Top := 3;
  FBackButton.Margins.Left := 3;
  FBackButton.Margins.Bottom := 3;
  FBackButton.Margins.Right := 3;
  FBackButton.Text := 'Back';
  FBackButton.Align := TAlignLayout.Top;
  FBackButton.Parent := FPanel;
  FBackButton.OnClick := BackButtonClicked;

  FColorPanel := TColorPanel.Create(FPanel);
  FColorPanel.Align := TAlignLayout.Client;
  FColorPanel.Margins.Top := 0;
  FColorPanel.Margins.Left := 3;
  FColorPanel.Margins.Bottom := 3;
  FColorPanel.Margins.Right := 3;
  FColorPanel.Parent := FPanel;
  FColorPanel.OnChange := ColorPanelChange;
  {$ENDIF}
end;

function TAdvChartCustomColorSelector.CreateItemsCollection: TAdvChartCustomSelectorItems;
begin
  Result := TAdvChartColorSelectorItems.Create(Self);
end;

procedure TAdvChartCustomColorSelector.DoItemBeforeDrawContent(AGraphics: TAdvChartGraphics;
  ARect: TRectF; AItemIndex: Integer; var ADefaultDraw: Boolean);
begin
  {$IFDEF FMXLIB}
  if Mode = csmExtendedMore then
    ADefaultDraw := AItemIndex <> 0;
  {$ENDIF}

  inherited;
end;

procedure TAdvChartCustomColorSelector.DoItemClick(AItemIndex: Integer);
begin
  {$IFDEF FMXLIB}
  if (Mode = csmExtendedMore) and Assigned(FPanel) and (AItemIndex = Items.Count - 2) then
  begin
    BlockChange := True;
    FColorPanel.Color := FindColorByItem(AItemIndex + 1);
    BlockChange := False;
    FPanel.Visible := True;
  end;
  {$ENDIF}

  inherited;
end;

procedure TAdvChartCustomColorSelector.DoItemDeselected(AItemIndex: Integer);
begin
  inherited;
  if Assigned(OnColorDeselected) then
    OnColorDeselected(Self, FindColorByItem(AItemIndex));
end;

procedure TAdvChartCustomColorSelector.DoItemSelected(AItemIndex: Integer);
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  c := FindColorByItem(AItemIndex);
  {$IFDEF FMXLIB}
  if Assigned(FColorPanel) and not BlockChange then
  begin
    BlockChange := True;
    FColorPanel.Color := c;
    if (Mode = csmExtendedMore) and (Items.Count > 0) then
      Items[Items.Count - 1].Color := c;
    BlockChange := False;
  end;
  {$ENDIF}

  if Assigned(OnColorSelected) then
    OnColorSelected(Self, c);
end;

procedure TAdvChartCustomColorSelector.DrawItemContent(AGraphics: TAdvChartGraphics;
  ADisplayItem: TAdvChartCustomSelectorDisplayItem);
var
  r: TRectF;
  it: TAdvChartCustomSelectorItem;
  a: Boolean;
begin
  it := ADisplayItem.Item;
  if Assigned(it) and (it is TAdvChartColorSelectorItem) then
  begin
    r := ADisplayItem.Rect;
    a := True;
    DoItemBeforeDrawContent(AGraphics, ADisplayItem.Rect, it.Index, a);
    if a then
    begin
      case Mode of
        csmSimple: InflateRectEx(r, -5, -5);
        csmExtended{$IFDEF FMXLIB}, csmExtendedMore{$ENDIF}: InflateRectEx(r, -3, -3);
      end;
      AGraphics.Fill.Kind := gfkSolid;
      AGraphics.Fill.Color := (it as TAdvChartColorSelectorItem).Color;
      AGraphics.Stroke.Color := AGraphics.Fill.Color;
//      if it.Enabled then
        AGraphics.DrawRectangle(r);
//      else
//        AGraphics.DrawRectangle(r, 0, 0, AllCorners, 0.25);

      DoItemAfterDrawContent(AGraphics, ADisplayItem.Rect, it.Index);
    end;
  end;
end;

function TAdvChartCustomColorSelector.FindColorByItem(
  AItem: Integer): TAdvChartGraphicsColor;
var
  I: Integer;
  it: TAdvChartColorSelectorItem;
begin
  Result := gcNull;
  for I := 0 to Items.Count - 1 do
  begin
    it := Items[I] as TAdvChartColorSelectorItem;
    if it.Index = AItem then
    begin
      Result := it.Color;
      Break;
    end;
  end;
end;

function TAdvChartCustomColorSelector.FindItemByColor(
  AColor: TAdvChartGraphicsColor): Integer;
var
  I: Integer;
  it: TAdvChartColorSelectorItem;
begin
  Result := -1;
  for I := 0 to Items.Count - 1 do
  begin
    it := Items[I] as TAdvChartColorSelectorItem;
    if (it.Color = AColor) and it.CanSelect then
    begin
      Result := it.Index;
      Break;
    end;
  end;
end;

function TAdvChartCustomColorSelector.GetItems: TAdvChartColorSelectorItems;
begin
  Result := TAdvChartColorSelectorItems(inherited Items);
end;

function TAdvChartCustomColorSelector.GetSelectedColor: TAdvChartGraphicsColor;
begin
  Result := FindColorByItem(SelectedItemIndex);
end;

function TAdvChartCustomColorSelector.GetVersion: String;
begin
  Result := GetVersionNumber(MAJ_VER, MIN_VER, REL_VER, BLD_VER);
end;

procedure TAdvChartCustomColorSelector.InitializeDefault;
begin
  inherited;
  AddColors;
end;

procedure TAdvChartCustomColorSelector.SetItems(
  const Value: TAdvChartColorSelectorItems);
begin
  inherited Items.Assign(Value);
end;

procedure TAdvChartCustomColorSelector.SetMode(
  const Value: TAdvChartCustomColorSelectorMode);
begin
  if FMode <> Value then
  begin
    FMode := Value;
    AddColors;
  end;
end;

procedure TAdvChartCustomColorSelector.SetSelectedColor(const Value: TAdvChartGraphicsColor);
begin
  {$IFDEF FMXLIB}
  case Mode of
    csmExtendedMore:
    begin
      if Items.Count > 0 then
        Items[Items.Count - 1].Color := Value;
    end;
  end;
  {$ENDIF}
  SelectedItemIndex := FindItemByColor(Value);
end;

{ TAdvChartColorSelectorItems }

constructor TAdvChartColorSelectorItems.Create(AOwner: TAdvChartCustomSelector);
begin
  inherited;
  FOwner := AOwner as TAdvChartCustomColorSelector;
end;

function TAdvChartColorSelectorItems.CreateItemClass: TCollectionItemClass;
begin
  Result := TAdvChartColorSelectorItem;
end;

function TAdvChartColorSelectorItems.GetItem(
  Index: integer): TAdvChartColorSelectorItem;
begin
  Result := TAdvChartColorSelectorItem(inherited Items[Index]);
end;

procedure TAdvChartColorSelectorItems.SetItem(Index: integer;
  const Value: TAdvChartColorSelectorItem);
begin
  inherited Items[Index] := Value;
end;

{ TAdvChartColorSelectorItem }

procedure TAdvChartColorSelectorItem.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartColorSelectorItem then
    FColor := (Source as TAdvChartColorSelectorItem).Color;
end;

constructor TAdvChartColorSelectorItem.Create(Collection: TCollection);
begin
  inherited;
  if Assigned(Collection) then
    FOwner := (Collection as TAdvChartColorSelectorItems).FOwner;
end;

procedure TAdvChartColorSelectorItem.SetColor(const Value: TAdvChartGraphicsColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    FOwner.InvalidateItems;
  end;
end;

end.
