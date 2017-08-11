object FrmFinanceConnect: TFrmFinanceConnect
  Left = 0
  Top = 0
  Caption = 'Finance Connect'
  ClientHeight = 589
  ClientWidth = 876
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
    Width = 876
    Height = 589
    ActivePage = sTabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    ExplicitWidth = 733
    object sTabSheet1: TsTabSheet
      Caption = 'Settings'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 725
      object sLabel1: TsLabel
        Left = 45
        Top = 33
        Width = 141
        Height = 13
        Alignment = taRightJustify
        Caption = 'Finance Connect System:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
      end
      object sLabel2: TsLabel
        Left = 125
        Top = 120
        Width = 61
        Height = 13
        Alignment = taRightJustify
        Caption = 'Service URL:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel3: TsLabel
        Left = 90
        Top = 149
        Width = 96
        Height = 13
        Alignment = taRightJustify
        Caption = 'Endpoint username:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel4: TsLabel
        Left = 136
        Top = 178
        Width = 50
        Height = 13
        Alignment = taRightJustify
        Caption = 'Password:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel5: TsLabel
        Left = 95
        Top = 207
        Width = 91
        Height = 13
        Alignment = taRightJustify
        Caption = 'Organization code:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel6: TsLabel
        Left = 127
        Top = 236
        Width = 59
        Height = 13
        Alignment = taRightJustify
        Caption = 'Office code:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel7: TsLabel
        Left = 111
        Top = 265
        Width = 75
        Height = 13
        Alignment = taRightJustify
        Caption = 'Company code:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel8: TsLabel
        Left = 268
        Top = 346
        Width = 94
        Height = 13
        Alignment = taRightJustify
        Caption = 'Receivables ledger:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel9: TsLabel
        Left = 199
        Top = 305
        Width = 212
        Height = 16
        Caption = 'Book keeping codes and settings'
      end
      object sLabel10: TsLabel
        Left = 579
        Top = 306
        Width = 111
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash transaction code:'
        ParentFont = False
        Visible = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel11: TsLabel
        Left = 581
        Top = 330
        Width = 109
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash balance account:'
        ParentFont = False
        Visible = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel12: TsLabel
        Left = 225
        Top = 373
        Width = 137
        Height = 13
        Alignment = taRightJustify
        Caption = 'Receivable balance account:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel13: TsLabel
        Left = 205
        Top = 401
        Width = 157
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text preceeding invoice number:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel14: TsLabel
        Left = 205
        Top = 429
        Width = 157
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text succeeding invoice number:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel15: TsLabel
        Left = 314
        Top = 457
        Width = 48
        Height = 13
        Alignment = taRightJustify
        Caption = 'Currency:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
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
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 0
        OnCloseUp = cbxSystemSelectionCloseUp
      end
      object cbxActive: TsCheckBox
        Left = 199
        Top = 56
        Width = 55
        Height = 17
        Caption = 'Active'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbxActiveClick
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
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = 'https://<finance_system_endpoints>'
        OnChange = edServiceUrlChange
      end
      object edUsername: TsEdit
        Left = 200
        Top = 146
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnChange = edServiceUrlChange
      end
      object edPassword: TsEdit
        Left = 200
        Top = 175
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 4
        Text = '***This is not valid password***'
        OnChange = edServiceUrlChange
      end
      object edOrg: TsEdit
        Left = 200
        Top = 204
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        OnChange = edServiceUrlChange
      end
      object edOffice: TsEdit
        Left = 200
        Top = 233
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        OnChange = edServiceUrlChange
      end
      object edCompany: TsEdit
        Left = 200
        Top = 262
        Width = 505
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnChange = edServiceUrlChange
      end
      object edSalesCode: TsEdit
        Left = 368
        Top = 343
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        Text = 'VRK'
        OnChange = edServiceUrlChange
      end
      object edCashCode: TsEdit
        Left = 696
        Top = 303
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
        Visible = False
        OnChange = edServiceUrlChange
      end
      object edCashAccount: TsEdit
        Left = 696
        Top = 327
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 10
        Visible = False
        OnChange = edServiceUrlChange
      end
      object edReceivableAccount: TsEdit
        Left = 368
        Top = 370
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 11
        Text = '1300'
        OnChange = edServiceUrlChange
      end
      object edPreInvoiceNumber: TsEdit
        Left = 368
        Top = 398
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
        OnChange = edServiceUrlChange
      end
      object edSuccInvoiceNumber: TsEdit
        Left = 368
        Top = 426
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 13
        OnChange = edServiceUrlChange
      end
      object btnSave: TsButton
        Left = 630
        Top = 521
        Width = 75
        Height = 25
        Caption = 'Save'
        Enabled = False
        TabOrder = 14
        OnClick = btnSaveClick
      end
      object edCurrency: TsEdit
        Left = 368
        Top = 454
        Width = 169
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 4473924
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 15
        OnChange = edServiceUrlChange
      end
    end
    object sTabSheet2: TsTabSheet
      Caption = 'Mappings'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 725
      object tabsMappings: TsTabControl
        AlignWithMargins = True
        Left = 3
        Top = 20
        Width = 862
        Height = 25
        Margins.Top = 20
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        Style = tsButtons
        TabOrder = 0
        Tabs.Strings = (
          'Customers'
          'Items'
          'Vat codes'
          'Pay groups')
        TabIndex = 0
        OnChange = tabsMappingsChange
        ExplicitWidth = 719
      end
      object pnl0: TsPanel
        Left = 2
        Top = 102
        Width = 398
        Height = 423
        TabOrder = 1
        object grCustomers: TcxGrid
          Left = 1
          Top = 1
          Width = 396
          Height = 421
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
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
        Left = 92
        Top = 115
        Width = 499
        Height = 359
        TabOrder = 2
        object grItems: TcxGrid
          Left = 1
          Top = 1
          Width = 497
          Height = 357
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
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
        Top = 100
        Width = 665
        Height = 327
        TabOrder = 3
        object grVats: TcxGrid
          Left = 1
          Top = 1
          Width = 663
          Height = 325
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
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
      object sPanel1: TsPanel
        Left = 0
        Top = 48
        Width = 868
        Height = 36
        Align = alTop
        TabOrder = 4
        ExplicitWidth = 725
        object edtSearch: TButtonedEdit
          AlignWithMargins = True
          Left = 4
          Top = 6
          Width = 860
          Height = 24
          Margins.Top = 5
          Margins.Bottom = 5
          Align = alClient
          BevelInner = bvNone
          BevelOuter = bvNone
          Images = DImages.PngImageList1
          LeftButton.DisabledImageIndex = 130
          LeftButton.Enabled = False
          LeftButton.HotImageIndex = 130
          LeftButton.ImageIndex = 130
          LeftButton.PressedImageIndex = 130
          LeftButton.Visible = True
          RightButton.DisabledImageIndex = 131
          RightButton.HotImageIndex = 131
          RightButton.ImageIndex = 131
          RightButton.PressedImageIndex = 131
          TabOrder = 0
          OnChange = edtSearchChange
          OnRightButtonClick = edtSearchRightButtonClick
          ExplicitWidth = 717
          ExplicitHeight = 21
        end
      end
      object pnl3: TsPanel
        Left = 167
        Top = 47
        Width = 665
        Height = 327
        TabOrder = 5
        object cxGrid1: TcxGrid
          Left = 1
          Top = 1
          Width = 663
          Height = 325
          Align = alClient
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object tvPayGroups: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            DataController.DataSource = dsPayGroups
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            object tvPayGroupsRecId: TcxGridDBColumn
              DataBinding.FieldName = 'RecId'
              Visible = False
            end
            object tvPayGroupsCode: TcxGridDBColumn
              DataBinding.FieldName = 'Code'
              Options.Editing = False
              Width = 114
            end
            object tvPayGroupsName: TcxGridDBColumn
              DataBinding.FieldName = 'Name'
              Options.Editing = False
              Width = 269
            end
            object tvPayGroupsBalanceAccount: TcxGridDBColumn
              DataBinding.FieldName = 'BalanceAccount'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  Kind = bkEllipsis
                end>
              Properties.OnButtonClick = tvPayGroupsBalanceAccountPropertiesButtonClick
            end
            object tvPayGroupsCashBook: TcxGridDBColumn
              DataBinding.FieldName = 'CashBook'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  Kind = bkEllipsis
                end>
              Properties.OnButtonClick = tvPayGroupsCashBookPropertiesButtonClick
            end
          end
          object glPayGroups: TcxGridLevel
            GridView = tvPayGroups
          end
        end
      end
    end
  end
  object memCustomers: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    BeforePost = memCustomersBeforePost
    Left = 504
    Top = 40
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
    Left = 504
    Top = 88
  end
  object memItems: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    BeforePost = memItemsBeforePost
    Left = 568
    Top = 40
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
    Left = 568
    Top = 88
  end
  object memVats: TdxMemData
    Active = True
    Indexes = <>
    SortOptions = []
    BeforePost = memVatsBeforePost
    Left = 632
    Top = 40
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
    Left = 632
    Top = 88
  end
  object memPayGroups: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 16
    Top = 472
    object memPayGroupsCode: TWideStringField
      FieldName = 'Code'
      Size = 40
    end
    object memPayGroupsName: TWideStringField
      FieldName = 'Name'
      Size = 80
    end
    object memPayGroupsBalanceAccount: TStringField
      FieldName = 'BalanceAccount'
      Size = 15
    end
    object memPayGroupsCashBook: TStringField
      FieldName = 'CashBook'
      Size = 15
    end
  end
  object dsPayGroups: TDataSource
    DataSet = memPayGroups
    Left = 16
    Top = 520
  end
end
