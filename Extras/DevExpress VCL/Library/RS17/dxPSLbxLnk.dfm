object dxLBxReportLinkDesignWindow: TdxLBxReportLinkDesignWindow
  Left = 280
  Top = 273
  BorderStyle = bsDialog
  Caption = 'dxLbxReportLinkDesigner'
  ClientHeight = 272
  ClientWidth = 554
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 530
    Height = 214
    ActivePage = tshOptions
    ShowFrame = True
    TabOrder = 1
    OnChange = PageControl1Change
    ClientRectBottom = 213
    ClientRectLeft = 1
    ClientRectRight = 529
    ClientRectTop = 24
    object tshOptions: TcxTabSheet
      Caption = '&Options'
      object imgGrid: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblShow: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Show'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 240
      end
      object lblPreview: TcxLabel
        Left = 257
        Top = 0
        TabStop = False
        Caption = 'Preview'
        Transparent = True
      end
      object chbxTransparentGraphics: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 108
        Caption = '&Transparent Graphics'
        TabOrder = 3
        Transparent = True
        OnClick = chbxTransparentGraphicsClick
        Width = 159
      end
      object chbxShowHorzLines: TcxCheckBox
        Tag = 1
        Left = 75
        Top = 49
        Caption = 'Horizontal Lines'
        TabOrder = 1
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 159
      end
      object chbxShowBorders: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxShowBordersClick
        Width = 159
      end
      object chbxPaintItemGraphics: TcxCheckBox
        Left = 75
        Top = 86
        Caption = '&Paint item graphics'
        TabOrder = 2
        Transparent = True
        OnClick = chbxPaintItemGraphicsClick
        Width = 159
      end
      object Bevel4: TcxLabel
        Left = 64
        Top = 73
        AutoSize = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 186
      end
    end
    object tshColor: TcxTabSheet
      Caption = '&Color'
      object stTransparent: TcxLabel
        Left = 22
        Top = 42
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 228
      end
      object lblGridLinesColor: TcxLabel
        Left = 28
        Top = 140
        Caption = 'Grid Lines Color: '
        FocusControl = ccbxGridLineColor
        Transparent = True
      end
      object lblEvenColor: TcxLabel
        Left = 28
        Top = 92
        Caption = 'E&ven Color: '
        FocusControl = ccbxEvenColor
        Transparent = True
      end
      object lblDrawMode: TcxLabel
        Left = 10
        Top = 18
        Caption = 'Draw &Mode:'
        FocusControl = cbxDrawMode
        Transparent = True
        OnClick = lblComboClick
      end
      object lblColor: TcxLabel
        Left = 28
        Top = 66
        Caption = 'Co&lor : '
        FocusControl = ccbxColor
        Transparent = True
      end
      object cxLabel1: TcxLabel
        Left = 5
        Top = 120
        TabStop = False
        AutoSize = False
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 10
        Width = 245
      end
      object chbxTransparent: TcxCheckBox
        Left = 7
        Top = 41
        TabOrder = 1
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 2
        Left = 115
        Top = 138
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 4
        Width = 134
      end
      object ccbxEvenColor: TcxColorComboBox
        Tag = 1
        Left = 115
        Top = 91
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 134
      end
      object ccbxColor: TcxColorComboBox
        Left = 115
        Top = 64
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 134
      end
      object cbxDrawMode: TcxImageComboBox
        Left = 96
        Top = 17
        Properties.Items = <>
        TabOrder = 0
        OnClick = cbxDrawModeClick
        Width = 153
      end
    end
    object tshFont: TcxTabSheet
      Caption = '&Font'
      object edFont: TcxTextEdit
        Left = 10
        Top = 41
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 1
        Width = 238
      end
      object edEvenFont: TcxTextEdit
        Left = 10
        Top = 99
        TabStop = False
        Properties.ReadOnly = True
        Style.TransparentBorder = False
        TabOrder = 3
        Width = 238
      end
      object btnFont: TcxButton
        Left = 10
        Top = 10
        Width = 85
        Height = 23
        Caption = 'Fo&nt ...'
        TabOrder = 0
        OnClick = btnFontClick
      end
      object btnEvenFont: TcxButton
        Tag = 1
        Left = 10
        Top = 68
        Width = 85
        Height = 23
        Caption = 'E&ven Font ...'
        TabOrder = 2
        OnClick = btnFontClick
      end
    end
    object tshBehaviors: TcxTabSheet
      Caption = '&Behaviors'
      object imgMiscellaneous: TImage
        Left = 10
        Top = 101
        Width = 48
        Height = 48
        Transparent = True
      end
      object Image3: TImage
        Left = 10
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object lblSelection: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Selection'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 240
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 81
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 240
      end
      object chbxRowAutoHeight: TcxCheckBox
        Left = 75
        Top = 120
        Caption = '&Row Auto Height'
        TabOrder = 2
        Transparent = True
        OnClick = chbxRowAutoHeightClick
        Width = 148
      end
      object chbxOnlySelected: TcxCheckBox
        Left = 75
        Top = 27
        Caption = 'Only &selected cells'
        TabOrder = 0
        Transparent = True
        OnClick = chbxOnlySelectedClick
        Width = 148
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 75
        Top = 98
        Caption = 'AutoWidth'
        TabOrder = 1
        Transparent = True
        OnClick = chbxAutoWidthClick
        Width = 148
      end
    end
  end
  object pnlPreview: TPanel
    Left = 273
    Top = 54
    Width = 258
    Height = 158
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelInner = bvLowered
    BevelOuter = bvNone
    Color = clWindow
    TabOrder = 0
  end
  object ilPreview: TcxImageList
    FormatVersion = 1
    DesignInfo = 14680072
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000103030309000000100000001B000000220000
          001D0000000E0000000200000000000000000000000000000000000000010000
          00050000000C0000001500000020030E054C07270D8B0A4214C90D581AEF0A4B
          15DD03170674000000230000000D000000020000000000000000000000070410
          073C0A2D127F114E1EC0156726EC197A30FF1D883BFF229C4AFF26AD56FF066E
          1CFF0B641CFF0A4814DD03170671000000220000000D00000002000000102183
          37FF279647FF2BA553FF2DB35FFF2FBB64FF2EBA62FF2DB961FF2CB860FF0575
          20FF03721DFF066D1CFF0A621AFF084713DB0217066B0000000E0000000F2387
          3AFF36BF6CFF36BE69FF34BC67FF32BC66FF30BC65FF2FBA63FF2DB962FF0676
          21FF057520FF03711CFF03701CFF056B1AFF0B5D19FF0000001D0000000B258B
          3DFF3AC16EFF38BF6DFF36BE6BFF35BD69FF34BC67FF32BC66FF2FBB63FF077C
          24FF067922FF057520FF04741FFF03711BFF0C611BFF0000001E00000008278E
          40FF3CC371FF3BC26FFF3AC06EFF37BF6CFF35BE6CFF34BD68FF33BC66FF0880
          26FF077C24FF067A22FF05761FFF04721DFF0E641EFF00000019000000052890
          42FF3FC473FF3EC372FF3CC270FF3AC06FFF38BF6DFF36BE6BFF35BD68FF0981
          28FF088026FF077C25FF067A22FF06761FFF106721FF00000017000000032993
          43FF42C676FF40C574FF3EC472FF3DC371FF3BC270FF3AC06EFF38BF6CFF0B85
          2AFF098228FF088026FF077D25FF067A22FF136B24FF00000014000000022A94
          44FF44C87AFF43C677FF40C675FF3FC574FF51C981FF76D59BFFA2E1BAFF0C89
          2DFF0B862AFF09852AFF098026FF077E26FF156F27FF00000012000000012A94
          44FF5ACF88FF7CD8A0FFA6E4BEFFBCEBCFFFB3E9C8FF9CE4B8FF8FE4AEFF71D5
          95FF43B668FF1C953EFF0A822AFF098127FF18742BFF000000100000000143A1
          5BFFBBEBCEFFADE9C5FFAAE9C5FFA8EAC2FFA0E9BEFF99E8B8FF91E6B5FF8AE5
          ADFF81E3A8FF79E1A2FF61D18BFF39B261FF1A782EFF0000000E000000002A94
          44FF70C088FF9FDEB5FFB2EDCAFFADEBC5FFA7EAC1FF9FE8BEFF98E8B8FF91E6
          B2FF8AE5ADFF75D69AFF58BF7BFF3BA259FF1C7C31FF0000000A000000000617
          0A271549217F237C39D53FA259FF6DC085FF97DDAFFF94DFB0FF74C990FF4FAD
          6AFF32964CFF217734E1165625AA0C2E1466040F062900000003000000000000
          0000000000000000000006170A2915492280237B39D625813BDF1B5E2AA60E33
          1760051108240000000600000004000000030000000100000000000000000000
          0000000000000000000000000000000000010000000100000002000000020000
          0001000000010000000000000000000000000000000000000000}
      end>
  end
end
