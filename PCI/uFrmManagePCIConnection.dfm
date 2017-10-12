inherited FrmManagePCIConnection: TFrmManagePCIConnection
  Caption = 'Manage Paycard Connection'
  ClientHeight = 450
  ClientWidth = 780
  OnDestroy = FormDestroy
  ExplicitWidth = 786
  ExplicitHeight = 479
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 430
    Width = 780
    ExplicitTop = 430
    ExplicitWidth = 780
  end
  inherited pnlButtons: TsPanel
    Top = 387
    Width = 780
    TabOrder = 0
    ExplicitTop = 387
    ExplicitWidth = 780
    inherited btnOK: TsButton
      Left = 464
      OnClick = btnOKClick
      ExplicitLeft = 464
    end
    inherited btnCancel: TsButton
      Left = 570
      ExplicitLeft = 570
    end
    inherited btnClose: TsButton
      Left = 676
      ExplicitLeft = 676
    end
  end
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 780
    Height = 57
    Align = alTop
    TabOrder = 2
    object cbxIsActive: TsCheckBox
      AlignWithMargins = True
      Left = 21
      Top = 19
      Width = 755
      Height = 17
      Margins.Left = 20
      Margins.Top = 18
      Margins.Bottom = 10
      Caption = '<auto>'
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      ImgChecked = 0
      ImgUnchecked = 0
      ReadOnly = True
    end
  end
  object pnlLeft: TsPanel [3]
    Left = 0
    Top = 89
    Width = 401
    Height = 298
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
    object __lblVISA: TsLabel
      Left = 147
      Top = 47
      Width = 30
      Height = 13
      Alignment = taRightJustify
      Caption = 'VISA:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbAMEX: TsLabel
      Left = 143
      Top = 74
      Width = 34
      Height = 13
      Alignment = taRightJustify
      Caption = 'AMEX:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbBC: TsLabel
      Left = 160
      Top = 101
      Width = 17
      Height = 13
      Alignment = taRightJustify
      Caption = 'BC:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbMastercard: TsLabel
      Left = 109
      Top = 128
      Width = 68
      Height = 13
      Alignment = taRightJustify
      Caption = 'Mastercard:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbMC_Alaska: TsLabel
      Left = 112
      Top = 155
      Width = 65
      Height = 13
      Alignment = taRightJustify
      Caption = 'MC_Alaska:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbMC_Canada: TsLabel
      Left = 108
      Top = 182
      Width = 69
      Height = 13
      Alignment = taRightJustify
      Caption = 'MC_Canada:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbUnionPay: TsLabel
      Left = 121
      Top = 209
      Width = 56
      Height = 13
      Alignment = taRightJustify
      Caption = 'UnionPay:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbDiscover: TsLabel
      Left = 125
      Top = 236
      Width = 52
      Height = 13
      Alignment = taRightJustify
      Caption = 'Discover:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbDinersclub: TsLabel
      Left = 25
      Top = 263
      Width = 152
      Height = 13
      Alignment = taRightJustify
      Caption = 'Dinersclub && CarteBlanche:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object lbOtherCards: TsLabel
      Left = 83
      Top = 13
      Width = 94
      Height = 13
      Alignment = taRightJustify
      Caption = 'Default paytype:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object shpDefaultPaytypeEmpty: TShape
      Tag = 12
      Left = 382
      Top = 13
      Width = 16
      Height = 17
      Brush.Color = clRed
      Pen.Color = clRed
      Shape = stCircle
      Visible = False
    end
    object cbVISA: TsComboBox
      Tag = 1
      AlignWithMargins = True
      Left = 190
      Top = 44
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Top = 10
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbAMEX: TsComboBox
      Tag = 2
      AlignWithMargins = True
      Left = 190
      Top = 71
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 2
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbBC: TsComboBox
      Tag = 3
      AlignWithMargins = True
      Left = 190
      Top = 98
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 3
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbMastercard: TsComboBox
      Tag = 4
      AlignWithMargins = True
      Left = 190
      Top = 125
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 4
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbMC_Alaska: TsComboBox
      Tag = 5
      AlignWithMargins = True
      Left = 190
      Top = 152
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbMC_Canada: TsComboBox
      Tag = 6
      AlignWithMargins = True
      Left = 190
      Top = 179
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 6
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbUnionPay: TsComboBox
      Tag = 7
      AlignWithMargins = True
      Left = 190
      Top = 206
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 7
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbDiscover: TsComboBox
      Tag = 8
      AlignWithMargins = True
      Left = 190
      Top = 233
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 8
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbDincersclub: TsComboBox
      Tag = 9
      AlignWithMargins = True
      Left = 190
      Top = 260
      Width = 186
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 190
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 9
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
    object cbDefault: TsComboBox
      AlignWithMargins = True
      Left = 190
      Top = 10
      Width = 186
      Height = 21
      Margins.Left = 190
      Margins.Top = 10
      Margins.Right = 25
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = '< SELECT >'
      OnChange = cbChange
      Items.Strings = (
        '< SELECT >')
    end
  end
  object pnlRight: TsPanel [4]
    Left = 401
    Top = 89
    Width = 379
    Height = 298
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object __lbCartaSi: TsLabel
      Left = 100
      Top = 14
      Width = 44
      Height = 13
      Alignment = taRightJustify
      Caption = 'CartaSi:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbCarteBleue: TsLabel
      Left = 79
      Top = 41
      Width = 65
      Height = 13
      Alignment = taRightJustify
      Caption = 'CarteBleue:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbDankort: TsLabel
      Left = 95
      Top = 68
      Width = 49
      Height = 13
      Alignment = taRightJustify
      Caption = 'Dankort:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbDelta: TsLabel
      Left = 111
      Top = 95
      Width = 33
      Height = 13
      Alignment = taRightJustify
      Caption = 'Delta:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbElectron: TsLabel
      Left = 95
      Top = 122
      Width = 49
      Height = 13
      Alignment = taRightJustify
      Caption = 'Electron:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbJCB: TsLabel
      Left = 121
      Top = 149
      Width = 23
      Height = 13
      Alignment = taRightJustify
      Caption = 'JCB:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbMaestro: TsLabel
      Left = 94
      Top = 176
      Width = 50
      Height = 13
      Alignment = taRightJustify
      Caption = 'Maestro:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbSwitch: TsLabel
      Left = 104
      Top = 203
      Width = 40
      Height = 13
      Alignment = taRightJustify
      Caption = 'Switch:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object __lbSolo: TsLabel
      Left = 117
      Top = 230
      Width = 27
      Height = 13
      Alignment = taRightJustify
      Caption = 'Solo:'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cbCartaSi: TsComboBox
      Tag = 10
      AlignWithMargins = True
      Left = 159
      Top = 10
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Top = 10
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbCarteBleue: TsComboBox
      Tag = 11
      AlignWithMargins = True
      Left = 159
      Top = 37
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbDankort: TsComboBox
      Tag = 12
      AlignWithMargins = True
      Left = 159
      Top = 64
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 2
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbDelta: TsComboBox
      Tag = 13
      AlignWithMargins = True
      Left = 159
      Top = 91
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 3
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbElectron: TsComboBox
      Tag = 14
      AlignWithMargins = True
      Left = 159
      Top = 118
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 4
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbJCB: TsComboBox
      Tag = 15
      AlignWithMargins = True
      Left = 159
      Top = 145
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbMaestro: TsComboBox
      Tag = 16
      AlignWithMargins = True
      Left = 159
      Top = 172
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 6
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbSwitch: TsComboBox
      Tag = 17
      AlignWithMargins = True
      Left = 159
      Top = 199
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 7
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
    object cbSolo: TsComboBox
      Tag = 18
      AlignWithMargins = True
      Left = 159
      Top = 226
      Width = 210
      Height = 21
      Hint = 'Press Del to clear'
      Margins.Left = 159
      Margins.Right = 10
      Align = alTop
      Alignment = taLeftJustify
      VerticalAlignment = taAlignTop
      Style = csDropDownList
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 8
      Text = '< SELECT >'
      OnChange = cbChange
      OnKeyUp = cbKeyUp
      Items.Strings = (
        '< SELECT >')
    end
  end
  object pnlMapCaption: TsPanel [5]
    Left = 0
    Top = 57
    Width = 780
    Height = 32
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 5
    object sLabel1: TsLabel
      AlignWithMargins = True
      Left = 20
      Top = 3
      Width = 197
      Height = 26
      Margins.Left = 20
      Align = alLeft
      Caption = 'Map Creditcard types to PayTypes:'
      ParentFont = False
      Layout = tlCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ExplicitHeight = 13
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 712
    Top = 0
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 640
    Top = 8
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
