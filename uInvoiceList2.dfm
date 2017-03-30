inherited frmInvoiceList2: TfrmInvoiceList2
  Left = 738
  Top = 198
  Caption = 'Detailed Invoice List'
  ClientHeight = 616
  ClientWidth = 1133
  Font.Height = -11
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 1149
  ExplicitHeight = 655
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 596
    Width = 1133
    OnDrawPanel = nil
    ExplicitTop = 596
    ExplicitWidth = 1133
  end
  object LMDSimplePanel1: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1133
    Height = 183
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object LMDGroupBox1: TsGroupBox
      Left = 10
      Top = 10
      Width = 531
      Height = 120
      Caption = 'Search'
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object LMDSimpleLabel2: TsLabel
        Left = 251
        Top = 20
        Width = 11
        Height = 16
        Caption = 'to'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSimpleLabel3: TsLabel
        Left = 251
        Top = 44
        Width = 11
        Height = 16
        Caption = 'to'
        ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
      end
      object LMDSpeedButton3: TsButton
        Left = 251
        Top = 89
        Width = 122
        Height = 25
        Caption = 'Refresh'
        Default = True
        ImageIndex = 28
        Images = DImages.PngImageList1
        TabOrder = 12
        OnClick = LMDSpeedButton3Click
        SkinData.SkinSection = 'BUTTON'
      end
      object dtFrom: TsDateEdit
        Left = 146
        Top = 18
        Width = 102
        Height = 21
        AutoSize = False
        Color = clWhite
        Enabled = False
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 4
        Text = '  -  -    '
        OnChange = dtFromChange
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object dtTo: TsDateEdit
        Left = 285
        Top = 18
        Width = 102
        Height = 21
        AutoSize = False
        Color = clWhite
        Enabled = False
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 5
        Text = '  -  -    '
        OnChange = dtToChange
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
      end
      object rbtDates: TsRadioButton
        Left = 4
        Top = 19
        Width = 82
        Height = 19
        Caption = 'Date range'
        TabOrder = 0
        OnClick = rbtDatesClick
        SkinData.SkinSection = 'CHECKBOX'
      end
      object rbtInvoices: TsRadioButton
        Left = 4
        Top = 42
        Width = 96
        Height = 19
        Caption = 'Number range'
        TabOrder = 1
        OnClick = rbtDatesClick
        SkinData.SkinSection = 'CHECKBOX'
      end
      object cbxPeriod: TsComboBox
        Left = 393
        Top = 18
        Width = 131
        Height = 21
        Alignment = taLeftJustify
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        Style = csDropDownList
        Color = clWhite
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 6
        OnChange = cbxPeriodChange
        Items.Strings = (
          ' - None Selected -'
          'Today'
          'Yesterday'
          'In the last 5 Days'
          'In the last 10 Days'
          'In the this Week'
          'last Week'
          'In this Month'
          'Last Month'
          'In this Year'
          'Last Year'
          'From the beginning'
          ' ')
      end
      object edtFreeText: TsEdit
        Left = 146
        Top = 67
        Width = 241
        Height = 21
        Color = clWhite
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
        OnChange = edtFreeTextChange
        SkinData.SkinSection = 'EDIT'
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
      end
      object rbtFreeText: TsRadioButton
        Left = 4
        Top = 68
        Width = 75
        Height = 19
        Caption = 'Text filter'
        TabOrder = 2
        OnClick = rbtDatesClick
        SkinData.SkinSection = 'CHECKBOX'
      end
      object rbtLast: TsRadioButton
        Left = 4
        Top = 92
        Width = 48
        Height = 19
        Caption = 'Last'
        Checked = True
        TabOrder = 3
        TabStop = True
        OnClick = rbtDatesClick
        SkinData.SkinSection = 'CHECKBOX'
      end
      object cbxTxtType: TsComboBox
        Left = 393
        Top = 68
        Width = 131
        Height = 21
        Alignment = taLeftJustify
        BoundLabel.Font.Charset = DEFAULT_CHARSET
        BoundLabel.Font.Color = clWindowText
        BoundLabel.Font.Height = -13
        BoundLabel.Font.Name = 'Tahoma'
        BoundLabel.Font.Style = []
        SkinData.SkinSection = 'COMBOBOX'
        VerticalAlignment = taAlignTop
        Style = csDropDownList
        Color = clWhite
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemIndex = -1
        ParentFont = False
        TabOrder = 10
        OnChange = cbxTxtTypeChange
        Items.Strings = (
          'Invoice Number'
          'Customer number'
          'Name of Guest or Company'
          'Refernce'
          'Booking number'
          'Room Booking')
      end
      object edtLast: TsSpinEdit
        Left = 146
        Top = 91
        Width = 102
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 11
        OnChange = edLastCountChange
        SkinData.SkinSection = 'EDIT'
        MaxValue = 99
        MinValue = 1
        Value = 0
      end
      object edtInvoiceFrom: TsSpinEdit
        Left = 146
        Top = 41
        Width = 102
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnChange = edtInvoiceFromChange
        SkinData.SkinSection = 'EDIT'
        MaxValue = 999999
        MinValue = 0
        Value = 0
      end
      object edtInvoiceTo: TsSpinEdit
        Left = 285
        Top = 42
        Width = 102
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        OnChange = edtInvoiceToChange
        SkinData.SkinSection = 'EDIT'
        MaxValue = 999999
        MinValue = 0
        Value = 0
      end
    end
    object btnExport: TsButton
      Left = 547
      Top = 19
      Width = 118
      Height = 44
      Caption = 'Export invoices'
      TabOrder = 1
      OnClick = btnExportClick
      SkinData.SkinSection = 'BUTTON'
    end
    object pnlButtons: TsPanel
      Left = 1
      Top = 141
      Width = 1131
      Height = 41
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      object LMDSpeedButton6: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'EXCEL'
        ImageIndex = 132
        Images = DImages.PngImageList1
        TabOrder = 0
        OnClick = LMDSpeedButton6Click
        SkinData.SkinSection = 'BUTTON'
      end
      object btnReservation: TsButton
        AlignWithMargins = True
        Left = 109
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Reservation'
        ImageIndex = 56
        Images = DImages.PngImageList1
        TabOrder = 1
        OnClick = btnReservationClick
        SkinData.SkinSection = 'BUTTON'
      end
      object LMDSpeedButton1: TsButton
        AlignWithMargins = True
        Left = 215
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Guests'
        ImageIndex = 39
        Images = DImages.PngImageList1
        TabOrder = 2
        OnClick = LMDSpeedButton1Click
        SkinData.SkinSection = 'BUTTON'
      end
      object btnViewInvoice: TsButton
        AlignWithMargins = True
        Left = 321
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Invoice'
        ImageIndex = 63
        Images = DImages.PngImageList1
        TabOrder = 3
        OnClick = btnViewInvoiceClick
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton1: TsButton
        AlignWithMargins = True
        Left = 427
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Print'
        ImageIndex = 3
        Images = DImages.PngImageList1
        TabOrder = 4
        OnClick = sButton1Click
        SkinData.SkinSection = 'BUTTON'
      end
      object sButton2: TsButton
        AlignWithMargins = True
        Left = 533
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Best fit'
        Images = DImages.PngImageList1
        TabOrder = 5
        OnClick = sButton2Click
        SkinData.SkinSection = 'BUTTON'
      end
      object LMDButton1: TsButton
        AlignWithMargins = True
        Left = 639
        Top = 3
        Width = 100
        Height = 35
        Align = alLeft
        Caption = 'Jump to room'
        ImageIndex = 57
        Images = DImages.PngImageList1
        ModalResult = 1
        TabOrder = 6
        OnClick = LMDButton1Click
        SkinData.SkinSection = 'BUTTON'
      end
    end
  end
  object sPanel1: TsPanel [2]
    Left = 0
    Top = 183
    Width = 1133
    Height = 33
    Align = alTop
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object cLabFilter: TsLabel
      Left = 70
      Top = 9
      Width = 31
      Height = 13
      Alignment = taRightJustify
      Caption = 'Filter :'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object btnClear: TsSpeedButton
      Left = 322
      Top = 6
      Width = 100
      Height = 21
      Caption = 'Clear'
      OnClick = btnClearClick
      SkinData.SkinSection = 'SPEEDBUTTON'
      Images = DImages.PngImageList1
      ImageIndex = 10
    end
    object edFilter: TsEdit
      Left = 107
      Top = 6
      Width = 209
      Height = 21
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = edFilterChange
      SkinData.SkinSection = 'EDIT'
    end
  end
  object grInvoiceHead: TcxGrid [3]
    Left = 0
    Top = 216
    Width = 1133
    Height = 380
    Align = alClient
    TabOrder = 2
    LookAndFeel.NativeStyle = False
    object tvInvoiceHead: TcxGridDBBandedTableView
      OnDblClick = tvInvoiceHeadDblClick
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.PriorPage.Enabled = False
      Navigator.Buttons.Prior.Enabled = False
      Navigator.Buttons.Insert.Enabled = False
      Navigator.Buttons.Append.Enabled = False
      Navigator.Buttons.Delete.Enabled = False
      Navigator.Buttons.Edit.Enabled = False
      Navigator.Buttons.Post.Enabled = False
      Navigator.Buttons.Cancel.Enabled = False
      Navigator.InfoPanel.Visible = True
      Navigator.Visible = True
      FilterBox.Visible = fvNever
      OnCellClick = tvInvoiceHeadCellClick
      OnSelectionChanged = tvInvoiceHeadSelectionChanged
      DataController.DataSource = mDS
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = ',0.00;-,0.00'
          FieldName = 'Amount'
          Column = tvInvoiceHeadAmount
        end
        item
          Format = ',0.00;-,0.00'
          FieldName = 'WithOutVAT'
          Column = tvInvoiceHeadWithOutVAT
        end
        item
          Format = ',0.00;-,0.00'
          FieldName = 'VAT'
          Column = tvInvoiceHeadVAT
        end
        item
        end
        item
        end
        item
          Format = ',0.00;-,0.00'
          Kind = skSum
          Column = tvInvoiceHeadLocalAmount
        end
        item
          Format = ',0.00;-,0.00'
          Kind = skSum
          Column = tvInvoiceHeadLocalWithOutVAT
        end
        item
          Format = ',0.00;-,0.00'
          Kind = skSum
          Column = tvInvoiceHeadLocalVAT
        end>
      DataController.Summary.SummaryGroups = <>
      Filtering.ColumnFilteredItemsList = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Inserting = False
      OptionsSelection.MultiSelect = True
      OptionsView.Footer = True
      OptionsView.HeaderAutoHeight = True
      OptionsView.Indicator = True
      Bands = <
        item
          Caption = 'Invoice'
          FixedKind = fkLeft
          Width = 592
        end
        item
          Caption = 'Amounts'
          Width = 895
        end
        item
          Caption = 'Customer'
        end
        item
          Caption = 'Other'
        end>
      object tvInvoiceHeadRowSelected: TcxGridDBBandedColumn
        DataBinding.FieldName = 'RowSelected'
        Visible = False
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
        IsCaptionAssigned = True
      end
      object tvInvoiceHeadInvoiceNumber: TcxGridDBBandedColumn
        Caption = 'Number'
        DataBinding.FieldName = 'InvoiceNumber'
        Options.Editing = False
        Width = 63
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvInvoiceHeadexternalInvoiceId: TcxGridDBBandedColumn
        Caption = 'External #'
        DataBinding.FieldName = 'externalInvoiceId'
        Options.Editing = False
        Width = 63
        Position.BandIndex = 1
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object tvInvoiceHeadInvoiceDate: TcxGridDBBandedColumn
        Caption = 'Date'
        DataBinding.FieldName = 'InvoiceDate'
        Options.Editing = False
        Width = 63
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvInvoiceHeadDueDate: TcxGridDBBandedColumn
        Caption = 'Due Date'
        DataBinding.FieldName = 'DueDate'
        Options.Editing = False
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCreditType: TcxGridDBBandedColumn
        DataBinding.FieldName = 'CreditType'
        Options.Editing = False
        Width = 69
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvInvoiceHeadNameOnInvoice: TcxGridDBBandedColumn
        Caption = 'Name on Invoice'
        DataBinding.FieldName = 'NameOnInvoice'
        Options.Editing = False
        Width = 136
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvInvoiceHeadInvoicetype: TcxGridDBBandedColumn
        Caption = 'Invoice type'
        DataBinding.FieldName = 'Invoicetype'
        Options.Editing = False
        Width = 67
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object tvInvoiceHeadLink: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Link'
        Options.Editing = False
        Width = 60
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object tvInvoiceHeadLocalAmount: TcxGridDBBandedColumn
        Caption = 'Local Gross Amount'
        DataBinding.FieldName = 'LocalAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadLocalAmountGetProperties
        Options.Editing = False
        Width = 95
        Position.BandIndex = 1
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvInvoiceHeadexportAllowed: TcxGridDBBandedColumn
        Caption = 'Exportable'
        DataBinding.FieldName = 'exportAllowed'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Options.Editing = False
        Width = 63
        Position.BandIndex = 1
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvInvoiceHeadLocalWithOutVAT: TcxGridDBBandedColumn
        Caption = 'Local Net Amount'
        DataBinding.FieldName = 'LocalWithOutVAT'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadLocalAmountGetProperties
        Options.Editing = False
        Width = 100
        Position.BandIndex = 1
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvInvoiceHeadLocalVAT: TcxGridDBBandedColumn
        Caption = 'Local VAT'
        DataBinding.FieldName = 'LocalVAT'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadLocalAmountGetProperties
        Options.Editing = False
        Width = 67
        Position.BandIndex = 1
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvInvoiceHeadAmount: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Amount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadAmountGetProperties
        Options.Editing = False
        Width = 61
        Position.BandIndex = 1
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvInvoiceHeadWithOutVAT: TcxGridDBBandedColumn
        Caption = 'Without VAT'
        DataBinding.FieldName = 'WithOutVAT'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadWithOutVATGetProperties
        Options.Editing = False
        Width = 71
        Position.BandIndex = 1
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object tvInvoiceHeadVAT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'VAT'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadVATGetProperties
        Options.Editing = False
        Width = 31
        Position.BandIndex = 1
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object tvInvoiceHeadTaxes: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Taxes'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        OnGetProperties = tvInvoiceHeadTaxesGetProperties
        Options.Editing = False
        Width = 38
        Position.BandIndex = 1
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object tvInvoiceHeadpaytypes: TcxGridDBBandedColumn
        Caption = 'Pay types'
        DataBinding.FieldName = 'paytypes'
        Options.Editing = False
        Width = 79
        Position.BandIndex = 1
        Position.ColIndex = 13
        Position.RowIndex = 0
      end
      object tvInvoiceHeadpayments: TcxGridDBBandedColumn
        Caption = 'Paid amounts'
        DataBinding.FieldName = 'payments'
        Options.Editing = False
        Width = 70
        Position.BandIndex = 1
        Position.ColIndex = 14
        Position.RowIndex = 0
      end
      object tvInvoiceHeadTaxunits: TcxGridDBBandedColumn
        Caption = 'Tax units'
        DataBinding.FieldName = 'Taxunits'
        Options.Editing = False
        Width = 33
        Position.BandIndex = 1
        Position.ColIndex = 9
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCurrency: TcxGridDBBandedColumn
        Caption = 'Curr.'
        DataBinding.FieldName = 'Currency'
        Options.Editing = False
        Width = 36
        Position.BandIndex = 1
        Position.ColIndex = 10
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCurrencyRate: TcxGridDBBandedColumn
        Caption = 'Rate'
        DataBinding.FieldName = 'CurrencyRate'
        Options.Editing = False
        Width = 37
        Position.BandIndex = 1
        Position.ColIndex = 11
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCurrencyAmount: TcxGridDBBandedColumn
        Caption = 'Currency Amount'
        DataBinding.FieldName = 'CurrencyAmount'
        PropertiesClassName = 'TcxCurrencyEditProperties'
        Properties.DisplayFormat = ',0.00;-,0.00'
        Options.Editing = False
        Width = 51
        Position.BandIndex = 1
        Position.ColIndex = 12
        Position.RowIndex = 0
      end
      object tvInvoiceHeadRoomGuest: TcxGridDBBandedColumn
        DataBinding.FieldName = 'RoomGuest'
        Options.Editing = False
        Width = 156
        Position.BandIndex = 2
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCustomer: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Customer'
        Options.Editing = False
        Width = 80
        Position.BandIndex = 2
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCompanyId: TcxGridDBBandedColumn
        DataBinding.FieldName = 'CompanyId'
        Options.Editing = False
        Width = 80
        Position.BandIndex = 2
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvInvoiceHeadCustomerName: TcxGridDBBandedColumn
        DataBinding.FieldName = 'CustomerName'
        Options.Editing = False
        Width = 150
        Position.BandIndex = 2
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvInvoiceHeadAddress1: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Address1'
        Options.Editing = False
        Width = 150
        Position.BandIndex = 2
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvInvoiceHeadAddress2: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Address2'
        Options.Editing = False
        Width = 150
        Position.BandIndex = 2
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvInvoiceHeadAddress3: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Address3'
        Options.Editing = False
        Width = 150
        Position.BandIndex = 2
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object tvInvoiceHeadRefrence: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Refrence'
        Options.Editing = False
        Width = 120
        Position.BandIndex = 3
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object tvInvoiceHeadStaff: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Staff'
        Options.Editing = False
        Width = 37
        Position.BandIndex = 3
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvInvoiceHeadConfirmdate: TcxGridDBBandedColumn
        Caption = 'Confirm date'
        DataBinding.FieldName = 'Confirmdate'
        Options.Editing = False
        Width = 75
        Position.BandIndex = 3
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvInvoiceHeadReservation: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Reservation'
        Options.Editing = False
        Width = 74
        Position.BandIndex = 3
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvInvoiceHeadRoomReservation: TcxGridDBBandedColumn
        Caption = 'Room Reservation'
        DataBinding.FieldName = 'RoomReservation'
        Options.Editing = False
        Width = 118
        Position.BandIndex = 3
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
    end
    object lvInvoiceHead: TcxGridLevel
      GridView = tvInvoiceHead
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
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
  object FormStore: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\InvoiceList2x'
    StorageType = stRegistry
    Left = 478
    Top = 328
  end
  object mDS: TDataSource
    DataSet = m22_
    Left = 184
    Top = 464
  end
  object m22_: TkbmMemTable
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
        Size = 200
      end
      item
        Name = 'Address1'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Address2'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Address3'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'Refrence'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'LocalAmount'
        DataType = ftFloat
      end
      item
        Name = 'LocalWithOutVAT'
        DataType = ftFloat
      end
      item
        Name = 'LocalVAT'
        DataType = ftFloat
      end
      item
        Name = 'Amount'
        DataType = ftFloat
      end
      item
        Name = 'WithOutVAT'
        DataType = ftFloat
      end
      item
        Name = 'VAT'
        DataType = ftFloat
      end
      item
        Name = 'RoomGuest'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'InvoiceDate'
        DataType = ftDateTime
      end
      item
        Name = 'Confirmdate'
        DataType = ftDateTime
      end
      item
        Name = 'DueDate'
        DataType = ftDateTime
      end
      item
        Name = 'Staff'
        DataType = ftWideString
        Size = 40
      end
      item
        Name = 'CompanyId'
        DataType = ftWideString
        Size = 50
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
        Name = 'Taxes'
        DataType = ftFloat
      end
      item
        Name = 'Taxunits'
        DataType = ftInteger
      end
      item
        Name = 'CreditType'
        DataType = ftString
        Size = 25
      end
      item
        Name = 'CurrencyAmount'
        DataType = ftFloat
      end
      item
        Name = 'Invoicetype'
        DataType = ftString
        Size = 25
      end
      item
        Name = 'Link'
        DataType = ftInteger
      end
      item
        Name = 'CustomerName'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'RowSelected'
        DataType = ftBoolean
      end
      item
        Name = 'externalInvoiceId'
        DataType = ftInteger
      end
      item
        Name = 'paytypes'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'payments'
        DataType = ftWideString
        Size = 200
      end
      item
        Name = 'exportAllowed'
        DataType = ftBoolean
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
    Left = 344
    Top = 432
  end
  object pmnuExportMenu: TPopupMenu
    OnPopup = pmnuExportMenuPopup
    Left = 696
    Top = 392
    object mnuExport: TMenuItem
      Caption = 'Export selected invoices'
      OnClick = mnuExportClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object mnuExportability: TMenuItem
      Caption = 'Toggle exportability of selected invoices'
      OnClick = mnuExportabilityClick
    end
    object E1: TMenuItem
      Caption = 'Edit finance export properties'
      OnClick = E1Click
    end
  end
end
