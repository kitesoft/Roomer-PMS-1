unit uRoomerForm;

interface

uses
  Vcl.Forms
  , Types
  , System.Classes
  , cxClasses
  , cxPropertiesStore
  , Winapi.Messages, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, Vcl.Controls,
  dxStatusBar, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, Vcl.ComCtrls, sStatusBar, acProgressBar,
  AdvSmoothProgressBar;

type
  /// <summary>
  ///   Possible Busystates of a Roomerform
  /// </summary>
  TRoomerFormBusyState = (fsIdle, fsLoadingData, fsPrinting);

  /// <summary>
  ///  Basic form to be used for all Roomer windows and dialogs. <br />
  ///  Restores and Stores its dimensional properties in the registry based on the actual form classname <br />
  ///  User can close window with ESC if that option is set (default = true) <br />
  ///  Contains a status panel with a statusindicator. Setting the BusyState property updates the statusmessage. <br/>
  ///  <br/>
  ///  The statusbar also contains a progressbar which is only visible when the position > 0 and position < max <br />
  ///  Forms derived from this base class should override the UpdateControls() ans DoLoadData() methods
  ///  </summary>
  TfrmBaseRoomerForm = class(TForm)
    psRoomerBase: TcxPropertiesStore;
    sbStatusBar: TsStatusBar;
    cxsrRoomerStyleRepository: TcxStyleRepository;
    procedure sbStatusBarDrawPanel(StatusBar: TStatusBar; Panel: TStatusPanel; const Rect: TRect);
    procedure sbProgressBarPositionChanged(Sender: TObject; Value: Double);
  private
    FCloseOnEsc: boolean;
    FBusyState: TRoomerFormBusyState;
    FUpdatingControls: boolean;
    FUpdatingData: boolean;
    FProgressBar: TAdvSmoothProgressBar;
    function GetStateTextPanel: TStatusPanel;
    function GetBusyState: TRoomerFormBusyState;
    procedure SetBusyState(const Value: TRoomerFormBusyState);
  protected
    const
      WM_REFRESH_DATA = WM_User + 51;
    var
    procedure WndProc(var message: TMessage); override;
    procedure DoShow; override;
    procedure Loaded; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    /// <summary>
    ///   Update the contents and/or properties of visual components, like Enabled etc
    /// </summary>
    procedure UpdateControls;
    procedure DoUpdateControls; virtual;
    /// <summary>
    ///   (Re)load data needed to display in the form
    /// </summary>
    procedure DoLoadData; virtual;
    procedure LoadData;
    property UpdatingData: boolean read FUpdatingData;
    property StateTextPanel: TStatusPanel read GetStateTextPanel;
    property ProgressBar: TAdvSmoothProgressBar read FProgressBar;
  public
    constructor Create(AOwner: TComponent); override;
    /// <summary>
    ///   Signal form through Windows messaging system to reload data and update controls
    /// </summary>
    procedure RefreshData;

  published
    /// <summary>
    ///  Close the window when ESC is pressed by the user, Default = True
    /// </summary>
    property CloseOnEsc: boolean read FCloseOnEsc write FCloseOnEsc default True;
    /// <summary>
    ///   The state of the form, made visible by the statusindicator and a message in the statuspanel
    /// </summary>
    property BusyState: TRoomerFormBusyState read GetBusyState write SetBusyState;
  end;

  //TODO: Create a form factory, with derivatives for implemented forms

implementation

{$R *.dfm}

uses
  uAppGlobal
  , Windows
  , uUtils
  , PrjConst
  , UITypes
  ;

type
  TRoomerFormBusyStateHelper = record helper for TRoomerFormBusyState
  public
    function StatusMessage: String;
//    function Indicator: TdxStatusBarStateIndicatorType;
  end;

{ TfrmBaseRoomerForm }

constructor TfrmBaseRoomerForm.Create(AOwner: TComponent);
begin
  inherited;

  // Place pogressbase on Statuspanel
  FProgressBar := TAdvSmoothProgressBar.Create(Self);
  FProgressBar.Parent := sbStatusBar;
  FProgressBar.Visible := False;

  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);

  FCloseOnEsc := True;
