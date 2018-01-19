inherited FrmConnectionsStatistics: TFrmConnectionsStatistics
  Caption = 'Statistical connections'
  ClientHeight = 458
  ClientWidth = 781
  ParentFont = False
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 787
  ExplicitHeight = 487
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 438
    Width = 781
    ExplicitTop = 476
    ExplicitWidth = 781
  end
  inherited pnlButtons: TsPanel
    Top = 395
    Width = 781
    ParentFont = False
    ExplicitTop = 433
    ExplicitWidth = 781
    inherited btnOK: TsButton
      Left = 465
      OnClick = btnOKClick
      ExplicitLeft = 465
    end
    inherited btnCancel: TsButton
      Left = 571
      ExplicitLeft = 571
    end
    inherited btnClose: TsButton
      Left = 677
      ExplicitLeft = 677
    end
  end
  object sPageControl1: TsPageControl [2]
    Left = 0
    Top = 0
    Width = 781
    Height = 395
    ActivePage = sTabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object sTabSheet1: TsTabSheet
      Caption = 'Snapshot'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitTop = 24
      ExplicitHeight = 405
      object gbxConnectionSettings: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 767
        Height = 199
        Align = alTop
        Caption = 'Connection settings'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 0
        SkinData.SkinSection = 'PANEL'
        object lbServiceUrl: TsLabel
          Left = 125
          Top = 64
          Width = 61
          Height = 13
          Alignment = taRightJustify
          Caption = 'Service URL:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbUsername: TsLabel
          Left = 90
          Top = 91
          Width = 96
          Height = 13
          Alignment = taRightJustify
          Caption = 'Endpoint username:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbPassword: TsLabel
          Left = 136
          Top = 120
          Width = 50
          Height = 13
          Alignment = taRightJustify
          Caption = 'Password:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbApiKey: TsLabel
          Left = 146
          Top = 150
          Width = 40
          Height = 13
          Alignment = taRightJustify
          Caption = 'Api Key:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object cbxActive: TsCheckBox
          Left = 198
          Top = 25
          Width = 58
          Height = 17
          Caption = 'Active'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = cbxActiveClick
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object edServiceUrl: TsEdit
          Left = 200
          Top = 61
          Width = 505
          Height = 21
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object edUsername: TsEdit
          Left = 200
          Top = 88
          Width = 505
          Height = 21
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object edPassword: TsEdit
          Left = 200
          Top = 115
          Width = 505
          Height = 24
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          PasswordChar = '*'
          TabOrder = 3
        end
        object edApiKey: TsEdit
          Left = 200
          Top = 145
          Width = 505
          Height = 24
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object __btnViePassword: TsButton
          Left = 707
          Top = 115
          Width = 27
          Height = 24
          ImageIndex = 129
          Images = DImages.cxSmallImagesFlat
          TabOrder = 5
          OnMouseDown = __btnViePasswordMouseDown
          OnMouseUp = __btnViePasswordMouseUp
        end
      end
      object sGroupBox1: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 208
        Width = 767
        Height = 121
        Align = alTop
        Caption = 'Actions'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 1
        SkinData.SkinSection = 'PANEL'
        object btnForceFull: TsButton
          Left = 22
          Top = 33
          Width = 201
          Height = 25
          Caption = 'Force FULL export'
          Enabled = False
          TabOrder = 0
          OnClick = btnForceFullClick
        end
        object btnForceIncremental: TsButton
          Left = 22
          Top = 64
          Width = 201
          Height = 25
          Caption = 'Force incremental export'
          Enabled = False
          TabOrder = 1
          OnClick = btnForceIncrementalClick
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
end
