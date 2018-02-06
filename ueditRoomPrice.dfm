inherited frmEditRoomPrice: TfrmEditRoomPrice
  Caption = 'Edit roomprice'
  ClientHeight = 497
  ClientWidth = 925
  Font.Height = -11
  ExplicitWidth = 941
  ExplicitHeight = 536
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 477
    Width = 925
    ExplicitTop = 477
    ExplicitWidth = 925
  end
  object Panel1: TsPanel [1]
    Left = 0
    Top = 0
    Width = 925
    Height = 136
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object gbxForAllDates: TsGroupBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 410
      Height = 130
      Align = alLeft
      Caption = 'Set for all dates'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      ExplicitLeft = -21
      ExplicitTop = -63
      DesignSize = (
        410
        130)
      object clabRate: TsLabel
        Left = 4
        Top = 46
        Width = 99
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Rate : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object clabPriceCode: TsLabel
        Left = 4
        Top = 23
        Width = 99
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Price Code : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object clabDiscount: TsLabel
        Left = 4
        Top = 71
        Width = 99
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Discount : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object cbxIsRoomResDiscountPrec: TsComboBox
        Left = 224
        Top = 68
        Width = 56
        Height = 21
        Alignment = taLeftJustify
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 5
        Text = 'cbxIsRoomResDiscountPrec'
        Items.Strings = (
          '%')
      end
      object ApplyDiscount: TsButton
        Left = 295
        Top = 68
        Width = 99
        Height = 21
        Anchors = [akTop, akRight]
        Caption = 'Apply for all dates'
        TabOrder = 6
        OnClick = ApplyDiscountClick
        SkinData.SkinSection = 'BUTTON'
      end
      object edRate: TsCalcEdit
        Left = 109
        Top = 44
        Width = 171
        Height = 21
        AutoSize = False
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object btnApplyRate: TsButton
        Left = 295
        Top = 43
        Width = 99
        Height = 21
        Anchors = [akTop, akRight]
        Caption = 'Apply for all dates'
        TabOrder = 3
        OnClick = btnApplyRateClick
        SkinData.SkinSection = 'BUTTON'
      end
      object btnApplyPriceCode: TsButton
        Left = 295
        Top = 20
        Width = 99
        Height = 21
        Anchors = [akTop, akRight]
        Caption = 'Apply for all dates'
        TabOrder = 1
        OnClick = btnApplyPriceCodeClick
        SkinData.SkinSection = 'BUTTON'
      end
      object edRoomResDiscount: TsCalcEdit
        Left = 109
        Top = 68
        Width = 109
        Height = 21
        AutoSize = False
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnKeyPress = edRoomResDiscountKeyPress
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      inline fraPriceCodePanel: TfraPriceCodePanel
        Left = 109
        Top = 20
        Width = 171
        Height = 20
        TabOrder = 0
        ExplicitLeft = 109
        ExplicitTop = 20
        ExplicitWidth = 171
        inherited pnlLookup: TsPanel
          Width = 171
          inherited lblDescription: TsLabel
            Width = 78
            Height = 20
            ExplicitWidth = 101
            ExplicitHeight = 20
          end
        end
      end
    end
    object sGroupBox1: TsGroupBox
      AlignWithMargins = True
      Left = 419
      Top = 3
      Width = 503
      Height = 130
      Align = alClient
      Caption = 'Room info'
      TabOrder = 1
      SkinData.SkinSection = 'GROUPBOX'
      object clabRoom: TsLabel
        Left = 12
        Top = 16
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Room : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object clabRomType: TsLabel
        Left = 12
        Top = 34
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Room type : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object cLabCurrency: TsLabel
        Left = 12
        Top = 51
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Currency : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object cLabAuduts: TsLabel
        Left = 12
        Top = 69
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Adults : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object cLabChildren: TsLabel
        Left = 12
        Top = 86
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Children : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object cLabInfants: TsLabel
        Left = 12
        Top = 104
        Width = 83
        Height = 13
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'Infants : '
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labRoom: TsLabel
        Left = 97
        Top = 16
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labRoomType: TsLabel
        Left = 97
        Top = 34
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labCurrency: TsLabel
        Left = 97
        Top = 51
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labAudults: TsLabel
        Left = 97
        Top = 69
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labChildren: TsLabel
        Left = 97
        Top = 86
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object labInfants: TsLabel
        Left = 97
        Top = 104
        Width = 4
        Height = 13
        Caption = '-'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
    end
  end
  object grRoomRates: TcxGrid [2]
    Left = 0
    Top = 136
    Width = 925
    Height = 304
    Align = alClient
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    object tvRoomRates: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = kbmRoomRatesDS
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '###0.00;###0.00'
          Kind = skSum
          OnGetText = tvRoomRatesFooterSummaryCurrencyGetText
          FieldName = 'Rate'
          Column = tvRoomRatesRate
        end
        item
          Format = 'Sum ###0.00;###0.00'
          Kind = skSum
          OnGetText = tvRoomRatesFoooterSummaryCurrencyGetTextSum
          FieldName = 'DiscountAmount'
          Column = tvRoomRatesDiscountAmount
        end
        item
          Format = '###0.00;###0.00'
          Kind = skSum
          OnGetText = tvRoomRatesFoooterSummaryCurrencyGetTextSum
          FieldName = 'RentAmount'
          Column = tvRoomRatesRentAmount
        end
        item
          Format = '###0.00;###0.00'
          Kind = skSum
          OnGetText = tvRoomRatesFooterSummaryNativeGetText
          FieldName = 'NativeAmount'
          Column = tvRoomRatesNativeAmount
        end
        item
          Format = '###0.00;###0.00'
          Kind = skAverage
          OnGetText = tvRoomRatesFoooterSummaryCurrencyGetTextAvg
          FieldName = 'RentAmount'
          Column = tvRoomRatesRentAmount
        end
        item
          Format = 'Avg ###0.00;###0.00'
          Kind = skAverage
          OnGetText = tvRoomRatesFoooterSummaryCurrencyGetTextAvg
          FieldName = 'DiscountAmount'
          Column = tvRoomRatesDiscountAmount
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.FocusCellOnTab = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.FooterAutoHeight = True
      OptionsView.FooterMultiSummaries = True
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
        Width = 92
      end
      object tvRoomRatesPriceCode: TcxGridDBColumn
        DataBinding.FieldName = 'PriceCode'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 100
      end
      object tvRoomRatesRate: TcxGridDBColumn
        DataBinding.FieldName = 'Rate'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomRatesRateGetProperties
        Width = 88
      end
      object tvRoomRatesDiscount: TcxGridDBColumn
        DataBinding.FieldName = 'Discount'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.DisplayFormat = '0.0 %'
        OnGetProperties = tvRoomRatesRentDiscountGetProperties
        Width = 68
      end
      object tvRoomRatesisPercentage: TcxGridDBColumn
        Caption = 'is %'
        DataBinding.FieldName = 'isPercentage'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Width = 43
      end
      object tvRoomRatesShowDiscount: TcxGridDBColumn
        DataBinding.FieldName = 'ShowDiscount'
        Visible = False
      end
      object tvRoomRatesisPaid: TcxGridDBColumn
        DataBinding.FieldName = 'isPaid'
        Visible = False
      end
      object tvRoomRatesDiscountAmount: TcxGridDBColumn
        Caption = 'Total Discount '
        DataBinding.FieldName = 'DiscountAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomRatesRateGetProperties
        Options.Editing = False
        Width = 92
      end
      object tvRoomRatesRentAmount: TcxGridDBColumn
        Caption = 'Total'
        DataBinding.FieldName = 'RentAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomRatesRateGetProperties
        Options.Editing = False
        Width = 83
      end
      object tvRoomRatesNativeAmount: TcxGridDBColumn
        Caption = 'Native currency'
        DataBinding.FieldName = 'NativeAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvRoomRatesNativeAmountGetProperties
        Options.Editing = False
        Width = 85
      end
    end
    object lvRoomRates: TcxGridLevel
      GridView = tvRoomRates
    end
  end
  object Panel2: TsPanel [3]
    Left = 0
    Top = 440
    Width = 925
    Height = 37
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 818
      Top = 3
      Width = 104
      Height = 31
      Align = alRight
      Cancel = True
      Caption = 'Cancel'
      ImageIndex = 10
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 3
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOK: TsButton
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 157
      Height = 31
      Align = alLeft
      Caption = 'Apply to this room'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 0
      OnClick = btnOKClick
      SkinData.SkinSection = 'BUTTON'
    end
    object sButton1: TsButton
      AlignWithMargins = True
      Left = 166
      Top = 3
      Width = 157
      Height = 31
      Align = alLeft
      Caption = 'Apply all rooms of this Roomtytpe'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 1
      OnClick = sButton1Click
      SkinData.SkinSection = 'BUTTON'
    end
    object sButton2: TsButton
      AlignWithMargins = True
      Left = 329
      Top = 3
      Width = 157
      Height = 31
      Align = alLeft
      Caption = 'Apply all rooms'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 2
      OnClick = sButton2Click
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
  object _kbmRoomRates: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomNumber'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'RateDate'
        DataType = ftDate
      end
      item
        Name = 'PriceCode'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Rate'
        DataType = ftFloat
      end
      item
        Name = 'Discount'
        DataType = ftFloat
      end
      item
        Name = 'isPercentage'
        DataType = ftBoolean
      end
      item
        Name = 'ShowDiscount'
        DataType = ftBoolean
      end
      item
        Name = 'isPaid'
        DataType = ftBoolean
      end
      item
        Name = 'DiscountAmount'
        DataType = ftFloat
      end
      item
        Name = 'RentAmount'
        DataType = ftFloat
      end
      item
        Name = 'NativeAmount'
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
    BeforePost = _kbmRoomRatesBeforePost
    Left = 128
    Top = 242
  end
  object kbmRoomRatesDS: TDataSource
    DataSet = mRoomRates
    Left = 32
    Top = 242
  end
  object mRoomRates: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforePost = mRoomRatesBeforePost
    Left = 32
    Top = 183
    object mRoomRatesReservation: TIntegerField
      FieldName = 'Reservation'
    end
    object mRoomRatesroomreservation: TIntegerField
      FieldName = 'roomreservation'
    end
    object mRoomRatesRoomNumber: TStringField
      FieldName = 'RoomNumber'
      Size = 10
    end
    object mRoomRatesRateDate: TDateField
      FieldName = 'RateDate'
    end
    object mRoomRatesPriceCode: TStringField
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
  end
end
