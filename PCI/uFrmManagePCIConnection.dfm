inherited FrmManagePCIConnection: TFrmManagePCIConnection
  BorderStyle = bsDialog
  Caption = 'Manage Paycard Connection'
  ClientHeight = 427
  ClientWidth = 766
  Font.Height = -11
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  ExplicitWidth = 772
  ExplicitHeight = 456
  PixelsPerInch = 96
  TextHeight = 13
  object __lblVISA: TsLabel [0]
    Left = 147
    Top = 79
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
  object __lbAMEX: TsLabel [1]
    Left = 143
    Top = 106
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
  object __lbBC: TsLabel [2]
    Left = 163
    Top = 133
    Width = 14
    Height = 13
    Alignment = taRightJustify
    Caption = 'BC'
    ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
  end
  object __lbMastercard: TsLabel [3]
    Left = 109
    Top = 159
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
  object __lbMC_Alaska: TsLabel [4]
    Left = 112
    Top = 186
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
  object __lbMC_Canada: TsLabel [5]
    Left = 108
    Top = 213
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
  object __lbUnionPay: TsLabel [6]
    Left = 121
    Top = 240
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
  object __lbDiscover: TsLabel [7]
    Left = 125
    Top = 266
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
  object __lbDinersclub: TsLabel [8]
    Left = 25
    Top = 293
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
  object __lbCartaSi: TsLabel [9]
    Left = 447
    Top = 79
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
  object __lbCarteBleue: TsLabel [10]
    Left = 426
    Top = 106
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
  object __lbDankort: TsLabel [11]
    Left = 442
    Top = 132
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
  object __lbDelta: TsLabel [12]
    Left = 458
    Top = 159
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
  object __lbElectron: TsLabel [13]
    Left = 442
    Top = 186
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
  object __lbJCB: TsLabel [14]
    Left = 468
    Top = 213
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
  object __lbMaestro: TsLabel [15]
    Left = 441
    Top = 239
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
  object __lbSwitch: TsLabel [16]
    Left = 451
    Top = 266
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
  object __lbSolo: TsLabel [17]
    Left = 464
    Top = 292
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
  inherited sbStatusBar: TsStatusBar
    Top = 407
    Width = 766
  end
  object cbxIsActive: TsCheckBox [19]
    Left = 8
    Top = 10
    Width = 322
    Height = 17
    Caption = 'Connection to payment provider has been activated'
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
  object sPanel1: TsPanel [20]
    Left = 0
    Top = 366
    Width = 766
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitLeft = 120
    ExplicitTop = 474
    object sButton1: TsButton
      AlignWithMargins = True
      Left = 666
      Top = 5
      Width = 95
      Height = 31
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Align = alRight
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
      OnClick = sButton1Click
      ExplicitLeft = 656
    end
  end
  object cbVISA: TsComboBox [21]
    Left = 194
    Top = 76
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbAMEX: TsComboBox [22]
    Left = 194
    Top = 103
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbBC: TsComboBox [23]
    Left = 194
    Top = 130
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbMastercard: TsComboBox [24]
    Left = 194
    Top = 156
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbMC_Alaska: TsComboBox [25]
    Left = 194
    Top = 183
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbMC_Canada: TsComboBox [26]
    Left = 194
    Top = 210
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbUnionPay: TsComboBox [27]
    Left = 194
    Top = 237
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
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
    Items.Strings = (
      '< SELECT >')
  end
  object cbDiscover: TsComboBox [28]
    Left = 194
    Top = 263
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 10
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbDincersclub: TsComboBox [29]
    Left = 194
    Top = 290
    Width = 169
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 11
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbCartaSi: TsComboBox [30]
    Left = 508
    Top = 76
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 12
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbCarteBleue: TsComboBox [31]
    Left = 508
    Top = 103
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 13
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbDankort: TsComboBox [32]
    Left = 508
    Top = 129
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 14
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbDelta: TsComboBox [33]
    Left = 508
    Top = 156
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 15
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbElectron: TsComboBox [34]
    Left = 508
    Top = 183
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 16
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbJCB: TsComboBox [35]
    Left = 508
    Top = 210
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 17
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbMaestro: TsComboBox [36]
    Left = 508
    Top = 236
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 18
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbSwitch: TsComboBox [37]
    Left = 508
    Top = 263
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 19
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  object cbSolo: TsComboBox [38]
    Left = 508
    Top = 289
    Width = 165
    Height = 21
    Alignment = taLeftJustify
    VerticalAlignment = taAlignTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 20
    Text = '< SELECT >'
    Items.Strings = (
      '< SELECT >')
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
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
