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

unit AdvChartBitmapContainer;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  Classes, AdvChartTypes, AdvChartCustomComponent, Controls
  {$IFNDEF LCLLIB}
  , Generics.Collections
  {$ENDIF}
  {$IFDEF LCLLIB}
  , fgl
  {$ENDIF}
  ;

const
  MAJ_VER = 1; // Major version nr.
  MIN_VER = 0; // Minor version nr.
  REL_VER = 0; // Release nr.
  BLD_VER = 0; // Build nr.

  // version history
  // v1.0.0.0 : First Release

type
  TAdvChartBitmapContainer = class;

  IAdvChartBitmapContainer = interface
    ['{ED26710D-395F-4971-8AC9-A31083BF2A3C}']
    procedure SetBitmapContainer(const Value: TAdvChartBitmapContainer);
    function GetBitmapContainer: TAdvChartBitmapContainer;
    property BitmapContainer: TAdvChartBitmapContainer read GetBitmapContainer write SetBitmapContainer;
  end;

  TAdvChartBitmapItem = class(TCollectionItem)
  private
    FBitmap: TAdvChartBitmap;
    FTag: NativeInt;
    FName: string;
    procedure SetBitmap(const Value: TAdvChartBitmap);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function GetDisplayName: string; override;
  published
    property Bitmap: TAdvChartBitmap read FBitmap write SetBitmap;
    property Name: string read FName write FName;
    property Tag: NativeInt read FTag write FTag;
  end;

  TAdvChartBitmapCollection = class(TOwnedCollection)
  private
    FOwner: TComponent;
    function GetItem(Index: Integer): TAdvChartBitmapItem;
    procedure SetItem(Index: Integer; Value: TAdvChartBitmapItem);
  protected
    function GetBitmapItemClass: TCollectionItemClass; virtual;
  public
    constructor Create(AOwner:TComponent);
    function Add: TAdvChartBitmapItem;
    function Insert(index: Integer): TAdvChartBitmapItem;
    property Items[Index: Integer]: TAdvChartBitmapItem read GetItem write SetItem; default;
  end;

  TControlList = class(TList<TControl>);

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartBitmapContainer = class(TAdvChartCustomComponent)
  private
    FControls: TControlList;
    FItems: TAdvChartBitmapCollection;
    procedure SetItems(const Value: TAdvChartBitmapCollection);
    function GetBitmapName(AIndex: Integer): String;
    function GetBitmap(AIndex: Integer): TAdvChartBitmap;
    function GetItems: TAdvChartBitmapCollection;
  protected
    function GetVersion: string;
    function CreateItems: TAdvChartBitmapCollection; virtual;
    procedure Notification(AComponent: TComponent; AOperation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Changed; virtual;
    procedure RegisterControl(AControl: TControl);
    function FindBitmap(s: string): TAdvChartBitmap; virtual;
    function ItemCount: Integer;
    function RandomBitmapName: string;
    function RandomBitmap: TAdvChartBitmap;
    procedure AddFromResource(ResourceName, BitmapName: string);
    procedure AddFromFile(FileName, BitmapName: String);
    procedure AddFromFolder(AFolder: string);
    property BitmapNames[AIndex: Integer]: String read GetBitmapName;
    property Bitmaps[AIndex: Integer]: TAdvChartBitmap read GetBitmap;
  published
    property Items: TAdvChartBitmapCollection read GetItems write SetItems;
    property Version: string read GetVersion;
  end;

implementation

{$R 'AdvChartBitmapContainer.res'}

uses
  SysUtils, AdvChartUtils;

{ TAdvChartBitmapItem }

procedure TAdvChartBitmapItem.Assign(Source: TPersistent);
begin
  Name := (Source as TAdvChartBitmapItem).Name;
  Tag := (Source as TAdvChartBitmapItem).Tag;
  Bitmap.Assign((Source as TAdvChartBitmapItem).Bitmap)
end;

constructor TAdvChartBitmapItem.Create(Collection: TCollection);
begin
  inherited;
  FBitmap := TAdvChartBitmap.Create;
  FName := 'Item' + IntToStr(Collection.Count);
end;

destructor TAdvChartBitmapItem.Destroy;
begin
  FBitmap.Free;
  inherited;
end;

function TAdvChartBitmapItem.GetDisplayName: string;
begin
  if FName <> '' then
    Result := FName
  else
    Result := inherited;
end;

procedure TAdvChartBitmapItem.SetBitmap(const Value: TAdvChartBitmap);
begin
  FBitmap.Assign(Value);
end;

{ TAdvChartBitmapCollection }

function TAdvChartBitmapCollection.Add: TAdvChartBitmapItem;
begin
  Result := TAdvChartBitmapItem(inherited Add);
end;


constructor TAdvChartBitmapCollection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner, GetBitmapItemClass);
  FOwner := AOwner;
end;

function TAdvChartBitmapCollection.GetBitmapItemClass: TCollectionItemClass;
begin
  Result := TAdvChartBitmapItem;
end;

