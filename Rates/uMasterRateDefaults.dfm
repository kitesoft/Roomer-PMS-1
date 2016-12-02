object frmMasterRateDefaults: TfrmMasterRateDefaults
  Left = 0
  Top = 0
  Caption = 'MasterRateDefaults'
  ClientHeight = 495
  ClientWidth = 953
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pnlHolder: TsPanel
    Left = 0
    Top = 0
    Width = 953
    Height = 495
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    ExplicitWidth = 448
    object sPanel2: TsPanel
      Left = 0
      Top = 0
      Width = 953
      Height = 105
      Align = alTop
      TabOrder = 0
      SkinData.SkinSection = 'PANEL'
      ExplicitWidth = 448
      object lbStartFrom: TsLabel
        Left = 49
        Top = 48
        Width = 88
        Height = 13
        Caption = 'Channel Manager:'
      end
      object sLabel1: TsLabel
        Left = 49
        Top = 72
        Width = 50
        Height = 13
        Caption = 'Plan code:'
      end
      object btnDelete: TsButton
        Left = 205
        Top = 7
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
        Left = 301
        Top = 7
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
      object btnNew: TsButton
        Left = 13
        Top = 7
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
        Left = 109
        Top = 7
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
      object cbxChannelManager: TsComboBox
        Left = 141
        Top = 45
        Width = 145
        Height = 21
        Alignment = taLeftJustify
        VerticalAlignment = taAlignTop
        ItemIndex = -1
        TabOrder = 4
        OnCloseUp = cbxChannelManagerCloseUp
      end
      object cbxPlanCode: TsComboBox
        Left = 141
        Top = 70
        Width = 145
        Height = 21
        Alignment = taLeftJustify
        VerticalAlignment = taAlignTop
        ItemIndex = -1
        TabOrder = 5
        OnCloseUp = cbxPlanCodeCloseUp
      end
    end
    object sbMain: TsStatusBar
      Left = 0
      Top = 476
      Width = 953
      Height = 19
      Panels = <>
      SkinData.SkinSection = 'STATUSBAR'
      ExplicitWidth = 448
    end
    object panBtn: TsPanel
      Left = 0
      Top = 443
      Width = 953
      Height = 33
      Align = alBottom
      TabOrder = 2
      SkinData.SkinSection = 'PANEL'
      ExplicitWidth = 448
      DesignSize = (
        953
        33)
      object btnCancel: TsButton
        Left = 864
        Top = 4
        Width = 86
        Height = 25
        Hint = 'Cancel and close'
        Anchors = [akTop, akRight]
        Cancel = True
        Caption = 'Cancel'
        ImageIndex = 4
        Images = DImages.PngImageList1
        ModalResult = 2
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
        ExplicitLeft = 359
      end
      object BtnOk: TsButton
        Left = 772
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
        OnClick = BtnOkClick
        SkinData.SkinSection = 'BUTTON'
        ExplicitLeft = 267
      end
    end
    object sPanel1: TsPanel
      Left = 0
      Top = 105
      Width = 953
      Height = 338
      Align = alClient
      TabOrder = 3
      ExplicitLeft = 272
      ExplicitTop = 296
      ExplicitWidth = 185
      ExplicitHeight = 41
      object sSplitter1: TsSplitter
        Left = 251
        Top = 1
        Height = 336
        ExplicitLeft = 256
        ExplicitTop = 112
        ExplicitHeight = 100
      end
      object grData: TcxGrid
        Left = 257
        Top = 1
        Width = 695
        Height = 336
        Align = alClient
        TabOrder = 0
        LookAndFeel.NativeStyle = False
        ExplicitTop = 0
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
          object tvDataDay: TcxGridDBColumn
            DataBinding.FieldName = 'Day'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.ShowTime = False
            HeaderAlignmentHorz = taCenter
            SortIndex = 0
            SortOrder = soDescending
            Width = 108
          end
          object tvDataClosingTime: TcxGridDBColumn
            DataBinding.FieldName = 'ClosingTimestamp'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.Kind = ckDateTime
            HeaderAlignmentHorz = taCenter
            Width = 121
          end
        end
        object lvData: TcxGridLevel
          GridView = tvData
        end
      end
      object lvRateCodes: TsListView
        Left = 1
        Top = 1
        Width = 250
        Height = 336
        Align = alLeft
        Columns = <
          item
            Caption = 'Rate code'
          end
          item
            Caption = 'Description'
            Width = 200
          end>
        ReadOnly = True
        RowSelect = True
        TabOrder = 1
        ViewStyle = vsReport
        ExplicitTop = 6
      end
    end
  end
  object mnuOther: TPopupMenu
    Images = DImages.PngImageList1
    Left = 14
    Top = 120
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
  object FormStore: TcxPropertiesStore
    Components = <
      item
        Component = Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Position'
          'Top'
          'Width')
      end>
    StorageName = 'Software\Roomer\FormStatus\BookKeepingCodes'
    StorageType = stRegistry
    Left = 334
    Top = 208
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
    object m_day: TDateField
      FieldName = 'Day'
    end
    object m_ClosingTime: TDateTimeField
      FieldName = 'ClosingTimestamp'
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
