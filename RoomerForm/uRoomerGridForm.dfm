inherited frmBaseRoomerGridForm: TfrmBaseRoomerGridForm
  BorderStyle = bsSizeable
  Caption = 'frmBaseRoomerGridForm'
  ClientHeight = 393
  ClientWidth = 704
  ExplicitWidth = 720
  ExplicitHeight = 432
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 373
    Width = 704
    ExplicitTop = 373
    ExplicitWidth = 704
  end
  inherited pnlButtons: TsPanel
    Top = 330
    Width = 704
    ExplicitTop = 330
    ExplicitWidth = 704
    inherited btnOK: TsButton
      Left = 388
      ExplicitLeft = 388
    end
    inherited btnCancel: TsButton
      Left = 494
      ExplicitLeft = 494
    end
    inherited btnClose: TsButton
      Left = 600
      ExplicitLeft = 600
    end
  end
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 704
    Height = 97
    Align = alTop
    AutoSize = True
    BevelOuter = bvNone
    TabOrder = 2
  end
  object pcClient: TsPageControl [3]
    Left = 0
    Top = 97
    Width = 704
    Height = 233
    ActivePage = tsMain
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Style = tsButtons
    TabHeight = 35
    TabOrder = 3
    TabPadding = 5
    SkinData.CustomFont = True
    object tsMain: TsTabSheet
      Caption = 'tsMain'
      TabVisible = False
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object grData: TcxGrid
        Left = 0
        Top = 0
        Width = 696
        Height = 223
        Align = alClient
        TabOrder = 0
        LookAndFeel.NativeStyle = False
        object tvData: TcxGridDBBandedTableView
          Navigator.Buttons.CustomButtons = <>
          Navigator.Buttons.PriorPage.Visible = False
          Navigator.Buttons.NextPage.Visible = False
          Navigator.Buttons.Refresh.Visible = False
          Navigator.Buttons.SaveBookmark.Visible = False
          Navigator.Buttons.GotoBookmark.Visible = False
          Navigator.Buttons.Filter.Visible = False
          Navigator.Visible = True
          FilterBox.Visible = fvNever
          OnCellDblClick = tvDataCellDblClick
          DataController.DataSource = dsData
          DataController.Filter.Options = [fcoCaseInsensitive]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.FocusCellOnTab = True
          OptionsData.Deleting = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.StyleSheet = cxssRoomerGridBandedTableView
          Bands = <
            item
              Width = 108
            end>
        end
        object lvData: TcxGridLevel
          GridView = tvData
        end
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 416
    Top = 192
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 320
    Top = 176
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
    object cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      Caption = 'cxssRoomerBandedGridTableView'
      Styles.Content = cxstContent
      Styles.ContentEven = cxstContentEven
      Styles.ContentOdd = cxstContentOdd
      Styles.Selection = cxstSelection
      Styles.Footer = cxstFooter
      Styles.Group = cxstGroup
      Styles.GroupSummary = cxstGroup
      Styles.Header = cxstHeader
      Styles.Preview = cxstPreview
      BuiltIn = True
    end
  end
  object dsData: TDataSource
    Left = 72
    Top = 152
  end
  object alGridActions: TActionList
    Images = DImages.PngImageList1
    OnUpdate = alGridActionsUpdate
    Left = 192
    Top = 184
    object acPrint: TAction
      Category = 'Other'
      Caption = 'Print'
      OnExecute = acPrintExecute
    end
    object acAllowGridEdit: TAction
      Category = 'Other'
      Caption = 'Allow grid edit'
      Checked = True
    end
  end
  object grPrinter: TdxComponentPrinter
    CurrentLink = prLink_grData
    Version = 0
    Left = 488
    Top = 184
    object prLink_grData: TdxGridReportLink
      Active = True
      Component = grData
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
      ReportDocument.CreationDate = 43185.525277835650000000
      BuiltInReportLink = True
    end
  end
end
