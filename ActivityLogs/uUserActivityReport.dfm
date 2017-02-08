inherited frmUserActivityReport: TfrmUserActivityReport
  Caption = 'User Activity Report'
  ClientHeight = 644
  ClientWidth = 1046
  OnShow = FormShow
  ExplicitWidth = 1062
  ExplicitHeight = 683
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 624
    Width = 1046
    ExplicitTop = 624
    ExplicitWidth = 1046
  end
  object pnlFilter: TsPanel [1]
    Left = 0
    Top = 0
    Width = 1046
    Height = 144
    Align = alTop
    TabOrder = 1
    SkinData.SkinSection = 'PANEL'
    object btnRefresh: TsButton
      Left = 914
      Top = 18
      Width = 118
      Height = 26
      Caption = 'Refresh'
      Default = True
      ImageIndex = 28
      Images = DImages.PngImageList1
      TabOrder = 1
      SkinData.SkinSection = 'BUTTON'
    end
    object gbxSelectDates: TsGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 277
      Height = 93
      Align = alLeft
      Caption = 'Select dates'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      SkinData.SkinSection = 'GROUPBOX'
      object lblFrom: TsLabel
        Left = 16
        Top = 19
        Width = 28
        Height = 13
        Caption = 'From:'
      end
      object lblTo: TsLabel
        Left = 16
        Top = 49
        Width = 28
        Height = 13
        Caption = 'From:'
      end
      object dtDateFrom: TsDateEdit
        Left = 66
        Top = 19
        Width = 105
        Height = 21
        AutoSize = False
        Color = clWhite
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 0
        Text = '  -  -    '
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
        DialogTitle = 'Date from select'
        Weekends = [dowLocaleDefault]
      end
      object dtDateTo: TsDateEdit
        Left = 66
        Top = 46
        Width = 105
        Height = 21
        AutoSize = False
        Color = clWhite
        EditMask = '!99/99/9999;1; '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 1
        Text = '  -  -    '
        SkinData.SkinSection = 'EDIT'
        GlyphMode.Blend = 0
        GlyphMode.Grayed = False
        DialogTitle = 'Date to select'
        Weekends = [dowLocaleDefault]
      end
      object tmFrom: TsTimePicker
        Left = 177
        Top = 19
        Width = 85
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '00:00:00'
        SkinData.SkinSection = 'EDIT'
      end
      object tmTo: TsTimePicker
        Left = 177
        Top = 46
        Width = 85
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '00:00:00'
        SkinData.SkinSection = 'EDIT'
      end
    end
    object pnlExportButtons: TsPanel
      Left = 1
      Top = 100
      Width = 1044
      Height = 43
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 128
        Height = 37
        Align = alLeft
        Caption = 'Excel'
        ImageIndex = 115
        Images = DImages.PngImageList1
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object btnProfile: TsButton
        AlignWithMargins = True
        Left = 137
        Top = 3
        Width = 128
        Height = 37
        Align = alLeft
        Caption = 'Profile'
        ImageIndex = 37
        Images = DImages.PngImageList1
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInvoice: TsButton
        AlignWithMargins = True
        Left = 271
        Top = 3
        Width = 128
        Height = 37
        Align = alLeft
        Caption = 'Invoice'
        ImageIndex = 62
        Images = DImages.PngImageList1
        Style = bsSplitButton
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnReport: TsButton
        AlignWithMargins = True
        Left = 913
        Top = 3
        Width = 128
        Height = 37
        Align = alRight
        Caption = 'Report'
        ImageIndex = 69
        Images = DImages.PngImageList1
        TabOrder = 3
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object gbxRestrictions: TsGroupBox
      AlignWithMargins = True
      Left = 287
      Top = 4
      Width = 277
      Height = 93
      Align = alLeft
      Caption = 'Restrictions'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      SkinData.SkinSection = 'GROUPBOX'
      object lblCategory: TsLabel
        Left = 16
        Top = 22
        Width = 49
        Height = 13
        Caption = 'Category:'
      end
      object lbAction: TsLabel
        Left = 16
        Top = 49
        Width = 34
        Height = 13
        Caption = 'Action:'
      end
      object cbxCategories: TsComboBox
        Left = 80
        Top = 19
        Width = 145
        Height = 21
        Alignment = taLeftJustify
        VerticalAlignment = taAlignTop
        Style = csDropDownList
        ItemIndex = -1
        TabOrder = 0
        OnChange = cbxCategoriesChange
      end
      object cbxActions: TsComboBox
        Left = 80
        Top = 46
        Width = 145
        Height = 21
        Alignment = taLeftJustify
        VerticalAlignment = taAlignTop
        Style = csDropDownList
        ItemIndex = -1
        TabOrder = 1
      end
    end
  end
  object grActivityLog: TcxGrid [2]
    Left = 0
    Top = 144
    Width = 1046
    Height = 480
    Align = alClient
    TabOrder = 2
    LookAndFeel.NativeStyle = False
    object grActivityLogDBTableView1: TcxGridDBTableView
      Navigator.Buttons.CustomButtons = <>
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
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupFooters = gfAlwaysVisible
    end
    object lvArrivalsListLevel1: TcxGridLevel
      GridView = grActivityLogDBTableView1
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 632
    Top = 72
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 528
    Top = 72
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
  object grdPrinter: TdxComponentPrinter
    CurrentLink = grdPrinterLink1
    Version = 0
    Left = 184
    Top = 432
    object grdPrinterLink1: TdxGridReportLink
      Active = True
      Component = grActivityLog
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.GrayShading = True
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 6350
      PrinterPage.Margins.Left = 5000
      PrinterPage.Margins.Right = 5000
      PrinterPage.Margins.Top = 12700
      PrinterPage.Orientation = poLandscape
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
      ReportDocument.CreationDate = 42774.603589004630000000
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
  object pmnuInvoiceMenu: TPopupMenu
    Images = DImages.cxSmallImagesFlat
    Left = 184
    Top = 304
    object R1: TMenuItem
      Caption = 'Room Invoice'
      Default = True
      ImageIndex = 62
    end
    object G1: TMenuItem
      Caption = 'Group Invoice'
      ImageIndex = 60
    end
  end
  object pnmuGridMenu: TPopupMenu
    Left = 184
    Top = 368
    object mnuCheckin: TMenuItem
      Caption = 'Check in'
    end
    object mnuProfile: TMenuItem
      Caption = 'Profile'
    end
    object mnuInvoice: TMenuItem
      Caption = 'Invoice'
      object mnuRoomInvoice: TMenuItem
        Caption = 'Room invoice'
      end
      object mnuGroupInvoice: TMenuItem
        Caption = 'Group invoice'
      end
    end
  end
end
