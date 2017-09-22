inherited frmItemTransactionsReport: TfrmItemTransactionsReport
  Left = 961
  Top = 264
  Caption = 'Creditcard token usage reports'
  ClientHeight = 641
  ClientWidth = 1116
  Font.Height = -11
  Position = poOwnerFormCenter
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
        object btnShowReservation: TsButton
          AlignWithMargins = True
          Left = 137
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Reservaton'
          Enabled = False
          ImageIndex = 56
          Images = DImages.PngImageList1
          TabOrder = 1
          OnClick = btnShowReservationClick
          SkinData.SkinSection = 'BUTTON'
          ExplicitTop = 0
        end
        object btnShowInvoice: TsButton
          AlignWithMargins = True
          Left = 271
          Top = 3
          Width = 128
          Height = 37
          Align = alLeft
          Caption = 'Invoice'
          Enabled = False
          ImageIndex = 63
          Images = DImages.PngImageList1
          TabOrder = 2
          Visible = False
          OnClick = btnShowInvoiceClick
          SkinData.SkinSection = 'BUTTON'
          ExplicitTop = 0
        end
      end
      object gTrxList: TcxGrid
        Left = 0
        Top = 43
        Width = 1108
        Height = 487
        Align = alClient
        BevelOuter = bvNone
        BorderStyle = cxcbsNone
        TabOrder = 1
        LookAndFeel.NativeStyle = False
        object tvTrxList: TcxGridDBTableView
          OnDblClick = tvTrxListDblClick
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
          DataController.DataSource = mTrxListDS
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Format = ',0;-,0'
              Kind = skSum
              Position = spFooter
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Column = tvTrxListTotal
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
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0;-,0'
              Kind = skSum
            end
            item
              Format = ',0.00;-,0.00'
              Kind = skSum
              Column = tvTrxListTotal
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
          object tvTrxListdate: TcxGridDBColumn
            Caption = 'Date'
            DataBinding.FieldName = 'date'
            Width = 71
          end
          object tvTrxListtime: TcxGridDBColumn
            Caption = 'Time'
            DataBinding.FieldName = 'time'
            Width = 62
          end
          object tvTrxListRecId: TcxGridDBColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
          end
          object tvTrxListEVENT: TcxGridDBColumn
            Caption = 'Event'
            DataBinding.FieldName = 'EVENT'
            Options.Editing = False
            Width = 114
          end
          object tvTrxListSource: TcxGridDBColumn
            DataBinding.FieldName = 'Source'
            Width = 75
          end
          object tvTrxListItemId: TcxGridDBColumn
            Caption = 'Item'
            DataBinding.FieldName = 'ItemId'
            Width = 94
          end
          object tvTrxListItemName: TcxGridDBColumn
            Caption = 'Item name'
            DataBinding.FieldName = 'ItemName'
            Width = 142
          end
          object tvTrxListNumber: TcxGridDBColumn
            Caption = 'Quantity'
            DataBinding.FieldName = 'Number'
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListPrice: TcxGridDBColumn
            DataBinding.FieldName = 'Price'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListTotal: TcxGridDBColumn
            DataBinding.FieldName = 'Total'
            PropertiesClassName = 'TcxCurrencyEditProperties'
            OnGetProperties = tvTrxListPriceGetProperties
            HeaderAlignmentHorz = taRightJustify
          end
          object tvTrxListRoom: TcxGridDBColumn
            DataBinding.FieldName = 'Room'
            Options.Editing = False
            Width = 61
          end
          object tvTrxListGuestName: TcxGridDBColumn
            Caption = 'Name of guest'
            DataBinding.FieldName = 'GuestName'
            Options.Editing = False
            Width = 166
          end
          object tvTrxListInvoiceNumber: TcxGridDBColumn
            Caption = 'Invoice'
            DataBinding.FieldName = 'InvoiceNumber'
            OnGetDisplayText = tvTrxListInvoiceNumberGetDisplayText
            HeaderAlignmentHorz = taRightJustify
            Width = 105
          end
          object tvTrxListReservation: TcxGridDBColumn
            DataBinding.FieldName = 'Reservation'
            Options.Editing = False
            Width = 92
          end
          object tvTrxListBookingId: TcxGridDBColumn
            DataBinding.FieldName = 'BookingId'
            Options.Editing = False
            Width = 151
          end
          object tvTrxListCustomer: TcxGridDBColumn
            DataBinding.FieldName = 'Customer'
            Options.Editing = False
          end
          object tvTrxListName: TcxGridDBColumn
            Caption = 'Customer Name'
            DataBinding.FieldName = 'Name'
            Options.Editing = False
            Width = 157
          end
          object tvTrxListContactName: TcxGridDBColumn
            DataBinding.FieldName = 'ContactName'
            Options.Editing = False
            Width = 168
          end
          object tvTrxListArrival: TcxGridDBColumn
            DataBinding.FieldName = 'Arrival'
            Options.Editing = False
          end
          object tvTrxListDeparture: TcxGridDBColumn
            DataBinding.FieldName = 'Departure'
            Options.Editing = False
            Width = 76
          end
          object tvTrxListRoomReservation: TcxGridDBColumn
            DataBinding.FieldName = 'RoomReservation'
            Width = 116
          end
          object tvTrxListCountry: TcxGridDBColumn
            DataBinding.FieldName = 'Country'
            Width = 79
          end
          object tvTrxListNationality: TcxGridDBColumn
            DataBinding.FieldName = 'Nationality'
            Width = 88
          end
        end
        object lvTrxList: TcxGridLevel
          GridView = tvTrxList
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
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
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
  object mTrxList: TdxMemData
    Indexes = <>
    SortOptions = []
    AfterScroll = mTrxListAfterScroll
    Left = 256
    Top = 321
    object mTrxListEVENT: TStringField
      FieldName = 'EVENT'
      Size = 16
    end
    object mTrxListSource: TWideStringField
      FieldName = 'Source'
      Size = 10
    end
    object mTrxListItemId: TWideStringField
      FieldName = 'ItemId'
    end
    object mTrxListNumber: TFloatField
      FieldName = 'Number'
    end
    object mTrxListPrice: TFloatField
      FieldName = 'Price'
    end
    object mTrxListTotal: TFloatField
      FieldName = 'Total'
    end
    object mTrxListRoom: TWideStringField
      FieldName = 'Room'
      Size = 25
    end
    object mTrxListReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mTrxListRoomReservation: TIntegerField
      FieldName = 'RoomReservation'
    end
    object mTrxListCustomer: TWideStringField
      FieldName = 'Customer'
      Size = 15
    end
    object mTrxListName: TWideStringField
      FieldName = 'Name'
      Size = 100
    end
    object mTrxListGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 40
    end
    object mTrxListContactName: TWideStringField
      FieldName = 'ContactName'
      Size = 64
    end
    object mTrxListArrival: TDateField
      FieldName = 'Arrival'
    end
    object mTrxListDeparture: TDateField
      FieldName = 'Departure'
    end
    object mTrxListBookingId: TWideStringField
      FieldName = 'BookingId'
      Size = 64
    end
    object mTrxListCountry: TWideStringField
      FieldName = 'Country'
      Size = 2
    end
    object mTrxListNationality: TWideStringField
      FieldName = 'Nationality'
      Size = 2
    end
    object mTrxListInvoiceNumber: TIntegerField
      FieldName = 'InvoiceNumber'
    end
    object mTrxListItemName: TWideStringField
      FieldName = 'ItemName'
      Size = 35
    end
    object mTrxListdate: TDateField
      FieldName = 'date'
    end
    object mTrxListtime: TTimeField
      FieldName = 'time'
    end
    object mTrxListGroupInvoice: TBooleanField
      FieldName = 'GroupInvoice'
    end
  end
  object mTrxListDS: TDataSource
    DataSet = mTrxList
    Left = 344
    Top = 321
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
    StorageName = 'Software\Roomer\FormStatus\ItemTransactionReport'
    StorageType = stRegistry
    Left = 496
    Top = 344
  end
end
