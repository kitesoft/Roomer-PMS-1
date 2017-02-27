object dxfmTVReportLinkDesignWindow: TdxfmTVReportLinkDesignWindow
  Left = 358
  Top = 280
  BorderStyle = bsDialog
  Caption = 'dxfmTVReportLinkDesignWindow'
  ClientHeight = 376
  ClientWidth = 590
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 566
    Height = 318
    ActivePage = tshOptions
    Anchors = [akLeft, akTop, akRight, akBottom]
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 317
    ClientRectLeft = 1
    ClientRectRight = 565
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
      object Bevel2: TcxLabel
        Left = 66
        Top = 73
        AutoSize = False
        ParentColor = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 189
      end
      object Bevel3: TcxLabel
        Left = 66
        Top = 132
        AutoSize = False
        ParentColor = False
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 10
        Width = 189
      end
      object chbxShowBorders: TcxCheckBox
        Left = 70
        Top = 27
        Caption = '&Border'
        TabOrder = 0
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object chbxShowButtons: TcxCheckBox
        Tag = 5
        Left = 70
        Top = 108
        Caption = 'Buttons'
        TabOrder = 3
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object chbxShowGrid: TcxCheckBox
        Tag = 1
        Left = 70
        Top = 49
        Caption = '&Grid'
        TabOrder = 1
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object chbxShowImages: TcxCheckBox
        Tag = 3
        Left = 70
        Top = 167
        Caption = 'Images'
        TabOrder = 5
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object chbxShowStateImages: TcxCheckBox
        Tag = 2
        Left = 70
        Top = 145
        Caption = 'State Images'
        TabOrder = 4
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object chbxShowTreeLines: TcxCheckBox
        Tag = 4
        Left = 70
        Top = 86
        Caption = 'TreeLines'
        TabOrder = 2
        Transparent = True
        OnClick = chbxShowClick
        Width = 113
      end
      object lblPreview: TcxLabel
        Left = 261
        Top = 0
        TabStop = False
        Caption = 'Preview'
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
        Width = 245
      end
    end
    object tshColors: TcxTabSheet
      Caption = '&Color'
      object stTransparent: TcxLabel
        Left = 22
        Top = 10
        TabStop = False
        AutoSize = False
        Caption = ' &Transparent '
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 233
      end
      object lblTreeLinesColor: TcxLabel
        Left = 32
        Top = 107
        Caption = 'TreeLines Color:'
        FocusControl = ccbxTreeLineColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblGridLinesColor: TcxLabel
        Left = 32
        Top = 80
        Caption = '&Grid Lines Color: '
        FocusControl = ccbxGridLineColor
        Transparent = True
        OnClick = lblColorClick
      end
      object lblColor: TcxLabel
        Left = 32
        Top = 35
        Caption = 'Co&lor: '
        FocusControl = ccbxColor
        Transparent = True
        OnClick = lblColorClick
      end
      object cxLabel1: TcxLabel
        Left = 16
        Top = 56
        TabStop = False
        AutoSize = False
        FocusControl = chbxTransparent
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = stTransparentClick
        Height = 18
        Width = 239
      end
      object chbxTransparent: TcxCheckBox
        Left = 7
        Top = 9
        TabOrder = 0
        Transparent = True
        OnClick = chbxTransparentClick
        Width = 21
      end
      object ccbxTreeLineColor: TcxColorComboBox
        Tag = 2
        Left = 126
        Top = 105
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 3
        Width = 128
      end
      object ccbxGridLineColor: TcxColorComboBox
        Tag = 1
        Left = 126
        Top = 77
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 2
        Width = 128
      end
      object ccbxColor: TcxColorComboBox
        Left = 126
        Top = 33
        Properties.AllowSelectColor = True
        Properties.CustomColors = <>
        Properties.OnChange = ccbxColorChange
        TabOrder = 1
        Width = 128
      end
    end
    object tshFonts: TcxTabSheet
      Caption = '&Font'
      object edFont: TcxTextEdit
        Left = 9
        Top = 40
        TabStop = False
        Properties.ReadOnly = True
        TabOrder = 1
        Text = 'edFont'
        Width = 244
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
    end
    object tshBehaviors: TcxTabSheet
      Caption = '&Behaviors'
      object Image5: TImage
        Left = 12
        Top = 106
        Width = 48
        Height = 48
      end
      object Image4: TImage
        Left = 12
        Top = 30
        Width = 48
        Height = 48
        Transparent = True
      end
      object seExpandLevel: TcxSpinEdit
        Left = 151
        Top = 55
        Properties.MaxValue = 100.000000000000000000
        Properties.MinValue = -1.000000000000000000
        Properties.OnChange = ExpandLevelChange
        TabOrder = 1
        Width = 103
      end
      object lblMiscellaneous: TcxLabel
        Left = 10
        Top = 86
        AutoSize = False
        Caption = 'Miscellaneous'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 245
      end
      object lblExpandLevel: TcxLabel
        Left = 74
        Top = 56
        Caption = 'Expand &level : '
        FocusControl = seExpandLevel
        Transparent = True
        OnClick = lblExpandLevelClick
      end
      object lblExpanding: TcxLabel
        Left = 10
        Top = 10
        AutoSize = False
        Caption = 'Expanding'
        Properties.LineOptions.Visible = True
        Transparent = True
        Height = 18
        Width = 245
      end
      object chbxNodeAutoHeight: TcxCheckBox
        Left = 72
        Top = 125
        Caption = '&Node Auto Height'
        TabOrder = 3
        Transparent = True
        OnClick = chbxNodeAutoHeightClick
        Width = 111
      end
      object chbxAutoWidth: TcxCheckBox
        Left = 72
        Top = 103
        Caption = 'Auto &Width'
        TabOrder = 2
        Transparent = True
        OnClick = chbxAutoWidthClick
        Width = 97
      end
      object chbxAutoNodesExpand: TcxCheckBox
        Left = 72
        Top = 27
        Caption = '&Auto Node Expanded'
        TabOrder = 0
        Transparent = True
        OnClick = chbxAutoNodesExpandClick
        Width = 154
      end
    end
  end
  object pnlPreview: TPanel
    Left = 276
    Top = 54
    Width = 290
    Height = 264
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvLowered
    Color = clWindow
    TabOrder = 1
  end
  object ilPreview: TcxImageList
    FormatVersion = 1
    DesignInfo = 16252936
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
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000003000000080000001100000019000000160000
          0009000000010000000000000000000000000000000000000000000000010000
          00030000000900000010050301232B16066A52290BAD7C3F10E964330DCD170B
          035300000016000000060000000100000000000000000000000000000004150A
          033249250A8970380FC6984E17FBA9602AFFB7723CFFC88650FFAC6027FF914A
          16FD52290BB4090501370000001000000004000000000000000000000009A652
          15FFC17941FFCE8C57FFDB9D6AFFDA9B67FFD79762FFD4925EFFBB6C33FFB766
          2DFFA3561EFF864413F63D1F0895020100230000000B0000000200000008A954
          16FFE9B07CFFE7AA78FFE3A573FFDEA16EFFDC9C69FFD79864FFBC6E35FFB96A
          31FFB5642BFFB05D24FF9A4E18FF73390FE32613056C0000000B00000006AC55
          16FFEEB684FFECB17EFFE7AC7AFFE4A874FFE1A36FFFDD9F6AFFBD7038FFBB6C
          33FFB8672EFFB36128FFB05C22FFA7551BFF894512FF0000001700000005B057
          17FFF3BB89FFF0B786FFEDB381FFE9AF7BFFE6A976FFE2A571FFBF723AFFBD6F
          37FFBA6A32FFB6652CFFB25F26FFAF5B20FF8B4612FF0000001800000004B258
          17FFF7BF90FFF4BC8BFFF0BA8AFFF1C399FFF1CAA6FFF3D3B4FFE5B994FFC781
          4DFFBB6D35FFB86830FFB46329FFB15E23FF8D4713FF0000001500000003B65A
          17FFFBD6B3FFFBDEC3FFFBE5D0FFF9E3CBFFF7DEC5FFF5DABDFFF4D5B6FFF1D1
          AFFFDCA77CFFBF723AFFB6662DFFB36127FF8F4813FF0000001100000001B85B
          18FFE3B794FFFAE7D2FFFBE7D2FFF9E2CCFFF7DEC5FFF5DABDFFF4D6B6FFF2D2
          B0FFF1CEABFFEDC6A0FFD29565FFB6652CFF934914FF0000000E000000002814
          0538763A0FA4B86427F9D69C71FFF2D6BAFFF7DEC4FFF6DABDFFF4D6B7FFF2D1
          B0FFF1CFABFFEDC8A2FFD7A77CFFBA7C4BFF964B14FF0000000A000000000000
          0000000000010F080217582B0B7EA45317E8C98754FFE7BE9AFFEBC4A1FFD097
          69FFB9753FFF9D5017F770380FBB4421097A140A032B00000003000000000000
          000000000000000000000000000002010003401F085A8C4512C9974C14DE5D2E
          0C8A2F1706480402010600000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end>
  end
end
