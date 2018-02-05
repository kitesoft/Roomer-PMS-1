inherited frmBaseRoomerEditGridForm: TfrmBaseRoomerEditGridForm
  Caption = 'frmBaseRoomerEditGridForm'
  PixelsPerInch = 96
  TextHeight = 13
  inherited pnlTop: TsPanel
    object pnlGridButons: TsPanel
      Left = 0
      Top = 0
      Width = 704
      Height = 41
      Align = alTop
      TabOrder = 0
      object btnDelete: TsButton
        AlignWithMargins = True
        Left = 196
        Top = 4
        Width = 90
        Height = 33
        Action = acDelete
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
      object btnOther: TsButton
        AlignWithMargins = True
        Left = 292
        Top = 4
        Width = 125
        Height = 33
        Hint = 'Other actions - Select from menu'
        Align = alLeft
        Caption = 'Other'
        DropDownMenu = pmnuOther
        ImageIndex = 76
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        Style = bsSplitButton
        TabOrder = 1
        SkinData.SkinSection = 'BUTTON'
      end
      object btnInsert: TsButton
        AlignWithMargins = True
        Left = 4
        Top = 4
        Width = 90
        Height = 33
        Action = acNew
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        SkinData.SkinSection = 'BUTTON'
      end
      object btnEdit: TsButton
        AlignWithMargins = True
        Left = 100
        Top = 4
        Width = 90
        Height = 33
        Action = acEdit
        Align = alLeft
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        SkinData.SkinSection = 'BUTTON'
      end
    end
    object pnlFilter: TsPanel
      Left = 0
      Top = 41
      Width = 704
      Height = 56
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object btnClear: TsSpeedButton
        Left = 292
        Top = 6
        Width = 59
        Height = 21
        Caption = 'Clear'
        OnClick = btnClearClick
        SkinData.SkinSection = 'SPEEDBUTTON'
        Images = DImages.PngImageList1
        ImageIndex = 10
      end
      object cLabFilter: TsLabel
        Left = 63
        Top = 9
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
      object chkActive: TsCheckBox
        Left = 100
        Top = 30
        Width = 109
        Height = 17
        Caption = 'Show active only'
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = chkActiveClick
        SkinData.SkinSection = 'CHECKBOX'
        ImgChecked = 0
        ImgUnchecked = 0
      end
      object edFilter: TsEdit
        Left = 100
        Top = 6
        Width = 186
        Height = 21
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnChange = edFilterChange
        SkinData.SkinSection = 'EDIT'
      end
    end
  end
  inherited pnlClient: TsPanel
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
    OnStateChange = dsDataStateChange
  end
  inherited alGridActions: TActionList
    object acNew: TAction
      Category = 'Data'
      Caption = 'New'
      ImageIndex = 23
      OnExecute = acNewExecute
    end
    object acEdit: TAction
      Category = 'Data'
      Caption = 'Edit'
      ImageIndex = 25
      OnExecute = acEditExecute
    end
    object acDelete: TAction
      Category = 'Data'
      Caption = 'Delete'
      ImageIndex = 24
      OnExecute = acDeleteExecute
    end
  end
  inherited grPrinter: TdxComponentPrinter
    inherited prLink_grData: TdxGridReportLink
      ReportDocument.CreationDate = 43112.381352962960000000
      AssignedFormatValues = []
      BuiltInReportLink = True
    end
  end
  object pmnuOther: TPopupMenu
    Left = 448
    Top = 8
    object Print1: TMenuItem
      Action = acPrint
    end
  end
  object tmrFilterChanged: TTimer
    Enabled = False
    Interval = 500
    OnTimer = tmrFilterChangedTimer
    Left = 360
    Top = 48
  end
end
