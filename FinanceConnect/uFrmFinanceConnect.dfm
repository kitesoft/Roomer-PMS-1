inherited FrmFinanceConnect: TFrmFinanceConnect
  BorderStyle = bsSizeable
  Caption = 'Finance Connect'
  ClientHeight = 686
  ClientWidth = 866
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  ExplicitWidth = 882
  ExplicitHeight = 725
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 666
    Width = 866
    ExplicitTop = 666
    ExplicitWidth = 866
  end
  object pgMain: TsPageControl [1]
    Left = 0
    Top = 0
    Width = 866
    Height = 623
    ActivePage = tsMappings
    Align = alClient
    TabOrder = 0
    OnChange = pgMainChange
    object tsSettings: TsTabSheet
      Caption = 'Settings'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object gbxConnectionSettings: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 45
        Width = 852
        Height = 212
        Align = alTop
        Caption = 'Finance Connect settings'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object lbServiceUrl: TsLabel
          Left = 125
          Top = 128
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
        object lbUsername: TsLabel
          Left = 90
          Top = 155
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
        object lbPassword: TsLabel
          Left = 136
          Top = 182
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
        object lbOrg: TsLabel
          Left = 95
          Top = 75
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
        object lbOffice: TsLabel
          Left = 127
          Top = 101
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
        object lbSystemName: TsLabel
          Left = 118
          Top = 49
          Width = 68
          Height = 13
          Alignment = taRightJustify
          Caption = 'System name:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object cbxActive: TsCheckBox
          Left = 200
          Top = 22
          Width = 50
          Height = 20
          Caption = 'Active'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = cbxActiveClick
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object __edServiceUrl: TsEdit
          Left = 200
          Top = 125
          Width = 505
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnChange = HandleChange
        end
        object edUsername: TsEdit
          Left = 200
          Top = 152
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
          OnChange = HandleChange
        end
        object edPassword: TsEdit
          Left = 200
          Top = 179
          Width = 505
          Height = 24
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PasswordChar = '*'
          TabOrder = 6
          OnChange = HandleChange
        end
        object edOrg: TsEdit
          Left = 200
          Top = 72
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
          OnChange = HandleChange
        end
        object edOffice: TsEdit
          Left = 200
          Top = 98
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
          OnChange = HandleChange
        end
        object edSystemName: TsEdit
          Left = 200
          Top = 46
          Width = 505
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnChange = HandleChange
        end
      end
      object gbxBookkeeping: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 263
        Width = 852
        Height = 159
        Align = alTop
        Caption = 'Bookkeeping codes and settings'
        Color = clBtnFace
        ParentColor = False
        TabOrder = 1
        SkinData.SkinSection = 'PANEL'
        object lbReceivablesLedger: TsLabel
          Left = 100
          Top = 27
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
        object lbReceivableBalanceAccount: TsLabel
          Left = 57
          Top = 53
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
        object lbTexPreceedingInvoice: TsLabel
          Left = 37
          Top = 79
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
        object lbTextSucceedingInvoiceNumber: TsLabel
          Left = 37
          Top = 105
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
        object lbCurrency: TsLabel
          Left = 146
          Top = 131
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
        object edSalesCode: TsEdit
          Left = 200
          Top = 24
          Width = 169
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = 'VRK'
          OnChange = HandleChange
        end
        object edReceivableAccount: TsEdit
          Left = 200
          Top = 50
          Width = 169
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = '1300'
          OnChange = HandleChange
        end
        object edPreInvoiceNumber: TsEdit
          Left = 200
          Top = 76
          Width = 169
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object edSuccInvoiceNumber: TsEdit
          Left = 200
          Top = 102
          Width = 169
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
        object edCurrency: TsEdit
          Left = 200
          Top = 128
          Width = 169
          Height = 21
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnChange = HandleChange
        end
      end
      object gbMappingResources: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 428
        Width = 852
        Height = 164
        Align = alClient
        Caption = 'Mapping resources'
        Color = clBtnFace
        ParentColor = False
        TabOrder = 2
        SkinData.SkinSection = 'PANEL'
        object lbCustomersMappingResource: TsLabel
          Left = 123
          Top = 28
          Width = 71
          Height = 13
          Alignment = taRightJustify
          Caption = 'Customers list:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbItemsMappingResource: TsLabel
          Left = 147
          Top = 54
          Width = 47
          Height = 13
          Alignment = taRightJustify
          Caption = 'Items list:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbVatsMappingResource: TsLabel
          Left = 158
          Top = 80
          Width = 36
          Height = 13
          Alignment = taRightJustify
          Caption = 'Vat list:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbCashBookssMappingResource: TsLabel
          Left = 118
          Top = 132
          Width = 76
          Height = 13
          Alignment = taRightJustify
          Caption = 'Cash-books list:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbPayGroupsMappingResource: TsLabel
          Left = 125
          Top = 106
          Width = 69
          Height = 13
          Alignment = taRightJustify
          Caption = 'Pay group list:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object edCustomersList: TsEdit
          Left = 200
          Top = 25
          Width = 505
          Height = 21
          Hint = 'Exmaple: http://www.mycrnter.com/customers.resoursc'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnChange = HandleChange
        end
        object edItemsList: TsEdit
          Left = 200
          Top = 51
          Width = 505
          Height = 21
          Hint = 'Exmaple: http://www.mycrnter.com/items.resoursc'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnChange = HandleChange
        end
        object edVatList: TsEdit
          Left = 200
          Top = 77
          Width = 505
          Height = 21
          Hint = 'Exmaple: http://www.mycrnter.com/vat.resoursc'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnChange = HandleChange
        end
        object edCashBookList: TsEdit
          Left = 200
          Top = 129
          Width = 505
          Height = 21
          Hint = 'Exmaple: http://www.mycrnter.com/cashbooks.resoursc'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnChange = HandleChange
        end
        object edPaygroupList: TsEdit
          Left = 200
          Top = 103
          Width = 505
          Height = 21
          Hint = 'Exmaple: http://www.mycrnter.com/paymentaccounts.resoursc'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnChange = HandleChange
        end
      end
      object pnlFinanceSystem: TsPanel
        Left = 0
        Top = 0
        Width = 858
        Height = 42
        Align = alTop
        TabOrder = 3
        object sLabel1: TsLabel
          Left = 67
          Top = 13
          Width = 122
          Height = 13
          Alignment = taRightJustify
          Caption = 'Finance Connect System:'
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object cbxSystemSelection: TsComboBox
          Left = 203
          Top = 10
          Width = 164
          Height = 21
          Alignment = taLeftJustify
          VerticalAlignment = taAlignTop
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
          OnChange = cbxSystemSelectionChange
        end
      end
    end
    object tsMappings: TsTabSheet
      Caption = 'Mappings'
      object tabsMappings: TsTabControl
        AlignWithMargins = True
        Left = 3
        Top = 20
        Width = 852
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
            OptionsBehavior.FocusCellOnTab = True
            OptionsView.ColumnAutoWidth = True
            Styles.StyleSheet = cxssRoomerGridTableView
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
            OptionsBehavior.FocusCellOnTab = True
            OptionsView.ColumnAutoWidth = True
            Styles.StyleSheet = cxssRoomerGridTableView
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
            OptionsBehavior.FocusCellOnTab = True
            OptionsView.ColumnAutoWidth = True
            Styles.StyleSheet = cxssRoomerGridTableView
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
        Width = 858
        Height = 36
        Align = alTop
        TabOrder = 4
        object edtSearch: TButtonedEdit
          AlignWithMargins = True
          Left = 4
          Top = 6
          Width = 850
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
          ExplicitHeight = 21
        end
      end
      object pnl3: TsPanel
        Left = 424
        Top = 168
        Width = 408
        Height = 206
        TabOrder = 5
        object grdPaygroups: TcxGrid
          Left = 1
          Top = 1
          Width = 406
          Height = 204
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
            OptionsBehavior.FocusCellOnTab = True
            OptionsView.ColumnAutoWidth = True
            Styles.StyleSheet = cxssRoomerGridTableView
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
  inherited pnlButtons: TsPanel
    Top = 623
    Width = 866
    ExplicitTop = 623
    ExplicitWidth = 866
    inherited btnOK: TsButton
      Left = 550
      Default = False
      OnClick = btnOKClick
      ExplicitLeft = 550
    end
    inherited btnCancel: TsButton
      Left = 656
      ExplicitLeft = 656
    end
    inherited btnClose: TsButton
      Left = 762
      ExplicitLeft = 762
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
    Left = 688
    Top = 40
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
    Left = 688
    Top = 88
  end
end
