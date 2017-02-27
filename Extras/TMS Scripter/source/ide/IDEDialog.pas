unit IDEDialog;

{$I ASCRIPT.INC}

interface
uses Classes, Dialogs,
  {$IFDEF THEMED_IDE}
  AdvAppStyler,
  AdvStyleIF,
  {$ENDIF}
  IDEMain, atScript,
  {$IFDEF LIBBROWSER}
  fLibraryBrowser,
  {$ENDIF}
  fIDEEditor;

type
  TIDECloseAction = (icaCloseAll, icaNothing);
  {$IFDEF LIBBROWSER}
  TAcceptLibraryEvent = fLibraryBrowser.TAcceptLibraryEvent;
  TAcceptClassEvent = fLibraryBrowser.TAcceptClassEvent;
  TAcceptMethodEvent = fLibraryBrowser.TAcceptMethodEvent;
  TAcceptPropertyEvent = fLibraryBrowser.TAcceptPropertyEvent;
  {$ENDIF}

  {$IFDEF DELPHI9_LVL}
  TPaletteStyle = (psNewButtons, psOldTabs);
  {$ENDIF}

  {$IFDEF DELPHIXE2_LVL}
  [ComponentPlatformsAttribute(pidWin32 or pidWin64)]
  {$ENDIF}
  TIDEDialog = class(TComponent)
  private
    FEngine: TIDEEngine;
    //FScripter: TIDEScripter;
    FTitle: string;
    FCloseAction: TIDECloseAction;
    FOnCreateIDEForm: TNotifyEvent;
    FOnShowIDEForm: TNotifyEvent;
    {$IFDEF LIBBROWSER}
    FOnAcceptLibrary: TAcceptLibraryEvent;
    FOnAcceptClass: TAcceptClassEvent;
    FOnAcceptMethod: TAcceptMethodEvent;
    FOnAcceptProperty: TAcceptPropertyEvent;
    {$ENDIF}
    {$IFDEF DELPHI9_LVL}
    FPaletteStyle: TPaletteStyle;
    {$ENDIF}
    {$IFDEF THEMED_IDE}
    FAppStyler: TAdvAppStyler;
    {$ENDIF}
    //FCloseProjectOnExit: boolean;
    function GetEngine: TIDEEngine;
    procedure SetEngine(const Value: TIDEEngine);
    {$IFDEF THEMED_IDE}
    procedure SetAppStyler(const Value: TAdvAppStyler);
    {$ENDIF}
    procedure InternalExecute(IsModal: boolean);
    function FindIDEForm: TIDEEditorForm;

    {$IFDEF LIBBROWSER}
    procedure AcceptLibrary(Sender: TObject; const LibName: string; var Accept: boolean);
    procedure AcceptClass(Sender: TObject; AClass: TatClass; var Accept: boolean);
    procedure AcceptProperty(Sender: TObject; AProp: TatProperty; var Accept: boolean);
    procedure AcceptMethod(Sender: TObject; AMethod: TatMethod; var Accept: boolean);
    {$ENDIF}
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Execute;
    procedure Show;
    property OnCreateIDEForm: TNotifyEvent read FOnCreateIDEForm write FOnCreateIDEForm;
    property OnShowIDEForm: TNotifyEvent read FOnShowIDEForm write FOnShowIDEForm;
  published
    property Engine: TIDEEngine read GetEngine write SetEngine;
    property Title: string read FTitle write FTitle;
    property IDECloseAction: TIDECloseAction read FCloseAction write FCloseAction;
    {$IFDEF DELPHI9_LVL}
    property PaletteStyle: TPaletteStyle read FPaletteStyle write FPaletteStyle default psNewButtons;
    {$ENDIF}
    {$IFDEF THEMED_IDE}
    property AppStyler: TAdvAppStyler read FAppStyler write SetAppStyler;
    {$ENDIF}
    //property CloseProjectOnExit: boolean read FCloseProjectOnExit write FCloseProjectOnExit;
    {$IFDEF LIBBROWSER}
    property OnAcceptLibrary: TAcceptLibraryEvent read FOnAcceptLibrary write FOnAcceptLibrary;
    property OnAcceptClass: TAcceptClassEvent read FOnAcceptClass write FOnAcceptClass;
    property OnAcceptMethod: TAcceptMethodEvent read FOnAcceptMethod write FOnAcceptMethod;
    property OnAcceptProperty: TAcceptPropertyEvent read FOnAcceptProperty write FOnAcceptProperty;
    {$ENDIF}
  end;


implementation

uses
  Forms;

{ TIDEDialog }

{$IFDEF LIBBROWSER}
procedure TIDEDialog.AcceptClass(Sender: TObject; AClass: TatClass;
  var Accept: boolean);
begin
  if Assigned(FOnAcceptClass) then
    FOnAcceptClass(Self, AClass, Accept);
