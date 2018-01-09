inherited frmPriceCodesGrid: TfrmPriceCodesGrid
  Caption = 'Rate codes'
  PixelsPerInch = 96
  TextHeight = 13
  inherited grData: TcxGrid
    inherited tvData: TcxGridDBBandedTableView
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
      object tvDataID: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ID'
        Visible = False
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvDatapcCode: TcxGridDBBandedColumn
        Caption = 'Price Code'
        DataBinding.FieldName = 'pcCode'
        Width = 144
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvDataActive: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Active'
        Width = 51
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvDatapcDescription: TcxGridDBBandedColumn
        Caption = 'Description'
        DataBinding.FieldName = 'pcDescription'
        Width = 433
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvDatapcRack: TcxGridDBBandedColumn
        Caption = 'Is Rack'
        DataBinding.FieldName = 'pcRack'
        Width = 74
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
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
    inherited cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      BuiltIn = True
    end
  end
  inherited dsData: TDataSource
    DataSet = m_
  end
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43109.601824074070000000
      AssignedFormatValues = []
      BuiltInReportLink = True
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 64
    Top = 208
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_pcCode: TWideStringField
      FieldName = 'pcCode'
      Size = 10
    end
    object m_Active: TBooleanField
      FieldName = 'Active'
    end
    object m_pcDescription: TWideStringField
      FieldName = 'pcDescription'
      Size = 50
    end
    object m_pcRack: TBooleanField
      FieldName = 'pcRack'
    end
    object m_pcRackCalc: TFloatField
      FieldName = 'pcRackCalc'
    end
    object m_pcShowDiscount: TBooleanField
      FieldName = 'pcShowDiscount'
    end
    object m_pcDiscountText: TWideStringField
      FieldName = 'pcDiscountText'
      Size = 50
    end
    object m_pcAutomatic: TBooleanField
      FieldName = 'pcAutomatic'
    end
    object m_pcLastUpdate: TDateTimeField
      FieldName = 'pcLastUpdate'
    end
    object m_pcDiscountMethod: TIntegerField
      FieldName = 'pcDiscountMethod'
    end
    object m_pcDiscountPriceAfter: TFloatField
      FieldName = 'pcDiscountPriceAfter'
    end
    object m_pcDiscountDaysAfter: TIntegerField
      FieldName = 'pcDiscountDaysAfter'
    end
  end
end
