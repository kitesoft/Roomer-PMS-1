object cxfmVerticalGridReportLinkDesignWindow: TcxfmVerticalGridReportLinkDesignWindow
  Left = 373
  Top = 217
  BorderStyle = bsDialog
  Caption = 'cxfmVerticalGridReportLinkDesignWindow'
  ClientHeight = 420
  ClientWidth = 652
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 628
    Height = 363
    ActivePage = tshView
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 362
    ClientRectLeft = 1
    ClientRectRight = 627
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
      object chbxShowHeaders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = '&Headers'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowExpandButtons: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 71
        Caption = 'Expand Buttons'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowBorders: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 49
        Caption = 'Borders'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsViewClick
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
      object lblPrintMode: TcxLabel
        Left = 75
        Top = 112
        Caption = 'Mode: '
        FocusControl = cbxPrintMode
        Transparent = True
      end
      object lblPreviewWindow: TcxLabel
        Left = 302
        Top = 0
        TabStop = False
        AutoSize = False
        Caption = 'Preview'
        Transparent = True
        Height = 17
        Width = 46
      end
      object bvlMultipleRecords: TcxLabel
        Left = 70
        Top = 95
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 225
      end
      object cbxPrintMode: TcxComboBox
        Left = 121
        Top = 111
        Properties.DropDownListStyle = lsFixedList
        Properties.OnChange = cbxPrintModeChange
        TabOrder = 3
        Width = 173
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
      object imgGridSize: TImage
        Left = 10
        Top = 103
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxExpandRows: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Rows'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 200
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 100
        Caption = '&Auto Width'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsSizeClick
        Width = 200
      end
      object chbxBestFit: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 122
        Caption = 'BestFit'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsSizeClick
        Width = 200
      end
      object chbxWrapRecords: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 166
        Caption = '&Wrap Records'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsSizeClick
        Width = 200
      end
      object chbxKeepSameRecordWidths: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 144
        Caption = 'Keep Equal Record Widths'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsSizeClick
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
      object lblSize: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Size'
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
      object imgPagination: TImage
        Left = 10
        Top = 206
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxFlatCheckMarks: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 144
        Caption = 'Flat Check &Marks'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 200
      end
      object chbxDisplayGraphicsAsText: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 122
        Caption = 'Display Graphics As &Text'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 200
      end
      object chbxTransparentGraphics: TcxCheckBox
        Left = 75
        Top = 100
        Caption = 'Transparent &Graphics'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsRefinementsClick
        Width = 200
      end
      object chbxSuppressBackgroundBitmaps: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 166
        Caption = 'Suppress Background Textures'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsFormattingClick
        Width = 200
      end
      object chbxPaginateByRows: TcxCheckBox
        Left = 75
        Top = 203
        Caption = 'By Rows'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsPaginationClick
        Width = 200
      end
      object chbxPaginateByWrapping: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 225
        Caption = 'By Wrapping'
        TabOrder = 6
        Transparent = True
        OnClick = OptionsPaginationClick
        Width = 200
      end
      object chbxOneWrappingPerPage: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 247
        Caption = 'One Wrapping Per Page'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsPaginationClick
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
      object lblPagination: TcxLabel
        Left = 10
        Top = 186
        AutoSize = False
        Caption = 'Pagination'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 285
      end
      object cbxLookAndFeel: TcxComboBox
        Left = 79
        Top = 31
        Properties.DropDownListStyle = lsFixedList
        Properties.OnChange = LookAndFeelChange
        TabOrder = 0
        Width = 215
      end
    end
    object tshStyles: TcxTabSheet
      Caption = 'Styles'
      ImageIndex = 4
      object bvlStylesHost: TBevel
        Left = 8
        Top = 32
        Width = 208
        Height = 183
      end
      object chbxUseNativeStyles: TcxCheckBox
        Left = 4
        Top = 9
        AutoSize = False
        TabOrder = 0
        Transparent = True
        OnClick = OptionsFormattingClick
        Height = 21
        Width = 21
      end
      object lblStyleSheets: TcxLabel
        Left = 6
        Top = 255
        AutoSize = False
        Caption = 'Style Sheets'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 289
      end
      object Label1: TcxLabel
        Left = 77
        Top = 118
        Caption = '[ Styles Host ]'
        Visible = False
      end
      object lblUseNativeStyles: TcxLabel
        Left = 23
        Top = 10
        AutoSize = False
        Caption = '&Use Native Styles'
        FocusControl = chbxUseNativeStyles
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = lblUseNativeStylesClick
        Height = 18
        Width = 272
      end
      object btnStyleColor: TcxButton
        Left = 221
        Top = 62
        Width = 72
        Height = 23
        Caption = 'Co&lor...'
        TabOrder = 2
        OnClick = StyleColorClick
      end
      object btnStyleFont: TcxButton
        Left = 221
        Top = 33
        Width = 72
        Height = 23
        Caption = '&Font...'
        TabOrder = 1
        OnClick = StyleFontClick
      end
      object btnStyleBackgroundBitmap: TcxButton
        Left = 221
        Top = 91
        Width = 72
        Height = 23
        Caption = '&Bitmap...'
        TabOrder = 3
        OnClick = StyleBackgroundBitmapClick
      end
      object btnStyleSheetNew: TcxButton
        Left = 9
        Top = 302
        Width = 66
        Height = 23
        Caption = '&New...'
        TabOrder = 8
        OnClick = btnStyleSheetNewClick
      end
      object btnStyleSheetCopy: TcxButton
        Left = 81
        Top = 302
        Width = 66
        Height = 23
        Caption = '&Copy...'
        TabOrder = 9
        OnClick = btnStyleSheetCopyClick
      end
      object btnStyleSheetDelete: TcxButton
        Left = 153
        Top = 302
        Width = 67
        Height = 23
        Caption = '&Delete...'
        TabOrder = 10
        OnClick = btnStyleSheetDeleteClick
      end
      object btnStylesSaveAs: TcxButton
        Left = 115
        Top = 221
        Width = 100
        Height = 23
        Caption = 'Save &As...'
        TabOrder = 6
        OnClick = StylesSaveAsClick
      end
      object btnStyleSheetRename: TcxButton
        Left = 226
        Top = 302
        Width = 67
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
        OnClick = StyleBackgroundBitmapClearClick
      end
      object btnStyleRestoreDefaults: TcxButton
        Left = 9
        Top = 221
        Width = 100
        Height = 23
        Caption = 'Restore Defaults'
        TabOrder = 5
        OnClick = StyleRestoreDefaultsClick
      end
      object cbxStyleSheets: TcxComboBox
        Left = 9
        Top = 277
        Properties.DropDownListStyle = lsFixedList
        Properties.ItemHeight = 18
        Properties.OnDrawItem = cbxStyleSheetsPropertiesDrawItem
        Style.TransparentBorder = False
        TabOrder = 7
        OnClick = cbxStyleSheetsClick
        OnKeyDown = cbxStyleSheetsKeyDown
        Width = 284
      end
    end
  end
  object pnlPreview: TPanel
    Left = 318
    Top = 54
    Width = 309
    Height = 307
    BevelOuter = bvLowered
    Color = clWindow
    ParentBackground = False
    TabOrder = 1
    object PreviewVGrid: TcxVerticalGrid
      Left = 8
      Top = 8
      Width = 297
      Height = 293
      BorderStyle = cxcbsNone
      OptionsView.ScrollBars = ssNone
      OptionsView.RowHeaderWidth = 112
      OptionsView.ValueWidth = 150
      TabOrder = 0
      OnDrawValue = PreviewVGridDrawValue
      object rowLuxurySedan: TcxCategoryRow
        Properties.Caption = 'Luxury sedans'
        Properties.HeaderAlignmentVert = vaCenter
        object rowManufacturer: TcxEditorRow
          Properties.Caption = 'Manufacturer'
          Properties.HeaderAlignmentVert = vaCenter
          Properties.EditPropertiesClassName = 'TcxTextEditProperties'
          Properties.EditProperties.MaxLength = 0
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = 'BMW'
        end
        object rowModel: TcxEditorRow
          Properties.Caption = 'Model'
          Properties.HeaderAlignmentVert = vaCenter
          Properties.EditPropertiesClassName = 'TcxTextEditProperties'
          Properties.EditProperties.MaxLength = 0
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = '760 Li V12'
        end
        object rowPicture: TcxEditorRow
          Height = 116
          Properties.Caption = 'Picture'
          Properties.HeaderAlignmentVert = vaCenter
          Properties.EditPropertiesClassName = 'TcxImageProperties'
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = Null
        end
        object rowEngine: TcxEditorRow
          Height = 57
          Properties.Caption = 'Engine'
          Properties.EditPropertiesClassName = 'TcxMemoProperties'
          Properties.EditProperties.MaxLength = 0
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = 
            '6.0L DOHC V12 438 HP 48V DI Valvetronic 12-cylinder engine with ' +
            '6.0-liter displacement, dual overhead cam valvetrain'
        end
        object rowTransmission: TcxEditorRow
          Height = 17
          Properties.Caption = 'Transmission'
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = 'Elec 6-Speed Automatic w/Steptronic'
        end
        object rowTires: TcxEditorRow
          Height = 44
          Properties.Caption = 'Tires'
          Properties.EditPropertiesClassName = 'TcxMemoProperties'
          Properties.EditProperties.MaxLength = 0
          Properties.DataBinding.ValueType = 'String'
          Properties.Value = 
            'P245/45R19 Fr - P275/40R19 Rr Performance. Low Profile tires wit' +
            'h 245mm width, 19.0" rim'
        end
      end
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 4
    Top = 373
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
    Top = 373
    object miStyleFont: TMenuItem
      Caption = '&Font...'
      ImageIndex = 0
      ShortCut = 16454
      OnClick = StyleFontClick
    end
    object miStyleColor: TMenuItem
      Caption = '&Color...'
      ShortCut = 16451
      OnClick = StyleColorClick
    end
    object miLine3: TMenuItem
      Caption = '-'
    end
    object miStyleBackgroundBitmap: TMenuItem
      Caption = '&Bitmap...'
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
    DesignInfo = 24444992
  end
end
