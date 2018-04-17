inherited frmArrivalsReport: TfrmArrivalsReport
  Caption = 'Arrivals'
  ClientHeight = 586
  ClientWidth = 1123
  Font.Height = -11
  ExplicitWidth = 1139
  ExplicitHeight = 625
  PixelsPerInch = 96
  TextHeight = 13
  object pnlFilter: TsPanel [0]
    Left = 0
    Top = 0
    Width = 1123
    Height = 167
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object btnRefresh: TsButton
      Left = 378
      Top = 14
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
      Top = 0
      Width = 368
      Height = 80
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
        Left = 122
        Top = 47
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
        Left = 233
        Top = 45
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
      Top = 88
      Width = 1121
      Height = 78
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 128
        Height = 41
        Align = alLeft
        Caption = 'Excel'
        ImageIndex = 115
        Images = DImages.PngImageList1
        TabOrder = 0
        OnClick = btnExcelClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnCheckIn: TsButton
        AlignWithMargins = True
        Left = 137
        Top = 3
        Width = 128
        Height = 41
        Align = alLeft
        Caption = 'Check in'
        ImageIndex = 45
        Images = DImages.PngImageList1
        TabOrder = 1
        OnClick = btnCheckInClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnProfile: TsButton
        AlignWithMargins = True
        Left = 271
        Top = 3
        Width = 128
        Height = 41
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
        Left = 539
        Top = 3
        Width = 128
        Height = 41
        Align = alLeft
        Caption = 'Invoice'
        DropDownMenu = pmnuInvoiceMenu
        ImageIndex = 62
        Images = DImages.PngImageList1
        Style = bsSplitButton
        TabOrder = 4
        OnClick = mnuRoomInvoiceClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnReport: TsButton
        AlignWithMargins = True
        Left = 990
        Top = 3
        Width = 128
        Height = 41
        Align = alRight
        Caption = 'Report'
        ImageIndex = 69
        Images = DImages.PngImageList1
        TabOrder = 5
        OnClick = btnReportClick
        SkinData.SkinSection = 'BUTTON'
      end
      object sPanel1: TsPanel
        Left = 0
        Top = 47
        Width = 1121
        Height = 31
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 6
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
      object btnAllocateRoom: TsButton
        AlignWithMargins = True
        Left = 405
        Top = 3
        Width = 128
        Height = 41
        Align = alLeft
        Caption = 'Allocate Room'
        ImageIndex = 47
        Images = DImages.PngImageList1
        TabOrder = 3
        OnClick = btnAllocateRoomClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
  end
  object grArrivalsList: TcxGrid [1]
    Left = 0
    Top = 167
    Width = 1123
    Height = 399
    Align = alClient
    PopupMenu = pnmuGridMenu
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    object grArrivalsListDBTableView1: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      OnCellDblClick = grArrivalsListDBTableView1CellDblClick
      DataController.DataSource = ArrivalsListDS
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoGroupsAlwaysExpanded]
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skCount
          Position = spFooter
          Column = grArrivalsListDBTableView1Room
        end
        item
          Format = '0'
          Kind = skSum
          Position = spFooter
          Column = grArrivalsListDBTableView1NumGuests
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0'
          Kind = skCount
          Column = grArrivalsListDBTableView1Room
        end
        item
          Format = '0'
          Kind = skSum
          Column = grArrivalsListDBTableView1NumGuests
        end>
      DataController.Summary.SummaryGroups = <>
      FilterRow.Visible = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
      Styles.Group = cxStyle1
      Styles.GroupSummary = cxStyle1
      Styles.StyleSheet = cxssRoomerGridTableView
      object grArrivalsListDBTableView1Room: TcxGridDBColumn
        DataBinding.FieldName = 'Room'
        Options.Editing = False
      end
      object grArrivalsListDBTableView1GuestName: TcxGridDBColumn
        Caption = 'Guest name'
        DataBinding.FieldName = 'GuestName'
        Options.Editing = False
        Width = 263
      end
      object grArrivalsListDBTableView1RoomerReservationID: TcxGridDBColumn
        Caption = 'Reservation ID'
        DataBinding.FieldName = 'RoomerReservationID'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taCenter
        Options.Editing = False
        Width = 83
      end
      object grArrivalsListDBTableView1CompanyCode: TcxGridDBColumn
        Caption = 'Company code'
        DataBinding.FieldName = 'CompanyCode'
        Options.Editing = False
      end
      object grArrivalsListDBTableView1Arrival: TcxGridDBColumn
        DataBinding.FieldName = 'Arrival'
        Options.Editing = False
      end
      object grArrivalsListDBTableView1Departure: TcxGridDBColumn
        DataBinding.FieldName = 'Departure'
        Options.Editing = False
      end
      object grArrivalsListDBTableView1Roomtype: TcxGridDBColumn
        Caption = 'Room type'
        DataBinding.FieldName = 'Roomtype'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taCenter
        Options.Editing = False
        Width = 66
      end
      object grArrivalsListDBTableView1NumGuests: TcxGridDBColumn
        Caption = 'Num guests'
        DataBinding.FieldName = 'NumGuests'
        Options.Editing = False
      end
      object grArrivalsListDBTableView1AverageRoomRate: TcxGridDBColumn
        Caption = 'Average Rate'
        DataBinding.FieldName = 'AverageRoomRate'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = grArrivalsListDBTableView1AverageRoomRateGetProperties
        Options.Editing = False
        Width = 82
      end
      object grArrivalsListDBTableView1ExpectedTimeOfArrival: TcxGridDBColumn
        Caption = 'Expected TOA'
        DataBinding.FieldName = 'ExpectedTimeOfArrival'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taCenter
        OnGetDisplayText = grArrivalsListDBTableView1ExpectedTimeOfArrivalGetDisplayText
        HeaderAlignmentHorz = taCenter
        Options.Editing = False
        Width = 88
      end
      object grArrivalsListDBTableView1RoomerRoomReservationID: TcxGridDBColumn
        Caption = 'Room Res ID'
        DataBinding.FieldName = 'RoomerRoomReservationID'
        Visible = False
        Options.Editing = False
        SortIndex = 0
        SortOrder = soAscending
      end
    end
    object lvArrivalsListLevel1: TcxGridLevel
      GridView = grArrivalsListDBTableView1
    end
  end
  inherited sbStatusBar: TsStatusBar
    Top = 566
    Width = 1123
    ExplicitTop = 566
    ExplicitWidth = 1123
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
  object kbmArrivalsList: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Room'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Roomtype'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RoomerReservationID'
        DataType = ftInteger
      end
      item
        Name = 'GuestName'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'CompanyCode'
        DataType = ftString
        Size = 15
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
        Name = 'NumGuests'
        DataType = ftInteger
      end
      item
        Name = 'AverageRoomRate'
        DataType = ftFloat
      end
      item
        Name = 'ExpectedTimeOfArrival'
        DataType = ftString
        Size = 5
      end
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
    AfterScroll = kbmArrivalsListAfterScroll
    Left = 416
    Top = 359
    object kbmArrivalsListfldRoom: TStringField
      FieldName = 'Room'
      Size = 10
    end
    object kbmArrivalsListfldRoomtype: TStringField
      FieldName = 'Roomtype'
    end
    object kbmArrivalsListfldRoomerReservationID: TIntegerField
      FieldName = 'RoomerReservationID'
    end
    object kbmArrivalsListfldGuestName: TStringField
      FieldName = 'GuestName'
      Size = 100
    end
    object kbmArrivalsListfldCompanyCode: TStringField
      FieldName = 'CompanyCode'
      Size = 15
    end
    object kbmArrivalsListfldArrival: TDateField
      FieldName = 'Arrival'
    end
    object kbmArrivalsListfldDeparture: TDateField
      FieldName = 'Departure'
    end
    object kbmArrivalsListfldNumGuests: TIntegerField
      FieldName = 'NumGuests'
    end
    object kbmArrivalsListAverageRoomRate: TFloatField
      FieldName = 'AverageRoomRate'
      currency = True
    end
    object kbmArrivalsListExpectedTimeOfArrival: TStringField
      FieldName = 'ExpectedTimeOfArrival'
      Size = 5
    end
    object kbmArrivalsListRoomerRoomReservationID: TIntegerField
      FieldName = 'RoomerRoomReservationID'
    end
  end
  object ArrivalsListDS: TDataSource
    DataSet = kbmArrivalsList
    Left = 488
    Top = 359
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
    Left = 480
    Top = 224
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
    Left = 184
    Top = 368
    object mnuCheckin: TMenuItem
      Caption = 'Check in'
      OnClick = btnCheckInClick
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
      Component = grArrivalsList
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
      ReportDocument.CreationDate = 43206.656396863430000000
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
      StyleRepository = cxStyleRepository2
      Styles.StyleSheet = dxGridReportLinkStyleSheet1
      BuiltInReportLink = True
    end
  end
  object cxStyleRepository2: TcxStyleRepository
    Left = 744
    Top = 320
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
