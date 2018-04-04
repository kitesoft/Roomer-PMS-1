object frmRptRoomRentStatistics: TfrmRptRoomRentStatistics
  Left = 0
  Top = 0
  Caption = 'Room/Rent Statistics'
  ClientHeight = 643
  ClientWidth = 1459
  Color = clBtnFace
  Constraints.MinWidth = 570
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TsPanel
    Left = 0
    Top = 0
    Width = 1459
    Height = 89
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object cxGroupBox2: TsGroupBox
      AlignWithMargins = True
      Left = 145
      Top = 4
      Width = 151
      Height = 81
      Align = alLeft
      Caption = '.. or select month'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object cbxMonth: TsComboBox
        Left = 15
        Top = 20
        Width = 121
        Height = 21
        Alignment = taLeftJustify
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        TextHint = 'Choose a month ...'
        Style = csDropDownList
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 0
        OnChange = cbxMonthChange
        Items.Strings = (
          '')
      end
      object cbxYear: TsComboBox
        Left = 15
        Top = 47
        Width = 121
        Height = 21
        Alignment = taLeftJustify
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        TextHint = 'Choose a year ...'
        Style = csDropDownList
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 1
        OnChange = cbxMonthChange
      end
    end
    object btnRefresh: TsButton
      Left = 805
      Top = 16
      Width = 118
      Height = 37
      Caption = 'Refresh ALL'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
    end
    object gbxSelectDates: TsGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 135
      Height = 81
      Align = alLeft
      Caption = 'Select dates'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      SkinData.SkinSection = 'GROUPBOX'
      object dtDateFrom: TsDateEdit
        Left = 16
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
        TabOrder = 0
        Text = '  -  -    '
        OnChange = dtDateChange
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object dtDateTo: TsDateEdit
        Left = 16
        Top = 47
        Width = 105
        Height = 20
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
        TabOrder = 1
        Text = '  -  -    '
        OnChange = dtDateChange
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
    end
    object gbxIncludedStates: TsGroupBox
      AlignWithMargins = True
      Left = 302
      Top = 4
      Width = 493
      Height = 81
      Align = alLeft
      Caption = 'Include rooms with status of:'
      TabOrder = 3
      object clbIncludedStates: TsCheckListBox
        Left = 2
        Top = 15
        Width = 489
        Height = 64
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        BorderStyle = bsSingle
        Color = 14540253
        Columns = 3
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4013373
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemHeight = 20
        Items.Strings = (
          '<auto filled>')
        ParentFont = False
        TabOrder = 0
        StyleElements = [seFont, seClient]
        SkinData.SkinSection = 'GROUPBOX'
      end
    end
  end
  object sStatusBar1: TsStatusBar
    Left = 0
    Top = 624
    Width = 1459
    Height = 19
    Panels = <>
    SkinData.SkinSection = 'STATUSBAR'
  end
  object pcMain: TsPageControl
    Left = 0
    Top = 89
    Width = 1459
    Height = 535
    ActivePage = tsComparison
    Align = alClient
    TabOrder = 2
    SkinData.SkinSection = 'PAGECONTROL'
    object tabStatGrid: TsTabSheet
      Caption = 'Data'
      object sPanel1: TsPanel
        Left = 0
        Top = 0
        Width = 1451
        Height = 43
        Align = alTop
        FullRepaint = False
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object btnGuestsExcel: TsButton
          AlignWithMargins = True
          Left = 11
          Top = 4
          Width = 128
          Height = 35
          Margins.Left = 10
          Align = alLeft
          Caption = 'Excel'
          ImageIndex = 132
          Images = DImages.PngImageList1
          TabOrder = 0
          OnClick = btnGuestsExcelClick
          SkinData.SkinSection = 'BUTTON'
        end
        object btnReportStats: TsButton
          AlignWithMargins = True
          Left = 1319
          Top = 4
          Width = 128
          Height = 35
          Margins.Left = 10
          Align = alRight
          Caption = 'Report'
          ImageIndex = 118
          Images = DImages.PngImageList1
          TabOrder = 1
          OnClick = btnReportStatsClick
          SkinData.SkinSection = 'BUTTON'
          ExplicitTop = 2
        end
      end
      object grStat: TcxGrid
        Left = 0
        Top = 43
        Width = 1451
        Height = 464
        Align = alClient
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        ExplicitTop = 41
        object tvStat: TcxGridDBTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataSource = StatDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.Footer = True
          OptionsView.HeaderAutoHeight = True
        end
        object tvStats: TcxGridDBBandedTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataSource = StatDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'revenue'
              Column = tvStatsrevenue
            end
            item
              Format = ',0.%;-,0.%'
              Kind = skAverage
              FieldName = 'occ'
              Column = tvStatsOccupancy
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skAverage
              FieldName = 'adr'
              Column = tvStatsadr
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skAverage
              FieldName = 'revPar'
              Column = tvStatsrevPar
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              FieldName = 'totalDiscount'
              Column = tvStatstotalDiscount
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skMax
              FieldName = 'maxRate'
              Column = tvStatsHighestRate
            end
            item
              Format = ',0.;-,0.'
              Kind = skCount
              FieldName = 'ADate'
              Column = tvStatsADate
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skAverage
              FieldName = 'averageRate'
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'totalGuests'
              Column = tvStatstotalGuests
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skMin
              FieldName = 'minRate'
              Column = tvStatsLowestRate
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'soldRooms'
              Column = tvStatssoldRooms
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'inHouse'
              Column = tvStatsInHouse
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'checkedInToday'
              Column = tvStatscheckedInToday
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'remainingArrivals'
              Column = tvStatsremainingArrivals
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'noShow'
              Column = tvStatsnoShow
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'remainingDepartures'
              Column = tvStatsRemainingDepartures
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              FieldName = 'departedRooms'
              Column = tvStatsdepartedRooms
            end
            item
              Format = ',0.;-,0.'
              Kind = skSum
              Column = tvStatsooo
            end
            item
              Kind = skSum
              Column = tvStatsExpectedArrivals
            end
            item
              Kind = skSum
              Column = tvStatsArrivedRooms
            end
            item
              Kind = skSum
              Column = tvStatsExpectedDepartures
            end
            item
              Kind = skSum
              Column = tvStatsTotalSellableRooms
            end>
          DataController.Summary.SummaryGroups = <>
          DataController.Summary.OnAfterSummary = tvStatsDataControllerSummaryAfterSummary
          Images = DImages.cxSmallImagesFlat
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.FooterMultiSummaries = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          Styles.StyleSheet = cxssRoomerGridBandedTableView
          Bands = <
            item
              Caption = 'Date'
              FixedKind = fkLeft
              Width = 126
            end
            item
              Caption = 'Main'
            end
            item
              Caption = 'Rate'
              Width = 504
            end
            item
              Caption = 'Status'
            end>
          object tvStatsADate: TcxGridDBBandedColumn
            Caption = 'Date'
            DataBinding.FieldName = 'ADate'
            HeaderAlignmentHorz = taCenter
            Width = 64
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvStatsWeekday: TcxGridDBBandedColumn
            Caption = 'Weekday'
            DataBinding.FieldName = 'ADate'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.DisplayFormat = 'ddd'
            HeaderAlignmentHorz = taCenter
            Width = 62
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvStatsrevenue: TcxGridDBBandedColumn
            Caption = 'Revenue'
            DataBinding.FieldName = 'revenue'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            HeaderHint = 'This is the header hint for Revenues'
            HeaderImageIndex = 134
            Width = 70
            Position.BandIndex = 1
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvStatsOccupancy: TcxGridDBBandedColumn
            Caption = 'Occupancy'
            DataBinding.FieldName = 'occ'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.%;-,0.%'
            HeaderAlignmentHorz = taCenter
            HeaderHint = 'Occupancy'
            HeaderImageIndex = 134
            Width = 88
            Position.BandIndex = 1
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvStatsadr: TcxGridDBBandedColumn
            Caption = 'ADR'
            DataBinding.FieldName = 'adr'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            HeaderHint = 'Average daily rates'
            HeaderImageIndex = 134
            Position.BandIndex = 1
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvStatsrevPar: TcxGridDBBandedColumn
            Caption = 'RevPar'
            DataBinding.FieldName = 'revPar'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            HeaderHint = '{RevParDefinition}'
            HeaderImageIndex = 134
            Width = 70
            Position.BandIndex = 1
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvStatslocalCurrency: TcxGridDBBandedColumn
            Caption = 'Curr- ency'
            DataBinding.FieldName = 'currency'
            PropertiesClassName = 'TcxTextEditProperties'
            Properties.Alignment.Horz = taRightJustify
            HeaderAlignmentHorz = taCenter
            Width = 35
            Position.BandIndex = 2
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvStatstotalDiscount: TcxGridDBBandedColumn
            Caption = 'Total Discount'
            DataBinding.FieldName = 'totalDiscount'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.Alignment.Horz = taRightJustify
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            Width = 88
            Position.BandIndex = 2
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvStatsHighestRate: TcxGridDBBandedColumn
            Caption = 'Highest Rate'
            DataBinding.FieldName = 'maxRate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.Alignment.Horz = taRightJustify
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            Width = 94
            Position.BandIndex = 2
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvStatsLowestRate: TcxGridDBBandedColumn
            Caption = 'Lowest Rate'
            DataBinding.FieldName = 'minRate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            Properties.Alignment.Horz = taRightJustify
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            HeaderAlignmentHorz = taCenter
            Width = 96
            Position.BandIndex = 2
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvStatstotalGuests: TcxGridDBBandedColumn
            Caption = 'Total Guests'
            DataBinding.FieldName = 'totalGuests'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Width = 96
            Position.BandIndex = 2
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvStatscheckedInToday: TcxGridDBBandedColumn
            Caption = 'CheckedIn Today'
            DataBinding.FieldName = 'checkedInToday'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvStatssoldRooms: TcxGridDBBandedColumn
            Caption = 'Sold Rooms'
            DataBinding.FieldName = 'soldRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvStatsremainingArrivals: TcxGridDBBandedColumn
            Caption = 'Remaining Arrivals'
            DataBinding.FieldName = 'remainingArrivals'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvStatsnoShow: TcxGridDBBandedColumn
            Caption = 'No Show'
            DataBinding.FieldName = 'noShow'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvStatsRemainingDepartures: TcxGridDBBandedColumn
            Caption = 'Remaining Departures'
            DataBinding.FieldName = 'remainingDepartures'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvStatsdepartedRooms: TcxGridDBBandedColumn
            Caption = 'Departed Rooms'
            DataBinding.FieldName = 'departedRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvStatsInHouse: TcxGridDBBandedColumn
            Caption = 'In House'
            DataBinding.FieldName = 'inHouse'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvStatsTotalSellableRooms: TcxGridDBBandedColumn
            Caption = 'Total Sellable Rooms'
            DataBinding.FieldName = 'totalSellableRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvStatsooo: TcxGridDBBandedColumn
            Caption = 'Out Of Order'
            DataBinding.FieldName = 'oooRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = ',0.;-,0.'
            OnGetDisplayText = tvStatsHideZeroValues
            HeaderAlignmentHorz = taCenter
            Position.BandIndex = 3
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvStatsExpectedDepartures: TcxGridDBBandedColumn
            Caption = 'Expected Departures'
            DataBinding.FieldName = 'expectedDepartures'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 3
            Position.ColIndex = 11
            Position.RowIndex = 0
          end
          object tvStatsArrivedRooms: TcxGridDBBandedColumn
            Caption = 'Arrived Rooms'
            DataBinding.FieldName = 'arrivedRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 3
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object tvStatsExpectedArrivals: TcxGridDBBandedColumn
            Caption = 'Expected Arrivals'
            DataBinding.FieldName = 'expectedArrivals'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 3
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
        end
        object lvStat: TcxGridLevel
          GridView = tvStats
        end
      end
    end
    object tsComparison: TsTabSheet
      Caption = 'Comparison'
      object sPanel3: TsPanel
        Left = 0
        Top = 0
        Width = 1451
        Height = 97
        Align = alTop
        FullRepaint = False
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object gbxComparisonStartDate: TsGroupBox
          AlignWithMargins = True
          Left = 4
          Top = 4
          Width = 135
          Height = 89
          Align = alLeft
          Caption = 'Select start date'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          SkinData.SkinSection = 'GROUPBOX'
          object dtComparisonStart: TsDateEdit
            Left = 12
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
            TabOrder = 0
            Text = '  -  -    '
            SkinData.SkinSection = 'EDIT'
            GlyphMode.Blend = 0
            GlyphMode.Grayed = False
          end
        end
        object gbxComparisonPeriod: TsGroupBox
          AlignWithMargins = True
          Left = 145
          Top = 4
          Width = 147
          Height = 89
          Align = alLeft
          Caption = '.. or select same period'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          SkinData.SkinSection = 'GROUPBOX'
          object cbxComparisonPeriod: TsComboBox
            Left = 11
            Top = 20
            Width = 121
            Height = 21
            Alignment = taLeftJustify
            BoundLabel.Font.Charset = DEFAULT_CHARSET
            BoundLabel.Font.Color = clWindowText
            BoundLabel.Font.Height = -13
            BoundLabel.Font.Name = 'Tahoma'
            BoundLabel.Font.Style = []
            SkinData.SkinSection = 'COMBOBOX'
            VerticalAlignment = taAlignTop
            Style = csDropDownList
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 0
            OnChange = cbxComparisonPeriodChange
            Items.Strings = (
              '')
          end
        end
        object rgCompareOn: TsRadioGroup
          AlignWithMargins = True
          Left = 298
          Top = 4
          Width = 131
          Height = 89
          Align = alLeft
          Caption = 'Compare'
          TabOrder = 2
          ItemIndex = 0
          Items.Strings = (
            'Show days'
            'Show months')
        end
        object gbxComparisonData: TsGroupBox
          AlignWithMargins = True
          Left = 435
          Top = 4
          Width = 356
          Height = 89
          Align = alLeft
          Caption = 'Data to compare'
          TabOrder = 3
          object clbComparisonDataSelection: TsCheckListBox
            Left = 2
            Top = 15
            Width = 352
            Height = 72
            Align = alClient
            BevelOuter = bvNone
            BorderStyle = bsSingle
            Color = 14540253
            Columns = 3
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 4013373
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Items.Strings = (
              '<auto filled>')
            ParentFont = False
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
            OnClickCheck = clbComparisonDataSelectionClickCheck
          end
        end
        object gbxComparisonRoomTypes: TsGroupBox
          AlignWithMargins = True
          Left = 797
          Top = 4
          Width = 304
          Height = 89
          Hint = 'Future extension'
          Align = alLeft
          Caption = 'Compare on room type'
          Enabled = False
          TabOrder = 4
          object clbCompareRoomTypes: TsCheckListBox
            Left = 2
            Top = 15
            Width = 300
            Height = 72
            Align = alClient
            BevelOuter = bvNone
            BorderStyle = bsSingle
            Color = 14540253
            Columns = 3
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 4013373
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Items.Strings = (
              '<auto filled>')
            ParentFont = False
            TabOrder = 0
            SkinData.SkinSection = 'GROUPBOX'
          end
        end
        object pnlExportButtons: TsPanel
          Left = 1324
          Top = 1
          Width = 126
          Height = 95
          Align = alRight
          BevelOuter = bvNone
          TabOrder = 5
          object btnComparisonExcel: TsButton
            AlignWithMargins = True
            Left = 10
            Top = 3
            Width = 113
            Height = 35
            Margins.Left = 10
            Align = alTop
            Caption = 'Excel'
            ImageIndex = 132
            Images = DImages.PngImageList1
            TabOrder = 0
            OnClick = btnComparisonExcelClick
            SkinData.SkinSection = 'BUTTON'
          end
          object btnComparisonReport: TsButton
            AlignWithMargins = True
            Left = 10
            Top = 44
            Width = 113
            Height = 35
            Margins.Left = 10
            Align = alTop
            Caption = 'Report'
            ImageIndex = 118
            Images = DImages.PngImageList1
            TabOrder = 1
            OnClick = btnComparisonReportClick
            SkinData.SkinSection = 'BUTTON'
          end
        end
      end
      object grdComparison: TcxGrid
        Left = 0
        Top = 97
        Width = 1451
        Height = 410
        Align = alClient
        TabOrder = 1
        object grdComparisonDBBandedTableView1: TcxGridDBBandedTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          Bands = <
            item
            end>
        end
        object tvComparison: TcxGridDBBandedTableView
          Navigator.Buttons.CustomButtons = <>
          DataController.DataSource = dsComparison
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonsoldRoomsBase
            end
            item
              Format = '0'
              Column = tvComparisonaDateBase
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonmaxRateBase
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonminRateBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalGuestsBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalSellableRoomsBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonoooRoomsBase
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalGuestsBase
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalSellableRoomsBase
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonoooRoomsBase
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonsoldRoomsBase
            end
            item
              Format = '0.00'
              Kind = skMax
              Position = spFooter
              Column = tvComparisonmaxRateBase
            end
            item
              Format = '0.00'
              Kind = skMin
              Position = spFooter
              Column = tvComparisonminRateBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalDiscountBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisontotalDiscountBase
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonsoldRooms
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonoooRooms
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalSellableRooms
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalGuests
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonsoldRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonoooRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalSellableRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalGuests
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonSoldRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonOooRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonTotalSellableRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonTotalGuestsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonSoldRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonOooRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonTotalSellableRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonTotalGuestsDiff
            end
            item
              Format = '0.00'
              Kind = skMin
              Position = spFooter
              Column = tvComparisonminRate
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonminRate
            end
            item
              Format = '0.00'
              Kind = skMax
              Position = spFooter
              Column = tvComparisonmaxRate
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonmaxRate
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonRevenueBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonRevenueBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonrevenue
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonrevenue
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisontotalDiscount
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisontotalDiscount
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonRevenueDiff
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonRevenueDiff
            end
            item
              Format = '0.00'
              Kind = skSum
              Position = spFooter
              Column = tvComparisonTotalDiscountDiff
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonTotalDiscountDiff
            end
            item
              Format = '0.00'
              Kind = skMax
              Position = spFooter
              Column = tvComparisonMaxRateDiff
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonMaxRateDiff
            end
            item
              Format = '0.00'
              Kind = skMin
              Position = spFooter
              Column = tvComparisonMinRateDiff
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonMinRateDiff
            end
            item
              Format = '0.00'
              Kind = skAverage
              Position = spFooter
              Column = tvComparisonrevParBase
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonrevParBase
            end
            item
              Format = '0.00'
              Kind = skAverage
              Position = spFooter
              Column = tvComparisonadrBase
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonadrBase
            end
            item
              Format = '0%'
              Kind = skAverage
              Position = spFooter
              Column = tvComparisonOccBase
            end
            item
              Format = '0%'
              Kind = skAverage
              Tag = 12
              Column = tvComparisonOccBase
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonsoldRoomsBase
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonmaxRateBase
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonminRateBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalGuestsBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalSellableRoomsBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonoooRoomsBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisontotalDiscountBase
            end
            item
              Format = '0'
              Kind = skCount
              Column = tvComparisonaDateBase
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonsoldRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonoooRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalSellableRooms
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisontotalGuests
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonSoldRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonOooRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonTotalSellableRoomsDiff
            end
            item
              Format = '0'
              Kind = skSum
              Column = tvComparisonTotalGuestsDiff
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonminRate
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonmaxRate
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonRevenueBase
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonrevenue
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisontotalDiscount
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonRevenueDiff
            end
            item
              Format = '0.00'
              Kind = skSum
              Column = tvComparisonTotalDiscountDiff
            end
            item
              Format = '0.00'
              Kind = skMax
              Column = tvComparisonMaxRateDiff
            end
            item
              Format = '0.00'
              Kind = skMin
              Column = tvComparisonMinRateDiff
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonrevParBase
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonadrBase
            end
            item
              Format = '0%'
              Kind = skAverage
              Column = tvComparisonOccBase
            end
            item
              Format = '0%'
              Kind = skAverage
              Column = tvComparisonocc
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonadr
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonrevPar
            end
            item
              Format = '0%'
              Kind = skAverage
              Column = tvComparisonOccDiff
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonAdrDiff
            end
            item
              Format = '0.00'
              Kind = skAverage
              Column = tvComparisonRevParDiff
            end>
          DataController.Summary.SummaryGroups = <>
          DataController.Summary.OnAfterSummary = tvComparisonDataControllerSummaryAfterSummary
          OptionsBehavior.BandHeaderHints = False
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsSelection.CellSelect = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          OptionsView.GroupFooters = gfVisibleWhenExpanded
          OptionsView.GroupSummaryLayout = gslAlignWithColumnsAndDistribute
          OptionsView.HeaderAutoHeight = True
          Styles.GroupSummary = cxstContent
          Styles.StyleSheet = cxssRoomerGridBandedTableView
          Styles.BandBackground = cxstBandHeaderBackground
          Styles.BandHeader = cxstBandHeader
          Bands = <
            item
              Caption = 'Base data'
            end
            item
              Caption = 'Compared data'
            end
            item
              Caption = 'Difference (1st - 2nd)'
            end>
          object tvComparisonDateBaseDay: TcxGridDBBandedColumn
            Caption = 'Day'
            DataBinding.FieldName = 'aDateBase'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.DisplayFormat = 'ddd'
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvComparisonaDateBase: TcxGridDBBandedColumn
            DataBinding.FieldName = 'aDateBase'
            PropertiesClassName = 'TcxDateEditProperties'
            DateTimeGrouping = dtgByMonth
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvComparisonRevenueBase: TcxGridDBBandedColumn
            Tag = 1
            DataBinding.FieldName = 'RevenueBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvComparisonOccBase: TcxGridDBBandedColumn
            Tag = 2
            DataBinding.FieldName = 'OccBase'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0%'
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvComparisonadrBase: TcxGridDBBandedColumn
            Tag = 3
            DataBinding.FieldName = 'adrBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvComparisonrevParBase: TcxGridDBBandedColumn
            Tag = 4
            DataBinding.FieldName = 'revParBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvComparisontotalDiscountBase: TcxGridDBBandedColumn
            Tag = 5
            DataBinding.FieldName = 'totalDiscountBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvComparisonmaxRateBase: TcxGridDBBandedColumn
            Tag = 6
            DataBinding.FieldName = 'maxRateBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvComparisonminRateBase: TcxGridDBBandedColumn
            Tag = 7
            DataBinding.FieldName = 'minRateBase'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 0
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvComparisontotalGuestsBase: TcxGridDBBandedColumn
            Tag = 8
            DataBinding.FieldName = 'totalGuestsBase'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 0
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object tvComparisontotalSellableRoomsBase: TcxGridDBBandedColumn
            Tag = 9
            DataBinding.FieldName = 'totalSellableRoomsBase'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 0
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object tvComparisonoooRoomsBase: TcxGridDBBandedColumn
            Tag = 10
            DataBinding.FieldName = 'oooRoomsBase'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 0
            Position.ColIndex = 11
            Position.RowIndex = 0
          end
          object tvComparisonsoldRoomsBase: TcxGridDBBandedColumn
            Tag = 11
            DataBinding.FieldName = 'soldRoomsBase'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 0
            Position.ColIndex = 12
            Position.RowIndex = 0
          end
          object tvComparisonrevenue: TcxGridDBBandedColumn
            Tag = 1
            DataBinding.FieldName = 'revenue'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvComparisonDateDay: TcxGridDBBandedColumn
            Caption = 'Day'
            DataBinding.FieldName = 'ADate'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.DisplayFormat = 'ddd'
            Position.BandIndex = 1
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvComparisonADate: TcxGridDBBandedColumn
            DataBinding.FieldName = 'ADate'
            PropertiesClassName = 'TcxDateEditProperties'
            Position.BandIndex = 1
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvComparisonocc: TcxGridDBBandedColumn
            Tag = 2
            DataBinding.FieldName = 'occ'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0%'
            Position.BandIndex = 1
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvComparisonadr: TcxGridDBBandedColumn
            Tag = 3
            DataBinding.FieldName = 'adr'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvComparisonrevPar: TcxGridDBBandedColumn
            Tag = 4
            DataBinding.FieldName = 'revPar'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvComparisontotalDiscount: TcxGridDBBandedColumn
            Tag = 5
            DataBinding.FieldName = 'totalDiscount'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvComparisonmaxRate: TcxGridDBBandedColumn
            Tag = 6
            DataBinding.FieldName = 'maxRate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvComparisonminRate: TcxGridDBBandedColumn
            Tag = 7
            DataBinding.FieldName = 'minRate'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 1
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvComparisontotalGuests: TcxGridDBBandedColumn
            Tag = 8
            DataBinding.FieldName = 'totalGuests'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 1
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object tvComparisontotalSellableRooms: TcxGridDBBandedColumn
            Tag = 9
            DataBinding.FieldName = 'totalSellableRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 1
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object tvComparisonoooRooms: TcxGridDBBandedColumn
            Tag = 10
            DataBinding.FieldName = 'oooRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 1
            Position.ColIndex = 11
            Position.RowIndex = 0
          end
          object tvComparisonsoldRooms: TcxGridDBBandedColumn
            Tag = 11
            DataBinding.FieldName = 'soldRooms'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 1
            Position.ColIndex = 12
            Position.RowIndex = 0
          end
          object tvComparisonRevenueDiff: TcxGridDBBandedColumn
            Tag = 1
            DataBinding.FieldName = 'RevenueDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvComparisonOccDiff: TcxGridDBBandedColumn
            Tag = 2
            DataBinding.FieldName = 'OccDiff'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0%'
            Position.BandIndex = 2
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvComparisonAdrDiff: TcxGridDBBandedColumn
            Tag = 3
            DataBinding.FieldName = 'AdrDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvComparisonRevParDiff: TcxGridDBBandedColumn
            Tag = 4
            DataBinding.FieldName = 'RevParDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvComparisonTotalDiscountDiff: TcxGridDBBandedColumn
            Tag = 5
            DataBinding.FieldName = 'TotalDiscountDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvComparisonMaxRateDiff: TcxGridDBBandedColumn
            Tag = 6
            DataBinding.FieldName = 'MaxRateDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvComparisonMinRateDiff: TcxGridDBBandedColumn
            Tag = 7
            DataBinding.FieldName = 'MinRateDiff'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvStatsGetDefaultCurrencyProperties
            Position.BandIndex = 2
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvComparisonTotalGuestsDiff: TcxGridDBBandedColumn
            Tag = 8
            DataBinding.FieldName = 'TotalGuestsDiff'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 2
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvComparisonTotalSellableRoomsDiff: TcxGridDBBandedColumn
            Tag = 9
            DataBinding.FieldName = 'TotalSellableRoomsDiff'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 2
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvComparisonOooRoomsDiff: TcxGridDBBandedColumn
            Tag = 10
            DataBinding.FieldName = 'OooRoomsDiff'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 2
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object tvComparisonSoldRoomsDiff: TcxGridDBBandedColumn
            Tag = 11
            DataBinding.FieldName = 'SoldRoomsDiff'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.DisplayFormat = '0'
            OnGetDisplayText = tvStatsHideZeroValues
            Position.BandIndex = 2
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
        end
        object lvComparison: TcxGridLevel
          GridView = tvComparison
          Options.DetailFrameWidth = 2
        end
      end
    end
    object tabGraph: TsTabSheet
      Caption = 'Charts'
      object pageCharts: TsPageControl
        Left = 0
        Top = 0
        Width = 1451
        Height = 507
        ActivePage = tabOcc
        Align = alClient
        TabOrder = 0
        SkinData.SkinSection = 'PAGECONTROL'
        object tabOcc: TsTabSheet
          Caption = 'OCC'
          object sPanel2: TsPanel
            Left = 0
            Top = 0
            Width = 1443
            Height = 33
            Align = alTop
            TabOrder = 0
            SkinData.SkinSection = 'PANEL'
            object sButton2: TsButton
              AlignWithMargins = True
              Left = 16
              Top = 6
              Width = 128
              Height = 21
              Margins.Left = 15
              Margins.Top = 5
              Margins.Bottom = 5
              Align = alLeft
              Caption = 'Create Chart'
              ImageIndex = 0
              TabOrder = 0
              OnClick = sButton2Click
              SkinData.SkinSection = 'BUTTON'
            end
          end
          object Chart1: TChart
            Left = 0
            Top = 33
            Width = 1443
            Height = 446
            Legend.Visible = False
            SubTitle.Font.Color = clBlack
            Title.Text.Strings = (
              'Occupancy')
            BottomAxis.LabelsFont.Height = -12
            SeriesGroups = <
              item
                Name = 'Group1'
              end>
            View3DWalls = False
            Align = alClient
            BevelOuter = bvNone
            Color = clWhite
            TabOrder = 1
            PrintMargins = (
              15
              29
              15
              29)
            ColorPaletteIndex = 10
            object Series1: TLineSeries
              Marks.Arrow.Visible = True
              Marks.Callout.Brush.Color = clBlack
              Marks.Callout.Arrow.Visible = True
              Marks.Visible = False
              Brush.BackColor = clDefault
              LinePen.Color = 390140
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              Pointer.Visible = False
              TreatNulls = tnIgnore
              XValues.Name = 'X'
              XValues.Order = loAscending
              YValues.Name = 'Y'
              YValues.Order = loNone
              Data = {
                0007000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000}
            end
          end
        end
      end
    end
  end
  object kbmStat: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ADate'
        DataType = ftDate
      end
      item
        Name = 'revenue'
        DataType = ftFloat
      end
      item
        Name = 'occ'
        DataType = ftFloat
      end
      item
        Name = 'adr'
        DataType = ftFloat
      end
      item
        Name = 'revPar'
        DataType = ftFloat
      end
      item
        Name = 'currency'
        DataType = ftWideString
        Size = 10
      end
      item
        Name = 'totalDiscount'
        DataType = ftFloat
      end
      item
        Name = 'maxRate'
        DataType = ftFloat
      end
      item
        Name = 'minRate'
        DataType = ftFloat
      end
      item
        Name = 'totalGuests'
        DataType = ftInteger
      end
      item
        Name = 'totalSellableRooms'
        DataType = ftInteger
      end
      item
        Name = 'oooRooms'
        DataType = ftInteger
      end
      item
        Name = 'soldRooms'
        DataType = ftInteger
      end
      item
        Name = 'inHouse'
        DataType = ftInteger
      end
      item
        Name = 'checkedInToday'
        DataType = ftInteger
      end
      item
        Name = 'remainingArrivals'
        DataType = ftInteger
      end
      item
        Name = 'noShow'
        DataType = ftInteger
      end
      item
        Name = 'remainingDepartures'
        DataType = ftInteger
      end
      item
        Name = 'departedRooms'
        DataType = ftInteger
      end
      item
        Name = 'expectedArrivals'
        DataType = ftInteger
      end
      item
        Name = 'arrivedRooms'
        DataType = ftInteger
      end
      item
        Name = 'expectedDepartures'
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
    Left = 504
    Top = 392
  end
  object StatDS: TDataSource
    DataSet = kbmStat
    Left = 560
    Top = 392
  end
  object AdvChartPanesEditorDialog1: TAdvChartPanesEditorDialog
    Left = 1032
    Top = 40
  end
  object FormStore: TcxPropertiesStore
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
    StorageName = 'Software\Roomer\FormStatus\frmRptManagment'
    StorageType = stRegistry
    Left = 1074
    Top = 6
  end
  object kbmStatReport: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ADate'
        DataType = ftDate
      end
      item
        Name = 'revenue'
        DataType = ftFloat
      end
      item
        Name = 'occ'
        DataType = ftFloat
      end
      item
        Name = 'adr'
        DataType = ftFloat
      end
      item
        Name = 'revPar'
        DataType = ftFloat
      end
      item
        Name = 'currency'
        DataType = ftWideString
        Size = 10
      end
      item
        Name = 'totalDiscount'
        DataType = ftFloat
      end
      item
        Name = 'maxRate'
        DataType = ftFloat
      end
      item
        Name = 'minRate'
        DataType = ftFloat
      end
      item
        Name = 'totalGuests'
        DataType = ftInteger
      end
      item
        Name = 'totalSellableRooms'
        DataType = ftInteger
      end
      item
        Name = 'oooRooms'
        DataType = ftInteger
      end
      item
        Name = 'soldRooms'
        DataType = ftInteger
      end
      item
        Name = 'inHouse'
        DataType = ftInteger
      end
      item
        Name = 'checkedInToday'
        DataType = ftInteger
      end
      item
        Name = 'remainingArrivals'
        DataType = ftInteger
      end
      item
        Name = 'noShow'
        DataType = ftInteger
      end
      item
        Name = 'remainingDepartures'
        DataType = ftInteger
      end
      item
        Name = 'departedRooms'
        DataType = ftInteger
      end
      item
        Name = 'expectedArrivals'
        DataType = ftInteger
      end
      item
        Name = 'arrivedRooms'
        DataType = ftInteger
      end
      item
        Name = 'expectedDepartures'
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
    Top = 408
  end
  object dsStatReport: TDataSource
    DataSet = kbmStatReport
    Left = 296
    Top = 408
  end
  object plStats: TppDBPipeline
    DataSource = dsStatReport
    UserName = 'plStats'
    Left = 304
    Top = 459
    object plStatsppField1: TppField
      FieldAlias = 'ADate'
      FieldName = 'ADate'
      FieldLength = 0
      DataType = dtDate
      DisplayWidth = 10
      Position = 0
    end
    object plStatsppField2: TppField
      Alignment = taRightJustify
      FieldAlias = 'revenue'
      FieldName = 'revenue'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 1
    end
    object plStatsppField3: TppField
      Alignment = taRightJustify
      FieldAlias = 'occ'
      FieldName = 'occ'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 2
    end
    object plStatsppField4: TppField
      Alignment = taRightJustify
      FieldAlias = 'adr'
      FieldName = 'adr'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 3
    end
    object plStatsppField5: TppField
      Alignment = taRightJustify
      FieldAlias = 'revPar'
      FieldName = 'revPar'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 4
    end
    object plStatsppField6: TppField
      FieldAlias = 'currency'
      FieldName = 'currency'
      FieldLength = 10
      DisplayWidth = 10
      Position = 5
    end
    object plStatsppField7: TppField
      Alignment = taRightJustify
      FieldAlias = 'totalDiscount'
      FieldName = 'totalDiscount'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 6
    end
    object plStatsppField8: TppField
      Alignment = taRightJustify
      FieldAlias = 'maxRate'
      FieldName = 'maxRate'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 7
    end
    object plStatsppField9: TppField
      Alignment = taRightJustify
      FieldAlias = 'minRate'
      FieldName = 'minRate'
      FieldLength = 0
      DataType = dtDouble
      DisplayWidth = 10
      Position = 8
    end
    object plStatsppField10: TppField
      Alignment = taRightJustify
      FieldAlias = 'totalGuests'
      FieldName = 'totalGuests'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 9
    end
    object plStatsppField11: TppField
      Alignment = taRightJustify
      FieldAlias = 'totalSellableRooms'
      FieldName = 'totalSellableRooms'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 10
    end
    object plStatsppField12: TppField
      Alignment = taRightJustify
      FieldAlias = 'oooRooms'
      FieldName = 'oooRooms'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 11
    end
    object plStatsppField13: TppField
      Alignment = taRightJustify
      FieldAlias = 'soldRooms'
      FieldName = 'soldRooms'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 12
    end
    object plStatsppField14: TppField
      Alignment = taRightJustify
      FieldAlias = 'inHouse'
      FieldName = 'inHouse'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 13
    end
    object plStatsppField15: TppField
      Alignment = taRightJustify
      FieldAlias = 'checkedInToday'
      FieldName = 'checkedInToday'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 14
    end
    object plStatsppField16: TppField
      Alignment = taRightJustify
      FieldAlias = 'remainingArrivals'
      FieldName = 'remainingArrivals'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 15
    end
    object plStatsppField17: TppField
      Alignment = taRightJustify
      FieldAlias = 'noShow'
      FieldName = 'noShow'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 16
    end
    object plStatsppField18: TppField
      Alignment = taRightJustify
      FieldAlias = 'remainingDepartures'
      FieldName = 'remainingDepartures'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 17
    end
    object plStatsppField19: TppField
      Alignment = taRightJustify
      FieldAlias = 'departedRooms'
      FieldName = 'departedRooms'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 18
    end
    object plStatsppField20: TppField
      Alignment = taRightJustify
      FieldAlias = 'expectedArrivals'
      FieldName = 'expectedArrivals'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 19
    end
    object plStatsppField21: TppField
      Alignment = taRightJustify
      FieldAlias = 'arrivedRooms'
      FieldName = 'arrivedRooms'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 20
    end
    object plStatsppField22: TppField
      Alignment = taRightJustify
      FieldAlias = 'expectedDepartures'
      FieldName = 'expectedDepartures'
      FieldLength = 0
      DataType = dtInteger
      DisplayWidth = 10
      Position = 21
    end
  end
  object rptStats: TppReport
    AutoStop = False
    DataPipeline = plStats
    PassSetting = psTwoPass
    PrinterSetup.BinName = 'Default'
    PrinterSetup.DocumentName = 'Report'
    PrinterSetup.Orientation = poLandscape
    PrinterSetup.PaperName = 'A4'
    PrinterSetup.PrinterName = 'Default'
    PrinterSetup.SaveDeviceSettings = False
    PrinterSetup.mmMarginBottom = 6350
    PrinterSetup.mmMarginLeft = 6350
    PrinterSetup.mmMarginRight = 6350
    PrinterSetup.mmMarginTop = 6350
    PrinterSetup.mmPaperHeight = 210000
    PrinterSetup.mmPaperWidth = 297000
    PrinterSetup.PaperSize = 9
    AllowPrintToArchive = True
    AllowPrintToFile = True
    ArchiveFileName = '($MyDocuments)\ReportArchive.raf'
    BeforePrint = rptStatsBeforePrint
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
    Left = 216
    Top = 459
    Version = '14.07'
    mmColumnWidth = 284300
    DataPipelineName = 'plStats'
    object ppHeaderBand1: TppHeaderBand
      BeforePrint = ppHeaderBand1BeforePrint
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 37306
      mmPrintPosition = 0
      object ppLabel4: TppLabel
        UserName = 'Label4'
        Caption = 'Room/Rent statistics Report'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 18
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 7535
        mmLeft = 2646
        mmTop = 529
        mmWidth = 85344
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel5: TppLabel
        UserName = 'Label5'
        Caption = 'From :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3704
        mmLeft = 2910
        mmTop = 9525
        mmWidth = 9790
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
        mmHeight = 3704
        mmLeft = 15081
        mmTop = 9525
        mmWidth = 15875
        BandType = 0
        LayerName = Foreground
      end
      object rLabTo: TppLabel
        UserName = 'rLabTo'
        Caption = '01.01.2010'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3704
        mmLeft = 42333
        mmTop = 9525
        mmWidth = 15875
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel6: TppLabel
        UserName = 'Label6'
        Caption = 'To :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 34660
        mmTop = 9525
        mmWidth = 5556
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
        mmHeight = 3704
        mmLeft = 268553
        mmTop = 529
        mmWidth = 15610
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
        mmHeight = 3704
        mmLeft = 281253
        mmTop = 4763
        mmWidth = 2910
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
        mmHeight = 3704
        mmLeft = 259028
        mmTop = 9525
        mmWidth = 25135
        BandType = 0
        LayerName = Foreground
      end
      object ppLine11: TppLine
        UserName = 'Line11'
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 529
        mmLeft = 0
        mmTop = 14288
        mmWidth = 284300
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel1: TppLabel
        UserName = 'Label1'
        AutoSize = False
        Caption = 'Date'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taCentered
        Transparent = True
        mmHeight = 3260
        mmLeft = 794
        mmTop = 29369
        mmWidth = 21167
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel2: TppLabel
        UserName = 'Label2'
        AutoSize = False
        Caption = 'Revenue'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 23283
        mmTop = 29369
        mmWidth = 18256
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel3: TppLabel
        UserName = 'Label3'
        AutoSize = False
        Caption = 'Occ'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 42333
        mmTop = 29369
        mmWidth = 8731
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel7: TppLabel
        UserName = 'Label7'
        AutoSize = False
        Caption = 'ADR'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 51594
        mmTop = 29369
        mmWidth = 11113
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel9: TppLabel
        UserName = 'Label9'
        AutoSize = False
        Caption = 'RevPar'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 63236
        mmTop = 29369
        mmWidth = 12435
        BandType = 0
        LayerName = Foreground
      end
      object ppLine3: TppLine
        UserName = 'Line3'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 20902
        mmLeft = 76465
        mmTop = 14288
        mmWidth = 265
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel11: TppLabel
        UserName = 'Label11'
        AutoSize = False
        Caption = 'Total Discount'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 77258
        mmTop = 24871
        mmWidth = 17198
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel12: TppLabel
        UserName = 'Label12'
        AutoSize = False
        Caption = 'Max'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 94986
        mmTop = 29369
        mmWidth = 19050
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel13: TppLabel
        UserName = 'Label13'
        AutoSize = False
        Caption = 'Min'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3260
        mmLeft = 114829
        mmTop = 29369
        mmWidth = 19050
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel15: TppLabel
        UserName = 'Label15'
        AutoSize = False
        Caption = 'Total Guests'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 135467
        mmTop = 24871
        mmWidth = 13229
        BandType = 0
        LayerName = Foreground
      end
      object ppLine5: TppLine
        UserName = 'Line5'
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 20638
        mmLeft = 149754
        mmTop = 14288
        mmWidth = 265
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel16: TppLabel
        UserName = 'Label16'
        AutoSize = False
        Caption = 'Total Sellable Rooms'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 11113
        mmLeft = 149754
        mmTop = 21431
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel17: TppLabel
        UserName = 'Label17'
        AutoSize = False
        Caption = 'Sold Rooms'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 161925
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel18: TppLabel
        UserName = 'Label18'
        AutoSize = False
        Caption = 'In House'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7408
        mmLeft = 174890
        mmTop = 25135
        mmWidth = 10583
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel19: TppLabel
        UserName = 'Label19'
        AutoSize = False
        Caption = 'Checked In Today'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 11113
        mmLeft = 186267
        mmTop = 21431
        mmWidth = 11113
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel20: TppLabel
        UserName = 'Label20'
        AutoSize = False
        Caption = 'Remain. Arr.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 197644
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel21: TppLabel
        UserName = 'Label21'
        AutoSize = False
        Caption = 'No Show'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 209550
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel22: TppLabel
        UserName = 'Label22'
        AutoSize = False
        Caption = 'Remain. Dep.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 221457
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel23: TppLabel
        UserName = 'Label23'
        AutoSize = False
        Caption = 'Main'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 10
        Font.Style = [fsBold]
        TextAlignment = taCentered
        Transparent = True
        mmHeight = 4191
        mmLeft = 1323
        mmTop = 16140
        mmWidth = 75406
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel24: TppLabel
        UserName = 'Label24'
        AutoSize = False
        Caption = 'Rate'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 10
        Font.Style = [fsBold]
        TextAlignment = taCentered
        Transparent = True
        mmHeight = 4191
        mmLeft = 76465
        mmTop = 16140
        mmWidth = 73554
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel25: TppLabel
        UserName = 'Label25'
        AutoSize = False
        Caption = 'Status'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 10
        Font.Style = [fsBold]
        TextAlignment = taCentered
        Transparent = True
        mmHeight = 4233
        mmLeft = 149754
        mmTop = 16140
        mmWidth = 135732
        BandType = 0
        LayerName = Foreground
      end
      object rLabCurrency: TppLabel
        UserName = 'rLabCurrency'
        Caption = 'Currency : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 129117
        mmTop = 9525
        mmWidth = 16595
        BandType = 0
        LayerName = Foreground
      end
      object rLabCurrencyCode: TppLabel
        UserName = 'rLabCurrency1'
        Caption = 'EUR'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = [fsBold]
        Transparent = True
        mmHeight = 3810
        mmLeft = 145786
        mmTop = 9525
        mmWidth = 6689
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel10: TppLabel
        UserName = 'Label10'
        AutoSize = False
        Caption = 'Dep. Rooms'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 233363
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLine1: TppLine
        UserName = 'Line1'
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 1588
        mmLeft = 0
        mmTop = 35454
        mmWidth = 284300
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel26: TppLabel
        UserName = 'Label101'
        AutoSize = False
        Caption = 'Exp. Arrivals'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 245269
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel27: TppLabel
        UserName = 'Label102'
        AutoSize = False
        Caption = 'Arrived Rooms'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 257440
        mmTop = 24871
        mmWidth = 11684
        BandType = 0
        LayerName = Foreground
      end
      object ppLabel28: TppLabel
        UserName = 'Label103'
        AutoSize = False
        Caption = 'Exp. Depart.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        WordWrap = True
        mmHeight = 7673
        mmLeft = 268288
        mmTop = 24871
        mmWidth = 14023
        BandType = 0
        LayerName = Foreground
      end
    end
    object ppDetailBand1: TppDetailBand
      Background1.Brush.Style = bsClear
      Background2.Brush.Style = bsClear
      PrintHeight = phDynamic
      mmBottomOffset = 0
      mmHeight = 4763
      mmPrintPosition = 0
      object redtRevenue: TppDBText
        UserName = 'redtRevenue'
        DataField = 'revenue'
        DataPipeline = plStats
        DisplayFormat = '#,0.00;-#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 23283
        mmTop = 0
        mmWidth = 18256
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText3: TppDBText
        UserName = 'DBText3'
        DataField = 'occ'
        DataPipeline = plStats
        DisplayFormat = '0%'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 42333
        mmTop = 0
        mmWidth = 8731
        BandType = 4
        LayerName = Foreground
      end
      object redtADR: TppDBText
        UserName = 'redtADR'
        DataField = 'adr'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 51594
        mmTop = 0
        mmWidth = 11113
        BandType = 4
        LayerName = Foreground
      end
      object redtRevPar: TppDBText
        UserName = 'redtRevPar'
        DataField = 'revPar'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 63236
        mmTop = 0
        mmWidth = 12435
        BandType = 4
        LayerName = Foreground
      end
      object ppLine4: TppLine
        UserName = 'Line4'
        ParentHeight = True
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 4763
        mmLeft = 76465
        mmTop = 0
        mmWidth = 265
        BandType = 4
        LayerName = Foreground
      end
      object redtDiscount: TppDBText
        UserName = 'redtDiscount'
        DataField = 'totalDiscount'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 77258
        mmTop = 0
        mmWidth = 17198
        BandType = 4
        LayerName = Foreground
      end
      object redtMaxRate: TppDBText
        UserName = 'redtMaxRate'
        DataField = 'maxRate'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 94986
        mmTop = 0
        mmWidth = 19050
        BandType = 4
        LayerName = Foreground
      end
      object redtMinRate: TppDBText
        UserName = 'redtMinRate'
        DataField = 'minRate'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 114829
        mmTop = 0
        mmWidth = 19050
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText11: TppDBText
        UserName = 'DBText11'
        BlankWhenZero = True
        DataField = 'totalGuests'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 135467
        mmTop = 0
        mmWidth = 13229
        BandType = 4
        LayerName = Foreground
      end
      object ppLine6: TppLine
        UserName = 'Line6'
        ParentHeight = True
        Position = lpLeft
        Weight = 0.750000000000000000
        mmHeight = 4763
        mmLeft = 149754
        mmTop = 0
        mmWidth = 265
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText12: TppDBText
        UserName = 'DBText12'
        BlankWhenZero = True
        DataField = 'totalSellableRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 150813
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText13: TppDBText
        UserName = 'DBText13'
        BlankWhenZero = True
        DataField = 'soldRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 162984
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText14: TppDBText
        UserName = 'DBText14'
        BlankWhenZero = True
        DataField = 'inHouse'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 174890
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText15: TppDBText
        UserName = 'DBText15'
        BlankWhenZero = True
        DataField = 'checkedInToday'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 186796
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText16: TppDBText
        UserName = 'DBText16'
        BlankWhenZero = True
        DataField = 'remainingArrivals'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 198702
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText17: TppDBText
        UserName = 'DBText17'
        BlankWhenZero = True
        DataField = 'noShow'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 210609
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText18: TppDBText
        UserName = 'DBText18'
        BlankWhenZero = True
        DataField = 'remainingDepartures'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 222515
        mmTop = 0
        mmWidth = 10584
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText1: TppDBText
        UserName = 'DBText1'
        DataField = 'ADate'
        DataPipeline = plStats
        DisplayFormat = 'ddd'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 794
        mmTop = 0
        mmWidth = 7144
        BandType = 4
        LayerName = Foreground
      end
      object redtFullDate: TppDBText
        UserName = 'redtFullDate'
        DataField = 'ADate'
        DataPipeline = plStats
        DisplayFormat = 'm/d/yy'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 7938
        mmTop = 0
        mmWidth = 14552
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText2: TppDBText
        UserName = 'DBText2'
        BlankWhenZero = True
        DataField = 'departedRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 234421
        mmTop = 0
        mmWidth = 10583
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText4: TppDBText
        UserName = 'DBText4'
        BlankWhenZero = True
        DataField = 'expectedArrivals'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 246328
        mmTop = 0
        mmWidth = 10583
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText5: TppDBText
        UserName = 'DBText5'
        BlankWhenZero = True
        DataField = 'arrivedRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 258498
        mmTop = 0
        mmWidth = 10583
        BandType = 4
        LayerName = Foreground
      end
      object ppDBText6: TppDBText
        UserName = 'DBText6'
        BlankWhenZero = True
        DataField = 'expectedDepartures'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 271728
        mmTop = 0
        mmWidth = 10583
        BandType = 4
        LayerName = Foreground
      end
    end
    object ppFooterBand1: TppFooterBand
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 6615
      mmPrintPosition = 0
      object ppSystemVariable1: TppSystemVariable
        UserName = 'SystemVariable1'
        VarType = vtPageSet
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 11642
        mmTop = 2117
        mmWidth = 7938
        BandType = 8
        LayerName = Foreground
      end
      object ppLabel8: TppLabel
        UserName = 'Label8'
        Caption = 'Page :'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 9
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3704
        mmLeft = 1323
        mmTop = 2117
        mmWidth = 9260
        BandType = 8
        LayerName = Foreground
      end
      object ppLine2: TppLine
        UserName = 'Line2'
        ParentWidth = True
        Weight = 0.750000000000000000
        mmHeight = 794
        mmLeft = 0
        mmTop = 265
        mmWidth = 284300
        BandType = 8
        LayerName = Foreground
      end
    end
    object ppSummaryBand1: TppSummaryBand
      Background.Brush.Style = bsClear
      mmBottomOffset = 0
      mmHeight = 13229
      mmPrintPosition = 0
      object ppLine7: TppLine
        UserName = 'Line7'
        Pen.Width = 2
        ParentWidth = True
        Weight = 1.500000000000000000
        mmHeight = 265
        mmLeft = 0
        mmTop = 0
        mmWidth = 284300
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc1: TppDBCalc
        UserName = 'DBCalc1'
        DataField = 'adate'
        DataPipeline = plStats
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        Transparent = True
        DBCalcType = dcCount
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 794
        mmTop = 794
        mmWidth = 18256
        BandType = 7
        LayerName = Foreground
      end
      object edtRevTotal: TppDBCalc
        UserName = 'edtRevTotal'
        DataField = 'revenue'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 20902
        mmTop = 794
        mmWidth = 19579
        BandType = 7
        LayerName = Foreground
      end
      object redtDiscountTotal: TppDBCalc
        UserName = 'redtDiscountTotal'
        DataField = 'totaldiscount'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 76465
        mmTop = 794
        mmWidth = 17198
        BandType = 7
        LayerName = Foreground
      end
      object redtMaxrateMax: TppDBCalc
        UserName = 'redtMaxrateMax'
        DataField = 'maxrate'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DBCalcType = dcMaximum
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 94192
        mmTop = 794
        mmWidth = 19050
        BandType = 7
        LayerName = Foreground
      end
      object redtMinRateMin: TppDBCalc
        UserName = 'redtMinRateMin'
        DataField = 'minrate'
        DataPipeline = plStats
        DisplayFormat = '$#,0.00;-$#,0.00'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DBCalcType = dcMinimum
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 114036
        mmTop = 794
        mmWidth = 19050
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc10: TppDBCalc
        UserName = 'DBCalc10'
        DataField = 'totalguests'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 134673
        mmTop = 794
        mmWidth = 13229
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc12: TppDBCalc
        UserName = 'DBCalc12'
        DataField = 'soldRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 162984
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc13: TppDBCalc
        UserName = 'DBCalc13'
        DataField = 'inHouse'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 174890
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc14: TppDBCalc
        UserName = 'DBCalc14'
        DataField = 'checkedInToday'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 186796
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc15: TppDBCalc
        UserName = 'DBCalc15'
        DataField = 'remainingArrivals'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 198702
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc16: TppDBCalc
        UserName = 'DBCalc16'
        DataField = 'noShow'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 210609
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc17: TppDBCalc
        UserName = 'DBCalc17'
        DataField = 'remainingDepartures'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 222515
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc11: TppDBCalc
        UserName = 'DBCalc11'
        DataField = 'departedRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 234421
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc18: TppDBCalc
        UserName = 'DBCalc18'
        DataField = 'expectedArrivals'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 246328
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc19: TppDBCalc
        UserName = 'DBCalc19'
        DataField = 'arrivedRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3260
        mmLeft = 258498
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc20: TppDBCalc
        UserName = 'DBCalc20'
        DataField = 'expectedDepartures'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 271728
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object ppDBCalc2: TppDBCalc
        UserName = 'DBCalc2'
        DataField = 'totalSellableRooms'
        DataPipeline = plStats
        DisplayFormat = '#,0;-#,0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        DataPipelineName = 'plStats'
        mmHeight = 3175
        mmLeft = 150813
        mmTop = 794
        mmWidth = 10583
        BandType = 7
        LayerName = Foreground
      end
      object redtOccSummary: TppLabel
        UserName = 'redtOccSummary'
        AutoSize = False
        Caption = 'Occ'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3175
        mmLeft = 42333
        mmTop = 794
        mmWidth = 8731
        BandType = 7
        LayerName = Foreground
      end
      object redtADRSummary: TppLabel
        UserName = 'redtOccSummary1'
        AutoSize = False
        Caption = 'adr'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3175
        mmLeft = 51594
        mmTop = 794
        mmWidth = 11113
        BandType = 7
        LayerName = Foreground
      end
      object redtRevParSummary: TppLabel
        UserName = 'redtOccSummary2'
        AutoSize = False
        Caption = 'revpar'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Name = 'Arial'
        Font.Size = 8
        Font.Style = []
        TextAlignment = taRightJustified
        Transparent = True
        mmHeight = 3175
        mmLeft = 63236
        mmTop = 794
        mmWidth = 12435
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
  object kbmComparison: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ADate'
        DataType = ftDate
      end
      item
        Name = 'revenueBase'
        DataType = ftFloat
      end
      item
        Name = 'occBase'
        DataType = ftFloat
      end
      item
        Name = 'adrBase'
        DataType = ftFloat
      end
      item
        Name = 'revParBase'
        DataType = ftFloat
      end
      item
        Name = 'totalDiscountBase'
        DataType = ftFloat
      end
      item
        Name = 'maxRateBase'
        DataType = ftFloat
      end
      item
        Name = 'minRateBase'
        DataType = ftFloat
      end
      item
        Name = 'totalGuestsBase'
        DataType = ftInteger
      end
      item
        Name = 'totalSellableRoomsBase'
        DataType = ftInteger
      end
      item
        Name = 'oooRoomsBase'
        DataType = ftInteger
      end
      item
        Name = 'soldRoomsBase'
        DataType = ftInteger
      end
      item
        Name = 'revenue'
        DataType = ftFloat
      end
      item
        Name = 'occ'
        DataType = ftFloat
      end
      item
        Name = 'adr'
        DataType = ftFloat
      end
      item
        Name = 'revPar'
        DataType = ftFloat
      end
      item
        Name = 'totalDiscount'
        DataType = ftFloat
      end
      item
        Name = 'maxRate'
        DataType = ftFloat
      end
      item
        Name = 'minRate'
        DataType = ftFloat
      end
      item
        Name = 'totalGuests'
        DataType = ftInteger
      end
      item
        Name = 'totalSellableRooms'
        DataType = ftInteger
      end
      item
        Name = 'oooRooms'
        DataType = ftInteger
      end
      item
        Name = 'soldRooms'
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
    OnCalcFields = kbmComparisonCalcFields
    Left = 496
    Top = 464
    object kbmComparisonADateBase: TDateField
      DisplayLabel = 'Date'
      FieldName = 'aDateBase'
    end
    object kbmComparisoncurrency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object kbmComparisonrevenueBase: TFloatField
      DisplayLabel = 'Revenue'
      FieldName = 'RevenueBase'
    end
    object kbmComparisonoccBase: TFloatField
      DisplayLabel = 'Occupancy'
      FieldKind = fkCalculated
      FieldName = 'OccBase'
      Calculated = True
    end
    object kbmComparisonadrBase: TFloatField
      DisplayLabel = 'ADR'
      FieldKind = fkCalculated
      FieldName = 'adrBase'
      Calculated = True
    end
    object kbmComparisonrevParBase: TFloatField
      DisplayLabel = 'RevPar'
      FieldKind = fkCalculated
      FieldName = 'revParBase'
      Calculated = True
    end
    object kbmComparisontotalDiscountBase: TFloatField
      DisplayLabel = 'Total Discount'
      FieldName = 'totalDiscountBase'
    end
    object kbmComparisonmaxRateBase: TFloatField
      DisplayLabel = 'Highest Rate'
      FieldName = 'maxRateBase'
    end
    object kbmComparisonminRateBase: TFloatField
      DisplayLabel = 'Lowest Rate'
      FieldName = 'minRateBase'
    end
    object kbmComparisontotalGuestsBase: TIntegerField
      DisplayLabel = 'Total Guests'
      FieldName = 'totalGuestsBase'
    end
    object kbmComparisontotalSellableRoomsBase: TIntegerField
      DisplayLabel = 'Sellable rooms'
      FieldName = 'totalSellableRoomsBase'
    end
    object kbmComparisonoooRoomsBase: TIntegerField
      DisplayLabel = 'Out of order'
      FieldName = 'oooRoomsBase'
    end
    object kbmComparisonsoldRoomsBase: TIntegerField
      DisplayLabel = 'Sold Rooms'
      FieldName = 'soldRoomsBase'
    end
    object kbmComparisonrevenue: TFloatField
      DisplayLabel = 'Revenue'
      FieldName = 'revenue'
    end
    object kbmComparisonADate: TDateField
      DisplayLabel = 'Date'
      FieldName = 'ADate'
    end
    object kbmComparisonocc: TFloatField
      DisplayLabel = 'Occupancy'
      FieldKind = fkCalculated
      FieldName = 'occ'
      Calculated = True
    end
    object kbmComparisonadr: TFloatField
      DisplayLabel = 'ADR'
      FieldKind = fkCalculated
      FieldName = 'adr'
      Calculated = True
    end
    object kbmComparisonrevPar: TFloatField
      DisplayLabel = 'RevPar'
      FieldKind = fkCalculated
      FieldName = 'revPar'
      Calculated = True
    end
    object kbmComparisontotalDiscount: TFloatField
      DisplayLabel = 'Total Discount'
      FieldName = 'totalDiscount'
    end
    object kbmComparisonmaxRate: TFloatField
      DisplayLabel = 'Highest Rate'
      FieldName = 'maxRate'
    end
    object kbmComparisonminRate: TFloatField
      DisplayLabel = 'Lowest Rate'
      FieldName = 'minRate'
    end
    object kbmComparisontotalGuests: TIntegerField
      DisplayLabel = 'Total Guests'
      FieldName = 'totalGuests'
    end
    object kbmComparisontotalSellableRooms: TIntegerField
      DisplayLabel = 'Sellable Rooms'
      FieldName = 'totalSellableRooms'
    end
    object kbmComparisonoooRooms: TIntegerField
      DisplayLabel = 'Out of Order'
      FieldName = 'oooRooms'
    end
    object kbmComparisonsoldRooms: TIntegerField
      DisplayLabel = 'Sold Rooms'
      FieldName = 'soldRooms'
    end
    object kbmComparisonrevenueDiff: TFloatField
      DisplayLabel = 'Revenue'
      FieldKind = fkCalculated
      FieldName = 'RevenueDiff'
      Calculated = True
    end
    object kbmComparisonOccDiff: TFloatField
      DisplayLabel = 'Occupancy'
      FieldKind = fkCalculated
      FieldName = 'OccDiff'
      Calculated = True
    end
    object kbmComparisonAdrDiff: TFloatField
      DisplayLabel = 'ADR'
      FieldKind = fkCalculated
      FieldName = 'AdrDiff'
      Calculated = True
    end
    object kbmComparisonRevParDiff: TFloatField
      DisplayLabel = 'RevPar'
      FieldKind = fkCalculated
      FieldName = 'RevParDiff'
      Calculated = True
    end
    object kbmComparisonTotalDiscountDiff: TFloatField
      DisplayLabel = 'Total Discount'
      FieldKind = fkCalculated
      FieldName = 'TotalDiscountDiff'
      Calculated = True
    end
    object kbmComparisonMaxRateDiff: TFloatField
      DisplayLabel = 'Highest Rate'
      FieldKind = fkCalculated
      FieldName = 'MaxRateDiff'
      Calculated = True
    end
    object kbmComparisonMinRateDiff: TFloatField
      DisplayLabel = 'Lowest Rate'
      FieldKind = fkCalculated
      FieldName = 'MinRateDiff'
      Calculated = True
    end
    object kbmComparisonTotalGuestsDiff: TIntegerField
      DisplayLabel = 'Total Guests'
      FieldKind = fkCalculated
      FieldName = 'TotalGuestsDiff'
      Calculated = True
    end
    object kbmComparisonTotalSellableRoomsDiff: TIntegerField
      DisplayLabel = 'Sellable Rooms'
      FieldKind = fkCalculated
      FieldName = 'TotalSellableRoomsDiff'
      Calculated = True
    end
    object kbmComparisonOooRoomsDiff: TIntegerField
      DisplayLabel = 'Out Of Order'
      FieldKind = fkCalculated
      FieldName = 'OooRoomsDiff'
      Calculated = True
    end
    object kbmComparisonSoldRoomsDiff: TIntegerField
      DisplayLabel = 'Sold Rooms'
      FieldKind = fkCalculated
      FieldName = 'SoldRoomsDiff'
      Calculated = True
    end
  end
  object dsComparison: TDataSource
    DataSet = kbmComparison
    Left = 568
    Top = 464
  end
  object cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 952
    Top = 16
    PixelsPerInch = 96
    object cxstBandHeader: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstCaption: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstCardCaptionRow: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstCardRowCaption: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContent: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContentEven: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContentOdd: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstFilterBar: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstFooter: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstGroup: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstHeader: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstPreview: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstSelection: TcxStyle
    end
    object cxstReportBandHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportCardCaptionRow: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportCardRowCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContent: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContentEven: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = 16053492
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContentOdd: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportFilterBar: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnShadow
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportFooter: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportGroup: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportPreview: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportSelection: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstBandHeaderBackground: TcxStyle
      AssignedValues = [svColor]
      Color = clSilver
    end
    object dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      Caption = 'Gridprinting Styles'
      Styles.BandHeader = cxstReportBandHeader
      Styles.Caption = cxstReportCaption
      Styles.CardCaptionRow = cxstReportCardCaptionRow
      Styles.CardRowCaption = cxstReportCardRowCaption
      Styles.Content = cxstReportContent
      Styles.ContentEven = cxstReportContentEven
      Styles.ContentOdd = cxstReportContentOdd
      Styles.FilterBar = cxstReportFilterBar
      Styles.Footer = cxstReportFooter
      Styles.Group = cxstReportGroup
      Styles.Header = cxstReportHeader
      Styles.Preview = cxstReportPreview
      Styles.Selection = cxstReportSelection
      BuiltIn = True
    end
    object cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      Caption = 'Gridview Styles'
      Styles.Content = cxstContent
      Styles.ContentEven = cxstContentEven
      Styles.ContentOdd = cxstContentOdd
      Styles.Selection = cxstSelection
      Styles.Footer = cxstFooter
      Styles.Group = cxstGroup
      Styles.GroupSummary = cxstGroup
      Styles.Header = cxstHeader
      Styles.Preview = cxstPreview
      BuiltIn = True
    end
    object cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      Caption = 'cxssRoomerBandedGridTableView'
      Styles.Content = cxstContent
      Styles.ContentEven = cxstContentEven
      Styles.ContentOdd = cxstContentOdd
      Styles.Selection = cxstSelection
      Styles.Footer = cxstFooter
      Styles.Group = cxstGroup
      Styles.GroupSummary = cxstGroup
      Styles.Header = cxstHeader
      Styles.Preview = cxstPreview
      Styles.BandHeader = cxstBandHeader
      BuiltIn = True
    end
  end
  object grdPrinter: TdxComponentPrinter
    CurrentLink = grdPrinterLinkStats
    Version = 0
    Left = 856
    Top = 64
    object grdPrinterLinkComparison: TdxGridReportLink
      Active = True
      Component = grdComparison
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
      ReportDocument.CreationDate = 43194.583583993060000000
      ReportTitle.Font.Charset = DEFAULT_CHARSET
      ReportTitle.Font.Color = clBlack
      ReportTitle.Font.Height = -19
      ReportTitle.Font.Name = 'Arial'
      ReportTitle.Font.Style = [fsBold]
      ReportTitle.Text = 'Roomrent Comparison'
      ShrinkToPageWidth = True
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      OptionsFormatting.LookAndFeelKind = lfFlat
      OptionsFormatting.UseNativeStyles = True
      OptionsView.ExpandButtons = False
      OptionsView.FilterBar = False
      BuiltInReportLink = True
    end
    object grdPrinterLinkStats: TdxGridReportLink
      Component = grStat
      PageNumberFormat = pnfNumeral
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.Orientation = poLandscape
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage.ScaleMode = smFit
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.Caption = 'Roomrent statistics'
      ReportDocument.Creator = 'Roomer'
      ReportTitle.Text = 'Roomrent Statistics'
      ShrinkToPageWidth = True
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
end
