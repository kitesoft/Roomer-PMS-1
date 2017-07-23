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
    ActivePage = sTabSheet2
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object sTabSheet1: TsTabSheet
      Caption = 'Settings'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
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
        Left = 250
        Top = 331
        Width = 112
        Height = 13
        Alignment = taRightJustify
        Caption = 'Sales transaction code:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel9: TsLabel
        Left = 200
        Top = 296
        Width = 212
        Height = 16
        Caption = 'Book keeping codes and settings'
      end
      object sLabel10: TsLabel
        Left = 251
        Top = 359
        Width = 111
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash transaction code:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel11: TsLabel
        Left = 253
        Top = 387
        Width = 109
        Height = 13
        Alignment = taRightJustify
        Caption = 'Cash balance account:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel12: TsLabel
        Left = 225
        Top = 415
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
        Left = 207
        Top = 443
        Width = 155
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text preceeding nvoice number:'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object sLabel14: TsLabel
        Left = 207
        Top = 471
        Width = 155
        Height = 13
        Alignment = taRightJustify
        Caption = 'Text succeeding nvoice number:'
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
        Left = 199
        Top = 56
        Width = 64
        Height = 17
        Caption = 'Active'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
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
        Font.Color = clBlack
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
        Font.Color = clBlack
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
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 4
        Text = 'This is not valid password'
        OnChange = edServiceUrlChange
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
        OnChange = edServiceUrlChange
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
        OnChange = edServiceUrlChange
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
        OnChange = edServiceUrlChange
      end
      object edSalesCode: TsEdit
        Left = 368
        Top = 328
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
        OnChange = edServiceUrlChange
      end
      object edCashCode: TsEdit
        Left = 368
        Top = 356
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
        OnChange = edServiceUrlChange
      end
      object edCashAccount: TsEdit
        Left = 368
        Top = 384
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
        OnChange = edServiceUrlChange
      end
      object edReceivableAccount: TsEdit
        Left = 368
        Top = 412
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
        OnChange = edServiceUrlChange
      end
      object edPreInvoiceNumber: TsEdit
        Left = 368
        Top = 440
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
        OnChange = edServiceUrlChange
      end
      object edSuccInvoiceNumber: TsEdit
        Left = 368
        Top = 468
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
        OnChange = edServiceUrlChange
      end
      object btnSave: TsButton
        Left = 630
        Top = 497
        Width = 75
        Height = 25
        Caption = 'Save'
        Enabled = False
        TabOrder = 14
        OnClick = btnSaveClick
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
      object tabsMappings: TsTabControl
        AlignWithMargins = True
        Left = 3
        Top = 20
        Width = 822
        Height = 25
        Margins.Top = 20
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
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
          ExplicitTop = 2
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
        Width = 828
        Height = 36
        Align = alTop
        TabOrder = 4
        ExplicitTop = 51
        object edtSearch: TButtonedEdit
          AlignWithMargins = True
          Left = 4
          Top = 6
          Width = 820
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
          ExplicitLeft = 280
          ExplicitTop = 5
          ExplicitWidth = 109
          ExplicitHeight = 21
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
