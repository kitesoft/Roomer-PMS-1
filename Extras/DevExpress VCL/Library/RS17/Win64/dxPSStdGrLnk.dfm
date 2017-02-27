object dxGridReportLinkDesignWindow: TdxGridReportLinkDesignWindow
  Left = 422
  Top = 253
  BorderStyle = bsDialog
  Caption = 'dxGridReportLinkDesigner'
  ClientHeight = 333
  ClientWidth = 600
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 576
    Height = 274
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 273
    ClientRectLeft = 1
    ClientRectRight = 575
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
      object Image1: TImage
        Left = 10
        Top = 157
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxFixedRowsOnEveryPage: TcxCheckBox
        Left = 75
        Top = 156
        Caption = 'Fi&xed Rows'
        TabOrder = 5
        Transparent = True
        OnClick = chbxFixedRowsOnEveryPageClick
        Width = 161
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 246
      end
      object lblPreview: TcxLabel
        Left = 264
        Top = 0
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
      object lblOnEveryPage: TcxLabel
        Left = 10
        Top = 137
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 246
      end
      object chbxShowVertLines: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 71
        Caption = 'Vertical Lines'
        TabOrder = 2
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 161
      end
      object chbxShowHorzLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Horizontal Lines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 161
      end
      object chbxShowFixedVertLines: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 115
        Caption = 'Fixed &Vertical Lines'
        TabOrder = 4
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 161
      end
      object chbxShowFixedHorzLines: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 93
        Caption = 'Fixed &Horizontal Lines'
        TabOrder = 3
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 161
      end
      object chbxShowBorders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 161
      end
    end
    object tshColor: TcxTabSheet
      Caption = '&Color'
      object cbxDrawMode: TcxImageComboBox
        Left = 76
        Top = 18
        Properties.Items = <>
        Style.TransparentBorder = False
        TabOrder = 0
        OnClick = cbxDrawModeClick
        Width = 177
      end
      object stTransparent: TcxLabel
        Left = 20
        Top = 42
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 234
      end
      object stFixedTransparent: TcxLabel
        Left = 20
        Top = 115
        TabStop = False
        AutoSize = False
        Caption = ' Fixed T&ransparent '
        FocusControl = chbxFixedTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stFixedTransparentClick
        Height = 18
        Width = 234
      end
      object lblGridLineSeparator: TcxLabel
        Left = 8
        Top = 162
        TabStop = False
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stFixedTransparentClick
        Height = 18
        Width = 246
      end
      object lblGridLinesColor: TcxLabel
        Left = 28
        Top = 186
        Caption = '&Grid lines color : '
        FocusControl = ccbxGridLineColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblFixedColor: TcxLabel
        Left = 28
        Top = 139
        Caption = 'F&ixed color : '
        FocusControl = ccbxFixedColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblEvenColor: TcxLabel
        Left = 28
        Top = 91
        Caption = 'E&ven Color: '
        FocusControl = ccbxEvenColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblDrawMode: TcxLabel
        Left = 9
        Top = 18
        Caption = 'Draw &Mode:'
        FocusControl = cbxDrawMode
        Transparent = True
        OnClick = lblColorClick
      end
      object lblColor: TcxLabel
        Left = 28
        Top = 65
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
        OnClick = lblColorClick
      end
      object chbxTransparent: TcxCheckBox
        Left = 5
        Top = 41
        TabOrder = 1
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object chbxFixedTransparent: TcxCheckBox
        Tag = 1
        Left = 5
        Top = 114
        TabOrder = 4
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 3
        Left = 114
        Top = 184
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 6
        Width = 139
      end
      object ccbxFixedColor: TcxColorComboBox
        Tag = 2
        Left = 114
        Top = 137
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 5
        Width = 139
      end
      object ccbxEvenColor: TcxColorComboBox
        Tag = 1
        Left = 114
        Top = 90
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 139
      end
      object ccbxColor: TcxColorComboBox
        Left = 114
        Top = 63
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 139
      end
    end
    object tshFont: TcxTabSheet
      Caption = '&Font'
      object btnFixedFont: TcxButton
        Tag = 2
        Left = 10
        Top = 126
        Width = 85
        Height = 23
        Caption = 'Fi&xed Font ...'
        TabOrder = 4
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = btnFontClick
      end
      object edFont: TcxTextEdit
        Left = 10
        Top = 40
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 1
        Width = 242
      end
      object edFixedFont: TcxTextEdit
        Left = 10
        Top = 156
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 5
        Width = 242
      end
      object edEvenFont: TcxTextEdit
        Left = 10
        Top = 98
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 3
        Width = 242
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
        Left = 10
        Top = 68
        Width = 85
        Height = 23
        Caption = 'E&ven Font ...'
        TabOrder = 2
        OnClick = btnFontClick
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = '&Behaviors'
      object imgMiscellaneous: TImage
        Left = 10
        Top = 177
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image8: TImage
        Left = 10
        Top = 104
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image3: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 175
        Caption = 'AutoWidth'
        TabOrder = 4
        Transparent = True
        OnClick = chbxAutoWidthClick
        Width = 161
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 244
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 158
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 244
      end
      object lblLookAndFeel: TcxLabel
        Left = 10
        Top = 84
        AutoSize = False
        Caption = 'Look And Feel'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 244
      end
      object chbxUseSoft3D: TcxCheckBox
        Tag = 13
        Left = 75
        Top = 123
        Caption = 'Soft &3D'
        TabOrder = 3
        Transparent = True
        OnClick = chbxUseSoft3DClick
        Width = 161
      end
      object chbxUse3DEffects: TcxCheckBox
        Tag = 12
        Left = 75
        Top = 101
        Caption = '&Use 3D Effects'
        TabOrder = 2
        Transparent = True
        OnClick = chbxUse3DEffectsClick
        Width = 161
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 197
        Caption = '&Row Auto Height'
        TabOrder = 5
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 161
      end
      object chbxOnlySelected: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Only &selected cells'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOnlySelectedClick
        Width = 161
      end
      object chbxIncludeFixed: TcxCheckBox
        Left = 75
        Top = 49
        Caption = '&Including fixed cells'
        TabOrder = 1
        Transparent = True
        OnClick = chbxIncludeFixedClick
        Width = 161
      end
    end
  end
  object pnlPreview: TPanel
    Left = 277
    Top = 54
    Width = 298
    Height = 218
    BevelInner = bvLowered
    BevelOuter = bvNone
    Color = clWindow
    TabOrder = 1
  end
end
