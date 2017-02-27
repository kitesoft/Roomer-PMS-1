object dxChlbxReportLinkDesignWindow: TdxChlbxReportLinkDesignWindow
  Left = 335
  Top = 330
  BorderStyle = bsDialog
  Caption = 'dxCLbReportLinkDesigner'
  ClientHeight = 263
  ClientWidth = 560
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 536
    Height = 204
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 1
    OnChange = PageControl1Change
    ClientRectBottom = 203
    ClientRectLeft = 1
    ClientRectRight = 535
    ClientRectTop = 24
    object tshOptions: TcxTabSheet
      Caption = '&Options'
      object Image5: TImage
        Left = 10
        Top = 105
        Width = 48
        Height = 48
        Transparent = True
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
        Width = 148
      end
      object chbxFlatCheckMarks: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 100
        Caption = 'Flat Check &Marks'
        TabOrder = 2
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 148
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 144
        Caption = '&Row Auto Height'
        TabOrder = 4
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 148
      end
      object chbxShowBorders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 148
      end
      object chbxShowHorzLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Horizontal Lines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 148
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 241
      end
      object lblPreview: TcxLabel
        Left = 259
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
        Height = 19
        Width = 241
      end
    end
    object tshColor: TcxTabSheet
      Caption = '&Color'
      object cbxDrawMode: TcxImageComboBox
        Left = 88
        Top = 16
        Properties.Items = <>
        TabOrder = 0
        OnClick = cbxDrawModeClick
        Width = 162
      end
      object stTransparent: TcxLabel
        Left = 21
        Top = 45
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 230
      end
      object lblGridLinesColor: TcxLabel
        Left = 27
        Top = 144
        Caption = 'Grid Lines Color: '
        FocusControl = ccbxGridLineColor
        Transparent = True
      end
      object lblEvenColor: TcxLabel
        Left = 27
        Top = 97
        Caption = 'E&ven Color: '
        FocusControl = ccbxEvenColor
        Transparent = True
      end
      object lblDrawMode: TcxLabel
        Left = 9
        Top = 17
        Caption = 'Draw &Mode:'
        FocusControl = cbxDrawMode
        Transparent = True
      end
      object lblColor: TcxLabel
        Left = 27
        Top = 69
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
      end
      object cxLabel1: TcxLabel
        Left = 4
        Top = 124
        TabStop = False
        AutoSize = False
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 10
        Width = 247
      end
      object chbxTransparent: TcxCheckBox
        Left = 6
        Top = 44
        TabOrder = 1
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 2
        Left = 113
        Top = 142
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 4
        Width = 137
      end
      object ccbxEvenColor: TcxColorComboBox
        Tag = 1
        Left = 113
        Top = 95
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 137
      end
      object ccbxColor: TcxColorComboBox
        Left = 113
        Top = 67
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 137
      end
    end
    object tshFont: TcxTabSheet
      Caption = '&Fonts'
      ImageIndex = 2
      object pnlFont: TPanel
        Left = 0
        Top = 0
        Width = 534
        Height = 179
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
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
          Left = 10
          Top = 68
          Width = 85
          Height = 23
          Caption = 'E&ven Font ...'
          TabOrder = 2
          OnClick = btnFontClick
        end
        object edFont: TcxTextEdit
          Left = 10
          Top = 41
          TabStop = False
          Style.TransparentBorder = False
          TabOrder = 1
          Text = 'edFont'
          Width = 239
        end
        object edEvenFont: TcxTextEdit
          Left = 10
          Top = 99
          TabStop = False
          Style.TransparentBorder = False
          TabOrder = 3
          Text = 'edFont'
          Width = 239
        end
      end
    end
  end
  object pnlPreview: TPanel
    Left = 274
    Top = 53
    Width = 264
    Height = 151
    BevelInner = bvLowered
    BevelOuter = bvNone
    Color = clWindow
    ParentBackground = False
    TabOrder = 0
  end
end
