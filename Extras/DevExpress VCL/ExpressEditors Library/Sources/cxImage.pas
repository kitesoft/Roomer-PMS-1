{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressEditors                                               }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSEDITORS AND ALL                }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

unit cxImage;

{$I cxVer.inc}

interface

uses
  Types, Variants,
  Windows, Messages, ExtDlgs, SysUtils, Classes, Clipbrd, Controls, Dialogs,
  ExtCtrls, Forms, Graphics, Menus, StdCtrls,
  dxCore, dxCoreClasses, cxClasses, cxContainer, cxControls, cxGraphics, cxLookAndFeels,
  cxLookAndFeelPainters, cxDataUtils, cxVariants, dxTouch, dxSkinsCore,
  cxEdit, cxEditConsts, ImgList;

const
  cxImageDefaultInplaceHeight = 15;

type
  TcxCustomImage = class;
  TcxPopupMenuItem = (pmiCut, pmiCopy, pmiPaste, pmiDelete, pmiLoad, pmiSave,
    pmiCustom);
  TcxPopupMenuItemClick = procedure(Sender: TObject;
    MenuItem: TcxPopupMenuItem) of object;
  TcxPopupMenuItems = set of TcxPopupMenuItem;

  { TcxPopupMenuLayout }

  TcxPopupMenuLayout = class(TPersistent)
  private
    FCustomMenuItemCaption: string;
    FCustomMenuItemGlyph: TBitmap;
    FImage: TcxCustomImage;
    FMenuItems: TcxPopupMenuItems;
    function GetCustomMenuItemGlyph: TBitmap; virtual;
    procedure SetCustomMenuItemGlyph(Value: TBitmap);
  public
    constructor Create(AImage: TcxCustomImage);
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property MenuItems: TcxPopupMenuItems read FMenuItems write FMenuItems default
      [pmiCut, pmiCopy, pmiPaste, pmiDelete, pmiLoad, pmiSave];
    property CustomMenuItemCaption: string
      read FCustomMenuItemCaption write FCustomMenuItemCaption;
    property CustomMenuItemGlyph: TBitmap
      read GetCustomMenuItemGlyph write SetCustomMenuItemGlyph;
  end;

  { TcxImageViewInfo }

  TcxImageViewInfo = class(TcxCustomEditViewInfo)
  private
    FFreePicture: Boolean;

    FZoomButtons: TdxSkinImage;
    FZoomInButtonRect: TRect;
    FZoomOutButtonRect: TRect;

    procedure DrawTransparentBackground(ACanvas: TcxCanvas; const R: TRect);
  protected
    procedure DrawZoomInButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    procedure DrawZoomOutButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    procedure InternalPaint(ACanvas: TcxCanvas); override;
    function IsRepaintOnStateChangingNeeded: Boolean; override;

    function GetRealStretch: Boolean;
  public
    ShowFocusRect: Boolean;
    TopLeft: TPoint;
    Caption: string;
    Center: Boolean;
    Picture: TPicture;
    FitMode: TcxImageFitMode;
    Scale: Integer;
    Scalable: Boolean;

    destructor Destroy; override;
  end;

  { TcxImageViewData }

  TcxImageViewData = class(TcxCustomEditViewData)
  public
    procedure Calculate(ACanvas: TcxCanvas; const ABounds: TRect; const P: TPoint;
      Button: TcxMouseButton; Shift: TShiftState; AViewInfo: TcxCustomEditViewInfo;
      AIsMouseEvent: Boolean); override;
    procedure EditValueToDrawValue(const AEditValue: TcxEditValue;
      AViewInfo: TcxCustomEditViewInfo); override;
    function GetEditContentSize(ACanvas: TcxCanvas;
      const AEditValue: TcxEditValue;
      const AEditSizeProperties: TcxEditSizeProperties): TSize; override;
  end;

  { TcxCustomImageProperties }

  TcxImageAssignPictureEvent = procedure(Sender: TObject;
    const Picture: TPicture) of object;
  TcxImageGraphicClassEvent = procedure(AItem: TObject; ARecordIndex: Integer;
    APastingFromClipboard: Boolean; var AGraphicClass: TGraphicClass) of object;
  TcxImageEditGraphicClassEvent = procedure(Sender: TObject;
    APastingFromClipboard: Boolean; var AGraphicClass: TGraphicClass) of object;

  TcxImageTransparency = (gtDefault, gtOpaque, gtTransparent);

  TcxCustomImageProperties = class(TcxCustomEditProperties)
  private
    FCaption: string;
    FCustomFilter: string;
    FDefaultHeight: Integer;
    FGraphicClass: TGraphicClass;
    FGraphicTransparency: TcxImageTransparency;
    FNeedUpdateImage: Boolean;
    FPopupMenuLayout: TcxPopupMenuLayout;
    FShowFocusRect: Boolean;

    FCenter: Boolean;
    FFitMode: TcxImageFitMode;

    FOnAssignPicture: TcxImageAssignPictureEvent;
    FOnCustomClick: TNotifyEvent;
    FOnGetGraphicClass: TcxImageGraphicClassEvent;

    function GetGraphicClassName: string;
    function IsGraphicClassNameStored: Boolean;
    procedure ReadIsGraphicClassNameEmpty(Reader: TReader);
    procedure SetCaption(const Value: string);
    procedure SetGraphicClass(const Value: TGraphicClass);
    procedure SetGraphicClassName(const Value: string);
    procedure SetGraphicTransparency(Value: TcxImageTransparency);
    procedure SetPopupMenuLayout(Value: TcxPopupMenuLayout);
    procedure SetShowFocusRect(Value: Boolean);
    procedure WriteIsGraphicClassNameEmpty(Writer: TWriter);

    function CalculateFitMode(AProportional, AStretch: Boolean): TcxImageFitMode;
    function GetProportional: Boolean;
    function GetStretch: Boolean;
    procedure SetCenter(AValue: Boolean);
    procedure SetProportional(AValue: Boolean);
    procedure SetStretch(AValue: Boolean);
    procedure SetFitMode(AValue: TcxImageFitMode);
  protected
    function CanValidate: Boolean; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DoAssign(AProperties: TcxCustomEditProperties); override;

    function IsDesigning: Boolean;
    function GetDefaultGraphicClass: TGraphicClass; virtual;
    function GetRealStretch(const APictureSize, ABoundsSize: TSize): Boolean;
    class function GetViewDataClass: TcxCustomEditViewDataClass; override;
    function IsScrollbarsNeeded(APicture: TPicture): Boolean;

    property DefaultHeight: Integer read FDefaultHeight write FDefaultHeight
      default cxImageDefaultInplaceHeight;

    property FitMode: TcxImageFitMode read FFitMode write SetFitMode;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    class function GetContainerClass: TcxContainerClass; override;
    function GetDisplayText(const AEditValue: TcxEditValue;
      AFullText: Boolean = False; AIsInplace: Boolean = True): WideString; override;
    function GetEditValueSource(AEditFocused: Boolean): TcxDataEditValueSource; override;
    function GetGraphicClass(AItem: TObject;
      ARecordIndex: Integer;
      APastingFromClipboard: Boolean = False): TGraphicClass; virtual;
    function GetSpecialFeatures: TcxEditSpecialFeatures; override;
    function GetSupportedOperations: TcxEditSupportedOperations; override;
    class function GetViewInfoClass: TcxContainerViewInfoClass; override;
    function IsResetEditClass: Boolean; override;
    procedure ValidateDisplayValue(var DisplayValue: TcxEditValue; var ErrorText: TCaption;
      var Error: Boolean; AEdit: TcxCustomEdit); override;
    property GraphicClass: TGraphicClass read FGraphicClass write SetGraphicClass;
    // !!!
    property Caption: string read FCaption write SetCaption;
    property Center: Boolean read FCenter write SetCenter default True;
    property CustomFilter: string read FCustomFilter write FCustomFilter;
    property GraphicClassName: string read GetGraphicClassName
      write SetGraphicClassName stored IsGraphicClassNameStored;
    property GraphicTransparency: TcxImageTransparency
      read FGraphicTransparency write SetGraphicTransparency default gtDefault;
    property PopupMenuLayout: TcxPopupMenuLayout
      read FPopupMenuLayout write SetPopupMenuLayout;
    property Proportional: Boolean read GetProportional write SetProportional default True;
    property ShowFocusRect: Boolean read FShowFocusRect write SetShowFocusRect default True;
    property Stretch: Boolean read GetStretch write SetStretch default False;
    property OnAssignPicture: TcxImageAssignPictureEvent
      read FOnAssignPicture write FOnAssignPicture;
    property OnCustomClick: TNotifyEvent read FOnCustomClick
      write FOnCustomClick;
    property OnGetGraphicClass: TcxImageGraphicClassEvent read FOnGetGraphicClass
      write FOnGetGraphicClass;
  end;

  { TcxImageProperties }

  TcxImageProperties = class(TcxCustomImageProperties)
  published
    property AssignedValues;
    property Caption;
    property Center;
    property ClearKey;
    property CustomFilter;
    property GraphicClassName;
    property GraphicTransparency;
    property ImmediatePost;
    property PopupMenuLayout;
    property Proportional;
    property ReadOnly;
    property ShowFocusRect;
    property Stretch;
    property OnAssignPicture;
    property OnChange;
    property OnCustomClick;
    property OnEditValueChanged;
    property OnGetGraphicClass;
  end;

  { TcxCustomImage }

  TcxCustomImage = class(TcxCustomEdit, IdxScrollingControl, IdxZoomClient)
  private
    FClipboardFormat: Word;
    FEditPopupMenu: TPopupMenu;
    FIsDialogShowed: Boolean;
    FPicture: TPicture;
    FOnGetGraphicClass: TcxImageEditGraphicClassEvent;
    FLastDragPos: TPoint;

    FMaxScale: Integer;
    FMinScale: Integer;
    FScalable: Boolean;
    FScale: Integer;
    FAllowUserChangeScale: Boolean;

    function CanScaleByMouseWheel(AShift: TShiftState; const AMousePos: TPoint): Boolean;
    procedure EditAndClear;
    procedure EditPopupMenuClick(Sender: TObject);
    function GetProperties: TcxCustomImageProperties;
    function GetViewInfo: TcxImageViewInfo;
    function GetActiveProperties: TcxCustomImageProperties;
    procedure MenuItemClick(Sender: TObject; MenuItem: TcxPopupMenuItem);
    procedure PictureChanged(Sender: TObject);
    procedure PreparePopup;
    procedure SetPicture(Value: TPicture);
    procedure SetProperties(const Value: TcxCustomImageProperties);

    function GetCurrentScale: Integer;
    procedure SetScalable(AValue: Boolean);
    procedure SetScale(AValue: Integer);
  protected
    //TControl
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; override;
    function CanAutoSize: Boolean; override;
    function CanAutoWidth: Boolean; override;
    procedure DoContextPopup( MousePos: TPoint; var Handled: Boolean); override;
    function GetDefaultPanOptions: Integer; override;
    function InternalMouseWheel(Shift: TShiftState; WheelDelta: Integer;
      MousePos: TPoint): Boolean; override;
    function IsDefaultGesture(AGestureID: Integer): Boolean; override;
    function IsMouseWheelHandleNeeded(Shift: TShiftState; WheelDelta: Integer;
      MousePos: TPoint): Boolean; override;
    function IsPanArea(const APoint: TPoint): Boolean; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure MouseEnter(AControl: TControl); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    function NeedsInvokeAfterKeyDown(AKey: Word; AShift: TShiftState): Boolean; override;

    procedure Initialize; override;
    function GetEditValue: TcxEditValue; override;
    procedure InternalSetEditValue(const Value: TcxEditValue;
      AIsValueValid: Boolean); override;
    procedure PropertiesChanged(Sender: TObject); override;
    procedure BoundsChanged; override;

    { IdxScrollingControl }
    function GetLeftPos: Integer;
    procedure SetLeftPos(Value: Integer);
    function GetTopPos: Integer;
    procedure SetTopPos(Value: Integer);
    function GetContentSize: TSize;
    function GetClientSize: TSize;
    function GetInstance: TcxControl;

    { IdxZoomClient }
    procedure Zoom(ADelta: Integer; var AHandled: Boolean);

    // scroll
    procedure Centre;
    procedure CheckScrollbars(AResetPosition: Boolean = False);
    procedure InitScrollBarsParameters; override;
    function IsScrollbarsNeeded: Boolean;
    function NeedsScrollBars: Boolean; override; 
    procedure Scroll(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode;
      var AScrollPos: Integer); override;

    // virtual methods
    function CanPasteFromClipboard: Boolean; virtual;
    procedure CustomClick; virtual;
    procedure DoOnAssignPicture;
    procedure DoPictureLoadedFromFile(AFileName: string); virtual;
    function GetGraphicClass(APastingFromClipboard: Boolean = False): TGraphicClass; virtual;
    property AutoSize default False;
    property ParentColor default False;
    property OnGetGraphicClass: TcxImageEditGraphicClassEvent
      read FOnGetGraphicClass write FOnGetGraphicClass;

    property IsDialogShowed: Boolean read FIsDialogShowed;
    property MaxScale: Integer read FMaxScale write FMaxScale;
    property MinScale: Integer read FMinScale write FMinScale;
    property Scalable: Boolean read FScalable write SetScalable;
    property Scale: Integer read FScale write SetScale;
    property AllowUserChangeScale: Boolean read FAllowUserChangeScale write FAllowUserChangeScale;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CopyToClipboard; override;
    procedure CutToClipboard; override;
    function Focused: Boolean; override;
    class function GetPropertiesClass: TcxCustomEditPropertiesClass; override;
    procedure LoadFromFile;
    procedure PasteFromClipboard; override;
    procedure SaveToFile;
    property ActiveProperties: TcxCustomImageProperties read GetActiveProperties;
    property ClipboardFormat: Word
      read FClipboardFormat write FClipboardFormat;
    property Picture: TPicture read FPicture write SetPicture;
    property Properties: TcxCustomImageProperties read GetProperties
      write SetProperties;
    property ViewInfo: TcxImageViewInfo read GetViewInfo;
  end;

  { TcxImage }

  TcxImage = class(TcxCustomImage)
  private
    function GetActiveProperties: TcxImageProperties;
    function GetProperties: TcxImageProperties;
    procedure SetProperties(Value: TcxImageProperties);
  public
    class function GetPropertiesClass: TcxCustomEditPropertiesClass; override;
    property ActiveProperties: TcxImageProperties read GetActiveProperties;
  published
    property Anchors;
    property AutoSize;
    property Constraints;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property ParentColor;
    property ParentShowHint;
    property Picture;
    property PopupMenu;
    property Properties: TcxImageProperties read GetProperties write SetProperties;
    property ShowHint;
    property Style;
    property StyleDisabled;
    property StyleFocused;
    property StyleHot;
    property TabOrder;
    property TabStop;
    property Transparent;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEditing;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnGetGraphicClass;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