end;


procedure TfrmBaseRoomerForm.DoLoadData;
begin
  // to be overridden in derived classes
end;

procedure TfrmBaseRoomerForm.DoShow;
begin
  inherited; // Calls ShowForm event handler
  PlaceFormOnVisibleMonitor(Self);
  UpdateControls;
  BusyState := fsIdle;
end;

procedure TfrmBaseRoomerForm.DoUpdateControls;
begin
// to be overriden
end;

function TfrmBaseRoomerForm.GetBusyState: TRoomerFormBusyState;
begin
  Result := FBusyState;
end;

function TfrmBaseRoomerForm.GetStateTextPanel: TStatusPanel;
begin
  Result := sbStatusBar.Panels[1];
end;

procedure TfrmBaseRoomerForm.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited; // Calls FormKeyDown event if present
  if FCloseOnEsc and (Key = VK_ESCAPE) then
    Close;
end;

procedure TfrmBaseRoomerForm.LoadData;
var
  lCursor: TCursor;
begin
  if not FUpdatingData then
  try
    FUpdatingData := True;
    lCursor := Screen.Cursor;
    Screen.Cursor := crHourGlass;
    try
      BusyState := fsLoadingData;
      DoLoadData;
    finally
      BusyState := fsIdle;
      Screen.Cursor := lCursor;
    end;
  finally
    FUpdatingData := False;
  end;
end;

procedure TfrmBaseRoomerForm.Loaded;
begin
  psRoomerBase.StorageName := 'Software\Roomer\FormStatus\' + classname;
  inherited;
end;

procedure TfrmBaseRoomerForm.RefreshData;
begin
  PostMessage(Handle, WM_REFRESH_DATA, 0, 0);
end;

procedure TfrmBaseRoomerForm.sbProgressBarPositionChanged(Sender: TObject; Value: Double);
begin
  sbStatusBar.Repaint;
end;

procedure TfrmBaseRoomerForm.sbStatusBarDrawPanel(StatusBar: TStatusBar; Panel: TStatusPanel; const Rect: TRect);
begin
  if Panel = Statusbar.Panels[2] then
  begin
    FProgressBar.Visible := (FProgressBar.Position > 0) and (FProgressBar.Position < FProgressBar.Maximum);
    if FProgressBar.Visible then
    begin
      FProgressBar.Top := Rect.top;
      FProgressBar.Left := Rect.Left;
      FProgressBar.Width := Rect.Right - Rect.Left - 15;
      FProgressBar.Height := Rect.Bottom - Rect.Top;
    end;
  end;
end;

procedure TfrmBaseRoomerForm.SetBusyState(const Value: TRoomerFormBusyState);
begin
  if Value <> FBusyState then
  begin
    FBusyState := Value;
    StateTextPanel.Text := FBusyState.StatusMessage;
//    StateIndicator.IndicatorType := FBusyState.Indicator;
    sbStatusBar.Repaint;
  end;
end;

procedure TfrmBaseRoomerForm.UpdateControls;
begin
  if not FUpdatingControls then
  try
    FUpdatingControls := true;
    DoUpdateControls;
  finally
    FUpdatingControls := False;
  end;
end;

procedure TfrmBaseRoomerForm.WndProc(var message: TMessage);
begin
  if message.Msg = WM_REFRESH_DATA then
  begin
    LoadData;
    UpdateControls
  end;
  inherited WndProc(message);
end;

{ TRoomerBusyStateHelper }

function TRoomerFormBusyStateHelper.StatusMessage: String;
begin
  case Self of
    fsIdle:         Result := GetTranslatedText('shRoomerFormBusyStateIdle');
    fsLoadingData:  Result := GetTranslatedText('shRoomerFormBusyStateLoadingData');
    fsPrinting:     Result := GetTranslatedText('shRoomerFormBusyStatePrinting');
  else
    Result := '';
  end;

end;


end.
