unit uHomeDate;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,

  _Glob, cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxContainer,
  cxEdit,
  cxCheckBox,
  StdCtrls, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit, sButton, Vcl.ExtCtrls, sPanel

  ;

type
  TfrmHomedate = class(TForm)
    Panel2: TsPanel;
    dtHome: TsDateEdit;
    sPanel1: TsPanel;
    btnOk: TsButton;
    btnCancel: TsButton;
    procedure FormCreate(Sender : TObject);
    procedure FormActivate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

function ShowHomeDateForm(aDate: TDate; Key: char = ' '): TDate;


implementation

uses
  uMain, uAppGlobal, uDImages, uUtils
  , uRoomerLanguage
  , uVCLUtils;

{$R *.dfm}

function ShowHomeDateForm(aDate: TDate; Key: Char = ' '): TDate;
var
  frm: TfrmHomedate;
begin
  Result := aDate;
  frm := TfrmHomedate.Create(nil);
  try
    with frm do
    begin
      frm.dtHome.Date := aDate;
      frm.Left := Application.MainForm.Left + 1;
      frm.Top := Application.MainForm.Top + 1;
      if Key in ['0' .. '9'] then
      begin
        dtHome.SelLength := 0;
        dtHome.SelStart := 0;
        dtHome.SelLength := 1;
        dtHome.SetSelText(Key);
        dtHome.SelLength := 0;
        dtHome.SelStart := 1;
      end;
      if ShowModal = mrOk then
        Result := dtHome.Date;
    end;
  finally
    frm.Free;
  end;

end;


procedure TfrmHomedate.FormActivate(Sender: TObject);
begin
  dtHome.SetFocus;
end;

procedure TfrmHomedate.FormCreate(Sender : TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  dtHome.Date := now;
  dthome.CheckOnExit := False;
end;

end.