procedure LoadPicture(APicture: TPicture; AGraphicClass: TGraphicClass;
  const AValue: Variant);
procedure SavePicture(APicture: TPicture; var AValue: AnsiString);

function GetGraphicClassByName(const AClassName: string): TGraphicClass;
function GetRegisteredGraphicClasses: TList;
procedure RegisterGraphicClass(AGraphicClass: TGraphicClass);
procedure UnRegisterGraphicClass(AGraphicClass: TGraphicClass);

implementation

{$R cxImage.res}

uses
{$IFDEF USEJPEGIMAGE}
  Jpeg,
{$ENDIF}
  cxGeometry, dxGDIPlusApi, dxGDIPlusClasses, Math, cxEditUtils;

type
  TPictureAccess = class(TPicture);
  TMemoryStreamAccess = class(TMemoryStream);
{$IFDEF USEJPEGIMAGE}
  TJPEGImageAccess = class(TJPEGImage);
{$ENDIF}

  { TcxImageCommonResources }

  TcxImageCommonResources = class
  private
    FLargeZoomButtons: TdxSkinImage;
    FPopupMenuImageList: TImageList;
    FSmallZoomButtons: TdxSkinImage;
  protected
    procedure InitializePopupMenuImageList;
    procedure InitializeZoomButtons;
  public
    constructor Create; virtual;
    destructor Destroy; override;

    property LargeZoomButtons: TdxSkinImage read FLargeZoomButtons;
    property PopupMenuImageList: TImageList read FPopupMenuImageList;
    property SmallZoomButtons: TdxSkinImage read FSmallZoomButtons;
  end;

var
  cxRegisteredGraphicClasses: TList;
  FCommonResources: TcxImageCommonResources = nil;

function cxImageCommonResources: TcxImageCommonResources;
begin
  if FCommonResources = nil then
    FCommonResources := TcxImageCommonResources.Create;
  Result := FCommonResources;
end;

