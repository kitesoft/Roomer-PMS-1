inherited frmChannels: TfrmChannels
  Caption = 'Channels'
  ClientHeight = 500
  ClientWidth = 1092
  Constraints.MinWidth = 450
  Font.Height = -11
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  ExplicitWidth = 1108
  ExplicitHeight = 539
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 480
    Width = 1092
    ExplicitTop = 480
    ExplicitWidth = 1092
  end
  object pnlFilter: TsPanel [1]
    Left = 0
    Top = 37
    Width = 1092
    Height = 54
    Align = alTop
    Constraints.MinWidth = 450
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object labFilterWarning: TsLabel
      Left = 1
      Top = 40
      Width = 3
      Height = 13
      Align = alBottom
      Alignment = taCenter
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cLabFilter: TsLabel
      Left = 19
      Top = 12
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
      Left = 265
      Top = 9
      Width = 71
      Height = 20
      Caption = 'Clear'
      OnClick = btnClearClick
      SkinData.SkinSection = 'SPEEDBUTTON'
      Images = DImages.PngImageList1
      ImageIndex = 10
    end
    object edFilter: TsEdit
      Left = 56
      Top = 9
      Width = 206
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
  object pnlButtons: TsPanel [2]
    Left = 0
    Top = 443
    Width = 1092
    Height = 37
    Align = alBottom
    TabOrder = 2
    SkinData.SkinSection = 'PANEL'
    object btnCancel: TsButton
      AlignWithMargins = True
      Left = 1003
      Top = 4
      Width = 85
      Height = 29
      Hint = 'Cancel and close'
      Align = alRight
      Caption = 'Cancel'
      ImageIndex = 4
      Images = DImages.PngImageList1
      ModalResult = 2
      TabOrder = 0
      OnClick = btnCancelClick
      SkinData.SkinSection = 'BUTTON'
    end
    object BtnOk: TsButton
      AlignWithMargins = True
      Left = 912
      Top = 4
      Width = 85
      Height = 29
      Hint = 'Apply and close'
      Align = alRight
      Caption = 'OK'
      ImageIndex = 82
      Images = DImages.PngImageList1
      ModalResult = 1
      TabOrder = 1
      OnClick = BtnOkClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
  object grData: TcxGrid [3]
    Left = 0
    Top = 91
    Width = 1092
    Height = 352
    Align = alClient
    TabOrder = 3
    LookAndFeel.NativeStyle = False
    ExplicitTop = 89
    object tvData: TcxGridDBTableView
      OnDblClick = tvDataDblClick
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.First.Visible = True
      Navigator.Buttons.PriorPage.Hint = 'Prior page'
      Navigator.Buttons.PriorPage.Visible = True
      Navigator.Buttons.Prior.Hint = 'Prior'
      Navigator.Buttons.Prior.Visible = True
      Navigator.Buttons.Next.Hint = 'Next'
      Navigator.Buttons.Next.Visible = True
      Navigator.Buttons.NextPage.Hint = 'Next page'
      Navigator.Buttons.NextPage.Visible = True
      Navigator.Buttons.Last.Hint = 'Last'
      Navigator.Buttons.Last.Visible = True
      Navigator.Buttons.Insert.Hint = 'Insert'
      Navigator.Buttons.Insert.Visible = True
      Navigator.Buttons.Append.Enabled = False
      Navigator.Buttons.Append.Hint = 'Append'
      Navigator.Buttons.Append.Visible = False
      Navigator.Buttons.Delete.Hint = 'Delete'
      Navigator.Buttons.Delete.Visible = True
      Navigator.Buttons.Edit.Enabled = False
      Navigator.Buttons.Edit.Hint = 'Edit'
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Hint = 'Post'
      Navigator.Buttons.Post.Visible = True
      Navigator.Buttons.Cancel.Hint = 'Cancel'
      Navigator.Buttons.Cancel.Visible = True
      Navigator.Buttons.Refresh.Enabled = False
      Navigator.Buttons.Refresh.Hint = 'Refresh'
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Enabled = False
      Navigator.Buttons.SaveBookmark.Hint = 'Save bookmark'
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Enabled = False
      Navigator.Buttons.GotoBookmark.Hint = 'Goto bookmark'
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Hint = 'Filter'
      Navigator.Buttons.Filter.Visible = True
      Navigator.InfoPanel.Visible = True
      Navigator.Visible = True
      OnEditing = tvDataEditing
      OnFocusedRecordChanged = tvDataFocusedRecordChanged
      DataController.DataSource = DS
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      DataController.OnSortingChanged = tvDataDataControllerSortingChanged
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.IncSearch = True
      OptionsData.Appending = True
      OptionsData.CancelOnExit = False
      OptionsData.DeletingConfirmation = False
      OptionsView.GroupByBox = False
      OptionsView.HeaderAutoHeight = True
      OptionsView.Indicator = True
      object tvDataRecId: TcxGridDBColumn
        DataBinding.FieldName = 'RecId'
        Visible = False
      end
      object tvDataID: TcxGridDBColumn
        DataBinding.FieldName = 'ID'
        Visible = False
      end
      object tvDatachannelManagerId: TcxGridDBColumn
        Caption = 'Code'
        DataBinding.FieldName = 'channelManagerId'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.CharCase = ecUpperCase
      end
      object tvDatadirectConnection: TcxGridDBColumn
        Caption = 'Direct Connection'
        DataBinding.FieldName = 'directConnection'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Width = 97
      end
      object tvDataname: TcxGridDBColumn
        Caption = 'Channel name'
        DataBinding.FieldName = 'name'
        PropertiesClassName = 'TcxTextEditProperties'
        Width = 200
      end
      object tvDatacolor: TcxGridDBColumn
        Caption = 'Color'
        DataBinding.FieldName = 'color'
        PropertiesClassName = 'TcxColorComboBoxProperties'
        Properties.CustomColors = <>
        Options.ShowEditButtons = isebAlways
        Width = 40
      end
      object tvDataroomClasses: TcxGridDBColumn
        Caption = 'Room Classes'
        DataBinding.FieldName = 'roomClasses'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataroomClassesPropertiesButtonClick
        Width = 220
      end
      object tvDataactivePlanCode: TcxGridDBColumn
        Caption = 'Plan Code'
        DataBinding.FieldName = 'activePlanCode'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataactivePlanCodePropertiesButtonClick
      end
      object tvDataratesExcludingTaxes: TcxGridDBColumn
        Caption = 'Rates Excl Taxes'
        DataBinding.FieldName = 'ratesExcludingTaxes'
        Width = 50
      end
      object tvDataminAlotment: TcxGridDBColumn
        Caption = 'Min Allot'
        DataBinding.FieldName = 'minAlotment'
        PropertiesClassName = 'TcxSpinEditProperties'
        Width = 72
      end
      object tvDatadefaultAvailability: TcxGridDBColumn
        Caption = 'Def Availability'
        DataBinding.FieldName = 'defaultAvailability'
        PropertiesClassName = 'TcxSpinEditProperties'
        Width = 100
      end
      object tvDatadefaultPricePP: TcxGridDBColumn
        Caption = 'Def Price/Person'
        DataBinding.FieldName = 'defaultPricePP'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ImmediateDropDownWhenKeyPressed = True
        Width = 110
      end
      object tvDataActive: TcxGridDBColumn
        DataBinding.FieldName = 'Active'
        Width = 54
      end
      object tvDatamarketSegment: TcxGridDBColumn
        Caption = 'Market'
        DataBinding.FieldName = 'marketSegment'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDatamarketSegmentPropertiesButtonClick
        Width = 64
      end
      object tvDatacurrencyId: TcxGridDBColumn
        Caption = 'curr Id'
        DataBinding.FieldName = 'currencyId'
        Visible = False
        Width = 60
      end
      object tvDataCurrency: TcxGridDBColumn
        DataBinding.FieldName = 'Currency'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataCurrencyPropertiesButtonClick
        Width = 88
      end
      object tvDatamanagedByChannelManager: TcxGridDBColumn
        Caption = 'Channel Manager'
        DataBinding.FieldName = 'managedByChannelManager'
        Width = 120
      end
      object tvDataCHANNEL_ARRANGES_PAYMENT: TcxGridDBColumn
        Caption = 'Channel arranges payment'
        DataBinding.FieldName = 'CHANNEL_ARRANGES_PAYMENT'
        Width = 153
      end
      object tvDatadefaultChannel: TcxGridDBColumn
        Caption = 'Is Default'
        DataBinding.FieldName = 'defaultChannel'
        Width = 82
      end
      object tvDatapush: TcxGridDBColumn
        Caption = 'Push'
        DataBinding.FieldName = 'push'
        Width = 49
      end
      object tvDatacustomerId: TcxGridDBColumn
        Caption = 'Customer'
        DataBinding.FieldName = 'customerId'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDatacustomerIdPropertiesButtonClick
      end
      object tvDatarateRoundingType: TcxGridDBColumn
        Caption = 'Rate Rounding'
        DataBinding.FieldName = 'RateRoundingText'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'No rounding'
          'Round to nearest whole number'
          'Round up to whole number'
          'Round down to whole number'
          'Round to 1 decimal'
          'Round to 2 decimals'
          'Round to 3 decimals')
        Width = 148
      end
      object tvDatacompensationPercentage: TcxGridDBColumn
        Caption = 'Compen- sation %'
        DataBinding.FieldName = 'compensationPercentage'
        Width = 53
      end
      object tvDatahotelsBookingEngine: TcxGridDBColumn
        Caption = 'Is Hotel owned'
        DataBinding.FieldName = 'hotelsBookingEngine'
        Width = 54
      end
      object tvDatarateRoundingType1: TcxGridDBColumn
        DataBinding.FieldName = 'rateRoundingType'
      end
    end
    object lvData: TcxGridLevel
      GridView = tvData
    end
  end
  object pnlToolbarButtons: TsPanel [4]
    Left = 0
    Top = 0
    Width = 1092
    Height = 37
    Align = alTop
    TabOrder = 4
    object btnClose: TsButton
      AlignWithMargins = True
      Left = 1008
      Top = 4
      Width = 80
      Height = 29
      Align = alRight
      Caption = 'Close'
      ImageIndex = 27
      Images = DImages.PngImageList1
      ModalResult = 8
      TabOrder = 7
      OnClick = btnCloseClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnDelete: TsButton
      AlignWithMargins = True
      Left = 246
      Top = 4
      Width = 115
      Height = 29
      Hint = 'Delete current record'
      Align = alLeft
      Caption = 'Delete'
      ImageIndex = 24
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = btnDeleteClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnEdit: TsButton
      AlignWithMargins = True
      Left = 125
      Top = 4
      Width = 115
      Height = 29
      Hint = 'Edit current record'
      Align = alLeft
      Caption = 'Edit'
      ImageIndex = 25
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = btnEditClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnInsert: TsButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 115
      Height = 29
      Hint = 'Add new record'
      Align = alLeft
      Caption = 'New'
      ImageIndex = 23
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = btnInsertClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOther: TsButton
      AlignWithMargins = True
      Left = 367
      Top = 4
      Width = 115
      Height = 29
      Align = alLeft
      Caption = 'Other actions'
      DropDownMenu = mnuOther
      ImageIndex = 76
      Images = DImages.PngImageList1
      Style = bsSplitButton
      TabOrder = 3
      SkinData.SkinSection = 'BUTTON'
    end
    object btnPaymentMatrix: TsButton
      AlignWithMargins = True
      Left = 488
      Top = 4
      Width = 146
      Height = 29
      Hint = 'Add new record'
      Align = alLeft
      Caption = 'Payment Matrix'
      ImageIndex = 113
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = btnPaymentMatrixClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnConfirmation: TsButton
      AlignWithMargins = True
      Left = 640
      Top = 4
      Width = 146
      Height = 29
      Hint = 'Add new record'
      Align = alLeft
      Caption = 'Confirmation emails'
      ImageIndex = 113
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = btnConfirmationClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnHotelNotifications: TsButton
      AlignWithMargins = True
      Left = 792
      Top = 4
      Width = 146
      Height = 29
      Hint = 'Add new record'
      Align = alLeft
      Caption = 'Hotel notification emails'
      ImageIndex = 113
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = btnHotelNotificationsClick
      SkinData.SkinSection = 'BUTTON'
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
  object mnuOther: TPopupMenu
    Left = 38
    Top = 152
    object mnuiPrint: TMenuItem
      Caption = 'Print'
      OnClick = mnuiPrintClick
    end
    object mnuiAllowGridEdit: TMenuItem
      Caption = 'Allow grid edit'
      Checked = True
      OnClick = mnuiAllowGridEditClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Export1: TMenuItem
      Caption = 'Export'
      object mnuiGridToExcel: TMenuItem
        Caption = 'Grid to Excel'
        OnClick = mnuiGridToExcelClick
      end
      object mnuiGridToHtml: TMenuItem
        Caption = 'Grid to HTML'
        OnClick = mnuiGridToHtmlClick
      end
      object mnuiGridToText: TMenuItem
        Caption = 'Grid to text'
        OnClick = mnuiGridToTextClick
      end
      object mnuiGridToXml: TMenuItem
        Caption = 'Grid to XML'
        OnClick = mnuiGridToXmlClick
      end
    end
  end
  object DS: TDataSource
    DataSet = m_
    Left = 368
    Top = 288
  end
  object grPrinter: TdxComponentPrinter
    CurrentLink = prLink_grData
    Version = 0
    Left = 368
    Top = 224
    object prLink_grData: TdxGridReportLink
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.GrayShading = True
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 41334.495374884260000000
      BuiltInReportLink = True
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforeInsert = m_BeforeInsert
    BeforePost = m_BeforePost
    BeforeDelete = m_BeforeDelete
    OnNewRecord = m_NewRecord
    Left = 120
    Top = 152
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_Active: TBooleanField
      FieldName = 'Active'
    end
    object m_name: TWideStringField
      FieldName = 'name'
      Size = 35
    end
    object m_channelManagerId: TWideStringField
      FieldName = 'channelManagerId'
      Size = 10
    end
    object m_minAlotment: TIntegerField
      FieldName = 'minAlotment'
    end
    object m_defaultAvailability: TIntegerField
      FieldName = 'defaultAvailability'
    end
    object m_defaultPricePP: TFloatField
      FieldName = 'defaultPricePP'
    end
    object m_marketSegment: TWideStringField
      FieldName = 'marketSegment'
    end
    object m_currencyId: TIntegerField
      FieldName = 'currencyId'
    end
    object m_roomClasses: TWideStringField
      DisplayWidth = 2096
      FieldName = 'roomClasses'
      Size = 2096
    end
    object m_Currency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object m_managedByChannelManager: TBooleanField
      FieldName = 'managedByChannelManager'
    end
    object m_default: TBooleanField
      DisplayLabel = 'default'
      FieldName = 'defaultChannel'
    end
    object m_push: TBooleanField
      FieldName = 'push'
    end
    object m_customerId: TIntegerField
      FieldName = 'customerId'
    end
    object m_color: TWideStringField
      FieldName = 'color'
      Size = 50
    end
    object m_ratesExcludingTaxes: TBooleanField
      FieldName = 'ratesExcludingTaxes'
    end
    object m_rateRoundingType: TIntegerField
      FieldName = 'rateRoundingType'
    end
    object m_compensationPercentage: TFloatField
      FieldName = 'compensationPercentage'
    end
    object m_hotelsBookingEngine: TBooleanField
      FieldName = 'hotelsBookingEngine'
    end
    object m_RateRoundingText: TStringField
      FieldName = 'RateRoundingText'
      Size = 30
    end
    object m_CHANNEL_ARRANGES_PAYMENT: TBooleanField
      FieldName = 'CHANNEL_ARRANGES_PAYMENT'
    end
    object m_directConnection: TBooleanField
      FieldName = 'directConnection'
    end
    object m_activePlanCode: TIntegerField
      FieldName = 'activePlanCode'
    end
  end
end
