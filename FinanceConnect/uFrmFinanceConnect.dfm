inherited FrmFinanceConnect: TFrmFinanceConnect
  BorderStyle = bsSizeable
  Caption = 'Finance Connect'
  ClientHeight = 591
  ClientWidth = 866
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  ExplicitWidth = 882
  ExplicitHeight = 630
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 571
    Width = 866
    ExplicitTop = 571
    ExplicitWidth = 866
  end
  object pgMain: TsPageControl [1]
    Left = 0
    Top = 0
    Width = 866
    Height = 528
    ActivePage = tsSettings
    Align = alClient
    TabOrder = 0
    OnChange = pgMainChange
    object tsSettings: TsTabSheet
      Caption = 'Settings'
      object gbxConnectionSettings: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 852
        Height = 265
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
        object sLabel1: TsLabel
          Left = 64
          Top = 33
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
        object sLabel2: TsLabel
          Left = 125
          Top = 83
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
          Top = 112
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
          Top = 141
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
          Top = 171
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
          Top = 199
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
          Top = 228
          Width = 75
          Height = 13
          Alignment = taRightJustify
          Caption = 'Company code:'
          ParentFont = False
          Visible = False
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
          OnCloseUp = cbxSystemSelectionCloseUp
        end
        object cbxActive: TsCheckBox
          Left = 200
          Top = 57
          Width = 58
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
        object __edServiceUrl: TsEdit
          Left = 200
          Top = 80
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
        object edUsername: TsEdit
          Left = 200
          Top = 109
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
        object edPassword: TsEdit
          Left = 200
          Top = 138
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
          TabOrder = 4
          OnChange = HandleChange
        end
        object edOrg: TsEdit
          Left = 200
          Top = 168
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
        object edOffice: TsEdit
          Left = 200
          Top = 196
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
          OnChange = HandleChange
        end
        object edCompany: TsEdit
          Left = 200
          Top = 225
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
          Visible = False
        end
      end
      object gbxBookkeeping: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 274
        Width = 852
        Height = 223
        Align = alClient
        Caption = 'Bookkeeping codes and settings'
        Color = clBtnFace
        ParentColor = False
        TabOrder = 1
        SkinData.SkinSection = 'PANEL'
        object sLabel8: TsLabel
          Left = 100
          Top = 28
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
        object sLabel12: TsLabel
          Left = 57
          Top = 55
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
          Left = 37
          Top = 83
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
          Left = 37
          Top = 111
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
          Left = 146
          Top = 139
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
          Top = 25
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
          Top = 52
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
          Top = 80
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
          Top = 108
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
          Top = 136
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
    Top = 528
    Width = 866
    ExplicitTop = 528
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
