inherited frmRoomerEditableGridForm: TfrmRoomerEditableGridForm
  Caption = 'Base Roomer Editable Grid Form'
  ClientHeight = 611
  ClientWidth = 827
  ExplicitWidth = 843
  ExplicitHeight = 650
  PixelsPerInch = 96
  TextHeight = 11
  inherited pnlTop: TsPanel
    Top = 97
    Width = 827
    ExplicitTop = 97
    ExplicitWidth = 827
    inherited pnlActionButtons: TsPanel
      Width = 825
      ExplicitWidth = 825
      object btnOther: TsButton
        AlignWithMargins = True
        Left = 678
        Top = 3
        Width = 144
        Height = 37
        Hint = 'Other actions - Select from menu'
        Margins.Left = 6
        Align = alRight
        Caption = 'Other actions'
        ImageIndex = 76
        Images = DImages.PngImageList1
        ParentShowHint = False
        ShowHint = True
        Style = bsSplitButton
        TabOrder = 0
        SkinData.SkinSection = 'BUTTON'
      end
    end
    inherited pnlSelection: TsPanel
      Width = 825
      ExplicitWidth = 825
    end
  end
  inherited grData: TcxGrid
    Top = 197
    Width = 827
    Height = 394
    ExplicitTop = 197
    ExplicitWidth = 827
    ExplicitHeight = 394
  end
  inherited dxStatusBar: TdxStatusBar
    Top = 591
    Width = 827
    ExplicitTop = 591
    ExplicitWidth = 827
  end
  object dxRibbon: TdxRibbon [3]
    Left = 0
    Top = 0
    Width = 827
    Height = 97
    BarManager = dxBarManager
    Style = rs2013
    ColorSchemeName = 'White'
    QuickAccessToolbar.Visible = False
    ShowTabHeaders = False
    Contexts = <>
    TabOrder = 7
    TabStop = False
    object dxRibbonTab1: TdxRibbonTab
      Active = True
      Caption = 'dxRibbonTab1'
      Groups = <
        item
          ToolbarName = 'dxBarPostCancel'
        end>
      Index = 0
    end
  end
  inherited gridPrinter: TdxComponentPrinter
    inherited gridPrinterLink1: TdxGridReportLink
      ReportDocument.CreationDate = 42636.425004895830000000
      AssignedFormatValues = []
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
  inherited alGridActions: TActionList
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
    end
  end
  object dxBarManager: TdxBarManager
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Categories.Strings = (
      'Default')
    Categories.ItemsVisibles = (
      2)
    Categories.Visibles = (
      True)
    ImageOptions.LargeImages = DImages.cxLargeImagesFlat
    PopupMenuLinks = <>
    UseSystemFont = True
    Left = 656
    Top = 16
    DockControlHeights = (
      0
      0
      0
      0)
    object dxBarPostCancel: TdxBar
      CaptionButtons = <>
      DockedLeft = 0
      DockedTop = 0
      FloatLeft = 398
      FloatTop = 153
      FloatClientWidth = 51
      FloatClientHeight = 42
      ItemLinks = <
        item
          Visible = True
          ItemName = 'btnPostRibbon'
        end
        item
          Visible = True
          ItemName = 'bntCancelRibbon'
        end
        item
          BeginGroup = True
          Visible = True
          ItemName = 'dxBarLargeButton4'
        end
        item
          Visible = True
          ItemName = 'dxBarLargeButton1'
        end
        item
          Visible = True
          ItemName = 'dxBarLargeButton5'
        end
        item
          Visible = True
          ItemName = 'dxBarLargeButton6'
        end>
      OneOnRow = True
      Row = 0
      UseOwnFont = False
      Visible = True
      WholeRow = False
    end
    object btnPostRibbon: TdxBarLargeButton
      Action = acPost
      Category = 0
    end
    object bntCancelRibbon: TdxBarLargeButton
      Action = acCancel
      Category = 0
    end
    object dxBarLargeButton1: TdxBarLargeButton
      Action = acEdit
      Category = 0
    end
    object dxBarLargeButton2: TdxBarLargeButton
      Action = acNew
      Category = 0
    end
    object dxBarLargeButton3: TdxBarLargeButton
      Action = acDelete
      Category = 0
    end
    object dxBarLargeButton4: TdxBarLargeButton
      Action = acNew
      Category = 0
    end
    object dxBarLargeButton5: TdxBarLargeButton
      Action = acDelete
      Category = 0
    end
    object dxBarLargeButton6: TdxBarLargeButton
      Caption = 'Other Actions'
      Category = 0
      Hint = 'Other Actions'
      Visible = ivAlways
      ButtonStyle = bsDropDown
      LargeImageIndex = 76
      SyncImageIndex = False
      ImageIndex = 76
    end
  end
  object mnuOther: TPopupMenu
    Left = 320
    Top = 328
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
    object Export1: TMenuItem
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