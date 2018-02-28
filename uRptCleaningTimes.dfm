inherited frmCleaningTimes: TfrmCleaningTimes
  Caption = 'Cleaning times report'
  ClientHeight = 586
  ClientWidth = 857
  ExplicitWidth = 873
  ExplicitHeight = 625
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 566
    Width = 857
    ExplicitTop = 566
    ExplicitWidth = 857
  end
  inherited pnlButtons: TsPanel
    Top = 523
    Width = 857
    TabOrder = 0
    ExplicitTop = 523
    ExplicitWidth = 857
    inherited btnOK: TsButton
      Left = 541
      ExplicitLeft = 541
    end
    inherited btnCancel: TsButton
      Left = 647
      ExplicitLeft = 647
    end
    inherited btnClose: TsButton
      Left = 753
      ExplicitLeft = 753
    end
  end
  inherited pnlTop: TsPanel
    Width = 857
    Height = 129
    AutoSize = False
    TabOrder = 1
    ExplicitWidth = 857
    ExplicitHeight = 129
    object pnlExportButtons: TsPanel
      Left = 0
      Top = 88
      Width = 857
      Height = 41
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 128
        Height = 35
        Align = alLeft
        Caption = 'Export'
        DropDownMenu = pmnuExport
        ImageIndex = 115
        Images = DImages.PngImageList1
        Style = bsSplitButton
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object gbxSelectDates: TsGroupBox
      Left = 3
      Top = 1
      Width = 368
      Height = 80
      Caption = 'Select dates:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      SkinData.SkinSection = 'GROUPBOX'
      object rbToday: TsRadioButton
        Left = 20
        Top = 20
        Width = 50
        Height = 20
        Caption = 'Today'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = rbTodayClick
      end
      object rbYesterday: TsRadioButton
        Left = 21
        Top = 46
        Width = 69
        Height = 20
        Caption = 'Yesterday'
        TabOrder = 1
        OnClick = rbYesterdayClick
      end
      object rbManualRange: TsRadioButton
        Left = 131
        Top = 21
        Width = 88
        Height = 20
        Caption = 'Manual dates:'
        TabOrder = 2
        OnClick = rbManualRangeClick
      end
      object dtDateFrom: TsDateEdit
        Left = 245
        Top = 20
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
      end
      object dtDateTo: TsDateEdit
        Left = 245
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
        TabOrder = 4
        Text = '  -  -    '
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
    end
    object btnRefresh: TsButton
      Left = 377
      Top = 14
      Width = 118
      Height = 26
      Caption = 'Refresh'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 2
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
  inherited pnlClient: TsPanel
    Top = 129
    Width = 857
    Height = 394
    TabOrder = 2
    ExplicitTop = 129
    ExplicitWidth = 857
    ExplicitHeight = 394
    inherited grData: TcxGrid
      Width = 855
      Height = 392
      ExplicitWidth = 855
      ExplicitHeight = 392
      inherited tvData: TcxGridDBBandedTableView
        Navigator.Visible = False
        DataController.Summary.DefaultGroupSummaryItems = <
          item
            Kind = skAverage
            Position = spFooter
            Column = tvDataDurationInMinutes
          end>
        DataController.Summary.FooterSummaryItems = <
          item
            Kind = skAverage
            Column = tvDataDurationInMinutes
          end>
        OptionsView.Footer = True
        OptionsView.GroupByBox = True
        Styles.Content = nil
        Styles.ContentEven = nil
        Styles.ContentOdd = nil
        Styles.Selection = nil
        Styles.Footer = nil
        Styles.Group = nil
        Styles.GroupSummary = nil
        Styles.Header = nil
        Styles.Preview = nil
        object tvDataLocation: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Location'
          Width = 95
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object tvDataRoom: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Room'
          Width = 95
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object tvDataroomtype: TcxGridDBBandedColumn
          Caption = 'RoomType'
          DataBinding.FieldName = 'roomtype'
          Width = 95
          Position.BandIndex = 0
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object tvDatastartTime: TcxGridDBBandedColumn
          Caption = 'Start Time'
          DataBinding.FieldName = 'startTime'
          Width = 155
          Position.BandIndex = 0
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object tvDataendTime: TcxGridDBBandedColumn
          Caption = 'End Time'
          DataBinding.FieldName = 'endTime'
          Width = 151
          Position.BandIndex = 0
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
        object tvDataDurationInMinutes: TcxGridDBBandedColumn
          Caption = 'Duration (min)'
          DataBinding.FieldName = 'DurationInMinutes'
          Width = 106
          Position.BandIndex = 0
          Position.ColIndex = 5
          Position.RowIndex = 0
        end
        object tvDataStaffmember: TcxGridDBBandedColumn
          DataBinding.FieldName = 'Staffmember'
          Width = 156
          Position.BandIndex = 0
          Position.ColIndex = 6
          Position.RowIndex = 0
        end
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 424
    Top = 216
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 312
    Top = 216
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      BuiltIn = True
    end
  end
  inherited dsData: TDataSource
    DataSet = kbmCleaningTimes
    Left = 320
    Top = 424
  end
  inherited alGridActions: TActionList
    Top = 216
  end
  inherited grPrinter: TdxComponentPrinter
    Top = 216
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43154.649115509260000000
      AssignedFormatValues = []
      OptionsSize.AutoWidth = True
      OptionsView.ExpandButtons = False
      OptionsView.FilterBar = False
      BuiltInReportLink = True
    end
  end
  object kbmCleaningTimes: TkbmMemTable
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
        Name = 'GuestName'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'NumGuests'
        DataType = ftInteger
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
    Left = 416
    Top = 359
    object kbmCleaningTimesLocation: TWideStringField
      FieldName = 'Location'
      Size = 10
    end
    object kbmCleaningTimesfldRoom: TWideStringField
      FieldName = 'Room'
      Size = 10
    end
    object kbmCleaningTimesroomtype: TWideStringField
      FieldName = 'roomtype'
      Size = 10
    end
    object kbmCleaningTimesStaffmember: TWideStringField
      FieldName = 'Staffmember'
      Size = 15
    end
    object kbmCleaningTimesstartTime: TDateTimeField
      FieldName = 'startTime'
    end
    object kbmCleaningTimesendTime: TDateTimeField
      FieldName = 'endTime'
    end
    object kbmCleaningTimesDurationMinutes: TIntegerField
      FieldName = 'DurationInMinutes'
    end
  end
  object pmnuExport: TPopupMenu
    Left = 72
    Top = 216
    object Print1: TMenuItem
      Action = acPrint
    end
  end
end
