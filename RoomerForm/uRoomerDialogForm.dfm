inherited frmBaseRoomerDialogForm: TfrmBaseRoomerDialogForm
  BorderStyle = bsDialog
  Caption = 'Base Roomer dialog form'
  ClientHeight = 360
  ClientWidth = 655
  ExplicitWidth = 661
  ExplicitHeight = 389
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 340
    Width = 655
    ExplicitTop = 340
    ExplicitWidth = 655
  end
  object pnlButtons: TsPanel [1]
    Left = 0
    Top = 297
    Width = 655
    Height = 43
    Align = alBottom
    Color = 14540253
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 4013373
    Font.Height = -9
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object btnOK: TsButton
      AlignWithMargins = True
      Left = 551
      Top = 4
      Width = 100
      Height = 35
      Align = alRight
      Caption = 'OK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4013373
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = []
      ModalResult = 1
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
    end
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
