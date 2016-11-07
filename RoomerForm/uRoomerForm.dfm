object frmBaseRoomerForm: TfrmBaseRoomerForm
  Left = 0
  Top = 0
  Caption = 'Base Roomer Form'
  ClientHeight = 253
  ClientWidth = 537
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 13
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  PixelsPerInch = 96
  TextHeight = 13
  object sbStatusBar: TsStatusBar
    Left = 0
    Top = 233
    Width = 537
    Height = 20
    Color = 15130321
    Panels = <
      item
        Style = psOwnerDraw
        Width = 27
      end
      item
        Text = 'Idle'
        Width = 50
      end
      item
        Style = psOwnerDraw
        Width = 50
      end>
    OnDrawPanel = sbStatusBarDrawPanel
    SkinData.SkinSection = 'STATUSBAR'
  end
  object sbProgressBar: TAdvSmoothProgressBar
    Left = 272
    Top = 144
    Width = 150
    Height = 17
    Step = 10.000000000000000000
    Maximum = 100.000000000000000000
    ProgressAnimation = False
    Appearance.BackGroundFill.Color = clInactiveBorder
    Appearance.BackGroundFill.ColorTo = clGradientActiveCaption
    Appearance.BackGroundFill.ColorMirror = clNone
    Appearance.BackGroundFill.ColorMirrorTo = clNone
    Appearance.BackGroundFill.GradientType = gtVertical
    Appearance.BackGroundFill.GradientMirrorType = gtSolid
    Appearance.BackGroundFill.BorderColor = clSilver
    Appearance.BackGroundFill.Rounding = 0
    Appearance.BackGroundFill.ShadowOffset = 0
    Appearance.BackGroundFill.Glow = gmNone
    Appearance.ProgressFill.Color = clBlue
    Appearance.ProgressFill.ColorTo = 16768452
    Appearance.ProgressFill.ColorMirror = 16765357
    Appearance.ProgressFill.ColorMirrorTo = 16767936
    Appearance.ProgressFill.GradientType = gtVertical
    Appearance.ProgressFill.GradientMirrorType = gtVertical
    Appearance.ProgressFill.BorderColor = 16765357
    Appearance.ProgressFill.Rounding = 0
    Appearance.ProgressFill.ShadowOffset = 0
    Appearance.ProgressFill.Glow = gmNone
    Appearance.Font.Charset = DEFAULT_CHARSET
    Appearance.Font.Color = clWindowText
    Appearance.Font.Height = -11
    Appearance.Font.Name = 'Tahoma'
    Appearance.Font.Style = []
    Appearance.ProgressFont.Charset = DEFAULT_CHARSET
    Appearance.ProgressFont.Color = clWindowText
    Appearance.ProgressFont.Height = -11
    Appearance.ProgressFont.Name = 'Tahoma'
    Appearance.ProgressFont.Style = []
    Appearance.ValueFormat = '%.0f%%'
    Version = '1.9.0.2'
    OnPositionChanged = sbProgressBarPositionChanged
    Visible = False
    TMSStyle = 4
  end
  object psRoomerBase: TcxPropertiesStore
    Components = <
      item
        Properties.Strings = (
          'Height'
          'Left'
          'Top'
          'Width'
          'Position')
      end>
    StorageName = 'cxPropertiesStore1'
    StorageType = stRegistry
    Left = 568
    Top = 16
  end
  object cxsrRoomerStyleRepository: TcxStyleRepository
    Left = 488
    Top = 16
    PixelsPerInch = 96
    object cxstBandHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstCardCaptionRow: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstCardRowCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContent: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContentEven: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = 16053492
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstContentOdd: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstFilterBar: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnShadow
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstFooter: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstGroup: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxstPreview: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxstSelection: TcxStyle
    end
    object cxstReportBandHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportCardCaptionRow: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportCardRowCaption: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContent: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContentEven: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = 16053492
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportContentOdd: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportFilterBar: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnShadow
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportFooter: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportGroup: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportHeader: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
    end
    object cxstReportPreview: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object cxstReportSelection: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clDefault
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
    end
    object dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet
      Caption = 'Gridprinting Styles'
      Styles.BandHeader = cxstReportBandHeader
      Styles.Caption = cxstReportCaption
      Styles.CardCaptionRow = cxstReportCardCaptionRow
      Styles.CardRowCaption = cxstReportCardRowCaption
      Styles.Content = cxstReportContent
      Styles.ContentEven = cxstReportContentEven
      Styles.ContentOdd = cxstReportContentOdd
      Styles.FilterBar = cxstReportFilterBar
      Styles.Footer = cxstReportFooter
      Styles.Group = cxstReportGroup
      Styles.Header = cxstReportHeader
      Styles.Preview = cxstReportPreview
      Styles.Selection = cxstReportSelection
      BuiltIn = True
    end
    object cxssRoomerGridTableView: TcxGridTableViewStyleSheet
      Caption = 'Gridview Styles'
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
end
