object FrmFinanceConnect: TFrmFinanceConnect
  Left = 0
  Top = 0
  Caption = 'Finance Connect'
  ClientHeight = 501
  ClientWidth = 836
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pgMain: TsPageControl
    Left = 0
    Top = 0
    Width = 836
    Height = 501
    ActivePage = sTabSheet2
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 40
    ExplicitTop = 48
    ExplicitWidth = 289
    ExplicitHeight = 193
    object sTabSheet1: TsTabSheet
      Caption = 'Settings'
      ExplicitWidth = 281
      ExplicitHeight = 165
    end
    object sTabSheet2: TsTabSheet
      Caption = 'Mappings'
      ExplicitLeft = 0
      ExplicitTop = 28
      object tabsMappings: TsTabControl
        AlignWithMargins = True
        Left = 3
        Top = 20
        Width = 822
        Height = 21
        Margins.Top = 20
        Align = alTop
        Style = tsButtons
        TabOrder = 0
        Tabs.Strings = (
          'Customers'
          'Items'
          'Vat codes')
        TabIndex = 0
        OnChange = tabsMappingsChange
      end
      object pnl0: TsPanel
        AlignWithMargins = True
        Left = 3
        Top = 47
        Width = 822
        Height = 423
        Align = alClient
        TabOrder = 1
        ExplicitWidth = 454
        object grList: TcxGrid
          Left = 1
          Top = 1
          Width = 820
          Height = 421
          Align = alClient
          TabOrder = 0
          ExplicitLeft = 32
          ExplicitTop = 40
          ExplicitWidth = 314
          ExplicitHeight = 280
          object tvList: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            DataController.DataSource = dsCustomers
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            object tvListCode: TcxGridDBColumn
              DataBinding.FieldName = 'Code'
            end
            object tvListName: TcxGridDBColumn
              DataBinding.FieldName = 'Name'
            end
            object tvListExternalCode: TcxGridDBColumn
              DataBinding.FieldName = 'ExternalCode'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  ImageIndex = 1
                  Kind = bkEllipsis
                end>
              Properties.Images = DImages.cxSmallImagesFlat
            end
          end
          object glList: TcxGridLevel
            GridView = tvList
          end
        end
      end
    end
  end
  object memCustomers: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Code'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Name'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'ExternalCode'
        DataType = ftWideString
        Size = 25
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
    Left = 48
    Top = 368
  end
  object dsCustomers: TDataSource
    DataSet = memCustomers
    Left = 48
    Top = 416
  end
  object memItems: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Code'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Name'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'ExternalCode'
        DataType = ftWideString
        Size = 25
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
    Left = 144
    Top = 368
  end
  object dsItems: TDataSource
    DataSet = memItems
    Left = 144
    Top = 416
  end
  object memVats: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'Code'
        DataType = ftWideString
        Size = 20
      end
      item
        Name = 'Name'
        DataType = ftWideString
        Size = 60
      end
      item
        Name = 'ExternalCode'
        DataType = ftWideString
        Size = 25
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
    Left = 238
    Top = 369
  end
  object dsVats: TDataSource
    DataSet = memVats
    Left = 238
    Top = 417
  end
end
