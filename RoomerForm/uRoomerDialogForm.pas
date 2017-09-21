unit uRoomerDialogForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinsdxStatusBarPainter, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore,
  dxStatusBar, Vcl.ExtCtrls, sPanel, Vcl.StdCtrls, sButton, Vcl.ComCtrls, sStatusBar, acProgressBar,
  AdvSmoothProgressBar
  , Generics.Collections

  ;

type
  /// <summary>
  ///   Dialog implementation of ROomerBaseForm
  ///  The available buttons can be set with the DialogButons property
  /// </summary>
  TfrmBaseRoomerDialogForm = class(TfrmBaseRoomerForm)
    pnlButtons: TsPanel;
    btnOK: TsButton;
    btnCancel: TsButton;
    btnClose: TsButton;
    procedure btnCloseClick(Sender: TObject);
  private
    FDialogButtons: TMsgDlgButtons;
    FOrderedButtonList: TList<TButton>;
    procedure SetDialogButtons(const Value: TMsgDlgButtons);
    procedure CorrectButtonDisplayOrder;
    procedure FillButtonList;
    procedure UpdateDialogButtons;
    { Private declarations }
  protected
    procedure DoShow; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    { Public declarations }
    property DialogButtons: TMsgDlgButtons read FDialogButtons write SetDialogButtons;
  end;

implementation

{$R *.dfm}

uses
  Generics.Defaults
  ;

type
  TButtonTabOrderComparer = TComparer<TButton>;

{ TfrmBaseRoomerDialogForm }

procedure TfrmBaseRoomerDialogForm.btnCloseClick(Sender: TObject);
begin
  inherited;
  Close;
end;

procedure TfrmBaseRoomerDialogForm.CorrectButtonDisplayOrder;
var
  b: TButton;
begin
  for b in FOrderedButtonList do
    b.Left := 0;
end;

constructor TfrmBaseRoomerDialogForm.Create(aOwner: TComponent);
begin
  inherited;
  FOrderedButtonList := TList<TButton>.Create;
  DialogButtons := mbOkCancel;
end;

destructor TfrmBaseRoomerDialogForm.Destroy;
begin
  FOrderedButtonList.Free;
  inherited;
end;

procedure TfrmBaseRoomerDialogForm.DoShow;
begin
  FillButtonList;
  inherited;
  RefreshData;
end;

procedure TfrmBaseRoomerDialogForm.FillButtonList;
var
  i: integer;
begin
  FOrderedButtonList.Clear;
  for i := 0 to pnlButtons.ControlCount-1 do
    if pnlButtons.Controls[i] is TButton then
      FOrderedButtonList.Add(TButton(pnlButtons.Controls[i]));

  // Sort in reverse order
  FOrderedButtonList.Sort(TButtonTabOrderComparer.Construct(
              function (const L, R: TButton): integer
              begin
                result := R.TabOrder - L.TabOrder;
              end
            ));
end;


procedure TfrmBaseRoomerDialogForm.UpdateDialogButtons;
var
  b: TButton;
begin
  if (FDialogButtons <> []) then
  begin
    pnlButtons.Visible := true;
    for b in FOrderedButtonList do
      b.Visible := (b.Tag = 0) or (TMsgDlgBtn(b.Tag) in FDialogButtons);

    CorrectButtonDisplayOrder;
  end
  else
    pnlButtons.Visible := false;
end;

procedure TfrmBaseRoomerDialogForm.SetDialogButtons(const Value: TMsgDlgButtons);
begin
  FDialogButtons := Value;
  UpdateDialogButtons;
end;

end.
