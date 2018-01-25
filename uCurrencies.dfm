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
  inherited pnlTop: TsPanel
    Width = 847
    Height = 89
    TabOrder = 1
    ExplicitWidth = 847
    ExplicitHeight = 89
    inherited pnlGridButons: TsPanel
      Width = 847
      ExplicitWidth = 847
      inherited btnInsert: TsButton
        TabOrder = 4
      end
      object btnHistory: TsButton
        AlignWithMargins = True
        Left = 423
        Top = 4
        Width = 90
        Height = 33
        Align = alLeft
        Caption = 'History'
        ImageIndex = 138
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = btnHistoryClick
        SkinData.SkinSection = 'BUTTON'
      end
    end
    inherited pnlFilter: TsPanel
      Width = 847
      Height = 48
      ExplicitWidth = 847
      ExplicitHeight = 48
      inherited btnClear: TsSpeedButton
        OnClick = nil
      end
      inherited chkActive: TsCheckBox
        OnClick = nil
      end
      inherited edFilter: TsEdit
        OnChange = nil
      end
    end
  end
  inherited pnlClient: TsPanel
    Top = 89
    Width = 847
    Height = 366
    ExplicitTop = 89
    ExplicitWidth = 847
    ExplicitHeight = 366
    inherited grData: TcxGrid
      Width = 845
      Height = 364
      ExplicitLeft = 2
      ExplicitTop = 0
      ExplicitWidth = 845
      ExplicitHeight = 364
      inherited tvData: TcxGridDBBandedTableView
        DataController.Options = [dcoAssignMasterDetailKeys, dcoSaveExpanding]
        OptionsData.Deleting = True
        OptionsData.Editing = True
        OptionsData.Inserting = True
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
  object m_: TdxMemData [7]
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
  object mnuOther: TPopupMenu [8]
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
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43108.585563333330000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
end
