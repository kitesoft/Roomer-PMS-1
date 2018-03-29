inherited FrmConnectionsStatistics: TFrmConnectionsStatistics
  BorderStyle = bsSizeable
  Caption = 'Statistical connections'
  ClientHeight = 532
  ClientWidth = 771
  ParentFont = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  ExplicitWidth = 787
  ExplicitHeight = 571
  PixelsPerInch = 96
  TextHeight = 13
  inherited sbStatusBar: TsStatusBar
    Top = 512
    Width = 771
    ExplicitTop = 512
    ExplicitWidth = 771
  end
  inherited pnlButtons: TsPanel
    Top = 469
    Width = 771
    ParentFont = False
    ExplicitTop = 469
    ExplicitWidth = 771
    inherited btnOK: TsButton
      Left = 455
      OnClick = btnOKClick
      ExplicitLeft = 455
    end
    inherited btnCancel: TsButton
      Left = 561
      ExplicitLeft = 561
    end
    inherited btnClose: TsButton
      Left = 667
      ExplicitLeft = 667
    end
  end
  object pcPages: TsPageControl [2]
    Left = 0
    Top = 0
    Width = 771
    Height = 469
    ActivePage = tsSnapshot
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object tsSnapshot: TsTabSheet
      Caption = 'Snapshot'
      object gbxConnectionSettings: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 757
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
      object gbxActions: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 208
        Width = 757
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
    object tsHagstofan: TsTabSheet
      Caption = 'Hagstofan'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object sGroupBox1: TsGroupBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 757
        Height = 432
        Align = alClient
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
        object lbHsId: TsLabel
          Left = 105
          Top = 163
          Width = 81
          Height = 13
          Alignment = taRightJustify
          Caption = 'ID at Hagstofan:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsKennitala: TsLabel
          Left = 94
          Top = 190
          Width = 92
          Height = 13
          Alignment = taRightJustify
          Caption = 'Civil ID (Kennitala):'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsName: TsLabel
          Left = 155
          Top = 219
          Width = 31
          Height = 13
          Alignment = taRightJustify
          Caption = 'Name:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsEmail: TsLabel
          Left = 158
          Top = 249
          Width = 28
          Height = 13
          Alignment = taRightJustify
          Caption = 'Email:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsAddress: TsLabel
          Left = 143
          Top = 280
          Width = 43
          Height = 13
          Alignment = taRightJustify
          Caption = 'Address:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsPostCode: TsLabel
          Left = 135
          Top = 340
          Width = 51
          Height = 13
          Alignment = taRightJustify
          Caption = 'Post code:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsTelephone: TsLabel
          Left = 132
          Top = 370
          Width = 54
          Height = 13
          Alignment = taRightJustify
          Caption = 'Telephone:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object lbHsHomepage: TsLabel
          Left = 131
          Top = 400
          Width = 55
          Height = 13
          Alignment = taRightJustify
          Caption = 'Homepage:'
          Enabled = False
          ParentFont = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
        end
        object sLabel1: TsLabel
          Left = 32
          Top = 32
          Width = 449
          Height = 73
          AutoSize = False
          Caption = 
            'This allows you to connect your hotel to the Icelandic "Bureau O' +
            'f Statistics, BOS" (Hagstofa '#205'slands).'#13#10'Please make sure to prov' +
            'ide the correct information. '#13#10'All information will be validated' +
            ' by the BOS.'
          WordWrap = True
        end
        object cbxHsActive: TsCheckBox
          Left = 198
          Top = 124
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
          OnClick = cbxHsActiveClick
          ImgChecked = 0
          ImgUnchecked = 0
        end
        object edHsId: TsEdit
          Left = 200
          Top = 160
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
        object edHsKennitala: TsEdit
          Left = 200
          Top = 187
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
        object edHsName: TsEdit
          Left = 200
          Top = 214
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
          TabOrder = 3
        end
        object edHsEmail: TsEdit
          Left = 200
          Top = 244
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
        object edHsAddress1: TsEdit
          Left = 200
          Top = 274
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
          TabOrder = 5
        end
        object edHsAddress2: TsEdit
          Left = 200
          Top = 304
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
          TabOrder = 6
        end
        object edHsPostCode: TsEdit
          Left = 200
          Top = 334
          Width = 53
          Height = 24
          Color = clWhite
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          MaxLength = 3
          ParentFont = False
          TabOrder = 7
        end
        object edHsTelephone: TsEdit
          Left = 200
          Top = 364
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
          TabOrder = 8
        end
        object edHsHomepage: TsEdit
          Left = 200
          Top = 394
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
          TabOrder = 9
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
