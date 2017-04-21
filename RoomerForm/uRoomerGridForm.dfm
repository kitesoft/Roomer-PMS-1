inherited frmBaseRoomerGridForm: TfrmBaseRoomerGridForm
  Caption = 'frmBaseRoomerGridForm'
  ClientHeight = 327
  ExplicitHeight = 366
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 307
    ExplicitTop = 307
    ExplicitWidth = 663
  end
  object grData: TcxGrid [1]
    Left = 0
    Top = 65
    Width = 663
    Height = 242
    Align = alClient
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    object tvData: TcxGridDBBandedTableView
      Navigator.Buttons.CustomButtons = <>
      DataController.DataSource = dsData
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
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
    Width = 663
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
  end
  inherited psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Component = frmBaseRoomerForm.Owner
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
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
    Left = 472
    Top = 232
  end
end
