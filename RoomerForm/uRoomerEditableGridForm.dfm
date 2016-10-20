inherited frmRoomerEditableGridForm: TfrmRoomerEditableGridForm
  Caption = 'Base Roomer Editable Grid Form'
  ClientHeight = 611
  ClientWidth = 827
  ExplicitWidth = 843
  ExplicitHeight = 650
  PixelsPerInch = 96
  TextHeight = 11
  inherited pnlTop: TsPanel
    Width = 827
    ExplicitWidth = 827
    inherited pnlActionButtons: TsPanel
      Width = 825
      ExplicitWidth = 825
    end
    inherited pnlSelection: TsPanel
      Top = 36
      Width = 825
      Height = 20
      ExplicitTop = 36
      ExplicitWidth = 825
      ExplicitHeight = 20
    end
    object pnlEditButtons: TsPanel
      Left = 1
      Top = 1
      Width = 825
      Height = 35
      Align = alTop
      TabOrder = 2
      object btnOther: TsButton
        AlignWithMargins = True
        Left = 677
        Top = 4
        Width = 144
        Height = 27
        Hint = 'Other actions - Select from menu'
        Align = alRight
        Caption = 'Other actions'
        DropDownMenu = mnuOther
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 76
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        Style = bsSplitButton
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object btnDelete: TsButton
        AlignWithMargins = True
        Left = 196
        Top = 4
        Width = 90
        Height = 27
        Action = acDelete
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
      object btnEdit: TsButton
        AlignWithMargins = True
        Left = 100
        Top = 4
        Width = 90
        Height = 27
        Action = acEdit
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInsert: TsButton
        AlignWithMargins = True
        Left = 4
        Top = 4
        Width = 90
        Height = 27
        Action = acNew
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        SkinData.SkinSection = 'BUTTON'
      end
      object btnrefresh: TsButton
        AlignWithMargins = True
        Left = 388
        Top = 4
        Width = 90
        Height = 27
        Action = acRefresh
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        SkinData.SkinSection = 'BUTTON'
        ExplicitLeft = 292
        ExplicitTop = 2
      end
      object btnPost: TsButton
        AlignWithMargins = True
        Left = 292
        Top = 4
        Width = 90
        Height = 27
        Action = acPost
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = DImages.PngImageList1
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        SkinData.SkinSection = 'BUTTON'
        ExplicitTop = 2
      end
    end
  end
  inherited grData: TcxGrid
    Width = 827
    Height = 491
    ExplicitWidth = 827
    ExplicitHeight = 491
    inherited vwTableView: TcxGridDBTableView
      OnCellDblClick = vwTableViewCellDblClick
      OptionsData.Appending = True
      OptionsData.Deleting = True
      OptionsData.Editing = True
      OptionsData.Inserting = True
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
  inherited dxStatusBar: TdxStatusBar
    Top = 591
    Width = 827
    ExplicitTop = 591
    ExplicitWidth = 827
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
  inherited alRoomerForm: TActionList
    Left = 672
    Top = 48
    object acNew: TAction
      Category = 'GridEdit'
      Caption = 'New'
      ImageIndex = 23
      OnExecute = acNewExecute
      OnUpdate = acNewUpdate
    end
    object acEdit: TAction
      Category = 'GridEdit'
      Caption = 'Edit'
      ImageIndex = 25
      OnExecute = acEditExecute
      OnUpdate = acEditUpdate
    end
    object acDelete: TAction
      Category = 'GridEdit'
      Caption = 'Delete'
      ImageIndex = 24
      OnExecute = acDeleteExecute
      OnUpdate = acDeleteUpdate
    end
    object acPost: TAction
      Category = 'GridEdit'
      Caption = 'Post'
      ImageIndex = 2
      OnExecute = acPostExecute
      OnUpdate = acPostUpdate
    end
    object acCancel: TAction
      Category = 'GridEdit'
      Caption = 'Cancel'
      ImageIndex = 4
      OnExecute = acCancelExecute
      OnUpdate = acCancelUpdate
    end
  end
  inherited kbmGridData: TkbmMemTable
    BeforePost = kbmGridDataBeforePost
  end
  inherited gridPrinter: TdxComponentPrinter
    inherited gridPrinterLink: TdxGridReportLink
      ReportDocument.CreationDate = 42650.926843981480000000
      AssignedFormatValues = []
      BuiltInReportLink = True
    end
  end
  object mnuOther: TPopupMenu
    Left = 672
    Top = 192
    object mnuiPrint: TMenuItem
      Action = acPrint
    end
    object mnuiAllowGridEdit: TMenuItem
      Caption = 'Allow grid edit'
      Checked = True
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object mnuExport: TMenuItem
      Caption = 'Export'
      object mnuiGridToExcel: TMenuItem
        Action = acExportExcel
      end
      object mnuiGridToHtml: TMenuItem
        Action = acExportHTML
      end
      object mnuiGridToText: TMenuItem
        Action = acExportText
      end
      object mnuiGridToXml: TMenuItem
        Action = acExportXML
      end
    end
  end
end
