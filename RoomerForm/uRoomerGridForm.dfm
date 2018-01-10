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
  object grData: TcxGrid [1]
    Left = 0
    Top = 97
    Width = 704
    Height = 233
    Align = alClient
    TabOrder = 3
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
      OnCellDblClick = tvDataCellDblClick
      DataController.DataSource = dsData
      DataController.Filter.Options = [fcoCaseInsensitive]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.FocusCellOnTab = True
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
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 704
    Height = 97
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object pnlFilter: TsPanel
      Left = 0
      Top = 41
      Width = 704
      Height = 56
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      object btnClear: TsSpeedButton
        Left = 292
        Top = 6
        Width = 59
        Height = 21
        Caption = 'Clear'
        OnClick = btnClearClick
        SkinData.SkinSection = 'SPEEDBUTTON'
        Images = DImages.PngImageList1
        ImageIndex = 10
      end
      object cLabFilter: TsLabel
        Left = 63
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
      object chkActive: TsCheckBox
        Left = 100
        Top = 30
        Width = 101
        Height = 20
        Caption = 'Show active only'
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = chkActiveClick
        SkinData.SkinSection = 'CHECKBOX'
        ImgChecked = 0
        ImgUnchecked = 0
      end
      object edFilter: TsEdit
        Left = 100
        Top = 6
        Width = 186
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnChange = edFilterChange
        SkinData.SkinSection = 'EDIT'
      end
    end
    object pnlGridButons: TsPanel
      Left = 0
      Top = 0
      Width = 704
      Height = 41
      Align = alTop
      TabOrder = 1
      object btnDelete: TsButton
        AlignWithMargins = True
        Left = 196
        Top = 4
        Width = 90
        Height = 33
        Action = acDelete
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object btnOther: TsButton
        AlignWithMargins = True
        Left = 292
        Top = 4
        Width = 125
        Height = 33
        Hint = 'Other actions - Select from menu'
        Align = alLeft
        Caption = 'Other'
        DropDownMenu = pmnuOther
        ImageIndex = 76
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        Style = bsSplitButton
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInsert: TsButton
        AlignWithMargins = True
        Left = 4
        Top = 4
        Width = 90
        Height = 33
        Action = acNew
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnEdit: TsButton
        AlignWithMargins = True
        Left = 100
        Top = 4
        Width = 90
        Height = 33
        Action = acEdit
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        SkinData.SkinSection = 'BUTTON'
      end
    end
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
    OnStateChange = dsDataStateChange
    Left = 72
    Top = 152
  end
  object alGridActions: TActionList
    Images = DImages.PngImageList1
    OnUpdate = alGridActionsUpdate
    Left = 192
    Top = 184
    object acNew: TAction
      Category = 'Data'
      Caption = 'New'
      ImageIndex = 23
      OnExecute = acNewExecute
    end
    object acEdit: TAction
      Category = 'Data'
      Caption = 'Edit'
      ImageIndex = 25
      OnExecute = acEditExecute
    end
    object acDelete: TAction
      Category = 'Data'
      Caption = 'Delete'
      ImageIndex = 24
      OnExecute = acDeleteExecute
    end
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
      ReportDocument.CreationDate = 43110.555139097230000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
  object pmnuOther: TPopupMenu
    Left = 448
    Top = 8
    object Print1: TMenuItem
      Action = acPrint
    end
  end
end
