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
        ExplicitLeft = 300
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
  inherited gridPrinter: TdxComponentPrinter
    inherited gridPrinterLink1: TdxGridReportLink
      ReportDocument.CreationDate = 42636.442572986110000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      Styles.BandHeader = nil
      Styles.Caption = nil
      Styles.CardCaptionRow = nil
      Styles.CardRowCaption = nil
      Styles.Content = nil
      Styles.ContentEven = nil
      Styles.ContentOdd = nil
      Styles.FilterBar = nil
      Styles.Footer = nil
      Styles.Group = nil
      Styles.Header = nil
      Styles.Preview = nil
      Styles.Selection = nil
      BuiltInReportLink = True
    end
  end
  inherited cxGridStyleRepository: TcxStyleRepository
    PixelsPerInch = 96
    inherited dxGridReportLinkStyleSheet1: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
  end
end
