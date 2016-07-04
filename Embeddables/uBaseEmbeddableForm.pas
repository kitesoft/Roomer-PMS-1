unit uBaseEmbeddableForm;

interface

uses
  Classes,
  VCL.Forms,
  Controls
  ;

type
  /// <summary>
  ///  Base and abstract form-class to implement embeddable controls <br />
  ///  To use, derive a form from TEmbeddableForm and implement getEmbeddableControl to return the part of the form that
  ///  should be embedded.
  /// </summary>
  /// <example>
  ///    TSomePanelForm = class(TEmbeddableForm)
  ///    protected
  ///       function GetEmbeddableControl: TControl; override; // returns the panel to embed
  ///     end;
  ///
  ///  f := TSomePanelForm.Create(nil);
  ///  try
  ///     f.Attach(MainForm.Groupbox1); // this will place the embeddable part of f into groupbox1
  ///  ...
  ///     f.Detach; // removed the embeddable part from the groupbox. Optionally, This is also done when f is freed
  ///  finally
  ///     f.Free;
  ///  end;
  ///  </example>
  TEmbeddableForm = class(TForm)
  private
    { Private declarations }
    FOriginalParent: TWinControl;
    FOnChange: TNotifyEvent;
    procedure SetOriginalParent(const Value: TWinControl);
  protected
    function GetEmbeddableControl: TControl; virtual; abstract;
    property OriginalParent: TWinControl read FOriginalParent write SetOriginalParent;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SignalChanges(Sender: TOjbect);
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;

    /// <summary>
    ///   Update visiblity and Enabled property of controls
    /// </summary>
    procedure UpdateControls; virtual; abstract;
    procedure Attach(aParent: TWinControl);
    procedure Detach;
    property EmbeddableControl: TControl read GetEmbeddableControl;
    property OnChange: TNotifyEvent read FOnChange write FOnchange;
  end;

implementation

{$R *.dfm}

procedure TEmbeddableForm.Attach(aParent: TWinControl);
begin
  OriginalParent := EmbeddableControl.Parent;
  EmbeddableControl.Parent := aParent;
end;

constructor TEmbeddableForm.Create(aOwner: TComponent);
begin
  inherited;
  FOriginalParent := nil;
end;

destructor TEmbeddableForm.Destroy;
begin
  Detach;
  inherited;
end;

procedure TEmbeddableForm.Detach;
begin
  EmbeddableControl.Parent := FOriginalParent;
  OriginalParent := nil;
end;

procedure TEmbeddableForm.SetOriginalParent(const Value: TWinControl);
begin
  if Assigned(FOriginalParent) then
    FOriginalParent.RemoveFreeNotification(Self);

  FOriginalParent := Value;

  if Assigned(FOriginalParent) then
    FOriginalParent.FreeNotification(Self);
end;

procedure TEmbeddableForm.SignalChanges(Sender: TOjbect);
begin
  If Assigned(FOnChange) then
    FOnChange(Sender);
end;

procedure TEmbeddableForm.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (aComponent = OriginalParent) and (Operation = opRemove) then
  begin
    Detach;
  end;

  inherited;
end;


end.
