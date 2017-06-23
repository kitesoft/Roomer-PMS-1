inherited FrmPayCardView: TFrmPayCardView
  Caption = 'View pay-card information'
  ClientHeight = 591
  ClientWidth = 976
  Font.Height = -11
  OnShow = FormShow
  ExplicitWidth = 992
  ExplicitHeight = 630
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 571
    Width = 976
    ExplicitTop = 571
    ExplicitWidth = 976
  end
  object pnlHead: TsPanel [1]
    Left = 0
    Top = 0
    Width = 976
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
  end
  object pnlClient: TsPanel [2]
    Left = 0
    Top = 41
    Width = 976
    Height = 530
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object browser: TsWebBrowser
      Left = 0
      Top = 0
      Width = 976
      Height = 530
      Align = alClient
      TabOrder = 0
      ExplicitHeight = 550
      ControlData = {
        4C000000DF640000C73600000000000000000000000000000000000000000000
        000000004C000000000000000000000001000000E0D057007335CF11AE690800
        2B2E126208000000000000004C0000000114020000000000C000000000000046
        8000000000000000000000000000000000000000000000000000000000000000
        00000000000000000100000000000000000000000000000000000000}
    end
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
    PixelsPerInch = 96
    inherited dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      BuiltIn = True
    end
    inherited cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      BuiltIn = True
    end
  end
end
