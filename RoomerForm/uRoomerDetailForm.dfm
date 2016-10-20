inherited frmBaseRoomerDetailForm: TfrmBaseRoomerDetailForm
  Caption = 'Base Roomer Detail form'
  ClientHeight = 483
  ClientWidth = 757
  Font.Height = -11
  ExplicitWidth = 773
  ExplicitHeight = 522
  PixelsPerInch = 96
  TextHeight = 13
  inherited dxStatusBar: TdxStatusBar
    Top = 463
    Width = 757
    ExplicitTop = 463
    ExplicitWidth = 757
  end
  object pnlButtons: TsPanel [1]
    Left = 0
    Top = 422
    Width = 757
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 626
      Top = 3
      Width = 128
      Height = 35
      Action = acCancel
      Align = alRight
      Cancel = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOK: TsButton
      AlignWithMargins = True
      Left = 492
      Top = 3
      Width = 128
      Height = 35
      Action = acOK
      Align = alRight
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object pnlDetails: TsPanel [2]
    Left = 0
    Top = 41
    Width = 757
    Height = 381
    Align = alClient
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
  end
  object pnlActionButtons: TsPanel [3]
    Left = 0
    Top = 0
    Width = 757
    Height = 41
    Align = alTop
    TabOrder = 0
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
  inherited alRoomerForm: TActionList
    object acOK: TAction
      Caption = 'OK'
      ImageIndex = 82
      OnExecute = acOKExecute
    end
    object acCancel: TAction
      Caption = 'Cancel'
      ImageIndex = 4
      OnExecute = acCancelExecute
    end
  end
end