function GetGraphicClassByName(const AClassName: string): TGraphicClass;
var
  I: Integer;
begin
  Result := nil;
  for i := 0 to GetRegisteredGraphicClasses.Count - 1 do
    if InternalCompareString(AClassName, TClass(GetRegisteredGraphicClasses[I]).ClassName, False) then
    begin
      Result := TGraphicClass(GetRegisteredGraphicClasses[I]);
      Break;
    end;
end;

function GetRegisteredGraphicClasses: TList;
begin
  if cxRegisteredGraphicClasses = nil then
  begin
    cxRegisteredGraphicClasses := TList.Create;
    RegisterGraphicClass(TBitmap);
    RegisterGraphicClass(TIcon);
    RegisterGraphicClass(TMetaFile);
    if GetClass(TdxPNGImage.ClassName) <> nil then
      RegisterGraphicClass(TdxPNGImage);
    if GetClass(TdxSmartImage.ClassName) <> nil then
      RegisterGraphicClass(TdxSmartImage);
  {$IFDEF USEJPEGIMAGE}
    RegisterGraphicClass(TJpegImage);
  {$ENDIF}
  end;
  Result := cxRegisteredGraphicClasses
end;

procedure RegisterGraphicClass(AGraphicClass: TGraphicClass);
begin
  if cxRegisteredGraphicClasses.IndexOf(TObject(AGraphicClass)) = -1 then
    cxRegisteredGraphicClasses.Add(TObject(AGraphicClass));
end;

procedure UnRegisterGraphicClass(AGraphicClass: TGraphicClass);
var
  I: Integer;
begin
  I := cxRegisteredGraphicClasses.IndexOf(TObject(AGraphicClass));
  if I <> -1 then
    cxRegisteredGraphicClasses.Delete(I);
end;

procedure LoadPicture(APicture: TPicture; AGraphicClass: TGraphicClass;
  const AValue: Variant);
{ Paradox graphic BLOB header - see DB.pas}
type
  TGraphicHeader = record
    Count: Word;                { Fixed at 1 }
    HType: Word;                { Fixed at $0100 }
    Size: Longint;              { Size not including header }
  end;
var
  AGraphic: TGraphic;
  AHeader: TGraphicHeader;
  ASize: Longint;
  AStream: TMemoryStream;
  AValueAsString: AnsiString;
begin
  if dxVarIsBlob(AValue) then
  begin
    AStream := TMemoryStream.Create;
    try
      AValueAsString := dxVariantToAnsiString(AValue);
      ASize := Length(AValueAsString);
      if ASize >= SizeOf(AHeader) then
      begin
        TMemoryStreamAccess(AStream).SetPointer(@AValueAsString[1], ASize);
        AStream.Position := 0;
        AStream.Read(AHeader, SizeOf(AHeader));
        if (AHeader.Count <> 1) or (AHeader.HType <> $0100) or
          (AHeader.Size <> ASize - SizeOf(AHeader)) then
          AStream.Position := 0;
      end;
      if AStream.Size > 0 then
        try
          if AGraphicClass = nil then
            APicture.Bitmap.LoadFromStream(AStream)
          else
          begin
            AGraphic := AGraphicClass.Create;
            try
              AGraphic.LoadFromStream(AStream);
              APicture.Graphic := AGraphic;
            finally
              AGraphic.Free;
            end;
          end;
        except
          APicture.Assign(nil);
        end
      else
        APicture.Assign(nil);
    finally
      AStream.Free;
    end;
  end
  else
    APicture.Assign(nil);
end;

procedure SavePicture(APicture: TPicture; var AValue: AnsiString);
var
  AStream: TMemoryStream;
begin
  if IsPictureAssigned(APicture) then
  begin
    AStream := TMemoryStream.Create;
    try
      APicture.Graphic.SaveToStream(AStream);
      AStream.Position := 0;
      SetLength(AValue, AStream.Size);
      AStream.ReadBuffer(AValue[1], AStream.Size);
    finally
      AStream.Free;
    end;
  end
  else
    AValue := '';
end;

{ TcxImageCommonResources }

constructor TcxImageCommonResources.Create;
begin
  inherited Create;
  InitializePopupMenuImageList;
  InitializeZoomButtons;
end;

destructor TcxImageCommonResources.Destroy;
begin
  FreeAndNil(FPopupMenuImageList);
  FreeAndNil(FLargeZoomButtons);
  FreeAndNil(FSmallZoomButtons);
  inherited Destroy;
end;

procedure TcxImageCommonResources.InitializePopupMenuImageList;

  function GetResourceName(APopupMenuItem: TcxPopupMenuItem): string;
  begin
    case APopupMenuItem of
      pmiCut:
        Result := 'CXMENUIMAGE_CUT';
      pmiCopy:
        Result := 'CXMENUIMAGE_COPY';
      pmiPaste:
        Result := 'CXMENUIMAGE_PASTE';
      pmiDelete:
        Result := 'CXMENUIMAGE_DELETE';
      pmiLoad:
        Result := 'CXMENUIMAGE_LOAD';
      pmiSave:
        Result := 'CXMENUIMAGE_SAVE';
      else
        Result := '';
    end;
  end;

  procedure LoadBitmapFromResource(ABitmap: TBitmap; APopupMenuItem: TcxPopupMenuItem);
  begin
    ABitmap.LoadFromResourceName(HInstance, GetResourceName(APopupMenuItem));
  end;

var
  ABitmap: TBitmap;
  APopupMenuItem: TcxPopupMenuItem;
begin
  ABitmap := TBitmap.Create;
  try
    LoadBitmapFromResource(ABitmap, Low(TcxPopupMenuItem));
    FPopupMenuImageList := TImageList.CreateSize(ABitmap.Width, ABitmap.Height);
    FPopupMenuImageList.AddMasked(ABitmap, clDefault);

    for APopupMenuItem := Succ(Low(TcxPopupMenuItem)) to High(TcxPopupMenuItem) do
    begin
      if APopupMenuItem <> pmiCustom then
      begin
        LoadBitmapFromResource(ABitmap, APopupMenuItem);
        FPopupMenuImageList.AddMasked(ABitmap, clFuchsia);
      end;
    end;
  finally
    ABitmap.Free;
  end;
end;

procedure TcxImageCommonResources.InitializeZoomButtons;

  function CreateSkinImage(const AResourceName: string): TdxSkinImage;
  begin
    Result := TdxSkinImage.Create(nil);
    Result.LoadFromResource(HInstance, AResourceName, 'PNG');
    Result.ImageLayout := ilHorizontal;
    Result.ImageCount := 2;
  end;

begin
  FSmallZoomButtons := CreateSkinImage('CXIMAGE_SMALLZOOMBUTTONS');
  FLargeZoomButtons := CreateSkinImage('CXIMAGE_LARGEZOOMBUTTONS');
end;

{ TcxPopupMenuLayout }

constructor TcxPopupMenuLayout.Create(AImage: TcxCustomImage);
begin
  inherited Create;
  FImage := AImage;
  FMenuItems := [pmiCut, pmiCopy, pmiPaste, pmiDelete, pmiLoad, pmiSave];
end;

destructor TcxPopupMenuLayout.Destroy;
begin
  if FCustomMenuItemGlyph <> nil then FCustomMenuItemGlyph.Free;
  inherited Destroy;
end;

function TcxPopupMenuLayout.GetCustomMenuItemGlyph: TBitmap;
begin
  if FCustomMenuItemGlyph = nil then
    FCustomMenuItemGlyph := TBitmap.Create;
  Result := FCustomMenuItemGlyph;
end;

procedure TcxPopupMenuLayout.SetCustomMenuItemGlyph(Value: TBitmap);
begin
  if (Value = nil) then
  begin
    FCustomMenuItemGlyph.Free;
    FCustomMenuItemGlyph := nil;
  end
  else
    CustomMenuItemGlyph.Assign(Value);
end;

procedure TcxPopupMenuLayout.Assign(Source: TPersistent);
begin
  if Source is TcxPopupMenuLayout then
    with TcxPopupMenuLayout(Source) do
    begin
      Self.MenuItems := MenuItems;
      Self.CustomMenuItemCaption := CustomMenuItemCaption;
      Self.CustomMenuItemGlyph.Assign(CustomMenuItemGlyph);
    end
  else
    inherited Assign(Source);
end;

{ TcxCustomImageProperties }

constructor TcxCustomImageProperties.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FPopupMenuLayout := TcxPopupMenuLayout.Create(nil);
  FCenter := True;
  FDefaultHeight := cxImageDefaultInplaceHeight;
  FGraphicTransparency := gtDefault;
  FShowFocusRect := True;
  FFitMode := ifmFit;
  FGraphicClass := GetDefaultGraphicClass;
