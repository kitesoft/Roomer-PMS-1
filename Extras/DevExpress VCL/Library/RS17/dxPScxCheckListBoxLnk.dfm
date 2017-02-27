object cxfmCheckListBoxDesignWindow: TcxfmCheckListBoxDesignWindow
  Left = 393
  Top = 324
  BorderStyle = bsDialog
  Caption = 'cxfmCheckListBoxDesignWindow'
  ClientHeight = 262
  ClientWidth = 561
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 537
    Height = 204
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 203
    ClientRectLeft = 1
    ClientRectRight = 536
    ClientRectTop = 24
    object tshOptions: TcxTabSheet
      Caption = '&Options'
      object Image5: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
      end
      object imgGrid: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 122
        Caption = 'AutoWidth'
        TabOrder = 3
        Transparent = True
        OnClick = chbxAutoWidthClick
        Width = 147
      end
      object chbxFlatCheckMarks: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 100
        Caption = 'Flat Check &Marks'
        TabOrder = 2
        Transparent = True
        OnClick = chbxOptionsClick
        Width = 147
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 144
        Caption = '&Row Auto Height'
        TabOrder = 4
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 147
      end
      object chbxShowBorders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOptionsClick
        Width = 147
      end
      object chbxShowHorzLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Horizontal Lines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxOptionsClick
        Width = 147
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 238
      end
      object lblPreview: TcxLabel
        Left = 257
        Top = 0
        TabStop = False
        Caption = 'Preview'
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
        Width = 238
      end
    end
    object tshColor: TcxTabSheet
      Caption = '&Color'
      object stTransparent: TcxLabel
        Left = 23
        Top = 42
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 225
      end
      object lblGridLinesColor: TcxLabel
        Left = 27
        Top = 139
        Caption = 'Grid Lines Color: '
        FocusControl = ccbxGridLineColor
        Transparent = True
      end
      object lblEvenColor: TcxLabel
        Left = 27
        Top = 94
        Caption = 'E&ven Color: '
        FocusControl = ccbxEvenColor
        Transparent = True
      end
      object lblDrawMode: TcxLabel
        Left = 10
        Top = 18
        Caption = 'Draw &Mode:'
        FocusControl = cbxDrawMode
        Transparent = True
      end
      object lblColor: TcxLabel
        Left = 27
        Top = 66
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
      end
      object cxLabel1: TcxLabel
        Left = 8
        Top = 121
        TabStop = False
        AutoSize = False
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 10
        Width = 240
      end
      object chbxTransparent: TcxCheckBox
        Left = 8
        Top = 41
        TabOrder = 1
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 2
        Left = 114
        Top = 138
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 4
        Width = 133
      end
      object ccbxEvenColor: TcxColorComboBox
        Tag = 1
        Left = 114
        Top = 92
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 133
      end
      object ccbxColor: TcxColorComboBox
        Left = 114
        Top = 64
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 133
      end
      object cbxDrawMode: TcxImageComboBox
        Left = 84
        Top = 18
        Properties.Items = <>
        Style.TransparentBorder = False
        TabOrder = 0
        OnClick = cbxDrawModeClick
        Width = 162
      end
    end
    object tshFont: TcxTabSheet
      Caption = '&Font'
      object edFont: TcxTextEdit
        Left = 10
        Top = 41
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 1
        Text = 'edFont'
        Width = 236
      end
      object edEvenFont: TcxTextEdit
        Left = 9
        Top = 99
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 3
        Text = 'edFont'
        Width = 237
      end
      object btnFont: TcxButton
        Left = 10
        Top = 10
        Width = 85
        Height = 23
        Caption = 'Fo&nt ...'
        TabOrder = 0
        OnClick = btnFontClick
      end
      object btnEvenFont: TcxButton
        Tag = 1
        Left = 9
        Top = 68
        Width = 85
        Height = 23
        Caption = 'E&ven Font ...'
        TabOrder = 2
        OnClick = btnFontClick
      end
    end
  end
  object pnlPreview: TPanel
    Left = 271
    Top = 54
    Width = 265
    Height = 150
    BevelOuter = bvLowered
    BorderWidth = 1
    Color = clWindow
    ParentBackground = False
    TabOrder = 1
  end
end