end;

procedure TIDEDialog.AcceptLibrary(Sender: TObject; const LibName: string;
  var Accept: boolean);
begin
  if Assigned(FOnAcceptLibrary) then
    FOnAcceptLibrary(Self, LibName, Accept);
end;

procedure TIDEDialog.AcceptMethod(Sender: TObject; AMethod: TatMethod;
  var Accept: boolean);
begin
  if Assigned(FOnAcceptMethod) then
    FOnAcceptMethod(Self, AMethod, Accept);
end;

procedure TIDEDialog.AcceptProperty(Sender: TObject; AProp: TatProperty;
  var Accept: boolean);
begin
  if Assigned(FOnAcceptProperty) then
    FOnAcceptProperty(Self, AProp, Accept);
end;
{$ENDIF}

constructor TIDEDialog.Create(AOwner: TComponent);
begin
  inherited;
  FTitle := 'TMS Scripter IDE - %s';
  FCloseAction := icaCloseAll;
  {$IFDEF DELPHI9_LVL}
  FPaletteStyle := psNewButtons;
  {$ENDIF}
end;

destructor TIDEDialog.Destroy;
begin
  inherited;
end;

procedure TIDEDialog.Execute;
begin
  InternalExecute(true);
end;

function TIDEDialog.FindIDEForm: TIDEEditorForm;
var
  I: integer;
begin
  for I := 0 to Screen.FormCount - 1 do
    if (Screen.Forms[I] is TIDEEditorForm) and (TIDEEditorForm(Screen.Forms[I]).Engine = Self.Engine) then
    begin
      Result := TIDEEditorForm(Screen.Forms[I]);
      Exit;
    end;
  Result := nil;
end;

function TIDEDialog.GetEngine: TIDEEngine;
begin
  result := FEngine;
end;

procedure TIDEDialog.InternalExecute(IsModal: boolean);
var
  IDEForm: TIDEEditorForm;
begin
  if Engine = nil then
    raise EIDEException.Create('Engine component not defined in TIDEDialog component.');
  if not IsModal then
  begin
    IDEForm := FindIDEForm;
    if IDEForm <> nil then
    begin
      IDEForm.Show;
      Exit;
    end;
  end;

  //FIDEForm.Scripter := FScripter;
  IDEForm := TIDEEditorForm.Create(Application);
  try
    {$IFDEF DELPHI9_LVL}
    if PaletteStyle = psOldTabs then
      IDEForm.ForceOldPalette := true;
    {$ENDIF}
    IDEForm.AttachEngine(FEngine);
    if Assigned(FOnCreateIDEForm) then
      FOnCreateIDEForm(IDEForm);
    IDEForm.OnNotifyShow := FOnShowIDEForm;

    {$IFDEF LIBBROWSER}
    IDEForm.LibraryBrowser.OnAcceptClass := AcceptClass;
    IDEForm.LibraryBrowser.OnAcceptLibrary := AcceptLibrary;
    IDEForm.LibraryBrowser.OnAcceptProperty := AcceptProperty;
    IDEForm.LibraryBrowser.OnAcceptMethod := AcceptMethod;
    {$ENDIF}

    IDEForm.Title := FTitle;
    case FCloseAction of
      icaCloseAll: IDEForm.CloseAllOnExit := true;
      icaNothing: IDEForm.CloseAllOnExit := false;
    end;

    {$IFDEF THEMED_IDE}
    IDEForm.AppStyler := FAppStyler;
    {$ENDIF}

    IDEForm.DestroyOnClose := not IsModal;
    if IsModal then
      IDEForm.ShowModal
    else
      IDEForm.Show;
  finally
    if IsModal then
    begin
      IDEForm.DetachEngine;
      IDEForm.Free;
    end;
  end;
end;

procedure TIDEDialog.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FEngine) then
    FEngine := nil;
  {$IFDEF THEMED_IDE}
  if (Operation = opRemove) and (AComponent = FAppStyler) then
    FAppStyler := nil;
  {$ENDIF}
end;

{$IFDEF THEMED_IDE}
procedure TIDEDialog.SetAppStyler(const Value: TAdvAppStyler);
begin
  if FAppStyler <> Value then
  begin
    if FAppStyler <> nil then
      FAppStyler.RemoveFreeNotification(Self);
    FAppStyler := Value;
    if FAppStyler <> nil then
      FAppStyler.FreeNotification(Self);
  end;
end;
{$ENDIF}

procedure TIDEDialog.SetEngine(const Value: TIDEEngine);
begin
  if FEngine <> Value then
  begin
    if FEngine <> nil then
      FEngine.RemoveFreeNotification(Self);
    FEngine := Value;
    if FEngine <> nil then
      FEngine.FreeNotification(Self);
  end;
end;

procedure TIDEDialog.Show;
begin
  InternalExecute(false);
end;

end.

