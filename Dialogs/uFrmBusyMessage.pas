unit uFrmBusyMessage;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, AdvSmoothWin8Marquee, Vcl.StdCtrls, sLabel, cxClasses, cxPropertiesStore, VrControls, VrThreads;

type
  TfrmBusyMessage = class(TForm)
    Marquee: TAdvSmoothWin8Marquee;
    __lblMessage: TsLabel;
    __lblHeadline: TsLabel;
    StoreMain: TcxPropertiesStore;
    procedure FormCreate(Sender: TObject);
  private
    procedure UpdateFromThreadViaQueue;
    { Private declarations }
  public
    { Public declarations }
    procedure ShowMessage(AHeadline, AMessage : String);
    procedure ChangeMessage(AMessage : String);
    procedure HideMessage;
  end;

var
  frmBusyMessage: TfrmBusyMessage;

implementation

{$R *.dfm}

uses uRoomerLanguage
     , uUtils
     ;

{ TfrmBusyMessage }

procedure TfrmBusyMessage.ChangeMessage(AMessage: String);
begin
  if NOT Visible then exit;

  __lblMessage.Caption := AMessage;
  __lblMessage.Update;
  Marquee.Update;
end;

procedure TfrmBusyMessage.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  PlaceFormOnVisibleMonitor(self);
end;

procedure TfrmBusyMessage.HideMessage;
begin
  Marquee.Animate := False;
  Hide;
end;

procedure TfrmBusyMessage.UpdateFromThreadViaQueue;
var
  i: integer;
begin
  while frmBusyMessage.Showing do
  begin
    Sleep(300);
    TThread.Queue(nil,
      procedure begin
        frmBusyMessage.Marquee.Step(10);
        frmBusyMessage.Marquee.Update;
        frmBusyMessage.Update;
      end);
  end;
end;

procedure TfrmBusyMessage.ShowMessage(AHeadline, AMessage: String);
begin
  Marquee.Animate := True;
  __lblHeadline.Caption := AHeadline;
  __lblMessage.Caption := AMessage;
  Show;
  __lblHeadline.Update;
  __lblMessage.Update;
  Marquee.Update;
  Update;
  TThread.CreateAnonymousThread(UpdateFromThreadViaQueue).Start;
end;

end.
