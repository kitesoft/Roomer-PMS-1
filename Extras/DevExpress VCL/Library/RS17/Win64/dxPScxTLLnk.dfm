object dxfmTreeListReportLinkDesignWindow: TdxfmTreeListReportLinkDesignWindow
  Left = 232
  Top = 184
  BorderStyle = bsDialog
  Caption = 'Property Sheets'
  ClientHeight = 410
  ClientWidth = 642
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 618
    Height = 353
    ActivePage = tshView
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 352
    ClientRectLeft = 1
    ClientRectRight = 617
    ClientRectTop = 24
    object tshView: TcxTabSheet
      Caption = 'View'
      object imgShow: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgOnEveryPage: TImage
        Left = 10
        Top = 186
        Width = 48
        Height = 48
        Transparent = True
      end
      object bvlWarningHost: TBevel
        Left = 10
        Top = 252
        Width = 288
        Height = 66
        Visible = False
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblOnEveryPage: TcxLabel
        Left = 10
        Top = 166
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object chbxShowBands: TcxCheckBox
        Left = 75
        Top = 26
        Caption = 'Ba&nds'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowHeaders: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 47
        Caption = '&Headers'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowFooters: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 68
        Caption = 'Foo&ters'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowExpandButtons: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 125
        Caption = 'Expand Buttons'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxBandsOnEveryPage: TcxCheckBox
        Left = 75
        Top = 183
        Caption = 'Ba&nds'
        TabOrder = 6
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxHeadersOnEveryPage: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 204
        Caption = 'Headers'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxFootersOnEveryPage: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 225
        Caption = 'Footers'
        TabOrder = 8
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxShowTreeLines: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 146
        Caption = 'TreeLines'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowBorders: TcxCheckBox
        Tag = 5
        Left = 75
        Top = 104
        Caption = 'Borders'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object Bevel2: TcxLabel
        Left = 75
        Top = 92
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 223
      end
      object lblPreviewWindow: TcxLabel
        Left = 307
        Top = 0
        TabStop = False
        AutoSize = False
        Caption = 'Preview'
        Transparent = True
        Height = 17
        Width = 46
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = 'Behaviors'
      ImageIndex = 1
      object imgSeparators: TImage
        Left = 10
        Top = 246
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgSelection: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgGridSize: TImage
        Left = 10
        Top = 174
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgExpanding: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
        Transparent = True
      end
      object seSeparatorThickness: TcxSpinEdit
        Left = 135
        Top = 247
        Properties.MaxValue = 16.000000000000000000
        Properties.OnChange = SeparatorThicknessChanged
        TabOrder = 5
        Width = 162
      end
      object lblSize: TcxLabel
        Left = 10
        Top = 154
        AutoSize = False
        Caption = 'Size'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblSeparatorsThickness: TcxLabel
        Left = 75
        Top = 248
        Caption = 'Thickness:'
        FocusControl = seSeparatorThickness
        Transparent = True
      end
      object lblSeparatorsColor: TcxLabel
        Left = 75
        Top = 276
        Caption = 'Color:'
        FocusControl = ccbxSeparatorColor
        Transparent = True
      end
      object lblSeparators: TcxLabel
        Left = 10
        Top = 226
        AutoSize = False
        Caption = 'Separators'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblExpanding: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Expanding'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object chbxProcessSelection: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Process Selection'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsSelectionClick
        Width = 205
      end
      object chbxProcessExactSelection: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Process Exact Selection'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsSelectionClick
        Width = 205
      end
      object chbxExplicitlyExpandNodes: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 122
        Caption = 'Explicitly Expand Nodes'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 205
      end
      object chbxExpandNodes: TcxCheckBox
        Left = 75
        Top = 100
        Caption = 'Nodes'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 205
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 171
        Caption = '&Auto Width'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsSizeClick
        Width = 205
      end
      object ccbxSeparatorColor: TcxColorComboBox
        Left = 135
        Top = 275
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = SeparatorColorChanged
        TabOrder = 6
        Width = 162
      end
    end
    object tshFormatting: TcxTabSheet
      Caption = 'Formatting'
      ImageIndex = 4
      object imgLookAndFeel: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgRefinements: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblLookAndFeel: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Look and Feel'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblRefinements: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Refinements'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object chbxFlatCheckMarks: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 144
        Caption = 'Flat Check &Marks'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 210
      end
      object chbxDisplayGraphicsAsText: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 122
        Caption = 'Display Graphics As &Text'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 210
      end
      object chbxTransparentGraphics: TcxCheckBox
        Left = 75
        Top = 100
        Caption = 'Transparent &Graphics'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 210
      end
      object chbxSuppressBackgroundBitmaps: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 181
        Caption = 'Suppress Background Textures'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsFormattingClick
        Width = 210
      end
      object chbxConsumeSelectionStyle: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 203
        Caption = 'Consume Selection Style'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsFormattingClick
        Width = 210
      end
      object cbxLookAndFeel: TcxComboBox
        Left = 75
        Top = 31
        Properties.DropDownListStyle = lsFixedList
        Properties.OnChange = LookAndFeelChange
        TabOrder = 0
        Width = 222
      end
      object bvlRefinementsSeparator: TcxLabel
        Left = 73
        Top = 165
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 17
        Width = 225
      end
    end
    object tshStyles: TcxTabSheet
      Caption = 'Styles'
      ImageIndex = 4
      object bvlStylesHost: TBevel
        Left = 8
        Top = 32
        Width = 211
        Height = 174
      end
      object lblStyleSheets: TcxLabel
        Left = 9
        Top = 248
        AutoSize = False
        Caption = 'Style Sheets'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 289
      end
      object Label1: TcxLabel
        Left = 79
        Top = 110
        Caption = '[ Styles Host ]'
        Visible = False
      end
      object lblUseNativeStyles: TcxLabel
        Left = 24
        Top = 10
        AutoSize = False
        Caption = '&Use Native Styles'
        FocusControl = chbxUseNativeStyles
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = lblUseNativeStylesClick
        Height = 18
        Width = 274
      end
      object chbxUseNativeStyles: TcxCheckBox
        Left = 7
        Top = 9
        AutoSize = False
        Style.TransparentBorder = False
        TabOrder = 0
        Transparent = True
        OnClick = OptionsFormattingClick
        Height = 21
        Width = 19
      end
      object btnStyleColor: TcxButton
        Left = 224
        Top = 62
        Width = 72
        Height = 23
        Caption = 'Co&lor...'
        TabOrder = 2
        OnClick = StyleColorClick
      end
      object btnStyleFont: TcxButton
        Left = 224
        Top = 33
        Width = 72
        Height = 23
        Caption = '&Font...'
        TabOrder = 1
        OnClick = StyleFontClick
      end
      object btnStyleBackgroundBitmap: TcxButton
        Left = 224
        Top = 91
        Width = 72
        Height = 23
        Caption = '&Texture...'
        TabOrder = 3
        OnClick = StyleBackgroundBitmapClick
      end
      object btnStyleSheetNew: TcxButton
        Left = 9
        Top = 295
        Width = 67
        Height = 23
        Caption = '&New...'
        TabOrder = 8
        OnClick = btnStyleSheetNewClick
      end
      object btnStyleSheetCopy: TcxButton
        Left = 83
        Top = 295
        Width = 67
        Height = 23
        Caption = '&Copy...'
        TabOrder = 9
        OnClick = btnStyleSheetCopyClick
      end
      object btnStyleSheetDelete: TcxButton
        Left = 156
        Top = 295
        Width = 67
        Height = 23
        Caption = '&Delete...'
        TabOrder = 10
        OnClick = btnStyleSheetDeleteClick
      end
      object btnStylesSaveAs: TcxButton
        Left = 117
        Top = 213
        Width = 101
        Height = 23
        Caption = 'Save &As...'
        TabOrder = 6
        OnClick = StylesSaveAsClick
      end
      object btnStyleSheetRename: TcxButton
        Left = 229
        Top = 295
        Width = 67
        Height = 23
        Caption = '&Rename...'
        TabOrder = 11
        OnClick = btnStyleSheetRenameClick
      end
      object btnStyleBackgroundBitmapClear: TcxButton
        Left = 224
        Top = 120
        Width = 72
        Height = 23
        Caption = 'Clear'
        TabOrder = 4
        OnClick = StyleBackgroundBitmapClearClick
      end
      object btnStyleRestoreDefaults: TcxButton
        Left = 9
        Top = 213
        Width = 101
        Height = 23
        Caption = 'Restore Defaults'
        TabOrder = 5
        OnClick = StyleRestoreDefaultsClick
      end
      object cbxStyleSheets: TcxComboBox
        Left = 9
        Top = 270
        Properties.DropDownListStyle = lsFixedList
        Properties.OnDrawItem = cbxStyleSheetsPropertiesDrawItem
        Style.TransparentBorder = False
        TabOrder = 7
        OnClick = cbxStyleSheetsClick
        OnKeyDown = cbxStyleSheetsKeyDown
        Width = 287
      end
    end
    object tshPreview: TcxTabSheet
      Caption = 'Preview'
      ImageIndex = 2
      object imgPreview: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblPreviewOptions: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Options'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 288
      end
      object lblPreviewMaxLineCount: TcxLabel
        Left = 78
        Top = 75
        Caption = 'Max Line Count:'
        FocusControl = sePreviewMaxLineCount
        Transparent = True
      end
      object chbxPreviewVisible: TcxCheckBox
        Left = 75
        Top = 30
        Caption = 'Visible'
        TabOrder = 0
        Transparent = True
        OnClick = PreviewVisibleClick
        Width = 207
      end
      object chbxPreviewAutoHeight: TcxCheckBox
        Left = 75
        Top = 51
        Caption = 'Auto Height'
        TabOrder = 1
        Transparent = True
        OnClick = PreviewAutoHeightClick
        Width = 207
      end
      object sePreviewMaxLineCount: TcxSpinEdit
        Left = 166
        Top = 74
        Properties.MaxValue = 1000.000000000000000000
        Properties.OnChange = PreviewMaxLineCountChanged
        TabOrder = 2
        Width = 131
      end
    end
  end
  object pnlPreview: TPanel
    Left = 321
    Top = 53
    Width = 298
    Height = 301
    BevelOuter = bvLowered
    Color = clWindow
    ParentBackground = False
    TabOrder = 1
    object PreviewTreeList: TcxTreeList
      Left = 5
      Top = 5
      Width = 288
      Height = 291
      Bands = <
        item
          Caption.Text = 'Manufacturer Data'
          Width = 173
        end
        item
          Caption.Text = 'Car Data'
          Width = 116
        end>
      DefaultRowHeight = 17
      Enabled = False
      OptionsView.CellAutoHeight = True
      OptionsView.ScrollBars = ssNone
      OptionsView.Bands = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GridLines = tlglBoth
      OptionsView.UseNodeColorForIndent = False
      Preview.Column = colManufacturerCountry
      TabOrder = 0
      OnCustomDrawBandHeaderCell = PreviewTreeListCustomDrawBandHeaderCell
      OnCustomDrawDataCell = PreviewTreeListCustomDrawDataCell
      OnCustomDrawFooterCell = PreviewTreeListCustomDrawFooterCell
      OnCustomDrawHeaderCell = PreviewTreeListCustomDrawHeaderCell
      object colManufacturerName: TcxTreeListColumn
        Caption.Text = 'Name'
        DataBinding.ValueType = 'String'
        Width = 113
        Position.ColIndex = 0
        Position.RowIndex = 0
        Position.BandIndex = 0
        Summary.FooterSummaryItems = <>
        Summary.GroupFooterSummaryItems = <>
      end
      object colManufacturerLogo: TcxTreeListColumn
        Caption.Text = 'Logo'
        DataBinding.ValueType = 'String'
        Width = 60
        Position.ColIndex = 1
        Position.RowIndex = 0
        Position.BandIndex = 0
        Summary.FooterSummaryItems = <>
        Summary.GroupFooterSummaryItems = <>
      end
      object colManufacturerCountry: TcxTreeListColumn
        Caption.Text = 'Country'
        DataBinding.ValueType = 'String'
        Width = 167
        Position.ColIndex = 2
        Position.RowIndex = 0
        Position.BandIndex = 0
        Summary.FooterSummaryItems = <>
        Summary.GroupFooterSummaryItems = <>
      end
      object colCarModel: TcxTreeListColumn
        Caption.Text = 'Model'
        DataBinding.ValueType = 'String'
        Width = 86
        Position.ColIndex = 0
        Position.RowIndex = 0
        Position.BandIndex = 1
        Summary.FooterSummaryItems = <>
        Summary.GroupFooterSummaryItems = <>
      end
      object colCarIsSUV: TcxTreeListColumn
        Caption.Text = 'SUV'
        DataBinding.ValueType = 'String'
        Width = 30
        Position.ColIndex = 1
        Position.RowIndex = 0
        Position.BandIndex = 1
        Summary.FooterSummaryItems = <>
        Summary.GroupFooterSummaryItems = <>
      end
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 4
    Top = 362
    PixelsPerInch = 96
    object styleBandHeaders: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object styleStandard: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object stylePreview: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object styleCardShadow: TcxStyle
    end
  end
  object pmStyles: TPopupMenu
    Images = ilStylesPopup
    OnPopup = pmStylesPopup
    Left = 32
    Top = 362
    object miStyleFont: TMenuItem
      Caption = '&Font...'
      ImageIndex = 0
      ShortCut = 16454
      OnClick = StyleFontClick
    end
    object miStyleColor: TMenuItem
      Caption = '&Color...'
      OnClick = StyleColorClick
    end
    object miLine3: TMenuItem
      Caption = '-'
    end
    object miStyleBackgroundBitmap: TMenuItem
      Caption = '&Texture...'
      ImageIndex = 1
      OnClick = StyleBackgroundBitmapClick
    end
    object miStyleBackgroundBitmapClear: TMenuItem
      Caption = 'Clear'
      ImageIndex = 3
      ShortCut = 16430
      OnClick = StyleBackgroundBitmapClearClick
    end
    object milLine: TMenuItem
      Caption = '-'
    end
    object miStylesSelectAll: TMenuItem
      Caption = 'Select A&ll'
      ShortCut = 16449
      OnClick = miStylesSelectAllClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miStyleRestoreDefaults: TMenuItem
      Caption = 'Restore Defaults'
      OnClick = StyleRestoreDefaultsClick
    end
    object miLine4: TMenuItem
      Caption = '-'
    end
    object miStylesSaveAs: TMenuItem
      Caption = 'Save &As...'
      ImageIndex = 2
      ShortCut = 16467
      OnClick = StylesSaveAsClick
    end
  end
  object ilStylesPopup: TcxImageList
    FormatVersion = 1
    DesignInfo = 23593024
  end
end
