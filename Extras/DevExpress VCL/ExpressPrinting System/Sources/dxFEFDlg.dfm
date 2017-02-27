object dxFEFDialog: TdxFEFDialog
  Left = 446
  Top = 168
  BorderStyle = bsDialog
  Caption = 'Fill Effects'
  ClientHeight = 318
  ClientWidth = 420
  Color = clBtnFace
  OldCreateOrder = True
  Position = poScreenCenter
  ShowHint = True
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object btnHelp: TcxButton
    Left = 324
    Top = 99
    Width = 85
    Height = 23
    Caption = '&Help'
    TabOrder = 4
  end
  object btnApply: TcxButton
    Left = 324
    Top = 70
    Width = 85
    Height = 23
    Caption = '&Apply'
    TabOrder = 3
    OnClick = btnApplyClick
  end
  object btnCancel: TcxButton
    Left = 324
    Top = 41
    Width = 85
    Height = 23
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object btnOK: TcxButton
    Left = 324
    Top = 12
    Width = 85
    Height = 23
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object pnlPreview: TcxGroupBox
    Left = 324
    Top = 224
    PanelStyle.Active = True
    PanelStyle.BorderWidth = 2
    ParentBackground = False
    ParentColor = False
    Style.Color = clBtnFace
    TabOrder = 5
    Height = 82
    Width = 85
    object pbxPreview: TPaintBox
      Left = 4
      Top = 4
      Width = 77
      Height = 74
      Align = alClient
      OnPaint = pbxPreviewPaint
    end
  end
  object lblSample: TcxLabel
    Left = 323
    Top = 206
    Caption = 'Sample : '
    Transparent = True
  end
  object PageControl1: TcxPageControl
    Left = 12
    Top = 12
    Width = 299
    Height = 294
    ActivePage = tshTexture
    ShowFrame = True
    TabOrder = 0
    OnChange = PageControl1Change
    ClientRectBottom = 293
    ClientRectLeft = 1
    ClientRectRight = 298
    ClientRectTop = 24
    object tshTexture: TcxTabSheet
      Caption = '&Texture'
      ImageIndex = 0
      object dgTexture: TDrawGrid
        Left = 9
        Top = 5
        Width = 280
        Height = 199
        Anchors = [akLeft, akTop, akBottom]
        BorderStyle = bsNone
        ColCount = 4
        Ctl3D = True
        DefaultColWidth = 65
        DefaultRowHeight = 65
        DefaultDrawing = False
        FixedCols = 0
        RowCount = 6
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goThumbTracking]
        ParentCtl3D = False
        ScrollBars = ssVertical
        TabOrder = 0
        OnClick = dgTextureClick
        OnDblClick = dgTextureDblClick
        OnDrawCell = dgTextureDrawCell
        OnMouseMove = dgTextureMouseMove
      end
      object btnOtherTexture: TcxButton
        Left = 168
        Top = 236
        Width = 121
        Height = 23
        Caption = '&Other Texture ...'
        TabOrder = 1
        OnClick = btnOtherTextureClick
      end
      object pnlTextureName: TcxLabel
        Left = 8
        Top = 210
        TabStop = False
        AutoSize = False
        ParentColor = False
        Style.BorderStyle = ebsFlat
        Properties.Alignment.Horz = taCenter
        Properties.Alignment.Vert = taVCenter
        Transparent = True
        Height = 20
        Width = 281
        AnchorX = 149
        AnchorY = 220
      end
    end
    object tshPattern: TcxTabSheet
      Caption = '&Pattern'
      ImageIndex = 1
      object dgPattern: TDrawGrid
        Left = 8
        Top = 7
        Width = 280
        Height = 157
        Anchors = [akLeft, akTop, akBottom]
        BorderStyle = bsNone
        ColCount = 8
        DefaultColWidth = 34
        DefaultRowHeight = 25
        DefaultDrawing = False
        FixedCols = 0
        RowCount = 6
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
        ParentShowHint = False
        ScrollBars = ssNone
        ShowHint = True
        TabOrder = 0
        OnClick = dgPatternClick
        OnDblClick = dgPatternDblClick
        OnDrawCell = dgPatternDrawCell
        OnMouseMove = dgPatternMouseMove
      end
      object btnInvert: TcxButton
        Left = 8
        Top = 237
        Width = 280
        Height = 23
        Caption = 'I&nvert colors'
        TabOrder = 3
        OnClick = btnInvertClick
      end
      object lblForeground: TcxLabel
        Left = 7
        Top = 193
        Caption = '&Foreground : '
        FocusControl = cbxForeColor
        Transparent = True
        OnClick = lblShowCombo
      end
      object lblBackground: TcxLabel
        Left = 163
        Top = 193
        Anchors = [akTop, akRight]
        Caption = '&Background : '
        FocusControl = cbxBackColor
        Transparent = True
        OnClick = lblShowCombo
      end
      object pnlPatternName: TcxLabel
        Left = 8
        Top = 169
        TabStop = False
        AutoSize = False
        ParentColor = False
        Style.BorderStyle = ebsFlat
        Properties.Alignment.Horz = taCenter
        Properties.Alignment.Vert = taVCenter
        Transparent = True
        Height = 20
        Width = 280
        AnchorX = 148
        AnchorY = 179
      end
      object cbxForeColor: TcxColorComboBox
        Left = 7
        Top = 210
        Properties.CustomColors = <>
        Properties.OnChange = cbxColorChange
        TabOrder = 1
        Width = 124
      end
      object cbxBackColor: TcxColorComboBox
        Left = 163
        Top = 210
        Anchors = [akTop, akRight]
        Properties.CustomColors = <>
        TabOrder = 2
        Width = 125
      end
    end
    object tshPicture: TcxTabSheet
      Caption = 'P&icture'
      ImageIndex = 2
      object bvlPictureHolder: TBevel
        Left = 8
        Top = 7
        Width = 279
        Height = 146
        Anchors = [akLeft, akTop, akRight, akBottom]
      end
      object pnlPictureName: TcxLabel
        Left = 8
        Top = 159
        TabStop = False
        Anchors = [akLeft, akRight, akBottom]
        AutoSize = False
        ParentColor = False
        Style.BorderStyle = ebsFlat
        Properties.Alignment.Horz = taCenter
        Properties.Alignment.Vert = taVCenter
        Transparent = True
        Height = 20
        Width = 279
        AnchorX = 148
        AnchorY = 169
      end
      object lblPaintMode: TcxLabel
        Left = 8
        Top = 214
        Anchors = [akLeft, akTop, akRight]
        AutoSize = False
        Caption = 'Paint &mode'
        FocusControl = cbxPaintMode
        Properties.LineOptions.Visible = True
        Transparent = True
        OnClick = lblShowCombo
        Height = 19
        Width = 279
      end
      object cbxPaintMode: TcxComboBox
        Left = 8
        Top = 236
        Properties.DropDownListStyle = lsFixedList
        Properties.OnChange = cbxPaintModeChange
        TabOrder = 2
        Width = 161
      end
      object btnSelectPicture: TcxButton
        Left = 166
        Top = 185
        Width = 121
        Height = 23
        Anchors = [akRight, akBottom]
        Caption = 'Se&lect Picture ...'
        TabOrder = 1
        OnClick = SelectPictureClick
      end
      object btnPreview: TcxButton
        Left = 8
        Top = 185
        Width = 121
        Height = 23
        Anchors = [akLeft, akBottom]
        Caption = 'Pre&view ...'
        TabOrder = 0
        OnClick = PicturePreviewClick
      end
    end
  end
  object pmPicture: TPopupMenu
    Images = ilMenu
    OnPopup = pmPicturePopup
    Left = 372
    Top = 50
    object miPreview: TMenuItem
      Caption = 'Pre&view...'
      ImageIndex = 8
      OnClick = PicturePreviewClick
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object miLoad: TMenuItem
      Caption = '&Load...'
      ImageIndex = 13
      ShortCut = 45
      OnClick = SelectPictureClick
    end
    object miDelete: TMenuItem
      Caption = '&Delete'
      ImageIndex = 5
      ShortCut = 46
      OnClick = miDeleteClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object miCut: TMenuItem
      Caption = 'Cu&t'
      ImageIndex = 3
      ShortCut = 16472
      OnClick = miCutClick
    end
    object miCopy: TMenuItem
      Caption = '&Copy'
      ImageIndex = 2
      ShortCut = 16451
      OnClick = miCopyClick
    end
    object miPaste: TMenuItem
      Caption = '&Paste'
      ImageIndex = 4
      ShortCut = 16470
      OnClick = miPasteClick
    end
  end
  object ilMenu: TcxImageList
    FormatVersion = 1
    DesignInfo = 5243256
  end
end
