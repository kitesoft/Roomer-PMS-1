inherited frmStaffComm: TfrmStaffComm
  Caption = 'Notes of day'
  ClientHeight = 663
  ClientWidth = 648
  Constraints.MinWidth = 450
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 664
  ExplicitHeight = 702
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 643
    Width = 648
    ExplicitTop = 643
    ExplicitWidth = 648
  end
  inherited pnlButtons: TsPanel
    Top = 600
    Width = 648
    ExplicitTop = 600
    ExplicitWidth = 648
    inherited btnOK: TsButton
      Left = 332
      ExplicitLeft = 332
    end
    inherited btnCancel: TsButton
      Left = 438
      ExplicitLeft = 438
    end
    inherited btnClose: TsButton
      Left = 544
      ExplicitLeft = 544
    end
  end
  inherited pnlTop: TsPanel
    Width = 648
    Height = 83
    ExplicitWidth = 648
    ExplicitHeight = 83
    object cLabFilter: TsLabel
      Left = 19
      Top = 34
      Width = 31
      Height = 13
      Alignment = taRightJustify
      Caption = 'Filter :'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object btnClear: TsSpeedButton
      Left = 273
      Top = 31
      Width = 63
      Height = 21
      Caption = 'Clear'
      OnClick = btnClearClick
      SkinData.SkinSection = 'SPEEDBUTTON'
      Images = DImages.PngImageList1
      ImageIndex = 4
    end
    object btnDelete: TsButton
      Left = 199
      Top = 0
      Width = 90
      Height = 25
      Caption = 'Delete'
      ImageIndex = 24
      Images = DImages.PngImageList1
      TabOrder = 2
      OnClick = btnDeleteClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnOther: TsButton
      Left = 295
      Top = 0
      Width = 135
      Height = 25
      Caption = 'Other actions'
      DropDownMenu = mnuOther
      ImageIndex = 76
      Images = DImages.PngImageList1
      Style = bsSplitButton
      TabOrder = 3
      SkinData.SkinSection = 'BUTTON'
    end
    object edFilter: TsEdit
      Left = 56
      Top = 31
      Width = 215
      Height = 21
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnChange = edFilterChange
      SkinData.SkinSection = 'EDIT'
    end
    object btnInsert: TsButton
      Left = 6
      Top = 0
      Width = 90
      Height = 25
      Hint = 'Add new record'
      Caption = 'New'
      ImageIndex = 23
      Images = DImages.PngImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = btnInsertClick
      SkinData.SkinSection = 'BUTTON'
    end
    object btnEdit: TsButton
      Left = 102
      Top = 0
      Width = 91
      Height = 25
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
    object dtDate: TsDateEdit
      Left = 82
      Top = 62
      Width = 96
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
      TabOrder = 6
      Text = '  -  -    '
      OnChange = dtDateChange
      SkinData.SkinSection = 'EDIT'
      GlyphMode.Blend = 0
      GlyphMode.Grayed = False
      Weekends = [dowSaturday, dowSunday]
    end
    object btNextDay: TsBitBtn
      Left = 179
      Top = 62
      Width = 25
      Height = 21
      TabOrder = 7
      OnClick = btNextDayClick
      ImageIndex = 3
      Images = DImages.ilGuests
    end
    object btnPeviousDay: TsBitBtn
      Left = 55
      Top = 62
      Width = 25
      Height = 21
      TabOrder = 5
      OnClick = btnPeviousDayClick
      ImageIndex = 2
      Images = DImages.ilGuests
    end
    object chkShowAllNotes: TsCheckBox
      Left = 273
      Top = 63
      Width = 161
      Height = 20
      Caption = 'Show all notes as of this date'
      TabOrder = 8
      OnClick = dtDateChange
      ImgChecked = 0
      ImgUnchecked = 0
    end
  end
  inherited pcClient: TsPageControl
    Top = 83
    Width = 648
    Height = 517
    ExplicitTop = 83
    ExplicitWidth = 648
    ExplicitHeight = 517
    inherited tsMain: TsTabSheet
      inherited grData: TcxGrid
        Width = 640
        Height = 507
        ExplicitWidth = 640
        ExplicitHeight = 507
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
          object tvDatadate: TcxGridDBBandedColumn
            Caption = 'Action Date'
            DataBinding.FieldName = 'date'
            Width = 77
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object tvDatanotes: TcxGridDBBandedColumn
            Caption = 'Notes'
            DataBinding.FieldName = 'notes'
            PropertiesClassName = 'TcxMemoProperties'
            Width = 280
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object tvDataaction: TcxGridDBBandedColumn
            Caption = 'Action'
            DataBinding.FieldName = 'action'
            OnGetDisplayText = tvData2actionGetDisplayText
            Width = 108
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object tvDatalastChangedBy: TcxGridDBBandedColumn
            Caption = 'Last changed by'
            DataBinding.FieldName = 'lastChangedBy'
            Width = 103
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object tvDatalastUpdate: TcxGridDBBandedColumn
            Caption = 'Last Update'
            DataBinding.FieldName = 'lastUpdate'
            Width = 78
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object tvDataRecId: TcxGridDBBandedColumn
            DataBinding.FieldName = 'RecId'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object tvDataID: TcxGridDBBandedColumn
            DataBinding.FieldName = 'ID'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object tvDatauser: TcxGridDBBandedColumn
            DataBinding.FieldName = 'user'
            Visible = False
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
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
    inherited cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      BuiltIn = True
    end
  end
  inherited dsData: TDataSource
    DataSet = m_
  end
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43131.436258391200000000
      AssignedFormatValues = [fvDate, fvTime, fvPageNumber]
      BuiltInReportLink = True
    end
  end
  object mnuOther: TPopupMenu
    Images = DImages.PngImageList1
    Left = 14
    Top = 200
    object mnuiPrint: TMenuItem
      Caption = 'Print'
      ImageIndex = 3
      OnClick = mnuiPrintClick
    end
    object mnuiAllowGridEdit: TMenuItem
      Caption = 'Allow grid edit'
      OnClick = mnuiAllowGridEditClick
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
    BeforePost = m_BeforePost
    BeforeDelete = m_BeforeDelete
    OnNewRecord = m_NewRecord
    Left = 256
    Top = 200
    object m_ID: TIntegerField
      FieldName = 'ID'
    end
    object m_date: TDateField
      FieldName = 'date'
    end
    object m_lastUpdate: TDateTimeField
      FieldName = 'lastUpdate'
    end
    object m_notes: TWideMemoField
      FieldName = 'notes'
      BlobType = ftWideMemo
    end
    object m_action: TWideStringField
      FieldName = 'action'
      Size = 25
    end
    object m_user: TWideStringField
      FieldName = 'user'
      Size = 30
    end
    object m_lastChangedBy: TWideStringField
      FieldName = 'lastChangedBy'
      Size = 30
    end
  end
end
