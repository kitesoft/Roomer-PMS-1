object fmdxSpreadSheetDesignWindow: TfmdxSpreadSheetDesignWindow
  Left = 402
  Top = 300
  BorderStyle = bsDialog
  Caption = 'SpreadSheet DesignWindow'
  ClientHeight = 280
  ClientWidth = 565
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object pgctrlMain: TcxPageControl
    Left = 12
    Top = 12
    Width = 541
    Height = 221
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 1
    OnChange = pgctrlMainChange
    ClientRectBottom = 220
    ClientRectLeft = 1
    ClientRectRight = 540
    ClientRectTop = 24
    object tshOptions: TcxTabSheet
      Caption = '&Options'
      object imgGrid: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image5: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 100
        Caption = '&Row AutoHeight'
        TabOrder = 2
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 150
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 19
        Width = 227
      end
      object lblPreview: TcxLabel
        Left = 246
        Top = 0
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 19
        Width = 227
      end
      object chbxSuppressSourceFormats: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 122
        Caption = '&Suppress source formats'
        TabOrder = 3
        Transparent = True
        OnClick = chbxOptionsViewChanged
        Width = 150
      end
      object chbxShowRowAndColumnHeadings: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Row and column headings'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOptionsViewChanged
        Width = 150
      end
      object chbxShowGridlines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Gridlines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxOptionsViewChanged
        Width = 150
      end
    end
    object tshColor: TcxTabSheet
      Caption = '&Color'
      object ccbxColor: TcxColorComboBox
        Left = 112
        Top = 32
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 1
        Width = 124
      end
      object stTransparent: TcxLabel
        Left = 22
        Top = 10
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 215
      end
      object stFixedTransparent: TcxLabel
        Left = 21
        Top = 57
        TabStop = False
        AutoSize = False
        Caption = ' Fixed Transparent '
        FocusControl = chbxFixedTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stFixedTransparentClick
        Height = 18
        Width = 216
      end
      object lblGridLinesColor: TcxLabel
        Left = 27
        Top = 127
        Caption = '&Grid lines color : '
        FocusControl = ccbxLineColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblFixedColor: TcxLabel
        Left = 27
        Top = 81
        Caption = 'F&ixed color : '
        FocusControl = ccbxFixedColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblColor: TcxLabel
        Left = 27
        Top = 33
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
        OnClick = lblColorClick
      end
      object cxLabel1: TcxLabel
        Left = 8
        Top = 108
        TabStop = False
        AutoSize = False
        FocusControl = chbxFixedTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stFixedTransparentClick
        Height = 10
        Width = 229
      end
      object chbxTransparent: TcxCheckBox
        Left = 8
        Top = 11
        Style.TransparentBorder = False
        TabOrder = 0
        Transparent = True
        OnClick = chbxFixedTransparentClick
        Width = 21
      end
      object chbxFixedTransparent: TcxCheckBox
        Tag = 1
        Left = 8
        Top = 58
        Style.TransparentBorder = False
        TabOrder = 2
        Transparent = True
        OnClick = chbxFixedTransparentClick
        Width = 21
      end
      object ccbxLineColor: TcxColorComboBox
        Tag = 2
        Left = 112
        Top = 125
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 4
        Width = 124
      end
      object ccbxFixedColor: TcxColorComboBox
        Tag = 1
        Left = 112
        Top = 79
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 124
      end
    end
    object tshFont: TcxTabSheet
      Caption = '&Font'
      object edFont: TcxTextEdit
        Left = 10
        Top = 40
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 1
        Width = 225
      end
      object edFixedFont: TcxTextEdit
        Left = 10
        Top = 98
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 3
        Width = 225
      end
      object btnFont: TcxButton
        Left = 10
        Top = 10
        Width = 110
        Height = 23
        Caption = 'Fo&nt...'
        TabOrder = 0
        OnClick = btnFixedFontClick
      end
      object btnFixedFont: TcxButton
        Tag = 1
        Left = 10
        Top = 68
        Width = 110
        Height = 23
        Caption = 'Fi&xed Font...'
        TabOrder = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = btnFixedFontClick
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = '&Behaviors'
      object Image3: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image1: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxFixedRowsOnEveryPage: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Fi&xed Rows On Every Page'
        TabOrder = 0
        Transparent = True
        OnClick = chbxFixedRowsOnEveryPageClick
        Width = 161
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 227
      end
      object lblOnEveryPage: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 227
      end
      object chbxOnlySelected: TcxCheckBox
        Left = 75
        Top = 100
        Caption = 'Only &selected cells'
        TabOrder = 3
        Transparent = True
        OnClick = chbxOnlySelectedClick
        Width = 150
      end
    end
  end
  object pnlPreview: TPanel
    Left = 260
    Top = 54
    Width = 282
    Height = 168
    BevelOuter = bvLowered
    Color = clWindow
    TabOrder = 0
  end
end
