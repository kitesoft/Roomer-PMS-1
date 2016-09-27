inherited frmHouseKeepingReport: TfrmHouseKeepingReport
  Caption = 'Simple HouseKeeping report'
  ClientHeight = 586
  ClientWidth = 1123
  Font.Height = -11
  Position = poOwnerFormCenter
  ExplicitWidth = 1139
  ExplicitHeight = 625
  PixelsPerInch = 96
  TextHeight = 13
  inherited pnlTop: TsPanel
    Width = 1123
    Height = 129
    ExplicitWidth = 1123
    ExplicitHeight = 129
    inherited pnlActionButtons: TsPanel
      Width = 1121
      ExplicitWidth = 1121
      inherited btnExcel: TsButton
        Left = 856
        ExplicitLeft = 856
      end
      inherited btnReport: TsButton
        Left = 990
        ExplicitLeft = 990
      end
    end
    inherited pnlSelection: TsPanel
      Width = 1121
      Height = 84
      ExplicitWidth = 1121
      ExplicitHeight = 84
      object gbxSelection: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 221
        Height = 78
        Align = alLeft
        Caption = 'Select date and location'
        TabOrder = 0
        Checked = False
        object lblDate: TsLabel
          Left = 47
          Top = 23
          Width = 30
          Height = 13
          Alignment = taRightJustify
          Caption = 'Date: '
        end
        object lblLocation: TsLabel
          Left = 33
          Top = 50
          Width = 44
          Height = 13
          Alignment = taRightJustify
          Caption = 'Location:'
        end
        object dtDate: TsDateEdit
          Left = 91
          Top = 20
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
          CheckOnExit = True
          SkinData.SkinSection = 'EDIT'
          GlyphMode.Blend = 0
          GlyphMode.Grayed = False
          DefaultToday = True
          DialogTitle = 'Housekeeping date'
        end
        object cbxLocations: TsComboBox
          Left = 91
          Top = 47
          Width = 105
          Height = 21
          Alignment = taLeftJustify
          VerticalAlignment = taAlignTop
          Style = csDropDownList
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemIndex = -1
          ParentFont = False
          TabOrder = 1
        end
      end
    end
  end
  inherited grData: TcxGrid
    Top = 129
    Width = 1123
    Height = 437
    TabOrder = 2
    ExplicitTop = 129
    ExplicitWidth = 1123
    ExplicitHeight = 437
    inherited grDataDBTableView1: TcxGridDBTableView
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skCount
          Position = spFooter
        end
        item
          Kind = skSum
          Position = spFooter
        end
        item
          Format = '0'
          Kind = skCount
          Position = spFooter
          Column = grDataDBTableView1Room
        end
        item
          Format = '0'
          Column = grDataDBTableView1Room
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0'
          Kind = skCount
        end
        item
          Format = '0'
          Kind = skSum
        end
        item
          Format = '0'
          Kind = skCount
          Column = grDataDBTableView1Room
        end>
      object grDataDBTableView1Room: TcxGridDBColumn
        DataBinding.FieldName = 'room'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1roomtype: TcxGridDBColumn
        DataBinding.FieldName = 'roomtype'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1location: TcxGridDBColumn
        DataBinding.FieldName = 'location'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1floor: TcxGridDBColumn
        DataBinding.FieldName = 'floor'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1expectedcot: TcxGridDBColumn
        DataBinding.FieldName = 'expectedcot'
        PropertiesClassName = 'TcxTimeEditProperties'
        Properties.TimeFormat = tfHourMin
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1LastGuests: TcxGridDBColumn
        DataBinding.FieldName = 'LastGuests'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1expectedtoa: TcxGridDBColumn
        DataBinding.FieldName = 'expectedtoa'
        PropertiesClassName = 'TcxTimeEditProperties'
        Properties.TimeFormat = tfHourMin
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1ArrivingGuests: TcxGridDBColumn
        DataBinding.FieldName = 'ArrivingGuests'
        HeaderAlignmentHorz = taCenter
      end
      object grDataDBTableView1housekeepingstatus: TcxGridDBColumn
        DataBinding.FieldName = 'housekeepingstatus'
      end
      object grDataDBTableView1Roomnotes: TcxGridDBColumn
        DataBinding.FieldName = 'Roomnotes'
        PropertiesClassName = 'TcxMemoProperties'
      end
      object grDataDBTableView1maintenancenotes: TcxGridDBColumn
        DataBinding.FieldName = 'maintenancenotes'
        Visible = False
      end
      object grDataDBTableView1cleaningnotes: TcxGridDBColumn
        DataBinding.FieldName = 'cleaningnotes'
        Visible = False
      end
    end
  end
  inherited dxStatusBar: TdxStatusBar
    Top = 566
    Width = 1123
    ExplicitTop = 566
    ExplicitWidth = 1123
  end
  inherited kbmGridData: TkbmMemTable
    FieldDefs = <
      item
        Name = 'room'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'roomtype'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'floor'
        DataType = ftInteger
      end
      item
        Name = 'LastGuests'
        DataType = ftInteger
      end
      item
        Name = 'ArrivingGuests'
        DataType = ftInteger
      end
      item
        Name = 'expectedcot'
        DataType = ftTime
      end
      item
        Name = 'housekeepingstatus'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'location'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'expectedtoa'
        DataType = ftTime
      end
      item
        Name = 'Roomnotes'
        DataType = ftMemo
      end
      item
        Name = 'maintenancenotes'
        DataType = ftMemo
      end
      item
        Name = 'cleaningnotes'
        DataType = ftMemo
      end>
    object kbmGridDataroom: TStringField
      Alignment = taCenter
      DisplayLabel = 'Room'
      FieldName = 'room'
      Size = 10
    end
    object kbmGridDataroomtype: TStringField
      Alignment = taCenter
      DisplayLabel = 'Roomtype'
      DisplayWidth = 15
      FieldName = 'roomtype'
      Size = 10
    end
    object kbmGridDatafloor: TIntegerField
      Alignment = taCenter
      DisplayLabel = 'Floor'
      FieldName = 'floor'
    end
    object kbmGridDataLastGuests: TIntegerField
      DisplayLabel = 'Last Guests'
      FieldName = 'LastGuests'
      DisplayFormat = '0'
    end
    object kbmGridDataArrivingGuests: TIntegerField
      DisplayLabel = 'Arriving Guests'
      FieldName = 'ArrivingGuests'
      DisplayFormat = '0'
    end
    object kbmGridDataexpectedcot: TTimeField
      Alignment = taCenter
      DisplayLabel = 'Checkout Time'
      DisplayWidth = 10
      FieldName = 'expectedcot'
    end
    object kbmGridDatahousekeepingstatus: TStringField
      DisplayLabel = 'Status'
      DisplayWidth = 40
      FieldName = 'housekeepingstatus'
    end
    object kbmGridDatalocation: TStringField
      DisplayLabel = 'Location'
      FieldName = 'location'
      Size = 10
    end
    object kbmGridDataexpectedtoa: TTimeField
      Alignment = taCenter
      DisplayLabel = 'Arrival time'
      FieldName = 'expectedtoa'
    end
    object kbmGridDataRoomnotes: TMemoField
      DisplayWidth = 100
      FieldName = 'Roomnotes'
      BlobType = ftMemo
    end
    object kbmGridDatamaintenancenotes: TMemoField
      DisplayLabel = 'Maintenancenotes'
      FieldName = 'maintenancenotes'
      BlobType = ftMemo
    end
    object kbmGridDatacleaningnotes: TMemoField
      DisplayLabel = 'Cleaningnotes'
      FieldName = 'cleaningnotes'
      BlobType = ftMemo
    end
  end
  inherited gridPrinter: TdxComponentPrinter
    Left = 176
    inherited gridPrinterLink1: TdxGridReportLink
      ReportDocument.CreationDate = 42628.627292673610000000
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
