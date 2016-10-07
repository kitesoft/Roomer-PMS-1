inherited frmBaseRoomerGridForm: TfrmBaseRoomerGridForm
  Caption = 'Base Roomer Grid Form'
  ClientHeight = 581
  ClientWidth = 808
  ExplicitWidth = 824
  ExplicitHeight = 620
  PixelsPerInch = 96
  TextHeight = 11
  object pnlTop: TsPanel [0]
    Left = 0
    Top = 0
    Width = 808
    Height = 100
    Align = alTop
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object pnlActionButtons: TsPanel
      Left = 1
      Top = 1
      Width = 806
      Height = 43
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
    end
    object pnlSelection: TsPanel
      Left = 1
      Top = 44
      Width = 806
      Height = 55
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      SkinData.SkinSection = 'PANEL'
    end
  end
  object grData: TcxGrid [1]
    Left = 0
    Top = 100
    Width = 808
    Height = 461
    Align = alClient
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    ExplicitTop = 94
    object vwTableView: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = dsGridData
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoGroupsAlwaysExpanded]
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skCount
          Position = spFooter
        end
        item
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
      OptionsBehavior.FocusCellOnTab = True
      OptionsData.Deleting = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
      OptionsView.HeaderAutoHeight = True
      Styles.Group = cxsBoldStyle
      Styles.GroupSummary = cxsBoldStyle
      Styles.Header = cxsBoldStyle
      Styles.StyleSheet = cxssRoomerGridTableView
    end
    object lvGridDataLevel1: TcxGridLevel
      GridView = vwTableView
    end
  end
  inherited dxStatusBar: TdxStatusBar
    Top = 561
    Width = 808
    ExplicitTop = 561
    ExplicitWidth = 808
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = vwTableView
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    PixelsPerInch = 96
    inherited cxstReportSelection: TcxStyle
      AssignedValues = []
    end
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object kbmGridData: TkbmMemTable
    Active = True
    DesignActivation = True
    AttachedAutoRefresh = True
    AttachMaxCount = 1
    FieldDefs = <
      item
        Name = 'RoomerRoomReservationID'
        DataType = ftInteger
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
    AfterScroll = kbmGridDataAfterScroll
    Left = 176
    Top = 327
  end
  object dsGridData: TDataSource
    DataSet = kbmGridData
    Left = 176
    Top = 391
  end
  object gridPrinter: TdxComponentPrinter
    CurrentLink = gridPrinterLink
    Version = 0
    Left = 168
    Top = 448
    object gridPrinterLink: TdxGridReportLink
      Active = True
      Component = grData
      PageNumberFormat = pnfNumeral
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage.ScaleMode = smFit
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 42650.703204062500000000
      ReportTitle.Font.Charset = DEFAULT_CHARSET
      ReportTitle.Font.Color = clBlack
      ReportTitle.Font.Height = -19
      ReportTitle.Font.Name = 'Arial'
      ReportTitle.Font.Style = [fsBold]
      ShrinkToPageWidth = True
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      OptionsFormatting.LookAndFeelKind = lfFlat
      OptionsFormatting.UseNativeStyles = True
      OptionsSize.AutoWidth = True
      ScaleFonts = False
      StyleRepository = cxGridStyleRepository
      Styles.BandHeader = cxstReportBandHeader
      Styles.Caption = cxstReportCaption
      Styles.CardCaptionRow = cxstReportCardCaptionRow
      Styles.CardRowCaption = cxstReportCardRowCaption
      Styles.Content = cxstReportContent
      Styles.ContentEven = cxstReportContentEven
      Styles.ContentOdd = cxstReportContentOdd
      Styles.FilterBar = cxstReportFilterBar
      Styles.Footer = cxstReportFooter
      Styles.Group = cxstReportFooter
      Styles.Header = cxstReportHeader
      Styles.Preview = cxstReportPreview
      Styles.Selection = cxstReportSelection
      Styles.StyleSheet = dxGridReportLinkStyleSheet1
      BuiltInReportLink = True
    end
  end
  object cxGridStyleRepository: TcxStyleRepository
    Left = 176
    Top = 240
    PixelsPerInch = 96
    object cxsBoldStyle: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = 16053492
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnShadow
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object dxGridReportLinkStyleSheet1: TdxGridReportLinkStyleSheet
      Caption = 'Arial font'
      Styles.BandHeader = cxStyle2
      Styles.Caption = cxStyle3
      Styles.CardCaptionRow = cxStyle4
      Styles.CardRowCaption = cxStyle5
      Styles.Content = cxStyle6
      Styles.ContentEven = cxStyle7
      Styles.ContentOdd = cxStyle8
      Styles.FilterBar = cxStyle9
      Styles.Footer = cxStyle10
      Styles.Group = cxStyle11
      Styles.Header = cxStyle12
      Styles.Preview = cxStyle13
      Styles.Selection = cxStyle14
      BuiltIn = True
    end
  end
  object alGridActions: TActionList
    Images = DImages.PngImageList1
    Left = 472
    Top = 240
    object acPrint: TAction
      Caption = 'Print'
      Enabled = False
      Hint = 'Print the current contents of the grid'
      ImageIndex = 3
      ShortCut = 16464
      OnExecute = acPrintExecute
    end
    object acRefresh: TAction
      Caption = 'Refresh'
      ImageIndex = 11
      OnExecute = acRefreshExecute
    end
    object acExportExcel: TAction
      Category = 'Export'
      Caption = 'Export to Excel'
      Hint = 'Create an Excel sheet with the current contents of the grid'
      ImageIndex = 115
      OnExecute = acExportExcelExecute
      OnUpdate = acGridDependentActionUpdate
    end
    object acExportHTML: TAction
      Category = 'Export'
      Caption = 'Export to HTML'
      ImageIndex = 115
      OnUpdate = acGridDependentActionUpdate
    end
    object acExportText: TAction
      Category = 'Export'
      Caption = 'Export to Text'
      ImageIndex = 115
      OnUpdate = acGridDependentActionUpdate
    end
    object acExportXML: TAction
      Category = 'Export'
      Caption = 'Export to XML'
      ImageIndex = 115
      OnUpdate = acGridDependentActionUpdate
    end
  end
end
