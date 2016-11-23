inherited frmRoomPrices: TfrmRoomPrices
  Caption = 'Room Rates'
  ClientHeight = 585
  ClientWidth = 1128
  OnShow = FormShow
  ExplicitWidth = 1144
  ExplicitHeight = 624
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 565
    Width = 1128
    ExplicitTop = 565
    ExplicitWidth = 1128
  end
  object pnlTopRoomRates: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1128
    Height = 89
    Align = alTop
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object cxGroupBox4: TsGroupBox
      AlignWithMargins = True
      Left = 230
      Top = 4
      Width = 220
      Height = 81
      Align = alLeft
      Caption = 'Selected room'
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      Checked = False
      object btnRatePerDate: TsButton
        AlignWithMargins = True
        Left = 5
        Top = 16
        Width = 210
        Height = 20
        Margins.Top = 1
        Margins.Bottom = 0
        Align = alTop
        Caption = 'Change rate per date'
        TabOrder = 0
        OnClick = btnRatePerDateClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnApplyAllRoomtypes: TsButton
        AlignWithMargins = True
        Left = 5
        Top = 37
        Width = 210
        Height = 20
        Margins.Top = 1
        Margins.Bottom = 0
        Align = alTop
        Caption = 'Apply to all roomtypes'
        TabOrder = 1
        OnClick = btnApplyAllRoomtypesClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnApplySameRoomType: TsButton
        AlignWithMargins = True
        Left = 5
        Top = 58
        Width = 210
        Height = 20
        Margins.Top = 1
        Margins.Bottom = 0
        Align = alTop
        Caption = 'Apply to same roomtype'
        TabOrder = 2
        OnClick = btnApplySameRoomTypeClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object sGroupBox2: TsGroupBox
      AlignWithMargins = True
      Left = 456
      Top = 4
      Width = 268
      Height = 81
      Align = alLeft
      Caption = 'Other properties'
      TabOrder = 1
      SkinData.SkinSection = 'GROUPBOX'
      Checked = False
      object chkAutoUpdateNullPrice: TsCheckBox
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 258
        Height = 19
        Caption = 'Auto update Null Price'
        Align = alTop
        Checked = True
        State = cbChecked
        TabOrder = 0
        SkinData.SkinSection = 'CHECKBOX'
        ImgChecked = 0
        ImgUnchecked = 0
      end
    end
    object pnlButtons: TsPanel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 220
      Height = 81
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 2
      SkinData.SkinSection = 'GROUPBOX'
      DesignSize = (
        220
        81)
      object btnCancel: TsButton
        Left = 111
        Top = 10
        Width = 100
        Height = 55
        Anchors = [akTop, akRight]
        Cancel = True
        Caption = 'Cancel'
        ImageIndex = 10
        Images = DImages.cxLargeImagesFlat
        TabOrder = 0
        OnClick = btnCancelClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnApply: TsButton
        Left = 5
        Top = 10
        Width = 100
        Height = 55
        Caption = 'Apply'
        ImageIndex = 82
        Images = DImages.cxLargeImagesFlat
        ModalResult = 1
        TabOrder = 1
        OnClick = btnApplyClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object gbxCurrency: TsGroupBox
      AlignWithMargins = True
      Left = 730
      Top = 4
      Width = 185
      Height = 81
      Align = alLeft
      Caption = 'Currency'
      TabOrder = 3
      Checked = False
      object lblCurrency: TsLabel
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 175
        Height = 13
        Align = alTop
        Alignment = taCenter
        Caption = '<autofilled>'
        ExplicitWidth = 60
      end
    end
  end
  object grRoomRes: TcxGrid [2]
    Left = 0
    Top = 89
    Width = 1128
    Height = 476
    Align = alClient
    TabOrder = 2
    LookAndFeel.NativeStyle = False
    object tvRoomRes: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = mRoomResDS
      DataController.DetailKeyFieldNames = 'RoomReservation'
      DataController.KeyFieldNames = 'RoomReservation'
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '###0.;###0.'
          Kind = skSum
          FieldName = 'Guests'
          Column = tvRoomResGuests
        end
        item
          Format = '###0.;###0.'
          Kind = skSum
          FieldName = 'ChildrenCount'
          Column = tvRoomResChildrenCount
        end
        item
          Format = '###0.;###0.'
          Kind = skSum
          FieldName = 'infantCount'
          Column = tvRoomResinfantCount
        end
        item
          Format = '###0.00;###0.00'
          Kind = skSum
          FieldName = 'AveragePrice'
          Column = tvRoomResAveragePrice
        end
        item
          Format = '###0.00;###0.00'
          Kind = skAverage
          FieldName = 'AveragePrice'
          Column = tvRoomResAveragePrice
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsData.DeletingConfirmation = False
      OptionsData.Inserting = False
      OptionsView.Footer = True
      OptionsView.FooterAutoHeight = True
      OptionsView.FooterMultiSummaries = True
      OptionsView.GroupByBox = False
      object tvRoomResEditButton: TcxGridDBColumn
        Caption = 'Edit'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Caption = 'Refresh'
            Default = True
            ImageIndex = 29
            Kind = bkGlyph
          end>
        Properties.ViewStyle = vsButtonsOnly
        Properties.OnButtonClick = tvRoomResEditColumnButtonClick
        Options.ShowEditButtons = isebAlways
        Width = 39
      end
      object tvRoomResRoom: TcxGridDBColumn
        DataBinding.FieldName = 'Room'
        Options.Editing = False
      end
      object tvRoomResRoomDescription: TcxGridDBColumn
        Caption = 'Description'
        DataBinding.FieldName = 'RoomDescription'
        Options.Editing = False
        Width = 95
      end
      object tvRoomResRoomType: TcxGridDBColumn
        Caption = 'Type'
        DataBinding.FieldName = 'RoomType'
        Options.Editing = False
      end
      object tvRoomResRoomTypeDescription: TcxGridDBColumn
        Caption = 'Description'
        DataBinding.FieldName = 'RoomTypeDescription'
        Visible = False
        Options.Editing = False
        Width = 111
      end
      object tvRoomResGuestName: TcxGridDBColumn
        Caption = 'Guest name'
        DataBinding.FieldName = 'GuestName'
        Width = 172
      end
      object tvRoomResArrival: TcxGridDBColumn
        DataBinding.FieldName = 'Arrival'
        Options.Editing = False
        Width = 80
      end
      object tvRoomResDeparture: TcxGridDBColumn
        DataBinding.FieldName = 'Departure'
        Options.Editing = False
        Width = 80
      end
      object tvRoomResGuests: TcxGridDBColumn
        DataBinding.FieldName = 'Guests'
        PropertiesClassName = 'TcxSpinEditProperties'
        Properties.CanEdit = False
        Properties.MaxValue = 100.000000000000000000
        Properties.MinValue = 1.000000000000000000
        Width = 45
      end
      object tvRoomResChildrenCount: TcxGridDBColumn
        Caption = 'Children'
        DataBinding.FieldName = 'ChildrenCount'
        PropertiesClassName = 'TcxSpinEditProperties'
        Properties.CanEdit = False
        Properties.MaxValue = 10.000000000000000000
        Width = 45
      end
      object tvRoomResinfantCount: TcxGridDBColumn
        Caption = 'Infants'
        DataBinding.FieldName = 'infantCount'
        PropertiesClassName = 'TcxSpinEditProperties'
        Properties.CanEdit = False
        Properties.MaxValue = 10.000000000000000000
        Width = 45
      end
      object tvRoomResAveragePrice: TcxGridDBColumn
        DataBinding.FieldName = 'AveragePrice'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        Properties.OnEditValueChanged = tvRoomResAveragePricePropertiesEditValueChanged
        OnGetProperties = tvRoomResAveragePriceGetProperties
      end
      object tvRoomResPackage: TcxGridDBColumn
        DataBinding.FieldName = 'Package'
        Width = 89
      end
      object tvRoomResRateCount: TcxGridDBColumn
        DataBinding.FieldName = 'RateCount'
        PropertiesClassName = 'TcxSpinEditProperties'
        Properties.DisplayFormat = '###0.;###0.'
        Options.Editing = False
      end
      object tvRoomResPriceCode: TcxGridDBColumn
        DataBinding.FieldName = 'PriceCode'
        Options.Editing = False
      end
      object tvRoomResAverageDiscount: TcxGridDBColumn
        DataBinding.FieldName = 'AverageDiscount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomResAveragePriceGetProperties
        Options.Editing = False
      end
      object tvRoomResRoomReservation: TcxGridDBColumn
        DataBinding.FieldName = 'RoomReservation'
      end
    end
    object tvRoomRates: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataModeController.SyncMode = False
      DataController.DataSource = kbmRoomRatesDS
      DataController.DetailKeyFieldNames = 'RoomReservation'
      DataController.KeyFieldNames = 'RoomReservation'
      DataController.MasterKeyFieldNames = 'RoomReservation'
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Inserting = False
      OptionsView.GroupByBox = False
      object tvRoomRatesReservation: TcxGridDBColumn
        DataBinding.FieldName = 'Reservation'
        Visible = False
      end
      object tvRoomRatesRoomReservation: TcxGridDBColumn
        DataBinding.FieldName = 'RoomReservation'
        Visible = False
      end
      object tvRoomRatesRoomNumber: TcxGridDBColumn
        Caption = 'Room'
        DataBinding.FieldName = 'RoomNumber'
        Visible = False
      end
      object tvRoomRatesRateDate: TcxGridDBColumn
        Caption = 'Date'
        DataBinding.FieldName = 'RateDate'
      end
      object tvRoomRatesPriceCode: TcxGridDBColumn
        Caption = 'Price code'
        DataBinding.FieldName = 'PriceCode'
      end
      object tvRoomRatesRate: TcxGridDBColumn
        Caption = 'Room Rate'
        DataBinding.FieldName = 'Rate'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomResAveragePriceGetProperties
        Width = 70
      end
      object tvRoomRatesDiscount: TcxGridDBColumn
        DataBinding.FieldName = 'Discount'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 70
      end
      object tvRoomRatesisPercentage: TcxGridDBColumn
        Caption = 'is %'
        DataBinding.FieldName = 'isPercentage'
        PropertiesClassName = 'TcxCheckBoxProperties'
      end
      object tvRoomRatesShowDiscount: TcxGridDBColumn
        Caption = 'Show Discount'
        DataBinding.FieldName = 'ShowDiscount'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Visible = False
      end
      object tvRoomRatesisPaid: TcxGridDBColumn
        Caption = 'Paid'
        DataBinding.FieldName = 'isPaid'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Visible = False
      end
      object tvRoomRatesDiscountAmount: TcxGridDBColumn
        Caption = 'Total discount'
        DataBinding.FieldName = 'DiscountAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomResAveragePriceGetProperties
        Options.Editing = False
        Width = 70
      end
      object tvRoomRatesRentAmount: TcxGridDBColumn
        Caption = 'Total Rent'
        DataBinding.FieldName = 'RentAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomResAveragePriceGetProperties
        Width = 70
      end
      object tvRoomRatesNativeAmount: TcxGridDBColumn
        Caption = 'Native'
        DataBinding.FieldName = 'NativeAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomRatesNativeAmountGetProperties
        Width = 70
      end
    end
    object lvRoomRes: TcxGridLevel
      GridView = tvRoomRes
      object lvRoomRates: TcxGridLevel
        GridView = tvRoomRates
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = chkAutoUpdateNullPrice
        Properties.Strings = (
          'Checked')
      end>
    Left = 928
    Top = 144
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 824
    Top = 152
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object mRoomRes: TdxMemData
    Indexes = <
      item
        FieldName = 'Room'
        SortOptions = []
      end>
    SortOptions = []
    Left = 64
    Top = 392
    object mRoomResReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomResroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomResRoom: TWideStringField
      FieldName = 'Room'
      Size = 10
    end
    object mRoomResRoomType: TWideStringField
      FieldName = 'RoomType'
      Size = 10
    end
    object mRoomResGuests: TIntegerField
      FieldName = 'Guests'
    end
    object mRoomResAveragePrice: TFloatField
      FieldName = 'AveragePrice'
    end
    object mRoomResRateCount: TIntegerField
      FieldName = 'RateCount'
    end
    object mRoomResRoomDescription: TWideStringField
      FieldName = 'RoomDescription'
      Size = 30
    end
    object mRoomResRoomTypeDescription: TWideStringField
      FieldName = 'RoomTypeDescription'
      Size = 30
    end
    object mRoomResArrival: TDateField
      FieldName = 'Arrival'
    end
    object mRoomResDeparture: TDateField
      FieldName = 'Departure'
    end
    object mRoomResChildrenCount: TIntegerField
      FieldName = 'ChildrenCount'
    end
    object mRoomResinfantCount: TIntegerField
      FieldName = 'infantCount'
    end
    object mRoomResPriceCode: TWideStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRoomResAverageDiscount: TFloatField
      FieldName = 'AverageDiscount'
    end
    object mRoomResPackage: TWideStringField
      FieldName = 'Package'
    end
    object mRoomResInvoiceIndex: TIntegerField
      FieldName = 'InvoiceIndex'
    end
    object mRoomResGroupAccount: TBooleanField
      FieldName = 'GroupAccount'
    end
    object mRoomResGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 60
    end
  end
  object mRoomResDS: TDataSource
    DataSet = mRoomRes
    Left = 64
    Top = 440
  end
  object mRoomRates: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 152
    Top = 400
    object mRoomRatesReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomRatesroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomRatesRoomNumber: TWideStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object mRoomRatesRateDate: TDateField
      FieldName = 'RateDate'
    end
    object mRoomRatesPriceCode: TWideStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object mRoomRatesRate: TFloatField
      FieldName = 'Rate'
    end
    object mRoomRatesDiscount: TFloatField
      FieldName = 'Discount'
    end
    object mRoomRatesisPercentage: TBooleanField
      FieldName = 'isPercentage'
    end
    object mRoomRatesShowDiscount: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object mRoomRatesisPaid: TBooleanField
      FieldName = 'isPaid'
    end
    object mRoomRatesDiscountAmount: TFloatField
      FieldName = 'DiscountAmount'
    end
    object mRoomRatesRentAmount: TFloatField
      FieldName = 'RentAmount'
    end
    object mRoomRatesNativeAmount: TFloatField
      FieldName = 'NativeAmount'
    end
    object mRoomRatesGuestName: TWideStringField
      FieldName = 'GuestName'
      Size = 60
    end
  end
  object kbmRoomRatesDS: TDataSource
    DataSet = mRoomRates
    Left = 192
    Top = 448
  end
  object mRR_: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 80
    Top = 199
    object IntegerField3: TIntegerField
      FieldName = 'Reservation'
    end
    object IntegerField4: TIntegerField
      FieldName = 'roomreservation'
    end
    object StringField3: TWideStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object DateTimeField2: TDateField
      FieldName = 'RateDate'
    end
    object StringField4: TWideStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object FloatField6: TFloatField
      FieldName = 'Rate'
    end
    object FloatField7: TFloatField
      FieldName = 'Discount'
    end
    object BooleanField4: TBooleanField
      FieldName = 'isPercentage'
    end
    object BooleanField5: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object BooleanField6: TBooleanField
      FieldName = 'isPaid'
    end
    object FloatField8: TFloatField
      FieldName = 'DiscountAmount'
    end
    object FloatField9: TFloatField
      FieldName = 'RentAmount'
    end
    object FloatField10: TFloatField
      FieldName = 'NativeAmount'
    end
  end
  object mRoomRatesTmp: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 248
    Top = 400
    object IntegerField1: TIntegerField
      FieldName = 'Reservation'
    end
    object IntegerField2: TIntegerField
      FieldName = 'roomreservation'
    end
    object StringField1: TWideStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object DateTimeField1: TDateField
      FieldName = 'RateDate'
    end
    object StringField2: TWideStringField
      FieldName = 'PriceCode'
      Size = 10
    end
    object FloatField1: TFloatField
      FieldName = 'Rate'
    end
    object FloatField2: TFloatField
      FieldName = 'Discount'
    end
    object BooleanField1: TBooleanField
      FieldName = 'isPercentage'
    end
    object BooleanField2: TBooleanField
      FieldName = 'ShowDiscount'
    end
    object BooleanField3: TBooleanField
      FieldName = 'isPaid'
    end
    object FloatField3: TFloatField
      FieldName = 'DiscountAmount'
    end
    object FloatField4: TFloatField
      FieldName = 'RentAmount'
    end
    object FloatField5: TFloatField
      FieldName = 'NativeAmount'
    end
  end
end
