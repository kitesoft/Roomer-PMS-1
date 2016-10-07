inherited frmRoomerReportGridForm: TfrmRoomerReportGridForm
  Caption = 'Base Roomer ReportGrid form'
  PixelsPerInch = 96
  TextHeight = 11
  inherited pnlTop: TsPanel
    inherited pnlActionButtons: TsPanel
      object btnRefresh: TsButton
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 128
        Height = 37
        Action = acRefresh
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object btnExcel: TsButton
        AlignWithMargins = True
        Left = 541
        Top = 3
        Width = 128
        Height = 37
        Action = acExportExcel
        Align = alRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
      object btnReport: TsButton
        AlignWithMargins = True
        Left = 675
        Top = 3
        Width = 128
        Height = 37
        Action = acPrint
        Align = alRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
    end
  end
  inherited grData: TcxGrid
    inherited vwTableView: TcxGridDBTableView
      Styles.Content = nil
      Styles.ContentEven = nil
      Styles.ContentOdd = nil
      Styles.Selection = nil
      Styles.Footer = nil
      Styles.Group = nil
      Styles.GroupSummary = nil
      Styles.Header = nil
      Styles.Preview = nil
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
  inherited gridPrinter: TdxComponentPrinter
    inherited gridPrinterLink: TdxGridReportLink
      ReportDocument.CreationDate = 42650.922173229170000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
end
