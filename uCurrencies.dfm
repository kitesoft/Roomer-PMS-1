inherited frmCurrencies: TfrmCurrencies
  Left = 2968
  Top = 305
  Caption = 'Currencies'
  ClientHeight = 518
  ClientWidth = 847
  Constraints.MinWidth = 460
  ParentFont = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 863
  ExplicitHeight = 557
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 498
    Width = 847
    ExplicitTop = 498
    ExplicitWidth = 847
  end
  inherited grData: TcxGrid
    Top = 89
    Width = 847
    Height = 366
    TabOrder = 0
    ExplicitTop = 89
    ExplicitWidth = 847
    ExplicitHeight = 366
    inherited tvData: TcxGridDBBandedTableView
      DataController.Options = [dcoAssignMasterDetailKeys, dcoSaveExpanding]
      OptionsView.GroupByBox = False
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
      object tvDataCurrency: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Currency'
        Width = 67
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvDataDescription: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Description'
        Width = 224
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvDataactive: TcxGridDBBandedColumn
        Caption = 'Active'
        DataBinding.FieldName = 'active'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        HeaderAlignmentHorz = taCenter
        Width = 66
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvDataAValue: TcxGridDBBandedColumn
        Caption = 'Rate'
        DataBinding.FieldName = 'AValue'
        HeaderAlignmentHorz = taRightJustify
        Width = 75
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvDataCurrencySign: TcxGridDBBandedColumn
        DataBinding.FieldName = 'CurrencySign'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        HeaderAlignmentHorz = taRightJustify
        Width = 96
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvDatadisplayformat: TcxGridDBBandedColumn
        Caption = 'Displayformat'
        DataBinding.FieldName = 'displayformat'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        HeaderAlignmentHorz = taRightJustify
        Width = 138
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object tvDatadecimals: TcxGridDBBandedColumn
        Caption = 'Decimals'
        DataBinding.FieldName = 'decimals'
        HeaderAlignmentHorz = taRightJustify
        Width = 72
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object tvDataID: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ID'
        Visible = False
        Width = 54
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object tvDataSellValue: TcxGridDBBandedColumn
        DataBinding.FieldName = 'SellValue'
        Visible = False
        Width = 53
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 0
      end
    end
  end
  inherited pnlTop: TsPanel
    Width = 847
    Height = 89
    TabOrder = 3
    ExplicitWidth = 847
    ExplicitHeight = 89
    object cLabFilter: TsLabel
      Left = 19
      Top = 42
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
      Left = 273
      Top = 39
      Width = 59
      Height = 21
      Caption = 'Clear'
      OnClick = btnClearClick
      SkinData.SkinSection = 'SPEEDBUTTON'
      Images = DImages.PngImageList1
      ImageIndex = 10
    end
    object btnInsert: TsButton
      Left = 10
      Top = 7
      Width = 82
      Height = 26
      Hint = 'Add new record'
      Caption = 'New'
      ImageIndex = 23
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = btnInsertClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnEdit: TsButton
      Left = 98
      Top = 7
      Width = 82
      Height = 26
      Hint = 'Edit current record'
      Caption = 'Edit'
      ImageIndex = 25
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = btnEditClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnDelete: TsButton
      Left = 186
      Top = 7
      Width = 81
      Height = 26
      Hint = 'Delete current record'
      Caption = 'Delete'
      ImageIndex = 24
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = btnDeleteClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOther: TsButton
      Left = 273
      Top = 7
      Width = 144
      Height = 26
      Hint = 'Other actions - Select from menu'
      Caption = 'Other actions'
      DropDownMenu = mnuOther
      ImageIndex = 76
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      Style = bsSplitButton
      TabOrder = 3
      SkinData.SkinSection = 'BUTTON'
    end
    object chkActive: TsCheckBox
      Left = 56
      Top = 63
      Width = 273
      Height = 20
      Caption = 'Active (if checked then just active are visible else all)'
      Checked = True
      State = cbChecked
      TabOrder = 4
      OnClick = chkActiveClick
      SkinData.SkinSection = 'CHECKBOX'
      ImgChecked = 0
      ImgUnchecked = 0
    end
    object edFilter: TsEdit
      Left = 56
      Top = 39
      Width = 206
      Height = 21
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnChange = edFilterChange
      SkinData.SkinSection = 'EDIT'
    end
    object btnHistory: TsButton
      Left = 423
      Top = 7
      Width = 81
      Height = 26
      Hint = 'Delete current record'
      Caption = 'History'
      ImageIndex = 138
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = btnHistoryClick
      SkinData.SkinSection = 'BUTTON'
    end
  end
  inherited pnlButtons: TsPanel
    Top = 455
    Width = 847
    TabOrder = 2
    ExplicitTop = 455
    ExplicitWidth = 847
    inherited btnOK: TsButton
      Left = 531
      OnClick = btnOKClick
      ExplicitLeft = 531
    end
    inherited btnCancel: TsButton
      Left = 637
      OnClick = btnCancelClick
      ExplicitLeft = 637
    end
    inherited btnClose: TsButton
      Left = 743
      ExplicitLeft = 743
    end
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 568
    Top = 72
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
    Left = 88
    Top = 224
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforePost = m_BeforePost
    BeforeDelete = m_BeforeDelete
    OnNewRecord = m_NewRecord
    Left = 88
    Top = 280
    object m_Currency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object m_Description: TWideStringField
      FieldName = 'Description'
      Size = 30
    end
    object m_AValue: TFloatField
      FieldName = 'AValue'
    end
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_active: TBooleanField
      FieldName = 'active'
    end
    object m_displayformat: TWideStringField
      FieldName = 'displayformat'
    end
    object m_decimals: TIntegerField
      FieldName = 'decimals'
    end
    object m_SellValue: TFloatField
      FieldName = 'SellValue'
    end
    object m_CurrencySign: TWideStringField
      FieldName = 'CurrencySign'
      Size = 6
    end
  end
  object mnuOther: TPopupMenu
    Images = DImages.PngImageList1
    Left = 248
    Top = 216
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
  object grPrinter: TdxComponentPrinter
    CurrentLink = prLink_grData
    Version = 0
    Left = 88
    Top = 336
    object prLink_grData: TdxGridReportLink
      Active = True
      Component = grData
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
      ReportDocument.CreationDate = 43103.660572638890000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
end
