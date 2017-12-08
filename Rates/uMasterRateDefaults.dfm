inherited frmMasterRateDefaults: TfrmMasterRateDefaults
  Caption = 'MasterRateDefaults'
  ClientHeight = 495
  ClientWidth = 953
  Font.Height = -11
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  ExplicitWidth = 969
  ExplicitHeight = 534
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 475
    Width = 953
    ExplicitTop = 475
    ExplicitWidth = 953
  end
  object pnlHolder: TsPanel [1]
    Left = 0
    Top = 0
    Width = 953
    Height = 475
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object panBtn: TsPanel
      Left = 0
      Top = 442
      Width = 953
      Height = 33
      Align = alBottom
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      ExplicitTop = 423
      DesignSize = (
        953
        33)
      object BtnOk: TsButton
        Left = 859
        Top = 4
        Width = 86
        Height = 25
        Hint = 'Apply and close'
        Anchors = [akTop, akRight]
        Caption = 'OK'
        Default = True
        ImageIndex = 82
        Images = DImages.PngImageList1
        ModalResult = 1
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object sPanel1: TsPanel
      Left = 0
      Top = 0
      Width = 953
      Height = 442
      Align = alClient
      TabOrder = 1
      ExplicitHeight = 423
      object sSplitter1: TsSplitter
        Left = 267
        Top = 1
        Height = 440
        ExplicitLeft = 198
        ExplicitTop = -4
        ExplicitHeight = 336
      end
      object sPanel4: TsPanel
        Left = 1
        Top = 1
        Width = 266
        Height = 440
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 0
        ExplicitHeight = 421
        object lvRateCodes: TsListView
          Left = 0
          Top = 65
          Width = 266
          Height = 375
          HighlightHeaders = False
          Align = alClient
          Color = clWhite
          Columns = <
            item
              Caption = 'Rate code'
            end
            item
              Caption = 'Description'
              Width = 200
            end>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          HideSelection = False
          ReadOnly = True
          RowSelect = True
          ParentFont = False
          TabOrder = 0
          ViewStyle = vsReport
          OnChange = lvRateCodesChange
          ExplicitHeight = 356
        end
        object sPanel3: TsPanel
          Left = 0
          Top = 0
          Width = 266
          Height = 65
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 1
          object lbStartFrom: TsLabel
            Left = 21
            Top = 8
            Width = 88
            Height = 13
            Caption = 'Channel Manager:'
          end
          object sLabel1: TsLabel
            Left = 59
            Top = 33
            Width = 50
            Height = 13
            Caption = 'Plan code:'
          end
          object cbxChannelManager: TsComboBox
            Left = 115
            Top = 5
            Width = 145
            Height = 21
            Alignment = taLeftJustify
            VerticalAlignment = taAlignTop
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = -1
            ParentFont = False
            TabOrder = 0
            OnCloseUp = cbxChannelManagerCloseUp
          end
          object cbxPlanCode: TsComboBox
            Left = 115
            Top = 30
            Width = 145
            Height = 21
            Alignment = taLeftJustify
            VerticalAlignment = taAlignTop
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ItemIndex = -1
            ParentFont = False
            TabOrder = 1
            OnCloseUp = cbxPlanCodeCloseUp
          end
        end
      end
      object sPanel5: TsPanel
        Left = 273
        Top = 1
        Width = 679
        Height = 440
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        ExplicitHeight = 421
        object grData: TcxGrid
          Left = 0
          Top = 65
          Width = 679
          Height = 375
          Align = alClient
          TabOrder = 0
          LookAndFeel.NativeStyle = False
          ExplicitHeight = 356
          object tvData: TcxGridDBTableView
            Navigator.Buttons.CustomButtons = <>
            Navigator.Buttons.First.Visible = True
            Navigator.Buttons.PriorPage.Hint = 'Prior page'
            Navigator.Buttons.PriorPage.Visible = True
            Navigator.Buttons.Prior.Hint = 'Prior'
            Navigator.Buttons.Prior.Visible = True
            Navigator.Buttons.Next.Hint = 'Next'
            Navigator.Buttons.Next.Visible = True
            Navigator.Buttons.NextPage.Hint = 'Next page'
            Navigator.Buttons.NextPage.Visible = True
            Navigator.Buttons.Last.Hint = 'Last'
            Navigator.Buttons.Last.Visible = True
            Navigator.Buttons.Insert.Hint = 'Insert'
            Navigator.Buttons.Insert.Visible = True
            Navigator.Buttons.Append.Enabled = False
            Navigator.Buttons.Append.Hint = 'Append'
            Navigator.Buttons.Append.Visible = False
            Navigator.Buttons.Delete.Hint = 'Delete'
            Navigator.Buttons.Delete.Visible = True
            Navigator.Buttons.Edit.Enabled = False
            Navigator.Buttons.Edit.Hint = 'Edit'
            Navigator.Buttons.Edit.Visible = False
            Navigator.Buttons.Post.Hint = 'Post'
            Navigator.Buttons.Post.Visible = True
            Navigator.Buttons.Cancel.Hint = 'Cancel'
            Navigator.Buttons.Cancel.Visible = True
            Navigator.Buttons.Refresh.Enabled = False
            Navigator.Buttons.Refresh.Hint = 'Refresh'
            Navigator.Buttons.Refresh.Visible = False
            Navigator.Buttons.SaveBookmark.Enabled = False
            Navigator.Buttons.SaveBookmark.Hint = 'Save bookmark'
            Navigator.Buttons.SaveBookmark.Visible = False
            Navigator.Buttons.GotoBookmark.Enabled = False
            Navigator.Buttons.GotoBookmark.Hint = 'Goto bookmark'
            Navigator.Buttons.GotoBookmark.Visible = False
            Navigator.Buttons.Filter.Hint = 'Filter'
            Navigator.Buttons.Filter.Visible = True
            Navigator.InfoPanel.Visible = True
            Navigator.Visible = True
            DataController.DataSource = DS
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsBehavior.AlwaysShowEditor = True
            OptionsBehavior.FocusCellOnTab = True
            OptionsBehavior.IncSearch = True
            OptionsData.Appending = True
            OptionsData.CancelOnExit = False
            OptionsData.DeletingConfirmation = False
            OptionsView.GroupByBox = False
            OptionsView.Indicator = True
            object tvDataRecId: TcxGridDBColumn
              DataBinding.FieldName = 'RecId'
              Visible = False
            end
            object tvDatafromDate: TcxGridDBColumn
              Caption = 'From date'
              DataBinding.FieldName = 'fromDate'
              Width = 86
            end
            object tvDatastop: TcxGridDBColumn
              Caption = 'Stop sell'
              DataBinding.FieldName = 'stop'
              Width = 50
            end
            object tvDataprice: TcxGridDBColumn
              Caption = 'Price'
              DataBinding.FieldName = 'price'
              PropertiesClassName = 'TcxCurrencyEditProperties'
              OnGetProperties = tvDatapriceGetProperties
              Width = 70
            end
            object tvDatasingleUsePrice: TcxGridDBColumn
              Caption = 'Single use price'
              DataBinding.FieldName = 'singleUsePrice'
              PropertiesClassName = 'TcxCurrencyEditProperties'
              OnGetProperties = tvDatapriceGetProperties
              Width = 87
            end
            object tvDataavailability: TcxGridDBColumn
              Caption = 'Availability'
              DataBinding.FieldName = 'availability'
              Width = 59
            end
            object tvDataminStay: TcxGridDBColumn
              Caption = 'Min. stay'
              DataBinding.FieldName = 'minStay'
            end
            object tvDatamaxStay: TcxGridDBColumn
              Caption = 'Max. Stay'
              DataBinding.FieldName = 'maxStay'
            end
            object tvDataclosedOnArrival: TcxGridDBColumn
              Caption = 'CTA'
              DataBinding.FieldName = 'closedOnArrival'
            end
            object tvDataclosedOnDeparture: TcxGridDBColumn
              Caption = 'CTD'
              DataBinding.FieldName = 'closedOnDeparture'
            end
            object tvDatalengthOfStayArrivalDateBased: TcxGridDBColumn
              Caption = 'LOS arrival based'
              DataBinding.FieldName = 'lengthOfStayArrivalDateBased'
              Width = 94
            end
          end
          object lvData: TcxGridLevel
            GridView = tvData
          end
        end
        object sPanel6: TsPanel
          Left = 0
          Top = 0
          Width = 679
          Height = 65
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 1
          object btnNew: TsButton
            Left = 9
            Top = 9
            Width = 90
            Height = 26
            Hint = 'Add new record'
            Caption = 'New'
            ImageIndex = 23
            Images = DImages.PngImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = btnNewClick
            SkinData.SkinSection = 'BUTTON'
          end
          object btnEdit: TsButton
            Left = 105
            Top = 9
            Width = 90
            Height = 26
            Hint = 'Edit current record'
            Caption = 'Edit'
            ImageIndex = 25
            Images = DImages.PngImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = btnEditClick
            SkinData.SkinSection = 'BUTTON'
          end
          object btnDelete: TsButton
            Left = 201
            Top = 9
            Width = 90
            Height = 26
            Caption = 'Delete'
            ImageIndex = 24
            Images = DImages.PngImageList1
            TabOrder = 2
            OnClick = btnDeleteClick
            SkinData.SkinSection = 'BUTTON'
          end
          object btnOther: TsButton
            Left = 297
            Top = 9
            Width = 134
            Height = 26
            Caption = 'Other actions'
            ImageIndex = 76
            Images = DImages.PngImageList1
            Style = bsSplitButton
            TabOrder = 3
            Visible = False
            SkinData.SkinSection = 'BUTTON'
          end
        end
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
  end
  object mnuOther: TPopupMenu
    Images = DImages.PngImageList1
    Left = 14
    Top = 72
    object mnuiPrint: TMenuItem
      Caption = 'Print'
      ImageIndex = 3
      OnClick = mnuiPrintClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object Export1: TMenuItem
      Caption = 'Export'
      ImageIndex = 98
      object mnuiGridToExcel: TMenuItem
        Caption = 'Grid to Excel'
        ImageIndex = 132
        OnClick = mnuiGridToExcelClick
      end
      object mnuiGridToHtml: TMenuItem
        Caption = 'Grid to HTML'
        ImageIndex = 99
        OnClick = mnuiGridToHtmlClick
      end
      object mnuiGridToText: TMenuItem
        Caption = 'Grid to text'
        ImageIndex = 0
        OnClick = mnuiGridToTextClick
      end
      object mnuiGridToXml: TMenuItem
        Caption = 'Grid to XML'
        ImageIndex = 0
        OnClick = mnuiGridToXmlClick
      end
    end
  end
  object m_: TdxMemData
    Indexes = <>
    SortOptions = []
    BeforeInsert = m_BeforeInsert
    BeforePost = m_BeforePost
    BeforeDelete = m_BeforeDelete
    OnNewRecord = m_NewRecord
    Left = 208
    Top = 192
    object m_fromDate: TDateField
      FieldName = 'fromDate'
    end
    object m_price: TFloatField
      FieldName = 'price'
    end
    object m_availability: TIntegerField
      FieldName = 'availability'
    end
    object m_minStay: TIntegerField
      FieldName = 'minStay'
    end
    object m_maxStay: TIntegerField
      FieldName = 'maxStay'
    end
    object m_closedOnArrival: TBooleanField
      FieldName = 'closedOnArrival'
    end
    object m_closedOnDeparture: TBooleanField
      FieldName = 'closedOnDeparture'
    end
    object m_stop: TBooleanField
      FieldName = 'stop'
    end
    object m_lengthOfStayArrivalDateBased: TBooleanField
      FieldName = 'lengthOfStayArrivalDateBased'
    end
    object m_singleUsePrice: TFloatField
      FieldName = 'singleUsePrice'
    end
    object m_id: TIntegerField
      FieldName = 'id'
    end
  end
  object DS: TDataSource
    DataSet = m_
    Left = 152
    Top = 192
  end
  object grPrinter: TdxComponentPrinter
    CurrentLink = prLink_grData
    Version = 0
    Left = 96
    Top = 192
    object prLink_grData: TdxGridReportLink
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
      ReportDocument.CreationDate = 41334.495374884260000000
      BuiltInReportLink = True
    end
  end
end
