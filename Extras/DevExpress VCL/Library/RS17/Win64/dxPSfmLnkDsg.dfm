object dxfmReportLinkDesignWindow: TdxfmReportLinkDesignWindow
  Left = 524
  Top = 253
  BorderStyle = bsDialog
  BorderWidth = 10
  Caption = 'Report Links'
  ClientHeight = 331
  ClientWidth = 494
  Color = clBtnFace
  Constraints.MinWidth = 520
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    00000000000000000000000000000FFFFFFFFFF000000F00F00000F000000FFF
    FFFFFFF000000F00F00000F000000FFFFFFFFFF000000FFFFFFF0FF000000F00
    FFF080F000000F080F08080000440FF080808088804400000808088888440000
    008088888844000000088888804400000000000000440000000000000000FFFF
    0000000F0000000F0000000F0000000F0000000F0000000F0000000F0000000F
    0000000400000000000000000000F8000000FC000000FE040000FFFF0000}
  KeyPreview = True
  OldCreateOrder = True
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  AutoScroll = False
  object lbxLinks: TcxListBox
    Left = 0
    Top = 0
    Width = 364
    Height = 331
    Align = alClient
    DragMode = dmAutomatic
    ItemHeight = 13
    ListStyle = lbOwnerDrawVariable
    MultiSelect = True
    PopupMenu = pmLinks
    Style.TransparentBorder = False
    TabOrder = 1
    OnClick = lbxLinksClick
    OnDblClick = lbxLinksDblClick
    OnDragDrop = lbxLinksDragDrop
    OnDragOver = lbxLinksDragOver
    OnDrawItem = lbxLinksDrawItem
    OnEndDrag = lbxLinksEndDrag
    OnKeyPress = lbxLinksKeyPress
    OnMeasureItem = lbxLinksMeasureItem
    OnStartDrag = lbxLinksStartDrag
  end
  object pnlButtons: TcxGroupBox
    Left = 364
    Top = 0
    Align = alRight
    PanelStyle.Active = True
    ParentBackground = False
    ParentColor = False
    Style.BorderStyle = ebsNone
    Style.TransparentBorder = False
    TabOrder = 0
    Height = 330
    Width = 130
    object btnAdd: TcxButton
      Left = 9
      Top = 0
      Width = 121
      Height = 22
      Caption = '&Add...'
      DropDownMenu = pmAdd
      Kind = cxbkDropDownButton
      TabOrder = 0
      OnClick = AddClick
    end
    object btnDelete: TcxButton
      Tag = 4
      Left = 9
      Top = 28
      Width = 121
      Height = 22
      Caption = '&Delete'
      TabOrder = 1
      OnClick = EditClick
    end
    object btnShowDesigner: TcxButton
      Left = 9
      Top = 140
      Width = 121
      Height = 22
      Caption = 'Show D&esigner...'
      TabOrder = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = LinkDesignClick
    end
    object btnSelectAll: TcxButton
      Tag = 6
      Left = 9
      Top = 56
      Width = 121
      Height = 22
      Caption = 'Se&lect All'
      TabOrder = 2
      OnClick = EditClick
    end
    object btnRestoreOriginal: TcxButton
      Left = 9
      Top = 224
      Width = 121
      Height = 22
      Caption = 'Rest&ore Or&iginal'
      TabOrder = 6
      OnClick = RestoreOriginalClick
    end
    object btnChangeComponent: TcxButton
      Tag = 3
      Left = 9
      Top = 168
      Width = 121
      Height = 22
      Caption = 'C&hange Component...'
      TabOrder = 8
      OnClick = LinkChangeComponentClick
    end
    object btnPrintPreview: TcxButton
      Tag = 2
      Left = 9
      Top = 280
      Width = 121
      Height = 22
      Caption = 'Pre&view...'
      TabOrder = 9
      OnClick = PrintPreviewClick
    end
    object btnPrint: TcxButton
      Tag = 3
      Left = 9
      Top = 308
      Width = 121
      Height = 22
      Caption = 'Print...'
      TabOrder = 10
      OnClick = PrintClick
    end
    object btnPageSetup: TcxButton
      Tag = 1
      Left = 9
      Top = 252
      Width = 121
      Height = 22
      Caption = 'Pa&ge Setup...'
      TabOrder = 11
      OnClick = PageSetupClick
    end
    object btnMoveUp: TcxButton
      Left = 9
      Top = 84
      Width = 121
      Height = 22
      Caption = 'Move &Up'
      TabOrder = 3
      OnClick = MoveUpClick
    end
    object btnMoveDown: TcxButton
      Tag = 1
      Left = 9
      Top = 112
      Width = 121
      Height = 22
      Caption = 'Move Dow&n'
      TabOrder = 4
      OnClick = MoveDownClick
    end
    object btnRestoreDefaults: TcxButton
      Left = 9
      Top = 196
      Width = 121
      Height = 22
      Caption = 'Rest&ore Defaults'
      TabOrder = 7
      OnClick = RestoreDefaultsClick
    end
  end
  object pmLinks: TPopupMenu
    Images = ilLinks
    OnPopup = pmLinksPopup
    Left = 7
    Top = 6
    object miAdd: TMenuItem
      Caption = '&Add...'
      ImageIndex = 0
      ShortCut = 45
      OnClick = AddClick
    end
    object miAddComposition: TMenuItem
      Caption = 'Add Composition...'
      ImageIndex = 1
      OnClick = AddCompositionClick
    end
    object miLine7: TMenuItem
      Caption = '-'
    end
    object miAddExisting: TMenuItem
      Caption = 'Add Existing'
      ShortCut = 32813
      OnClick = AddExistingClick
    end
    object miAddStandard: TMenuItem
      Caption = 'Add Standard Link...'
      ShortCut = 16429
      OnClick = AddStandardClick
    end
    object miLine5: TMenuItem
      Caption = '-'
    end
    object miEdit: TMenuItem
      Caption = '&Edit'
      object miCut: TMenuItem
        Tag = 2
        Caption = 'Cu&t'
        ImageIndex = 3
        ShortCut = 16472
        OnClick = EditClick
      end
      object miCopy: TMenuItem
        Tag = 1
        Caption = '&Copy'
        ImageIndex = 2
        ShortCut = 16451
        OnClick = EditClick
      end
      object miPaste: TMenuItem
        Tag = 3
        Caption = '&Paste'
        ImageIndex = 4
        ShortCut = 16470
        OnClick = EditClick
      end
      object miDelete: TMenuItem
        Tag = 4
        Caption = '&Delete'
        ImageIndex = 5
        ShortCut = 46
        OnClick = EditClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object miSelectAll: TMenuItem
        Tag = 6
        Caption = 'Se&lect All'
        ShortCut = 16449
        OnClick = EditClick
      end
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object miMoveUp: TMenuItem
      Caption = 'Move &Up'
      ImageIndex = 10
      ShortCut = 16422
      OnClick = MoveUpClick
    end
    object miMoveDown: TMenuItem
      Caption = 'Move Dow&n'
      ImageIndex = 11
      ShortCut = 16424
      OnClick = MoveDownClick
    end
    object miLine1: TMenuItem
      Caption = '-'
    end
    object miShowDesigner: TMenuItem
      Caption = 'Show Designer...'
      Default = True
      ImageIndex = 6
      ShortCut = 16397
      OnClick = LinkDesignClick
    end
    object miSetAsCurrent: TMenuItem
      Caption = '&Make Current'
      ShortCut = 16416
      OnClick = SetAsCurrentClick
    end
    object miChangeComponent: TMenuItem
      Caption = 'C&hange Component...'
      OnClick = LinkChangeComponentClick
    end
    object miLine2: TMenuItem
      Caption = '-'
    end
    object miRestoreDefaults: TMenuItem
      Caption = 'Rest&ore Defaults'
      ShortCut = 16463
      OnClick = RestoreDefaultsClick
    end
    object miRestoreOriginal: TMenuItem
      Caption = 'Rest&ore Or&iginal'
      ShortCut = 16457
      OnClick = RestoreOriginalClick
    end
    object miLine3: TMenuItem
      Caption = '-'
    end
    object miPageSetup: TMenuItem
      Tag = 1
      Caption = 'Pa&ge Setup...'
      ImageIndex = 7
      OnClick = PageSetupClick
    end
    object miPrintPreview: TMenuItem
      Tag = 2
      Caption = 'Print Pre&view...'
      ImageIndex = 8
      OnClick = PrintPreviewClick
    end
    object miPrint: TMenuItem
      Tag = 3
      Caption = '&Print...'
      ImageIndex = 9
      ShortCut = 16464
      OnClick = PrintClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object miBackground: TMenuItem
      Caption = 'Bac&kground'
      object miBackgroundEffects: TMenuItem
        Tag = 4
        Caption = 'E&ffects...'
        ImageIndex = 12
        OnClick = BackgroundClick
      end
      object miBackgroundClear: TMenuItem
        Tag = 5
        Caption = 'Clear'
        OnClick = ClearBackgroundClick
      end
    end
    object miLine: TMenuItem
      Caption = '-'
    end
    object miShowButtons: TMenuItem
      Caption = 'Show &Button Bar'
      Checked = True
      OnClick = ShowButtonsClick
    end
  end
  object pmAdd: TPopupMenu
    Images = ilLinks
    OnPopup = pmLinksPopup
    Left = 35
    Top = 6
    object miAdd1: TMenuItem
      Caption = '&Add...'
      Default = True
      ImageIndex = 0
      ShortCut = 45
      OnClick = AddClick
    end
    object miAddComposition1: TMenuItem
      Caption = 'Add Composition...'
      Hint = 'miAddComposition'
      ImageIndex = 1
      OnClick = AddCompositionClick
    end
    object miLine6: TMenuItem
      Caption = '-'
    end
    object miAddExisting1: TMenuItem
      Caption = 'Add Existing'
      ShortCut = 32813
      OnClick = AddExistingClick
    end
    object miAddStandard1: TMenuItem
      Caption = 'Add Standard...'
      ShortCut = 16429
      OnClick = AddStandardClick
    end
  end
  object ilLinks: TcxImageList
    FormatVersion = 1
    DesignInfo = 393279
  end
end
