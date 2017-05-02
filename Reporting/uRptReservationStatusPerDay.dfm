object FrmRptReservationStatusPerDay: TFrmRptReservationStatusPerDay
  Left = 0
  Top = 0
  Caption = 'FrmRptReservationStatusPerDay'
  ClientHeight = 98
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TsPanel
    Left = 0
    Top = 0
    Width = 635
    Height = 98
    Align = alClient
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object labLocationsList: TsLabel
      Left = 170
      Top = 80
      Width = 11
      Height = 13
      Caption = 'All'
    end
    object labLocations: TsLabel
      AlignWithMargins = True
      Left = 112
      Top = 80
      Width = 52
      Height = 13
      Alignment = taRightJustify
      Caption = 'Locations :'
    end
    object cxGroupBox2: TsGroupBox
      Left = 170
      Top = 3
      Width = 151
      Height = 78
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
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 0
        Text = 'Choose a Month ...'
        OnCloseUp = cbxMonthCloseUp
        Items.Strings = (
          'Choose a Month ...'
          'January'
          'February'
          'March'
          'April'
          'may'
          'June'
          'July'
          'august'
          'September'
          'October'
          'November'
          'December')
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
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 1
        Text = 'Choose a year ...'
        OnCloseUp = cbxMonthCloseUp
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
      Left = 332
      Top = 10
      Width = 118
      Height = 25
      Caption = 'Report'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
    end
    object gbxSelectDates: TsGroupBox
      Left = 15
      Top = 3
      Width = 146
      Height = 78
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
        OnChange = dtDateFromChange
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
        OnChange = dtDateFromChange
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
    end
  end
  object fdRegFormDesigner: TfrxDesigner
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
    DefaultOrientation = poLandscape
    GradientEnd = 11982554
    GradientStart = clWindow
    TemplatesExt = 'fr3'
    Restrictions = []
    RTLLanguage = False
    MemoParentFont = False
    Left = 352
    Top = 47
  end
  object rptForm: TfrxReport
    Version = '4.13.2'
    DataSet = dsForm
    DataSetName = 'frxDBDataset1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42857.342411956000000000
    ReportOptions.LastChange = 42857.365317291700000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 504
    Top = 47
    Datasets = <
      item
        DataSet = dsForm
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Orientation = poLandscape
      PaperWidth = 297.000000000000000000
      PaperHeight = 210.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 22.677180000000000000
        Top = 18.897650000000000000
        Width = 1046.929810000000000000
      end
      object MasterData1: TfrxMasterData
        Height = 529.134199999999900000
        Top = 102.047310000000000000
        Width = 1046.929810000000000000
        RowCount = 0
        object frxDBDataset1dtDate: TfrxMemoView
          Left = 7.559060000000000000
          Top = 3.779530000000008000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ShowHint = False
          DataField = 'dtDate'
          DataSet = dsForm
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."dtDate"]')
          ParentFont = False
        end
        object frxDBDataset1WeekNr: TfrxMemoView
          Left = 102.047310000000000000
          Top = 3.779530000000008000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ShowHint = False
          DataField = 'WeekNr'
          DataSet = dsForm
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."WeekNr"]')
          ParentFont = False
        end
        object frxDBDataset1Reservation: TfrxMemoView
          Left = 34.015770000000010000
          Top = 30.236239999999990000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ShowHint = False
          DataField = 'Reservation'
          DataSet = dsForm
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."Reservation"]')
          ParentFont = False
        end
        object frxDBDataset1CustomerName: TfrxMemoView
          Left = 128.504020000000000000
          Top = 30.236239999999990000
          Width = 185.196970000000000000
          Height = 18.897650000000000000
          ShowHint = False
          DataField = 'CustomerName'
          DataSet = dsForm
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."CustomerName"]')
          ParentFont = False
        end
        object frxDBDataset1Name: TfrxMemoView
          Left = 325.039580000000000000
          Top = 30.236239999999990000
          Width = 154.960730000000000000
          Height = 18.897650000000000000
          ShowHint = False
          DataField = 'Name'
          DataSet = dsForm
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."Name"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 691.653990000000000000
        Width = 1046.929810000000000000
        object Memo1: TfrxMemoView
          Left = 642.520100000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
    end
  end
  object dsForm: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = tblDaysAndGroups
    BCDToCurrency = False
    Left = 432
    Top = 47
  end
  object tblDaysAndGroups: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'dtDate'
        DataType = ftDate
      end
      item
        Name = 'WeekNr'
        DataType = ftInteger
      end
      item
        Name = 'invRefrence'
        DataType = ftWideString
      end
      item
        Name = 'Name'
        DataType = ftWideString
      end
      item
        Name = 'CustomerName'
        DataType = ftWideString
      end
      item
        Name = 'Reservation'
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
    Left = 8
    Top = 6
  end
  object dsDays: TDataSource
    DataSet = tblDaysAndGroups
    Left = 56
    Top = 6
  end
  object dslUnconfirmed: TDataSource
    DataSet = tblUnconfirmed
    Left = 168
    Top = 6
  end
  object tblUnconfirmed: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'dtDate'
        DataType = ftDate
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'WeekNr'
        DataType = ftInteger
      end
      item
        Name = 'invRefrence'
        DataType = ftWideString
      end
      item
        Name = 'RoomType'
        DataType = ftWideString
      end
      item
        Name = 'NumRooms'
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
    Left = 120
    Top = 6
  end
  object tblConfirmed: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'dtDate'
        DataType = ftDate
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'WeekNr'
        DataType = ftInteger
      end
      item
        Name = 'invRefrence'
        DataType = ftWideString
      end
      item
        Name = 'RoomType'
        DataType = ftWideString
      end
      item
        Name = 'NumRooms'
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
    Left = 24
    Top = 54
  end
  object dsConfirmed: TDataSource
    DataSet = tblConfirmed
    Left = 72
    Top = 54
  end
  object tblWaitingList: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'dtDate'
        DataType = ftDate
      end
      item
        Name = 'Reservation'
        DataType = ftInteger
      end
      item
        Name = 'WeekNr'
        DataType = ftInteger
      end
      item
        Name = 'invRefrence'
        DataType = ftWideString
      end
      item
        Name = 'RoomType'
        DataType = ftWideString
      end
      item
        Name = 'NumRooms'
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
    Left = 168
    Top = 54
  end
  object dsWaitingList: TDataSource
    DataSet = tblWaitingList
    Left = 216
    Top = 54
  end
end
