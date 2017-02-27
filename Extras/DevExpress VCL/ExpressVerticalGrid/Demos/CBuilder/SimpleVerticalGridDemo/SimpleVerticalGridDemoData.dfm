object SimpleVerticalGridDemoMainDM: TSimpleVerticalGridDemoMainDM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Left = 723
  Top = 297
  Height = 219
  Width = 226
  object dsCars: TDataSource
    DataSet = mdCars
    Left = 36
    Top = 24
  end
  object cxStyleRepository: TcxStyleRepository
    Left = 124
    Top = 24
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor]
      Color = 14590588
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13795663
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clYellow
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16247513
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clNavy
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14590588
      TextColor = clWhite
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 15120279
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor]
      Color = 16049100
    end
    object cxVerticalGridStyleSheetDevExpress: TcxVerticalGridStyleSheet
      Caption = 'DevExpress'
      Styles.Background = cxStyle1
      Styles.Content = cxStyle3
      Styles.Inactive = cxStyle5
      Styles.Selection = cxStyle7
      Styles.Category = cxStyle2
      Styles.Header = cxStyle4
      Styles.IncSearch = cxStyle6
      BuiltIn = True
    end
  end
  object mdCars: TdxMemData
    Indexes = <>
    Persistent.Data = {
      5665728FC2F5285C8FFE3F0F000000040000000C000300494400320000000100
      0A0054726164656D61726B0032000000010006004D6F64656C00020000000200
      030048500008000000060006004C6974657200020000000200040043796C0002
      000000020014005472616E736D6973735370656564436F756E74000300000001
      0013005472616E736D6973734175746F6D617469630002000000020009004D50
      475F43697479000200000002000C004D50475F48696768776179000700000001
      00090043617465676F727900000000000E000C004465736372697074696F6E00
      3200000001000A0048797065726C696E6B00000000000D000800506963747572
      65000800000006000600507269636500}
    SortOptions = []
    Left = 36
    Top = 96
    object mdCarsID: TAutoIncField
      FieldName = 'ID'
    end
    object mdCarsTrademark: TStringField
      FieldName = 'Trademark'
      Size = 50
    end
    object mdCarsModel: TStringField
      FieldName = 'Model'
      Size = 50
    end
    object mdCarsHP: TSmallintField
      FieldName = 'HP'
    end
    object mdCarsLiter: TFloatField
      FieldName = 'Liter'
    end
    object mdCarsCyl: TSmallintField
      FieldName = 'Cyl'
    end
    object mdCarsTransmissSpeedCount: TSmallintField
      FieldName = 'TransmissSpeedCount'
    end
    object mdCarsTransmissAutomatic: TStringField
      FieldName = 'TransmissAutomatic'
      Size = 3
    end
    object mdCarsMPG_City: TSmallintField
      FieldName = 'MPG_City'
    end
    object mdCarsMPG_Highway: TSmallintField
      FieldName = 'MPG_Highway'
    end
    object mdCarsCategory: TStringField
      FieldName = 'Category'
      Size = 7
    end
    object mdCarsDescription: TMemoField
      FieldName = 'Description'
      BlobType = ftMemo
    end
    object mdCarsHyperlink: TStringField
      FieldName = 'Hyperlink'
      Size = 50
    end
    object mdCarsPicture: TBlobField
      FieldName = 'Picture'
    end
    object mdCarsPrice: TFloatField
      FieldName = 'Price'
    end
  end
end
