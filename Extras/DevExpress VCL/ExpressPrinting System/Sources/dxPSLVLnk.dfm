object dxfmLVReportLinkDesignWindow: TdxfmLVReportLinkDesignWindow
  Left = 316
  Top = 170
  BorderStyle = bsDialog
  Caption = 'dxfmLVReportLinkDesignWindow'
  ClientHeight = 372
  ClientWidth = 555
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 45
    Width = 531
    Height = 281
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 280
    ClientRectLeft = 1
    ClientRectRight = 530
    ClientRectTop = 24
    object tshOptions: TcxTabSheet
      Caption = 'Options'
      object imgGrid: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image1: TImage
        Left = 10
        Top = 151
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 224
      end
      object lblPreview: TcxLabel
        Left = 244
        Top = 1
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
      object lblOnEveryPage: TcxLabel
        Left = 10
        Top = 131
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 224
      end
      object chbxShowVertLines: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 71
        Caption = 'Vertical Lines'
        TabOrder = 2
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 143
      end
      object chbxShowHorzLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Horizontal Lines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 143
      end
      object chbxShowColumnHeaders: TcxCheckBox
        Left = 75
        Top = 108
        Caption = '&Column Headers'
        TabOrder = 3
        Transparent = True
        OnClick = chbxShowColumnHeadersClick
        Width = 143
      end
      object chbxShowBorders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 143
      end
      object chbxHeadersOnEveryPage: TcxCheckBox
        Left = 75
        Top = 149
        Caption = 'Headers'
        TabOrder = 4
        Transparent = True
        OnClick = chbxHeadersOnEveryPageClick
        Width = 143
      end
      object Bevel1: TcxLabel
        Left = 68
        Top = 95
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 166
      end
    end
    object tshColor: TcxTabSheet
      Caption = 'Color'
      object stTransparentHeaders: TcxLabel
        Left = 23
        Top = 117
        TabStop = False
        AutoSize = False
        Caption = ' Transaprent Headers '
        FocusControl = chbxTransparentHeaders
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentHeadersClick
        Height = 18
        Width = 211
      end
      object stTransparent: TcxLabel
        Left = 23
        Top = 42
        TabStop = False
        AutoSize = False
        Caption = ' Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 19
        Width = 211
      end
      object lblGridLinesColor: TcxLabel
        Left = 31
        Top = 188
        Caption = '&Grid Lines Color: '
        FocusControl = ccbxGridLineColor
        Transparent = True
      end
      object lblDrawMode: TcxLabel
        Left = 10
        Top = 18
        Caption = 'Draw &Mode:'
        FocusControl = cbxDrawMode
        Transparent = True
      end
      object chbxTransparentHeaders: TcxCheckBox
        Tag = 1
        Left = 8
        Top = 116
        TabOrder = 4
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object chbxTransparent: TcxCheckBox
        Left = 8
        Top = 41
        TabOrder = 1
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object lblColor: TcxLabel
        Left = 30
        Top = 66
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
      end
      object lblEvenColor: TcxLabel
        Left = 30
        Top = 92
        Caption = 'E&ven Color: '
        FocusControl = ccbxEvenColor
        Transparent = True
      end
      object lblHeadersColor: TcxLabel
        Left = 31
        Top = 141
        Caption = 'Headers Color: '
        FocusControl = ccbxHeadersColor
        Transparent = True
      end
      object ccbxColor: TcxColorComboBox
        Left = 115
        Top = 64
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 118
      end
      object ccbxEvenColor: TcxColorComboBox
        Tag = 1
        Left = 115
        Top = 91
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 118
      end
      object ccbxHeadersColor: TcxColorComboBox
        Tag = 2
        Left = 115
        Top = 140
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 5
        Width = 118
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 3
        Left = 115
        Top = 187
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 6
        Width = 118
      end
      object cxLabel1: TcxLabel
        Left = 8
        Top = 165
        TabStop = False
        AutoSize = False
        FocusControl = chbxTransparentHeaders
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentHeadersClick
        Height = 18
        Width = 226
      end
      object cbxDrawMode: TcxImageComboBox
        Left = 80
        Top = 18
        Properties.Items = <>
        Style.TransparentBorder = False
        TabOrder = 0
        OnClick = cbxDrawModeClick
        Width = 152
      end
    end
    object tshFont: TcxTabSheet
      Caption = 'Font'
      object edFont: TcxTextEdit
        Left = 10
        Top = 41
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 1
        Width = 222
      end
      object edFixedFont: TcxTextEdit
        Left = 10
        Top = 157
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 5
        Width = 222
      end
      object edEvenFont: TcxTextEdit
        Left = 10
        Top = 99
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 3
        Width = 222
      end
      object btnHeadersFont: TcxButton
        Tag = 2
        Left = 10
        Top = 126
        Width = 110
        Height = 23
        Caption = 'Headers Font...'
        TabOrder = 4
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = btnFontClick
      end
      object btnFont: TcxButton
        Left = 10
        Top = 10
        Width = 110
        Height = 23
        Caption = 'Fo&nt...'
        TabOrder = 0
        OnClick = btnFontClick
      end
      object btnEvenFont: TcxButton
        Tag = 1
        Left = 10
        Top = 68
        Width = 110
        Height = 23
        Caption = 'E&ven Font...'
        TabOrder = 2
        OnClick = btnFontClick
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = 'Behaviors'
      object Image8: TImage
        Left = 10
        Top = 100
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image5: TImage
        Left = 10
        Top = 172
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image3: TImage
        Left = 10
        Top = 29
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 224
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 150
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 224
      end
      object lblLookAndFeel: TcxLabel
        Left = 10
        Top = 80
        AutoSize = False
        Caption = 'Look And Feel'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 224
      end
      object chbxUseSoft3D: TcxCheckBox
        Tag = 13
        Left = 75
        Top = 119
        Caption = 'Soft &3D'
        TabOrder = 3
        Transparent = True
        OnClick = chbxUseSoft3DClick
        Width = 143
      end
      object chbxUse3DEffects: TcxCheckBox
        Tag = 12
        Left = 75
        Top = 97
        Caption = '&Use 3D Effects'
        TabOrder = 2
        Transparent = True
        OnClick = chbxUse3DEffectsClick
        Width = 143
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 189
        Caption = '&Row Auto Height'
        TabOrder = 5
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 136
      end
      object chbxOnlySelected: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Only &selected cells'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOnlySelectedClick
        Width = 143
      end
      object chbxIncludeFixed: TcxCheckBox
        Left = 75
        Top = 49
        Caption = '&Including fixed cells'
        TabOrder = 1
        Transparent = True
        OnClick = chbxIncludeFixedClick
        Width = 143
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 167
        Caption = 'AutoWidth'
        TabOrder = 4
        Transparent = True
        OnClick = chbxAutoWidthClick
        Width = 136
      end
    end
  end
  object pnlPreview: TPanel
    Left = 257
    Top = 87
    Width = 275
    Height = 228
    BevelOuter = bvLowered
    Color = clWindow
    TabOrder = 1
  end
  object pnlHint: TPanel
    Left = 12
    Top = 12
    Width = 531
    Height = 27
    Alignment = taLeftJustify
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Color = clInfoBk
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 2
    object imgHint: TImage
      Left = 7
      Top = 5
      Width = 16
      Height = 16
      Picture.Data = {
        055449636F6E0000010001001010000001002000680400001600000028000000
        1000000020000000010020000000000040040000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000010000000B0000001A00000021000000230000002500000027
        000000290000002B0000002C0000002E0000002F000000310000002900000012
        0000000300000008034D7D620471B8FF056DB6FF056CB4FF0469B1FF0468B0FF
        0566ACFF0563AAFF0562A8FF0461A7FF045EA4FF055CA3FF045BA2FF0231557D
        000000100000000F056CADCE8FD0EBFF37D2F5FF01C2F0FF01BFEEFF01BAECFF
        01B6ECFF5DCEF1FF5DCBF0FF01A9E5FF01A6E3FF01A3E3FF0290D3FF04508CE0
        0000001F0000000D046FAFC88AD1EDFF9BEFFEFF03D3FBFF00CFF9FF00CAF8FF
        003845FF1D3D46FF66D7F6FF00B8F0FF00B3EDFF00ACEAFF0491D2FF034E8AD9
        0000001D00000005034F7C4B2791CCFDBDF4FEFF47E1FDFF00D3FBFF00CEF9FF
        00303BFF08313BFF20C9F5FF00BCF1FF00B7F0FF00B0EBFF1172B5FE022B4B6A
        0000000C000000010000000D036FAEB57BC9E8FFABF2FFFF04D6FDFF00D2FBFF
        02A1C5FF2AA7C6FF36D1F7FF00C1F4FF00BCF2FF0495D3FF03528BC90000001E
        00000002000000000000000302466D31188AC8FBBBF3FEFF5BE6FEFF01D5FCFF
        02809DFF2D87A0FF4BD9FAFF01C5F6FF00BBF0FF0E75B7FC0228434F00000008
        000000000000000000000000000000090370AC9B67BEE4FFB2F4FFFF0DDBFEFF
        026277FF2A6677FF60E1FBFF01CAF8FF0A9AD5FF03558CB10000001600000001
        00000000000000000000000000000002024265241288C8F2B2EEFBFF68EAFFFF
        013C48FF1F404BFF76E7FDFF01C3F2FF0B77BAF501243B380000000600000000
        00000000000000000000000000000000000000070372AE875AB7E1FFBBF5FFFF
        02151AFF09181CFF64E5FDFF0D9FD7FF035C92970000000F0000000100000000
        000000000000000000000000000000000000000101293D140885C6E8A9E9F9FF
        1C3539FF00333BFF01C8F3FF0779BCEA01162221000000030000000000000000
        0000000000000000000000000000000000000000000000040374AE6A46AEDDFF
        BDF6FFFF25DEFEFF109ED7FF0361947600000009000000000000000000000000
        0000000000000000000000000000000000000000000000010120300D0687C8D6
        9CE1F5FF9CDFF3FF0780C0D901121B1600000002000000000000000000000000
        000000000000000000000000000000000000000000000000000000030377B051
        038ACEFF0389CCFF036A9F580000000600000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000003
        000000080000000A000000050000000100000000000000000000000000000000
        00000000FFFF0000000000000000000000000000000000000000000000000000
        80010000C0010000C0030000E0030000E0070000F00F0000F00F0000F81F0000
        FC1F0000}
      Transparent = True
    end
    object lblHint: TcxLabel
      Left = 30
      Top = 3
      Caption = ' Most Options Are Being Taken Into Account Only In Detailed View'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Transparent = True
    end
  end
end