end;

destructor TcxCustomImageProperties.Destroy;
begin
  FPopupMenuLayout.Free;
  inherited Destroy;
end;

function TcxCustomImageProperties.GetGraphicClassName: string;
begin
  if FGraphicClass = nil then
    Result := ''
  else
    Result := FGraphicClass.ClassName;
end;

function TcxCustomImageProperties.IsGraphicClassNameStored: Boolean;
begin
  Result := GraphicClass <> GetDefaultGraphicClass;
end;

procedure TcxCustomImageProperties.ReadIsGraphicClassNameEmpty(Reader: TReader);
begin
  Reader.ReadBoolean;
  GraphicClassName := '';
end;

procedure TcxCustomImageProperties.SetCaption(const Value: string);
begin
  if FCaption <> Value then
  begin
    FCaption := Value;
    Changed;
  end;
end;

procedure TcxCustomImageProperties.SetCenter(AValue: Boolean);
begin
  if FCenter <> AValue then
  begin
    FCenter := AValue;
    Changed;
  end;
end;

procedure TcxCustomImageProperties.SetGraphicClass(
  const Value: TGraphicClass);
begin
  if FGraphicClass <> Value then
  begin
    FGraphicClass := Value;
    Changed;
  end;
end;

procedure TcxCustomImageProperties.SetGraphicClassName(
  const Value: string);
var
  AGraphicClass: TGraphicClass;
begin
  if Value = '' then
    GraphicClass := nil
  else
  begin
    AGraphicClass := GetGraphicClassByName(Value);
    if AGraphicClass <> nil then
      GraphicClass := AGraphicClass;
  end;
end;

procedure TcxCustomImageProperties.SetGraphicTransparency(
  Value: TcxImageTransparency);
begin
  if FGraphicTransparency <> Value then
  begin
    FGraphicTransparency := Value;
    FNeedUpdateImage := True;
    Changed;
  end;
end;

procedure TcxCustomImageProperties.SetPopupMenuLayout(
  Value: TcxPopupMenuLayout);
begin
  FPopupMenuLayout.Assign(Value);
end;

procedure TcxCustomImageProperties.SetProportional(AValue: Boolean);
begin
  if Proportional <> AValue then
    FitMode := CalculateFitMode(AValue, Stretch);
end;

procedure TcxCustomImageProperties.SetStretch(AValue: Boolean);
begin
  if Stretch <> AValue then
    FitMode := CalculateFitMode(Proportional, AValue);
end;

procedure TcxCustomImageProperties.SetFitMode(AValue: TcxImageFitMode);
begin
  if FitMode <> AValue then
  begin
    FFitMode := AValue;
    Changed;
  end;
end;

procedure TcxCustomImageProperties.SetShowFocusRect(Value: Boolean);
begin
  if FShowFocusRect <> Value then
  begin
    FShowFocusRect := Value;
    Changed;
  end;
end;

function TcxCustomImageProperties.CalculateFitMode(AProportional, AStretch: Boolean): TcxImageFitMode;
begin
  if AProportional then
    if AStretch then
      Result := ifmProportionalStretch
    else
      Result := ifmFit
  else
    if AStretch then
      Result := ifmStretch
    else
      Result := ifmNormal;
end;

function TcxCustomImageProperties.GetProportional: Boolean;
begin
  Result := FitMode in [ifmProportionalStretch, ifmFit];
end;

function TcxCustomImageProperties.GetStretch: Boolean;
begin
  Result := FitMode in [ifmProportionalStretch, ifmStretch];
end;

procedure TcxCustomImageProperties.WriteIsGraphicClassNameEmpty(Writer: TWriter);
begin
  Writer.WriteBoolean(True);
end;

function TcxCustomImageProperties.CanValidate: Boolean;
begin
  Result := True;
end;

procedure TcxCustomImageProperties.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('IsGraphicClassNameEmpty', ReadIsGraphicClassNameEmpty,
    WriteIsGraphicClassNameEmpty, GraphicClassName = '');
end;

procedure TcxCustomImageProperties.DoAssign(AProperties: TcxCustomEditProperties);
begin
  inherited;
  if AProperties is TcxCustomImageProperties then
    with TcxCustomImageProperties(AProperties) do
    begin
      Self.Caption := Caption;
      Self.Center := Center;
      Self.CustomFilter := CustomFilter;
      Self.GraphicClass := GraphicClass;
      Self.GraphicTransparency := GraphicTransparency;
      Self.PopupMenuLayout := PopupMenuLayout;
      Self.ShowFocusRect := ShowFocusRect;
      Self.Proportional := Proportional;
      Self.Stretch := Stretch;
      Self.OnAssignPicture := OnAssignPicture;
      Self.OnCustomClick := OnCustomClick;
      Self.OnGetGraphicClass := OnGetGraphicClass;
    end;
end;

function TcxCustomImageProperties.IsDesigning: Boolean;
var
  AOwner: TPersistent;
begin
  AOwner := GetOwner;
  Result := (AOwner is TComponent) and
    (csDesigning in (AOwner as TComponent).ComponentState);
end;

function TcxCustomImageProperties.GetDefaultGraphicClass: TGraphicClass;
begin
  if GetRegisteredGraphicClasses.Count > 0 then
    Result := TGraphicClass(GetRegisteredGraphicClasses[0])
  else
    Result := nil;
end;

function TcxCustomImageProperties.GetRealStretch(const APictureSize, ABoundsSize: TSize): Boolean;
begin
  Result := Stretch or (Proportional and
    ((APictureSize.cy > ABoundsSize.cy) or (APictureSize.cx > ABoundsSize.cx)));
end;

class function TcxCustomImageProperties.GetViewDataClass: TcxCustomEditViewDataClass;
begin
  Result := TcxImageViewData;
end;

function TcxCustomImageProperties.IsScrollbarsNeeded(APicture: TPicture): Boolean;
begin
  Result := not Center and (FitMode = ifmNormal) and IsPictureAssigned(APicture);
end;

class function TcxCustomImageProperties.GetContainerClass: TcxContainerClass;
begin
  Result := TcxImage;
end;

function TcxCustomImageProperties.GetDisplayText(const AEditValue: TcxEditValue;
  AFullText: Boolean = False; AIsInplace: Boolean = True): WideString;
begin
  if VarIsNull(AEditValue) then Result := '' else Result := Caption;
end;

function TcxCustomImageProperties.GetEditValueSource(AEditFocused: Boolean): TcxDataEditValueSource;
begin
  Result := evsValue;
end;

function TcxCustomImageProperties.GetGraphicClass(AItem: TObject;
  ARecordIndex: Integer; APastingFromClipboard: Boolean = False): TGraphicClass;
begin
  Result := FGraphicClass;
  if Result = nil then
  begin
    if APastingFromClipboard then
      Result := TBitmap;
    if Assigned(FOnGetGraphicClass) then
      FOnGetGraphicClass(AItem, ARecordIndex, APastingFromClipboard, Result);
  end;
end;

function TcxCustomImageProperties.GetSpecialFeatures: TcxEditSpecialFeatures;
begin
  Result := inherited GetSpecialFeatures + [esfMultiRow, esfBlobEditValue];
end;

function TcxCustomImageProperties.GetSupportedOperations: TcxEditSupportedOperations;
begin
  Result := inherited GetSupportedOperations + [esoAutoHeight, esoEditing];
end;

class function TcxCustomImageProperties.GetViewInfoClass: TcxContainerViewInfoClass;
begin
  Result := TcxImageViewInfo;
end;

function TcxCustomImageProperties.IsResetEditClass: Boolean;
begin
  Result := True;
end;

procedure TcxCustomImageProperties.ValidateDisplayValue(var DisplayValue: TcxEditValue;
  var ErrorText: TCaption; var Error: Boolean; AEdit: TcxCustomEdit);
begin
  with TcxCustomImage(AEdit) do
  begin
    LockEditValueChanging(True);
    try
      DoOnAssignPicture;
      SaveModified;
      try
        EditModified := False;
        DoEditing;
      finally
        RestoreModified;
      end;
    finally
      LockEditValueChanging(False);
    end;
  end;
end;

{ TcxCustomImage }

constructor TcxCustomImage.Create(AOwner: TComponent);
begin
  inherited;
  FScale := 100;
  FMaxScale := 500;
  DoubleBuffered := True;

  FAllowUserChangeScale := True;
