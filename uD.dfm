object d: Td
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 672
  Width = 1101
  object wRooms_: TRoomerDataSet
    CommandText = 'SELECT * FROM wRooms'#13#10
    CommandType = cmdUnknown
    Parameters = <>
    DataActive = False
    RoomerStoreUri = 'http://localhost:8080/services/'
    RoomerUri = 'http://localhost:8080/services/'
    RoomerEntitiesUri = 'http://localhost:8080/services/entities/'
    RoomerDatasetsUri = 'http://localhost:8080/services/datasets/'
    SessionLengthSeconds = 0
    PrimaryKeyField = 'ID'
    Left = 168
    Top = 76
  end
  object rptDesign: TfrxDesigner
    DefaultScriptLanguage = 'PascalScript'
    DefaultFont.Charset = DEFAULT_CHARSET
    DefaultFont.Color = clWindowText
    DefaultFont.Height = -13
    DefaultFont.Name = 'Arial'
    DefaultFont.Style = []
    DefaultLeftMargin = 10.000000000000000000
    DefaultRightMargin = 10.000000000000000000
    DefaultTopMargin = 10.000000000000000000
    DefaultBottomMargin = 10.000000000000000000
    DefaultPaperSize = 9
    DefaultOrientation = poPortrait
    GradientEnd = 11982554
    GradientStart = clWindow
    TemplatesExt = 'fr3'
    Restrictions = []
    RTLLanguage = False
    MemoParentFont = False
    Left = 28
    Top = 484
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    Left = 177
    Top = 436
  end
  object frxHTMLExport1: TfrxHTMLExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    FixedWidth = True
    Background = False
    Centered = False
    EmptyLines = True
    Print = False
    PictureType = gpPNG
    Left = 101
    Top = 440
  end
  object frxRTFExport1: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 33
    Top = 436
  end
  object frxJPEGExport1: TfrxJPEGExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    Left = 373
    Top = 592
  end
  object mtPayments_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Code'
        DataType = ftWideString
        Size = 10
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
    Left = 25
    Top = 381
  end
  object mtHead_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'CustomerName'
        DataType = ftString
        Size = 20
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
    Left = 173
    Top = 381
  end
  object mtVAT_: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <>
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
    Left = 33
    Top = 317
  end
  object mtLines_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Code'
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    SortFields = 'LineNo'
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
    Left = 101
    Top = 381
  end
  object mtCompany_: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <>
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
    Left = 317
    Top = 381
  end
  object mtCaptions_: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <>
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
    Left = 245
    Top = 381
  end
  object inPosMonitor: TTimer
    Enabled = False
    Interval = 5000
    Left = 32
    Top = 144
  end
  object mQuickRes: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 168
    Top = 16
    object mQuickResRoom: TStringField
      FieldName = 'Room'
      Size = 10
    end
    object mQuickResDateFrom: TDateField
      FieldName = 'DateFrom'
    end
    object mQuickResDateTo: TDateField
      FieldName = 'DateTo'
    end
  end
  object mQuickRes2: TkbmMemTable
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Room'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Arrival'
        DataType = ftDateTime
      end
      item
        Name = 'Departure'
        DataType = ftDateTime
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
    Left = 728
    Top = 88
  end
  object roomerMainDataSet: TRoomerDataSet
    CommandText = ''
    CommandType = cmdUnknown
    Parameters = <>
    DataActive = False
    RoomerStoreUri = 'http://localhost:8080/services/'
    RoomerUri = 'http://localhost:8080/services/'
    RoomerEntitiesUri = 'http://localhost:8080/services/entities/'
    RoomerDatasetsUri = 'http://localhost:8080/services/datasets/'
    SessionLengthSeconds = 0
    PrimaryKeyField = 'ID'
    Left = 24
    Top = 16
  end
  object kbmInvoiceLines: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'AutoGen'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'SplitNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemNumber'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftDateTime
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Number'
        DataType = ftFloat
      end
      item
        Name = 'Description'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'Price'
        DataType = ftFloat
      end
      item
        Name = 'VATType'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Total'
        DataType = ftFloat
      end
      item
        Name = 'TotalWOVAT'
        DataType = ftFloat
      end
      item
        Name = 'Vat'
        DataType = ftFloat
      end
      item
        Name = 'AutoGenerated'
        DataType = ftBoolean
      end
      item
        Name = 'CurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Currency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ReportDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'ReportTime'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Persons'
        DataType = ftInteger
      end
      item
        Name = 'Nights'
        DataType = ftInteger
      end
      item
        Name = 'BreakfastPrice'
        DataType = ftFloat
      end
      item
        Name = 'AYear'
        DataType = ftInteger
      end
      item
        Name = 'AMon'
        DataType = ftInteger
      end
      item
        Name = 'ADay'
        DataType = ftInteger
      end
      item
        Name = 'ilTmp'
        DataType = ftString
        Size = 3
      end
      item
        Name = 'ilID'
        DataType = ftInteger
      end
      item
        Name = 'ilAccountKey'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ItemCurrency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ItemCurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Discount'
        DataType = ftFloat
      end
      item
        Name = 'Discount_isPrecent'
        DataType = ftBoolean
      end
      item
        Name = 'ImportRefrence'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ImportSource'
        DataType = ftWideString
      end
      item
        Name = 'IsPackage'
        DataType = ftBoolean
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'InvoiceIndex'
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
    Left = 721
    Top = 21
  end
  object cxEditRepository1: TcxEditRepository
    Left = 32
    Top = 216
    object currencyEUR2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = #8364' ,0.00;'#8364' -,0.00'
    end
    object currencyISK2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DecimalPlaces = 0
      Properties.DisplayFormat = ',0 kr'#39'.'#39';-,0 kr'#39'.'#39
      Properties.EditFormat = '0'
    end
    object currencyUSD2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = '$ ,0.00;$ -,0.00'
    end
    object currencyCAD2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = '$ ,0.00;$ -,0.00'
    end
    object currencyGBP2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DecimalPlaces = 2
      Properties.DisplayFormat = #163' ,0.00;'#163' -,0.00'
      Properties.EditFormat = '0.00'
    end
    object CurrencyMXN2d: TcxEditRepositoryCurrencyItem
      Properties.Alignment.Horz = taRightJustify
      Properties.DisplayFormat = '$ ,0.00;$ -,0.00'
    end
  end
  object RoomsDateDS: TDataSource
    DataSet = kbmRoomsDate_
    Left = 424
    Top = 320
  end
  object mInvoiceHeadsDS: TDataSource
    DataSet = mInvoiceHeads
    Left = 512
    Top = 320
  end
  object mInvoiceLinesDS: TDataSource
    DataSet = mInvoiceLines
    Left = 616
    Top = 320
  end
  object mrptTurnoverDS: TDataSource
    DataSet = mrptTurnover
    Left = 712
    Top = 320
  end
  object PaymentListDS: TDataSource
    DataSet = kbmPaymentList_
    Left = 800
    Top = 320
  end
  object RoomRentOnInvoiceDS: TDataSource
    DataSet = kbmRoomRentOnInvoice_
    Left = 904
    Top = 320
  end
  object kbmRoomsDate_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'StayDate'
        DataType = ftDate
      end
      item
        Name = 'roomreservation'
        DataType = ftInteger
      end
      item
        Name = 'reservation'
        DataType = ftInteger
      end
      item
        Name = 'RentAmount'
        DataType = ftFloat
      end
      item
        Name = 'currency'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'currencyRate'
        DataType = ftFloat
      end
      item
        Name = 'isTaxIncluted'
        DataType = ftBoolean
      end
      item
        Name = 'DiscountAmount'
        DataType = ftFloat
      end
      item
        Name = 'TotalStayTax'
        DataType = ftFloat
      end
      item
        Name = 'id'
        DataType = ftInteger
      end
      item
        Name = 'invoicenumber'
        DataType = ftInteger
      end
      item
        Name = 'paid'
        DataType = ftBoolean
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 424
    Top = 368
  end
  object mInvoiceHeads: TkbmMemTable
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
        Name = 'SplitNumber'
        DataType = ftInteger
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'Customer'
        DataType = ftWideString
        Size = 50
      end
      item
        Name = 'NameOnInvoice'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Address1'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Address2'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Address3'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'ihAmountWithTax'
        DataType = ftFloat
      end
      item
        Name = 'ihAmountNoTax'
        DataType = ftFloat
      end
      item
        Name = 'ihAmountTax'
        DataType = ftFloat
      end
      item
        Name = 'CreditInvoice'
        DataType = ftInteger
      end
      item
        Name = 'OriginalInvoice'
        DataType = ftInteger
      end
      item
        Name = 'RoomGuest'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'InvoiceDate'
        DataType = ftDateTime
      end
      item
        Name = 'dueDate'
        DataType = ftDateTime
      end
      item
        Name = 'invRefrence'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'isKredit'
        DataType = ftBoolean
      end
      item
        Name = 'isGroup'
        DataType = ftBoolean
      end
      item
        Name = 'isCash'
        DataType = ftBoolean
      end
      item
        Name = 'isRoom'
        DataType = ftBoolean
      end
      item
        Name = 'TotalStayTax'
        DataType = ftFloat
      end
      item
        Name = 'TotalStayTaxNights'
        DataType = ftFloat
      end
      item
        Name = 'confirmedDate'
        DataType = ftDateTime
      end
      item
        Name = 'Currency'
        DataType = ftWideString
        Size = 10
      end
      item
        Name = 'Rate'
        DataType = ftFloat
      end
      item
        Name = 'CustomerName'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'isAgency'
        DataType = ftBoolean
      end
      item
        Name = 'markedSegment'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'markedSegmentDescription'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Staff'
        DataType = ftWideString
        Size = 20
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    BeforePost = mInvoiceHeadsBeforePost
    Left = 744
    Top = 192
  end
  object mInvoiceLines: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftDateTime
      end
      item
        Name = 'Item'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Quantity'
        DataType = ftFloat
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Price'
        DataType = ftFloat
      end
      item
        Name = 'VATType'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'ilAmountWithTax'
        DataType = ftFloat
      end
      item
        Name = 'ilAmountNoTax'
        DataType = ftFloat
      end
      item
        Name = 'ilAmountTax'
        DataType = ftFloat
      end
      item
        Name = 'Currency'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'CurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'ImportRefrence'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'ImportSource'
        DataType = ftWideString
        Size = 100
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 840
    Top = 192
  end
  object mrptTurnover: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ItemID'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Itemtype'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'TypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'VATCode'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'VATPercentage'
        DataType = ftFloat
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'VAT'
        DataType = ftFloat
      end
      item
        Name = 'Itemcount'
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
    Left = 712
    Top = 368
  end
  object kbmPaymentList_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'PayType'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'paytypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'paygroupDescripion'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'dtPayDate'
        DataType = ftDateTime
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'Medhod'
        DataType = ftWideString
        Size = 45
      end
      item
        Name = 'customer'
        DataType = ftWideString
        Size = 30
      end
      item
        Name = 'customername'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'NameOnInvoice'
        DataType = ftWideString
        Size = 100
      end
      item
        Name = 'reservation'
        DataType = ftInteger
      end
      item
        Name = 'roomreservation'
        DataType = ftInteger
      end
      item
        Name = 'invoicenumber'
        DataType = ftInteger
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 800
    Top = 368
  end
  object kbmRoomRentOnInvoice_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ItemID'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Itemtype'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'TypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'VATCode'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'VATPercentage'
        DataType = ftFloat
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'VAT'
        DataType = ftFloat
      end
      item
        Name = 'Itemcount'
        DataType = ftFloat
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'isTaxIncluted'
        DataType = ftBoolean
      end
      item
        Name = 'totalStayTax'
        DataType = ftFloat
      end
      item
        Name = 'splitNumber'
        DataType = ftInteger
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'Room'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Staff'
        DataType = ftString
        Size = 5
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
    BeforePost = kbmRoomRentOnInvoice_BeforePost
    Left = 912
    Top = 368
  end
  object TurnoverDS: TDataSource
    DataSet = kbmTurnover_
    Left = 416
    Top = 440
  end
  object mrptPaymentsDS: TDataSource
    DataSet = mrptPayments
    Left = 496
    Top = 440
  end
  object RoomsDateChangeDS: TDataSource
    DataSet = kbmRoomsDateChange_
    Left = 600
    Top = 440
  end
  object PaymentsDS: TDataSource
    DataSet = kbmPayments_
    Left = 712
    Top = 432
  end
  object kbmInvoiceLinePriceChangeDS: TDataSource
    DataSet = kbmInvoiceLinePriceChange_
    Left = 984
    Top = 432
  end
  object kbmTurnover_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ItemID'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Itemtype'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'TypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'VATCode'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'VATPercentage'
        DataType = ftFloat
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'VAT'
        DataType = ftFloat
      end
      item
        Name = 'Itemcount'
        DataType = ftFloat
      end
      item
        Name = 'Invoicenumber'
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
    Top = 504
  end
  object mrptPayments: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'PayType'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'PaymentCount'
        DataType = ftInteger
      end
      item
        Name = 'paytypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'paygroupDescripion'
        DataType = ftWideString
        Size = 60
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 496
    Top = 504
  end
  object kbmRoomsDateChange_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'StayDate'
        DataType = ftDate
      end
      item
        Name = 'roomreservation'
        DataType = ftInteger
      end
      item
        Name = 'reservation'
        DataType = ftInteger
      end
      item
        Name = 'RentAmount'
        DataType = ftFloat
      end
      item
        Name = 'currency'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'currencyRate'
        DataType = ftFloat
      end
      item
        Name = 'isTaxIncluted'
        DataType = ftBoolean
      end
      item
        Name = 'DiscountAmount'
        DataType = ftFloat
      end
      item
        Name = 'TotalStayTax'
        DataType = ftFloat
      end
      item
        Name = 'roomsdateID'
        DataType = ftInteger
      end
      item
        Name = 'invoicenumber'
        DataType = ftInteger
      end
      item
        Name = 'DiscountChange'
        DataType = ftFloat
      end
      item
        Name = 'TaxChange'
        DataType = ftFloat
      end
      item
        Name = 'RentChange'
        DataType = ftFloat
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 600
    Top = 496
  end
  object kbmPayments_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'PayType'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'PaymentCount'
        DataType = ftFloat
      end
      item
        Name = 'paytypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'paygroupDescripion'
        DataType = ftWideString
        Size = 60
      end>
    IndexDefs = <>
    SortOptions = []
    PersistentBackup = False
    ProgressFlags = [mtpcLoad, mtpcSave, mtpcCopy]
    LoadedCompletely = False
    SavedCompletely = False
    EnableVersioning = True
    FilterOptions = []
    Version = '7.22.00 Standard Edition'
    LanguageID = 0
    SortID = 0
    SubLanguageID = 1
    LocaleID = 1024
    Left = 928
    Top = 192
  end
  object kbmInvoiceLinePriceChange_: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'ItemID'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'Description'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'Itemtype'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'TypeDescription'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'VATCode'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'VATPercentage'
        DataType = ftFloat
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'VAT'
        DataType = ftFloat
      end
      item
        Name = 'Itemcount'
        DataType = ftFloat
      end
      item
        Name = 'IvlID'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftDateTime
      end
      item
        Name = 'reservation'
        DataType = ftInteger
      end
      item
        Name = 'roomReservation'
        DataType = ftInteger
      end
      item
        Name = 'confirmAmount'
        DataType = ftFloat
      end
      item
        Name = 'PriceChange'
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
    Left = 992
    Top = 488
  end
  object confirmMonitor: TTimer
    Interval = 120000
    OnTimer = confirmMonitorTimer
    Left = 160
    Top = 144
  end
  object ALWinInetHTTPClient1: TALWinInetHTTPClient
    Left = 640
    Top = 600
  end
  object mlogInvoicelines: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'AutoGen'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'SplitNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemNumber'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftDateTime
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Number'
        DataType = ftFloat
      end
      item
        Name = 'Description'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'Price'
        DataType = ftFloat
      end
      item
        Name = 'VATType'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Total'
        DataType = ftFloat
      end
      item
        Name = 'TotalWOVAT'
        DataType = ftFloat
      end
      item
        Name = 'Vat'
        DataType = ftFloat
      end
      item
        Name = 'AutoGenerated'
        DataType = ftBoolean
      end
      item
        Name = 'CurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Currency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ReportDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'ReportTime'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Persons'
        DataType = ftInteger
      end
      item
        Name = 'Nights'
        DataType = ftInteger
      end
      item
        Name = 'BreakfastPrice'
        DataType = ftFloat
      end
      item
        Name = 'AYear'
        DataType = ftInteger
      end
      item
        Name = 'AMon'
        DataType = ftInteger
      end
      item
        Name = 'ADay'
        DataType = ftInteger
      end
      item
        Name = 'ilTmp'
        DataType = ftString
        Size = 3
      end
      item
        Name = 'ilID'
        DataType = ftInteger
      end
      item
        Name = 'ilAccountKey'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ItemCurrency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ItemCurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Discount'
        DataType = ftFloat
      end
      item
        Name = 'Discount_isPrecent'
        DataType = ftBoolean
      end
      item
        Name = 'ImportRefrence'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ImportSource'
        DataType = ftWideString
      end
      item
        Name = 'IsPackage'
        DataType = ftBoolean
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
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
    Left = 841
    Top = 101
  end
  object mInvoicelines_before: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'AutoGen'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'SplitNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemNumber'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Number'
        DataType = ftFloat
      end
      item
        Name = 'Description'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'Price'
        DataType = ftFloat
      end
      item
        Name = 'VATType'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Total'
        DataType = ftFloat
      end
      item
        Name = 'TotalWOVAT'
        DataType = ftFloat
      end
      item
        Name = 'Vat'
        DataType = ftFloat
      end
      item
        Name = 'AutoGenerated'
        DataType = ftBoolean
      end
      item
        Name = 'CurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Currency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ReportDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'ReportTime'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Persons'
        DataType = ftInteger
      end
      item
        Name = 'Nights'
        DataType = ftInteger
      end
      item
        Name = 'BreakfastPrice'
        DataType = ftFloat
      end
      item
        Name = 'AYear'
        DataType = ftInteger
      end
      item
        Name = 'AMon'
        DataType = ftInteger
      end
      item
        Name = 'ADay'
        DataType = ftInteger
      end
      item
        Name = 'ilTmp'
        DataType = ftString
        Size = 3
      end
      item
        Name = 'ilID'
        DataType = ftInteger
      end
      item
        Name = 'ilAccountKey'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ItemCurrency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ItemCurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Discount'
        DataType = ftFloat
      end
      item
        Name = 'Discount_isPrecent'
        DataType = ftBoolean
      end
      item
        Name = 'ImportRefrence'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ImportSource'
        DataType = ftWideString
      end
      item
        Name = 'IsPackage'
        DataType = ftBoolean
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'confirmAmount'
        DataType = ftFloat
      end
      item
        Name = 'RoomReservationAlias'
        DataType = ftInteger
      end
      item
        Name = 'isSystemLine'
        DataType = ftBoolean
      end
      item
        Name = 'InvoiceIndex'
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
    OnNewRecord = mInvoicelines_beforeNewRecord
    Left = 1026
    Top = 29
  end
  object mInvoicelines_after: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'AutoGen'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'RoomReservation'
        DataType = ftInteger
      end
      item
        Name = 'SplitNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemNumber'
        DataType = ftInteger
      end
      item
        Name = 'PurchaseDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'InvoiceNumber'
        DataType = ftInteger
      end
      item
        Name = 'ItemID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'Number'
        DataType = ftFloat
      end
      item
        Name = 'Description'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'Price'
        DataType = ftFloat
      end
      item
        Name = 'VATType'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'Total'
        DataType = ftFloat
      end
      item
        Name = 'TotalWOVAT'
        DataType = ftFloat
      end
      item
        Name = 'Vat'
        DataType = ftFloat
      end
      item
        Name = 'AutoGenerated'
        DataType = ftBoolean
      end
      item
        Name = 'CurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Currency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ReportDate'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'ReportTime'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'Persons'
        DataType = ftInteger
      end
      item
        Name = 'Nights'
        DataType = ftInteger
      end
      item
        Name = 'BreakfastPrice'
        DataType = ftFloat
      end
      item
        Name = 'AYear'
        DataType = ftInteger
      end
      item
        Name = 'AMon'
        DataType = ftInteger
      end
      item
        Name = 'ADay'
        DataType = ftInteger
      end
      item
        Name = 'ilTmp'
        DataType = ftString
        Size = 3
      end
      item
        Name = 'ilID'
        DataType = ftInteger
      end
      item
        Name = 'ilAccountKey'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ItemCurrency'
        DataType = ftString
        Size = 5
      end
      item
        Name = 'ItemCurrencyRate'
        DataType = ftFloat
      end
      item
        Name = 'Discount'
        DataType = ftFloat
      end
      item
        Name = 'Discount_isPrecent'
        DataType = ftBoolean
      end
      item
        Name = 'ImportRefrence'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'ImportSource'
        DataType = ftWideString
      end
      item
        Name = 'IsPackage'
        DataType = ftBoolean
      end
      item
        Name = 'confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'confirmAmount'
        DataType = ftFloat
      end
      item
        Name = 'RoomReservationAlias'
        DataType = ftInteger
      end
      item
        Name = 'isSystemLine'
        DataType = ftBoolean
      end
      item
        Name = 'InvoiceIndex'
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
    OnNewRecord = mInvoicelines_afterNewRecord
    Left = 1026
    Top = 133
  end
  object mInvoicelog: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'user'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'reservation'
        DataType = ftInteger
      end
      item
        Name = 'roomreservation'
        DataType = ftInteger
      end
      item
        Name = 'invoiceIndex'
        DataType = ftInteger
      end
      item
        Name = 'action'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'code'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'value'
        DataType = ftFloat
      end
      item
        Name = 'lineId'
        DataType = ftInteger
      end
      item
        Name = 'moreInfo'
        DataType = ftString
        Size = 100
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
    Left = 1042
    Top = 221
  end
end
