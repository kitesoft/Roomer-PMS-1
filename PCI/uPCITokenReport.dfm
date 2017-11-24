inherited frmPCITokenReport: TfrmPCITokenReport
  Left = 961
  Top = 264
  Caption = 'Creditcard token usage reports'
  ClientHeight = 641
  ClientWidth = 1116
  Font.Height = -11
  OnClose = FormClose
  OnCreate = FormCreate
  ExplicitWidth = 1132
  ExplicitHeight = 680
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 621
    Width = 1116
    ExplicitTop = 621
    ExplicitWidth = 1116
  end
  object pageMain: TsPageControl [1]
    Left = 0
    Top = 81
    Width = 1116
    Height = 540
    ActivePage = sheetMain
    Align = alClient
    TabOrder = 0
    SkinData.SkinSection = 'PAGECONTROL'
    object sheetMain: TsTabSheet
      Caption = 'Main'
      TabVisible = False
      object Panel1: TsPanel
        Left = 0
        Top = 0
        Width = 1108
        Height = 43
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object btnExcelS1: TsButton
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Excel'
          Enabled = False
          ImageIndex = 115
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnExcelS1Click
          SkinData.SkinSection = 'BUTTON'
        end
        object btnReportS1: TsButton
          AlignWithMargins = True
          Left = 137
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Report'
          Enabled = False
          ImageIndex = 69
          Images = DImages.PngImageList1
          TabOrder = 1
          OnClick = btnReportS1Click
          SkinData.SkinSection = 'BUTTON'
        end
        object chkPageBreak: TsCheckBox
          AlignWithMargins = True
          Left = 405
          Top = 3
          Width = 211
          Height = 37
          Caption = 'Page break before summary on report'
          Align = alLeft
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          SkinData.SkinSection = 'CHECKBOX'
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object btnShowReservation: TsButton
          AlignWithMargins = True
          Left = 271
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Reservaton'
          Enabled = False
          ImageIndex = 56
          Images = DImages.PngImageList1
          TabOrder = 3
          OnClick = btnShowReservationClick
          SkinData.SkinSection = 'BUTTON'
        end
      end
      object gTokenUsage: TcxGrid
        Left = 0
        Top = 43
        Width = 1108
        Height = 487
        Align = alClient
        BevelOuter = bvNone
        BorderStyle = cxcbsNone
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        object tvTokenUsage: TcxGridDBTableView
          OnDblClick = tvTokenUsageDblClick
          Navigator.Buttons.CustomButtons = <>
          Navigator.Buttons.First.Visible = True
          Navigator.Buttons.PriorPage.Visible = True
          Navigator.Buttons.Prior.Visible = True
          Navigator.Buttons.Next.Visible = True
          Navigator.Buttons.NextPage.Visible = True
          Navigator.Buttons.Last.Visible = True
          Navigator.Buttons.Insert.Enabled = False
          Navigator.Buttons.Insert.Visible = False
          Navigator.Buttons.Append.Enabled = False
          Navigator.Buttons.Append.Visible = False
          Navigator.Buttons.Delete.Enabled = False
          Navigator.Buttons.Delete.Visible = False
          Navigator.Buttons.Edit.Enabled = False
          Navigator.Buttons.Edit.Visible = False
          Navigator.Buttons.Post.Enabled = False
          Navigator.Buttons.Post.Visible = False
          Navigator.Buttons.Cancel.Enabled = False
          Navigator.Buttons.Cancel.Visible = True
          Navigator.Buttons.Refresh.Visible = True
          Navigator.Buttons.SaveBookmark.Visible = True
          Navigator.Buttons.GotoBookmark.Visible = True
          Navigator.Buttons.Filter.Visible = True
          DataController.DataSource = mTokenUsageDS
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Format = ',0;-,0'
              Kind = skSum
              Position = spFooter
              Column = tvTokenUsageCREATIONS
            end
            item
              Format = ',0;-,0'
              Kind = skSum
              Column = tvTokenUsageVIEWS
            end
            item
              Format = ',0;-,0'
              Kind = skSum
              Column = tvTokenUsageCharges
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'Total'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalWOVAT'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalVAT'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalStayTax'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalStayTaxNights'
            end
            item
              Kind = skCount
              FieldName = 'InvoiceNumber'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'totalStayTaxExcluted'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'TotalTax'
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTokenUsageCOST_IN_EUR
            end
            item
              Format = ',0;-,0'
              Kind = skSum
              Column = tvTokenUsageVIEWS
            end
            item
              Format = ',0;-,0'
              Kind = skSum
              Column = tvTokenUsageCREATIONS
            end
            item
              Format = ',0;-,0'
              Kind = skSum
              Column = tvTokenUsageCharges
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.IncSearch = True
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.Footer = True
          OptionsView.HeaderAutoHeight = True
          OptionsView.Indicator = True
          Styles.StyleSheet = cxssRoomerGridTableView
          object tvTokenUsageRecId: TcxGridDBColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
          end
          object tvTokenUsageTSTAMP: TcxGridDBColumn
            Caption = 'Time of event'
            DataBinding.FieldName = 'TSTAMP'
            Options.Editing = False
          end
          object tvTokenUsageEVENT: TcxGridDBColumn
            Caption = 'Event'
            DataBinding.FieldName = 'EVENT'
            Options.Editing = False
          end
          object tvTokenUsageCOST_IN_EUR: TcxGridDBColumn
            Caption = 'Cost in EUR'
            DataBinding.FieldName = 'COST_IN_EUR'
            Options.Editing = False
            Width = 90
          end
          object tvTokenUsageReservation: TcxGridDBColumn
            DataBinding.FieldName = 'Reservation'
            Options.Editing = False
            Width = 92
          end
          object tvTokenUsageRoom: TcxGridDBColumn
            DataBinding.FieldName = 'Room'
            Options.Editing = False
            Width = 61
          end
          object tvTokenUsageRoomType: TcxGridDBColumn
            Caption = 'Room Type'
            DataBinding.FieldName = 'RoomType'
            Options.Editing = False
            Width = 76
          end
          object tvTokenUsageCustomer: TcxGridDBColumn
            DataBinding.FieldName = 'Customer'
            Options.Editing = False
          end
          object tvTokenUsageName: TcxGridDBColumn
            Caption = 'Customer Name'
            DataBinding.FieldName = 'Name'
            Options.Editing = False
            Width = 157
          end
          object tvTokenUsageGuestName: TcxGridDBColumn
            DataBinding.FieldName = 'GuestName'
            Options.Editing = False
            Width = 166
          end
          object tvTokenUsageCREATIONS: TcxGridDBColumn
            Caption = 'Creations'
            DataBinding.FieldName = 'CREATIONS'
            Options.Editing = False
            Width = 66
          end
          object tvTokenUsageVIEWS: TcxGridDBColumn
            Caption = 'Views'
            DataBinding.FieldName = 'VIEWS'
            Options.Editing = False
            Width = 58
          end
          object tvTokenUsageCharges: TcxGridDBColumn
            DataBinding.FieldName = 'Charges'
          end
          object tvTokenUsageUSER_ID: TcxGridDBColumn
            Caption = 'User'
            DataBinding.FieldName = 'USER_ID'
            Options.Editing = False
            Width = 61
          end
          object tvTokenUsageIP_NUMBER: TcxGridDBColumn
            Caption = 'IP Number'
            DataBinding.FieldName = 'IP_NUMBER'
            Options.Editing = False
            Width = 118
          end
          object tvTokenUsageMACHINE_NAME: TcxGridDBColumn
            Caption = 'Machine name'
            DataBinding.FieldName = 'MACHINE_NAME'
            Options.Editing = False
            Width = 194
          end
          object tvTokenUsageContactName: TcxGridDBColumn
            DataBinding.FieldName = 'ContactName'
            Options.Editing = False
            Width = 168
          end
          object tvTokenUsageArrival: TcxGridDBColumn
            DataBinding.FieldName = 'Arrival'
            Options.Editing = False
          end
          object tvTokenUsageDeparture: TcxGridDBColumn
            DataBinding.FieldName = 'Departure'
            Options.Editing = False
            Width = 76
          end
          object tvTokenUsageBookingId: TcxGridDBColumn
            DataBinding.FieldName = 'BookingId'
            Options.Editing = False
            Width = 151
          end
          object tvTokenUsageRoomClass: TcxGridDBColumn
            DataBinding.FieldName = 'RoomClass'
            Options.Editing = False
            Width = 105
          end
          object tvTokenUsageNumGuests: TcxGridDBColumn
            DataBinding.FieldName = 'NumGuests'
            Options.Editing = False
            Width = 73
          end
        end
        object lvTokenUsage: TcxGridLevel
          GridView = tvTokenUsage
        end
      end
    end
  end
  object Panel3: TsPanel [2]
    Left = 0
    Top = 0
    Width = 1116
    Height = 81
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object gbxPeriodSelection: TsGroupBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 189
      Height = 75
      Align = alLeft
      Caption = 'Select month and year'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object cbxMonth: TsComboBox
        Left = 32
        Top = 22
        Width = 121
        Height = 21
        Alignment = taLeftJustify
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = 0
        ParentFont = False
        TabOrder = 0
        Text = 'Choose month ...'
        OnCloseUp = cbxYearCloseUp
        Items.Strings = (
          'Choose month ...'
          'January'
          'February'
          'March'
          'April'
          'may'
          'June'
          'July'
          'August'
          'September'
          'October'
          'November'
          'December')
      end
      object cbxYear: TsComboBox
        Left = 32
        Top = 50
        Width = 121
        Height = 21
        Alignment = taLeftJustify
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = 0
        ParentFont = False
        TabOrder = 1
        Text = 'Choose year ...'
        OnCloseUp = cbxYearCloseUp
        Items.Strings = (
          'Choose year ...'
          '2011'
          '2012'
          '2013'
          '2014'
          '2015'
          '2016'
          '2017'
          '2018'
          '2020')
      end
    end
    object btnRefresh: TsButton
      Left = 198
      Top = 17
      Width = 100
      Height = 37
      Caption = 'Refresh ALL'
      Enabled = False
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
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
  object mTokenUsage: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    AfterScroll = mTokenUsageAfterScroll
    Left = 256
    Top = 321
    object mTokenUsageReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mTokenUsageCustomer: TWideStringField
      FieldName = 'Customer'
      Size = 15
    end
    object mTokenUsageName: TWideStringField
      FieldName = 'Name'
      Size = 100
    end
    object mTokenUsageGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 40
    end
    object mTokenUsageVIEWS: TIntegerField
      FieldName = 'VIEWS'
    end
    object mTokenUsageCREATIONS: TIntegerField
      FieldName = 'CREATIONS'
    end
    object mTokenUsageUSER_ID: TWideStringField
      FieldName = 'USER_ID'
      Size = 25
    end
    object mTokenUsageCharges: TIntegerField
      FieldName = 'Charges'
    end
    object mTokenUsageIP_NUMBER: TStringField
      FieldName = 'IP_NUMBER'
      Size = 32
    end
    object mTokenUsageMACHINE_NAME: TStringField
      FieldName = 'MACHINE_NAME'
      Size = 128
    end
    object mTokenUsageEVENT: TStringField
      FieldName = 'EVENT'
      Size = 16
    end
    object mTokenUsageCOST_IN_EUR: TFloatField
      FieldName = 'COST_IN_EUR'
    end
    object mTokenUsageTSTAMP: TDateTimeField
      FieldName = 'TSTAMP'
    end
    object mTokenUsageContactName: TWideStringField
      FieldName = 'ContactName'
      Size = 64
    end
    object mTokenUsageArrival: TDateField
      FieldName = 'Arrival'
    end
    object mTokenUsageDeparture: TDateField
      FieldName = 'Departure'
    end
    object mTokenUsageBookingId: TWideStringField
      FieldName = 'BookingId'
      Size = 64
    end
    object mTokenUsageRoom: TWideStringField
      FieldName = 'Room'
      Size = 25
    end
    object mTokenUsageRoomType: TWideStringField
      FieldName = 'RoomType'
      Size = 25
    end
    object mTokenUsageRoomClass: TWideStringField
      FieldName = 'RoomClass'
      Size = 25
    end
    object mTokenUsageNumGuests: TIntegerField
      FieldName = 'NumGuests'
    end
  end
  object mTokenUsageDS: TDataSource
    DataSet = mTokenUsage
    Left = 344
    Top = 321
  end
  object rptbLodgingtaxList: TppReport
    AutoStop = False
    DataPipeline = dplMTokenUsage
    PassSetting = psTwoPass
    PrinterSetup.BinName = 'Default'
    PrinterSetup.DocumentName = 'Lodgingtax'
    PrinterSetup.PaperName = 'A4'
    PrinterSetup.PrinterName = 'Default'
    PrinterSetup.SaveDeviceSettings = False
    PrinterSetup.mmMarginBottom = 6350
    PrinterSetup.mmMarginLeft = 6350
    PrinterSetup.mmMarginRight = 6350
    PrinterSetup.mmMarginTop = 6350
    PrinterSetup.mmPaperHeight = 297000
    PrinterSetup.mmPaperWidth = 210000
    PrinterSetup.PaperSize = 9
    AllowPrintToArchive = True
    AllowPrintToFile = True
    ArchiveFileName = '($MyDocuments)\ReportArchive.raf'
    DeviceType = 'Screen'
    DefaultFileDeviceType = 'PDF'
    EmailSettings.ReportFormat = 'PDF'
    LanguageID = 'Default'
    ModalCancelDialog = False
    OutlineSettings.CreateNode = True
    OutlineSettings.CreatePageNodes = True
    OutlineSettings.Enabled = True
    OutlineSettings.Visible = True
    PDFSettings.EmbedFontOptions = [efUseSubset]
    PDFSettings.EncryptSettings.AllowCopy = True
    PDFSettings.EncryptSettings.AllowInteract = True
    PDFSettings.EncryptSettings.AllowModify = True
    PDFSettings.EncryptSettings.AllowPrint = True
    PDFSettings.EncryptSettings.Enabled = False
    PDFSettings.FontEncoding = feAnsi
    PDFSettings.ImageCompressionLevel = 25
    RTFSettings.DefaultFont.Charset = DEFAULT_CHARSET
    RTFSettings.DefaultFont.Color = clWindowText
    RTFSettings.DefaultFont.Height = -13
    RTFSettings.DefaultFont.Name = 'Arial'
    RTFSettings.DefaultFont.Style = []
    TextFileName = '($MyDocuments)\Report.pdf'
    TextSearchSettings.DefaultString = '<FindText>'
    TextSearchSettings.Enabled = True
    XLSSettings.AppName = 'ReportBuilder'
    XLSSettings.Author = 'ReportBuilder'
    XLSSettings.Subject = 'Report'
    XLSSettings.Title = 'Report'
    Left = 48
    Top = 273
    Version = '14.07'
    mmColumnWidth = 0
    DataPipelineName = 'dplMTokenUsage'
    object ppHeaderBand1: TppHeaderBand
      BeforePrint = ppHeaderBand1BeforePrint
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 20373
      mmPrintPosition = 0
      object rlabHeader: TppLabel
        UserName = 'rlabHeader'
        Caption = 'Credit-card token events'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 18
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 7535
        mmLeft = 529
        mmTop = 529
        mmWidth = 74253
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel4: TppLabel
        UserName = 'Label4'
        Caption = 'Period :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 1323
        mmTop = 9525
        mmWidth = 11811
        BandType = 0
        LayerName = Foreground
      end
      object rlabMionthAndYear: TppLabel
        UserName = 'rLabFrom'
        Caption = '07/2015'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 17727
        mmTop = 9790
        mmWidth = 11557
        BandType = 0
        LayerName = Foreground
      end
      object rLabHotelName: TppLabel
        UserName = 'rLabHotelName'
        Caption = 'Hotel name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 180182
        mmTop = 529
        mmWidth = 15579
        BandType = 0
        LayerName = Foreground
      end
      object rLabTimeCreated: TppLabel
        UserName = 'rLabTimeCreated'
        Caption = '01.01.2010 22:33'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 170773
        mmTop = 9525
        mmWidth = 25019
        BandType = 0
        LayerName = Foreground
      end
      object rlabUser: TppLabel
        UserName = 'rLabUser'
        Caption = 'hj'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 192956
        mmTop = 4763
        mmWidth = 2836
        BandType = 0
        LayerName = Foreground
      end
      object ppLine1: TppLine
        UserName = 'Line1'
        Border.Weight = 1.000000000000000000
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 265
        mmLeft = 0
        mmTop = 13758
        mmWidth = 197300
        BandType = 0
        LayerName = Foreground
      end
      object rlabCaption_number: TppLabel
        UserName = 'Label11'
        AutoSize = False
        Caption = 'Time of event'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 1323
        mmTop = 16140
        mmWidth = 20373
        BandType = 0
        LayerName = Foreground
      end
      object ppLine2: TppLine
        UserName = 'Line2'
        Border.Weight = 1.000000000000000000
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 265
        mmLeft = 0
        mmTop = 20108
        mmWidth = 197300
        BandType = 0
        LayerName = Foreground
      end
      object rlabCaption_date: TppLabel
        UserName = 'rlabCaption_date'
        AutoSize = False
        Caption = 'Event'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 31485
        mmTop = 16140
        mmWidth = 14552
        BandType = 0
        LayerName = Foreground
      end
      object rlabCaption_customer: TppLabel
        UserName = 'rlabCaption_customer'
        AutoSize = False
        Caption = 'Cost [EUR]'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3387
        mmLeft = 47890
        mmTop = 16140
        mmWidth = 15875
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel18: TppLabel
        UserName = 'Label18'
        AutoSize = False
        Caption = 'Customer'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 114036
        mmTop = 16140
        mmWidth = 17198
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel10: TppLabel
        UserName = 'Label10'
        AutoSize = False
        Caption = 'Reservation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3387
        mmLeft = 67998
        mmTop = 16140
        mmWidth = 18256
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel1: TppLabel
        UserName = 'Label1'
        AutoSize = False
        Caption = 'Customer name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 132557
        mmTop = 16140
        mmWidth = 30956
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel6: TppLabel
        UserName = 'Label6'
        AutoSize = False
        Caption = 'Guest name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 164836
        mmTop = 16140
        mmWidth = 30956
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel11: TppLabel
        UserName = 'Label12'
        AutoSize = False
        Caption = 'User'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3387
        mmLeft = 88106
        mmTop = 16140
        mmWidth = 23813
        BandType = 0
        LayerName = Foreground
      end
    end
    object ppDetailBand1: TppDetailBand
      Background1.Brush.Style = bsClear
      Background2.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 4498
      mmPrintPosition = 0
      object ppDBText2: TppDBText
        UserName = 'DBText2'
        DataField = 'COST_IN_EUR'
        DataPipeline = dplMTokenUsage
        DisplayFormat = '#,0.00;-#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 47890
        mmTop = 794
        mmWidth = 15875
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText3: TppDBText
        UserName = 'DBText3'
        DataField = 'EVENT'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 31485
        mmTop = 794
        mmWidth = 14552
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText4: TppDBText
        UserName = 'DBText4'
        DataField = 'Customer'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 114036
        mmTop = 794
        mmWidth = 17198
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText9: TppDBText
        UserName = 'DBText9'
        DataField = 'Reservation'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 65617
        mmTop = 794
        mmWidth = 20638
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText1: TppDBText
        UserName = 'DBText1'
        DataField = 'TSTAMP'
        DataPipeline = dplMTokenUsage
        DisplayFormat = 'dd-mmm-yyyy hh:nn:ss'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 1323
        mmTop = 794
        mmWidth = 28575
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText5: TppDBText
        UserName = 'DBText5'
        DataField = 'Name'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 132557
        mmTop = 794
        mmWidth = 30956
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText6: TppDBText
        UserName = 'DBText6'
        DataField = 'GuestName'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 164836
        mmTop = 794
        mmWidth = 30956
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText7: TppDBText
        UserName = 'DBText7'
        DataField = 'USER_ID'
        DataPipeline = dplMTokenUsage
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3260
        mmLeft = 88106
        mmTop = 794
        mmWidth = 23813
        BandType = 4
        LayerName = Foreground
      end
    end
    object ppFooterBand1: TppFooterBand
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 8202
      mmPrintPosition = 0
      object ppSystemVariable2: TppSystemVariable
        UserName = 'SystemVariable2'
        VarType = vtPageSetDesc
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        Transparent = True
        mmHeight = 3598
        mmLeft = 3969
        mmTop = 4498
        mmWidth = 720
        BandType = 8
        LayerName = Foreground
      end
    end
    object ppSummaryBand1: TppSummaryBand
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 32808
      mmPrintPosition = 0
      object ppLabel3: TppLabel
        UserName = 'Label3'
        Caption = 'Summery'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 12
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 5027
        mmLeft = 1323
        mmTop = 10054
        mmWidth = 19315
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel2: TppLabel
        UserName = 'Label2'
        AutoSize = False
        Caption = 'Number'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 1588
        mmTop = 20902
        mmWidth = 23283
        BandType = 7
        LayerName = Foreground
      end
      object ppLine3: TppLine
        UserName = 'Line3'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 25929
        mmTop = 16140
        mmWidth = 3440
        BandType = 7
        LayerName = Foreground
      end
      object ppLine4: TppLine
        UserName = 'Line4'
        Weight = 0.750000000000000000
        mmHeight = 1323
        mmLeft = 1058
        mmTop = 20108
        mmWidth = 80963
        BandType = 7
        LayerName = Foreground
      end
      object ppLine5: TppLine
        UserName = 'Line5'
        Weight = 0.750000000000000000
        mmHeight = 1323
        mmLeft = 1058
        mmTop = 25135
        mmWidth = 80963
        BandType = 7
        LayerName = Foreground
      end
      object ppLine6: TppLine
        UserName = 'Line6'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 9790
        mmLeft = 1058
        mmTop = 20373
        mmWidth = 3440
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel5: TppLabel
        UserName = 'Label5'
        AutoSize = False
        Caption = 'Charges'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 67469
        mmTop = 15875
        mmWidth = 13758
        BandType = 7
        LayerName = Foreground
      end
      object ppLine7: TppLine
        UserName = 'Line7'
        Weight = 0.750000000000000000
        mmHeight = 1323
        mmLeft = 1323
        mmTop = 30427
        mmWidth = 96044
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel7: TppLabel
        UserName = 'Label7'
        AutoSize = False
        Caption = 'Creations'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 27252
        mmTop = 16140
        mmWidth = 17463
        BandType = 7
        LayerName = Foreground
      end
      object ppLine8: TppLine
        UserName = 'Line8'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 45773
        mmTop = 16140
        mmWidth = 3440
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel8: TppLabel
        UserName = 'Label8'
        AutoSize = False
        Caption = 'Views'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 47361
        mmTop = 16140
        mmWidth = 17727
        BandType = 7
        LayerName = Foreground
      end
      object ppLine9: TppLine
        UserName = 'Line9'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 66411
        mmTop = 16140
        mmWidth = 3440
        BandType = 7
        LayerName = Foreground
      end
      object ppLine10: TppLine
        UserName = 'Line10'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 81756
        mmTop = 15875
        mmWidth = 529
        BandType = 7
        LayerName = Foreground
      end
      object rlabNumCreations: TppLabel
        UserName = 'rlabNumCreations'
        Caption = '18.000.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 28840
        mmTop = 20902
        mmWidth = 15875
        BandType = 7
        LayerName = Foreground
      end
      object rlabNumViews: TppLabel
        UserName = 'Label101'
        Caption = '18.000.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 49213
        mmTop = 20902
        mmWidth = 15875
        BandType = 7
        LayerName = Foreground
      end
      object rlabNumCharges: TppLabel
        UserName = 'Label102'
        Caption = '4.700'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 67998
        mmTop = 20902
        mmWidth = 13229
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc5: TppDBCalc
        UserName = 'DBCalc5'
        DataField = 'InvoiceNumber'
        DataPipeline = dplMTokenUsage
        DisplayFormat = '#,##0'#39
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DBCalcType = dcCount
        DataPipelineName = 'dplMTokenUsage'
        mmHeight = 3704
        mmLeft = 1588
        mmTop = 1588
        mmWidth = 14288
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel23: TppLabel
        UserName = 'Label13'
        Caption = 'total events.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 17463
        mmTop = 1588
        mmWidth = 18584
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel9: TppLabel
        UserName = 'Label9'
        AutoSize = False
        Caption = 'Cost'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 1588
        mmTop = 25929
        mmWidth = 23283
        BandType = 7
        LayerName = Foreground
      end
      object rlabCostCreations: TppLabel
        UserName = 'rlabttLodgingTax1'
        Caption = '18.000.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 28840
        mmTop = 25929
        mmWidth = 15875
        BandType = 7
        LayerName = Foreground
      end
      object rlabCostViews: TppLabel
        UserName = 'rlabCostViews'
        Caption = '18.000.000'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 49213
        mmTop = 25929
        mmWidth = 15875
        BandType = 7
        LayerName = Foreground
      end
      object rlabCostCharges: TppLabel
        UserName = 'Label14'
        Caption = '4.700'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 67998
        mmTop = 25929
        mmWidth = 13229
        BandType = 7
        LayerName = Foreground
      end
      object ppLine11: TppLine
        UserName = 'Line11'
        Weight = 0.750000000000000000
        mmHeight = 1323
        mmLeft = 16404
        mmTop = 20108
        mmWidth = 80963
        BandType = 7
        LayerName = Foreground
      end
      object ppLine13: TppLine
        UserName = 'Line13'
        Weight = 0.750000000000000000
        mmHeight = 1323
        mmLeft = 16404
        mmTop = 25135
        mmWidth = 80963
        BandType = 7
        LayerName = Foreground
      end
      object ppLabel14: TppLabel
        UserName = 'Label15'
        AutoSize = False
        Caption = 'Total'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3810
        mmLeft = 82815
        mmTop = 15875
        mmWidth = 13758
        BandType = 7
        LayerName = Foreground
      end
      object ppLine15: TppLine
        UserName = 'Line15'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 81756
        mmTop = 16140
        mmWidth = 3440
        BandType = 7
        LayerName = Foreground
      end
      object ppLine16: TppLine
        UserName = 'Line101'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 14552
        mmLeft = 97102
        mmTop = 15875
        mmWidth = 529
        BandType = 7
        LayerName = Foreground
      end
      object rlabNumTotal: TppLabel
        UserName = 'Label16'
        Caption = '4.700'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 83344
        mmTop = 20902
        mmWidth = 13229
        BandType = 7
        LayerName = Foreground
      end
      object rlabCostTotal: TppLabel
        UserName = 'Label17'
        Caption = '4.700'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 82815
        mmTop = 25929
        mmWidth = 13229
        BandType = 7
        LayerName = Foreground
      end
    end
    object ppDesignLayers1: TppDesignLayers
      object ppDesignLayer1: TppDesignLayer
        UserName = 'Foreground'
        LayerType = ltBanded
        Index = 0
      end
    end
    object ppParameterList1: TppParameterList
    end
  end
  object dplMTokenUsage: TppDBPipeline
    DataSource = mTokenUsageDS
    CloseDataSource = True
    UserName = 'dplMTokenUsage'
    Left = 144
    Top = 276
  end
  object StoreMain: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\PCITokenUsageReport'
    StorageType = stRegistry
    Left = 496
    Top = 344
  end
end
