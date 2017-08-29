inherited frmBaseRoomerGridForm: TfrmBaseRoomerGridForm
  BorderStyle = bsSizeable
  Caption = 'frmBaseRoomerGridForm'
  ClientHeight = 317
  ClientWidth = 645
  ExplicitHeight = 356
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 297
    Width = 645
    ExplicitTop = 307
  end
  object grData: TcxGrid [1]
    Left = 0
    Top = 65
    Width = 645
    Height = 189
    Align = alClient
    TabOrder = 3
    LookAndFeel.NativeStyle = False
    ExplicitWidth = 655
    ExplicitHeight = 199
    object tvData: TcxGridDBBandedTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = dsData
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.FocusCellOnTab = True
      OptionsView.ColumnAutoWidth = True
      Styles.StyleSheet = cxssRoomerGridBandedTableView
      Bands = <
        item
          Width = 108
        end>
    end
    object lvData: TcxGridLevel
      GridView = tvData
    end
  end
  object pnlTop: TsPanel [2]
    Left = 0
    Top = 0
    Width = 645
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitWidth = 655
  end
  inherited pnlButtons: TsPanel
    Top = 254
    Width = 645
    ExplicitTop = 264
    inherited btnOK: TsButton
      Left = 329
    end
    inherited btnCancel: TsButton
      Left = 435
    end
    inherited btnClose: TsButton
      Left = 541
    end
  end
  inherited cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 408
    Top = 8
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
    object cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet
      Caption = 'cxssRoomerBandedGridTableView'
      Styles.Content = cxstContent
      Styles.ContentEven = cxstContentEven
      Styles.ContentOdd = cxstContentOdd
      Styles.Selection = cxstSelection
      Styles.Footer = cxstFooter
      Styles.Group = cxstGroup
      Styles.GroupSummary = cxstGroup
      Styles.Header = cxstHeader
      Styles.Preview = cxstPreview
      BuiltIn = True
    end
  end
  object dsData: TDataSource
    Left = 72
    Top = 152
  end
end
