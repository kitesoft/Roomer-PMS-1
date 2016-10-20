inherited frmCountryGroupsGrid: TfrmCountryGroupsGrid
  PixelsPerInch = 96
  TextHeight = 11
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
  inherited kbmGridData: TkbmMemTable
    object kbmGridDataad: TIntegerField
      FieldName = 'ad'
    end
  end
  inherited gridPrinter: TdxComponentPrinter
    inherited gridPrinterLink: TdxGridReportLink
      ReportDocument.CreationDate = 42662.630291342590000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
end
