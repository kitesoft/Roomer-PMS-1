inherited fraCustomerPanel: TfraCustomerPanel
  inherited pnlLookup: TsPanel
    Align = alClient
    inherited lblDescription: TsLabel
      Left = 126
      ExplicitLeft = 126
    end
    object btnLast: TsButton
      AlignWithMargins = True
      Left = 87
      Top = 0
      Width = 30
      Height = 20
      Hint = 'Load customer from last reservation'
      Margins.Left = 0
      Margins.Top = 0
      Margins.Bottom = 0
      Align = alLeft
      Caption = 'Last'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = btnLastClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
end
