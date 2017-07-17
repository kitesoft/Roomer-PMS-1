object FrmFinanceConnect: TFrmFinanceConnect
  Left = 0
  Top = 0
  Caption = 'Finance Connect'
  ClientHeight = 584
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
    Height = 584
    ActivePage = sTabSheet1
    Align = alClient
    TabOrder = 0
    object sTabSheet1: TsTabSheet
      Caption = 'Settings'
      object sLabel1: TsLabel
        Left = 64
        Top = 33
        Width = 122
        Height = 13
        Alignment = taRightJustify
        Caption = 'Finance Connect System:'
      end
      object sLabel2: TsLabel
        Left = 125
        Top = 120
        Width = 61
        Height = 13
        Alignment = taRightJustify
        Caption = 'Service URL:'
      end
      object sLabel3: TsLabel
        Left = 90
        Top = 149
        Width = 96
        Height = 13
        Alignment = taRightJustify
        Caption = 'Endpoint username:'
      end
      object sLabel4: TsLabel
        Left = 136
        Top = 178
        Width = 50
        Height = 13
        Alignment = taRightJustify
        Caption = 'Password:'
      end
      object sLabel5: TsLabel
        Left = 95
        Top = 207
        Width = 91
        Height = 13
        Alignment = taRightJustify
        Caption = 'Organization code:'
      end
      object sLabel6: TsLabel
        Left = 127
        Top = 236
        Width = 59
        Height = 13
        Alignment = taRightJustify
        Caption = 'Office code:'
      end
      object sLabel7: TsLabel
        Left = 111
        Top = 265
        Width = 75
        Height = 13
        Alignment = taRightJustify
        Caption = 'Company code:'
      end
      object sLabel8: TsLabel
        Left = 250
        Top = 322
        Width = 112
        Height = 13
        Alignment = taRightJustify
        Caption = 'Sales transaction code:'
      end
      object sLabel9: TsLabel
        Left = 200
        Top = 296
        Width = 156
        Height = 13
        Caption = 'Book keeping codes and settings'
      end
      object sLabel10: TsLabel
        Left = 251
        Top = 350
        Width = 111
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash transaction code:'
      end
      object sLabel11: TsLabel
        Left = 253
        Top = 378
        Width = 109
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash balance account:'
      end
      object sLabel12: TsLabel
        Left = 225
        Top = 406
        Width = 137
        Height = 13
        Alignment = taRightJustify
        Caption = 'Receivable balance account:'
      end
      object sLabel13: TsLabel
        Left = 207
        Top = 434
        Width = 155
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text preceeding nvoice number:'
      end
      object sLabel14: TsLabel
        Left = 207
        Top = 462
        Width = 155
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text succeeding nvoice number:'
      end
      object cbxSystemSelection: TsComboBox
        Left = 200
        Top = 30
        Width = 164
        Height = 21
        Alignment = taLeftJustify
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
      end
      object cbxActive: TsCheckBox
        Left = 199
        Top = 73
        Width = 50
        Height = 20
        Caption = 'Active'
        TabOrder = 1
        ImgChecked = 0
        ImgUnchecked = 0
      end
      object edServiceUrl: TsEdit
        Left = 200
        Top = 117
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = 'https://<finance_system_endpoints>'
      end
      object edUsername: TsEdit
        Left = 200
        Top = 146
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object edPassword: TsEdit
        Left = 200
        Top = 175
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 4
        Text = 'This is not valid password'
      end
      object edOrg: TsEdit
        Left = 200
        Top = 204
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object edOffice: TsEdit
        Left = 200
        Top = 233
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
      end
      object edCompany: TsEdit
        Left = 200
        Top = 262
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
      end
      object edSalesCode: TsEdit
        Left = 368
        Top = 319
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
      end
      object edCashCode: TsEdit
        Left = 368
        Top = 347
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
      end
      object edCashAccount: TsEdit
        Left = 368
        Top = 375
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 10
      end
      object edReceivableAccount: TsEdit
        Left = 368
        Top = 403
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 11
      end
      object edPreInvoiceNumber: TsEdit
        Left = 368
        Top = 431
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
      end
      object edSuccInvoiceNumber: TsEdit
        Left = 368
        Top = 459
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 13
      end
      object sButton1: TsButton
        Left = 630
        Top = 488
        Width = 75
        Height = 25
        Caption = 'Save'
        TabOrder = 14
        OnClick = sButton1Click
      end
      object sMemo1: TsMemo
        Left = 576
        Top = 312
        Width = 201
        Height = 140
        Lines.Strings = (
          'sMemo1')
        TabOrder = 15
        Text = 'sMemo1'
      end
    end
    object sTabSheet2: TsTabSheet
      Caption = 'Mappings'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
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
        Left = 2
        Top = 47
        Width = 398
        Height = 423
        TabOrder = 1
        object grCustomers: TcxGrid
          Left = 1
          Top = 1
          Width = 396
          Height = 421
          Align = alClient
          TabOrder = 0
          object tvCustomers: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            DataController.DataSource = dsCustomers
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            object tvCustomersCode: TcxGridDBColumn
              DataBinding.FieldName = 'Code'
              Options.Editing = False
            end
            object tvCustomersName: TcxGridDBColumn
              DataBinding.FieldName = 'Name'
              Options.Editing = False
            end
            object tvCustomersExternalCode: TcxGridDBColumn
              DataBinding.FieldName = 'ExternalCode'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  ImageIndex = 1
                  Kind = bkEllipsis
                end>
              Properties.Images = DImages.cxSmallImagesFlat
              Properties.OnButtonClick = tvListExternalCodePropertiesButtonClick
            end
          end
          object glCustomers: TcxGridLevel
            GridView = tvCustomers
          end
        end
      end
      object pnl1: TsPanel
        Left = 107
        Top = 50
        Width = 499
        Height = 359
        TabOrder = 2
        object grItems: TcxGrid
          Left = 1
          Top = 1
          Width = 497
          Height = 357
          Align = alClient
          TabOrder = 0
          object tvItems: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            DataController.DataSource = dsItems
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            object cxGridDBColumn1: TcxGridDBColumn
              DataBinding.FieldName = 'Code'
              Options.Editing = False
            end
            object cxGridDBColumn2: TcxGridDBColumn
              DataBinding.FieldName = 'Name'
              Options.Editing = False
            end
            object cxGridDBColumn3: TcxGridDBColumn
              DataBinding.FieldName = 'ExternalCode'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  ImageIndex = 1
                  Kind = bkEllipsis
                end>
              Properties.Images = DImages.cxSmallImagesFlat
              Properties.OnButtonClick = tvListExternalCodePropertiesButtonClick
            end
          end
          object glItems: TcxGridLevel
            GridView = tvItems
          end
        end
      end
      object pnl2: TsPanel
        Left = 144
        Top = 10
        Width = 665
        Height = 327
        TabOrder = 3
        object grVats: TcxGrid
          Left = 1
          Top = 1
          Width = 663
          Height = 325
          Align = alClient
          TabOrder = 0
          object tvVats: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            DataController.DataSource = dsVats
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            object cxGridDBColumn4: TcxGridDBColumn
              DataBinding.FieldName = 'Code'
              Options.Editing = False
            end
            object cxGridDBColumn5: TcxGridDBColumn
              DataBinding.FieldName = 'Name'
              Options.Editing = False
            end
            object cxGridDBColumn6: TcxGridDBColumn
              DataBinding.FieldName = 'ExternalCode'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  ImageIndex = 1
                  Kind = bkEllipsis
                end>
              Properties.Images = DImages.cxSmallImagesFlat
              Properties.OnButtonClick = tvListExternalCodePropertiesButtonClick
            end
          end
          object glVats: TcxGridLevel
            GridView = tvVats
          end
        end
      end
    end
  end
  object memCustomers: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    Left = 16
    Top = 360
    object memCustomersCode: TWideStringField
      FieldName = 'Code'
      Size = 40
    end
    object memCustomersName: TWideStringField
      FieldName = 'Name'
      Size = 80
    end
    object memCustomersExternalCode: TWideStringField
      FieldName = 'ExternalCode'
      Size = 40
    end
  end
  object dsCustomers: TDataSource
    DataSet = memCustomers
    Left = 16
    Top = 408
  end
  object memItems: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    Left = 80
    Top = 360
    object memItemsCode: TWideStringField
      FieldName = 'Code'
      Size = 40
    end
    object memItemsName: TWideStringField
      FieldName = 'Name'
      Size = 80
    end
    object memItemsExternalCode: TWideStringField
      FieldName = 'ExternalCode'
      Size = 40
    end
  end
  object dsItems: TDataSource
    DataSet = memItems
    Left = 80
    Top = 408
  end
  object memVats: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    Left = 144
    Top = 360
    object memVatsCode: TWideStringField
      FieldName = 'Code'
      Size = 40
    end
    object memVatsName: TWideStringField
      FieldName = 'Name'
      Size = 80
    end
    object memVatsExternalCode: TWideStringField
      FieldName = 'ExternalCode'
      Size = 40
    end
  end
  object dsVats: TDataSource
    DataSet = memVats
    Left = 144
    Top = 408
  end
end
