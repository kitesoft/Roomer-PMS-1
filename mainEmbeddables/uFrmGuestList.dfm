object frmGuestList: TfrmGuestList
  Left = 0
  Top = 0
  ClientHeight = 602
  ClientWidth = 1037
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pnlHolder: TsPanel
    Left = 0
    Top = 0
    Width = 1037
    Height = 602
    Align = alClient
    TabOrder = 0
    object Panel3: TsPanel
      Left = 1
      Top = 1
      Width = 1035
      Height = 100
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      SkinData.SkinSection = 'TRANSPARENT'
      object rgrGroupreportStayType: TsRadioGroup
        Left = 2
        Top = 4
        Width = 128
        Height = 84
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        OnClick = rgrGroupReportDateTypeClick
        SkinData.SkinSection = 'GROUPBOX'
        ItemIndex = 2
        Items.Strings = (
          'Arrival'
          'Departure'
          'All')
      end
      object btnGroupReportExpandAll: TsButton
        Left = 136
        Top = 11
        Width = 117
        Height = 22
        Caption = 'Expand All'
        TabOrder = 1
        OnClick = btnGroupReportExpandAllClick
      end
      object btnGroupreportCollapseAll: TsButton
        Left = 136
        Top = 39
        Width = 117
        Height = 21
        Caption = 'Collapse All'
        TabOrder = 2
        OnClick = btnGroupreportCollapseAllClick
      end
      object btnGuestListExcel: TsButton
        Left = 136
        Top = 66
        Width = 117
        Height = 22
        Caption = 'Excel'
        TabOrder = 3
        OnClick = btnGuestListExcelClick
      end
      object grbGroupReportProperties: TsGroupBox
        Left = 301
        Top = 4
        Width = 258
        Height = 84
        Caption = 'Report'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        SkinData.SkinSection = 'GROUPBOX'
        object chkNewPage: TsCheckBox
          Left = 3
          Top = 15
          Width = 151
          Height = 17
          Caption = 'Reservation on new page'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          SkinData.SkinSection = 'CHECKBOX'
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object chkPrintMemo: TsCheckBox
          Left = 3
          Top = 36
          Width = 81
          Height = 17
          Caption = 'Print memo'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          SkinData.SkinSection = 'CHECKBOX'
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object btnGroupReportShow: TsButton
          Left = 74
          Top = 58
          Width = 80
          Height = 21
          Caption = 'Show'
          TabOrder = 2
          OnClick = btnGroupReportShowClick
        end
      end
    end
    object gAllReservations: TcxGrid
      Left = 1
      Top = 101
      Width = 1035
      Height = 500
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvRaised
      BorderStyle = cxcbsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      PopupMenu = pupGroups
      TabOrder = 1
      LookAndFeel.NativeStyle = False
      ExplicitLeft = 0
      ExplicitTop = 95
      object tvAllReservations: TcxGridDBTableView
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
        DataController.DataSource = allReservationsDS
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <
          item
            Kind = skSum
            FieldName = 'RvGuestCount'
            Column = tvAllReservationsRvGuestCount
          end
          item
            Kind = skSum
            FieldName = 'RRGuestCount'
            Column = tvAllReservationsRRGuestCount
          end
          item
            Kind = skSum
            FieldName = 'breakfastGuests'
            Column = tvAllReservationsbreakfastGuests
          end>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsData.CancelOnExit = False
        OptionsData.Deleting = False
        OptionsData.DeletingConfirmation = False
        OptionsData.Editing = False
        OptionsData.Inserting = False
        OptionsView.Footer = True
        OptionsView.Indicator = True
        object tvAllReservationsRoom: TcxGridDBColumn
          Caption = 'Room.'
          DataBinding.FieldName = 'Room'
          Width = 44
        end
        object tvAllReservationsRoomType: TcxGridDBColumn
          Caption = 'Type'
          DataBinding.FieldName = 'RoomType'
          Width = 49
        end
        object tvAllReservationsReservationName: TcxGridDBColumn
          Caption = 'Reservation Name'
          DataBinding.FieldName = 'ReservationName'
          Visible = False
          Width = 189
        end
        object tvAllReservationsmainGuests: TcxGridDBColumn
          DataBinding.FieldName = 'mainGuests'
          Visible = False
          Width = 164
        end
        object tvAllReservationsResLine: TcxGridDBColumn
          Caption = 'Guest / Reservation Name'
          DataBinding.FieldName = 'ResLine'
          Width = 210
        end
        object tvAllReservationsArrivalDate: TcxGridDBColumn
          Caption = 'Arrival'
          DataBinding.FieldName = 'ArrivalDate'
        end
        object tvAllReservationsDepartureDate: TcxGridDBColumn
          Caption = 'Departure'
          DataBinding.FieldName = 'DepartureDate'
        end
        object tvAllReservationsNights: TcxGridDBColumn
          DataBinding.FieldName = 'Nights'
          Width = 42
        end
        object tvAllReservationsRRGuestCount: TcxGridDBColumn
          Caption = 'Guests'
          DataBinding.FieldName = 'RRGuestCount'
          Width = 40
        end
        object tvAllReservationsAdults: TcxGridDBColumn
          DataBinding.FieldName = 'Adults'
          Width = 52
        end
        object tvAllReservationsChildren: TcxGridDBColumn
          DataBinding.FieldName = 'Children'
          Width = 52
        end
        object tvAllReservationsInfants: TcxGridDBColumn
          DataBinding.FieldName = 'Infants'
          Width = 47
        end
        object tvAllReservationsStatustext: TcxGridDBColumn
          Caption = 'Status'
          DataBinding.FieldName = 'Statustext'
          Width = 89
        end
        object tvAllReservationsCurrency: TcxGridDBColumn
          DataBinding.FieldName = 'Currency'
        end
        object tvAllReservationsAverageRate: TcxGridDBColumn
          Caption = 'Average Rate'
          DataBinding.FieldName = 'AverageRate'
          OnGetProperties = tvAllReservationsAverageRateGetProperties
        end
        object tvAllReservationsTotalStayRate: TcxGridDBColumn
          Caption = 'Total Stay Rate'
          DataBinding.FieldName = 'TotalStayRate'
          OnGetProperties = tvAllReservationsTotalStayRateGetProperties
        end
        object tvAllReservationsBreakfast: TcxGridDBColumn
          DataBinding.FieldName = 'Breakfast'
          PropertiesClassName = 'TcxTextEditProperties'
          Properties.MaxLength = 20
        end
        object tvAllReservationsbreakfastGuests: TcxGridDBColumn
          Caption = 'Brkf. Guests'
          DataBinding.FieldName = 'breakfastGuests'
          Width = 58
        end
        object tvAllReservationsmarketSegmentDescription: TcxGridDBColumn
          Caption = 'Market'
          DataBinding.FieldName = 'marketSegmentDescription'
          Width = 90
        end
        object tvAllReservationsGroupAccount: TcxGridDBColumn
          Caption = 'Group'
          DataBinding.FieldName = 'GroupAccount'
        end
        object tvAllReservationsRoomDescription: TcxGridDBColumn
          Caption = 'Room description'
          DataBinding.FieldName = 'RoomDescription'
          Width = 84
        end
        object tvAllReservationsFloor: TcxGridDBColumn
          Caption = 'Floor.'
          DataBinding.FieldName = 'Floor'
          Width = 35
        end
        object tvAllReservationsLocationDescription: TcxGridDBColumn
          Caption = 'Location'
          DataBinding.FieldName = 'LocationDescription'
          Width = 102
        end
        object tvAllReservationsCustomer: TcxGridDBColumn
          DataBinding.FieldName = 'Customer'
          Visible = False
        end
        object tvAllReservationsCustomerName: TcxGridDBColumn
          DataBinding.FieldName = 'CustomerName'
        end
        object tvAllReservationsPersonalID: TcxGridDBColumn
          Caption = 'Personal ID'
          DataBinding.FieldName = 'PersonalID'
        end
        object tvAllReservationsEmail: TcxGridDBColumn
          DataBinding.FieldName = 'Email'
          Visible = False
          Width = 148
        end
        object tvAllReservationsWebsite: TcxGridDBColumn
          DataBinding.FieldName = 'Website'
          Visible = False
          Width = 125
        end
        object tvAllReservationsRvGuestCount: TcxGridDBColumn
          DataBinding.FieldName = 'RvGuestCount'
          Visible = False
        end
        object tvAllReservationsNoRoom: TcxGridDBColumn
          Caption = 'No-Room'
          DataBinding.FieldName = 'NoRoom'
          Width = 52
        end
        object tvAllReservationsBookable: TcxGridDBColumn
          DataBinding.FieldName = 'Bookable'
          Visible = False
        end
        object tvAllReservationsStatistics: TcxGridDBColumn
          DataBinding.FieldName = 'Statistics'
          Visible = False
        end
        object tvAllReservationsRoomReservation: TcxGridDBColumn
          DataBinding.FieldName = 'RoomReservation'
          Visible = False
        end
        object tvAllReservationsroomCount: TcxGridDBColumn
          DataBinding.FieldName = 'roomCount'
          Visible = False
        end
        object tvAllReservationsReservation: TcxGridDBColumn
          DataBinding.FieldName = 'Reservation'
          Visible = False
        end
        object tvAllReservationsStatus: TcxGridDBColumn
          DataBinding.FieldName = 'Status'
          Visible = False
        end
        object tvAllReservationsLocation: TcxGridDBColumn
          DataBinding.FieldName = 'Location'
          Visible = False
        end
        object tvAllReservationsmarketSegment: TcxGridDBColumn
          DataBinding.FieldName = 'marketSegment'
          Visible = False
        end
        object tvAllReservationsresInfo: TcxGridDBColumn
          Caption = 'Reservation info:'
          DataBinding.FieldName = 'resInfo'
          Visible = False
          GroupIndex = 0
          Width = 242
        end
        object tvAllReservationshidden: TcxGridDBColumn
          DataBinding.FieldName = 'hidden'
          Visible = False
        end
        object tvAllReservationsEquipments: TcxGridDBColumn
          DataBinding.FieldName = 'Equipments'
          Visible = False
          Width = 137
        end
        object tvAllReservationsGroupReservation: TcxGridDBColumn
          Caption = 'Group Res.'
          DataBinding.FieldName = 'GroupReservation'
          Visible = False
        end
        object tvAllReservationsGroupReservationName: TcxGridDBColumn
          DataBinding.FieldName = 'GroupReservationName'
          Width = 200
        end
        object tvAllReservationsRoomNotes: TcxGridDBColumn
          DataBinding.FieldName = 'RoomNotes'
          Width = 200
        end
      end
      object lvAllReservations: TcxGridLevel
        GridView = tvAllReservations
      end
    end
  end
  object rptbGroups: TppReport
    AutoStop = False
    DataPipeline = dplGroups
    PrinterSetup.BinName = 'Default'
    PrinterSetup.DocumentName = 'Report'
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
    Left = 472
    Top = 17
    Version = '14.07'
    mmColumnWidth = 0
    DataPipelineName = 'dplGroups'
    object ppHeaderBand1: TppHeaderBand
      BeforePrint = ppHeaderBand1BeforePrint
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 17198
      mmPrintPosition = 0
      object rLabReportName: TppLabel
        UserName = 'rLabReportName'
        Caption = 'ReportName'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 18
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 7535
        mmLeft = 529
        mmTop = 529
        mmWidth = 37677
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel9: TppLabel
        UserName = 'Label9'
        Caption = 'Date :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 1323
        mmTop = 9525
        mmWidth = 8805
        BandType = 0
        LayerName = Foreground
      end
      object rlabFrom: TppLabel
        UserName = 'rLabFrom'
        Caption = '01.01.2010'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 13494
        mmTop = 9790
        mmWidth = 16002
        BandType = 0
        LayerName = Foreground
      end
      object rLabHotelName: TppLabel
        UserName = 'rLabHotelName'
        Caption = 'Hotel nafn'
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
        mmLeft = 192882
        mmTop = 4763
        mmWidth = 2836
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
        mmLeft = 170657
        mmTop = 9525
        mmWidth = 25019
        BandType = 0
        LayerName = Foreground
      end
      object ppLine4: TppLine
        UserName = 'Line4'
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 2910
        mmLeft = 0
        mmTop = 14288
        mmWidth = 197300
        BandType = 0
        LayerName = Foreground
      end
    end
    object ppDetailBand1: TppDetailBand
      Background1.Brush.Style = bsClear
      Background2.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 4233
      mmPrintPosition = 0
      object ppDBText1: TppDBText
        UserName = 'DBText1'
        DataField = 'Room'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 794
        mmTop = 0
        mmWidth = 13494
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText2: TppDBText
        UserName = 'DBText2'
        DataField = 'RoomType'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 16669
        mmTop = 0
        mmWidth = 9790
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText5: TppDBText
        UserName = 'DBText5'
        DataField = 'ResLine'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 28575
        mmTop = 0
        mmWidth = 41275
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText6: TppDBText
        UserName = 'DBText6'
        DataField = 'ArrivalDate'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3260
        mmLeft = 71702
        mmTop = 0
        mmWidth = 14288
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText7: TppDBText
        UserName = 'DBText7'
        DataField = 'DepartureDate'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3260
        mmLeft = 86784
        mmTop = 0
        mmWidth = 14288
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText8: TppDBText
        UserName = 'DBText8'
        DataField = 'RRGuestCount'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 121444
        mmTop = 0
        mmWidth = 9790
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText9: TppDBText
        UserName = 'DBText9'
        DataField = 'Statustext'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 102394
        mmTop = 0
        mmWidth = 18521
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText10: TppDBText
        UserName = 'DBText10'
        DataField = 'Breakfast'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3260
        mmLeft = 132557
        mmTop = 0
        mmWidth = 18256
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText11: TppDBText
        UserName = 'DBText11'
        DataField = 'CustomerName'
        DataPipeline = dplGroups
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'dplGroups'
        mmHeight = 3175
        mmLeft = 151607
        mmTop = 0
        mmWidth = 42333
        BandType = 4
        LayerName = Foreground
      end
    end
    object ppFooterBand1: TppFooterBand
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 13229
      mmPrintPosition = 0
    end
    object ppGroup1: TppGroup
      BreakName = 'GroupReservation'
      DataPipeline = dplGroups
      GroupFileSettings.NewFile = False
      GroupFileSettings.EmailFile = False
      KeepTogether = True
      OutlineSettings.CreateNode = True
      StartOnOddPage = False
      UserName = 'Group1'
      mmNewColumnThreshold = 0
      mmNewPageThreshold = 0
      DataPipelineName = 'dplGroups'
      NewFile = False
      object ppGroupHeaderBand1: TppGroupHeaderBand
        BeforePrint = ppGroupHeaderBand1BeforePrint
        Background.Brush.Style = bsClear
        PrintHeight = phDynamic
        mmBottomOffset = 0
        mmHeight = 15081
        mmPrintPosition = 0
        object ppLabel1: TppLabel
          UserName = 'Label1'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Room'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 5112
          mmLeft = 794
          mmTop = 11113
          mmWidth = 13494
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel2: TppLabel
          UserName = 'Label2'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Type'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 5112
          mmLeft = 16669
          mmTop = 11113
          mmWidth = 9790
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppDBText3: TppDBText
          UserName = 'DBText3'
          DataField = 'GroupReservation'
          DataPipeline = dplGroups
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 12
          Font.Style = []
          Transparent = True
          Visible = False
          DataPipelineName = 'dplGroups'
          mmHeight = 2381
          mmLeft = 6615
          mmTop = 6085
          mmWidth = 19050
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLine2: TppLine
          UserName = 'Line2'
          Anchors = [atLeft, atTop, atBottom]
          ParentWidth = True
          Weight = 0.750000000000000000
          mmHeight = 2646
          mmLeft = 0
          mmTop = 14817
          mmWidth = 197300
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel5: TppLabel
          UserName = 'Label5'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Guest / reservation name'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 5112
          mmLeft = 28575
          mmTop = 11377
          mmWidth = 41275
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel6: TppLabel
          UserName = 'Label6'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Arrival'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          TextAlignment = taRightJustified
          Transparent = True
          mmHeight = 5112
          mmLeft = 75936
          mmTop = 11113
          mmWidth = 9790
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel7: TppLabel
          UserName = 'Label7'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Departure'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          TextAlignment = taRightJustified
          Transparent = True
          mmHeight = 5112
          mmLeft = 87842
          mmTop = 11113
          mmWidth = 13229
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel8: TppLabel
          UserName = 'Label8'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Guests'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          TextAlignment = taRightJustified
          Transparent = True
          mmHeight = 5027
          mmLeft = 121444
          mmTop = 11113
          mmWidth = 9790
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object mem: TppMemo
          UserName = 'mem'
          Border.Weight = 1.000000000000000000
          Caption = 'mem'
          CharWrap = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 9
          Font.Style = []
          Stretch = True
          Transparent = True
          mmHeight = 3175
          mmLeft = 1323
          mmTop = 6879
          mmWidth = 89429
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
          mmBottomOffset = 0
          mmOverFlowOffset = 0
          mmStopPosition = 0
          mmMinHeight = 0
          mmLeading = 0
        end
        object ppDBText4: TppDBText
          UserName = 'DBText4'
          DataField = 'resInfo'
          DataPipeline = dplGroups
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 12
          Font.Style = []
          Transparent = True
          DataPipelineName = 'dplGroups'
          mmHeight = 4763
          mmLeft = 1058
          mmTop = 794
          mmWidth = 194205
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel4: TppLabel
          UserName = 'Label4'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Breakfast'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 3260
          mmLeft = 132557
          mmTop = 11113
          mmWidth = 18256
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel10: TppLabel
          UserName = 'Label10'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Customer'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 3260
          mmLeft = 151607
          mmTop = 11113
          mmWidth = 27781
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel11: TppLabel
          UserName = 'Label11'
          Anchors = [atLeft, atTop, atBottom]
          AutoSize = False
          Caption = 'Status'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 3260
          mmLeft = 102394
          mmTop = 11113
          mmWidth = 9790
          BandType = 3
          GroupNo = 0
          LayerName = Foreground
        end
      end
      object ppGroupFooterBand1: TppGroupFooterBand
        Background.Brush.Style = bsClear
        HideWhenOneDetail = False
        mmBottomOffset = 0
        mmHeight = 8202
        mmPrintPosition = 0
        object ppLine1: TppLine
          UserName = 'Line1'
          ParentWidth = True
          Weight = 0.750000000000000000
          mmHeight = 3969
          mmLeft = 0
          mmTop = 264
          mmWidth = 197300
          BandType = 5
          GroupNo = 0
          LayerName = Foreground
        end
        object ppDBCalc1: TppDBCalc
          UserName = 'DBCalc1'
          DataField = 'Room'
          DataPipeline = dplGroups
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          ResetGroup = ppGroup1
          TextAlignment = taRightJustified
          Transparent = True
          DBCalcType = dcCount
          DataPipelineName = 'dplGroups'
          mmHeight = 3260
          mmLeft = 1058
          mmTop = 529
          mmWidth = 8996
          BandType = 5
          GroupNo = 0
          LayerName = Foreground
        end
        object ppLabel3: TppLabel
          UserName = 'Label3'
          Caption = 'Rooms'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          Transparent = True
          mmHeight = 3260
          mmLeft = 10848
          mmTop = 529
          mmWidth = 9017
          BandType = 5
          GroupNo = 0
          LayerName = Foreground
        end
        object ppDBCalc2: TppDBCalc
          UserName = 'DBCalc2'
          DataField = 'RRGuestCount'
          DataPipeline = dplGroups
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Name = 'Arial'
          Font.Size = 8
          Font.Style = []
          ResetGroup = ppGroup1
          TextAlignment = taRightJustified
          Transparent = True
          DataPipelineName = 'dplGroups'
          mmHeight = 3175
          mmLeft = 121444
          mmTop = 1058
          mmWidth = 9790
          BandType = 5
          GroupNo = 0
          LayerName = Foreground
        end
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
  object dplGroups: TppDBPipeline
    DataSource = mDS
    UserName = 'dplGroups'
    Left = 528
    Top = 17
  end
  object pupGroups: TPopupMenu
    OnPopup = pupGroupsPopup
    Left = 112
    Top = 184
    object mnuReservationProfile: TMenuItem
      Caption = 'Reservation Profile'
      Default = True
      OnClick = mnuReservationProfileClick
    end
    object mnuGuestProfile: TMenuItem
      Caption = 'Room Profile'
      OnClick = mnuGuestprofileClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object mnuPrintRegistrationForm: TMenuItem
      Caption = 'Print registration form'
      OnClick = mnuPrintRegistrationFormClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object mnuCheckin: TMenuItem
      Caption = 'Check in'
      OnClick = mnuCheckinClick
    end
    object mnuCheckout: TMenuItem
      Caption = 'Check out'
      OnClick = mnuCheckoutClick
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object mnuRoominvoice: TMenuItem
      Caption = 'Room Invoice'
      OnClick = mnuRoomInvoiceClick
    end
    object mnuGroupInvoice: TMenuItem
      Caption = 'Group Invoice'
      OnClick = mnuGroupInvoiceClick
    end
  end
  object mAllReservations: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'ReservationName'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'ArrivalDate'
        DataType = ftDate
      end
      item
        Name = 'DepartureDate'
        DataType = ftDate
      end
      item
        Name = 'Room'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'RoomType'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Status'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Breakfast'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'NoRoom'
        DataType = ftBoolean
      end
      item
        Name = 'RoomDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Bookable'
        DataType = ftBoolean
      end
      item
        Name = 'Statistics'
        DataType = ftBoolean
      end
      item
        Name = 'hidden'
        DataType = ftBoolean
      end
      item
        Name = 'Location'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'Floor'
        DataType = ftInteger
      end
      item
        Name = 'Equipments'
        DataType = ftWideString
        Size = 80
      end
      item
        Name = 'LocationDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'GroupAccount'
        DataType = ftBoolean
      end
      item
        Name = 'marketSegment'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'marketSegmentDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Email'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Website'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Customer'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'CustomerName'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'PersonalID'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'Statustext'
        DataType = ftWideString
        Size = 50
      end
      item
        Name = 'Currency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'resInfo'
        DataType = ftWideString
        Size = 120
      end
      item
        Name = 'roomCount'
        DataType = ftInteger
      end
      item
        Name = 'RvGuestCount'
        DataType = ftInteger
      end
      item
        Name = 'RRGuestCount'
        DataType = ftInteger
      end
      item
        Name = 'mainGuests'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'GroupReservation'
        DataType = ftInteger
      end
      item
        Name = 'GroupReservationName'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'ResLine'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'RoomNotes'
        DataType = ftWideString
        Size = 255
      end
      item
        Name = 'breakfastGuests'
        DataType = ftInteger
      end
      item
        Name = 'Nights'
        DataType = ftInteger
      end
      item
        Name = 'AverageRate'
        DataType = ftFloat
      end
      item
        Name = 'TotalStayRate'
        DataType = ftFloat
      end
      item
        Name = 'Adults'
        DataType = ftInteger
      end
      item
        Name = 'Children'
        DataType = ftInteger
      end
      item
        Name = 'Infants'
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
    Left = 216
    Top = 185
  end
  object allReservationsDS: TDataSource
    DataSet = mAllReservations
    Left = 216
    Top = 238
  end
  object m: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'ReservationName'
        DataType = ftWideString
      end
      item
        Name = 'ArrivalDate'
        DataType = ftDate
      end
      item
        Name = 'DepartureDate'
        DataType = ftDate
      end
      item
        Name = 'Room'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'RoomType'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'Status'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'Breakfast'
        DataType = ftWideString
        Precision = 25
      end
      item
        Name = 'NoRoom'
        DataType = ftBoolean
      end
      item
        Name = 'RoomDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Bookable'
        DataType = ftBoolean
      end
      item
        Name = 'Statistics'
        DataType = ftBoolean
      end
      item
        Name = 'hidden'
        DataType = ftBoolean
      end
      item
        Name = 'Location'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'Floor'
        DataType = ftInteger
      end
      item
        Name = 'Equipments'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'LocationDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'GroupAccount'
        DataType = ftBoolean
      end
      item
        Name = 'marketSegment'
        DataType = ftWideString
        Size = 15
      end
      item
        Name = 'marketSegmentDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Email'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Website'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Customer'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'CustomerName'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'PersonalID'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'Statustext'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'resInfo'
        DataType = ftWideString
        Size = 80
      end
      item
        Name = 'roomCount'
        DataType = ftInteger
      end
      item
        Name = 'RvGuestCount'
        DataType = ftInteger
      end
      item
        Name = 'RRGuestCount'
        DataType = ftInteger
      end
      item
        Name = 'mainGuests'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'GroupReservation'
        DataType = ftInteger
      end
      item
        Name = 'GroupReservationName'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'ResLine'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'mem'
        DataType = ftMemo
        Size = 255
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
    Left = 336
    Top = 193
  end
  object mDS: TDataSource
    DataSet = m
    Left = 336
    Top = 246
  end
end
