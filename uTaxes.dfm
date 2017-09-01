inherited frmTaxes: TfrmTaxes
  Caption = 'Taxes'
  ClientHeight = 521
  ClientWidth = 1112
  Constraints.MinWidth = 750
  ParentFont = False
  Position = poOwnerFormCenter
  OnCloseQuery = FormCloseQuery
  ExplicitWidth = 1128
  ExplicitHeight = 560
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 501
    Width = 1112
    ExplicitTop = 501
    ExplicitWidth = 1112
  end
  inherited grData: TcxGrid
    Top = 89
    Width = 1112
    Height = 369
    TabOrder = 2
    ExplicitTop = 89
    ExplicitWidth = 1112
    ExplicitHeight = 369
    inherited tvData: TcxGridDBBandedTableView
      Navigator.Buttons.PriorPage.Visible = False
      Navigator.Buttons.NextPage.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Visible = True
      OptionsView.ColumnAutoWidth = False
      Styles.Content = nil
      Styles.ContentEven = nil
      Styles.ContentOdd = nil
      Styles.Selection = nil
      Styles.Footer = nil
      Styles.Group = nil
      Styles.GroupSummary = nil
      Styles.Header = nil
      Styles.Preview = nil
      object tvDataRecId: TcxGridDBBandedColumn
        DataBinding.FieldName = 'RecId'
        Visible = False
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object tvDataID: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ID'
        Visible = False
        Width = 23
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvDataValid_From: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Valid_From'
        PropertiesClassName = 'TcxDateEditProperties'
        MinWidth = 100
        Width = 102
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvDataValid_To: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Valid_To'
        PropertiesClassName = 'TcxDateEditProperties'
        MinWidth = 100
        Width = 100
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvDataDescription: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Description'
        MinWidth = 200
        Width = 224
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvDataAmount: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Amount'
        PropertiesClassName = 'TcxCalcEditProperties'
        OnGetProperties = tvDataAmountGetProperties
        MinWidth = 75
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object tvDataTax_Type: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Tax_Type'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'FIXED_AMOUNT'
          'PERCENTAGE')
        Properties.MaxLength = 30
        MinWidth = 75
        Width = 103
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvDataTax_Base: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Tax_Base'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'ROOM_NIGHT'
          'GUEST_NIGHT')
        Properties.MaxLength = 30
        Properties.OnValidate = tvDataIncl_ExclPropertiesValidate
        MinWidth = 75
        Width = 97
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object tvDataTime_Due: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Time_Due'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'PREPAID'
          'CHECKOUT')
        MinWidth = 75
        Width = 122
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 0
      end
      object tvDataReTaxable: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ReTaxable'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'FALSE'
          'TRUE')
        MinWidth = 75
        Width = 122
        Position.BandIndex = 0
        Position.ColIndex = 10
        Position.RowIndex = 0
      end
      object tvDataTaxChildren: TcxGridDBBandedColumn
        DataBinding.FieldName = 'TaxChildren'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'FALSE'
          'TRUE')
        MinWidth = 75
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 15
        Position.RowIndex = 0
      end
      object tvDataBooking_Item_Id: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Booking_Item_Id'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataBooking_Item_IdPropertiesButtonClick
        Visible = False
        Width = 122
        Position.BandIndex = 0
        Position.ColIndex = 11
        Position.RowIndex = 0
      end
      object tvDataHotel_Id: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Hotel_Id'
        Visible = False
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 12
        Position.RowIndex = 0
      end
      object tvDataBooking_Item: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Booking_Item'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataBooking_Item_IdPropertiesButtonClick
        Properties.OnValidate = tvDataBooking_ItemPropertiesValidate
        MinWidth = 100
        Width = 100
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object tvDataIncl_Excl: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Incl_Excl'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'EXCLUDED'
          'INCLUDED'
          'PER_CUSTOMER')
        Properties.OnValidate = tvDataIncl_ExclPropertiesValidate
        MinWidth = 75
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 13
        Position.RowIndex = 0
      end
      object tvDataNetto_Amount_Based: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Netto_Amount_Based'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'FALSE'
          'TRUE')
        MinWidth = 130
        Width = 130
        Position.BandIndex = 0
        Position.ColIndex = 14
        Position.RowIndex = 0
      end
      object tvDataValue_Formula: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Value_Formula'
        MinWidth = 75
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 16
        Position.RowIndex = 0
      end
    end
  end
  inherited pnlTop: TsPanel
    Width = 1112
    Height = 89
    TabOrder = 1
    ExplicitWidth = 1112
    ExplicitHeight = 89
    object cLabFilter: TsLabel
      Left = 19
      Top = 41
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
      Left = 271
      Top = 39
      Width = 66
      Height = 20
      Caption = 'Clear'
      OnClick = btnClearClick
      SkinData.SkinSection = 'SPEEDBUTTON'
      Images = DImages.PngImageList1
      ImageIndex = 10
    end
    object btnDelete: TsButton
      Left = 199
      Top = 7
      Width = 90
      Height = 26
      Caption = 'Delete'
      ImageIndex = 24
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnDeleteClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOther: TsButton
      Left = 295
      Top = 7
      Width = 134
      Height = 26
      Caption = 'Other actions'
      DropDownMenu = mnuOther
      ImageIndex = 76
      Images = DImages.PngImageList1
      Style = bsSplitButton
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
    object edFilter: TsEdit
      Left = 56
      Top = 39
      Width = 213
      Height = 21
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnChange = edFilterChange
      SkinData.SkinSection = 'EDIT'
    end
    object chkActive: TsCheckBox
      Left = 56
      Top = 65
      Width = 238
      Height = 20
      Caption = 'Active (if checked then just active are visible)'
      Checked = True
      State = cbChecked
      TabOrder = 3
      Visible = False
      OnClick = chkActiveClick
      SkinData.SkinSection = 'CHECKBOX'
      ImgChecked = 0
      ImgUnchecked = 0
    end
    object btnInsert: TsButton
      Left = 7
      Top = 7
      Width = 90
      Height = 26
      Hint = 'Add new record'
      Caption = 'New'
      ImageIndex = 23
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = btnInsertClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnEdit: TsButton
      Left = 103
      Top = 7
      Width = 90
      Height = 26
      Hint = 'Edit current record'
      Caption = 'Edit'
      ImageIndex = 25
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = btnEditClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnRefresh: TsButton
      Left = 449
      Top = 7
      Width = 79
      Height = 26
      Hint = 'Refresh'
      Anchors = [akTop, akRight]
      Caption = 'Refresh'
      ImageIndex = 28
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
  inherited pnlButtons: TsPanel
    Top = 458
    Width = 1112
    TabOrder = 0
    ExplicitTop = 458
    ExplicitWidth = 1112
    inherited btnOK: TsButton
      Left = 796
      ExplicitLeft = 796
    end
    inherited btnCancel: TsButton
      Left = 902
      ExplicitLeft = 902
    end
    inherited btnClose: TsButton
      Left = 1008
      ExplicitLeft = 1008
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 760
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 648
    Top = 16
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      BuiltIn = True
    end
  end
  inherited dsData: TDataSource
    DataSet = m_
    Left = 112
    Top = 200
  end
  object mnuOther: TPopupMenu
    Left = 190
    Top = 160
    object mnuiPrint: TMenuItem
      Caption = 'Print'
      ImageIndex = 3
      OnClick = mnuiPrintClick
    end
    object A1: TMenuItem
      Caption = 'Apply best fit'
      OnClick = A1Click
    end
    object mnuiAllowGridEdit: TMenuItem
      Caption = 'Allow grid edit'
      Checked = True
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Export1: TMenuItem
      Caption = 'Export'
      ImageIndex = 98
      object mnuiGridToExcel: TMenuItem
        Caption = 'Grid to Excel'
        ImageIndex = 132
        OnClick = mnuiGridToExcelClick
      end
      object mnuiGridToHtml: TMenuItem
        Caption = 'Grid to HTML'
        ImageIndex = 99
        OnClick = mnuiGridToHtmlClick
      end
      object mnuiGridToText: TMenuItem
        Caption = 'Grid to text'
        ImageIndex = 0
        OnClick = mnuiGridToTextClick
      end
      object mnuiGridToXml: TMenuItem
        Caption = 'Grid to XML'
        ImageIndex = 0
        OnClick = mnuiGridToXmlClick
      end
    end
  end
  object grPrinter: TdxComponentPrinter
    CurrentLink = prLink_grData
    Version = 0
    Left = 368
    Top = 224
    object prLink_grData: TdxGridReportLink
      PageNumberFormat = pnfNumeral
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
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforeInsert = m_BeforeInsert
    BeforePost = m_BeforePost
    OnNewRecord = m_NewRecord
    Left = 104
    Top = 272
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_Description: TWideStringField
      FieldName = 'Description'
      Required = True
      Size = 64
    end
    object m_Amount: TFloatField
      FieldName = 'Amount'
    end
    object m_Tax_Type: TWideStringField
      FieldName = 'Tax_Type'
      Size = 30
    end
    object m_Tax_Base: TWideStringField
      FieldName = 'Tax_Base'
      Size = 30
    end
    object m_Time_Due: TWideStringField
      FieldName = 'Time_Due'
      Size = 30
    end
    object m_ReTaxable: TWideStringField
      FieldName = 'ReTaxable'
      Size = 10
    end
    object m_Booking_Item_Id: TIntegerField
      FieldName = 'Booking_Item_Id'
    end
    object m_Hotel_Id: TWideStringField
      FieldName = 'Hotel_Id'
      Size = 10
    end
    object m_Booking_Item: TWideStringField
      FieldName = 'Booking_Item'
      Size = 30
    end
    object m_Incl_Excl: TWideStringField
      FieldName = 'Incl_Excl'
      Size = 15
    end
    object m_Netto_Amount_Based: TWideStringField
      FieldName = 'Netto_Amount_Based'
      Size = 10
    end
    object m_Value_Formula: TWideStringField
      FieldName = 'Value_Formula'
      Size = 255
    end
    object m_Valid_From: TDateField
      FieldName = 'Valid_From'
    end
    object m_Valid_To: TDateField
      FieldName = 'Valid_To'
    end
    object m_TaxChildren: TWideStringField
      DisplayWidth = 10
      FieldName = 'TaxChildren'
      Size = 10
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 192
    Top = 216
    object C1: TMenuItem
      Caption = 'Duplicate current'
      OnClick = C1Click
    end
  end
end
