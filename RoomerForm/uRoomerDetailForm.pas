unit uRoomerDetailForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs
  , uRoomerForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter,
  cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, dxStatusBar, Vcl.StdCtrls,
  sButton, System.Actions, Vcl.ActnList, Vcl.ExtCtrls, sPanel;

type

  TDetailFormMode = (fmDisplay, fmInsert, fmEdit, fmDelete);

  /// <summary>
  ///   Basic form to be used for displaying detail data, editable or not. <br />
  ///  Creation should be initiated by using the TRoomerDetailFormFactory
  /// </summary>
  TfrmBaseRoomerDetailForm = class(TfrmBaseRoomerForm)
    pnlButtons: TsPanel;
    acOK: TAction;
    acCancel: TAction;
    btnCancel: TsButton;
    btnOK: TsButton;
    pnlDetails: TsPanel;
    pnlActionButtons: TsPanel;
    procedure acOKExecute(Sender: TObject);
    procedure acCancelExecute(Sender: TObject);
  private
    FFormMode: TDetailFormMode;
  protected
    procedure UpdateControls; override;
  public
    constructor Create(aOwner: TComponent; aFormMode: TDetailFormMode); reintroduce;
  end;

  TfrmBaseRoomerDetailFormClass = class of TfrmBaseRoomerDetailForm;

  TRoomerDetailFormFactory = class
  public
    /// <summary>
    ///   Create and show an instance of form in the provided mode. <br />
    ///  Returns true if modalresult = OK
    /// </summary>
    class function ShowDetailModal(aClass: TfrmBaseRoomerDetailFormClass; aFormMode: TDetailFormMode): boolean;
  end;

implementation

{$R *.dfm}

uses
  RTTI
  ;


{ TRoomerDetailFormFactory }

class function TRoomerDetailFormFactory.ShowDetailModal(aClass: TfrmBaseRoomerDetailFormClass; aFormMode: TDetailFormMode): boolean;
begin
  Result := False;
  if assigned(aClass) then
    with aClass.Create(nil, aFormMode) do
    try
      Result := (ShowModal = mrOK)
    finally
      Free;
    end;
end;

procedure TfrmBaseRoomerDetailForm.acCancelExecute(Sender: TObject);
begin
  inherited;
  ModalResult := mrCancel;
  Close;
end;

procedure TfrmBaseRoomerDetailForm.acOKExecute(Sender: TObject);
begin
  inherited;
  ModalResult := mrOK;
  Close;
end;

constructor TfrmBaseRoomerDetailForm.Create(aOwner: TComponent; aFormMode: TDetailFormMode);
begin
  FFormMode := aFormMode;
  inherited Create(aOwner);
end;

procedure TfrmBaseRoomerDetailForm.UpdateControls;
var
  lType: TRttiType;
  lReadonly: boolean;
  lProp: TRttiProperty;
  i: integer;
begin
  inherited;
  acCancel.Visible := FFormMode <> fmDisplay;

  // TODO: Replace with a DuckTyping class
  lReadOnly := FFormmode in [fmDisplay, fmDelete];
  with TRttiContext.Create do
  try
    for i := 0 to pnlDetails.ComponentCount-1 do
    begin
      lType := GetType(pnlDetails.Components[i].ClassInfo);
      if assigned(lType) then
      begin
        lProp := lType.GetProperty('readonly');
        if assigned(lProp) and lProp.IsWritable then
          lProp.SetValue(pnlDetails.Components[i], lReadOnly);
      end;
    end;
  finally
    Free;
  end;

end;

end.