end;

destructor TcxCustomImage.Destroy;
begin
  if FEditPopupMenu <> nil then FEditPopupMenu.Free;
  FPicture.Free;
  inherited Destroy;
end;

function TcxCustomImage.CanScaleByMouseWheel(AShift: TShiftState; const AMousePos: TPoint): Boolean;
begin
  Result := Scalable and (ssCtrl in AShift) and IsScrollbarsNeeded and AllowUserChangeScale;
end;

procedure TcxCustomImage.EditAndClear;
begin
  if DoEditing then
    FPicture.Graphic := nil;
end;

procedure TcxCustomImage.EditPopupMenuClick(Sender: TObject);
begin
  MenuItemClick(Sender, TcxPopupMenuItem(TMenuItem(Sender).Tag));
end;

function TcxCustomImage.GetProperties: TcxCustomImageProperties;
begin
  Result := TcxCustomImageProperties(FProperties);
end;

function TcxCustomImage.GetViewInfo: TcxImageViewInfo;
begin
  Result := TcxImageViewInfo(inherited ViewInfo);
end;

function TcxCustomImage.GetActiveProperties: TcxCustomImageProperties;
begin
  Result := TcxCustomImageProperties(InternalGetActiveProperties);
end;

procedure TcxCustomImage.MenuItemClick(Sender: TObject;
  MenuItem: TcxPopupMenuItem);
begin
  IsUserAction := True;
  try
    case MenuItem of
      pmiCut: CutToClipboard;
      pmiCopy: CopyToClipboard;
      pmiPaste: PasteFromClipboard;
      pmiDelete: EditAndClear;
      pmiLoad: LoadFromFile;
      pmiSave: SaveToFile;
      pmiCustom: CustomClick;
    end;
  finally
    IsUserAction := False;
  end;
end;

procedure TcxCustomImage.PictureChanged(Sender: TObject);
var
  APrevEvent: TNotifyEvent;
begin
  if IsLoading then
    Exit;
  LockChangeEvents(True);
  try
    if Picture.Graphic is TIcon then // Otherwise the Icon returns the incorrect sizes
      TIcon(Picture.Graphic).Handle; // HandleNeeded;

    if ActiveProperties.GraphicTransparency <> gtDefault then
    begin
      APrevEvent := Picture.OnChange;
      try
        Picture.OnChange := nil;
        if IsPictureAssigned(Picture) then
          Picture.Graphic.Transparent := ActiveProperties.GraphicTransparency = gtTransparent;
      finally
        Picture.OnChange := APrevEvent;
      end;
    end;

    SetSize;
    if IsUserAction then
      ModifiedAfterEnter := True;
    DoChange;
    ShortRefreshContainer(False);
    
    if ActiveProperties.ImmediatePost and CanPostEditValue and InternalValidateEdit then
      InternalPostEditValue;
  finally
    LockChangeEvents(False);
  end;
  CheckScrollbars(True);
  ActiveProperties.FNeedUpdateImage := False;
end;

procedure TcxCustomImage.PreparePopup;

  procedure RefreshCaptions;
  begin
    with FEditPopupMenu do
    begin
      Items[0].Caption := cxGetResourceString(@cxSMenuItemCaptionCut);
      Items[1].Caption := cxGetResourceString(@cxSMenuItemCaptionCopy);
      Items[2].Caption := cxGetResourceString(@cxSMenuItemCaptionPaste);
      Items[3].Caption := cxGetResourceString(@cxSMenuItemCaptionDelete);
      Items[5].Caption := cxGetResourceString(@cxSMenuItemCaptionLoad);
      Items[6].Caption := cxGetResourceString(@cxSMenuItemCaptionSave);
    end;
  end;

  function NewItem(const ACaption: string; ABitmap: TBitmap; ATag: TdxNativeInt): TMenuItem;
  begin
    Result := TMenuItem.Create(Self);
    with Result do
    begin
      Caption := ACaption;
      if Assigned(ABitmap) then
        Bitmap := ABitmap
      else
        ImageIndex := ATag;
      Tag := ATag;
      OnClick := EditPopupMenuClick;
    end;
  end;

  procedure AddItem(AItems: TMenuItem; AMenuItem: TcxPopupMenuItem);
  begin
    with AItems do
    begin
      if AMenuItem = pmiCustom then
      begin
        ActiveProperties.PopupMenuLayout.CustomMenuItemGlyph.Transparent := True;
        Add(NewItem(ActiveProperties.PopupMenuLayout.CustomMenuItemCaption,
          ActiveProperties.PopupMenuLayout.CustomMenuItemGlyph, TdxNativeInt(AMenuItem)));
      end
      else
        Add(NewItem('', nil, TdxNativeInt(AMenuItem)));
      if AMenuItem in [pmiDelete, pmiSave] then
        Add(NewItem('-', nil, -1));
    end;
  end;

var
  I: TcxPopupMenuItem;
  AFlagRO, AFlagEmpty, AIsIcon, ACanPaste: Boolean;
begin
  with ActiveProperties.PopupMenuLayout do
  begin
    if FEditPopupMenu = nil then
    begin
      FEditPopupMenu := TPopupMenu.Create(nil);
      FEditPopupMenu.Images := cxImageCommonResources.PopupMenuImageList;
      for I := Low(TcxPopupMenuItem) to High(TcxPopupMenuItem) do
        AddItem(FEditPopupMenu.Items, I);
    end;
    RefreshCaptions;
    // visible
    with FEditPopupMenu do
    begin
      Items[0].Visible := pmiCut in MenuItems;
      Items[1].Visible := pmiCopy in MenuItems;
      Items[2].Visible := pmiPaste in MenuItems;
      Items[3].Visible := pmiDelete in MenuItems;
      Items[5].Visible := pmiLoad in MenuItems;
      Items[6].Visible := pmiSave in MenuItems;
      Items[8].Visible := pmiCustom in MenuItems;
      // Separators
      Items[4].Visible := Items[5].Visible or Items[6].Visible;
      Items[7].Visible := Items[8].Visible;

      AIsIcon := ActiveProperties.GraphicClass = TIcon;

      ACanPaste := CanPasteFromClipboard;
      // Custom Item
      with Items[8] do
      begin
        Caption := CustomMenuItemCaption;
        Bitmap := CustomMenuItemGlyph;
      end;

      AFlagRO := not CanModify;
      AFlagEmpty := not IsPictureAssigned(FPicture);
      Items[0].Enabled := not (AFlagEmpty or AFlagRO or AIsIcon);
      Items[1].Enabled := not AFlagEmpty and not AIsIcon;
      Items[2].Enabled := not AFlagRO and ACanPaste;
      Items[3].Enabled := not AFlagEmpty and not AFlagRO;
      Items[5].Enabled := not AFlagRO;
      Items[6].Enabled := not AFlagEmpty;
    end;
  end;
end;

procedure TcxCustomImage.SetPicture(Value: TPicture);
begin
  FPicture.Assign(Value);
end;

procedure TcxCustomImage.SetProperties(const Value: TcxCustomImageProperties);
begin
  FProperties.Assign(Value);
end;

function TcxCustomImage.GetCurrentScale: Integer;
begin
  if Scalable then
    Result := Scale
  else
    Result := 100;
end;

procedure TcxCustomImage.SetScalable(AValue: Boolean);
begin
  if Scalable <> AValue then
  begin
    FScalable := AValue;
    CheckScrollbars;
    ShortRefreshContainer(False);
  end;
end;

procedure TcxCustomImage.SetScale(AValue: Integer);
var
  APrevScale: Integer;
  cx, cy: double;
begin
  AValue := Min(MaxScale, Max(MinScale, AValue));
  if Scale <> AValue then
  begin
    APrevScale := Scale;
    FScale := AValue;
    if Scalable then
    begin
      if APrevScale <> 0 then
      begin
        cx := (GetLeftPos + GetClientSize.cx / 2) * Scale / APrevScale;
        cy := (GetTopPos + GetClientSize.cy / 2) * Scale / APrevScale;
      end
      else
      begin
        cx := 0;
        cy := 0;
      end;

      TdxScrollHelper.SetPos(Self, Round(cx - GetClientSize.cx / 2), Round(cy - GetClientSize.cy / 2));
    end;
    CheckScrollbars;
    ShortRefreshContainer(False);
  end;
end;

function TcxCustomImage.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  if AScrollKind = sbHorizontal then
    Result := HScrollBarVisible
  else
    Result := VScrollBarVisible;
end;

