inherited frmCurrencyHistory: TfrmCurrencyHistory
  Caption = 'Currency History'
  ClientHeight = 442
  ClientWidth = 1005
  Font.Height = -11
  ExplicitWidth = 1021
  ExplicitHeight = 481
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 422
    Width = 1005
    ExplicitTop = 566
    ExplicitWidth = 1123
  end
  object grCurrencyHistory: TcxGrid [1]
    Left = 0
    Top = 78
    Width = 1005
    Height = 344
    Align = alClient
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    ExplicitLeft = 8
    ExplicitTop = 72
    ExplicitWidth = 1123
    ExplicitHeight = 488
    object tvCurrencyHistory: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = dsData
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoGroupsAlwaysExpanded]
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skCount
          Position = spFooter
        end
        item
          Format = '0'
          Kind = skSum
          Position = spFooter
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0'
          Kind = skCount
        end
        item
          Format = '0'
          Kind = skSum
        end>
      DataController.Summary.SummaryGroups = <>
      FilterRow.Visible = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
      object tvCurrencyHistoryLogtime: TcxGridDBColumn
        DataBinding.FieldName = 'Logtime'
        PropertiesClassName = 'TcxDateEditProperties'
        SortIndex = 0
        SortOrder = soDescending
        Width = 149
      end
      object tvCurrencyHistoryCurrency: TcxGridDBColumn
        DataBinding.FieldName = 'Currency'
        Width = 76
      end
      object tvCurrencyHistoryDescription: TcxGridDBColumn
        DataBinding.FieldName = 'Description'
        Width = 195
      end
      object tvCurrencyHistoryRate: TcxGridDBColumn
        DataBinding.FieldName = 'Rate'
        PropertiesClassName = 'TcxCalcEditProperties'
        HeaderAlignmentHorz = taRightJustify
        Width = 87
      end
      object tvCurrencyHistoryActive: TcxGridDBColumn
        DataBinding.FieldName = 'Active'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        HeaderAlignmentHorz = taCenter
        Width = 62
      end
      object tvCurrencyHistoryCurrencySign: TcxGridDBColumn
        DataBinding.FieldName = 'CurrencySign'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        HeaderAlignmentHorz = taRightJustify
        Width = 85
      end
      object tvCurrencyHistoryDisplayFormat: TcxGridDBColumn
        DataBinding.FieldName = 'DisplayFormat'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        HeaderAlignmentHorz = taRightJustify
        Width = 145
      end
      object tvCurrencyHistoryDecimals: TcxGridDBColumn
        DataBinding.FieldName = 'Decimals'
        PropertiesClassName = 'TcxCalcEditProperties'
        HeaderAlignmentHorz = taRightJustify
        Width = 78
      end
      object tvCurrencyHistoryAction: TcxGridDBColumn
        DataBinding.FieldName = 'Action'
        Width = 111
      end
      object tvCurrencyHistorylastUpdate: TcxGridDBColumn
        DataBinding.FieldName = 'lastUpdate'
        PropertiesClassName = 'TcxDateEditProperties'
        Width = 133
      end
    end
    object lvCurrencyHistory: TcxGridLevel
      GridView = tvCurrencyHistory
    end
  end
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 1005
    Height = 78
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitTop = 482
    ExplicitWidth = 1123
    object btnExcel: TsButton
      AlignWithMargins = True
      Left = 740
      Top = 3
      Width = 128
      Height = 34
      Align = alRight
      Caption = 'Excel'
      ImageIndex = 115
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnExcelClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 858
      ExplicitHeight = 41
    end
    object btnReport: TsButton
      AlignWithMargins = True
      Left = 874
      Top = 3
      Width = 128
      Height = 34
      Align = alRight
      Caption = 'Report'
      ImageIndex = 69
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnReportClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 992
      ExplicitHeight = 41
    end
    object pnlFilter: TsPanel
      Left = 0
      Top = 40
      Width = 1005
      Height = 38
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      ExplicitWidth = 1123
      object cLabFilter: TsLabel
        Left = 19
        Top = 6
        Width = 31
        Height = 13
        Alignment = taRightJustify
        Caption = 'Filter :'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object btnClear: TsSpeedButton
        Left = 273
        Top = 3
        Width = 63
        Height = 21
        Caption = 'Clear'
        OnClick = btnClearClick
        SkinData.SkinSection = 'SPEEDBUTTON'
        Images = DImages.PngImageList1
        ImageIndex = 4
      end
      object edFilter: TsEdit
        Left = 56
        Top = 3
        Width = 215
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnChange = edFilterChange
        SkinData.SkinSection = 'EDIT'
      end
    end
    object btnRefresh: TsButton
      AlignWithMargins = True
      Left = 20
      Top = 3
      Width = 118
      Height = 34
      Margins.Left = 20
      Align = alLeft
      Caption = 'Refresh'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 3
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitHeight = 47
    end
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
  object kbmCurrencyhistory: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'RoomerRoomReservationID'
        DataType = ftInteger
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    AfterScroll = kbmCurrencyhistoryAfterScroll
    Left = 416
    Top = 359
    object kbmCurrencyhistoryLogtime: TDateTimeField
      FieldName = 'Logtime'
    end
    object kbmCurrencyhistoryCurrency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object kbmCurrencyhistoryDescription: TWideStringField
      FieldName = 'Description'
      Size = 30
    end
    object kbmCurrencyhistoryRate: TFloatField
      FieldName = 'Rate'
    end
    object kbmCurrencyhistoryActive: TBooleanField
      FieldName = 'Active'
    end
    object kbmCurrencyhistoryCurrencySign: TWideStringField
      DisplayWidth = 3
      FieldName = 'CurrencySign'
      Size = 3
    end
    object kbmCurrencyhistorylastUpdate: TDateTimeField
      FieldName = 'lastUpdate'
    end
    object kbmCurrencyhistoryDisplayFormat: TWideStringField
      FieldName = 'DisplayFormat'
    end
    object kbmCurrencyhistoryDecimals: TIntegerField
      FieldName = 'Decimals'
    end
    object kbmCurrencyhistoryAction: TWideStringField
      FieldName = 'Action'
      Size = 15
    end
  end
  object dsData: TDataSource
    DataSet = kbmCurrencyhistory
    Left = 488
    Top = 359
  end
  object grdPrinter: TdxComponentPrinter
    CurrentLink = grdPrinterLink1
    Version = 0
    Left = 672
    Top = 320
    object grdPrinterLink1: TdxGridReportLink
      Active = True
      Component = grCurrencyHistory
      PageNumberFormat = pnfNumeral
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.GrayShading = True
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 6350
      PrinterPage.Margins.Left = 5000
      PrinterPage.Margins.Right = 5000
      PrinterPage.Margins.Top = 12700
      PrinterPage.Orientation = poLandscape
      PrinterPage.PageFooter.Font.Charset = ANSI_CHARSET
      PrinterPage.PageFooter.Font.Color = clBlack
      PrinterPage.PageFooter.Font.Height = -7
      PrinterPage.PageFooter.Font.Name = 'Arial'
      PrinterPage.PageFooter.Font.Style = []
      PrinterPage.PageFooter.RightTitle.Strings = (
        '[Page # of Pages #]')
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage.ScaleMode = smFit
      PrinterPage._dxMeasurementUnits_ = 2
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 43103.580745451390000000
      ReportTitle.Font.Charset = DEFAULT_CHARSET
      ReportTitle.Font.Color = clBlack
      ReportTitle.Font.Height = -19
      ReportTitle.Font.Name = 'Arial'
      ReportTitle.Font.Style = [fsBold]
      ShrinkToPageWidth = True
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      OptionsFormatting.LookAndFeelKind = lfFlat
      OptionsFormatting.UseNativeStyles = True
      OptionsView.FilterBar = False
      BuiltInReportLink = True
    end
  end
  object timFilter: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = timFilterTimer
    Left = 200
    Top = 304
  end
end
