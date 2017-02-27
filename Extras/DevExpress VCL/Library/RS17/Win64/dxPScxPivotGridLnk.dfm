object cxfmPivotGridReportLinkDesignWindow: TcxfmPivotGridReportLinkDesignWindow
  Left = 349
  Top = 253
  BorderStyle = bsDialog
  Caption = 'cxfmPivotGridReportLinkDesignWindow'
  ClientHeight = 422
  ClientWidth = 720
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 696
    Height = 363
    ActivePage = tshView
    ShowFrame = True
    TabOrder = 0
    ClientRectBottom = 362
    ClientRectLeft = 1
    ClientRectRight = 695
    ClientRectTop = 24
    object tshView: TcxTabSheet
      Caption = 'View'
      object Image1: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgOnEveryPage: TImage
        Left = 9
        Top = 258
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxColumnFields: TcxCheckBox
        Left = 75
        Top = 27
        Caption = '&Column Fields'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxShowExpandButtons: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 115
        Caption = '&Expand Buttons'
        TabOrder = 4
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxHorizontalLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 174
        Caption = '&Horizontal Lines'
        TabOrder = 6
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxVerticalLines: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 196
        Caption = '&Vertical Lines'
        TabOrder = 7
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxBorders: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 218
        Caption = '&Borders'
        TabOrder = 8
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxDataFields: TcxCheckBox
        Left = 75
        Top = 49
        Caption = '&Data Fields'
        TabOrder = 1
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxFilterFields: TcxCheckBox
        Left = 75
        Top = 71
        Caption = '&Filter Fields'
        TabOrder = 2
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxRowFields: TcxCheckBox
        Left = 75
        Top = 93
        Caption = '&Row Fields'
        TabOrder = 3
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object chbxPrefilter: TcxCheckBox
        Tag = 5
        Left = 75
        Top = 137
        Caption = '&Prefilter'
        TabOrder = 5
        Transparent = True
        OnClick = chbxOptionsViewClick
        Width = 200
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 285
      end
      object cxLabel1: TcxLabel
        Left = 65
        Top = 157
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 230
      end
      object lblOnEveryPage: TcxLabel
        Left = 5
        Top = 238
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 290
      end
      object chbxColumnHeadersOnEveryPage: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 255
        Caption = 'Column Headers'
        TabOrder = 9
        Transparent = True
        OnClick = chbxOptionsOnEveryPageClick
        Width = 200
      end
      object chbxRowHeadersOnEveryPage: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 277
        Caption = 'Row Headers'
        TabOrder = 10
        Transparent = True
        OnClick = chbxOptionsOnEveryPageClick
        Width = 200
      end
      object chbxFilterBarOnEveryPage: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 299
        Caption = 'Filter Bar'
        TabOrder = 11
        Transparent = True
        OnClick = chbxOptionsOnEveryPageClick
        Width = 200
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = 'Behaviors'
      ImageIndex = 1
      object imgExpanding: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxExpandRows: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Rows'
        TabOrder = 1
        Transparent = True
        OnClick = chbxExpandOptionsClick
        Width = 200
      end
      object chbxExpandColumns: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Columns'
        TabOrder = 0
        Transparent = True
        OnClick = chbxExpandOptionsClick
        Width = 200
      end
      object lblExpanding: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Expanding'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 285
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
      object chbxSuppressBackgroundBitmaps: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 181
        Caption = 'Suppress Background Textures'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsFormattingChanged
        Width = 200
      end
      object chbxSuppressContentColoration: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 203
        Caption = 'Suppress Content Coloration'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsFormattingChanged
        Width = 200
      end
      object lblLookAndFeel: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Look and Feel'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 285
      end
      object lblRefinements: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Refinements'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 285
      end
      object cbxLookAndFeel: TcxComboBox
        Left = 75
        Top = 31
        Properties.DropDownListStyle = lsFixedList
        Properties.OnChange = cbxLookAndFeelChange
        TabOrder = 0
        Width = 218
      end
      object chbxFlatCheckMarks: TcxCheckBox
        Tag = 5
        Left = 75
        Top = 144
        Caption = 'Flat Check &Marks'
        Properties.OnChange = OptionsFormattingChanged
        TabOrder = 3
        Transparent = True
        OnClick = OptionsFormattingChanged
        Width = 200
      end
      object chbxDisplayGraphicsAsText: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 122
        Caption = 'Display Graphics As &Text'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsFormattingChanged
        Width = 200
      end
      object chbxTransparentGraphics: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 100
        Caption = 'Transparent &Graphics'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsFormattingChanged
        Width = 200
      end
      object bvlRefinementsSeparator: TcxLabel
        Left = 70
        Top = 170
        AutoSize = False
        Properties.LineOptions.Visible = True
        Height = 6
        Width = 225
      end
    end
    object tshStyles: TcxTabSheet
      Caption = 'Styles'
      ImageIndex = 4
      object bvlStylesHost: TBevel
        Left = 8
        Top = 32
        Width = 208
        Height = 185
      end
      object chbxUseNativeStyles: TcxCheckBox
        Left = 5
        Top = 8
        TabStop = False
        AutoSize = False
        Style.TransparentBorder = False
        TabOrder = 0
        Transparent = True
        OnClick = OptionsFormattingChanged
        Height = 21
        Width = 18
      end
      object lblStyleSheets: TcxLabel
        Left = 9
        Top = 255
        AutoSize = False
        Caption = 'Style Sheets'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 286
      end
      object lblUseNativeStyles: TcxLabel
        Left = 22
        Top = 9
        AutoSize = False
        Caption = '&Use Native Styles'
        FocusControl = chbxUseNativeStyles
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = lblUseNativeStylesClick
        Height = 18
        Width = 273
      end
      object btnStyleColor: TcxButton
        Left = 221
        Top = 62
        Width = 72
        Height = 23
        Caption = 'Co&lor...'
        TabOrder = 2
        OnClick = btnStyleColorClick
      end
      object btnStyleFont: TcxButton
        Left = 221
        Top = 33
        Width = 72
        Height = 23
        Caption = '&Font...'
        TabOrder = 1
        OnClick = btnStyleFontClick
      end
      object btnStyleBackgroundBitmap: TcxButton
        Left = 221
        Top = 91
        Width = 72
        Height = 23
        Caption = '&Bitmap...'
        TabOrder = 3
        OnClick = btnStyleBackgroundBitmapClick
      end
      object btnStyleSheetNew: TcxButton
        Left = 9
        Top = 303
        Width = 66
        Height = 23
        Caption = '&New...'
        TabOrder = 8
        OnClick = btnStyleSheetNewClick
      end
      object btnStyleSheetCopy: TcxButton
        Left = 81
        Top = 303
        Width = 67
        Height = 23
        Caption = '&Copy...'
        TabOrder = 9
        OnClick = btnStyleSheetCopyClick
      end
      object btnStyleSheetDelete: TcxButton
        Left = 154
        Top = 303
        Width = 67
        Height = 23
        Caption = '&Delete...'
        TabOrder = 10
        OnClick = btnStyleSheetDeleteClick
      end
      object btnStylesSaveAs: TcxButton
        Left = 115
        Top = 223
        Width = 100
        Height = 23
        Caption = 'Save &As...'
        TabOrder = 6
        OnClick = btnStylesSaveAsClick
      end
      object btnStyleSheetRename: TcxButton
        Left = 227
        Top = 303
        Width = 66
        Height = 23
        Caption = '&Rename...'
        TabOrder = 11
        OnClick = btnStyleSheetRenameClick
      end
      object btnStyleBackgroundBitmapClear: TcxButton
        Left = 221
        Top = 120
        Width = 72
        Height = 23
        Caption = 'Clear'
        TabOrder = 4
        OnClick = btnStyleClearClick
      end
      object btnStyleRestoreDefaults: TcxButton
        Left = 9
        Top = 223
        Width = 100
        Height = 23
        Caption = 'Restore Defaults'
        TabOrder = 5
        OnClick = btnStyleRestoreDefaultsClick
      end
      object cbxStyleSheets: TcxComboBox
        Left = 8
        Top = 276
        Properties.DropDownListStyle = lsFixedList
        Properties.ItemHeight = 18
        Properties.OnDrawItem = cbxStyleSheetsPropertiesDrawItem
        TabOrder = 7
        OnClick = cbxStyleSheetsClick
        OnKeyDown = cbxStyleSheetsKeyDown
        Width = 286
      end
    end
  end
  object pnlPreview: TPanel
    Left = 318
    Top = 53
    Width = 379
    Height = 309
    BevelOuter = bvLowered
    Color = clWindow
    ParentBackground = False
    TabOrder = 1
    object PreviewPivotGrid: TcxPivotGrid
      Left = 4
      Top = 4
      Width = 372
      Height = 301
      Enabled = False
      Groups = <
        item
          IsCaptionAssigned = True
          Caption = 'FieldsGroup 1'
        end>
      LookAndFeel.SkinName = ''
      TabOrder = 0
      object pgfPurchaseQuarter: TcxPivotGridField
        Area = faColumn
        AreaIndex = 0
        IsCaptionAssigned = True
        Caption = 'Purchase Quarter'
        DataBinding.ValueType = 'DateTime'
        GroupIndex = 0
        GroupInterval = giDateQuarter
        Visible = True
      end
      object pgfPurchaseMonth: TcxPivotGridField
        Area = faColumn
        AreaIndex = 1
        IsCaptionAssigned = True
        Caption = 'Purchase Month'
        DataBinding.ValueType = 'DateTime'
        GroupIndex = 0
        GroupExpanded = False
        GroupInterval = giDateMonth
        Visible = True
      end
      object pgfPaymentType: TcxPivotGridField
        Tag = 1
        Area = faRow
        AreaIndex = 0
        IsCaptionAssigned = True
        Caption = 'Payment Type'
        DataBinding.ValueType = 'String'
        Visible = True
        Width = 90
      end
      object pgfQuantity: TcxPivotGridField
        Tag = 2
        Area = faData
        AreaIndex = 0
        IsCaptionAssigned = True
        Caption = 'Quantity'
        DataBinding.ValueType = 'Integer'
        Visible = True
        Width = 62
      end
      object pgfCarName: TcxPivotGridField
        Tag = 3
        AreaIndex = 1
        IsCaptionAssigned = True
        Caption = 'Car Name'
        DataBinding.ValueType = 'String'
        Visible = True
      end
      object pgfUnitPrice: TcxPivotGridField
        Tag = 4
        AreaIndex = 0
        IsCaptionAssigned = True
        Caption = 'Unit Price'
        DataBinding.ValueType = 'Currency'
        Visible = True
      end
      object pgfCompanyName: TcxPivotGridField
        Tag = 5
        Area = faRow
        AreaIndex = 1
        IsCaptionAssigned = True
        Caption = 'Company Name'
        DataBinding.ValueType = 'String'
        Visible = True
        Width = 90
      end
      object pgfPaymentAmount: TcxPivotGridField
        Tag = 6
        Area = faData
        AreaIndex = 1
        IsCaptionAssigned = True
        Caption = 'Payment Amount'
        DataBinding.ValueType = 'Currency'
        Visible = True
      end
    end
  end
  object lblPreviewWindow: TcxLabel
    Left = 317
    Top = 35
    TabStop = False
    Caption = 'Preview'
    Transparent = True
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 4
    Top = 368
    PixelsPerInch = 96
    object styleCategory: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWindowText
    end
    object styleHeader: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWindowText
    end
    object styleContent: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWindowText
    end
  end
  object pmStyles: TPopupMenu
    Images = ilStylesPopup
    OnPopup = pmStylesPopup
    Left = 32
    Top = 368
    object miStyleFont: TMenuItem
      Caption = '&Font...'
      ImageIndex = 0
      ShortCut = 16454
      OnClick = btnStyleFontClick
    end
    object miStyleColor: TMenuItem
      Caption = '&Color...'
      ShortCut = 16451
      OnClick = btnStyleColorClick
    end
    object miLine3: TMenuItem
      Caption = '-'
    end
    object miStyleBackgroundBitmap: TMenuItem
      Caption = '&Bitmap...'
      ImageIndex = 1
      OnClick = btnStyleBackgroundBitmapClick
    end
    object miStyleBackgroundBitmapClear: TMenuItem
      Caption = 'Clear'
      ImageIndex = 3
      ShortCut = 16430
      OnClick = btnStyleClearClick
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
      OnClick = btnStyleRestoreDefaultsClick
    end
    object miLine4: TMenuItem
      Caption = '-'
    end
    object miStylesSaveAs: TMenuItem
      Caption = 'Save &As...'
      ImageIndex = 2
      ShortCut = 16467
      OnClick = btnStylesSaveAsClick
    end
  end
  object ilStylesPopup: TcxImageList
    FormatVersion = 1
    DesignInfo = 24117312
  end
end
