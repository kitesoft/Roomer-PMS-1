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
  StdCtrls, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit, sButton, Vcl.ExtCtrls, sPanel, Vcl.ComCtrls, dxCore,
  cxDateUtils, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  cxTextEdit, cxMaskEdit, cxDropDownEdit, cxCalendar

  ;

type
  TfrmHomedate = class(TForm)
    Panel2: TsPanel;
    dtHome: TcxDateEdit;
    sPanel1: TsPanel;
    Button2: TsButton;
    Button1: TsButton;
    procedure FormCreate(Sender : TObject);
    procedure Button2Click(Sender: TObject);
    procedure dtHomeKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Button1Click(Sender: TObject);
    procedure dtHomePropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: Boolean);
  private
    { Private declarations }
    FResult : boolean;
    FCanClose: Boolean;
    function Getdate: TDateTime;
    procedure SetDate(const Value: TDateTime);
  public
    function ShowWithPrePressedKey(const aChar: char): boolean;
    { Public declarations }
    property Date: TDateTime read Getdate write SetDate;
  end;

var
  frmHomedate : TfrmHomedate;

implementation

uses
  uMain, uAppGlobal, uDImages, uUtils;

{$R *.dfm}

procedure TfrmHomedate.Button1Click(Sender: TObject);
begin
  FResult := false;
end;

procedure TfrmHomedate.Button2Click(Sender: TObject);
begin
  Button2.SetFocus; // initiate loosefocus of dateedit control
  if FCanClose then
  begin
    FResult := True;
    Close;
  end;
end;

procedure TfrmHomedate.dtHomeKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
 if Key = VK_RETURN then
  begin
    Button2Click(Sender);
    Key := VK_NONAME;
  end;
end;

procedure TfrmHomedate.dtHomePropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
  var Error: Boolean);
begin
  FCanClose := not Error;
end;

procedure TfrmHomedate.FormCreate(Sender : TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  dtHome.Date := now;
  FCanClose := True;
end;

function TfrmHomedate.Getdate: TDateTime;
begin
  Result := dtHome.Date;
end;

procedure TfrmHomedate.SetDate(const Value: TDateTime);
begin
  dtHome.Date := Value;
end;

function TfrmHomedate.ShowWithPrePressedKey(const aChar: char): boolean;
begin
  // replace first char with prepressedkey
  if aChar <> #0 then
  begin
    dtHome.SetSelection(0, 1); // select char to replace
    dtHome.SelText := aChar;
    dtHome.SelStart := 1; // set cursor after first char
  end;
  ShowModal;
  Result := FResult;
end;

end.




