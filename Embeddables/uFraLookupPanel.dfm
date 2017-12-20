object fraLookupPanel: TfraLookupPanel
  Left = 0
  Top = 0
  Width = 250
  Height = 20
  TabOrder = 0
  object pnlLookup: TsPanel
    Left = 0
    Top = 0
    Width = 250
    Height = 20
    Margins.Left = 0
    Margins.Top = 1
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    StyleElements = [seFont, seClient]
    SkinData.SkinSection = 'PANEL'
    object lblDescription: TLabel
      AlignWithMargins = True
      Left = 93
      Top = 0
      Width = 157
      Height = 20
      Margins.Left = 6
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alClient
      Caption = '-'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
      Layout = tlCenter
      ExplicitLeft = 91
      ExplicitWidth = 4
      ExplicitHeight = 13
    end
    object edCode: TsEdit
      AlignWithMargins = True
      Left = 0
      Top = 0
      Width = 60
      Height = 20
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alLeft
      CharCase = ecUpperCase
      Constraints.MaxWidth = 140
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      MaxLength = -1
      ParentFont = False
      TabOrder = 0
      OnChange = edCodeChange
      OnDblClick = edCodeDblClick
      OnKeyUp = edCodeKeyUp
      SkinData.SkinSection = 'EDIT'
      BoundLabel.Font.Charset = DEFAULT_CHARSET
      BoundLabel.Font.Color = clWindowText
      BoundLabel.Font.Height = -13
      BoundLabel.Font.Name = 'Tahoma'
      BoundLabel.Font.Style = []
      ExplicitHeight = 22
    end
    object btnSelect: TsButton
      AlignWithMargins = True
      Left = 63
      Top = 0
      Width = 21
      Height = 20
      Margins.Top = 0
      Margins.Bottom = 0
      Align = alLeft
      Caption = '...'
      TabOrder = 1
      OnClick = btnSelectClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
end