function TAdvChartBitmapCollection.GetItem(Index: Integer): TAdvChartBitmapItem;
begin
  Result := TAdvChartBitmapItem(inherited Items[Index]);
end;

function TAdvChartBitmapCollection.Insert(index: Integer): TAdvChartBitmapItem;
begin
  Result := TAdvChartBitmapItem(inherited Insert(Index));
end;

procedure TAdvChartBitmapCollection.SetItem(Index: Integer;
  Value: TAdvChartBitmapItem);
begin
  inherited SetItem(Index, Value);
end;

{ TAdvChartBitmapContainer }

procedure TAdvChartBitmapContainer.AddFromFile(FileName, BitmapName: string);
var
  bmpi: TAdvChartBitmapItem;
begin
  bmpi := Items.Add;
  bmpi.Bitmap.LoadFromFile(FileName);
  bmpi.Name := BitmapName;
end;

procedure TAdvChartBitmapContainer.AddFromFolder(AFolder: string);
var
  SR: TSearchRec;

  procedure AddToList(s: string);
  begin
    with Items.Add do
    begin
      try
        Bitmap.LoadFromFile(s);
        Name := ExtractFileName(s);
      except
        Bitmap.Assign(nil);
      end;
    end;
  end;

begin
  if FindFirst(AFolder,faAnyFile and not faDirectory,SR) = 0 then
  begin
    AddToList(ExtractFilePath(AFolder) + SR.Name);
    while FindNext(SR) = 0 do
      AddToList(ExtractFilePath(AFolder) + SR.Name);
  end;
  FindClose(SR);
end;

procedure TAdvChartBitmapContainer.AddFromResource(ResourceName, BitmapName: string);
var
  bmpi: TAdvChartBitmapItem;
begin
  bmpi := Items.Add;
  bmpi.Bitmap.LoadFromResource(ResourceName);
  bmpi.Name := BitmapName;
end;

procedure TAdvChartBitmapContainer.Changed;
var
  i: integer;
begin
  for i := 0 to FControls.Count - 1 do
  {$IFDEF FMXLIB}
    FControls.Items[i].Invalidate;
  {$ENDIF}
  {$IFDEF CMNLIB}
    FControls.Items[i].Invalidate;
  {$ENDIF}
end;

constructor TAdvChartBitmapContainer.Create(AOwner: TComponent);
begin
  inherited;
  FItems := CreateItems;
  FControls := TControlList.Create;
end;

function TAdvChartBitmapContainer.CreateItems: TAdvChartBitmapCollection;
begin
  Result := TAdvChartBitmapCollection.Create(Self);
end;

destructor TAdvChartBitmapContainer.Destroy;
begin
  FControls.Free;
  FItems.Free;
  inherited;
end;

function TAdvChartBitmapContainer.FindBitmap(s: string): TAdvChartBitmap;
var
  i: Integer;
begin
  Result := nil;
  s := Uppercase(s);
  i := 1;
  while i <= Items.Count do
  begin
    if Uppercase(Items[i - 1].Name) = s then
    begin
      Result := Items[i - 1].Bitmap;
      Break;
    end;
    Inc(i);
  end;
end;

procedure TAdvChartBitmapContainer.SetItems(const Value: TAdvChartBitmapCollection);
begin
  FItems.Assign(Value);
end;

function TAdvChartBitmapContainer.GetBitmap(AIndex: Integer): TAdvChartBitmap;
begin
  Result := nil;
  if (AIndex >= 0) and (AIndex <= Items.Count - 1) then
    Result := Items[AIndex].Bitmap;
end;

function TAdvChartBitmapContainer.GetBitmapName(AIndex: Integer): String;
begin
  Result := '';
  if (AIndex >= 0) and (AIndex <= Items.Count - 1) then
    Result := Items[AIndex].Name;
end;

function TAdvChartBitmapContainer.GetItems: TAdvChartBitmapCollection;
begin
  Result := FItems;
end;

function TAdvChartBitmapContainer.GetVersion: string;
begin
  Result := GetVersionNumber(MAJ_VER, MIN_VER, REL_VER, BLD_VER);
end;

function TAdvChartBitmapContainer.ItemCount: Integer;
begin
  Result := Items.Count;
end;

procedure TAdvChartBitmapContainer.Notification(AComponent: TComponent;
  AOperation: TOperation);
var
  i: integer;
begin
  inherited;
  if (AOperation = opRemove) then
  begin
    for i := FControls.Count - 1 downto 0 do
    begin
      if (FControls.Items[i] = AComponent) then
        FControls.Delete(i);
    end;
  end;
end;

function TAdvChartBitmapContainer.RandomBitmap: TAdvChartBitmap;
begin
  Result := Bitmaps[Random(ItemCount)];
end;

function TAdvChartBitmapContainer.RandomBitmapName: string;
begin
  Result := BitmapNames[Random(ItemCount)];
end;

procedure TAdvChartBitmapContainer.RegisterControl(
  AControl: TControl);
begin
  FControls.Add(AControl);
end;

end.
