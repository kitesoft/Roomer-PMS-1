inherited frmTaxes: TfrmTaxes
  Caption = 'Taxes'
  ClientHeight = 521
  ClientWidth = 1112
  Constraints.MinWidth = 750
  ParentFont = False
  Position = poOwnerFormCenter
  OnCloseQuery = FormCloseQuery
  ExplicitWidth = 1128
  ExplicitHeight = 560
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 501
    Width = 1112
    ExplicitTop = 501
    ExplicitWidth = 1112
  end
  inherited pnlButtons: TsPanel
    Top = 458
    Width = 1112
    TabOrder = 0
    ExplicitTop = 458
    ExplicitWidth = 1112
    inherited btnOK: TsButton
      Left = 796
      ExplicitLeft = 796
    end
    inherited btnCancel: TsButton
      Left = 902
      ExplicitLeft = 902
    end
    inherited btnClose: TsButton
      Left = 1008
      ExplicitLeft = 1008
    end
  end
  inherited pnlTop: TsPanel
    Width = 1112
    Height = 95
    AutoSize = False
    TabOrder = 1
    ExplicitWidth = 1112
    ExplicitHeight = 95
    inherited pnlGridButons: TsPanel
      Width = 1112
      ExplicitWidth = 1112
    end
    inherited pnlFilter: TsPanel
      Width = 1112
      Height = 54
      ExplicitWidth = 1112
      ExplicitHeight = 54
    end
  end
  inherited pcClient: TsPageControl
    Top = 95
    Width = 1112
    Height = 363
    ExplicitTop = 95
    ExplicitWidth = 1112
    ExplicitHeight = 363
    inherited tsMain: TsTabSheet
      ExplicitLeft = 4
      ExplicitTop = 6
      ExplicitWidth = 1104
      ExplicitHeight = 353
      inherited grData: TcxGrid
        Width = 1104
        Height = 353
        ExplicitWidth = 1104
        ExplicitHeight = 353
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
            Width = 23
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvDataValid_From: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Valid_From'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.MinDate = 2.000000000000000000
            Properties.OnValidate = tvDataValid_FromPropertiesValidate
            MinWidth = 100
            Width = 102
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvDataValid_To: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Valid_To'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.MinDate = 2.000000000000000000
            Properties.OnValidate = tvDataValid_ToPropertiesValidate
            MinWidth = 100
            Width = 100
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object __tvDataProbe_Date: TcxGridDBBandedColumn
            Caption = 'Probe Date'
            DataBinding.FieldName = 'Probe_Date'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'INVOICEDATE'
              'STAYDATE')
            MinWidth = 80
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvDataDescription: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Description'
            MinWidth = 200
            Width = 224
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvDataAmount: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Amount'
            PropertiesClassName = 'TcxCalcEditProperties'
            OnGetProperties = tvDataAmountGetProperties
            MinWidth = 75
            Width = 75
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object tvDataTax_Type: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Tax_Type'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'FIXED_AMOUNT'
              'PERCENTAGE')
            Properties.MaxLength = 30
            MinWidth = 75
            Width = 103
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvDataTax_Base: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Tax_Base'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'ROOM_NIGHT'
              'GUEST_NIGHT')
            Properties.MaxLength = 30
            Properties.OnValidate = tvDataTax_BasePropertiesValidate
            MinWidth = 75
            Width = 97
            Position.BandIndex = 0
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object tvDataTime_Due: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Time_Due'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'PREPAID'
              'CHECKOUT')
            MinWidth = 75
            Width = 122
            Position.BandIndex = 0
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object tvDataReTaxable: TcxGridDBBandedColumn
            DataBinding.FieldName = 'ReTaxable'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'FALSE'
              'TRUE')
            MinWidth = 75
            Width = 122
            Position.BandIndex = 0
            Position.ColIndex = 11
            Position.RowIndex = 0
          end
          object tvDataTaxChildren: TcxGridDBBandedColumn
            DataBinding.FieldName = 'TaxChildren'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'FALSE'
              'TRUE')
            MinWidth = 75
            Width = 75
            Position.BandIndex = 0
            Position.ColIndex = 16
            Position.RowIndex = 0
          end
          object tvDataBooking_Item_Id: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Booking_Item_Id'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = tvDataBooking_Item_IdPropertiesButtonClick
            Visible = False
            Width = 122
            Position.BandIndex = 0
            Position.ColIndex = 12
            Position.RowIndex = 0
          end
          object tvDataHotel_Id: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Hotel_Id'
            Visible = False
            Width = 20
            Position.BandIndex = 0
            Position.ColIndex = 13
            Position.RowIndex = 0
          end
          object tvDataBooking_Item: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Booking_Item'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = tvDataBooking_Item_IdPropertiesButtonClick
            Properties.OnValidate = tvDataBooking_ItemPropertiesValidate
            MinWidth = 100
            Width = 100
            Position.BandIndex = 0
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object tvDataIncl_Excl: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Incl_Excl'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'EXCLUDED'
              'INCLUDED'
              'PER_CUSTOMER')
            Properties.OnValidate = tvDataIncl_ExclPropertiesValidate
            MinWidth = 75
            Width = 75
            Position.BandIndex = 0
            Position.ColIndex = 14
            Position.RowIndex = 0
          end
          object tvDataNetto_Amount_Based: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Netto_Amount_Based'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'FALSE'
              'TRUE')
            MinWidth = 130
            Width = 130
            Position.BandIndex = 0
            Position.ColIndex = 15
            Position.RowIndex = 0
          end
          object tvDataAfter_discount: TcxGridDBBandedColumn
            DataBinding.FieldName = 'After_discount'
            PropertiesClassName = 'TcxComboBoxProperties'
            Properties.DropDownListStyle = lsFixedList
            Properties.Items.Strings = (
              'FALSE'
              'TRUE')
            MinWidth = 100
            Width = 130
            Position.BandIndex = 0
            Position.ColIndex = 17
            Position.RowIndex = 0
          end
          object tvDataValue_Formula: TcxGridDBBandedColumn
            DataBinding.FieldName = 'Value_Formula'
            MinWidth = 75
            Width = 75
            Position.BandIndex = 0
            Position.ColIndex = 18
            Position.RowIndex = 0
          end
        end
      end
    end
  end
  inherited psRoomerBase: TcxPropertiesStore
    Left = 760
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 648
    Top = 16
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
    Left = 112
    Top = 200
  end
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43119.436669074070000000
      AssignedFormatValues = []
      BuiltInReportLink = True
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforeInsert = m_BeforeInsert
    BeforePost = m_BeforePost
    OnNewRecord = m_NewRecord
    Left = 104
    Top = 272
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_Description: TWideStringField
      FieldName = 'Description'
      Required = True
      Size = 64
    end
    object m_Amount: TFloatField
      FieldName = 'Amount'
    end
    object m_Tax_Type: TWideStringField
      FieldName = 'Tax_Type'
      Size = 30
    end
    object m_Tax_Base: TWideStringField
      FieldName = 'Tax_Base'
      Size = 30
    end
    object m_Time_Due: TWideStringField
      FieldName = 'Time_Due'
      Size = 30
    end
    object m_ReTaxable: TWideStringField
      FieldName = 'ReTaxable'
      Size = 10
    end
    object m_Booking_Item_Id: TIntegerField
      FieldName = 'Booking_Item_Id'
    end
    object m_Hotel_Id: TWideStringField
      FieldName = 'Hotel_Id'
      Size = 10
    end
    object m_Booking_Item: TWideStringField
      FieldName = 'Booking_Item'
      Size = 30
    end
    object m_Incl_Excl: TWideStringField
      FieldName = 'Incl_Excl'
      Size = 15
    end
    object m_Netto_Amount_Based: TWideStringField
      FieldName = 'Netto_Amount_Based'
      Size = 10
    end
    object m_Value_Formula: TWideStringField
      FieldName = 'Value_Formula'
      Size = 255
    end
    object m_Valid_From: TDateField
      FieldName = 'Valid_From'
    end
    object m_Valid_To: TDateField
      FieldName = 'Valid_To'
    end
    object m_TaxChildren: TWideStringField
      DisplayWidth = 10
      FieldName = 'TaxChildren'
      Size = 10
    end
    object m_After_discount: TWideStringField
      FieldName = 'After_discount'
      Size = 5
    end
    object m_Probe_Date: TWideStringField
      FieldName = 'Probe_Date'
    end
  end
end
