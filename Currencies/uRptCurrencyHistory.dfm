inherited frmCurrencyHistory: TfrmCurrencyHistory
  Caption = 'Currency History'
  ClientHeight = 442
  ClientWidth = 810
  Font.Height = -11
  ExplicitWidth = 826
  ExplicitHeight = 481
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 422
    Width = 810
    ExplicitTop = 422
    ExplicitWidth = 1005
  end
  object grCurrencyHistory: TcxGrid [1]
    Left = 0
    Top = 78
    Width = 810
    Height = 344
    Align = alClient
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    ExplicitWidth = 1005
    object tvCurrencyHistory: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = dsData
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoGroupsAlwaysExpanded]
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skCount
          Position = spFooter
        end
        item
          Format = '0'
          Kind = skSum
          Position = spFooter
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0'
          Kind = skCount
        end
        item
          Format = '0'
          Kind = skSum
        end>
      DataController.Summary.SummaryGroups = <>
      FilterRow.Visible = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
      object tvCurrencyHistoryLogtime: TcxGridDBColumn
        DataBinding.FieldName = 'Logtime'
        PropertiesClassName = 'TcxDateEditProperties'
        SortIndex = 0
        SortOrder = soDescending
        Width = 149
      end
      object tvCurrencyHistoryCurrency: TcxGridDBColumn
        DataBinding.FieldName = 'Currency'
        Width = 76
      end
      object tvCurrencyHistoryDescription: TcxGridDBColumn
        DataBinding.FieldName = 'Description'
        Width = 195
      end
      object tvCurrencyHistoryRate: TcxGridDBColumn
        DataBinding.FieldName = 'Rate'
        PropertiesClassName = 'TcxCalcEditProperties'
        HeaderAlignmentHorz = taRightJustify
        Width = 87
      end
      object tvCurrencyHistoryActive: TcxGridDBColumn
        DataBinding.FieldName = 'Active'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        HeaderAlignmentHorz = taCenter
        Width = 62
      end
      object tvCurrencyHistoryCurrencySign: TcxGridDBColumn
        DataBinding.FieldName = 'CurrencySign'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Visible = False
        HeaderAlignmentHorz = taRightJustify
        Width = 85
      end
      object tvCurrencyHistoryDisplayFormat: TcxGridDBColumn
        DataBinding.FieldName = 'DisplayFormat'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Visible = False
        HeaderAlignmentHorz = taRightJustify
        Width = 145
      end
      object tvCurrencyHistoryDecimals: TcxGridDBColumn
        DataBinding.FieldName = 'Decimals'
        PropertiesClassName = 'TcxCalcEditProperties'
        HeaderAlignmentHorz = taRightJustify
        Width = 78
      end
      object tvCurrencyHistoryAction: TcxGridDBColumn
        DataBinding.FieldName = 'Action'
        Visible = False
        Width = 111
      end
      object tvCurrencyHistorylastUpdate: TcxGridDBColumn
        DataBinding.FieldName = 'lastUpdate'
        PropertiesClassName = 'TcxDateEditProperties'
        Visible = False
        Width = 133
      end
    end
    object lvCurrencyHistory: TcxGridLevel
      GridView = tvCurrencyHistory
    end
  end
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 810
    Height = 78
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitWidth = 1005
    object btnExcel: TsButton
      AlignWithMargins = True
      Left = 545
      Top = 3
      Width = 128
      Height = 43
      Align = alRight
      Caption = 'Excel'
      ImageIndex = 115
      Images = DImages.PngImageList1
      TabOrder = 0
      OnClick = btnExcelClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 740
      ExplicitHeight = 34
    end
    object btnReport: TsButton
      AlignWithMargins = True
      Left = 679
      Top = 3
      Width = 128
      Height = 43
      Align = alRight
      Caption = 'Report'
      ImageIndex = 69
      Images = DImages.PngImageList1
      TabOrder = 1
      OnClick = btnReportClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitLeft = 874
      ExplicitHeight = 34
    end
    object pnlFilter: TsPanel
      Left = 0
      Top = 49
      Width = 810
      Height = 29
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
    end
    object btnRefresh: TsButton
      AlignWithMargins = True
      Left = 20
      Top = 3
      Width = 118
      Height = 43
      Margins.Left = 20
      Align = alLeft
      Caption = 'Refresh'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 3
      OnClick = btnRefreshClick
      SkinData.SkinSection = 'BUTTON'
      ExplicitHeight = 34
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
  object m_Currencyhistory: TdxMemData
    Indexes = <>
    SortOptions = []
    AfterScroll = m_CurrencyhistoryAfterScroll
    Left = 288
    Top = 311
    object m_CurrencyhistoryLogtime: TDateTimeField
      FieldName = 'Logtime'
    end
    object m_CurrencyhistoryCurrency: TWideStringField
      FieldName = 'Currency'
      Size = 5
    end
    object m_CurrencyhistoryDescription: TWideStringField
      FieldName = 'Description'
      Size = 30
    end
    object m_CurrencyhistoryRate: TFloatField
      FieldName = 'Rate'
    end
    object m_CurrencyhistoryActive: TBooleanField
      FieldName = 'Active'
    end
    object m_CurrencyhistoryCurrencySign: TWideStringField
      DisplayWidth = 3
      FieldName = 'CurrencySign'
      Size = 3
    end
    object m_CurrencyhistorylastUpdate: TDateTimeField
      FieldName = 'lastUpdate'
    end
    object m_CurrencyhistoryDisplayFormat: TWideStringField
      FieldName = 'DisplayFormat'
    end
    object m_CurrencyhistoryDecimals: TIntegerField
      FieldName = 'Decimals'
    end
    object m_CurrencyhistoryAction: TWideStringField
      FieldName = 'Action'
      Size = 15
    end
  end
  object dsData: TDataSource
    DataSet = m_Currencyhistory
    Left = 400
    Top = 311
  end
  object grdPrinter: TdxComponentPrinter
    CurrentLink = grdPrinterLink1
    Version = 0
    Left = 672
    Top = 320
    object grdPrinterLink1: TdxGridReportLink
      Active = True
      Component = grCurrencyHistory
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.GrayShading = True
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 6350
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 6350
      PrinterPage.Margins.Top = 6350
      PrinterPage.PageFooter.Font.Charset = ANSI_CHARSET
      PrinterPage.PageFooter.Font.Color = clBlack
      PrinterPage.PageFooter.Font.Height = -7
      PrinterPage.PageFooter.Font.Name = 'Arial'
      PrinterPage.PageFooter.Font.Style = []
      PrinterPage.PageFooter.RightTitle.Strings = (
        '[Page # of Pages #]')
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage.ScaleMode = smFit
      PrinterPage._dxMeasurementUnits_ = 2
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 43129.563101446760000000
      ReportTitle.Font.Charset = DEFAULT_CHARSET
      ReportTitle.Font.Color = clBlack
      ReportTitle.Font.Height = -19
      ReportTitle.Font.Name = 'Arial'
      ReportTitle.Font.Style = [fsBold]
      ShrinkToPageWidth = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      OptionsFormatting.LookAndFeelKind = lfFlat
      OptionsFormatting.UseNativeStyles = True
      OptionsView.FilterBar = False
      BuiltInReportLink = True
    end
  end
end