function TcxCustomImage.CanAutoSize: Boolean;
begin
  Result := inherited CanAutoSize and IsPictureAssigned(Picture);
end;

function TcxCustomImage.CanAutoWidth: Boolean;
begin
  Result := True;
end;

procedure TcxCustomImage.DoContextPopup( MousePos: TPoint;
  var Handled: Boolean);
var
  P: TPoint;
begin
  if (PopupMenu = nil) and (ActiveProperties.PopupMenuLayout.MenuItems <> []) then
  begin
    Handled := True;
    P := MousePos;
    if (P.X = -1) and (P.Y = -1) then
    begin
      P.X := 10;
      P.Y := 10;
    end;
    // Popup
    PreparePopup;
    P := ClientToScreen(P);
    FEditPopupMenu.Popup(P.X, P.Y);
  end
  else
    inherited;
end;

function TcxCustomImage.GetDefaultPanOptions: Integer;
begin
  Result := inherited GetDefaultPanOptions and not GC_PAN_WITH_GUTTER;
end;

function TcxCustomImage.InternalMouseWheel(Shift: TShiftState; WheelDelta: Integer;
  MousePos: TPoint): Boolean;
begin
  Result := CanScaleByMouseWheel(Shift, MousePos);
  if Result then
    Scale := Scale + Sign(WheelDelta)* 2
  else
    Result := inherited InternalMouseWheel(Shift, WheelDelta, MousePos);
end;

function TcxCustomImage.IsDefaultGesture(AGestureID: Integer): Boolean;
begin
  Result := inherited IsDefaultGesture(AGestureID) or (AGestureID = GID_ZOOM);
end;

function TcxCustomImage.IsMouseWheelHandleNeeded(Shift: TShiftState; WheelDelta: Integer;
  MousePos: TPoint): Boolean;
begin
  Result := inherited IsMouseWheelHandleNeeded(Shift, WheelDelta, MousePos) or
    CanScaleByMouseWheel(Shift, MousePos);
end;

function TcxCustomImage.IsPanArea(const APoint: TPoint): Boolean;
begin
  Result := not cxRectPtIn(ViewInfo.FZoomInButtonRect, APoint) and
    not cxRectPtIn(ViewInfo.FZoomOutButtonRect, APoint) and
    inherited IsPanArea(APoint);
end;

procedure TcxCustomImage.Initialize;
begin
  inherited Initialize;
  AutoSize := False;
  Width := 140;
  Height := 100;
  FClipboardFormat := CF_PICTURE;
  FPicture := TPicture.Create;
  FPicture.OnChange := PictureChanged;
  ViewInfo.Picture := FPicture;
end;

procedure TcxCustomImage.Centre;
begin
  if ActiveProperties.IsScrollbarsNeeded(Picture) then
  begin
    TdxScrollHelper.SetPos(Self,
      (GetContentSize.cx - cxSize(ClientBounds).cx) div 2,
      (GetContentSize.cy - cxSize(ClientBounds).cy) div 2);
  end;
end;

procedure TcxCustomImage.CheckScrollbars(AResetPosition: Boolean);
begin
  UpdateScrollBars;
  if IsScrollbarsNeeded then
  begin
    if AResetPosition then
      TdxScrollHelper.SetPos(Self, 0, 0)
    else
      TdxScrollHelper.CheckPositions(Self);
  end;
end;

procedure TcxCustomImage.InitScrollBarsParameters;
begin
  if not ViewInfo.Calculated and HandleAllocated then
    CalculateViewInfo(False);
  if IsInplace or AutoSize or IsRectEmpty(ClientBounds) or not IsPictureAssigned(Picture) or // TODO
    ActiveProperties.Center or ViewInfo.GetRealStretch then // TODO
      Exit;

  TdxScrollHelper.InitScrollBarsParameters(Self);
end;

procedure TcxCustomImage.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  IsUserAction := True;
  try
    case Key of
      VK_INSERT:
        if ssShift in Shift then
          PasteFromClipBoard
        else
          if ssCtrl in Shift then
            CopyToClipBoard;
      VK_DELETE:
        if ssShift in Shift then
          CutToClipBoard;
    end;
  finally
    IsUserAction := False;
  end;
end;

procedure TcxCustomImage.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  IsUserAction := True;
  try
    case Key of
      ^X: CutToClipBoard;
      ^C: CopyToClipBoard;
      ^V: PasteFromClipBoard;
    end;
  finally
    IsUserAction := False;
  end;
end;

procedure TcxCustomImage.MouseEnter(AControl: TControl);
begin
  Invalidate;
end;

procedure TcxCustomImage.MouseLeave(AControl: TControl);
begin
  ShortRefreshContainer(True);
  Invalidate;
end;

procedure TcxCustomImage.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if (Button = mbLeft) and not IsScrollBarsArea(Point(X, Y)) then
    FLastDragPos := Point(X, Y)
  else
    FLastDragPos := cxInvalidPoint;
  inherited;
end;

procedure TcxCustomImage.MouseMove(Shift: TShiftState; X, Y: Integer);
var
  dx, dy: Integer;
begin
  if (ssLeft in Shift) and not cxPointIsInvalid(FLastDragPos) and ActiveProperties.IsScrollbarsNeeded(Picture) then
  begin
    dx := FLastDragPos.X - X;
    dy := FLastDragPos.Y - Y;
    TdxScrollHelper.SetPos(Self, GetLeftPos + dx, GetTopPos + dy);
    FLastDragPos := Point(X, Y);
  end;
  inherited;
end;

procedure TcxCustomImage.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if (Button = mbLeft) and not cxPointIsInvalid(FLastDragPos) and ActiveProperties.IsScrollbarsNeeded(Picture) and Scalable then
  begin
    if cxRectPtIn(ViewInfo.FZoomOutButtonRect, Point(X, Y)) then
      Scale := Scale - 5
    else
      if cxRectPtIn(ViewInfo.FZoomInButtonRect, Point(X, Y)) then
        Scale := Scale + 5;
  end;
  inherited;
end;

function TcxCustomImage.NeedsInvokeAfterKeyDown(AKey: Word;
  AShift: TShiftState): Boolean;
begin
  Result := inherited NeedsInvokeAfterKeyDown(AKey, AShift);
  case AKey of
    VK_INSERT:
      Result := AShift * [ssCtrl, ssShift] = [];
    VK_DELETE:
      Result := not (ssShift in AShift);
  end;
end;

function TcxCustomImage.IsScrollbarsNeeded: Boolean;
begin
  Result := (ActiveProperties <> nil) and ActiveProperties.IsScrollbarsNeeded(Picture);
end;

function TcxCustomImage.NeedsScrollBars: Boolean;
begin
  Result := True;
end;

procedure TcxCustomImage.Scroll(AScrollBarKind: TScrollBarKind;
  AScrollCode: TScrollCode; var AScrollPos: Integer);
begin
  TdxScrollHelper.Scroll(Self, AScrollBarKind, AScrollCode, AScrollPos);
end;

function TcxCustomImage.GetEditValue: TcxEditValue;
var
  S: AnsiString;
begin
  if IsPictureAssigned(FPicture) then
  begin
    SavePicture(FPicture, S);
    Result := S;
  end
  else
    Result := Null;
end;

procedure TcxCustomImage.InternalSetEditValue(const Value: TcxEditValue; AIsValueValid: Boolean);
begin
  if not VarEquals(EditValue, Value) then
  begin
    try
      if dxVarIsBlob(Value) then
        LoadPicture(Picture, GetGraphicClass, Value)
      else
        Picture.Assign(nil);
    finally
      EditModified := False;
    end;
  end;
end;

procedure TcxCustomImage.PropertiesChanged(Sender: TObject);
begin
  if not PropertiesChangeLocked and not IsLoading then
  begin
    if ActiveProperties.FNeedUpdateImage then
      PictureChanged(nil);

    CheckScrollbars;
    inherited;
  end;
end;

procedure TcxCustomImage.BoundsChanged;
begin
  inherited;
  CheckScrollbars;
end;

function TcxCustomImage.GetLeftPos: Integer;
begin
  Result := ViewInfo.TopLeft.X;
end;

procedure TcxCustomImage.SetLeftPos(Value: Integer);
begin
  ViewInfo.TopLeft.X := Value;
end;

function TcxCustomImage.GetTopPos: Integer;
begin
  Result := ViewInfo.TopLeft.Y;
end;

procedure TcxCustomImage.SetTopPos(Value: Integer);
begin
  ViewInfo.TopLeft.Y := Value;
end;

