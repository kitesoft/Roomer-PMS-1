object dxfmGridReportLinkDesignWindow: TdxfmGridReportLinkDesignWindow
  Left = 330
  Top = 198
  BorderStyle = bsDialog
  Caption = 'fmdxGridDesignWindow'
  ClientHeight = 478
  ClientWidth = 665
  Color = clBtnFace
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 641
    Height = 420
    ActivePage = tshView
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 419
    ClientRectLeft = 1
    ClientRectRight = 640
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
        Top = 291
        Width = 302
        Height = 76
        Visible = False
      end
      object chbxShowBands: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 46
        Caption = 'Ba&nds'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowHeaders: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 66
        Caption = '&Headers'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowFooters: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 86
        Caption = 'Foo&ters'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowGroupFooters: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 106
        Caption = 'G&roup Footers'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowExpandButtons: TcxCheckBox
        Tag = 5
        Left = 75
        Top = 126
        Caption = 'Expand Buttons'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxBandsOnEveryPage: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 204
        Caption = 'Ba&nds'
        TabOrder = 8
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxHeadersOnEveryPage: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 224
        Caption = 'Headers'
        TabOrder = 9
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxFootersOnEveryPage: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 244
        Caption = 'Footers'
        TabOrder = 10
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxFilterBarOnEveryPage: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 264
        Caption = 'FilterBar'
        TabOrder = 11
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxCaptionsOnEveryPage: TcxCheckBox
        Left = 75
        Top = 184
        Caption = 'Captions'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsOnEveryPageClick
        Width = 200
      end
      object chbxShowCaptions: TcxCheckBox
        Left = 75
        Top = 26
        Caption = 'Captions'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsViewClick
        Width = 200
      end
      object chbxShowFilterBar: TcxCheckBox
        Tag = 6
        Left = 75
        Top = 146
        Caption = 'FilterBar'
        TabOrder = 6
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
        Width = 302
      end
      object lblOnEveryPage: TcxLabel
        Left = 10
        Top = 166
        AutoSize = False
        Caption = 'On Every Page'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblPreviewWindow: TcxLabel
        Left = 321
        Top = 0
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = 'Behaviors'
      ImageIndex = 1
      object imgSelection: TImage
        Left = 10
        Top = 28
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgExpanding: TImage
        Left = 10
        Top = 93
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgDetails: TImage
        Left = 10
        Top = 234
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgLevels: TImage
        Left = 10
        Top = 302
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgGridSize: TImage
        Left = 10
        Top = 168
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxProcessSelection: TcxCheckBox
        Left = 75
        Top = 26
        Caption = 'Process Selection'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsSelectionClick
        Width = 200
      end
      object chbxProcessExactSelection: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 46
        Caption = 'Process Exact Selection'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsSelectionClick
        Width = 200
      end
      object chbxExpandGroupRows: TcxCheckBox
        Left = 75
        Top = 91
        Caption = 'Groups'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 200
      end
      object chbxExpandMasterRows: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 111
        Caption = 'Details'
        TabOrder = 3
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 200
      end
      object chbxStartFromActiveView: TcxCheckBox
        Left = 75
        Top = 232
        Caption = 'Start From Active Details'
        TabOrder = 6
        Transparent = True
        OnClick = OptionsDetailsClick
        Width = 200
      end
      object chbxOnlyActiveView: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 252
        Caption = 'Only Active Details'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsDetailsClick
        Width = 200
      end
      object chbxLevelsUnwrap: TcxCheckBox
        Left = 75
        Top = 300
        Caption = '&Unwrap'
        TabOrder = 8
        Transparent = True
        OnClick = OptionsLevelsClick
        Width = 200
      end
      object chbxLevelsUnwrapTopLevel: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 320
        Caption = 'Unwrap Top Level'
        TabOrder = 9
        Transparent = True
        OnClick = OptionsLevelsClick
        Width = 200
      end
      object chbxLevelsRiseActiveLevelOntoTop: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 340
        Caption = 'Rise Active Level onto Top'
        TabOrder = 10
        Transparent = True
        OnClick = OptionsLevelsClick
        Width = 200
      end
      object chbxGridAutoWidth: TcxCheckBox
        Left = 75
        Top = 166
        Caption = '&Auto Width'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsSizeClick
        Width = 200
      end
      object chbxExpandCards: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 131
        Caption = 'Cards'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsExpandingClick
        Width = 200
      end
      object chbxLevelsSkipEmptyViews: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 360
        Caption = 'Skip Empty Views'
        TabOrder = 11
        Transparent = True
        OnClick = OptionsLevelsClick
        Width = 200
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblExpanding: TcxLabel
        Left = 10
        Top = 75
        AutoSize = False
        Caption = 'Expanding'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblDetails: TcxLabel
        Left = 10
        Top = 216
        AutoSize = False
        Caption = 'Details'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblLevels: TcxLabel
        Left = 10
        Top = 284
        AutoSize = False
        Caption = 'Levels'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblGridSize: TcxLabel
        Left = 10
        Top = 150
        AutoSize = False
        Caption = 'Size'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
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
        Top = 241
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
        OnClick = OptionsRefinementClick
        Width = 200
      end
      object chbxDisplayGraphicsAsText: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 122
        Caption = 'Display Graphics As &Text'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsRefinementClick
        Width = 200
      end
      object chbxTransparentGraphics: TcxCheckBox
        Left = 75
        Top = 100
        Caption = 'Transparent &Graphics'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsRefinementClick
        Width = 200
      end
      object chbxSuppressBackgroundBitmaps: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 181
        Caption = 'Suppress Background Images'
        TabOrder = 4
        Transparent = True
        OnClick = OptionsFormatingClick
        Width = 200
      end
      object chbxConsumeSelectionStyle: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 201
        Caption = 'Consume Selection Style'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsFormatingClick
        Width = 200
      end
      object chbxPaginateOneGroupPerPage: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 260
        Caption = 'One Group Per Page'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsPaginationClick
        Width = 200
      end
      object chbxPaginateByTopLevelGroups: TcxCheckBox
        Left = 75
        Top = 238
        Caption = 'By TopLevel Groups'
        TabOrder = 6
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
        Width = 302
      end
      object lblRefinements: TcxLabel
        Left = 10
        Top = 83
        AutoSize = False
        Caption = 'Refinements'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblPagination: TcxLabel
        Left = 10
        Top = 221
        AutoSize = False
        Caption = 'Pagination'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object bvlRefinementsSeparator: TcxLabel
        Left = 73
        Top = 168
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 239
      end
      object cbxLookAndFeel: TcxComboBox
        Left = 75
        Top = 31
        Properties.DropDownListStyle = lsFixedList
        TabOrder = 0
        OnClick = LookAndFeelClick
        Width = 236
      end
    end
    object tshStyles: TcxTabSheet
      Caption = 'Styles'
      ImageIndex = 5
      object bvlStylesHost: TBevel
        Left = 10
        Top = 32
        Width = 223
        Height = 225
      end
      object chbxUseNativeStyles: TcxCheckBox
        Left = 7
        Top = 9
        AutoSize = False
        Style.TransparentBorder = False
        TabOrder = 0
        Transparent = True
        OnClick = OptionsFormatingClick
        Height = 21
        Width = 21
      end
      object lblStyleSheets: TcxLabel
        Left = 10
        Top = 295
        AutoSize = False
        Caption = 'Style Sheets'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
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
        Width = 288
      end
      object btnStyleColor: TcxButton
        Left = 238
        Top = 62
        Width = 72
        Height = 23
        Caption = 'Co&lor...'
        TabOrder = 2
        OnClick = StyleColorClick
      end
      object btnStyleFont: TcxButton
        Left = 238
        Top = 33
        Width = 72
        Height = 23
        Caption = '&Font...'
        TabOrder = 1
        OnClick = StyleFontClick
      end
      object btnStyleBackgroundBitmap: TcxButton
        Left = 238
        Top = 91
        Width = 72
        Height = 23
        Caption = '&Bitmap...'
        TabOrder = 3
        OnClick = StyleBackgroundBitmapClick
      end
      object btnStyleSheetNew: TcxButton
        Left = 12
        Top = 344
        Width = 70
        Height = 23
        Caption = '&New...'
        TabOrder = 8
        OnClick = StyleSheetNewClick
      end
      object btnStyleSheetCopy: TcxButton
        Left = 88
        Top = 344
        Width = 70
        Height = 23
        Caption = '&Copy...'
        TabOrder = 9
        OnClick = StyleSheetCopyClick
      end
      object btnStyleSheetDelete: TcxButton
        Left = 164
        Top = 344
        Width = 70
        Height = 23
        Caption = '&Delete...'
        TabOrder = 10
        OnClick = StyleSheetDeleteClick
      end
      object btnStylesSaveAs: TcxButton
        Left = 123
        Top = 262
        Width = 109
        Height = 23
        Caption = 'Save &As...'
        TabOrder = 6
        OnClick = StylesSaveAsClick
      end
      object btnStyleSheetRename: TcxButton
        Left = 240
        Top = 344
        Width = 70
        Height = 23
        Caption = '&Rename...'
        TabOrder = 11
        OnClick = StyleSheetRenameClick
      end
      object btnStyleBackgroundBitmapClear: TcxButton
        Left = 238
        Top = 120
        Width = 72
        Height = 23
        Caption = 'Cle&ar'
        TabOrder = 4
        OnClick = StyleBackgroundBitmapClearClick
      end
      object btnStyleRestoreDefaults: TcxButton
        Left = 11
        Top = 262
        Width = 106
        Height = 23
        Caption = 'Rest&ore Defaults'
        TabOrder = 5
        OnClick = StyleRestoreDefaultsClick
      end
      object cbxStyleSheets: TcxComboBox
        Left = 11
        Top = 317
        Properties.DropDownListStyle = lsFixedList
        Properties.ItemHeight = 18
        Properties.OnDrawItem = cbxStyleSheetsPropertiesDrawItem
        TabOrder = 7
        OnClick = cbxStyleSheetsClick
        OnKeyDown = cbxStyleSheetsKeyDown
        Width = 300
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
      object chbxPreviewVisible: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Visible'
        TabOrder = 0
        Transparent = True
        OnClick = PreviewVisibleClick
        Width = 150
      end
      object chbxPreviewAutoHeight: TcxCheckBox
        Left = 75
        Top = 49
        Caption = 'Auto Height'
        TabOrder = 1
        Transparent = True
        OnClick = PreviewAutoHeightClick
        Width = 150
      end
      object lblPreviewOptions: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Options'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblPreviewMaxLineCount: TcxLabel
        Left = 77
        Top = 73
        Caption = 'Max Line Count:'
        Transparent = True
      end
      object sePreviewMaxLineCount: TcxSpinEdit
        Left = 163
        Top = 72
        Properties.AssignedValues.MinValue = True
        Properties.MaxValue = 1000.000000000000000000
        Properties.OnChange = PreviewMaxLineCountChanged
        TabOrder = 4
        Width = 148
      end
    end
    object tshCards: TcxTabSheet
      Caption = 'Cards'
      ImageIndex = 3
      object imgCardSpacing: TImage
        Left = 10
        Top = 111
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgCardSizes: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgCardFraming: TImage
        Left = 10
        Top = 185
        Width = 48
        Height = 48
        Transparent = True
      end
      object imgCardShadow: TImage
        Left = 10
        Top = 266
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxCardsKeepSameHeight: TcxCheckBox
        Tag = 2
        Left = 75
        Top = 71
        Caption = 'Keep Same Height'
        TabOrder = 2
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object chbxCardsKeepSameWidth: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Keep Same Width'
        TabOrder = 1
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object chbxCardsAutoWidth: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Auto Width'
        TabOrder = 0
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object chbxCardsVertLines: TcxCheckBox
        Tag = 5
        Left = 75
        Top = 226
        Caption = 'Vertical Lines'
        TabOrder = 7
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object chbxCardsHorzLines: TcxCheckBox
        Tag = 4
        Left = 75
        Top = 204
        Caption = 'Horizontal Lines'
        TabOrder = 6
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object chbxCardsBorder: TcxCheckBox
        Tag = 3
        Left = 75
        Top = 182
        Caption = 'Border'
        TabOrder = 5
        Transparent = True
        OnClick = OptionsCardsClick
        Width = 200
      end
      object lblCardSpaceVert: TcxLabel
        Left = 75
        Top = 141
        Caption = 'Vertical:'
        Transparent = True
      end
      object lblCardSpaceHorz: TcxLabel
        Left = 75
        Top = 113
        Caption = 'Horizontal:'
        Transparent = True
      end
      object lblCardSpacing: TcxLabel
        Left = 10
        Top = 91
        AutoSize = False
        Caption = 'Spacing'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblCardSizes: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Sizes'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblCardFraming: TcxLabel
        Left = 10
        Top = 165
        AutoSize = False
        Caption = 'Framing'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblCardShadowDepth: TcxLabel
        Left = 75
        Top = 296
        Caption = 'Depth:'
        Transparent = True
      end
      object lblCardShadow: TcxLabel
        Left = 10
        Top = 246
        AutoSize = False
        Caption = 'Shadow'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 302
      end
      object lblCardShadowColor: TcxLabel
        Left = 75
        Top = 270
        Caption = 'Color:'
        Transparent = True
      end
      object seCardsSpaceVert: TcxSpinEdit
        Left = 153
        Top = 140
        Properties.AssignedValues.MinValue = True
        Properties.MaxValue = 20.000000000000000000
        Properties.OnChange = CardSpaceVertChanged
        TabOrder = 4
        Width = 158
      end
      object seCardsSpaceHorz: TcxSpinEdit
        Left = 153
        Top = 113
        Properties.AssignedValues.MinValue = True
        Properties.MaxValue = 20.000000000000000000
        Properties.OnChange = CardSpaceHorzChanged
        TabOrder = 3
        Width = 158
      end
      object seCardsShadowDepth: TcxSpinEdit
        Left = 153
        Top = 296
        Properties.OnChange = CardShadowDepthChanged
        TabOrder = 9
        Width = 158
      end
      object ccbxCardsShadowColor: TcxColorComboBox
        Left = 153
        Top = 268
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = CardShadowColorChanged
        TabOrder = 8
        Width = 158
      end
    end
    object tshCharts: TcxTabSheet
      Caption = 'Charts'
      ImageIndex = 6
      object imgCharts: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object chbxChartsTransparent: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Transparent'
        TabOrder = 0
        Transparent = True
        OnClick = chbxChartsTransparentClick
        Width = 200
      end
      object lblChartsOptions: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Options'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 303
      end
    end
  end
  object pnlPreview: TPanel
    Left = 335
    Top = 53
    Width = 306
    Height = 350
    BevelOuter = bvLowered
    Color = clWindow
    ParentBackground = False
    TabOrder = 1
    object PreviewGrid: TcxGrid
      Left = 5
      Top = 7
      Width = 296
      Height = 337
      TabOrder = 0
      LookAndFeel.NativeStyle = False
      RootLevelOptions.DetailTabsPosition = dtpTop
      object PreviewBandedView: TcxGridBandedTableView
        NavigatorButtons.ConfirmDelete = False
        FilterBox.CustomizeDialog = False
        FilterBox.Visible = fvAlways
        DataController.Summary.DefaultGroupSummaryItems = <
          item
            Format = 'Count = 0'
            Kind = skCount
            Position = spFooter
            Column = colVendorName
          end>
        DataController.Summary.FooterSummaryItems = <
          item
            Format = 'Count = 0'
            Kind = skCount
            Column = colVendorName
          end>
        DataController.Summary.SummaryGroups = <>
        OptionsView.ScrollBars = ssNone
        OptionsView.CellAutoHeight = True
        OptionsView.ColumnAutoWidth = True
        OptionsView.Footer = True
        OptionsView.GroupByBox = False
        OptionsView.GroupFooters = gfAlwaysVisible
        Preview.Column = colVendorCountry
        Preview.Visible = True
        OnCustomDrawColumnHeader = PreviewBandedViewCustomDrawColumnHeader
        OnCustomDrawFooterCell = PreviewBandedViewCustomDrawFooterCell
        Bands = <
          item
            Caption = 'Vendor Data'
            Width = 150
          end
          item
            Caption = 'Car Data'
          end>
        OnCustomDrawBandHeader = PreviewBandedViewCustomDrawBandHeader
        object colVendorName: TcxGridBandedColumn
          Caption = 'Name'
          PropertiesClassName = 'TcxTextEditProperties'
          Options.Filtering = False
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object colVendorLogo: TcxGridBandedColumn
          Caption = 'Logo'
          PropertiesClassName = 'TcxImageProperties'
          Properties.GraphicTransparency = gtTransparent
          OnCustomDrawCell = VendorLogoCustomDrawCell
          Options.Filtering = False
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object colVendorCountry: TcxGridBandedColumn
          PropertiesClassName = 'TcxTextEditProperties'
          Position.BandIndex = 0
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object colCarModel: TcxGridBandedColumn
          Caption = 'Model'
          PropertiesClassName = 'TcxTextEditProperties'
          Options.Filtering = False
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object colIsSUVModel: TcxGridBandedColumn
          Caption = 'SUV'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueGrayed = #39#39
          OnCustomDrawCell = IsSUVModelCustomDrawCell
          HeaderAlignmentHorz = taCenter
          Options.Filtering = False
          Width = 30
          Position.BandIndex = 1
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
      end
      object PreviewGridLevel: TcxGridLevel
        Caption = 'Cars'
      end
    end
  end
  object pmStyles: TPopupMenu
    Images = ilStylesPopup
    OnPopup = pmStylesPopup
    Left = 4
    Top = 424
    object miStyleFont: TMenuItem
      Caption = '&Font...'
      ImageIndex = 0
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
      Caption = '&Bitmap...'
      ImageIndex = 1
      ShortCut = 16463
      OnClick = StyleBackgroundBitmapClick
    end
    object miStyleBackgroundBitmapClear: TMenuItem
      Caption = 'Clear'
      ImageIndex = 3
      ShortCut = 16430
      OnClick = StyleBackgroundBitmapClearClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miStyleRestoreDefaults: TMenuItem
      Caption = 'Restore Defaults'
      OnClick = StyleRestoreDefaultsClick
    end
    object milLine: TMenuItem
      Caption = '-'
    end
    object miStylesSelectAll: TMenuItem
      Caption = 'Select A&ll'
      ShortCut = 16449
      OnClick = miStylesSelectAllClick
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
  object cxStyleRepository1: TcxStyleRepository
    Left = 60
    Top = 424
    PixelsPerInch = 96
    object styleCardShadow: TcxStyle
    end
    object styleCardBorder: TcxStyle
      AssignedValues = [svColor]
      Color = clWindow
    end
  end
  object ilStylesPopup: TcxImageList
    FormatVersion = 1
    DesignInfo = 27787296
  end
end
