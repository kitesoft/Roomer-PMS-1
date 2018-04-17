inherited frmDeparturesReport: TfrmDeparturesReport
  Caption = 'Departures'
  ClientHeight = 585
  ClientWidth = 1103
  Font.Height = -11
  ExplicitWidth = 1119
  ExplicitHeight = 624
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 565
    Width = 1103
    ExplicitTop = 565
    ExplicitWidth = 1103
  end
  object pnlFilter: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1103
    Height = 156
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object btnRefresh: TsButton
      Left = 398
      Top = 9
      Width = 118
      Height = 26
      Caption = 'Refresh'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
    end
    object gbxSelectDates: TsGroupBox
      Left = 4
      Top = 2
      Width = 370
      Height = 78
      Caption = 'Select dates'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object rbToday: TsRadioButton
        Left = 4
        Top = 21
        Width = 50
        Height = 20
        Caption = 'Today'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = rbRadioButtonClick
      end
      object rbTomorrow: TsRadioButton
        Left = 4
        Top = 46
        Width = 68
        Height = 20
        Caption = 'Tomorrow'
        TabOrder = 1
        OnClick = rbRadioButtonClick
      end
      object rbManualRange: TsRadioButton
        Left = 119
        Top = 21
        Width = 114
        Height = 20
        Caption = 'Manual date range:'
        TabOrder = 2
        OnClick = rbRadioButtonClick
      end
      object dtDateFrom: TsDateEdit
        Left = 139
        Top = 46
        Width = 105
        Height = 21
        AutoSize = False
        Color = clWhite
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 3
        Text = '  -  -    '
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
        OnCloseUp = dtDateFromCloseUp
        DialogTitle = 'Date from select'
      end
      object dtDateTo: TsDateEdit
        Left = 250
        Top = 46
        Width = 105
        Height = 21
        AutoSize = False
        Color = clWhite
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 4
        Text = '  -  -    '
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
        OnCloseUp = dtDateToCloseUp
        DialogTitle = 'Date to select'
      end
    end
    object pnlExportButtons: TsPanel
      Left = 1
      Top = 86
      Width = 1101
      Height = 69
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 128
        Height = 29
        Align = alLeft
        Caption = 'Excel'
        ImageIndex = 115
        Images = DImages.PngImageList1
        TabOrder = 0
        OnClick = btnExcelClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnCheckOut: TsButton
        AlignWithMargins = True
        Left = 137
        Top = 3
        Width = 128
        Height = 29
        Align = alLeft
        Caption = 'Check out'
        ImageIndex = 46
        Images = DImages.PngImageList1
        TabOrder = 1
        OnClick = btnCheckOutClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnProfile: TsButton
        AlignWithMargins = True
        Left = 271
        Top = 3
        Width = 128
        Height = 29
        Align = alLeft
        Caption = 'Profile'
        ImageIndex = 37
        Images = DImages.PngImageList1
        TabOrder = 2
        OnClick = btnProfileClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInvoice: TsButton
        AlignWithMargins = True
        Left = 405
        Top = 3
        Width = 128
        Height = 29
        Align = alLeft
        Caption = 'Invoice'
        DropDownMenu = pmnuInvoiceMenu
        ImageIndex = 62
        Images = DImages.PngImageList1
        Style = bsSplitButton
        TabOrder = 3
        OnClick = mnuRoomInvoiceClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnPrintGrid: TsButton
        AlignWithMargins = True
        Left = 970
        Top = 3
        Width = 128
        Height = 29
        Align = alRight
        Caption = 'Report'
        ImageIndex = 69
        Images = DImages.PngImageList1
        TabOrder = 4
        OnClick = btnPrintGridClick
        SkinData.SkinSection = 'BUTTON'
      end
      object sPanel1: TsPanel
        Left = 0
        Top = 35
        Width = 1101
        Height = 34
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 5
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
    end
  end
  object grDeparturesList: TcxGrid [2]
    Left = 0
    Top = 156
    Width = 1103
    Height = 409
    Align = alClient
    PopupMenu = pnmuGridMenu
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    object tvDeparturesList: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = DeparturesListDS
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Format = '0'
          Kind = skCount
          Position = spFooter
          Column = tvDeparturesListRoom
        end
        item
          Format = '0'
          Kind = skSum
          Position = spFooter
          Column = tvDeparturesListNumGuests
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0'
          Kind = skCount
          Column = tvDeparturesListRoom
        end
        item
          Format = '0'
          Kind = skSum
          Column = tvDeparturesListNumGuests
        end>
      DataController.Summary.SummaryGroups = <>
      FilterRow.Visible = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
      object tvDeparturesListRoom: TcxGridDBColumn
        DataBinding.FieldName = 'Room'
        SortIndex = 0
        SortOrder = soDescending
        Width = 55
      end
      object tvDeparturesListGuestName: TcxGridDBColumn
        DataBinding.FieldName = 'GuestName'
        Width = 168
      end
      object tvDeparturesListRoomerReservationId: TcxGridDBColumn
        Caption = 'Reservation ID'
        DataBinding.FieldName = 'RoomerReservationId'
        PropertiesClassName = 'TcxLabelProperties'
        Properties.Alignment.Horz = taCenter
        Width = 65
      end
      object tvDeparturesListCompanyName: TcxGridDBColumn
        Caption = 'Company Name'
        DataBinding.FieldName = 'CompanyName'
        Width = 136
      end
      object tvDeparturesListArrival: TcxGridDBColumn
        DataBinding.FieldName = 'Arrival'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.ShowTime = False
        Width = 73
      end
      object tvDeparturesListDeparture: TcxGridDBColumn
        DataBinding.FieldName = 'Departure'
        Width = 75
      end
      object tvDeparturesListRoomType: TcxGridDBColumn
        DataBinding.FieldName = 'RoomType'
        PropertiesClassName = 'TcxLabelProperties'
        Properties.Alignment.Horz = taCenter
        Width = 72
      end
      object tvDeparturesListNumGuests: TcxGridDBColumn
        Caption = 'Guests'
        DataBinding.FieldName = 'NumGuests'
        HeaderAlignmentHorz = taRightJustify
        Width = 74
      end
      object tvDeparturesListAverageRatePerNight: TcxGridDBColumn
        Caption = 'Rate Amount'
        DataBinding.FieldName = 'AverageRatePerNight'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvDeparturesList2AverageRatePerNightGetProperties
        HeaderAlignmentHorz = taRightJustify
        Width = 94
      end
      object tvDeparturesListBalance: TcxGridDBColumn
        Caption = 'Room balance'
        DataBinding.FieldName = 'Balance'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvDeparturesListGroupInvoiceBalanceGetProperties
        HeaderAlignmentHorz = taRightJustify
        HeaderGlyphAlignmentHorz = taRightJustify
        Options.Editing = False
        Width = 75
      end
      object tvDeparturesListGroupAccount: TcxGridDBColumn
        Caption = 'Group'
        DataBinding.FieldName = 'GroupAccount'
        PropertiesClassName = 'TcxCheckBoxProperties'
        HeaderAlignmentHorz = taCenter
        Options.Editing = False
        Width = 48
      end
      object tvDeparturesListGroupInvoiceBalance: TcxGridDBColumn
        Caption = 'Group Balance'
        DataBinding.FieldName = 'GroupInvoiceBalance'
        OnGetProperties = tvDeparturesListGroupInvoiceBalanceGetProperties
        HeaderAlignmentHorz = taRightJustify
        Options.Editing = False
        Width = 78
      end
      object tvDeparturesListExpectedCheckOutTime: TcxGridDBColumn
        Caption = 'Expected COT'
        DataBinding.FieldName = 'ExpectedCheckOutTime'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taCenter
        Width = 86
      end
    end
    object lvDeparturesList: TcxGridLevel
      GridView = tvDeparturesList
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 616
    Top = 40
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
  object kbmDeparturesList: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'CheckOutDate'
        DataType = ftDate
      end
      item
        Name = 'RoomerReservationId'
        DataType = ftInteger
      end
      item
        Name = 'Room'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RoomType'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'GuestName'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'NumGuests'
        DataType = ftInteger
      end
      item
        Name = 'Arrival'
        DataType = ftDate
      end
      item
        Name = 'Departure'
        DataType = ftDate
      end
      item
        Name = 'ExpectedCheckOutTime'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Customer'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'CompanyName'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'NumNights'
        DataType = ftInteger
      end
      item
        Name = 'AverageRatePerNight'
        DataType = ftFloat
      end
      item
        Name = 'Balance'
        DataType = ftFloat
      end
      item
        Name = 'RoomerRoomReservationID'
        DataType = ftInteger
      end
      item
        Name = 'GroupAccount'
        DataType = ftBoolean
      end
      item
        Name = 'GroupInvoiceBalance'
        DataType = ftFloat
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
    AfterScroll = kbmDeparturesListAfterScroll
    Left = 448
    Top = 231
  end
  object DeparturesListDS: TDataSource
    DataSet = kbmDeparturesList
    Left = 448
    Top = 279
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 176
    Top = 240
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
  end
  object pmnuInvoiceMenu: TPopupMenu
    Images = DImages.cxSmallImagesFlat
    Left = 48
    Top = 272
    object R1: TMenuItem
      Caption = 'Room Invoice'
      Default = True
      ImageIndex = 62
      OnClick = mnuRoomInvoiceClick
    end
    object G1: TMenuItem
      Caption = 'Group Invoice'
      ImageIndex = 60
      OnClick = mnuGroupInvoiceClick
    end
  end
  object pnmuGridMenu: TPopupMenu
    Left = 48
    Top = 328
    object mnuCheckin: TMenuItem
      Caption = 'Check in'
      OnClick = btnCheckOutClick
    end
    object mnuProfile: TMenuItem
      Caption = 'Profile'
      OnClick = btnProfileClick
    end
    object mnuInvoice: TMenuItem
      Caption = 'Invoice'
      object mnuRoomInvoice: TMenuItem
        Caption = 'Room invoice'
        OnClick = mnuRoomInvoiceClick
      end
      object mnuGroupInvoice: TMenuItem
        Caption = 'Group invoice'
        OnClick = mnuGroupInvoiceClick
      end
    end
  end
  object grdPrinter: TdxComponentPrinter
    CurrentLink = grdPrinterLink1
    Version = 0
    Left = 672
    Top = 320
    object grdPrinterLink1: TdxGridReportLink
      Active = True
      Component = grDeparturesList
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
      ReportDocument.CreationDate = 43206.659886203710000000
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
      OptionsExpanding.ExpandGroupRows = True
      OptionsFormatting.LookAndFeelKind = lfFlat
      OptionsFormatting.UseNativeStyles = True
      OptionsOnEveryPage.Footers = False
      OptionsOnEveryPage.FilterBar = False
      OptionsView.FilterBar = False
      StyleRepository = cxStyleRepository2
      Styles.StyleSheet = dxGridReportLinkStyleSheet1
      BuiltInReportLink = True
    end
  end
  object cxStyleRepository2: TcxStyleRepository
    Left = 784
    Top = 272
    PixelsPerInch = 96
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -7
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = 16053492
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -7
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -7
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnShadow
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -7
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -7
      Font.Name = 'Arial Black'
      Font.Style = [fsBold]
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -9
      Font.Name = 'Arial'
      Font.Style = []
    end
    object dxGridReportLinkStyleSheet1: TdxGridReportLinkStyleSheet
      Caption = 'Arial font'
      Styles.BandHeader = cxStyle2
      Styles.Caption = cxStyle3
      Styles.CardCaptionRow = cxStyle4
      Styles.CardRowCaption = cxStyle5
      Styles.Content = cxStyle6
      Styles.ContentEven = cxStyle7
      Styles.ContentOdd = cxStyle8
      Styles.FilterBar = cxStyle9
      Styles.Footer = cxStyle10
      Styles.Group = cxStyle11
      Styles.Header = cxStyle12
      Styles.Preview = cxStyle13
      Styles.Selection = cxStyle14
      BuiltIn = True
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