function TcxCustomImage.GetContentSize: TSize;
var
  AImageSize: TSize;
  AImageRect: TRect;
begin
  AImageSize := dxGetImageSize(Picture);
  AImageRect := cxGetImageRect(ClientBounds, AImageSize, ActiveProperties.FitMode, ActiveProperties.Center, GetCurrentScale);
  Result := cxSize(AImageRect);
end;

function TcxCustomImage.GetClientSize: TSize;
begin
  Result := TdxScrollHelper.GetClientSize(Self);
end;

function TcxCustomImage.GetInstance: TcxControl;
begin
  Result := Self;
end;

procedure TcxCustomImage.Zoom(ADelta: Integer; var AHandled: Boolean);
begin
  if Scalable and AllowUserChangeScale then
    Scale := Scale + ADelta div 4;
  AHandled := True;
end;

function TcxCustomImage.CanPasteFromClipboard: Boolean;
var
  AGraphicClass: TGraphicClass;
begin
  AGraphicClass := ActiveProperties.GraphicClass;
  if AGraphicClass = TBitmap then
    Result := Clipboard.HasFormat(CF_BITMAP)
  else if AGraphicClass = TIcon then
    Result := False
  else if AGraphicClass = TMetafile then
    Result := Clipboard.HasFormat(CF_METAFILEPICT)
  {$IFDEF USEJPEGIMAGE}
  else if AGraphicClass = TJPEGImage then
    Result := Clipboard.HasFormat(CF_BITMAP)
  {$ENDIF}
  else if AGraphicClass = nil then
    Result := Clipboard.HasFormat(CF_PICTURE)
  else
    Result := Clipboard.HasFormat(ClipboardFormat);
end;

procedure TcxCustomImage.CustomClick;
begin
  with Properties do
    if Assigned(OnCustomClick) then
      OnCustomClick(Self);
  if RepositoryItem <> nil then
    with ActiveProperties do
      if Assigned(OnCustomClick) then
        OnCustomClick(Self);
end;

procedure TcxCustomImage.DoOnAssignPicture;
begin
  with Properties do
    if Assigned(OnAssignPicture) then
      OnAssignPicture(Self, Picture);
  if RepositoryItem <> nil then
    with ActiveProperties do
      if Assigned(OnAssignPicture) then
        OnAssignPicture(Self, Picture);
end;

procedure TcxCustomImage.DoPictureLoadedFromFile(AFileName: string);
begin
end;

function TcxCustomImage.GetGraphicClass(APastingFromClipboard: Boolean = False): TGraphicClass;
begin
  if IsInplace then
    Result := ActiveProperties.GetGraphicClass(InplaceParams.Position.Item,
      InplaceParams.Position.RecordIndex, APastingFromClipboard)
  else
  begin
    Result := ActiveProperties.GraphicClass;
    if Result = nil then
    begin
      if APastingFromClipboard then
        Result := TBitmap;
      if Assigned(FOnGetGraphicClass) then
        FOnGetGraphicClass(Self, APastingFromClipboard, Result);
    end;
  end;
end;

procedure TcxCustomImage.CopyToClipboard;
begin
  if (FPicture <> nil) and (FPicture.Graphic <> nil) then
    Clipboard.Assign(FPicture);
end;

procedure TcxCustomImage.CutToClipboard;
begin
  CopyToClipboard;
  EditAndClear;
end;

function TcxCustomImage.Focused: Boolean;
begin
  Result := FIsDialogShowed or inherited Focused;
end;

class function TcxCustomImage.GetPropertiesClass: TcxCustomEditPropertiesClass;
begin
  Result := TcxCustomImageProperties;
end;

procedure TcxCustomImage.LoadFromFile;

  function GetDialogFilter: string;
  var
    AGraphicClass: TGraphicClass;
  begin
    if ActiveProperties.CustomFilter <> '' then
      Result := ActiveProperties.CustomFilter
    else
    begin
      AGraphicClass := ActiveProperties.GraphicClass;
      if AGraphicClass <> nil then
        Result := GraphicFilter(AGraphicClass)
      else
        Result := GraphicFilter(TGraphic);
    end;
  end;

var
  ADialog: TOpenPictureDialog;
begin
  if not CanModify then
    Exit;
  ADialog := TOpenPictureDialog.Create(nil);
  try
    FIsDialogShowed := True;
    ADialog.Filter := GetDialogFilter;
    if ADialog.Execute and DoEditing then
    begin
      FPicture.LoadFromFile(ADialog.FileName);
      DoClosePopup(crEnter);
      DoPictureLoadedFromFile(ADialog.FileName);
    end
    else
      DoClosePopup(crCancel);
    Application.ProcessMessages;
  finally
    FIsDialogShowed := False;
    ADialog.Free;
  end;
end;

procedure TcxCustomImage.PasteFromClipboard;
var
{$IFDEF USEJPEGIMAGE}
  AGraphicClass: TGraphicClass;
  AGraphic: TJPEGImage;
{$ENDIF}
  APrevEvent: TNotifyEvent;
begin
  if CanPasteFromClipboard and DoEditing then
  begin
    APrevEvent := Picture.OnChange;
    try
      Picture.OnChange := nil;
      if Clipboard.HasFormat(CF_BITMAP) then
      begin
     {$IFDEF USEJPEGIMAGE}
        AGraphicClass := GetGraphicClass(True);
        if (AGraphicClass = TJPEGImage) then
        begin
          AGraphic := TJPEGImage.Create;
          try
            TJPEGImageAccess(AGraphic).NewBitmap;
            TJPEGImageAccess(AGraphic).Bitmap.Assign(Clipboard);
            AGraphic.JPEGNeeded;
            Picture.Graphic := AGraphic;
          finally
            AGraphic.Free;
          end;
        end
        else
     {$ENDIF}
          Picture.Bitmap.Assign(Clipboard);
      end
      else
        Picture.Assign(Clipboard);
    finally
      Picture.OnChange := APrevEvent;
    end;
    TPictureAccess(Picture).Changed(Picture);
  end;
end;

procedure TcxCustomImage.SaveToFile;
var
  ADialog: TSavePictureDialog;
begin
  if (FPicture = nil) or (FPicture.Graphic = nil) then
    Exit;
  ADialog := TSavePictureDialog.Create(Application);
  FIsDialogShowed := True;
  try
    if ActiveProperties.CustomFilter <> '' then
      ADialog.Filter := ActiveProperties.CustomFilter
    else
      ADialog.Filter := GraphicFilter(TGraphicClass(FPicture.Graphic.ClassType));
    ADialog.DefaultExt := GraphicExtension(TGraphicClass(FPicture.Graphic.ClassType));
    if ADialog.Execute then
      FPicture.SaveToFile(ADialog.FileName);
    Application.ProcessMessages;
  finally
    FIsDialogShowed := False;
    ADialog.Free;
  end;
end;

{ TcxImage }

class function TcxImage.GetPropertiesClass: TcxCustomEditPropertiesClass;
begin
  Result := TcxImageProperties;
end;

function TcxImage.GetActiveProperties: TcxImageProperties;
begin
  Result := TcxImageProperties(InternalGetActiveProperties);
end;

function TcxImage.GetProperties: TcxImageProperties;
begin
  Result := TcxImageProperties(FProperties);
end;

procedure TcxImage.SetProperties(Value: TcxImageProperties);
begin
  FProperties.Assign(Value);
end;

{ TcxImageViewInfo }

destructor TcxImageViewInfo.Destroy;
begin
  if FFreePicture then
    FreeAndNil(Picture);
  inherited Destroy;
end;

procedure TcxImageViewInfo.DrawTransparentBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  ACanvas.SaveClipRegion;
  try
    ACanvas.SetClipRegion(TcxRegion.Create(R), roIntersect);
    cxDrawTransparentControlBackground(Edit, ACanvas, Bounds);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TcxImageViewInfo.DrawZoomInButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  if not cxRectIsEmpty(R) then
  begin
  {
    if UseSkins then
      Painter.DrawZoomInButton(ACanvas, R, AState)
    else
    }
      FZoomButtons.Draw(ACanvas.Handle, R, 1);
  end;
end;

procedure TcxImageViewInfo.DrawZoomOutButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  if not cxRectIsEmpty(R) then
  begin
  {
    if UseSkins then
      Painter.DrawZoomOutButton(ACanvas, R, AState)
    else
    }
      FZoomButtons.Draw(ACanvas.Handle, R, 0);
  end;
end;

procedure TcxImageViewInfo.InternalPaint(ACanvas: TcxCanvas);
var
  CR, R, R2: TRect;
