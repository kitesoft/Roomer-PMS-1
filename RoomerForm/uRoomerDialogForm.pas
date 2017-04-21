unit uRoomerDialogForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinsdxStatusBarPainter, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore,
  dxStatusBar, Vcl.ExtCtrls, sPanel, Vcl.StdCtrls, sButton, Vcl.ComCtrls, sStatusBar, acProgressBar,
  AdvSmoothProgressBar;

type
  TfrmBaseRoomerDialogForm = class(TfrmBaseRoomerForm)
    pnlButtons: TsPanel;
    btnOK: TsButton;
    btnCancel: TsButton;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

end.
