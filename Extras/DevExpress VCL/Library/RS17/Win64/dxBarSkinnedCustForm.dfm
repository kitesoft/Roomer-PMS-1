inherited dxBarSkinnedCustomizationForm: TdxBarSkinnedCustomizationForm
  ClientWidth = 370
  ClientHeight = 310
  BorderIcons = [biSystemMenu]
  Caption = 'Customize'
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object LeftBevel: TBevel
    Left = 0
    Top = 8
    Width = 6
    Height = 266
    Align = alLeft
    Shape = bsSpacer
  end
  object RightBevel: TBevel
    Left = 364
    Top = 8
    Width = 6
    Height = 266
    Align = alRight
    Shape = bsSpacer
  end
  object TopBevel: TBevel
    Left = 0
    Top = 0
    Width = 370
    Height = 8
    Align = alTop
    Shape = bsSpacer
  end
  object Panel1: TcxGroupBox
    Left = 0
    Top = 274
    Align = alBottom
    PanelStyle.Active = True
    Style.BorderStyle = ebsNone
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Transparent = True
    Height = 36
    Width = 370
    object BClose: TcxButton
      Left = 285
      Top = 6
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Close'
      Default = True
      ModalResult = 1
      TabOrder = 1
      OnClick = BCloseClick
    end
    object BHelp: TcxButton
      Left = 6
      Top = 6
      Width = 25
      Height = 25
      TabOrder = 0
      OnClick = BHelpClick
    end
  end
  object PageControl: TcxPageControl
    Left = 6
    Top = 8
    Width = 358
    Height = 266
    Align = alClient
    TabOrder = 0
    Properties.ActivePage = tsToolbars
    Properties.CustomButtons.Buttons = <>
    Properties.ShowFrame = True
    ClientRectBottom = 265
    ClientRectLeft = 1
    ClientRectRight = 357
    ClientRectTop = 24
    object tsToolbars: TcxTabSheet
      Caption = ' Toolbars '
      object Panel2: TcxGroupBox
        Left = 0
        Top = 0
        Align = alClient
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 0
        Height = 241
        Width = 356
        object BBarDelete: TcxButton
          Left = 242
          Top = 83
          Width = 107
          Height = 25
          Anchors = [akTop, akRight]
          TabOrder = 0
        end
        object BBarNew: TcxButton
          Left = 242
          Top = 21
          Width = 107
          Height = 25
          Anchors = [akTop, akRight]
          TabOrder = 1
        end
        object BBarRename: TcxButton
          Left = 242
          Top = 52
          Width = 107
          Height = 25
          Anchors = [akTop, akRight]
          TabOrder = 2
        end
        object BBarReset: TcxButton
          Left = 242
          Top = 114
          Width = 107
          Height = 25
          Anchors = [akTop, akRight]
          TabOrder = 3
        end
        object LabelToobars: TcxLabel
          Left = 4
          Top = 4
          Caption = 'Toolb&ars:'
          Transparent = True
        end
        object lbBarsList: TcxListBox
          Left = 6
          Top = 20
          Width = 230
          Height = 214
          Anchors = [akLeft, akTop, akRight, akBottom]
          ItemHeight = 13
          ListStyle = lbOwnerDrawFixed
          TabOrder = 5
        end
      end
    end
    object tsItems: TcxTabSheet
      Caption = ' Commands '
      object Panel6: TcxGroupBox
        Left = 0
        Top = 0
        Align = alTop
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 0
        Height = 25
        Width = 356
        object LabelCategories: TcxLabel
          Left = 6
          Top = 8
          Caption = 'Cate&gories:'
          FocusControl = lbCategories
          Transparent = True
        end
        object LabelCommands: TcxLabel
          Left = 166
          Top = 8
          Anchors = [akTop, akRight]
          Caption = 'Comman&ds:'
          Transparent = True
        end
        object CategoriesPopupButtonPlace: TcxButton
          Left = 65
          Top = 6
          Width = 88
          Height = 17
          TabOrder = 3
        end
        object CommandsPopupButtonPlace: TcxButton
          Left = 231
          Top = 6
          Width = 121
          Height = 17
          Anchors = [akTop, akRight]
          TabOrder = 2
        end
      end
      object Panel7: TcxGroupBox
        Left = 0
        Top = 25
        Align = alClient
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 1
        Height = 150
        Width = 356
        object Bevel4: TBevel
          Left = 348
          Top = 2
          Width = 6
          Height = 146
          Align = alRight
          Shape = bsSpacer
        end
        object Bevel5: TBevel
          Left = 2
          Top = 2
          Width = 6
          Height = 146
          Align = alLeft
          Shape = bsSpacer
        end
        object lbCategories: TcxListBox
          Left = 8
          Top = 2
          Width = 149
          Height = 146
          Align = alLeft
          ItemHeight = 13
          TabOrder = 0
        end
        object lbItems: TcxListBox
          Left = 165
          Top = 2
          Width = 183
          Height = 146
          Align = alRight
          ItemHeight = 13
          ListStyle = lbOwnerDrawVariable
          TabOrder = 1
          OnDrawItem = lbItemsDrawItem
        end
      end
      object Panel9: TcxGroupBox
        Left = 0
        Top = 175
        Align = alBottom
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 2
        Height = 66
        Width = 356
        object DescriptionLabel: TcxLabel
          Left = 8
          Top = 20
          AutoSize = False
          Transparent = True
          Height = 37
          Width = 337
        end
        object LabelDescription: TcxLabel
          Left = 6
          Top = 4
          Anchors = [akLeft, akTop, akRight]
          AutoSize = False
          Caption = 'Description  '
          Properties.Alignment.Vert = taVCenter
          Properties.LineOptions.Visible = True
          Transparent = True
          Height = 16
          Width = 344
          AnchorY = 12
        end
      end
    end
    object tsOptions: TcxTabSheet
      Caption = ' Options '
      object StandardOptionsPanel: TcxGroupBox
        Left = 0
        Top = 0
        Align = alClient
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 0
        Height = 241
        Width = 356
        object LabelMenuAnimations: TcxLabel
          Left = 24
          Top = 152
          Caption = '&Menu animations:'
          FocusControl = ComboBoxMenuAnimations
          Transparent = True
        end
        object ComboBoxMenuAnimations: TcxComboBox
          Left = 134
          Top = 148
          Properties.DropDownListStyle = lsEditFixedList
          TabOrder = 2
          OnClick = ComboBoxMenuAnimationsClick
          Width = 93
        end
        object CBHint2: TcxCheckBox
          Left = 24
          Top = 85
          Caption = 'Show s&hortcut keys in ToolTips'
          TabOrder = 1
          Transparent = True
          OnClick = CBHint2Click
          Width = 301
        end
        object CBLargeIcons: TcxCheckBox
          Left = 24
          Top = 38
          Caption = '&Large icons'
          TabOrder = 0
          Transparent = True
          OnClick = CBLargeIconsClick
          Width = 301
        end
        object CBHint1: TcxCheckBox
          Left = 24
          Top = 63
          Caption = 'Show Tool&Tips on toolbars'
          TabOrder = 4
          Transparent = True
          OnClick = CBHint1Click
          Width = 301
        end
      end
      object EnhancedOptionsPanel: TcxGroupBox
        Left = 0
        Top = 0
        Align = alClient
        PanelStyle.Active = True
        Style.BorderStyle = ebsNone
        TabOrder = 1
        Height = 241
        Width = 356
        object BResetUsageData: TcxButton
          Left = 20
          Top = 76
          Width = 119
          Height = 25
          Caption = '&Reset my usage data'
          TabOrder = 2
          OnClick = BResetUsageDataClick
        end
        object Label1: TcxLabel
          Left = 20
          Top = 197
          Caption = '&Menu animations:'
          FocusControl = ComboBoxMenuAnimationsEx
          Transparent = True
        end
        object Label2: TcxLabel
          Left = 12
          Top = 115
          AutoSize = False
          Caption = 'Other  '
          Properties.Alignment.Vert = taVCenter
          Properties.LineOptions.Visible = True
          Transparent = True
          Height = 16
          Width = 320
          AnchorY = 123
        end
        object Label3: TcxLabel
          Left = 12
          Top = 12
          AutoSize = False
          Caption = 'Personalized Menus and Toolbars  '
          Properties.Alignment.Vert = taVCenter
          Properties.LineOptions.Visible = True
          Transparent = True
          Height = 16
          Width = 320
          AnchorY = 20
        end
        object CBMenusShowRecentItemsFirst: TcxCheckBox
          Left = 20
          Top = 32
          Caption = 'Me&nus show recently used commands first'
          TabOrder = 0
          Transparent = True
          OnClick = CBMenusShowRecentItemsFirstClick
          Width = 309
        end
        object CBShowFullMenusAfterDelay: TcxCheckBox
          Left = 36
          Top = 52
          Caption = 'Show f&ull menus after a short delay'
          TabOrder = 1
          Transparent = True
          OnClick = CBShowFullMenusAfterDelayClick
          Width = 293
        end
        object CBHint1Ex: TcxCheckBox
          Left = 20
          Top = 152
          Caption = 'Show Tool&Tips on toolbars'
          TabOrder = 4
          Transparent = True
          OnClick = CBHint1ExClick
          Width = 309
        end
        object CBHint2Ex: TcxCheckBox
          Left = 36
          Top = 172
          Caption = 'Show s&hortcut keys in ToolTips'
          TabOrder = 5
          Transparent = True
          OnClick = CBHint2Click
          Width = 293
        end
        object CBLargeIconsEx: TcxCheckBox
          Left = 20
          Top = 132
          Caption = '&Large icons'
          TabOrder = 3
          Transparent = True
          OnClick = CBLargeIconsClick
          Width = 309
        end
        object ComboBoxMenuAnimationsEx: TcxComboBox
          Left = 132
          Top = 196
          Properties.DropDownListStyle = lsFixedList
          TabOrder = 6
          OnClick = ComboBoxMenuAnimationsClick
          Width = 93
        end
      end
    end
    object TabSheet1: TcxTabSheet
      Caption = 'Key Tips'
      ImageIndex = 5
      TabVisible = False
      object tvKeyTips: TTreeView
        Left = 11
        Top = 13
        Width = 314
        Height = 204
        Indent = 19
        TabOrder = 0
      end
    end
  end
end