begin
  if Transparent and not IsInplace then
    DrawTransparentBackground(ACanvas, Bounds);

  CR := ClientRect;
  inherited InternalPaint(ACanvas);
  if ShowFocusRect then
  begin
    ACanvas.FrameRect(CR, clBlack);
    InflateRect(CR, -1, -1);
  end;

  if not IsPictureAssigned(Picture) then
  begin
    inherited InternalPaint(ACanvas);
    ACanvas.Font.Color := TextColor;
    ACanvas.Font.Name := Font.Name;
    cxDrawText(ACanvas, Caption, CR, DT_CENTER or DT_VCENTER or DT_SINGLELINE);
  end
  else
  begin
    R := cxRectOffset(cxGetImageRect(CR, dxGetImageSize(Picture), FitMode, Center, Scale), TopLeft, False);
    if not Center and Scalable then
    begin
      R2 := cxRectCenter(ClientRect, cxSize(R));
      if cxRectWidth(R) < cxRectWidth(ClientRect) then
      begin
        R.Left := R2.Left;
        R.Right := R2.Right;
      end;
      if cxRectHeight(R) < cxRectHeight(ClientRect) then
      begin
        R.Top := R2.Top;
        R.Bottom := R2.Bottom;
      end;
    end;

    ACanvas.SaveClipRegion;
    try
      ACanvas.SetClipRegion(TcxRegion.Create(CR), roIntersect);
      ACanvas.StretchDraw(R, Picture.Graphic);
      DrawZoomInButton(ACanvas, FZoomInButtonRect, cxbsNormal);
      DrawZoomOutButton(ACanvas, FZoomOutButtonRect, cxbsNormal);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

function TcxImageViewInfo.IsRepaintOnStateChangingNeeded: Boolean;
begin
  Result := not IsPictureAssigned(Picture) and (Caption <> '');
end;

function TcxImageViewInfo.GetRealStretch: Boolean;
begin
  Result := TcxCustomImageProperties(EditProperties).GetRealStretch(
    Size(Picture.Width, Picture.Height),
    Size(cxRectWidth(ClientRect), cxRectHeight(ClientRect)));
end;

{ TcxImageViewData }

procedure TcxImageViewData.Calculate(ACanvas: TcxCanvas;
  const ABounds: TRect; const P: TPoint; Button: TcxMouseButton;
  Shift: TShiftState; AViewInfo: TcxCustomEditViewInfo; AIsMouseEvent: Boolean);
var
  AZoomOutButtonSize: TSize;
  AZoomInButtonSize: TSize;
  AProperties: TcxCustomImageProperties;
begin
  inherited Calculate(ACanvas, ABounds, P, Button, Shift, AViewInfo, AIsMouseEvent);
  if IsRectEmpty(ABounds) then
    Exit;
  AProperties := TcxCustomImageProperties(Properties);

  with TcxImageViewInfo(AViewInfo) do
  begin
    Caption := AProperties.Caption;
    Center := AProperties.Center;
    ShowFocusRect := AProperties.ShowFocusRect and Focused and not IsInplace;
    FitMode := AProperties.FitMode;
    if Edit <> nil then
    begin
      Scale := (Edit as TcxCustomImage).GetCurrentScale;
      Scalable := (Edit as TcxCustomImage).Scalable;
    end
    else
    begin
      Scale := 100;
      Scalable := False;
    end;

    if Center or AProperties.Stretch then
      TopLeft := Point(0, 0);

    if (Edit <> nil) and (Edit as TcxCustomImage).Scalable and (Edit as TcxCustomImage).AllowUserChangeScale and AProperties.IsScrollbarsNeeded(Picture) and cxRectPtIn(ABounds, P) then
    begin
      if (cxRectWidth(ABounds) > 150) and (cxRectHeight(ABounds) > 150) then
        FZoomButtons := cxImageCommonResources.LargeZoomButtons
      else
        FZoomButtons := cxImageCommonResources.SmallZoomButtons;


{      if UseSkins then
      begin
        AZoomOutButtonSize := Painter.GetZoomOutButtonSize;
        AZoomInButtonSize := Painter.GetZoomInButtonSize;
      end
      else}
      begin
        AZoomOutButtonSize := FZoomButtons.Size;
        AZoomInButtonSize := AZoomOutButtonSize;
      end;

      FZoomOutButtonRect := cxRectBounds(
        cxRectWidth(ClientRect) div 3 - AZoomOutButtonSize.cx,
        cxRectHeight(ClientRect) * 3 div 4, AZoomOutButtonSize.cx, AZoomOutButtonSize.cy);
      FZoomInButtonRect := cxRectBounds(
        cxRectWidth(ClientRect) * 2 div 3, cxRectHeight(ClientRect) * 3 div 4,
        AZoomInButtonSize.cx, AZoomInButtonSize.cy);
    end
    else
    begin
      FZoomOutButtonRect := cxNullRect;
      FZoomInButtonRect := cxNullRect;
    end;
  end;
end;

procedure TcxImageViewData.EditValueToDrawValue(
  const AEditValue: TcxEditValue; AViewInfo: TcxCustomEditViewInfo);
var
  AGraphicClass: TGraphicClass;
begin
  with TcxImageViewInfo(AViewInfo) do
    if Length(dxVariantToAnsiString(AEditValue)) > 0 then
    begin
      if not Assigned(Picture) then
      begin
        Picture := TPicture.Create;
        FFreePicture := True;
      end;
      AGraphicClass := TcxCustomImageProperties(Properties).GetGraphicClass(
        InplaceEditParams.Position.Item, InplaceEditParams.Position.RecordIndex);
      LoadPicture(Picture, AGraphicClass, AEditValue);
      if TcxCustomImageProperties(Properties).GraphicTransparency <> gtDefault then
        Picture.Graphic.Transparent :=
          TcxCustomImageProperties(Properties).GraphicTransparency = gtTransparent;
    end
    else
      if Assigned(Picture) then
        Picture.Assign(nil);
end;

function TcxImageViewData.GetEditContentSize(ACanvas: TcxCanvas;
  const AEditValue: TcxEditValue;
  const AEditSizeProperties: TcxEditSizeProperties): TSize;
var
  ABorderExtent: TRect;
  AGraphicClass: TGraphicClass;
  APicture: TPicture;
begin
  if IsInplace then
  begin
    if Edit <> nil then
    begin
      Result := Size(Edit.Width, Edit.Height);
      ABorderExtent := GetBorderExtent;
      Result.cx := Result.cx - (ABorderExtent.Left + ABorderExtent.Right);
      Result.cy := Result.cy - (ABorderExtent.Top + ABorderExtent.Bottom);
    end
    else
      with TcxCustomImageProperties(Properties) do
      begin
        Result := Size(0, DefaultHeight);
        if dxVarIsBlob(AEditValue) then
        begin
          AGraphicClass := GetGraphicClass(InplaceEditParams.Position.Item,
            InplaceEditParams.Position.RecordIndex);
          APicture := TPicture.Create;
          try
            LoadPicture(APicture, AGraphicClass, AEditValue);
            Result := Size(APicture.Width, APicture.Height);
          finally
            APicture.Free;
          end;
          if GetRealStretch(Result, Size(AEditSizeProperties.Width, AEditSizeProperties.Height)) then
          begin
            if (AEditSizeProperties.Width > 0) and (Result.cx > 0) and
                ((AEditSizeProperties.Height > 0) or (AEditSizeProperties.Width < Result.cx)) then
              Result := Size(AEditSizeProperties.Width, Round(Result.cy * AEditSizeProperties.Width / Result.cx))
            else
              if (AEditSizeProperties.Height > 0) and (Result.cy > 0) and
                  ((AEditSizeProperties.Width > 0) or (AEditSizeProperties.Height < Result.cy)) then
                Result := Size(Round(Result.cx * AEditSizeProperties.Height / Result.cy), AEditSizeProperties.Height);
          end;
        end
        else
          if Length(Caption) <> 0 then
          begin
            ACanvas.Font := Style.GetVisibleFont;
            Result := ACanvas.TextExtent(Caption);
          end;
      end;
  end
  else
    if Edit <> nil then
      with TcxCustomImage(Edit) do
        Result := Size(Picture.Width, Picture.Height)
    else
      Result := Size(0, 0);
end;

initialization
  GetRegisteredEditProperties.Register(TcxImageProperties, scxSEditRepositoryImageItem);

finalization
  FreeAndNil(cxRegisteredGraphicClasses);
  FreeAndNil(FCommonResources);
end.

