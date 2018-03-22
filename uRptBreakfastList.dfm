inherited frmBreakfastList: TfrmBreakfastList
  Caption = 'Breakfast List'
  ClientHeight = 586
  ClientWidth = 1123
  ExplicitWidth = 1139
  ExplicitHeight = 625
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 566
    Width = 1123
    ExplicitTop = 566
    ExplicitWidth = 1123
  end
  inherited pnlButtons: TsPanel
    Top = 523
    Width = 1123
    TabOrder = 0
    ExplicitTop = 523
    ExplicitWidth = 1123
    inherited btnOK: TsButton
      Left = 807
      ExplicitLeft = 807
    end
    inherited btnCancel: TsButton
      Left = 913
      ExplicitLeft = 913
    end
    inherited btnClose: TsButton
      Left = 1019
      ExplicitLeft = 1019
    end
  end
  inherited pnlTop: TsPanel
    Width = 1123
    Height = 121
    AutoSize = False
    TabOrder = 1
    ExplicitWidth = 1123
    ExplicitHeight = 121
    object pnlExportButtons: TsPanel
      Left = 0
      Top = 80
      Width = 1123
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
      object btnProfile: TsButton
        AlignWithMargins = True
        Left = 137
        Top = 3
        Width = 128
        Height = 35
        Align = alLeft
        Caption = 'Profile'
        ImageIndex = 37
        Images = DImages.PngImageList1
        TabOrder = 1
        OnClick = btnProfileClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object gbxSelectDates: TsGroupBox
      Left = 3
      Top = 0
      Width = 368
      Height = 80
      Caption = 'Select breakfast date:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
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
        Width = 83
        Height = 20
        Caption = 'Manual date:'
        TabOrder = 2
        OnClick = rbRadioButtonClick
      end
      object dtDate: TsDateEdit
        Left = 216
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
  inherited pcClient: TsPageControl
    Top = 121
    Width = 1123
    Height = 402
    ExplicitTop = 121
    ExplicitWidth = 1123
    ExplicitHeight = 402
    inherited tsMain: TsTabSheet
      inherited grData: TcxGrid
        Width = 1115
        Height = 392
        ExplicitWidth = 1115
        ExplicitHeight = 392
        inherited tvData: TcxGridDBBandedTableView
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Kind = skSum
              Position = spFooter
              Column = tvDataNumGuests
            end
            item
              Kind = skSum
              Position = spFooter
              Column = tvDatanumChildren
            end
            item
              Kind = skSum
              Position = spFooter
              Column = tvDatanumInfants
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = tvDataNumGuests
            end
            item
              Kind = skSum
              Column = tvDatanumChildren
            end
            item
              Kind = skSum
              Column = tvDatanumInfants
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
          Styles.BandHeader = cxstHeader
          Bands = <
            item
              Width = 331
            end
            item
              Caption = 'Number of'
              Width = 333
            end
            item
              Width = 453
            end>
          object tvDataReservation: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Reservation'
            Width = 80
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvDataRoomReservationID: TcxGridDBBandedColumn
            DataBinding.FieldName = 'RoomReservation'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvDataLocation: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Location'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvDataLocationDescription: TcxGridDBBandedColumn
            Caption = 'Location'
            DataBinding.FieldName = 'LocationDescription'
            PropertiesClassName = 'TcxTextEditProperties'
            Visible = False
            GroupIndex = 0
            Width = 102
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvDataRoom: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Room'
            PropertiesClassName = 'TcxTextEditProperties'
            Width = 88
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvDataMainGuest: TcxGridDBBandedColumn
            Caption = 'Guest name'
            DataBinding.FieldName = 'MainGuest'
            PropertiesClassName = 'TcxTextEditProperties'
            Width = 145
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvDataNumGuests: TcxGridDBBandedColumn
            Caption = 'Guests'
            DataBinding.FieldName = 'NumGuests'
            PropertiesClassName = 'TcxCalcEditProperties'
            HeaderAlignmentHorz = taRightJustify
            Position.BandIndex = 1
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvDatanumChildren: TcxGridDBBandedColumn
            Caption = 'Children'
            DataBinding.FieldName = 'numChildren'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetDisplayText = tvDataGetDisplayTextHideZeroes
            HeaderAlignmentHorz = taRightJustify
            Position.BandIndex = 1
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvDatanumInfants: TcxGridDBBandedColumn
            Caption = 'Infants'
            DataBinding.FieldName = 'numInfants'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetDisplayText = tvDataGetDisplayTextHideZeroes
            HeaderAlignmentHorz = taRightJustify
            Position.BandIndex = 1
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvDataRoomnotes: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Roomnotes'
            PropertiesClassName = 'TcxMemoProperties'
            Position.BandIndex = 2
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
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
    DataSet = kbmBreakfastList
    Left = 320
    Top = 424
  end
  inherited alGridActions: TActionList
    Top = 216
  end
  inherited grPrinter: TdxComponentPrinter
    Top = 216
    inherited prLink_grData: TdxGridReportLink
      PrinterPage.Orientation = poLandscape
      ReportDocument.CreationDate = 43151.492630763890000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
  object kbmBreakfastList: TkbmMemTable
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
    AfterScroll = kbmBreakfastListAfterScroll
    Left = 416
    Top = 359
    object kbmBreakfastListReservations: TIntegerField
      FieldName = 'Reservation'
    end
    object kbmBreakfastListRoomerRoomReservationID: TIntegerField
      FieldName = 'RoomReservation'
    end
    object kbmBreakfastListfldRoom: TStringField
      FieldName = 'Room'
      Size = 10
    end
    object kbmBreakfastListfldGuestName: TStringField
      FieldName = 'MainGuest'
      Size = 100
    end
    object kbmBreakfastListfldNumGuests: TIntegerField
      FieldName = 'NumGuests'
    end
    object kbmBreakfastListLocation: TWideStringField
      FieldName = 'Location'
      Size = 10
    end
    object kbmBreakfastListLocationDescription: TWideStringField
      FieldName = 'LocationDescription'
      Size = 35
    end
    object kbmBreakfastListnumChildren: TIntegerField
      FieldName = 'numChildren'
    end
    object kbmBreakfastListnumInfants: TIntegerField
      FieldName = 'numInfants'
    end
    object kbmBreakfastListRoomnotes: TWideMemoField
      FieldName = 'Roomnotes'
      BlobType = ftWideMemo
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
