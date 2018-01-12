inherited frmVatCodesGrid: TfrmVatCodesGrid
  Caption = 'Vatcodes'
  ExplicitWidth = 320
  ExplicitHeight = 240
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
      object tvDataactive: TcxGridDBBandedColumn
        Caption = 'Active'
        DataBinding.FieldName = 'active'
        BestFitMaxWidth = 60
        MinWidth = 50
        Width = 50
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object tvDataVATCode: TcxGridDBBandedColumn
        DataBinding.FieldName = 'VATCode'
        PropertiesClassName = 'TcxTextEditProperties'
        Options.Editing = False
        Width = 78
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object tvDataDescription: TcxGridDBBandedColumn
        DataBinding.FieldName = 'Description'
        PropertiesClassName = 'TcxTextEditProperties'
        Width = 181
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object tvDataVATPercentage: TcxGridDBBandedColumn
        DataBinding.FieldName = 'VATPercentage'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.DisplayFormat = '0 %'
        Width = 115
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object tvDataBookKeepCode: TcxGridDBBandedColumn
        DataBinding.FieldName = 'BookKeepCode'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = tvDataBookKeepCodePropertiesButtonClick
        Width = 110
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object tvDatavalueFormula: TcxGridDBBandedColumn
        Caption = 'ValueFormula'
        DataBinding.FieldName = 'valueFormula'
        Width = 166
        Position.BandIndex = 0
        Position.ColIndex = 6
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
    Left = 64
    Top = 216
  end
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43108.629184525460000000
      BuiltInReportLink = True
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    Left = 64
    Top = 280
    object m_VATCode: TWideStringField
      FieldName = 'VATCode'
      Size = 10
    end
    object m_Description: TWideStringField
      FieldName = 'Description'
      Size = 30
    end
    object m_VATPercentage: TFloatField
      FieldName = 'VATPercentage'
    end
    object m_BookKeepCode: TWideStringField
      FieldName = 'BookKeepCode'
      Size = 25
    end
    object m_valueFormula: TWideStringField
      FieldName = 'valueFormula'
      Size = 255
    end
    object m_active: TBooleanField
      FieldName = 'active'
    end
  end
end
